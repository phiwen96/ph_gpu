//#include <ph_gpu/ph_gpu.hpp>
#include <ph_gpu/gpu.hpp>
#include <iostream>
using namespace std;

consteval int ja ()
{
    return gpu<0>::queueFamilyCount;
}

int main ()
{
    constexpr int q = ja();
    cout << q << endl;
    cout << gpu<0>::properties::limits::nonCoherentAtomSize << endl;
      cout << GPU_COUNT << endl;
      cout << "hi" << endl;
      return 0;
}


