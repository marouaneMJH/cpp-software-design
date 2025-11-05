cmake_minimum_required(VERSION 3.16)
project(DSPlayground LANGUAGES CXX)

# C++ standard + common warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Executable
add_executable(app
  src/main.cpp
)

# Public headers live under include/
target_include_directories(app PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

# When running from the build dir, copy assets next to the binary
add_custom_command(TARGET app POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_SOURCE_DIR}/assets
          $<TARGET_FILE_DIR:app>/assets
)

# Optional: installation (cmake --install build)
install(TARGETS app RUNTIME DESTINATION bin)
install(DIRECTORY assets/ DESTINATION bin/assets)

# ---- Optional tests (enable with -DBUILD_TESTS=ON) ----
option(BUILD_TESTS "Build unit tests" OFF)
if (BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
  )
  FetchContent_MakeAvailable(catch2)

  add_executable(tests
    tests/test_dictionary.cpp
  )
  target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
  target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

  include(CTest)
  include(Catch)
  catch_discover_tests(tests)
endif()
