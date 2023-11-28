#include "FileGestion.h"
#include "Anonym_function.h"
using namespace std;

int main(){
    fstream RawFile;
    vector<vector<float>> RawTab;
    vector<vector<float>> CookedTab;
    string chemin="BDLBS_dataset-main/set_1000_traces_30_seconds_between_two_values/multivariate";
    ofstream AnonymFile;
    string RawFile_name;
    string AnonymFile_name;
    string header;
    string SecondLine;

    //Check existence de données.
    CheckThisFile(chemin);

    //check existence de dossier cible
    filesystem::create_directories("projet_codes_Lapoutge_Rimet_2023_12_08_Fri/gener_simulated_data_EcartRandom");

    for (const auto& entry : filesystem::directory_iterator(chemin)){
        if(entry.path().filename().string().find("series") != string::npos){
            RawFile_name=entry.path().filename().string();
            RawFile.open(entry.path().string(),ios::in);
            getline(RawFile,header); //  Elimine le header
            RawTab=FileToTab(RawFile,header); // Extraction RawData
            CookedTab=AnonymData(RawTab); //Data cooking
            RawFile.close(); //Close RawData

            AnonymFile_name="projet_codes_Lapoutge_Rimet_2023_12_08_Fri/gener_simulated_data_EcartRandom/"+RawFile_name;
            AnonymFile.open(AnonymFile_name,ios::out);
            WriteThisData(CookedTab,header,AnonymFile);

            AnonymFile.close();}}
        return 0;
        }


