#include <iostream>
#include <cmath>
#include <iomanip>
#include "SimplexNoise.h"
using namespace std;

const int MAX_WIDTH = 150;

double mapRange(double val, double min1, double max1, double min2, double max2);

int main(int argc, const char * argv[]) {

    SimplexNoise simp;
    simp.init();

    clock_t start;

    int i = 0;
    while (true) {

        double duration = 0;
        start = clock();

        while (duration < CLOCKS_PER_SEC * 0.0016) {
            duration += (clock() - start) / (double) CLOCKS_PER_SEC;
        }

        //cout << simp.noise(i * 0.005, i * 0.005) << endl;

        double val = roundl(mapRange(simp.noise(i * 0.0075, i * 0.0075), -1, 1, 1, MAX_WIDTH));
        cout << right << setw(val) << setfill(' ') << "|" << endl;

        i++;
    }
    return 0;
}

double mapRange(double val, double min1, double max1, double min2, double max2) {
    double unitratio = (val - min1) / (max1 - min1);
    return (unitratio * (max2 - min2)) + min2;
}
