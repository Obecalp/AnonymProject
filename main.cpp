#include<iostream>
#include<vector>
#include<filesystem>
#include<fstream>
#include<algorithm>
#include<sstream>

using namespace std;



vector<vector<int>> GrabMyFood(fstream &Myfood){         //Intégrer les données des constantes sous un vecteur de vecteurs, chaque "sous vecteurs" correspondant à une ligne tel que: Vecteur_final={{ligne1}...{ligne_n}}

    stringstream LectLine;
    string tempoboi;
    string line;
    vector<vector<int>>DoggoKennel;
    vector<int> Doggo;
    string header;
    string trash;
    getline(Myfood,header); //  Elimine le header
    getline(Myfood,trash); //Elimine la deuxième ligne (t -1)
    int NbVariable= count(header.begin(),header.end(),',') +1; //compter le nombre de variables à partir du header
    while (getline(Myfood,line)) // opération sur chaque ligne
    {   
        LectLine.clear();
        LectLine.str(line);   
        while(getline(LectLine,tempoboi,','))//pour chaque ligne, extraire les entiers, intégrer dans un vecteur, puis intégrer le vecteur dans le vecteur de vecteur
            {Doggo.push_back(stoi(tempoboi));}
        DoggoKennel.push_back(Doggo);
        Doggo={};
        }
        return DoggoKennel;

}
vector<vector<int>> CookMyFood(vector<vector<int>> &RawBowl){
    vector<vector<int>> CookedBowl;
    vector<int> CookedFood;
    for (unsigned int i=0;i<RawBowl[0].size();i++){
    CookedFood.push_back(RawBowl[0][i]);
    }
    CookedBowl.push_back(CookedFood);
    CookedFood={};

    for (unsigned int i=1;i<RawBowl.size();i++){
        
        for(unsigned int j=0;j<RawBowl[0].size();j++){
            CookedFood.push_back(RawBowl[i-1][j]+(RawBowl[i][j]-RawBowl[i-1][j])*0.8);
        }
        CookedBowl.push_back(CookedFood);
        CookedFood={};
    }
    return CookedBowl;

}

void FeedMyBoiz(vector<vector<int>> MyKennel, fstream MyGoodFood){

}

 // Doggo need good food (anynomisée)

int main(){
    std::filesystem::create_directory("projet_codes_LAPOUTGE_HUGO_2023_12_16__thur");
    std::fstream truckFile;
    vector<vector<int>> MyFood;
    vector<vector<int>> MyGoodFood;
    std::string chemin="DossierCible";
    vector <string> doggoes;
    /*rajoutoer un check (voir testons.cpp)
        fichier .txt
        fichier existe?
        fichier numba?
    */   
for (const auto& entry : filesystem::directory_iterator(chemin)){
    truckFile.open(entry.path().string(),ios::in);
    MyFood=GrabMyFood(truckFile); // My DoggoFood is in the truckFile, I gotta take it
    MyGoodFood=CookMyFood(MyFood); //Of course hat food is garbage, let's cook it
    truckFile.close(); //I don't need the truckFile anymore, kick him' ass!
    //MyKennel.open()

    for (unsigned int i=0;i<MyGoodFood.size();i++){
        for (unsigned int j=0;j<MyGoodFood[0].size();j++){
            cout << MyGoodFood[i][j] << ' ';
        }
        cout << endl;
}
}

}
