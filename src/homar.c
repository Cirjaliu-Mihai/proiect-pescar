#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "homar.h"
void generare_obiecte(struct obiect *obiecte,int numar_obiecte)//generarea aleatorie a unui set de date
{
    int i;

    srand(1);
    for(i = 1; i <= numar_obiecte; i++)
    {
        obiecte[i].marime = rand() % 100 + 1;
        obiecte[i].valoare = rand() % 100 + 1;
    }
}

int maxim_2nr(int valoare1, int valoare2)//maximul a 2 numere
{
    if (valoare1 > valoare2)
    {
        return valoare1;
    }
    else
    {
        return valoare2;
    }
}

void generare_matrice_solutii(struct obiect *obiecte, int numar_obiecte,int capacitate_plasa)//algoritmul de generare a matricii de solutii pentru problema rucsacului folosind formula
{
    struct s_matrice matrice;
    matrice.nrrand=numar_obiecte+1;
    matrice.nrcol=capacitate_plasa+1;
    matrice.matrice=calloc(matrice.nrrand*matrice.nrcol,sizeof(int));
    int val1,val2,val3;//val1-valoarea de pe randul superior
    //val2-valoarea de pe randul superior fara marimea obiectului curent
    //val3-valoarea 2 + pretul obiectului curent
    for(int iterator_obiect=1; iterator_obiect<=numar_obiecte; iterator_obiect++)
    {
        for(int marime=1; marime<=capacitate_plasa; marime++)
        {
            val1=gasire_valoare_matrice(matrice,iterator_obiect-1,marime);
            if((marime-obiecte[iterator_obiect].marime)>=0)//in caz ca valoarea de pe randul superior fara marimea obiectului curent nu este in matrice
            {
                val2=gasire_valoare_matrice(matrice,iterator_obiect-1,marime-obiecte[iterator_obiect].marime);
                val3=val2+obiecte[iterator_obiect].valoare;
            }
            else
            {
                val2=0;
                val3=0;
            }

            int val_max=maxim_2nr(val1,val3);
            setare_valoare_matrice(matrice,iterator_obiect,marime,val_max);//introducem in matrice val pentru obiectul curent si marimea curenta
        }
    }
    //afisare(matrice);
    printf("    Valoarea maxima a homarilor care pot intra in plasa este : %d monede de aur",gasire_valoare_matrice(matrice,matrice.nrrand-1,matrice.nrcol-1));
    free(matrice.matrice);
}
void printare_obiecte(struct obiect *obiecte,int numar_obiecte)//afisarea homarilor care sunt disponibil pentru a fi pusi in plasa
{
    for(int i=1; i<=numar_obiecte; i++)
    {
        printf("    Lungimea homarului %d : %d cm\n",i,obiecte[i].marime);
        printf("    Valoarea homarului %d : %d monede de aur\n",i,obiecte[i].valoare);

    }
}
void setare_valoare_matrice(struct s_matrice matrice,int rand,int coloana,int valoare)
{
    int pozitie=rand*matrice.nrcol+coloana;
    *(matrice.matrice+pozitie)=valoare;
}
int gasire_valoare_matrice(struct s_matrice matrice,int rand,int coloana)
{
    int pozitie=rand*matrice.nrcol+coloana;
    return *(matrice.matrice+pozitie);
}
void afisare(struct s_matrice matrice)
{
    printf("    Matricea de solutii va fi: \n");
    for(int i=0; i<=matrice.nrrand-1; i++)
    {
        for(int j=0; j<=matrice.nrcol-1; j++)
        {
            printf("%d ",matrice.matrice[i*matrice.nrcol+j]);
        }
        printf("\n");
    }
}
