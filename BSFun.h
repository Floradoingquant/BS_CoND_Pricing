//BSFun.h
#ifndef BSFUN_H
#define BSFUN_H

double BSCoNDCall(double S0, double H, double C, double r, double sigma, double T);  //code taken from MA323 worksheet 3

double VarofMCestimator(double S0, double H, double C, double r, double sigma, double T, int n);

#endif
