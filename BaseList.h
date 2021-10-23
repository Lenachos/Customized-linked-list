#ifndef NF16_TP3_LIST_PTR_H
#define NF16_TP3_LIST_PTR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
#endif //NF16_TP3_LIST_PTR_H


struct BaseList {
    int list_ID;
    struct BaseList* suivant;
    struct s_mot* thisList;
};

typedef struct BaseList lp;

lp *creerList(int ID);

lp *ajouterList(lp *liste, lp *nouveau);

lp *retirerList(lp *liste, char *mot);

void afficherList(lp *liste);