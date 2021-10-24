#include <ctype.h>
#include "tp3.h"

// Création nouvel élément
t_mot *creerMot(char *mot) {
    t_mot *nouveau = malloc(sizeof(t_mot));
    if(nouveau != NULL){
        strcpy(nouveau->mot,mot);
        nouveau->nombre_occurences = 1;
        nouveau->suivant = NULL;
    }
    return nouveau;
}
/* ====== FIN creerMot ====== */

// Ajout mot dans une liste
t_mot *ajouterMot(t_mot *liste, char *mot) {
    if(mot == NULL)return liste;
    t_mot *precedent = NULL, *courant = liste;
    for(int i=0; i<strlen(mot);i++){mot[i] = tolower(mot[i]);}

    if(liste == NULL || strcmp(liste->mot,mot) > 0){
        t_mot *nouveau = creerMot(mot);
        nouveau->suivant = liste;
        return nouveau;
    }

    while(courant != NULL && strcmp(courant->mot,mot) < 0){
        precedent = courant;
        courant = courant->suivant;
    }
    if(courant == NULL || strcmp(courant->mot,mot) > 0){
        t_mot *nouveau = creerMot(mot);
        precedent->suivant = nouveau;
        nouveau->suivant = courant;
    }else{
        courant->nombre_occurences++;
    }
    return liste;
}
/* ====== FIN  ====== */

// Retrait occurence mot d'une liste
t_mot *retirerMot(t_mot *liste, char *mot) {
    if(liste == NULL){
        printf("\n\n\tLA LISTE EST VIDE\n\n");
        return NULL;
    }

    t_mot *courant = liste;
    t_mot *precedent = NULL;
    if(strcmp(courant->mot,mot) == 0){
        courant->nombre_occurences--;
        if(courant->nombre_occurences == 0){
            t_mot *newHead = courant->suivant;
            free(courant);
            return newHead;
        }
    }

    precedent = liste;
    courant = liste->suivant;
    while(courant!=NULL){
        if(strcmp(courant->mot,mot) == 0){
            courant->nombre_occurences--;
            if(courant->nombre_occurences == 0){
                precedent->suivant = courant->suivant;
                free(courant);
            }
            break;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    return liste; // à remplacer par le code la fonctino
}
/* ====== FIN ajouterMot ====== */

// Affichage mots d'un lexique
void afficherMots(t_mot *liste,int ID){
    t_mot *courant = liste;
    if(liste == NULL){
        printf("\n\n\tLA LISTE ID(%d) EST VIDE\n\n",ID);
        return;
    }
    char prefixe = '-';
    printf("\n\n==================\nID(%d)",ID);
    while(courant != NULL){
        if(courant->mot[0] == prefixe){
            printf("\n    --- %s [%d]",courant->mot,courant->nombre_occurences);
        }else{
            prefixe = courant->mot[0];
            printf("\n%c   --- %s [%d]",toupper(prefixe),courant->mot,courant->nombre_occurences);
        }
        courant = courant->suivant;
    }
    printf("\n==================\n\n");
}
/* ====== FIN afficherMots ====== */

// Fusion listes
t_mot *fusionner(t_mot *listeA, t_mot *listeB){
    t_mot *temp = NULL;
    t_mot *newHeader = NULL;
    if(listeB == NULL){
        return listeA;
    }
    char a[1];
    a[0] = '-';
    if(listeA == NULL){
        temp = creerMot(a);
        temp->suivant = listeB;
        listeB = temp;
        newHeader = temp->suivant;
        free(listeB);
        return newHeader;
    }
    // à remplacer par le code la fonctino
}
/* ====== FIN fusionner ====== */


// Import fichier de mots dans une liste
t_mot *importerFichier(t_mot *liste){
    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN importerFichier ====== */

// fonction utile pour vider le tampon clavier
void viderBuffer() {
    int c = '0';
    while (c!='\n' && c != EOF) { c = getchar(); }
}

void resetArray(t_mot **para1,int* para2,int len){
    for(int i = 0;i<len;i++){
        para2[i] = 0;
        para1[i] = NULL;
    }
    for(int i = 0;i<len;i++){
        printf("%d",*(para2+i));
    }
    printf("\n");
}