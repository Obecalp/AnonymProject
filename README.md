# Anonymisation de séries temporelles multivariées, associées à des traces d’événements

## Contenu du fichier
#### Le sous répertoire "anonym_meth" contenant les fichiers .cpp/.h avec le makefile
#### Le sous répertoire "exemple_meth" contenant le test de script "launch_anonym_toy.py", le dossier de test "TestAlgo" ainsi qu'un exemple d'output attendu
#### Le sous répertoire data contenant toutes les données du projet à anonymiser
#### Le sous répertoire "analyse_anonym_meth" contenant les statistiques effectuées sur l'anonymisation avec les scripts python correspondants
## Utilisation
### Compilation
#### La compilation du script doit être effectuée en faisant la commande "make" dans le sous répertoire "anonym_meth"
### Input
#### Initialement le dossier cible est "data", à l'exécution du fichier il est cependant possible de changer de path
### Output
#### En sortie un dossier daté de même format que le fichier à anonymiser sera produit, contenant les fichier "series" anonymisés et "events" non modifiés


