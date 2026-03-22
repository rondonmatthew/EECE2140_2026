# Miniproject03 - Image Denoising 
**EECE 2140 | spring 2026 | Matthew Rondon

A C++ command-line program that denoises a grayscale image represented a 2D matrix of integers (0-255) using a 3x3 neighborhood filter.

## How to Build

'''bash
clang++ -std=c++17 -Wall -Wextra src/main.cpp src/denoise.cpp -o denoise
'''

## How to Run
'''bash
./denoise
'''

**Example:**
'''bash
./denoise tests/small.txt tests/out_small.txt mean 1
./denoise tests/saltpepper.txt tests/out_saltpepper.txt median 2
'''

---

## Input / Output Format

**Input file:**
- First line: 'rows cols'
- Following lines: space-seperated integers (0-255)

**Example:**
'''
4 5
10 10 10 10 10 
10 200 10 200 10
10 10 10 10 10 
10 200 10 200 10
'''

**Output file:** same format as input, with filtered pixel values.

---

## Design Notes

### Filters
- **Mean filter:** replaces each pixel with the average of its 3x3 neighborhood (9 pixels).
- **Median filter:** replaces each pixel with the median of of its 3x3 neighborhood. Better at removing impulse (salt and pepper) noise without blurring edges as much as mean.

### Border Handling - Clamp (edge Replication)
When a 3x3 window outsode the matrix boundary, the nearest valid pixel is repeated.

### Iterations
The filter can be appplied multiple times via the '<iterations>' argument. Each pass uses the output of the previous pass as input.

---

## Demo Output

'''
$ ./denoise tests/salt.txt tests/out_saltpepper.txt median 1
Finished. Output written to: tests/out_saltpepper.txt

$ cat tests/out_saltpepper.txt
5 5
128 128 128 128 128
128 128 128 128 128
128 128 128 128 128
128 128 128 128 128
128 128 128 128 128
'''


---