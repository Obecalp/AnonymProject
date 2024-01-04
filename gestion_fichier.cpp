#include "gestion_fichier.h"

using namespace std;


string change_file(){
    char choice;
    string chemin;
cout << "Le nom du dossier à anonymiser est par défaut multivariate, souhaitez vous entrer un autre nom? (y/n)" << endl; cin >> choice;
    if(choice == 'y'){
        while(!filesystem::exists(chemin)){
        cout << "Entrez le nom du dossier contenant les séries et évènements" << endl; getline(cin >> ws,chemin);
        if(!filesystem::exists(chemin)){
            cout <<"Dossier introuvable, souhaitez vous en entrer un autre? (y/n)" << endl; cin >> choice; if(choice!='y'){exit(1);}
        }}
    }
    else{chemin="multivariate";};
    return chemin;
}



vector<vector<float>> FileToTab(fstream &Myfile, string header){

    stringstream LectLine;
    string data;
    string line;
    vector<vector<float>>GlobalTab;
    vector<float> LineTab;
    string SecondLine;
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


string GimmeString(float &NotAString){
    ostringstream MyString;
    MyString << NotAString;
    return MyString.str();
}


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


