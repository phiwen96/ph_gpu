#pragma once 
#include <iostream>
namespace{
#define YES 1
#if defined YES
#pragma once
constexpr int GPU_COUNT = 1;
constexpr uint32_t GPU_0_MAX_IMAGE_DIMENSION_1D = 16384;
#endif
#undef YES
}
template <int>struct gpu;