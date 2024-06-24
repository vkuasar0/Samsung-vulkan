adb push arm64-v8a/libVkLayer_khronos_validation.so /data/local/tmp/vulkan-layers
adb shell setprop debug.vulkan.layers /data/local/tmp/vulkan-layers
adb shell setprop debug.vulkan.validation 1