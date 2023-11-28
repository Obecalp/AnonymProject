#include "Anonym_function.h"

using namespace std;

//randomisation data (lissage aléatoire)
vector<vector<float>> AnonymData(vector<vector<float>> &RawData){
    random_device rd;  // Obtention de seed
    mt19937 gen(rd()); // Algorithme randomisation
    uniform_real_distribution<> dis(0.5, 0.8); // Critère de choix pour l'intervalle de valeur?
    uniform_real_distribution<> first(0.8, 0.9); // (..)
    vector<vector<float>> AnoData;
    vector<float> CookedData;
    for (unsigned int i=0;i<RawData[0].size();i++){
    CookedData.push_back(RawData[0][i]*first(gen));
    }
    AnoData.push_back(CookedData);
    CookedData={};

    for (unsigned int i=1;i<RawData.size();i++){
        CookedData.push_back(RawData[i][0]);
        for(unsigned int j=1;j<RawData[0].size();j++){
            CookedData.push_back(RawData[i-1][j]+(RawData[i][j]-RawData[i-1][j])*dis(gen));
        }
        AnoData.push_back(CookedData);
        CookedData={};
    }
    return AnoData;

}