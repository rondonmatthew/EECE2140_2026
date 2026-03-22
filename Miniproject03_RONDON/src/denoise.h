#ifndef DENOISE_H
#define DENOISE_H

#include <vector>
#include <string>


std::vector<std::vector<int>> loadImage(const std::string& filename);
void saveImage(const std::string& filename, const std::vector<std::vector<int>>& image);

std::vector<std::vector<int>> applyDenoise(const std::vector<std::vector<int>>& image, const std::string& filterType,int iterations);
#endif
