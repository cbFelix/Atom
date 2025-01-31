#include <stdexcept>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <cmath>

const long double DALTON = 1.66053906892e-27;                    // kg
const long double ELECTRONMASS = 9.1093837e-31;         // kg
const long double NEUTRONMASS = 1.67492749804e-27;          // kg
const long double PROTONMASS = 1.67262192e-27;          // kg    

double long dalton2MeV(double long mass) {
        return mass * 931.4936148385;
}

double long kg2dalton(long double mass) {
        return mass / DALTON;
}

class Atom{
public:
        Atom(unsigned int protons, unsigned int neutrons, unsigned int electrons = 0, unsigned int isotopeIndex = 1) 
        : _p(protons), _n(neutrons), _e(electrons) {

        }

        double getMass() {
                double res = _p * kg2dalton(PROTONMASS) + (_p + _n - _p) * kg2dalton(NEUTRONMASS) - (_p * kg2dalton(PROTONMASS) + _n * kg2dalton(NEUTRONMASS) - (_n + _p));

                return res;
        }

        bool isIsatope() {
                return false;
        }       

private:
        unsigned int _p;
        unsigned int _n;
        unsigned int _e;

};

class AtomSystem{
public:


private:
        std::vector<Atom> _atoms;

};

int main() {
        Atom a1(6, 8, 6);

        printf("%f\n", a1.getMass());

        return 0;
}