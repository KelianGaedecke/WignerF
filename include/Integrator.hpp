#ifndef INT_HPP
#define INT_HPP

#include <functional> 

namespace INT {
    double adaptiveSimpson(std::function<double(double)> f, double a, double b, double tol);
}

#endif