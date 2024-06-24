# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.6)

# Define the project name
project(VulkanComputeApp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include Vulkan headers
include_directories(${VULKAN_HEADERS})

include_directories(${ANDROID_NDK_HOME}/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include)

# Add the source file
add_executable(vulkan_compute main.cpp)

# Link Vulkan libraries
target_link_libraries(vulkan_compute ${VULKAN_LIB} dl c)
