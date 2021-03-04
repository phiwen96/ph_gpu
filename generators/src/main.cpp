#include "main.hpp"
















#define PROCC2(str, max, var) var = []()->string\
{\
vector <string> strings (max);\
\
fill (strings.begin(), strings.end(), str);\
\
auto a1 = strings[0].find("${");\
\
while (a1 != string::npos)\
{\
      if (int a2 = strings[0].find ("}"); a2 != string::npos)\
      {\
            for (int i = 0; i < max; ++i)\
            {\
               \
                  strings[i].replace (strings[i].begin() + a1, strings[i].begin() + a2 + 1, to_string (i));\
            }\
      }\
      a1 = strings[0].find ("${");\
}\
\
string res;\
\
for (auto const& i : strings)\
res += i;\
      return res;\
}();// = [&s]->string{return "";}();

#define PROCC(x) PROCC2 (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (0, x)), BOOST_PP_SEQ_ELEM (1, x), BOOST_PP_SEQ_ELEM (2, x))//BOOST_PP_SEQ_ELEM (2, x) = [](string s){ \

//#define CAT_MID(x, y, z) BOOST_PP_CAT (x, BOOST_PP_CAT (y, z))

#define TINY_size(z, n, unused) \
template <> \
struct gpu <n> \
{ \
static constexpr uint32_t max_image_dimension_1D = 0;\
};
//= CAT_MID (GPU_, n, _MAX_IMAGE_DIMENSION_1D;) \


#define PRED(r, state) \
BOOST_PP_NOT_EQUAL ( \
BOOST_PP_TUPLE_ELEM (2, 0, state), \
BOOST_PP_INC (BOOST_PP_TUPLE_ELEM (2, 1, state)) \
) \
/**/

#define OP(r, state) \
( \
BOOST_PP_INC (BOOST_PP_TUPLE_ELEM (2, 0, state)), \
BOOST_PP_TUPLE_ELEM (2, 1, state) \
) \
/**/

#define CAT_MID (x) BOOST_PP_CAT (BOOST_PP_CAT (x, BOOST_PP_CAT (y, z))

#define MACRO5(n) \
template <> \
struct gpu <n> \
{ \
static constexpr uint32_t max_image_dimension_1D =  BOOST_PP_CAT (GPU_, n);\
};

#define MACRO4(r, state) MACRO5 (BOOST_BOOST_PP_TUPLE_ELEM (2, 0, state))
#include "gpu_gen_definitions.hpp"


#define MACRO6(z, n, text) \
struct gpu <n> \
{ \
static constexpr uint32_t max_image_dimension_1D =  BOOST_PP_CAT (GPU_, n);\
};


#define CAT(x) BOOST_PP_SEQ_CAT (x)

#define NL \n
#define TB \t

