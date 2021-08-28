#include "measures.h"
#include "StopWatch.h"

#include <iomanip>
#include <utility>
#include <iostream>

void gotoxy(short x, short y)
{
    COORD coord;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle, coord);
}

void clear() {
    system("cls");
}

measures::measures(std::vector<std::string> names,
                   std::vector<std::function<double(double, unsigned)>> algorithms) {
    generate_exponents();
    algorithm_names = std::move(names);
    this->algorithms = std::move(algorithms);
}

void measures::generate_exponents() {
    exponents = std::vector<int>(600);
    for(int k = 0; k < 600; k++){
        exponents[k] = k;
    }
}

std::list<measurement> measures::perform_measurements() {
    std::list<measurement> results;
    clear();
    std::cout << "MEASURING SPEED OF DIFFERENT POWERING ALGORITHMS" << std::endl
            << "Algorithm: " << std::endl << "Exponent:     out of " << exponents.size();
    for(int i = 0; i < algorithms.size(); i++){
        gotoxy(12, 1);
        std::cout << std::setw(20) << std::left << algorithm_names[i];
        std::cout << "(" << std::setw(2) << i + 1 << " out of "
                    << std::setw(2) << algorithm_names.size() << ")";
        for(int exponent : exponents){
            gotoxy(10, 2);
            std::cout << std::setw(3) << std::right << exponent + 1;
            measurement res = single_measurement(i, exponent);
            results.push_back(res);
        }
    }
    return results;
}

measurement measures::single_measurement(size_t algorithm_index, int exponent) {
    measurement result;
    result.algorithm = algorithm_names[algorithm_index];
    result.exponent = exponent;
    result.time = 0;
    for(int i = 0; i < 1000000; i++){
        StopWatch watch;
        watch.start();
        double power = algorithms[algorithm_index](base, exponent);
        watch.stop();
        power -=1;
        result.time += watch.getLastMeasurmentPiccosec();
    }
    return result;
}
