# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.21)

# Define the project name and version
project(RenameMeTradeSystem VERSION 1.0)

# Set the C++ standard to use (C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add preprocessor definitions globally
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-DBOOST_ASIO_NO_WIN32_LEAN_AND_MEAN)
add_definitions(-D_WIN32_WINNT=0x0A00)  # Windows 11

# Ensure all libraries use the same runtime
if(MSVC)
  option(gtest_force_shared_crt "Use shared (DLL) run-time lib even when Google Test is built as static lib." ON)
endif()

# Specify the path to Google Benchmark installation
set(BENCHMARK_ROOT "C:/Program Files (x86)/benchmark")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${BENCHMARK_ROOT}")

# Set policies for Boost
cmake_policy(SET CMP0167 NEW)
cmake_policy(SET CMP0144 NEW)

# Find Google Benchmark
find_package(benchmark REQUIRED)

if (benchmark_FOUND)
  include_directories(${BENCHMARK_ROOT}/include)
  link_directories(${BENCHMARK_ROOT}/lib)
  link_libraries(benchmark)
else()
  message(FATAL_ERROR "Could not find Google Benchmark. Please ensure it is installed and BENCHMARK_ROOT is set correctly.")
endif()

# Include signal-forge-core
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../signal-forge-core ${CMAKE_CURRENT_BINARY_DIR}/signal-forge-core)

# Include directories from signal-forge-core
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../signal-forge-core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../signal-forge-core/external)

# Include the headers for RenameMeTradeSystem
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set build type to Debug to include debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Set compiler and linker flags for debug builds
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /DEBUG")

# Add the RenameMeTradeSystem library
add_library(RenameMeTradeSystem SHARED
    src/RenameMeTradeSystem.cpp
    src/RenameMeSignalGenerator.cpp
    src/RenameMeSignalProcessor.cpp
    src/RenameMeActiveOrderRiskProcessor.cpp
    src/RenameMePendingOrderRiskProcessor.cpp
    src/RenameMePositionRiskProcessor.cpp
    src/RenameMeOrderProcessor.cpp
    src/RenameMeMarketTimingOrderFilter.cpp
    src/RenameMeParameterTuner.cpp
    src/RenameMeLevelGenerator.cpp
    src/RenameMeLevelProcessor.cpp
    src/main.cpp
)

# Link the libraries
target_link_libraries(RenameMeTradeSystem PUBLIC
    signal-forge-core
    benchmark
)

# Copy the DLL and the config file to the Sierra Chart Data directory
add_custom_command(TARGET RenameMeTradeSystem POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:RenameMeTradeSystem>
    "C:/SierraChart/Data/$<TARGET_FILE_NAME:RenameMeTradeSystem>"
)

# Output debug files (PDBs)
set(CMAKE_PDB_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
