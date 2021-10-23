#include "BaseList.h"

lp *creerList(int ID) {
    lp *nouveau = malloc(sizeof(lp));
    nouveau->list_ID = ID;
    nouveau->thisList = NULL;
    nouveau->suivant = NULL;
    return nouveau;
}

lp *ajouterList(lp *liste, lp *nouveau){
    lp *courant = liste;
    while(courant->suivant!=NULL){
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
}

lp *retirerList(lp *liste, char *mot){
    lp *precedent = liste;
    if(liste == NULL){
        return NULL;
    }
    lp *courant = liste->suivant;
    while(courant!=NULL){
        courant = courant->suivant;
    }
}

void afficherList(lp *liste){
    lp *courant = liste;
    while(courant!=NULL){
        printf("LISTID:%d\n",courant->list_ID);
        afficherMots(courant->thisList);
        courant = courant->suivant;
    }
}