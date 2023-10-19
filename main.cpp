#include<iostream>
#include<vector>
#include<filesystem>
#include<fstream>
#include<algorithm>

using namespace std;


/*
//preserver ordre UTS, ET
//ajouter bruit entre chaque ET
//ajouter bruit valeur

//hey can I at least finish Offman project first?

//script créer dossiers

    
struct ET
{
    int valeur;
    ET* next;

};


vector <int> GetOrder(ET* preums){
    vector <int> ordres;
    while (preums != NULL){
        ordres.push_back(preums->valeur);
        preums=preums->next;
    }


}
*/

int main(){
    std::filesystem::create_directory("projet_codes_LAPOUTGE_HUGO_2023_12_16__thur");
    std::fstream MyFile;
    MyFile.open("ExempleFile/MeGoodCSV.csv", ios::in);
    string line;
    vector<vector<int>>DoggoKennel;
    vector<int> Doggo;
    string header;
    string trash;
    getline(MyFile,header); // My Doggoes don't like headers
    int DogBelly= count(header.begin(),header.end(),';');
    getline(MyFile,trash); // Don't feed my doggoes with that shit!
    //My Chenil has one Doggo per line, he has to ate every int from his line.
    while (getline(MyFile,line,';'))
    { for (unsigned int i=0;i<DogBelly-1;i++){
        Doggo.push_back(stoi(line));
    }
        DoggoKennel.push_back(Doggo);
        Doggo={};

    }
    for (int i=0;i<DoggoKennel[0].size();i++){
        cout << DoggoKennel[0][0] << endl;
    }
   
    std::cout << DoggoKennel.size() << "     " << Doggo.size() << endl;
    MyFile.close();
    std::fstream DoggoFile;
    DoggoFile.open("MyKennel.txt",ios::out);
    DoggoFile << header;
    
    for (unsigned int bed=0;bed<DoggoKennel.size();bed++){
        for(unsigned int DoggoBelly;DoggoBelly<Doggo.size();DoggoBelly++){
            DoggoKennel[bed][DoggoBelly]*=2;
            //cout << DoggoKennel[bed][DoggoBelly] << ";";
        }
    }
    // I think we should use chainlist instead of vectorm, Good doggoes preferm chainlists
    //We finish by a big Kennel with as many Doggo as line in our file.csv
    DoggoFile.close();


    
}