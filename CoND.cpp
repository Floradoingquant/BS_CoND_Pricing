//CoND.cpp
#include "CoND.h"
#include "Sampler.h"
#include<ctime>
#include<cmath>
#include<iostream>

//the following code have structures extracted from MA323 class worksheet 4
double CoND::computepriceMC(double S0, double sigma, double r, double T, int n) //code from worksheet 3
{
    NormalSampler mystdnormal(0.0, 1.0);
    double mysum=0.0;
    double MCprice=0.0;
    double onenormal, spot, tmppayoff;

	for (int i=0; i < n; i++)
	{
		onenormal = mystdnormal.getnumber();
		spot=S0*exp((r-0.5*sigma*sigma)*T + sigma*sqrt(T)*onenormal);
		tmppayoff = computepayoff(spot);
		mysum+=tmppayoff;
     }
    MCprice=mysum*exp(-r*T)/n; //Don't forget discounting!
	return MCprice;
}

double CoND::computepriceAV(double S0, double sigma, double r, double T, int n) //code from worksheet 4
{
    NormalSampler mystdnormal(0.0, 1.0);
    double mysum=0.0;
    double AVprice=0.0;
    double onenormal, spot1, spot2, tmppayoff;

	for (int i=0; i < n; i++)
	{
		onenormal = mystdnormal.getnumber();
		spot1=S0*exp((r-0.5*sigma*sigma)*T + sigma*sqrt(T)*onenormal);
		spot2=S0*exp((r-0.5*sigma*sigma)*T + sigma*sqrt(T)*onenormal*(-1.0));
		tmppayoff = 0.5*(computepayoff(spot1) + computepayoff(spot2));
		mysum+=tmppayoff;
     }
    AVprice=mysum*exp(-r*T)/n; //Don't forget discounting!
	return AVprice;

}

CoNDCall::CoNDCall(double H, double C)
{
    strike=H;
    cash=C;
}

double CoNDCall::computepayoff(double spot)
{
    double res=0.0;
    if (spot >=strike){res=cash;}
    return res;
}

