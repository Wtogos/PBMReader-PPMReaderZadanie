#ifndef _PGM_READER_HPP_
#define _PGM_READER_HPP_

#include "ImageReader.h"
#include <string>
#include <vector>
#include <map>

class PGMReader : public ImageReader {
private:
    int width;
    int height;
    std::vector<int> pixels;

public:
    PGMReader(const std::string filename);

    virtual void printImageInfo() override;
    virtual int calculateNumberOfUniqueColors() override;
    virtual void printMostFrequentColor() override;
};

#endif