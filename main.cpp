#include "PGMReader.h"
#include "PPMReader.h"

int main() {
    PGMReader pgm("monalisa.pgm");
    pgm.printImageInfo();
    std::cout << "Liczba roznych kolorow: " << pgm.calculateNumberOfUniqueColors() << std::endl;
    pgm.printMostFrequentColor();

    PPMReader ppm("snail.ppm");
    ppm.printImageInfo();
    std::cout << "Liczba roznych kolorow: " << ppm.calculateNumberOfUniqueColors() << std::endl;
    ppm.printMostFrequentColor();

    return 0;
}
