//  Chapitre 5 TD1

//QUESTION 3
//Ecrire une fonction de prototype void saisie(int *val,int *nb) qui permet de faire la saisie d’entiers différents de 0(au maximum 20) et de les stocker où pointe val. Ladernière valeur entrée devra être 0. Le paramètre nb permet de stocker le nombre de valeurs qui ont été entrées.
//Vous définirez une fonction affiche qui permet d’afficher les nb valeurs lues dans la fonction saisie.
//Ecrire un programme qui appelle saisie, qui appelle ensuite affiche puis écrit à l’écran le nombre de valeurs qui ont été entrées par l’utilisateur.


#include <stdio.h>

void saisie(int *val, int *nb);
void affiche(int *val, int nb);

int main() {
    int valeurs[20];
    int nbValeurs;

    saisie(valeurs, &nbValeurs);
    affiche(valeurs, nbValeurs);
    printf("Nombre de valeurs entrées : %d\n", nbValeurs);

    return 0;
}

void saisie(int *val, int *nb) {
    int valeur;
    *nb = 0;

    printf("Saisissez des entiers différents de 0 (au maximum 20).\n");
    printf("Entrez 0 pour terminer la saisie.\n");

    do {
        printf("Valeur %d : ", *nb + 1);
        scanf("%d", &valeur);

        if (valeur != 0) {
            *(val + *nb) = valeur;
            (*nb)++;
        }
    } while (valeur != 0 && *nb < 20);
}

void affiche(int *val, int nb) {
    printf("Valeurs entrées :\n");

    for (int i = 0; i < nb; i++) {
        printf("%d\n", *(val + i));
    }
}
