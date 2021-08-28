#ifndef POWERS_MEASURES_H
#define POWERS_MEASURES_H
#include <numbers>
#include <functional>

#include <vector>
#include <list>
#include <string>

class measurement {
public:
    std::string algorithm;
    uint64_t time;
    double exponent;
};

class measures {
private:
    std::vector<int> exponents;
    std::vector<std::string> algorithm_names;
    std::vector<std::function<double(double, unsigned)>> algorithms;
    double base = std::numbers::pi;

    void generate_exponents();
    measurement single_measurement(size_t algorithm_index, int exponent);

public:
    measures(std::vector<std::string>,
             std::vector<std::function<double(double, unsigned)>>);

    std::list<measurement> perform_measurements();
};

#endif //POWERS_MEASURES_H
