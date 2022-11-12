#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "polynomial.h"

void Linux103::Polynomial::add(double coef, double degree) {
    if(coef != 0) {
        pol_.push_back({double(degree), double(coef)});
        std::sort(pol_.begin(), pol_.end(), std::greater<std::pair<double,double>>());
    }
}

Linux103::Polynomial Linux103::Polynomial::derive() const {
    Polynomial dx;

    for(int i=0; i < pol_.size(); ++i) {
        double degree = pol_[i].first;
        double coef = pol_[i].second;
        
        dx.add(coef*degree, degree-1);
    }

    return dx;
}

double Linux103::Polynomial::calculate(const double xValue) const
{
    double value = 0;
    for(int i=0; i < pol_.size(); ++i) {
        double degree = pol_[i].first;
        double coef = pol_[i].second;
        
        value += coef*(pow(xValue, degree));
    }

    return value;
}

void Linux103::Polynomial::print() const
{
    std::cout<<pol_[0].second<<"x^"<<pol_[0].first;

    for (int i = 1; i < pol_.size(); i++)
    {
        double degree = pol_[i].first;
        double coef = pol_[i].second;
     
        if(coef > 0) std::cout<<" + ";
        else if(coef < 0) std::cout<<" - ";
        
        std::cout<<coef;
        if(int(degree) != 0) std::cout<<"x^"<<degree;
    }
    std::cout<<std::endl;
}