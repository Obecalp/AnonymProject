#!/bin/env python3
import shutil
import os
import subprocess

### Préparation du set de données à tester

#Changement des paramètres de bases (choix du nom du dossier des fichier/nombre de séries à utiliser pour le test)
nombre=2
newfolder="multivariate"
reponse=input("Par défaut le test est effectué sur 2 patients, souhaitez vous augmenter la capacité?(y/n)")
if reponse.lower()=="y": nombre= input("Entrez le nombre de séries à tester (maximum 1000)")
reponse=input("Par défaut le dossier à anonymiser est \"multivariate\" souhaitez vous changer le nom?(y/n)")
if reponse.lower()=="y": newfolder=input("Entrez le nom du dossier contenant les fichier à anonymiser")

#Création d'un Dossier spécifique pour l'exécution du script
try:
    os.mkdir("TestAlgo")
except FileExistsError:
    shutil.rmtree("TestAlgo")
    os.mkdir("TestAlgo")

#Copie des séries vers le Dossier de test
for i in range(1,nombre+1):
    shutil.copy(newfolder+"/"+str(i)+"_series.txt","TestAlgo/"+str(i)+"_series.txt")
    shutil.copy(newfolder+"/"+str(i)+"_events.txt","TestAlgo/"+str(i)+"_events.txt")

### Test du Script

#Définition du pipe employé et des commandes en inputs correspondant à un choix alternatif de dossier (Anonymisation de TestAlgo a la place de multivariate)
command = ["./a.out"]
process = subprocess.Popen(command, stdin=subprocess.PIPE,text=True)

#
inputs=['y','TestAlgo']

for i in inputs:
    process.stdin.write(i)
    process.stdin.flush()

output,error = process.communicate()
print(output)