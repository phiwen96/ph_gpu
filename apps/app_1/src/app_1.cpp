//#include <ph_gpu/ph_gpu.hpp>
#include <phulkan_generator/gpu.hpp>
#include "app_1.hpp"

#include <iostream>
using namespace std;

consteval int ja ()
{
    return phulkan_generator::gpu<0>::queueFamilyCount;
}

int main ()
{
    constexpr int q = ja();
    cout << q << endl;
    cout << phulkan_generator::gpu<0>::properties::limits::nonCoherentAtomSize << endl;
      cout << GPU_COUNT << endl;
      cout << "hi" << endl;
      return 0;
}


