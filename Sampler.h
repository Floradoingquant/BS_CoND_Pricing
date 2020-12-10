//Sampler.h
#ifndef SAMPLER_H
#define SAMPLER_H

//the entire file is copied from MA323 worksheet 3, under name "Sampler.cpp"
//Note that the class Sampler is an abstract class since it contains a pure virtual function getnumber.
//You can see this from the "=0" part.

class Sampler
{
      public:
             virtual double getnumber()=0;
};


class UniformSampler:public Sampler
{
      public:
              virtual double getnumber();
              UniformSampler(double lower=0.0, double upper=1.0);

      private:
              double mylower;
              double myupper;
};

class ExponentialSampler:public Sampler
{
   public:
           virtual double getnumber();
           ExponentialSampler(double lambda=1.0);
   private:
            double mylambda;
};


class NormalSampler:public Sampler
{
   public:
           virtual double getnumber();
           NormalSampler(double mu=0.0, double sigsqrd=1.0);
   private:
            double mymu;
            double mysigmasquared;
};

class ExampleF:public Sampler
{
    public:
        virtual double getnumber();
};
#endif
