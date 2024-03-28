#include "PGMReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

PGMReader::PGMReader(std::string filename) {
    std::ifstream file;
    file.open(filename);
    if (!file.good()) {
        std::cout << "Nie mozna otworzyc pliku: " << filename << std::endl;
        return;
    }

    std::string formatPGM;
    std::getline(file, formatPGM);

    if (formatPGM != "P2") {
        std::cout << "Niepoprawny format PPM pliku: " << formatPGM << std::endl;
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == '#')
            continue;
        std::istringstream iss(line);
        if (!(iss >> width >> height))
            break;
        break;
    }

    int pixel;
    while (file >> pixel) {
        pixels.push_back(pixel);
    }

    file.close();
}


void PGMReader::printImageInfo() {
    std::cout << "PGM:" << std::endl;
    std::cout << "Szerokosc: " << width << std::endl;
    std::cout << "Wysokosc: " << height << std::endl;
    std::cout << "Liczba wszystkich pikseli: " << width * height << std::endl;
}

int PGMReader::calculateNumberOfUniqueColors() {
    std::map<int, int> colorCounts;
    for (int pixel : pixels) {
        colorCounts[pixel]++;
    }
    return colorCounts.size();
}

void PGMReader::printMostFrequentColor() {
    std::map<int, int> colorCounts;
    for (int pixel : pixels) {
        colorCounts[pixel]++;
    }
    if (!colorCounts.empty()) {
        auto maxColor = std::max_element(colorCounts.begin(), colorCounts.end(),
            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.second < p2.second;
            });
        std::cout << "Najczesciej wystepujacy kolor: " << maxColor->first << " (Ilosc: " << maxColor->second << ")" << std::endl;
    }
    else {
        std::cout << "Nie znaleziono kolorow." << std::endl;
    }
}
