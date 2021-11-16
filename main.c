#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int lexiqueID = 0;//lexique qu'on choisit
t_mot *lexiques[MAX_NUM_LEXIQUE];//listPtr est toujours pointée vers la liste target

int main() {
    char choixMenu = '0' ;

    do {
        printf("\n========================================");
        printf("\n  [1] Afficher un lexique");
        printf("\n  [2] Ajouter un mot dans un lexique");
        printf("\n  [3] Retirer un mot d'un lexique");
        printf("\n  [4] Fusionner deux lexiques");
        printf("\n  [5] Charger un fichier dans un lexique");
        printf("\n  [6] Quitter");
        printf("\n========================================");
        printf("\nVotre choix : ");
        choixMenu = getchar();
        viderBuffer();
        switch (choixMenu) {
            case '1' :
                printf("\n\n\t<Faire Afficher un lexique>");
                printf("\n\n\t<Afficher quel lexique?>");
                lexiqueID = getlexique();//Pour juger si le lexique a dépassé la limite
                if(lexiqueID != -1)
                    afficherMots(lexiques[lexiqueID],lexiqueID);
                break;

            case '2' :
            {
                printf("\n\n\t<Faire Ajouter un mot dans un lexique>");
                printf("\n\n\t<Entrer ID(0~%d) du lexique>",MAX_NUM_LEXIQUE-1);
                lexiqueID = getlexique();
                if(lexiqueID != -1){
                    printf("\n\t<Entrer le mot pour ajouter:>");
                    char nouveau_mot1[20]="\0";
                    gets(nouveau_mot1);
                    lexiques[lexiqueID] = ajouterMot(lexiques[lexiqueID],nouveau_mot1);
                    afficherMots(lexiques[lexiqueID],lexiqueID);
                }
                break;
            }

            case '3' :
            {

                printf("\n\n\t<Faire Retirer un mot d'un lexique>");
                printf("\n\n\t<Retirer dans quel lexique?>");
                lexiqueID = getlexique();
                if(lexiqueID != -1){
                    printf("\n\t<Entrer le mot pour retirer:>");
                    char nouveau_mot2[20]="\0";
                    gets(nouveau_mot2);
                    lexiques[lexiqueID] = retirerMot(lexiques[lexiqueID],nouveau_mot2);
                    afficherMots(lexiques[lexiqueID],lexiqueID);
                }
                break;
            }
             case '4' :
            {
                int lexiqueID_1,lexiqueID_2;
                printf("\n\n\t<Faire Fusionner deux lexiques>");
                printf("\n\n\t<Entrer ID du 1ér lexique:>");
                scanf("%d",&lexiqueID_1);
                viderBuffer();
                printf("\n\t<Entrer ID du 2ème lexique:>");
                scanf("%d",&lexiqueID_2);
                viderBuffer();
                lexiques[lexiqueID_1] = fusionner(lexiques[lexiqueID_1], lexiques[lexiqueID_2]);
                lexiques[lexiqueID_2] = NULL;//il est obligatoire de reattribuer lexiques[lexiqueID_2] dehors de function!
                afficherMots(lexiques[lexiqueID_1],lexiqueID_1);
                break;
            }
            case '5' :
                printf("\n\n\t<Faire Charger un fichier dans un lexique>");
                printf("\n\n\t<Charger dans quel lexique?>");
                lexiqueID = getlexique();
                if(lexiqueID != -1){
                    lexiques[lexiqueID]=importerFichier(lexiques[lexiqueID]);
                    printf("\n\t<Après charger:>\n\n");
                    afficherMots(lexiques[lexiqueID],lexiqueID);
                }
                break;
        }
    } while (choixMenu != '6');
    printf("\n\n*** FIN DU PROGRAMME ***\n");
    return 0;
}
