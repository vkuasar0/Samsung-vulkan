# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.6)

# Define the project name
project(VulkanComputeApp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Vulkan headers
include_directories(${VULKAN_HEADERS})

include_directories(${ANDROID_NDK_HOME}/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include)

# Add the source file
add_executable(vulkan_compute main.cpp)

# Link Vulkan libraries
target_link_libraries(vulkan_compute ${VULKAN_LIB} c++_shared android log)

set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK_HOME}/build/cmake/android.toolchain.cmake)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
set(CMAKE_ANDROID_NDK_PLATFORM android-30)

