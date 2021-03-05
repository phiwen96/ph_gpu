#include "main.hpp"

#include GENERATED_INSTANCE_FILE
#include GENERATED_GPU_FILE

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



#include "parse_gpu.hpp"
#include "parse_instance.hpp"






int main (int argc, const char * argv[])
{
    file <write> instance_header (argv [1]);
    instance_header << "#pragma once \n";
    instance_header << "#include <iostream>\n\n";
    
    instance_header << "struct instance \n{\n";
        instance_header << "\t\tstatic constexpr int extensionCount = " << INSTANCE_EXTENSION_COUNT << ";\n";
        instance_header << "\t\tstatic constexpr int layerCount = " << INSTANCE_LAYER_COUNT << ";\n";
        instance_header << "\n";
    
        instance_header << "\t\ttemplate <int>\n";
        instance_header << "\t\tstruct extension;\n\n";
        instance_header << "\t\ttemplate <int>\n";
        instance_header << "\t\tstruct layer;\n\n";
//        instance_header << "\tstruct extensions \n\t{\n";
//        instance_header << "\t};\n\n";
    
        instance_header << "\tstruct layer \n\t{\n";
        instance_header << "\t};\n";
    
        instance_header << BOOST_PP_STRINGIZE (BOOST_PP_REPEAT(INSTANCE_EXTENSION_COUNT, DECL_INSTANCE_EXTENSIONS, int x));
        instance_header << BOOST_PP_STRINGIZE (BOOST_PP_REPEAT(INSTANCE_LAYER_COUNT, DECL_INSTANCE_LAYERS, int x));
    
    instance_header << "};\n";
    
    
    
    file <write> gpu_header (argv [2]);
    gpu_header << "#pragma once \n";
    gpu_header << "#include <iostream>\n";
    gpu_header << "#define GPU_COUNT " << GPU_COUNT << "\n\n";
    gpu_header << "template <int>\nstruct gpu;\n\n";
    gpu_header << BOOST_PP_STRINGIZE (BOOST_PP_REPEAT(GPU_COUNT, DECL_GPU, int x));
    
    return 0;
    
    
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
    
    
    
    return 0;
}


