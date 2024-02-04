//Fatima Mahamat ; BTS ciel1
//Exercices sur les fichiers en C


//EXERCICE 1
//Ecrire un programme C permettant de créer un fichier qui contiendra l’alphabet.

#include <stdio.h>

int main() {
    FILE *fichier;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    
    fichier = fopen("alphabet.txt", "w");


    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    for (i = 0; i < 26; i++) {
        fputc(alphabet[i], fichier);
    }

  
    fclose(fichier);

    printf("Le fichier alphabet.txt a été créé avec succès.\n");

    return 0;
}

//EXERCICE 2
//Ecrire un programme C permettant d’afficher le contenu d’un fichier créé préalablement.

#include <stdio.h>

int main() {
    FILE *fichier;
    char caractere;

    fichier = fopen("alphabet.txt", "r");

    
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    
    while ((caractere = fgetc(fichier)) != EOF) {
        printf("%c", caractere);
    }

    
    fclose(fichier);

    return 0;
}

//EXERCICE 3
//Ecrire un programme qui permet de lire dans un fichier des entiers et de les trier avant de les enregistrer dans un autre fichier. Vous devez écrire les fonctions suivantes :
//1. int lireDonnees(char * nomFichier, int * T) qui lit les données dans le fichier nommé nomFichier des entiers, puis les stocke dans un tableau T. La valeur de retour est le nombre d’entiers qui ont été lus (c’est-à-dire le nombre d’éléments du tableau).
//2. void afficherTableau(int * T, int nb) qui affiche le contenu du tableau T qui comprend nb éléments.
//3. void triABulles(int * T, int nb) qui trie le tableau T de nb éléments avec la méthode du tri à bulles et qui retourne le tableau trié.
//4. void enregistrerDonnees(char * nomFichier, int * T, int nb) qui enregistre les nb valeurs du tableau T dans le fichier nommé nomFichier.
//Pour tester vos fonctions, vous réaliserez un programme principal. Vous choisirez le nom du fichier pour la lecture des données ainsi que celui pour l’enregistrement des valeurs (vous pouvez mettre ces noms en dur dans votre code).
#include <stdio.h>

int lireDonnees(char *nomFichier, int *T) {
    FILE *fichier;
    int nb = 0;

    fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return 0;
    }

    while (fscanf(fichier, "%d", &T[nb]) == 1) {
        nb++;
    }

    fclose(fichier);

    return nb;
}

void afficherTableau(int *T, int nb) {
    printf("Contenu du tableau :\n");
    for (int i = 0; i < nb; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void triABulles(int *T, int nb) {
    for (int i = 0; i < nb - 1; i++) {
        for (int j = 0; j < nb - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                // Échanger les éléments s'ils sont dans le mauvais ordre
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

void enregistrerDonnees(char *nomFichier, int *T, int nb) {
    FILE *fichier;

    fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return;
    }

    for (int i = 0; i < nb; i++) {
        fprintf(fichier, "%d ", T[i]);
    }

    fclose(fichier);
}

int main() {
    char nomFichierLecture[] = "donnees.txt";
    char nomFichierEnregistrement[] = "donnees_triees.txt";
    int T[100];  // taille arbitraire du tableau

    // Lecture des données depuis le fichier
    int nbElements = lireDonnees(nomFichierLecture, T);

    if (nbElements == 0) {
        return 1; // Erreur lors de la lecture des données
    }

    // Affichage du tableau non trié
    afficherTableau(T, nbElements);

    // Tri du tableau
    triABulles(T, nbElements);

    // Affichage du tableau trié
    afficherTableau(T, nbElements);

    // Enregistrement des données triées dans un nouveau fichier
    enregistrerDonnees(nomFichierEnregistrement, T, nbElements);

    return 0;
}

