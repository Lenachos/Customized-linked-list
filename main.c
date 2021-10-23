#include <stdlib.h>
#include <stdio.h>
#include "BaseList.h"

//lexique lequel on choisi
int listID = 1;

int main() {
    lp* headPtr = creerList(0);
    lp* listPtr = creerList(listID);
    headPtr->suivant = listPtr;
    char choixMenu = '0';
    do {
        printf("\n========================================");
        printf("\n  [1] Afficher un lexique");
        printf("\n  [2] Ajouter un mot dans un lexique");
        printf("\n  [3] Retirer un mot d'un lexique");
        printf("\n  [4] Fusionner deux lexiques");
        printf("\n  [5] Charger un fichier dans un lexique");
        printf("\n  [6] Quitter");
        printf("\n----------------------------------------");
        printf("\n  lexique lequel on choisi ID:%d",listID);
        printf("\n  [a] Modifier lexique");
        printf("\n  [b] Ajouter lexique");
        printf("\n  [c] Retirer lexique");
        printf("\n  [d] Afficher les lexiques");
        printf("\n========================================");
        printf("\nVotre choix : ");
        choixMenu = getchar();
        viderBuffer();
        //t_mot *mes_mots = malloc(sizeof(t_mot));
        switch (choixMenu) {
            case 'a' :
                printf("\n\n\t<Faire modifier lexique>\n\n");
                printf("\n\n\t<Entrez le ID:>\n\n");
                scanf("%d",&listID);
                listPtr = headPtr->suivant;
                while(listPtr!=NULL){
                    if(listPtr->list_ID == listID){
                        break;
                    }
                    listPtr = listPtr->suivant;
                }
                if(listPtr==NULL){
                    printf("Switch fail\n");
                    listPtr = headPtr->suivant;
                }
                break;
            case 'b' :
                printf("\n\n\t<Faire ajouter lexique>\n\n");
                printf("\n\n\t<Entrez le ID:>\n\n");
                int newListID;
                scanf("%d",&newListID);
                headPtr->suivant = ajouterList(headPtr->suivant, creerList(newListID));
                printf("\t<Ajouter new List ID:%d>\n\n",newListID);
                break;
            case 'c' :
                printf("\n\n\t<Faire retirer lexique>\n\n");

                printf("\t<Switch to ID:%d>\n\n",listID);
                break;
            case 'd' :
                printf("\n\n\t<Afficher les lexiques>\n\n");
                afficherList(headPtr->suivant);
                break;
            case '1' :
                printf("\n\n\t<Faire Afficher un lexique>\n\n");
                afficherMots(listPtr->thisList);
                break;
            case '2' :
                printf("\n\n\t<Faire Ajouter un mot dans un lexique>\n\n");
                printf("\n\n\t<Entrez le mot:>\n\n");
                char nouveau_mot1[20]="\0";
                gets(nouveau_mot1);
                listPtr->thisList = ajouterMot(listPtr->thisList,nouveau_mot1);
                afficherMots(listPtr->thisList);
                break;
            case '3' :
                printf("\n\n\t<Faire Retirer un mot d'un lexique>\n\n");
                printf("\n\n\t<Entrez le mot pour retirer:>\n\n");
                char nouveau_mot2[20]="\0";
                gets(nouveau_mot2);
                listPtr->thisList = retirerMot(listPtr->thisList,nouveau_mot2);
                afficherMots(listPtr->thisList);
                break;
            case '4' :
                printf("\n\n\t<Faire Fusionner deux lexiques>\n\n");
                break;
            case '5' :
                printf("\n\n\t<Faire Charger un fichier dans un lexique>\n\n");
                break;
        }
    } while (choixMenu != '6');
    printf("\n\n*** FIN DU PROGRAMME ***\n");
    return 0;
}
