//Fatima Nour ; BTS ciel 1
//  Chapitre 5 TP1

//QUESTION 1
//adr1 et adr2 sont des pointeurs pointant sur des réels.
//Le contenu de où pointe adr1 vaut -45,78; le contenu de où pointe adr2 vaut 678,89.
//Ecrire un programme qui ne contient que deux variables(adr1 et adr2) de type pointeurs sur réél, qui stocke deux valeurs réelles (-45.78 et 678.89) et qui affiche les
//adresses des espaces mémoires qui stockent les deux rééls ainsi que le contenu de ces deux espaces.


#include <stdio.h>

int main() {
    float valeur1 = -45.78;
    float valeur2 = 678.89;

    float *adr1 = &valeur1;
    float *adr2 = &valeur2;

    printf("Adresse de adr1 : %p\n", (void *)adr1);
    printf("Contenu de adr1 : %.2f\n", *adr1);

    printf("Adresse de adr2 : %p\n", (void *)adr2);
    printf("Contenu de adr2 : %2f\n", *adr2);

    return 0;
}

//QUESTION 2
//Soit adr_deb un pointeur sur entiers, vous ferez en sorte que adr_deb pointe sur un emplacement mémoire suffisant afin de stocker 6 entiers donnés par l’utilisateur. Puis vous rangerez ces valeurs dans l’ordre croissant.
//Rechercher le maximum, l'afficher ainsi que son adresse et sa position.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *adr_deb;
    adr_deb = (int *)malloc(6 * sizeof(int));

    for (int i = 0; i < 6; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &adr_deb[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (adr_deb[i] > adr_deb[j]) {
                int temp = adr_deb[i];
                adr_deb[i] = adr_deb[j];
                adr_deb[j] = temp;
            }
        }
    }

    printf("Valeurs triées dans l'ordre croissant :\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", adr_deb[i]);
    }
    printf("\n");

    int *max = adr_deb;
    for (int i = 1; i < 6; i++) {
        if (adr_deb[i] > *max) {
            max = &adr_deb[i];
        }
    }

    printf("Maximum : %d\n", *max);
    printf("Adresse du maximum : %p\n", (void *)max);
    printf("Position du maximum : %ld\n", max - adr_deb);

    return 0;
}


//Question 3
//Soit une variable de type char * , écrire un programme qui saisit une chaîne de caractères et qui la stocke dans cette variable, puis qui affiche les éléments de la chaîne caractère par caractère avec leur adresse.

#include <stdio.h>

int main() {
    char chaine[100];
    printf("Entrez une chaîne de caractères : ");
    scanf("%s", chaine);

    printf("Caractères de la chaîne avec leurs adresses :\n");
    for (int i = 0; chaine[i] != '\0'; i++) {
        printf("Caractère : %c\t Adresse : %p\n", chaine[i], (void *)&chaine[i]);
    }

    return 0;
}


//Question 4
//tab1 et tab2 sont des variables locales à main:
//int tab1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
//int tab2[] = {-19,18,-17,16,-15,14,-13,12,-11,10,-9,8,-7,6,-5,4,-3,2,-1,0};
//Ecrire une fonction de prototype void affiche(int *tab,int i,int j) qui permet d'afficher les i*j nombres suivant un tableau i x j(à l’affichage i lignes et j colonnes).
//La mettre en oeuvre dans main() pour afficher tab1 et tab2.

#include <stdio.h>

void affiche(int *tab, int i, int j);

int main() {
    int tab1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int tab2[] = {-19,18,-17,16,-15,14,-13,12,-11,10,-9,8,-7,6,-5,4,-3,2,-1,0};

    printf("Affichage de tab1 :\n");
    affiche(tab1, 4, 5);

    printf("\nAffichage de tab2 :\n");
    affiche(tab2, 5, 4);

    return 0;
}

void affiche(int *tab, int i, int j) {
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            printf("%d\t", *(tab + row * j + col));
        }
        printf("\n");
    }
}


//Question 5
//Calculer et afficher les racines de ax2+bx+c=0.
//Une fonction de prototype void saisie(float *aa,float *bb,float *cc) permet de saisir a,b,c.
//Une fonction de prototype float *calcul(float aa,float bb,float cc) exécute les calculs et renvoie les résultats. a, b, c sont des variables locales à main();
//main() se contente de saisir a,b et c puis d'appeler saisie et calcul et d’afficher les solutions.

#include <stdio.h>
#include <math.h>

void saisie(float *aa, float *bb, float *cc);
float calcul(float aa, float bb, float cc);

int main() {
    float a, b, c;
    saisie(&a, &b, &c);

    float *resultats = calcul(a, b, c);

    printf("Les racines de l'equation sont : %.2f et %.2f\n", resultats[0], resultats[1]);

    return 0;
}

void saisie(float *aa, float *bb, float *cc) {
    printf("Entrez a, b et c de l'equation ax^2 + bx + c = 0 :\n");
    scanf("%f %f %f", aa, bb, cc);
}

float *calcul(float aa, float bb, float cc) {
    static float resultats[2];
    float discriminant = bb * bb - 4 * aa * cc;

    if (discriminant >= 0) {
        resultats[0] = (-bb + sqrt(discriminant)) / (2 * aa);
        resultats[1] = (-bb - sqrt(discriminant)) / (2 * aa);
    } else {
        resultats[0] = resultats[1] = 0.0;
    }

    return resultats;
}
