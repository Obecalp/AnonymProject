#include "gestion_fichier.h"
#include "anonym_data.h"
using namespace std; //conservation dans fichier.h?



int main(){
    filesystem::create_directory("projet_codes_LAPOUTGE_HUGO_2023_12_16__thur"); //nom_test
    filesystem::create_directory("Dossiertest"); //nom_test
    fstream RawFile;
    vector<vector<float>> RawTab;
    vector<vector<float>> CookedTab;
    string chemin= change_file();
    ofstream AnonymFile;
    string RawFile_name;
    string AnonymFile_name;
    string header;

//Itération dans le dossier cible
for (const auto& entry : filesystem::directory_iterator(chemin)){

    // Pour chaque fichier portant le nom "serie", effectuer la séquence suivante:
    if(entry.path().filename().string().find("series") != string::npos){

        //Ouverture du fichier et élimination du header
        RawFile_name=entry.path().filename().string();
        RawFile.open(entry.path().string(),ios::in);
        getline(RawFile,header);

        //Extraction des données, puis anonymisation et fermeture du fichier à anonymiser.
        RawTab=FileToTab(RawFile,header);
        CookedTab=AnonymData(RawTab);
        RawFile.close();

        //Ecriture du nouveau fichier Anonymisé
        AnonymFile_name="Dossiertest/"+RawFile_name;
        AnonymFile.open(AnonymFile_name,ios::out);
        WriteThisData(CookedTab,header,AnonymFile);

        //Copie du fichier d'évènements correspondants (non modifiés) dans le nouveau dossier
        RawFile_name.erase(RawFile_name.end()-9,RawFile_name.end());
        filesystem::copy(RawFile_name,"Dossiertest");

        AnonymFile_name.erase()
        }
    AnonymFile.close();
    }}


