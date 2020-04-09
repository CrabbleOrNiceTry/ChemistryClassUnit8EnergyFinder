#include <iostream>

using namespace std;
class EnergyToHeatUp
{
private:
    
    double grams, startingTemp, endingTemp, deltaTemp, molarMass;

public:
    double energyChangeForIceToLiquid();
    EnergyToHeatUp(double grams, double startingTemp, double endingTemp, double molarMass); 
};

EnergyToHeatUp::EnergyToHeatUp(double grams, double startingTemp, double endingTemp, double molarMass)
{
    // temps are in celcius
    this->grams = grams;
    this->molarMass = molarMass;
    this->startingTemp = startingTemp;
    this->endingTemp = endingTemp;
    deltaTemp = endingTemp - startingTemp;
}

double EnergyToHeatUp::energyChangeForIceToLiquid()
{
    // since this is ice to liquid we use 6.02 
    double energyToGoToLiquid = ((grams / molarMass) * 6.02);
    cout << energyToGoToLiquid << endl;
    // using q = mc(DeltaT) specific heat is 4.184
    double heatWater = ((grams * 4.184) * deltaTemp) / 1000;
    cout << heatWater << endl;
    return heatWater + energyToGoToLiquid;
}


int main()
{
    EnergyToHeatUp ans(125, 0, 90, 18.016);
    cout << ans.energyChangeForIceToLiquid();
}