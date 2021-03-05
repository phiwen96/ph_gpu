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


void parse_instance_extensions (auto& output_file)
{
    vector <VkExtensionProperties> instanceExtensions = getInstanceExtensions ();
    
    for (int i = 0; auto const& instanceExtension : instanceExtensions)
    {
        output_file << DEF (INSTANCE_EXTENSION_) << i << "_NAME " << instanceExtension.extensionName << "\n";
        
        ++i;
    }
}
void parse_instance_layers (auto& output_file)
{
    vector <VkLayerProperties> instanceLayers = getInstanceLayers ();
    
    for (int i = 0; auto const& instanceLayer : instanceLayers)
    {
        output_file << DEF (INSTANCE_LAYER_) << i << "_NAME " << instanceLayer.layerName << "\n";
        
        ++i;
    }
}
void parse_physical_device (auto& output_file, vector<VkPhysicalDevice>& physicalDevices)
{
    for (int i = 0; auto& physicalDevice : physicalDevices)
    {
          
          uint32_t queue_families_count = 0;
          
          vkGetPhysicalDeviceQueueFamilyProperties (physicalDevice, &queue_families_count, nullptr);
          
          output_file << DEF (GPU_) << i << "_QUEUE_FAMILIES_COUNT " << queue_families_count << " \n";

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
                
                
                output_file << graphics;
                output_file << compute;
                output_file << transfer;
                output_file << sparse_binding;
                output_file << protect;
                ++j;
          }
          
          VkPhysicalDeviceProperties props = getPhysicalDeviceProperties (physicalDevice);
          VkPhysicalDeviceFeatures feats = getPhysicalDeviceFeatures (physicalDevice);
          VkPhysicalDeviceLimits limits = props.limits;
          
          output_file << DEF (GPU_) << i << PARSE (props.apiVersion, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (props.driverVersion, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (props.vendorID, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (props.deviceID, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (props.deviceName, << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[0], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[1], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[2], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[3], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[4], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[5], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[6], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[7], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[8], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[9], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[10], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[11], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[12], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[13], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[14], << " " <<) << " \n";
//            output_file << DEF (GPU_) << i << PARSE (props.pipelineCacheUUID[15], << " " <<) << " \n";
          
          output_file << DEF (GPU_) << i << "_TYPE_DISCRETE " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) << "\n";
          output_file << DEF (GPU_) << i << "_TYPE_INTEGRATED " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) << "\n";
          output_file << DEF (GPU_) << i << "_TYPE_VIRTUAL " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU) << "\n";
          output_file << DEF (GPU_) << i << "_TYPE_CPU " << (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU) << "\n";
          
          output_file << "\n";
          
          output_file << DEF (GPU_) << i << PARSE (feats.robustBufferAccess, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.fullDrawIndexUint32, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.imageCubeArray, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.independentBlend, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.geometryShader, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.tessellationShader, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sampleRateShading, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.dualSrcBlend, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.logicOp, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.multiDrawIndirect, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.drawIndirectFirstInstance, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.depthClamp, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.depthBiasClamp, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.fillModeNonSolid, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.depthBounds, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.wideLines, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.largePoints, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.alphaToOne, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.multiViewport, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.samplerAnisotropy, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.textureCompressionETC2, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.textureCompressionASTC_LDR, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.textureCompressionBC, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.occlusionQueryPrecise, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.pipelineStatisticsQuery, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.vertexPipelineStoresAndAtomics, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.fragmentStoresAndAtomics, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderTessellationAndGeometryPointSize, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderImageGatherExtended, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageExtendedFormats, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageMultisample, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageReadWithoutFormat, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageWriteWithoutFormat, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderUniformBufferArrayDynamicIndexing, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderSampledImageArrayDynamicIndexing, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageBufferArrayDynamicIndexing, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderStorageImageArrayDynamicIndexing, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderClipDistance, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderCullDistance, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderFloat64, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderInt64, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderInt16, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderResourceResidency, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.shaderResourceMinLod, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseBinding, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyBuffer, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyImage2D, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyImage3D, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidency2Samples, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidency4Samples, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidency8Samples, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidency16Samples, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.sparseResidencyAliased, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.variableMultisampleRate, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (feats.inheritedQueries, << " " <<) << " \n";
          
          output_file << "\n";
          
          output_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension1D, << " " <<) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension2D, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetUniformBuffersDynamic, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetUniformBuffers, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageResources, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorInputAttachments, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorStorageImages, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSampledImages, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorSamplers, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxBoundDescriptorSets, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.sparseAddressSpaceSize, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.bufferImageGranularity, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxSamplerAllocationCount, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPushConstantsSize, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxStorageBufferRange, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxUniformBufferRange, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTexelBufferElements, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxImageArrayLayers, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxImageDimensionCube, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxImageDimension3D, << " " << ) << " \n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageBuffers, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageBuffersDynamic, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetSampledImages, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetStorageImages, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetInputAttachments, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputAttributes, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputBindings, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputAttributeOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxVertexInputBindingStride, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxVertexOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationGenerationLevel, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationPatchSize, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerVertexInputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerVertexOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlPerPatchOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationControlTotalOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationEvaluationInputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTessellationEvaluationOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDescriptorSetSamplers, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorStorageBuffers, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxPerStageDescriptorUniformBuffers, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxMemoryAllocationCount, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxGeometryShaderInvocations, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxGeometryInputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxGeometryOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxGeometryOutputVertices, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxGeometryTotalOutputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFragmentInputComponents, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFragmentOutputAttachments, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFragmentDualSrcAttachments, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFragmentCombinedOutputResources, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeSharedMemorySize, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupCount[2], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupInvocations, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxComputeWorkGroupSize[2], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.subPixelPrecisionBits, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.subTexelPrecisionBits, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.mipmapPrecisionBits, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDrawIndexedIndexValue, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxDrawIndirectCount, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxSamplerLodBias, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxSamplerAnisotropy, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxViewports, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxViewportDimensions[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxViewportDimensions[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.viewportBoundsRange[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.viewportBoundsRange[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.viewportSubPixelBits, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minMemoryMapAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minTexelBufferOffsetAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minUniformBufferOffsetAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minStorageBufferOffsetAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minTexelOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTexelOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minTexelGatherOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxTexelGatherOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.minInterpolationOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxInterpolationOffset, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.subPixelInterpolationOffsetBits, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferWidth, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferHeight, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxFramebufferLayers, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.framebufferColorSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.framebufferDepthSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.framebufferStencilSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.framebufferNoAttachmentsSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxColorAttachments, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.sampledImageColorSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.sampledImageIntegerSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.sampledImageDepthSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.sampledImageStencilSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.storageImageSampleCounts, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxSampleMaskWords, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.timestampComputeAndGraphics, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.timestampPeriod, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxClipDistances, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxCullDistances, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.maxCombinedClipAndCullDistances, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.discreteQueuePriorities, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.pointSizeRange[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.pointSizeRange[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.lineWidthRange[0], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.lineWidthRange[1], << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.pointSizeGranularity, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.lineWidthGranularity, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.strictLines, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.standardSampleLocations, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.optimalBufferCopyOffsetAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.optimalBufferCopyRowPitchAlignment, << " " <<) << "\n";
          output_file << DEF (GPU_) << i << PARSE (limits.nonCoherentAtomSize, << " " <<) << "\n";
          
          ++i;
    }
}



int main (int argc, const char * argv[])
{
      string const output_file_path = argv [1];
      
      file <write> output_file (output_file_path);
      output_file << "#pragma once\n";

      
      glfwInit();
      auto instanceExtensions = getInstanceExtensions ();
      auto instanceLayers = getInstanceLayers ();
      auto instance = getInstance (instanceExtensions, instanceLayers);
      auto physicalDevices = getPhysicalDevices (instance);
      output_file << "#define GPU_COUNT " << physicalDevices.size() << "\n";

      
      
      [&]{
            for (auto& i : instanceExtensions)
                  cout << "\t" << i.extensionName << endl;
            
            cout << endl;
            
            for (auto& i : instanceLayers)
                  cout << "\t" << i.layerName << endl;
      };
    parse_instance_extensions (output_file);
    parse_instance_layers (output_file);
    parse_physical_device(output_file, physicalDevices);
      
      
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
      
      return 0;
}

