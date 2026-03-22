#include "denoise.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


static int clampPixel(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

static int getPixel(const vector<vector<int>>& image, int r, int c) {
    int rows = (int)image.size();
    int cols = (int)image[0].size();

    if (r < 0) r = 0;
    if (r>= rows) r = rows - 1;
    if (c<0) c = 0;
    if (c>= cols) c = cols - 1;

    return image[r][c];
}

vector<vector<int>> loadImage(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Error: could not open input file: " << filename << "\n";
        exit(1);
    }
    int rows, cols;
    in >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols,0));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int value;
            in >> value;
            image[r][c] = clampPixel(value);
        }
    }
    return image;
}

void saveImage(const string& filename, const vector<vector<int>>& image) {
    ofstream out(filename);
    if (!out) {
        cout << "Error: could not open output file: " << filename << "\n";
        exit(1);
    }
    int rows = (int)image.size();
    int cols = (int)image[0].size();

    out << rows << " " << cols << "\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            out << image[r][c];
            if (c < cols - 1) out << " ";
        }
        out << "\n";
    }
}

static int meanValue(const vector<vector<int>>& image, int r, int c) {
    int sum = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            sum += getPixel(image, r + dr, c + dc);
        }
    }
    int avg = sum / 9;
    return clampPixel(avg);
}

static int medianValue(const vector<vector<int>>& image, int r, int c) {
    int vals[9];
    int k = 0;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1;dc++) {
            vals[k] = getPixel(image, r + dr, c + dc);
            k++;
        }
    }

    sort(vals, vals + 9);
    return clampPixel(vals[4]);
}

static vector<vector<int>> onePass(const vector<vector<int>>& image, const string& filterType) {
    int rows = (int)image.size();
    int cols = (int)image[0].size();

    vector<vector<int>> result (rows, vector<int>(cols,0));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (filterType == "mean") {
                result[r][c] = meanValue(image, r, c);
            } else {
                result [r][c] = medianValue(image, r, c);
            }
        }
    }
    return result;
}

vector<vector<int>> applyDenoise(const vector<vector<int>>& image,const string& filterType, int iterations) {
    vector<vector<int>> current = image;
    for (int i = 0; i < iterations; i++) {
        current = onePass(current, filterType);
    }
    return current;
}




