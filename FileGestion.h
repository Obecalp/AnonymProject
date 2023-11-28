#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<filesystem>
#include<algorithm>

using namespace std;

vector<vector<float>> FileToTab(fstream &Myfile, string header);
void CheckThisFile(string &chemin);
void WriteThisData(vector<vector<float>> DataTab, string header,ofstream &TargetFile);
string GimmeString(float &NotAString);