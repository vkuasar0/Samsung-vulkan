glslc -fshader-stage=compute -o shaders/compute.spv shaders/grey.comp
adb push libs/arm64-v8a/vulkan_compute /data/local/tmp
adb push image_add1.png /data/local/tmp
adb push image_add2.png /data/local/tmp
adb push shaders /data/local/tmp
adb shell