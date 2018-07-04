cmake_minimum_required (VERSION 2.6)
project (RustCPPTest)

set (RUSTCPP_VERSION_MAJOR 0)
set (RUSTCPP_VERSION_MINOR 1)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/rust_test/binding")

add_executable (RustCPPTest cpptest.cpp)

include (ExternalProject)
set_directory_properties (PROPERTIES EP_PREFIX ${PROJECT_BINARY_DIR}/RUST)

ExternalProject_Add (
  rust_test
  DOWNLOAD_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND cargo build COMMAND cargo build --release COMMAND cbindgen -o binding/rust_test.h
  BINARY_DIR "${PROJECT_SOURCE_DIR}/rust_test"
  INSTALL_COMMAND ""
  LOG_BUILD ON )

add_dependencies(RustCPPTest rust_test)

target_link_libraries(
  RustCPPTest
  debug "${PROJECT_SOURCE_DIR}/rust_test/target/debug/librust_test.a"
  optimized "${PROJECT_SOURCE_DIR}/rust_test/target/release/librust_test.a"
)

set_target_properties(RustCPPTest PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
