#include <stdio.h>
#include <stdlib.h>
#include "homar.h"
int main()
{

    struct obiect *obiecte;
    int numar_obiecte;
    int capacitate_plasa;
    printf("    Modul de testare : \n 1.Date introduse de la tastatura . \n 2.Date generate aleatoriu.\n    ");
    //Alegerea modului de testare
    int mod_testare;
    scanf("%d",&mod_testare);
    while(mod_testare!=1 && mod_testare!=2)//in caz ca se introduce orice altceva inafara de selectia disponibila
    {
        printf("    Mod invalid , reincercati. \n");
        printf("    Modul de testare : \n 1.Date introduse de la tastatura . \n 2.Date generate aleatoriu.\n     ");
         scanf("%d",&mod_testare);
    }
    printf("    Capacitatea plasei este: ");
    scanf("%d",&capacitate_plasa);
    printf("    Numar homari: ");
    scanf("%d",&numar_obiecte);
    obiecte=malloc(numar_obiecte*sizeof(struct obiect));
    if(mod_testare==1)
    {
        for(int i=1;i<=numar_obiecte;i++)
        {
            printf("    Lungimea homarului %d : ",i);
            scanf("%d",&obiecte[i].marime);
            printf("    Valoarea homarului %d : ",i);
            scanf("%d",&obiecte[i].valoare);
        }
    }
    else
    {
        generare_obiecte(obiecte,numar_obiecte);
        printf("    Homari generati sunt: \n");
        printare_obiecte(obiecte,numar_obiecte);
    }
    generare_matrice_solutii(obiecte,numar_obiecte,capacitate_plasa);
    free(obiecte);
    return 0;
}
