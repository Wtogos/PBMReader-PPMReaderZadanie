#include "PPMReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

PPMReader::PPMReader(string imagePath) : width(0), height(0), maxColor(0)
{
    imageFile.open(imagePath);
    if (!imageFile.good())
    {
        cout << "Nie mozna otworzyc pliku: " << imagePath << "\n";
        return;
    }

    string fileType;
    string line;
    int pixelValue;

    getline(imageFile, fileType);
    if (fileType != "P3")
    {
        cout << "Niepoprawny format PPM: " << imagePath << "\n";
        return;
    }

    while (getline(imageFile, line))
    {
        if (!line.empty() && line[0] != '#')
        {
            istringstream iss(line);
            iss >> width >> height;
            break;
        }
    }

    imageFile >> maxColor;
    imageData.resize(height, std::vector<int>(width * 3));
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width * 3; ++x)
        {
            imageFile >> pixelValue;
            imageData[y][x] = pixelValue;
        }
    }
}

void PPMReader::printImageInfo() {
    std::cout << "PPM: " << std::endl;
    std::cout << "Szerokosc: " << width << std::endl;
    std::cout << "Wysokosc: " << height << std::endl;
    std::cout << "Liczba wszystkich pikseli: " << width * height << std::endl;
}

void PPMReader::printMostFrequentColor()
{
    auto mostFrequentColor = getMostFrequentColors();
    cout << "Najczesciej wystepujacy kolor: " << mostFrequentColor.first << " (liczba wystapien: " << mostFrequentColor.second << ")" << "\n";
}

int PPMReader::calculateNumberOfUniqueColors()
{
    set<int> uniqueColors;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width * 3; ++x)
        {
            uniqueColors.insert(imageData[y][x]);
        }
    }
    return uniqueColors.size();
}

std::pair <std::string, int> PPMReader::getMostFrequentColors()
{
    map<std::string, int> colorFrequency;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width * 3; x += 3)
        {
            std::string rgb;
            rgb += std::to_string(imageData[y][x]) +
                ", " +
                std::to_string(imageData[y][x + 1]) +
                +", "
                + std::to_string(imageData[y][x + 2]);
            colorFrequency[rgb]++;
        }
    }

    std::pair <string, int> cl;
        for (const auto& pair : colorFrequency)
        {
            if (pair.second > cl.second)
            {
                cl = pair;
            }
        }

    return cl;
}
