#include <iostream>
#include "measures.h"
#include "pows.h"
#include <vector>
#include <functional>
#include <string>
#include <fstream>

int main() {
    std::cout << "Hello, World! " << std::endl;
    std::cout << "Choose name for file: ";
    std::string filename;
    std::cin >> filename;
    if(!filename.ends_with(".txt")) {
        filename = filename + ".txt";
    }
    std::vector<std::string> algorithm_names {"STANDARD", "FAST", "NAIVE"};
    std::vector<std::function<double(double, unsigned )>> algorithms
            {powers::standard, powers::fast, powers::naive};
    measures measurer = measures(algorithm_names, algorithms);
    auto results = measurer.perform_measurements();

    std::ofstream ofstream = std::ofstream(filename);
    ofstream << "ALGORITHM\tEXPONENT\tTIME\n";
    for(const measurement& meas : results) {
        ofstream << meas.algorithm << '\t'
                << meas.exponent << '\t'
                << meas.time << '\n';
    }
    return 0;
}
