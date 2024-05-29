#ifndef homar
#define homar

struct obiect{
    int marime;
    int valoare;
};
struct s_matrice{
int nrcol,nrrand;
int *matrice;
};

void generare_obiecte(struct obiect *obiecte, int numar_obiecte);
void generare_matrice_solutii(struct obiect *obiecte, int numar_obiecte, int capacitate_plasa);
void printare_obiecte(struct obiect *obiecte,int numar_obiecte);
int maxim_2nr(int valoare1, int valoare2);
void setare_valoare_matrice(struct s_matrice matrice,int rand,int coloana,int valoare);
int gasire_valoare_matrice(struct s_matrice matrice,int rand,int coloana);
void afisare(struct s_matrice matrice);
#endif
