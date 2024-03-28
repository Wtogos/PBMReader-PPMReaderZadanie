#ifndef _PPMREADER_HPP_
#define _PPMREADER_HPP_

#include "ImageReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class PPMReader : public ImageReader {
private:

    std::ifstream imageFile;
    int width;
    int height;
    int maxColor;
    std::vector<std::vector<int>> imageData;

public:

    PPMReader(std::string imagePath);
    void printImageInfo() override;
    void printMostFrequentColor() override;
    int calculateNumberOfUniqueColors() override;
    std::pair <std::string, int> getMostFrequentColors();


};

#endif