## How to Build

'''bash
clang++ -std=c++17 -Wall -Wextra src/main.cpp src/denoise.cpp -o denoise
'''

# How to Run Tests

### Test 1 - Small Matrix (manual verification)
'''bash
./denoise tests/small.txt tests/out_small.txt mean 1
'''
**Expected outcome:** The two spike pixels (200) at interior positions should be averaged down significantly. 

### Test 2 - Salt and Pepper Noise
'''bash
./denoise tests/saltpepper.txt tests/out_saltpepper.txt median 1
'''
**Expected outcome:** The impulse noise pixels (0 and 255) surrounded by 128s should be replaced with 128 after one median pass, since the median of a mostly- 128neighborhood is 128.

### Test 3 - Border Behavior
'''bash
./denoise tests/borders.txt tests/out_borders.txt mean 1
'''
**Expected outcome:** Corner pixels (255) and edge pixels (0) are processed using clamped neighbors - edge pixels replicate the nearest valid pixel when the3x3 window outside the matrix.interior 128 values should remain relatively stable. no pixels should go out of range [0,255].

## Border Policy
This program uses **clamp (edge replication)**: when a filter windowextends past the matrix boundary, the nearestvaild pixel value is repeated. This is the implemented in 'getPixel()' in 'denoise.cpp'.