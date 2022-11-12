#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>

namespace Linux103
{
    class Polynomial
    {
    public:
        Polynomial() = default;

        void add(double coef, double degree);
        void print() const;
        double calculate(const double xValue) const;

	    Polynomial derive() const;

    private:
        std::vector<std::pair<double, double>> pol_;
    };
}

#endif