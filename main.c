#include "tp3.h"
#define MAX_NUM_LEXIQUE 20
//lexique lequel on choisi
int listID = 0;

//listPtr est toujours pointee vers le liste target
t_mot *lexiques[MAX_NUM_LEXIQUE];
int isExist[MAX_NUM_LEXIQUE];

int main() {
    resetArray(lexiques,isExist,MAX_NUM_LEXIQUE);
    char choixMenu = '0';
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
        //t_mot *mes_mots = malloc(sizeof(t_mot));
        switch (choixMenu) {
            case '1' :
                printf("\n\n\t<Faire Afficher un lexique>\n\n");
                printf("Afficher quelle lexique?\n");
                listID = getchar()-48;
                viderBuffer();
                afficherMots(lexiques[listID],listID);
                break;
            case '2' :
                printf("\n\n\t<Faire Ajouter un mot dans un lexique>\n\n");
                printf("Ajouter quelle lexique?\n");
                listID = getchar()-48;
                viderBuffer();
                printf("\n\n\t<Entrez le mot:>\n\n");
                char nouveau_mot1[20]="\0";
                gets(nouveau_mot1);
                lexiques[listID] = ajouterMot(lexiques[listID],nouveau_mot1);
                afficherMots(lexiques[listID],listID);
                break;
            case '3' :
                printf("\n\n\t<Faire Retirer un mot d'un lexique>\n\n");
                printf("Retirer dans quelle lexique?\n");
                listID = getchar()-48;
                viderBuffer();
                printf("\n\n\t<Entrez le mot pour retirer:>\n\n");
                char nouveau_mot2[20]="\0";
                gets(nouveau_mot2);
                lexiques[listID] = retirerMot(lexiques[listID],nouveau_mot2);
                afficherMots(lexiques[listID],listID);
                break;
            case '4' :
                printf("\n\n\t<Faire Fusionner deux lexiques>\n\n");
                printf("Fusionner quelle lexique?\n");
                int listID_1 = getchar()-48;
                viderBuffer();
                printf("Fusionner quelle lexique?\n");
                int listID_2 = getchar()-48;
                viderBuffer();
                lexiques[listID_1] = fusionnerON(lexiques[listID_1], lexiques[listID_2]);

//                il est obligatoire de reattribuer lexiques[listID_2] dehors de function!
                lexiques[listID_2] = NULL;

                afficherMots(lexiques[listID_1],listID_1);
                break;
            case '5' :
                printf("\n\n\t<Faire Charger un fichier dans un lexique>\n\n");
                break;
        }
    } while (choixMenu != '6');
    printf("\n\n*** FIN DU PROGRAMME ***\n");
    return 0;
}
