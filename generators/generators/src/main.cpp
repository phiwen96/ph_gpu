#include "main.hpp"
#define DEF(x) string("#define ") + string(BOOST_PP_STRINGIZE (x))
#define PARSE_1(s) [](string str){str = regex_replace (str, regex ("(.*)(\\[)"), R"($1)");str = regex_replace (str, regex ("(.*)(\\])"), R"($1)");str = regex_replace (str, regex ("(.*)(\\.)"), R"()");str = regex_replace (str, regex ("([a-z])([A-Z])"), R"($1_$2)");str = regex_replace (str, regex ("([[:digit:]]+)"), R"(_$1)");for (auto & c: str) c = toupper(c);str.insert (0, "_"); return str;}(string (s))
#define PARSE(x, ...) PARSE_1 (BOOST_PP_STRINGIZE (x)) __VA_ARGS__ x
auto getInstanceExtensions = [] () -> vector<VkExtensionProperties> {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    vector<VkExtensionProperties> extensions (extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    return extensions;
};
auto getInstanceLayers = [] () -> vector<VkLayerProperties> {
    uint32_t layerCount = 0;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    vector<VkLayerProperties> availableLayers (layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
    return availableLayers;
};
auto getInstance = [] (vector<VkExtensionProperties>& extensions, vector<VkLayerProperties>& layers) -> VkInstance {
    VkApplicationInfo appInfo
    {
        .sType                  = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName       = "generator",
        .applicationVersion     = VK_MAKE_VERSION (1, 0, 0),
        .pEngineName            = "No Engine",
        .engineVersion          = VK_MAKE_VERSION (1, 0, 0),
        .apiVersion             = VK_API_VERSION_1_2
    };
    
    
    
    VkInstance instance;
    
    vector <char const*> extensionNames;
    for (auto const& i : extensions)
        extensionNames.push_back (i.extensionName);
    
    vector <char const*> layerNames;
    for (auto const& i : layers)
        layerNames.push_back (i.layerName);
    
    
    VkInstanceCreateInfo createInfo
    {
        .sType                        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo             = &appInfo,
        .enabledExtensionCount        = (uint32_t) extensionNames.size(),
        .ppEnabledExtensionNames      = extensionNames.data(),
        .enabledLayerCount = (uint32_t) layerNames.size(),
        .ppEnabledLayerNames = layerNames.data()
    };
    
    
    
    
    
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    {
        throw runtime_error ("failed to create instance");
    }
    return instance;
};
auto getPhysicalDevices = [] (VkInstance& instance) -> vector<VkPhysicalDevice> {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    vector<VkPhysicalDevice> devices (deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
    return devices;
};
auto getPhysicalDeviceProperties = [](VkPhysicalDevice const& physicalDevice) -> VkPhysicalDeviceProperties {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);
    return properties;
};
auto getPhysicalDeviceFeatures = [](VkPhysicalDevice const& physicalDevice) -> VkPhysicalDeviceFeatures {
    VkPhysicalDeviceFeatures features;
    vkGetPhysicalDeviceFeatures(physicalDevice, &features);
    return features;
};


void parse_instance_extensions (auto& gpu_file)
{
    vector <VkExtensionProperties> instanceExtensions = getInstanceExtensions ();
    
    gpu_file << DEF (INSTANCE_EXTENSION_COUNT) << " " << instanceExtensions.size() << "\n";
    
    for (int i = 0; auto const& instanceExtension : instanceExtensions)
    {
        gpu_file << DEF (INSTANCE_EXTENSION_) << i << "_NAME " << instanceExtension.extensionName << "\n";
        
        ++i;
    }
}
void parse_instance_layers (auto& gpu_file)
{
    vector <VkLayerProperties> instanceLayers = getInstanceLayers ();
    
    gpu_file << DEF (INSTANCE_LAYER_COUNT) << " " << instanceLayers.size() << "\n";
    
    for (int i = 0; auto const& instanceLayer : instanceLayers)
    {
        gpu_file << DEF (INSTANCE_LAYER_) << i << "_NAME " << instanceLayer.layerName << "\n";
        
        ++i;
    }
}
void parse_physical_device (auto& gpu_file, vector<VkPhysicalDevice>& physicalDevices)
{
    gpu_file << "#define GPU_COUNT " << physicalDevices.size() << "\n";
    
    for (int i = 0; auto& physicalDevice : physicalDevices)
    {
        
        uint32_t queue_families_count = 0;
        
        vkGetPhysicalDeviceQueueFamilyProperties (physicalDevice, &queue_families_count, nullptr);
        
        gpu_file << DEF (GPU_) << i << "_QUEUE_FAMILIES_COUNT " << queue_families_count << " \n";
        
        vector <VkQueueFamilyProperties> queueFamilies (queue_families_count);
        for (int j = 0; auto const& queueFamily : queueFamilies)
        {
            string graphics = DEF (GPU_) + to_string (i) + "_QUEUE_FAMILY_" + to_string (j) + "_GRAPHICS ";
            string compute = DEF (GPU_) + to_string (i) + "_QUEUE_FAMILY_" + to_string (j) + "_COMPUTE ";
            string transfer = DEF (GPU_) + to_string (i) + "_QUEUE_FAMILY_" + to_string (j) + "_TRANSFER ";
            string sparse_binding = DEF (GPU_) + to_string (i) + "_QUEUE_FAMILY_" + to_string (j) + "_SPARSE_BINDING ";
            string protect = DEF (GPU_) + to_string (i) + "_QUEUE_FAMILY_" + to_string (j) + "_PROTECTED ";
            
            
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                graphics += "1 \n";
            } else
            {
                graphics += "0 \n";
            }
            
            if (queueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
            {
                compute += "1 \n";
            } else
            {
                compute += "0 \n";
            }
            
            if (queueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT)
            {
                transfer += "1 \n";
            } else
            {
                transfer += "0 \n";
            }
            
            if (queueFamily.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT)
            {
                sparse_binding += "1 \n";
            } else
            {
                sparse_binding += "0 \n";
            }
            
            if (queueFamily.queueFlags & VK_QUEUE_PROTECTED_BIT)
            {
                protect += "1 \n";
            } else
            {
                protect += "0 \n";
            }
            
            
            gpu_file << graphics;
            gpu_file << compute;
            gpu_file << transfer;
            gpu_file << sparse_binding;
            gpu_file << protect;
            ++j;
        }
        
        VkPhysicalDeviceProperties props = getPhysicalDeviceProperties (physicalDevice);
        VkPhysicalDeviceFeatures feats = getPhysicalDeviceFeatures (physicalDevice);
        VkPhysicalDeviceLimits limits = props.limits;
        
        gpu_file << DEF (GPU_) << i << PARSE (props.apiVersion, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (props.driverVersion, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (props.vendorID, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (props.deviceID, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (props.deviceName, << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[0], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[1], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[2], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[3], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[4], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[5], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[6], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[7], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[8], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[9], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[10], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[11], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[12], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[13], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[14], << " " <<) << " \n";
        //            gpu_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[15], << " " <<) << " \n";
        
        gpu_file << DEF (GPU_) << i << "_TYPE_DISCRETE " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) << "\n";
        gpu_file << DEF (GPU_) << i << "_TYPE_INTEGRATED " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) << "\n";
        gpu_file << DEF (GPU_) << i << "_TYPE_VIRTUAL " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU) << "\n";
        gpu_file << DEF (GPU_) << i << "_TYPE_CPU " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU) << "\n";
        
        gpu_file << "\n";
        
        gpu_file << DEF (GPU_) << i << PARSE (feats.robustBufferAccess, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.fullDrawIndexUint32, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.imageCubeArray, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.independentBlend, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.geometryShader, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.tessellationShader, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sampleRateShading, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.dualSrcBlend, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.logicOp, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.multiDrawIndirect, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.drawIndirectFirstInstance, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.depthClamp, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.depthBiasClamp, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.fillModeNonSolid, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.depthBounds, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.wideLines, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.largePoints, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.alphaToOne, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.multiViewport, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.samplerAnisotropy, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.textureCompressionETC2, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.textureCompressionASTC_LDR, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.textureCompressionBC, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.occlusionQueryPrecise, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.pipelineStatisticsQuery, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.vertexPipelineStoresAndAtomics, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.fragmentStoresAndAtomics, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderTessellationAndGeometryPointSize, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderImageGatherExtended, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageExtendedFormats, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageMultisample, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageReadWithoutFormat, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageWriteWithoutFormat, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderUniformBufferArrayDynamicIndexing, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderSampledImageArrayDynamicIndexing, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageBufferArrayDynamicIndexing, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageArrayDynamicIndexing, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderClipDistance, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderCullDistance, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderFloat64, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderInt64, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderInt16, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderResourceResidency, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.shaderResourceMinLod, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseBinding, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyBuffer, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyImage2D, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyImage3D, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidency2Samples, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidency4Samples, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidency8Samples, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidency16Samples, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyAliased, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.variableMultisampleRate, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (feats.inheritedQueries, << " " <<) << " \n";
        
        gpu_file << "\n";
        
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension1D, << " " <<) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension2D, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetUniformBuffersDynamic, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetUniformBuffers, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageResources, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorInputAttachments, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorStorageImages, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSampledImages, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxBoundDescriptorSets, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.sparseAddressSpaceSize, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.bufferImageGranularity, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxSamplerAllocationCount, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPushConstantsSize, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxStorageBufferRange, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxUniformBufferRange, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTexelBufferElements, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxImageArrayLayers, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxImageDimensionCube, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension3D, << " " << ) << " \n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageBuffers, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageBuffersDynamic, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetSampledImages, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageImages, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetInputAttachments, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputAttributes, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputBindings, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputAttributeOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputBindingStride, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxVertexOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationGenerationLevel, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationPatchSize, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerVertexInputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerVertexOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerPatchOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlTotalOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationEvaluationInputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTessellationEvaluationOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetSamplers, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorStorageBuffers, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorUniformBuffers, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxMemoryAllocationCount, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxGeometryShaderInvocations, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxGeometryInputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxGeometryOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxGeometryOutputVertices, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxGeometryTotalOutputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFragmentInputComponents, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFragmentOutputAttachments, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFragmentDualSrcAttachments, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFragmentCombinedOutputResources, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeSharedMemorySize, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[2], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupInvocations, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[2], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.subPixelPrecisionBits, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.subTexelPrecisionBits, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.mipmapPrecisionBits, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDrawIndexedIndexValue, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxDrawIndirectCount, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxSamplerLodBias, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxSamplerAnisotropy, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxViewports, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxViewportDimensions[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxViewportDimensions[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.viewportBoundsRange[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.viewportBoundsRange[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.viewportSubPixelBits, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minMemoryMapAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minTexelBufferOffsetAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minUniformBufferOffsetAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minStorageBufferOffsetAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minTexelOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTexelOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minTexelGatherOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxTexelGatherOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.minInterpolationOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxInterpolationOffset, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.subPixelInterpolationOffsetBits, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferWidth, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferHeight, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferLayers, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.framebufferColorSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.framebufferDepthSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.framebufferStencilSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.framebufferNoAttachmentsSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxColorAttachments, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.sampledImageColorSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.sampledImageIntegerSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.sampledImageDepthSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.sampledImageStencilSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.storageImageSampleCounts, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxSampleMaskWords, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.timestampComputeAndGraphics, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.timestampPeriod, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxClipDistances, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxCullDistances, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.maxCombinedClipAndCullDistances, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.discreteQueuePriorities, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.pointSizeRange[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.pointSizeRange[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.lineWidthRange[0], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.lineWidthRange[1], << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.pointSizeGranularity, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.lineWidthGranularity, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.strictLines, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.standardSampleLocations, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.optimalBufferCopyOffsetAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.optimalBufferCopyRowPitchAlignment, << " " <<) << "\n";
        gpu_file << DEF (GPU_) << i << PARSE (limits.nonCoherentAtomSize, << " " <<) << "\n";
        
        ++i;
    }
}



int main (int argc, const char * argv[])
{
    string const instance_file_path = argv [1];
    string const gpu_file_path = argv [2];
    
    file <write> instance_file (instance_file_path);
    file <write> gpu_file (gpu_file_path);
    
    instance_file << "#pragma once\n\n";
    gpu_file << "#pragma once\n\n";
    
    
    glfwInit();
    auto instanceExtensions = getInstanceExtensions ();
    auto instanceLayers = getInstanceLayers ();
    auto instance = getInstance (instanceExtensions, instanceLayers);
    auto physicalDevices = getPhysicalDevices (instance);
    
    
    
    
  
    parse_instance_extensions (instance_file);
    instance_file << "\n";
    parse_instance_layers (instance_file);
    parse_physical_device (gpu_file, physicalDevices);
    
    
    
    vkDestroyInstance(instance, nullptr);
    glfwTerminate();
    
    return 0;
}

