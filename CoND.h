//CoND.h
#ifndef COND_H
#define COND_H
//the following classes originated from worksheet 3
class CoND
{
public:
    virtual double computepayoff(double spot) = 0;
    double computepriceMC(double S0, double sigma, double r, double T, int n);
    double computepriceAV(double S0, double sigma, double r, double T, int n);
};

class CoNDCall: public CoND{
private:
    double strike;
    double cash;
public:
    CoNDCall(double H, double C);
    virtual double computepayoff(double spot);
};

#endif
