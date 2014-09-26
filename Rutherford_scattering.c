#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

double BEAM_ENERGY=10.;     // Beam energy in KeV's (our expression for energy loss is for low energy ranges)
double TARGET_RADIUS=0.0001;
double TARGET_AREA=3.14159*TARGET_RADIUS*TARGET_RADIUS;
int Z=78;                   //atomic number of target, in this case platium
double density=0.02145;      //density in kg/cm^3

double Na=6.02*pow(10,23);     //Avogadro's number

double Ei,Es,Ef;    //Initial Energy, energy at the scattering point, final (exit) energy
double Si,Sf;       //Path length before scattering, path length from scattering to exit
double Psi,Phi;     //Scattering angles (psi is around Z, beam axis; phi is angle away from Z)

double z;           //used for smearing of incident energy
double k=0.01;           //used to scale z^



srand((unsigned)time(NULL));  //seeding rand with time

z=sqrt(-2*log((double)rand()/RAND_MAX))*cos(6.28318*(double)rand()/RAND_MAX);

Ei=BEAM_ENERGY*(1+k*z);

//First let's calculate some thing's we will need to do the problem
double alpha;
double cross_section;
double csconstant=5.21*pow(10,-21);
//
//
//getting the cross section
alpha=(3.4*0.001)*(pow(Z,0.67)/Ei);
cross_section=csconstant*(Z*Z/Ei/Ei)*(12.56637/(alpha+alpha*alpha))*((Ei*Ei+1022*Ei+261121)/(Ei*Ei+Ei*2044+1044484));
//
//get the mean free path
double lambda;
//
lambda=TARGET_AREA/(Na*density*cross_section);  // mean free path
Si=-1*lambda*log((double)rand()/RAND_MAX);      // path of our test electron (smeared by exponential decay?)
//
//get the energy loss per centimeter
double energy_loss;
double J;
//
J=(9.76*Z)*(58.5/(pow(Z,0.19)))*(0.001);
energy_loss=-78500*(density*Z)*log(1+1.166*BEAM_ENERGY/J)/(BEAM_ENERGY*TARGET_AREA);
//
//get the energy at the scattering point (Ei-energy_loss*Si)
Es=Ei+Si*energy_loss;
//
//get scattering angles
double cosinephi;
//
cosinephi=1-(2*alpha*(double)rand()/RAND_MAX)/(1+alpha-(double)rand()/RAND_MAX);
Phi=acos(cosinephi);
Psi=2*3.14159*(double)rand()/RAND_MAX;
//
//get path length from scattering to exiting the object
Sf=TARGET_RADIUS*sin(Phi);
//
//get exit energy
Ef=Es+Sf*energy_loss;
//
//print results
printf("The beam energy is %f KeV\n",BEAM_ENERGY);
printf("The incident electron energy is %f KeV\n",Ei);
printf("Alpha is %f\n",alpha);
printf("The cross section is %f\n",cross_section);
printf("The mean free path is %f nm\n",lambda*10000000);
printf("The rate of energy loss per cm is %f\n",energy_loss);
printf("The distance travelled before scattering is %f nm\n",Si*10000000);
printf("The electron energy upon scattering is %f\n",Es);
printf("The distance travelled after scattering is %f nm\n",Sf*10000000);
printf("The scattering angles are: %f for Phi\n and %f for Psi\n",Phi,Psi);
printf("The exit energy of the electron is %f\n",Ef);
    return(0);
        }
