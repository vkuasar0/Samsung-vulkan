LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=vulkan
LOCAL_SRC_FILES:=../arm64-v8a/libvulkan.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE+=vulkan_compute

LOCAL_C_INCLUDES += ${ANDROID_NDK_HOME}/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include
LOCAL_SRC_FILES += main.cpp
LOCAL_SHARED_LIBRARIES := vulkan
LOCAL_CFLAGS += -std=c++11 -frtti -fexceptions  -w
# LOCAL_LDLIBS += -llog -L$(SYSROOT)/usr/lib
LOCAL_LDLIBS += -llog

include $(BUILD_EXECUTABLE)
