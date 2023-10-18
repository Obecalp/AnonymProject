#include<iostream>
#include<vector>
#include<filesystem>


using namespace std;



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

int main(){

    std::filesystem::create_directories("blabla");
}