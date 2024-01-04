#include "anonym_data.h"

using namespace std;

vector<vector<float>> AnonymData(vector<vector<float>> &RawData){
    random_device rd;  // Obtention de seed
    mt19937 gen(rd()); // Algorithme randomisation
    uniform_real_distribution<> dis(0.5, 0.8); // randomisation (r1)
    uniform_real_distribution<> first(0.8, 0.9); // randomisation arbitraire (r2)
    vector<vector<float>> AnoData;//tableau final
    vector<float> CookedData;//Ligne de valeur une fois modifiée

    for (unsigned int i=0;i<RawData[0].size();i++){
    CookedData.push_back(RawData[0][i]*first(gen)); // randomisation des valeurs du premier vector, multipliées par des valeurs dans l'intervale choisi en (r2)
    }
    AnoData.push_back(CookedData);
    CookedData={};

    for (unsigned int i=1;i<RawData.size();i++){
        CookedData.push_back(RawData[i][0]); //pas d'anonymisation du temps (donc de la première valeur) sur cet algorithme.
        for(unsigned int j=1;j<RawData[0].size();j++){
            CookedData.push_back(RawData[i-1][j]+(RawData[i][j]-RawData[i-1][j])*dis(gen)); //au lieu d'ajouter Vt2 au temps t2, ajouter Vt1+(Vt2-Vt1)*(r1) (au lieu de Vt1+(Vt2-Vt1)*1)
        }
        AnoData.push_back(CookedData);
        CookedData={};
    }
    return AnoData;

}