#include <vulkan/vulkan.h>
#include <vector>
#include <assert.h>
#include <stdexcept>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = false;
#endif

#define VK_CHECK_RESULT(f)                                                                \
    {                                                                                     \
        VkResult res = (f);                                                               \
        if (res != VK_SUCCESS)                                                            \
        {                                                                                 \
            printf("Fatal : VkResult is %d in %s at line %d\n", res, __FILE__, __LINE__); \
            assert(res == VK_SUCCESS);                                                    \
        }                                                                                 \
    }

class ComputeApplication
{
private:
    struct Pixel
    {
        float r, g, b, a;
    };
    VkInstance instance;
    VkDebugReportCallbackEXT debugReportCallback;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkPipeline pipeline;
    VkPipelineLayout pipelineLayout;
    VkShaderModule computeShaderModule;
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;
    VkDescriptorPool descriptorPool;
    VkDescriptorSet descriptorSet;
    VkDescriptorSetLayout descriptorSetLayout;
    VkImage inImage1;
    VkImage inImage2;
    VkImage outImage;
    VkImageView inImageView1;
    VkImageView inImageView2;
    VkImageView outImageView;
    VkDeviceMemory inImageMemory1;
    VkDeviceMemory inImageMemory2;
    VkDeviceMemory outImageMemory;

    VkDeviceSize size;
    int WIDTH, HEIGHT, CHANNELS;

    std::vector<const char *> enabledLayers;
    VkQueue queue;
    uint32_t queueFamilyIndex;

public:
    void saveRenderedImage();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugReportCallbackFn(
        VkDebugReportFlagsEXT flags,
        VkDebugReportObjectTypeEXT objectType,
        uint64_t object,
        size_t location,
        int32_t messageCode,
        const char *pLayerPrefix,
        const char *pMessage,
        void *pUserData)
    {
        printf("Debug Report: %s: %s\n", pLayerPrefix, pMessage);
        return VK_FALSE;
    }
    void createInstance();
    void findPhysicalDevice();
    uint32_t getComputeQueueFamilyIndex();
    void createDevice();
    uint32_t findMemoryType(uint32_t memoryTypeBits, VkMemoryPropertyFlags properties);
    void createTextureImage(const char *filename, VkImage &image, VkImageView &imageView, VkDeviceMemory &imageMemory, int &texWidth, int &texHeight, int &texChannels);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &bufferMemory);
    void createDescriptorSetLayout();
    void createDescriptorSet();
    void createAllImages();
    void createOutputImage(int width, int height, VkImage &image, VkImageView &imageView, VkDeviceMemory &imageMemory);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void createComputePipeline();
    void createCommandBuffer();
    void runCommandBuffer();
    void cleanup();
    uint32_t *readFile(uint32_t &length, const char *filename);
    void run();
};