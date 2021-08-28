#include "pows.h"
#include <math.h>

double powers::standard(double base, unsigned exponent) {
    return pow(base, exponent);
}

double powers::naive(double base, unsigned exponent) {
    double result = 1;
    for(unsigned i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}

double powers::fast(double base, unsigned exponent) {
    double result, curr;
    result = curr = 1;
    while(exponent){
        if(exponent & 1){
            result *= curr;
        }
        curr *= base;
        exponent = exponent >> 1;
    }
    return result;
}