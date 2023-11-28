#include "FileGestion.h"

using namespace std;

void CheckThisFile(string &chemin){
    char yesOrNo;
    while(filesystem::exists(chemin)==false){
        cout << "Fichier " << "\"" << chemin << "\"" << " introuvable" << "\n" << "Entrer un autre chemin?(y/n)" << endl;
        cin >> yesOrNo;
        if((yesOrNo=='y') || (yesOrNo=='Y')){cout << "Entrez le chemin correspondant au fichier contenant les séries de variables et les fichiers d'évènements correspondant: "; cin >> chemin;}
        else{exit(0);}
    }
}

//écriture d'un vecteur de vecteur dans un fichier.
//Le header ici est précisé en entrée car déjà sélectionné dans le main

void WriteThisData(vector<vector<float>> DataTab, string header,ofstream &TargetFile){
    string Line;
    TargetFile << header << endl;
     for (unsigned int i=0;i<DataTab.size();i++){
        Line="";
        Line+=to_string(int(DataTab[i].at(0)))+',';
        for (unsigned int j=1;j<DataTab[0].size();j++){
            Line+=GimmeString(DataTab[i].at(j));
            if (j <DataTab[0].size()-1)  {Line+=',';}
        }
        TargetFile << Line << endl;

}
}

//Convertion float en string, nécessaire pour passage en ofstream.
string GimmeString(float &NotAString){
    ostringstream MyString;
    MyString << NotAString;
    return MyString.str();

}

vector<vector<float>> FileToTab(fstream &Myfile, string header){

    stringstream LectLine;
    string data;
    string line;
    vector<vector<float>>GlobalTab;
    vector<float> LineTab;
    string SecondLine;
    // getline(Myfile,header); //  Elimine le header
    getline(Myfile,SecondLine); //Elimine la deuxième ligne (t -1)
    int NbVariable= count(header.begin(),header.end(),',') +1; //compter le nombre de variables à partir du header
    while (getline(Myfile,line)) // opération sur chaque ligne
    {   
        LectLine.clear();
        LectLine.str(line);   
        while(getline(LectLine,data,','))//pour chaque ligne, extraire les entiers, intégrer dans un vecteur, puis intégrer le vecteur dans le vecteur de vecteur
            {LineTab.push_back(stof(data));}
        GlobalTab.push_back(LineTab);
        LineTab={};
        }
        return GlobalTab;

}