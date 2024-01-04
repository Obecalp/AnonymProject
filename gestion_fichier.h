#include<iostream>
#include<vector>
#include<filesystem>
#include<sstream>
#include<fstream>
#include<algorithm>


using namespace std;

string change_file();
vector<vector<float>> FileToTab(fstream &Myfile, string header); //conversion de fichier csv Myfiler (avec comme séparateur ',' et séparé par le main de son header entré en 'header') sous le format vector<vector>.
string GimmeString(float &NotAString); //conversion d'un float en string
void WriteThisData(vector<vector<float>> DataTab, string header,ofstream &TargetFile); //conversion d'un vector<vector> en fichier csv.