#define DECL(z, n, text) \
struct gpu <n> NL \
{ NL \
TB struct properties NL \
TB { NL \
TB TB limits NL \
TB TB { NL \
TB TB TB static constexpr uint32_t max_image_dimension_1D =  CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D)); NL \
TB TB TB static constexpr uint32_t              maxImageDimension2D = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D)); NL \
TB TB TB static constexpr uint32_t              maxImageDimension3D = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_1D));  NL \
TB TB TB static constexpr uint32_t              maxImageDimensionCube = CAT ((GPU_) (n) (_MAX_IMAGE_DIMENSION_CUBE));  NL \
TB TB TB static constexpr uint32_t              maxImageArrayLayers = CAT ((GPU_) (n) (_MAX_IMAGE_ARRAY_LAYERS));  NL \
TB TB TB static constexpr uint32_t              maxTexelBufferElements = CAT ((GPU_) (n) (_MAX_TEXEL_BUFFER_ELEMENTS));  NL \
TB TB TB static constexpr uint32_t              maxUniformBufferRange = CAT ((GPU_) (n) (_MAX_UNIFORM_BUFFER_RANGE));  NL \
TB TB TB static constexpr uint32_t              maxStorageBufferRange = CAT ((GPU_) (n) (_MAX_STORAGE_BUFFER_RANGE));  NL \
TB TB TB static constexpr uint32_t              maxPushConstantsSize = CAT ((GPU_) (n) (_MAX_PUSH_CONSTANTS_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxMemoryAllocationCount = CAT ((GPU_) (n) (_MAX_MEMORY_ALLOCATION_COUNT));  NL \
TB TB TB static constexpr uint32_t              maxSamplerAllocationCount = CAT ((GPU_) (n) (_MAX_SAMPLER_ALLOCATION_COUNT));  NL \
TB TB TB static constexpr uint64_t          bufferImageGranularity = CAT ((GPU_) (n) (_BUFFER_IMAGE_GRANULARITY));  NL \
TB TB TB static constexpr uint64_t          sparseAddressSpaceSize = CAT ((GPU_) (n) (_SPARSE_ADDRESS_SPACE_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxBoundDescriptorSets = CAT ((GPU_) (n) (_MAX_BOUND_DESCRIPTOR_SETS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorSamplers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_SAMPLERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorUniformBuffers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_UNIFORM_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorStorageBuffers = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_STORAGE_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorSampledImages = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_SAMPLED_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorStorageImages = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_STORAGE_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxPerStageDescriptorInputAttachments = CAT ((GPU_) (n) (_MAX_PER_STAGE_DESCRIPTOR_INPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxPerStageResources = CAT ((GPU_) (n) (_MAX_PER_STAGE_RESOURCES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetSamplers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_SAMPLERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetUniformBuffers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetUniformBuffersDynamic = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS_DYNAMIC));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageBuffers = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageBuffersDynamic = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS_DYNAMIC));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetSampledImages = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_SAMPLED_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetStorageImages = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_STORAGE_IMAGES));  NL \
TB TB TB static constexpr uint32_t              maxDescriptorSetInputAttachments = CAT ((GPU_) (n) (_MAX_DESCRIPTOR_SET_INPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputAttributes = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_ATTRIBUTES));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputBindings = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_BINDINGS));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputAttributeOffset = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxVertexInputBindingStride = CAT ((GPU_) (n) (_MAX_VERTEX_INPUT_BINDING_STRIDE));  NL \
TB TB TB static constexpr uint32_t              maxVertexOutputComponents = CAT ((GPU_) (n) (_MAX_VERTEX_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationGenerationLevel = CAT ((GPU_) (n) (_MAX_TESSELLATION_GENERATION_LEVEL));  NL \
TB TB TB static constexpr uint32_t              maxTessellationPatchSize = CAT ((GPU_) (n) (_MAX_TESSELLATION_PATCH_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerVertexInputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_VERTEX_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerVertexOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_VERTEX_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlPerPatchOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_PER_PATCH_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationControlTotalOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_CONTROL_TOTAL_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationEvaluationInputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_EVALUATION_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxTessellationEvaluationOutputComponents = CAT ((GPU_) (n) (_MAX_TESSELLATION_EVALUATION_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryShaderInvocations = CAT ((GPU_) (n) (_MAX_GEOMETRY_SHADER_INVOCATIONS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryInputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryOutputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxGeometryOutputVertices = CAT ((GPU_) (n) (_MAX_GEOMETRY_OUTPUT_VERTICES));  NL \
TB TB TB static constexpr uint32_t              maxGeometryTotalOutputComponents = CAT ((GPU_) (n) (_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentInputComponents = CAT ((GPU_) (n) (_MAX_FRAGMENT_INPUT_COMPONENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentOutputAttachments = CAT ((GPU_) (n) (_MAX_FRAGMENT_OUTPUT_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentDualSrcAttachments = CAT ((GPU_) (n) (_MAX_FRAGMENT_DUAL_SRC_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t              maxFragmentCombinedOutputResources = CAT ((GPU_) (n) (_MAX_FRAGMENT_COMBINED_OUTPUT_RESOURCES));  NL \
TB TB TB static constexpr uint32_t              maxComputeSharedMemorySize = CAT ((GPU_) (n) (_MAX_COMPUTE_SHARED_MEMORY_SIZE));  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupCount[3] = {CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_0)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_1)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_COUNT_2))};  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupInvocations = CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_INVOCATIONS));  NL \
TB TB TB static constexpr uint32_t              maxComputeWorkGroupSize[3] = {CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_0)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_1)), CAT ((GPU_) (n) (_MAX_COMPUTE_WORK_GROUP_SIZE_2))};  NL \
TB TB TB static constexpr uint32_t              subPixelPrecisionBits = CAT ((GPU_) (n) (_SUB_PIXEL_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              subTexelPrecisionBits = CAT ((GPU_) (n) (_SUB_TEXEL_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              mipmapPrecisionBits = CAT ((GPU_) (n) (_MIPMAP_PRECISION_BITS));  NL \
TB TB TB static constexpr uint32_t              maxDrawIndexedIndexValue = CAT ((GPU_) (n) (_MAX_DRAW_INDEXED_INDEX_VALUE));  NL \
TB TB TB static constexpr uint32_t              maxDrawIndirectCount = CAT ((GPU_) (n) (_MAX_DRAW_INDIRECT_COUNT));  NL \
TB TB TB static constexpr float                 maxSamplerLodBias = CAT ((GPU_) (n) (_MAX_SAMPLER_LOD_BIAS));  NL \
TB TB TB static constexpr float                 maxSamplerAnisotropy = CAT ((GPU_) (n) (_MAX_SAMPLER_ANISOTROPY));  NL \
TB TB TB static constexpr uint32_t              maxViewports = CAT ((GPU_) (n) (_MAX_VIEWPORTS));  NL \
TB TB TB static constexpr uint32_t              maxViewportDimensions[2] = {CAT ((GPU_) (n) (_MAX_VIEWPORT_DIMENSIONS_0)), CAT ((GPU_) (n) (_MAX_VIEWPORT_DIMENSIONS_1))};  NL \
TB TB TB static constexpr uint32_t              viewportBoundsRange[2] = {CAT ((GPU_) (n) (_VIEWPORT_BOUNDS_RANGE_0)), CAT ((GPU_) (n) (_VIEWPORT_BOUNDS_RANGE_1))};  NL \
TB TB TB static constexpr uint32_t              viewportSubPixelBits = CAT ((GPU_) (n) (_VIEWPORT_SUB_PIXEL_BITS));  NL \
TB TB TB static constexpr size_t                minMemoryMapAlignment = CAT ((GPU_) (n) (_MIN_MEMORY_MAP_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minTexelBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_TEXEL_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minUniformBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_UNIFORM_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          minStorageBufferOffsetAlignment = CAT ((GPU_) (n) (_MIN_STORAGE_BUFFER_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr int32_t               minTexelOffset = CAT ((GPU_) (n) (_MIN_TEXEL_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxTexelOffset = CAT ((GPU_) (n) (_MAX_TEXEL_OFFSET));  NL \
TB TB TB static constexpr int32_t               minTexelGatherOffset = CAT ((GPU_) (n) (_MIN_TEXEL_GATHER_OFFSET));  NL \
TB TB TB static constexpr uint32_t              maxTexelGatherOffset = CAT ((GPU_) (n) (_MAX_TEXEL_GATHER_OFFSET));  NL \
TB TB TB static constexpr float                 minInterpolationOffset = CAT ((GPU_) (n) (_MIN_INTERPOLATION_OFFSET));  NL \
TB TB TB static constexpr float                 maxInterpolationOffset = CAT ((GPU_) (n) (_MAX_INTERPOLATION_OFFSET));  NL \
TB TB TB static constexpr uint32_t              subPixelInterpolationOffsetBits = CAT ((GPU_) (n) (_SUB_PIXEL_INTERPOLATION_OFFSET_BITS));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferWidth = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_WIDTH));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferHeight = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_HEIGHT));  NL \
TB TB TB static constexpr uint32_t              maxFramebufferLayers = CAT ((GPU_) (n) (_MAX_FRAMEBUFFER_LAYERS));  NL \
TB TB TB static constexpr uint32_t    framebufferColorSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_COLOR_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferDepthSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_DEPTH_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferStencilSampleCounts = CAT ((GPU_) (n) (_FRAME_BUFFER_STENCIL_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    framebufferNoAttachmentsSampleCounts = CAT ((GPU_) (n) (_FRAMEBUFFER_NO_ATTACHMENTS_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t              maxColorAttachments = CAT ((GPU_) (n) (_MAX_COLOR_ATTACHMENTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageColorSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_COLOR_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageIntegerSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_INTEGER_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageDepthSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_DEPTH_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    sampledImageStencilSampleCounts = CAT ((GPU_) (n) (_SAMPLED_IMAGE_STENCIL_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t    storageImageSampleCounts = CAT ((GPU_) (n) (_STORAGE_IMAGE_SAMPLE_COUNTS));  NL \
TB TB TB static constexpr uint32_t              maxSampleMaskWords = CAT ((GPU_) (n) (_MAX_SAMPLE_MASK_WORDS));  NL \
TB TB TB static constexpr uint32_t              timestampComputeAndGraphics = CAT ((GPU_) (n) (_TIMESTAMP_COMPUTE_AND_GRAPHICS));  NL \
TB TB TB static constexpr float                 timestampPeriod = CAT ((GPU_) (n) (_TIMESTAMP_PERIOD));  NL \
TB TB TB static constexpr uint32_t              maxClipDistances = CAT ((GPU_) (n) (_MAX_CLIP_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              maxCullDistances = CAT ((GPU_) (n) (_MAX_CULL_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              maxCombinedClipAndCullDistances = CAT ((GPU_) (n) (_MAX_COMBINED_CLIP_AND_CULL_DISTANCES));  NL \
TB TB TB static constexpr uint32_t              discreteQueuePriorities = CAT ((GPU_) (n) (_DISCRETE_QUEUE_PRIORITIES));  NL \
TB TB TB static constexpr uint32_t              pointSizeRange[2] = {CAT ((GPU_) (n) (_POINT_SIZE_RANGE_0)), CAT ((GPU_) (n) (_POINT_SIZE_RANGE_1))};  NL \
TB TB TB static constexpr uint32_t              lineWidthRange[2] = {CAT ((GPU_) (n) (_LINE_WIDTH_RANGE_0)), CAT ((GPU_) (n) (_LINE_WIDTH_RANGE_1))};  NL \
TB TB TB static constexpr float                 pointSizeGranularity = CAT ((GPU_) (n) (_POINT_SIZE_GRANULARITY));  NL \
TB TB TB static constexpr float                 lineWidthGranularity = CAT ((GPU_) (n) (_LINE_WIDTH_GRANULARITY));  NL \
TB TB TB static constexpr uint32_t              strictLines = CAT ((GPU_) (n) (_STRICT_LINES));  NL \
TB TB TB static constexpr uint32_t              standardSampleLocations = CAT ((GPU_) (n) (_STANDARD_SAMPLE_LOCATIONS));  NL \
TB TB TB static constexpr uint64_t          optimalBufferCopyOffsetAlignment = CAT ((GPU_) (n) (_OPTIMAL_BUFFER_COPY_OFFSET_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          optimalBufferCopyRowPitchAlignment = CAT ((GPU_) (n) (_OPTIMAL_BUFFER_COPY_ROW_PITCH_ALIGNMENT));  NL \
TB TB TB static constexpr uint64_t          nonCoherentAtomSize = CAT ((GPU_) (n) (_NON_COHERENT_ATOM_SIZE));  NL \
TB TB }; NL \
TB }; NL \
}; NL NL



#define BB(x)

#define AA(x) BOOST_PP_IF (string (BOOST_PP_STRINGIZE (x) == string ("hej"), BOOST_PP_IDENTITY (BOOST_PP_STRINGIZE (x)), BOOST_PP_EMPTY ())

// cout << BOOST_PP_STRINGIZE(BOOST_PP_FOR((5, 10, kiss), PRED, OP, MACRO4)) << endl; // expands to 5 6 7 8 9 10)
int main (int argc, const char * argv[])
{
      
      
      cout << BOOST_PP_STRINGIZE (BOOST_PP_REPEAT(1, DECL, int x)) << endl;
      
      
//       cout << BOOST_PP_STRINGIZE (BOOST_PP_FOR ((0, BOOST_PP_DEC (GPU_COUNT), kiss), PRED, OP, MACRO4)) << endl; // expands to 5 6 7 8 9 10)

      return 0;
//      BOOST_PP_REPEAT
//      BOOST_PP_REA
//      BOOST_PP_REPEAT (GPU_COUNT, TINY_size, ~)
      
      file <write> header (argv [1]);
      header << "#pragma once \n";
      header << "#include <iostream>\n";
      
      header << "namespace{\n";
      header << readFileIntoString (GENERATED_INCLUDE_FILE);
      header << "}\n";
      
      PROCC((
             template <int>                                                                                                   \n
             struct gpu;                                                                                                   \n\n
             
             template <>                                                                                                         \n
             struct gpu <${i}>                                                                                                   \n
             {                                                                                                   \n\t
            static constexpr int fitta = GPU_COUNT;                                                                                                   \n\t
            static constexpr int count = GPU_COUNT;                                                                                                   \n\t
            static constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;                                                                                                   \n
      };\n

             )(GPU_COUNT)
            (string gpu_class_header))
      
      header << gpu_class_header;
      
      
//      PROCC((
//             template <>
//             struct gpu <${i}>
//             {
//                  static constexpr int fitta = GPU_COUNT;
//                  static constexpr int count = GPU_COUNT;
//                  static constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;
//             };
//
//             )(GPU_COUNT)
//            (string gpu_class_header))
      
//      PROCC((
//             template <>
//             struct gpu <${i}>
//             {
//            static constexpr int fitta = GPU_COUNT;
//            static constexpr int count = GPU_COUNT;
//            static constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;
//      };
//
//             )(1)
//            (string gpu_class_source))
      
      
      

//      file <write> source (generate_source_file);
//      source << "#include \"" << generate_header_file << "\"\n";
//      source << "#include <iostream>\n";
//      source << readFileIntoString (GENERATED_INCLUDE_FILE);
//      source << gpu_class_source;
      
      
//      header << gpu_class_header;
      
      

      
      
      
      
     
      
      return 0;
      
      
     
      
      
      
      file <write> myfile (argv[1]);
//      string template_string = readFileIntoString (TEMPLATE_FILE);
      glfwInit();
      auto instanceExtensions = []{
            uint32_t extensionCount = 0;
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
            vector<VkExtensionProperties> extensions (extensionCount);
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
            return extensions;
      }();
      auto instanceValidationLayers = []{
            uint32_t layerCount = 0;
            vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
            vector<VkLayerProperties> availableLayers (layerCount);
            vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
            return availableLayers;
      }();
      auto instance = []{
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
            
            VkInstanceCreateInfo createInfo
            {
                  .sType                        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .pApplicationInfo             = &appInfo,
                  .enabledExtensionCount        = 0,//glfwExtensionCount,
                  .ppEnabledExtensionNames      = nullptr,//glfwExtensions,
                  .enabledLayerCount            = 0
            };
            

            
            
            
            if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            {
                  throw runtime_error ("failed to create instance");
            }
            return instance;
      }();
      auto physicalDevices = [&instance] {
            uint32_t deviceCount = 0;
            vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
            vector<VkPhysicalDevice> devices (deviceCount);
            vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
            return devices;
      }();
      
 
      
      
      auto getPhysicalDeviceProperties = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(physicalDevice, &properties);
            return properties;
      };
      auto getPhysicalDeviceFeatures = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceFeatures features;
            vkGetPhysicalDeviceFeatures(physicalDevice, &features);
            return features;
      };
      
      [&]{
            for (auto& i : instanceExtensions)
                  cout << "\t" << i.extensionName << endl;
            
            cout << endl;
            
            for (auto& i : instanceValidationLayers)
                  cout << "\t" << i.layerName << endl;
      };
      

      

      int nr_of_gpus = 0;
      
      for (auto& i : physicalDevices)
      {
            auto props = getPhysicalDeviceProperties (i);
            auto feats = getPhysicalDeviceFeatures (i);
            VkPhysicalDeviceLimits limits = props.limits;
            auto _int = to_string (nr_of_gpus);
            
            
            
            

      
            
                       

            break;
            
            
            
            
            
            string gpu = "#define GPU_" + to_string (nr_of_gpus);
            
            
//            myfile << gpu + "_NAME = \"" + props.deviceName + "\"";
            
            
            {
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_1D = " + to_string (limits.maxImageDimension1D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_2D = " + to_string (limits.maxImageDimension2D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_3D = " + to_string (limits.maxImageDimension3D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_CUBE = " + to_string (limits.maxImageDimensionCube);
//                  myfile << endl << gpu + "_MAX_IMAGE_ARRAY_LAYERS = " + to_string (limits.maxImageArrayLayers);
//                  myfile << endl << gpu + "_MAX_TEXEL_BUFFER_ELEMENTS = " + to_string (limits.maxTexelBufferElements);
//                  myfile << endl << gpu + "_MAX_UNIFORM_BUFFER_RANGE = " + to_string (limits.maxUniformBufferRange);
//                  myfile << endl << gpu + "_MAX_STORAGE_BUFFER_RANGE = " + to_string (limits.maxStorageBufferRange);
//                  myfile << endl << gpu + "_MAX_PUSH_CONSTANTS_SIZE = " + to_string (limits.maxPushConstantsSize);
//                  myfile << endl << gpu + "_MAX_MEMORY_ALLOCATION_COUNT = " + to_string (limits.maxMemoryAllocationCount);
//                  myfile << endl << gpu + "_MAX_SAMPLER_ALLOCATION_COUNT = " + to_string (limits.maxSamplerAllocationCount);
//                  myfile << endl << gpu + "_BUFFER_IMAGE_GRANULARIY = " + to_string (limits.bufferImageGranularity);
//                  myfile << endl << gpu + "_SPARSE_ADDRESS_SPACE_SIZE = " + to_string (limits.sparseAddressSpaceSize);
//                  myfile << endl << gpu + "_MAX_BOUND_DESCRIPTOR_SETS = " + to_string (limits.maxBoundDescriptorSets);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLERS = " + to_string (limits.maxPerStageDescriptorSamplers);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_UNIFORM_BUFFERS = " + to_string (limits.maxPerStageDescriptorUniformBuffers);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLED_IMAGES = " + to_string (limits.maxPerStageDescriptorSampledImages);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_STORAGE_IMAGES = " + to_string (limits.maxPerStageDescriptorStorageImages);
//
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_INPUT_ATTACHMENTS = " + to_string (limits.maxPerStageDescriptorInputAttachments);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_RESOURCES = " + to_string (limits.maxPerStageResources);
//                  myfile << endl << gpu + "_MAX_PER_SET_SAMPLERS= " + to_string (limits.maxDescriptorSetSamplers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS = " + to_string (limits.maxDescriptorSetUniformBuffers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetUniformBuffersDynamic);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS = " + to_string (limits.maxDescriptorSetStorageBuffers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetStorageBuffersDynamic);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_SAMPLED_IMAGES = " + to_string (limits.maxDescriptorSetSampledImages);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_IMAGES = " + to_string (limits.maxDescriptorSetStorageImages);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_INPUT_ATTACHMENTS = " + to_string (limits.maxDescriptorSetInputAttachments);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTES = " + to_string (limits.maxVertexInputAttributes);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDINGS = " + to_string (limits.maxVertexInputBindings);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET = " + to_string (limits.maxVertexInputAttributeOffset);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDING_STRIDE = " + to_string (limits.maxVertexInputBindingStride);
//                  myfile << endl << gpu + "_MAX_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxVertexOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_GENERATION_LEVEL = " + to_string (limits.maxTessellationGenerationLevel);
//                  myfile << endl << gpu + "_MAX_PER_TESSELLATION_PATCH_SIZE = " + to_string (limits.maxTessellationPatchSize);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_INPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_PATCH_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerPatchOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_TOTAL_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlTotalOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_INPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationOutputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_SHADER_INVOCATIONS = " + to_string (limits.maxGeometryShaderInvocations);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_OUTPUT_COMPONENTS = " + to_string (limits.maxGeometryOutputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_OUTPUT_VERTICES = " + to_string (limits.maxGeometryOutputVertices);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = " + to_string (limits.maxGeometryTotalOutputComponents);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_INPUT_COMPONENTS= " + to_string (limits.maxFragmentInputComponents);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_OUTPUT_ATTACHMENTS = " + to_string (limits.maxFragmentOutputAttachments);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_DUAL_SRC_ATTACHMENTS = " + to_string (limits.maxFragmentDualSrcAttachments);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_COMBINED_OUTPUT_RESOURCES = " + to_string (limits.maxFragmentCombinedOutputResources);
//                  myfile << endl << gpu + "_MAX_COMPUTE_SHARED_MEMORY_SIZE = " + to_string (limits.maxComputeSharedMemorySize);
//                  //            myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_COUNT = " + to_string (limits.maxComputeWorkGroupCount);
//                  myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = " + to_string (limits.maxComputeWorkGroupInvocations);
//                  //            myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_SIZE = " + to_string (limits.maxComputeWorkGroupSize);
//                  myfile << endl << gpu + "_SUB_PIXEL_PRECISION_BITS = " + to_string (limits.subPixelPrecisionBits);
//                  myfile << endl << gpu + "_SUB_TEXEL_PRECISION_BITS = " + to_string (limits.subTexelPrecisionBits);
//                  myfile << endl << gpu + "_MIPMAP_PRECISION_BITS = " + to_string (limits.mipmapPrecisionBits);
//                  myfile << endl << gpu + "_MAX_DRAW_INDEXED_INDEX_VALUE = " + to_string (limits.maxDrawIndexedIndexValue);
//                  myfile << endl << gpu + "_MAX_DRAW_INDIRECT_COUNT = " + to_string (limits.maxDrawIndirectCount);
//                  myfile << endl << gpu + "_MAX_SAMPLER_LOD_BIAS = " + to_string (limits.maxSamplerLodBias);
//                  myfile << endl << gpu + "_MAX_SAMPLER_ANISOTROPY = " + to_string (limits.maxSamplerAnisotropy);
//                  myfile << endl << gpu + "_MAX_VIEWPORTS = " + to_string (limits.maxViewports);
            }
            
            


                                                                                                  

            
            
//            cout << "\t" <<  props.deviceName << endl;
//            cout << "\t" <<  props.deviceType << endl;
//            cout << "\t" <<  props.limits << endl;
            ++nr_of_gpus;
      }
      
            
      
              
      
      
      

      
//      system("echo \"struct snoppen{};\" > graphics_info.hpp");
//      std::cout << argc << " " << argv[0] << std::endl;
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
//      system("open graphics_info.hpp");
      return 0;
}


