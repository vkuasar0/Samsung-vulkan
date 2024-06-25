# adb push arm64-v8a/libvulkan.so /system/vendor/lib
adb push libs/arm64-v8a/vulkan_compute /data/local/tmp
adb push image_add1.png /data/local/tmp
adb push image_add2.png /data/local/tmp
adb shell /data/local/tmp/vulkan_compute