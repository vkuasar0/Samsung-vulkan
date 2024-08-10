#!/bin/bash

# Define paths and variables
DEVICE_PATH="/data/local/tmp"
OUTPUT_DIR="output"

# Ensure the output directory exists
mkdir -p "$OUTPUT_DIR"

# Pull the result files from the device
adb pull "$DEVICE_PATH/output_image.png" "$OUTPUT_DIR/"
adb pull "$DEVICE_PATH/result.jpg" "$OUTPUT_DIR/"
adb pull "$DEVICE_PATH/report_vulkan.csv" "$OUTPUT_DIR/"
