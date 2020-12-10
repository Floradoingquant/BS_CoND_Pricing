//BSFun.cpp
//BSCall uses the CDF of the standard normal distribution from "Normals.h".
#include "BSFun.h"
#include "Normals.h"
#include <cmath>

double BSCoNDCall(double S0, double H, double C, double r, double sigma, double T) //the function design is taken from MA323 worksheet 3
{
    double d2 =(log(S0/H) + (r - sigma*sigma*0.5)*T)/(sigma*sqrt(T));
    return C*exp(-r*T)*CumulativeNormal(d2);
}

double VarofMCestimator(double S0, double H, double C, double r, double sigma, double T, int n)
{
    double d2 =(log(S0/H) + (r - sigma*sigma*0.5)*T)/(sigma*sqrt(T));
    return exp(-2*r*T)*C*C*CumulativeNormal(d2)*(1-CumulativeNormal(d2))/n;
}
