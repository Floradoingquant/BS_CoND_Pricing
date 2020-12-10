//MonteCarloMain.cpp
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "Normals.h"
#include "Sampler.h"
#include "BSfun.h"
#include "CoND.h"
using namespace std;

int main()
{
//srand(time(0));
 srand(3.0);  //Could also use such a seed. This is useful if you would like to reproduce your results;

 double T=1.0;
 double H=10.0;
 double C=15.0;
 double S0=10.0;
 double sig=0.2;
 double r=0.01;
 int NumberOfPaths=1e6;

 //to calculate the BS option price
 double price1;
 price1=BSCoNDCall(S0,H,C,r,sig,T);
 cout << "The Black-Scholes Cash-or-nothing Digital Option price is " << price1 << "\n";

 //to calculate the MC price
 double price2;
 CoNDCall CDC(H,C);
 price2=CDC.computepriceMC(S0, sig, r, T, NumberOfPaths);
 cout <<"The MC price of the CoND call is " <<price2 <<"\n";

 //to calculate the confidence interval of 95% for MC estimator
 double myvar,mystdev;
 myvar=VarofMCestimator(S0, H, C, r, sig, T, NumberOfPaths);
 mystdev=sqrt(myvar);
 cout << "The variance of the MCestimator is" << myvar<< "and the standard deviation of the MCestimator is"<<mystdev<<"\n";

 //the measures for confidence intervals are from worksheet 3
 double myepsilon=0.05;
 double leftside, rightside;
 double quantile=InverseCumulativeNormal(1.0-myepsilon*0.5);
 leftside= price2-quantile*mystdev;
 rightside=price2+quantile*mystdev;
 cout << "Recall that Phi^{-1}(" <<1.0-myepsilon*0.5 <<") = " << quantile << "\n";
 cout << "MC confidence interval for confidence level ="<<1.0-myepsilon <<"  and n=" << NumberOfPaths << " is (" << leftside << " , " << rightside << ") \n";

 //to calculate the confidence interval of 99% for MCestimator
 double myepsilon1=0.01;
 double leftside1, rightside1;
 double quantile1=InverseCumulativeNormal(1.0-myepsilon1*0.5);
 leftside1= price2-quantile1*mystdev;
 rightside1=price2+quantile1*mystdev;
 cout << "Recall that Phi^{-1}(" <<1.0-myepsilon1*0.5 <<") = " << quantile1 << "\n";
 cout << "MC confidence interval for confidence level ="<<1.0-myepsilon1 <<"  and n=" << NumberOfPaths << " is (" << leftside1 << " , " << rightside1 << ") \n";

 //to calculate an antithetic variate estimate
 double price3;
 price3=CDC.computepriceAV(S0, sig, r, T, NumberOfPaths);
 cout <<"Antithetic Variate estimate for price is " <<price3 <<"\n";

 return 0;
}


 //cout <<"Checking analytical put-call-parity: put-call=" <<price3-price1 <<" and Ke^{-rT}-S0= "<<K*exp(-r*T)-S0 <<"\n";
 //cout <<"Checking MC put-call-parity: put-call=" <<price4-price2 <<" and Ke^{-rT}-S0= "<<K*exp(-r*T)-S0 <<"\n";


