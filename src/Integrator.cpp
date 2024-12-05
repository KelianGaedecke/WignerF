#include "Integrator.hpp"
#include <stdexcept>
#include <fstream>   
#include <iostream>
#include <cmath>
#include <random>
#include <stdexcept>


namespace INT {
    double MedianS(std::function<double(double)> f, double a, double b) {
        double m = (a + b) / 2.0;
        return (b - a) / 6.0 * (f(a) + 4.0 * f(m) + f(b));
    }
    
    double adaptiveSimpson(std::function<double(double)> f, double a, double b, double tol){
        
        double m = (a + b)/2.0;
        double I1 = MedianS(f,a,b);
        double I2 = MedianS(f,a,m) + MedianS(f,m,b);

        if (std::abs(I1-I2) < 15.0 * tol) {
            return I2 + (I2 - I1) / 15.0;
        }
        else {
            return adaptiveSimpson(f,a,m,tol * 0.5) + adaptiveSimpson(f,m,b,tol * 0.5);
        }
    }
}