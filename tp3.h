#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#define LENGTH 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_mot {
    char mot[LENGTH];
    int nombre_occurences;
    struct s_mot* suivant;
};

typedef struct s_mot t_mot;

void resetArray(t_mot **para1,int* para2,int len);

t_mot *creerMot(char *mot);

t_mot *ajouterMot(t_mot *liste, char *mot);

t_mot *retirerMot(t_mot *liste, char *mot);

void afficherMots(t_mot *liste,int ID);

t_mot *fusionner(t_mot *listeA, t_mot *listeB);

t_mot *importerFichier(t_mot *liste);


// fonction utile pour vider le tampon clavier
void viderBuffer() ;

#endif // TP3_H_INCLUDED
