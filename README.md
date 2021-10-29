# NF16_TP3
29/10/2021 2:22

1)Changer char mot[length] en char* mot
2)Remplacer strcmp par strdup dans fonction "creerMot()"  
3)Ajouter "free(courant->mot)" dans fonction "retirerMot()"  
4)Corriger la fonction "importerFichier()"  
5)Ajouter la fonction "getlexique()" pour juger si le lexique a dépassé la limite:  
Dans code dernier, on peut créer un lexique avec ID='a'.Ça dépasse "MAX_NUM_LEXIQUE"  
6)Corriger la mauvaise utilisation de la fonction "viderBuffer()":  
On ne doit l'utiliser après "gets()".Par contre, on doit l'utiliser après scanf().  
7)Réécrire la fonction "main()" avec "getlexique()" et ajouter "{}" dans "case" pour limiter la portée des variables  
8)Modifier le format d'affichage  
