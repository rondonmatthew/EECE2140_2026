#include <iostream>
#include <string>
#include "denoise.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Usage: denoise <input.txt> <output.txt> <mean | median> <iterations>\n";
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];
    string filterType = argv [3];
    int iterations = stoi(argv[4]);

    if (filterType != "mean" && filterType != "median") {
        cout << "Error: fiolter must be 'mean' or 'median'\n";
        return 1;
    }

    if (iterations < 1) {
        cout << "Error: iterations must be at least 1\n";
        return 1;
    }

    vector<vector<int>> image = loadImage(inputFile);
    vector<vector<int>> output = applyDenoise(image, filterType, iterations);
    saveImage(outputFile, output);

    cout << "Finished. Output written to: " << outputFile << "\n";
    return 0;
}
