#include <stdlib.h>
#include <stdio.h>
#include "tp3.h"
int main() {
    char choixMenu = '0' ;
    t_mot *tete = NULL;
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
                afficherMots(tete);
                break;
            case '2' :
                printf("\n\n\t<Faire Ajouter un mot dans un lexique>\n\n");
                printf("\n\n\t<Entrez le mot:>\n\n");
                char nouveau_mot1[20]="\0";
                gets(nouveau_mot1);
                tete = ajouterMot(tete,nouveau_mot1);
                afficherMots(tete);
                break;
            case '3' :
                printf("\n\n\t<Faire Retirer un mot d'un lexique>\n\n");
                printf("\n\n\t<Entrez le mot pour retirer:>\n\n");
                char nouveau_mot2[20]="\0";
                gets(nouveau_mot2);
                tete = retirerMot(tete,nouveau_mot2);
                afficherMots(tete);
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
