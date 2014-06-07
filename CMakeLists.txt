# ----------------------------------------------------------------------
# CMake Settings
# ----------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)


# ----------------------------------------------------------------------
# Enable CTest Support
# ----------------------------------------------------------------------

enable_testing()


# ----------------------------------------------------------------------
# Top-Level Project Settings
# ----------------------------------------------------------------------

project(glowing-adventure)

set(SOVERSION 0)
set(VERSION 0.1.0)


# ----------------------------------------------------------------------
# Doxygen Settings
# ----------------------------------------------------------------------

#configure_file(
#  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
#  ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#  @ONLY  # only replace variables of the form @VAR@
#  )


# ----------------------------------------------------------------------
# Build Environment Settings
# ----------------------------------------------------------------------

function(encode_compiler_flag_as_token string_value result_var)
  string(STRIP "${string_value}" RESULT)
  string(REPLACE " " "_" RESULT "${RESULT}")
  string(REPLACE "," "_" RESULT "${RESULT}")
  string(REPLACE "." "_" RESULT "${RESULT}")
  string(REPLACE "=" "_" RESULT "${RESULT}")
  string(REPLACE "/" "_" RESULT "${RESULT}")
  string(REPLACE "-" "_" RESULT "${RESULT}")
  string(REPLACE "+" "x" RESULT "${RESULT}")
  set(${result_var} ${RESULT} PARENT_SCOPE)
endfunction()


include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

set(BUILD_SHARED_LIBS ON)


set(PROJECT_GNU_COMMON_FLAGS
  "-D_FORTIFY_SOURCE=2"
  "-O3"
  #"-g"
  "-fvisibility=hidden"
  "-fdiagnostics-show-option"
  "-pedantic-errors"
  "-Wall"
  "-Wextra"
  "-Wformat=2"
  "-Werror=format-security"
  "-Wno-long-long"
  "-Wfatal-errors"
  "-Wcast-align"
  "-Wcast-qual"
  #"-Wconversion"
  "-Wsign-conversion"
  "-Wsign-compare"
  "-Wfloat-equal"
  "-Wlogical-op"
  "-Wmissing-include-dirs"
  "-Wmissing-declarations"
  "-Wredundant-decls"
  "-Wshadow"
  "-Wswitch-default"
  "-Wswitch-enum"
  "-Wundef"
  "-Wuninitialized"
  "-Winit-self"
  #"-Wunreachable-code"
  "-Wwrite-strings"
  "-Winline"
  "-Wpacked"
  #"-Wpadded"
  "-fstack-protector-all"
  "-Wstack-protector"
  "-ftrapv"
  "-Wl,-z,relro"
  "-Wl,-z,now"
  )

set(PROJECT_GNU_C_FLAGS
  "-std=c11"
  "-Wbad-function-cast"
  "-Wc++-compat"
  "-Wmissing-prototypes"
  "-Wstrict-prototypes"
  "-Wnested-externs"
  "-Wold-style-declaration"
  "-Wold-style-definition"
  "-Wtraditional-conversion"
  )

set(PROJECT_GNU_CXX_FLAGS
  "-std=c++11"
  "-Weffc++"
  "-Wctor-dtor-privacy"
  "-Wold-style-cast"
  "-Woverloaded-virtual"
  "-Wsign-promo"
  "-Wstrict-null-sentinel"
  "-Wabi"
  )

# GNU C compiler (gcc) or LLVM C compiler (clang)
if( ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU") OR
    ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang") )
  foreach(LINE ${PROJECT_GNU_COMMON_FLAGS} ${PROJECT_GNU_C_FLAGS})
    # Check whether each requested flag is supported by this compiler.
    encode_compiler_flag_as_token("${LINE}" FLAG)
    check_c_compiler_flag("-Werror ${LINE}" GNUCC_SUPPORTS_FLAG_${FLAG})
    if(GNUCC_SUPPORTS_FLAG_${FLAG})
      # Add each supported flag to CMAKE_C_FLAGS.
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LINE}")
    endif()
  endforeach(LINE)
endif()

# GNU C++ compiler (g++) or LLVM C++ compiler (clang++)
if( ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR
    ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") )
  foreach(LINE ${PROJECT_GNU_COMMON_FLAGS} ${PROJECT_GNU_CXX_FLAGS})
    # Check whether each requested flag is supported by this compiler.
    encode_compiler_flag_as_token("${LINE}" FLAG)
    check_cxx_compiler_flag("-Werror ${LINE}" GNUCXX_SUPPORTS_FLAG_${FLAG})
    if(GNUCXX_SUPPORTS_FLAG_${FLAG})
      # Add each supported flag to CMAKE_CXX_FLAGS.
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINE}")
    endif()
  endforeach(LINE)
endif()


# Microsoft Visual C++ compiler
if(MSVC)
  foreach(TYPE "_DEBUG" "_MINSIZEREL" "_RELEASE" "_RELWITHDEBINFO")
    foreach(LANG "C" "CXX")
      # static libc flags (change /MD to /MT and /MDd to /MTd)
      string(REPLACE "/MD" "/MT" TMP_FLAGS "${CMAKE_${LANG}_FLAGS${TYPE}}")
      set(CMAKE_${LANG}_FLAGS${TYPE} "${TMP_FLAGS}")
      # Disable warning #4290:
      #   C++ exception specification ignored except to
      #   indicate a function is not __declspec(nothrow)
      set(CMAKE_${LANG}_FLAGS${TYPE}
        "${CMAKE_${LANG}_FLAGS${TYPE}} /wd 4290"
        )
      # Disable warning #4996:
      #   The POSIX name for this item is deprecated.
      #   Instead, use the ISO C++ conformant name: ...
      set(CMAKE_${LANG}_FLAGS${TYPE}
        "${CMAKE_${LANG}_FLAGS${TYPE}} /wd 4996"
        )
    endforeach(LANG)
  endforeach(TYPE)
endif()


message("CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
message("CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

# ----------------------------------------------------------------------
# Project Settings
# ----------------------------------------------------------------------

project(glowing-adventure)

add_definitions(
  -DPROJECT="${PROJECT_NAME}"
  -DVERSION="${VERSION}"
  )


# ----------------------------------------------------------------------
# Find libraries and headers on different platforms in a portable way
# ----------------------------------------------------------------------

set(Boost_USE_MULTITHREAD ON)

find_package(Boost REQUIRED
  date_time
)

# find_package(LibXml2 REQUIRED)


# ----------------------------------------------------------------------
# Build Environment Settings
# ----------------------------------------------------------------------

include_directories(
  ${Boost_INCLUDE_DIR}
#  ${LIBXML2_INCLUDE_DIR}
  .
  )


# ----------------------------------------------------------------------
# Build Dependencies, Link Dependencies, Properties
# ----------------------------------------------------------------------

add_executable(glowing-adventure
  main.cpp
  )

target_link_libraries(glowing-adventure
  ${Boost_LIBRARIES}
  # pugixml
  # pqxx
  )

# ----------------------------------------------------------------------
# Installation
# ----------------------------------------------------------------------

#install(TARGETS foo
#  DESTINATION /some/path/to/install/dir
#  )


# ----------------------------------------------------------------------
