#include <stdio.h>
#include <assert.h>

//Ex4 Q1
//Affiche un carre de cote 3 avec le nombre n
void carre(int n){
    printf("%d%d%d\n", n,n,n);
    printf("%d%d%d\n", n,n,n);
    printf("%d%d%d\n", n,n,n);
}

//Ex4 Q2
//Affiche un carre de taille 4x4 evide de valeur n
void carre_evide(int n){
    printf("%d%d%d%d\n", n,n,n,n);
    printf("%d  %d\n", n,n);
    printf("%d  %d\n", n,n);
    printf("%d%d%d%d\n", n,n,n,n);
}

//Ex 5 - Q1
//Renvoie le minimum entre n_1 et n_2
int min(int n_1, int n_2){
    if (n_1 < n_2){
        return n_1;
    }
    else{
        return n_2;
    }
}
//Ex 5 - Q2
//Renvoie le maximum entre n_1 et n_2
int max(int n_1, int n_2){
    if (n_1 < n_2){
        return n_2;
    }
    else{
        return n_1;
    }
}

//Ex 5 - Q3
//Pareil mais pour les doubles
double min_double(double n_1, double n_2){
    if (n_1 < n_2){
        return n_1;
    }
    else{
        return n_2;
    }
}

//Pareil mais pour les doubles
double max_double(double n_1, double n_2){
    if (n_1 < n_2){
        return n_2;
    }
    else{
        return n_1;
    }
}

//Ex 5 - Q5
//Affiche l'heure qui suit un instant donner
void affiche_instant_suivant(int heure, int minute, int seconde){
    //Verifier que l'entrer est correct
    assert(heure >= 0 && heure <= 23);
    assert(minute >= 0 && minute <= 59);
    assert(seconde >= 0 && seconde <= 59);

    int nouv_seconde = seconde + 1;
    int nouv_minute = minute;
    int nouv_heure = heure;

    if (nouv_seconde == 60){
        nouv_seconde = 0;
        nouv_minute++;
        if (nouv_minute == 60){
            nouv_minute = 0;
            nouv_heure++;
            if(nouv_heure == 24){
                nouv_heure = 0;
            }
        }
        else{
            nouv_minute++;
        }
    }

    //Affichage heures
    if(nouv_heure <= 1){
        printf("%d heure ", nouv_heure);
    }
    else{
        printf("%d heures ", nouv_heure);
    }
    //Affichage minutes
    if(nouv_minute <= 1){
        printf("%d minute ", nouv_minute);
    }
    else{
        printf("%d minutes ", nouv_minute);
    }

    //Affichage secondes
    if(nouv_seconde <= 1){
        printf("%d seconde \n", nouv_seconde);
    }
    else{
        printf("%d secondes \n", nouv_seconde);
    }
}

//Ex6 - Q1
//Affiche les nombres pairs entre 10 et 1000
void affiche_pair(){
    for(int i = 10; i <= 1000; i++){
        if (i % 2 == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

//Ex6 - Q2
//Affiche les nombre impairs entre 501 et 0 dans l'ordre decroissant
void affiche_impair(){
    for (int i = 501; i >= 0; i--){
        if(i % 2 == 1){
            printf("%d ", i);
        }
    }
    printf("\n");
}

//Ex7 - Q1
//Calcule n^k
int puissance(int n, int k){
    if (k == 0){
        return 1;
    }
    else if(k % 2 == 0){
        return puissance(n, k/2) * puissance(n, k/2);
    }
    else{
        return n * puissance(n, (k-1)/2) * puissance(n, (k-1)/2);
    }
}

double puissance_double_posi(double n, int k){
    if (k == 0){
        return 1;
    }
    else if(k % 2 == 0){
        return puissance(n, k/2) * puissance(n, k/2);
    }
    else{
        return n * puissance(n, (k-1)/2) * puissance(n, (k-1)/2);
    }
}

//Calcule n^k avec n en reel
double puissance_double(double n, int k){
    if (k > 0 && n != 0.0){
        return puissance_double_posi(n,k);
    }
    else if (k < 0 && n != 0.0){
        return 1 / puissance_double_posi(n,(-1) * k);
    }
    else if (k == 0 && n != 0.0){
        return 1;
    }
    else{
        return 0;
    }
}

//Ex7 - Q2
//Calcule n!
int fact(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * fact(n-1);
    }
}

//Ex7 - Q3
//Calcule le n-ime terme de la suite de fibonnaci
int fib(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

//Ex8 - Q1
//Affiche un carre de constitue de n
void carre_2(int hauteur, int largeur, int n){
    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){
            printf("%d", n);
        }
        printf("\n");
    }
}

//Ex8 - Q2
//affiche un carre evide de n
void carre_evide_2(int hauteur, int largeur, int n){
    for (int i = 0; i < hauteur; i++){
        if (i == 0 || i == (hauteur-1)){
            for (int j = 0; j < largeur; j++){
                printf("%d" , n);
            }
        }
        else{
            for (int j = 0; j < largeur; j++){
                if(j == 0 || j == (largeur-1)){
                    printf("%d", n);
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

//Ex9 - Q1
//Calcule la prochaine valeur avec l'algo de syracuse
int suivant_syracuse(int n){
    if(n % 2 == 0){
        return n/2;
    }
    else{
        return(3*n + 1);
    }
}

//Ex9 - Q2
//renvoie le temps de vol pour n via l'algo de syracuse
int temps_de_vol(int n){
    int temps = 0;
    int actuelle_syracuse = n;

    while(actuelle_syracuse != 1){
        //printf("%d ", actuelle_syracuse);
        actuelle_syracuse = suivant_syracuse(actuelle_syracuse);
        //printf("%d ", actuelle_syracuse);
        temps++;
    }
    //printf("\n");
    return temps;
}

//Ex9 - Q3
//Compte le nombre d'entier entre 1 et 10000 dont le temps de vol est > 20
int compte_tdv(){
    int cpt = 0;
    for (int i = 1; i <= 10000; i++){
        if (temps_de_vol(i) >= 20){
            cpt++;
            //printf("%d : a un temps de vol >= 20 \n", i);
        }
    }
    return cpt;
}

//Ex10 - Q1
//Renvoie le plus petit k tel que fib(k) > n 
int arg_fib(int n){
    int k = 0;
    while (fib(k) <= n){
        k++;
    }
    return k;
}

//Ex10 - Q2
//Renvoie le plus petit k tel que fact(k) > n 
int arg_fact(int n){
    int k = 0;
    while (fact(k) <= n){
        k++;
    }
    return k;
}

//Ex11 - Q1/2/3
//Calcule le pgcd de a et b via l'algo d'Euclide
int pgcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return pgcd(b, a%b);
    }

}

//Ex12 - Q1
//Renvoie le plus petit puissance de 2 pour n
int plus_petit_k(int n){
    int k = 0;
    while (n - puissance(2, k) >= 0){
        k++;
    }
    return k;
}

//Affiche le decomposition de n dan la base 2 de cette maniere 12 = 0x1 + 0x2 + 1x4 + 1x8
void decompose(int n){
    int k = plus_petit_k(n);

    int d_j = n%2;
    int n_partielle = d_j;
    printf("%d = %dx1", n, d_j);
    if (k > 1){
        printf(" + ");
    }
    for (int j = 1; j < k; j++){
        //n_partielle = n_partielle + (d_j * puissance(2, j));
        d_j = ((n - n_partielle)/puissance(2, j)) % 2;
        n_partielle = n_partielle + (d_j * puissance(2, j));
        //printf("%d : %d\n", d_j, j);
        printf("%dx%d", d_j, puissance(2,j));
        if(j < k-1){
            printf(" + ");
        }
    }
    printf("\n");
}

//Renvoie le plus petit puissance de b pour n
int plus_petit_k_base(int n, int b){
    int k = 0;
    while(n - puissance(b,k) >= 0){
        k++;
    }
    return k;
}

//Ex12 - Q2
//Affiche le decomposition de n dan la base b
void affiche_decomposition(int n, int b){
    int k = plus_petit_k_base(n,b);

    int d_j = n%b;
    int n_partielle = d_j;
    printf("%d = %dx%d", n, d_j, 1); //0 = b^0
    if(k >= 1){
        printf(" + ");
    }
    for (int j = 1; j < k; j++){
        d_j = ((n - n_partielle)/puissance(b, j))%b;
        n_partielle = n_partielle + d_j * puissance(b, j);
        printf("%dx%d", d_j, puissance(b,j));
        if(j < k-1){
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    carre(5);
    carre(4);
    carre_evide(4);
    printf("min : %d\n", min(30,4));
    printf("max : %d\n", max(30,4));
    printf("min : %f\n", min_double(30.0,4.0));
    printf("max : %f\n", max_double(30.0,4.0));

    affiche_instant_suivant(2,45,0);
    affiche_instant_suivant(2,45,12);
    affiche_instant_suivant(2,0,59);
    affiche_instant_suivant(0,59,59);
    affiche_instant_suivant(23,59,59);

    //affiche_pair();
    //affiche_impair();

    printf("5^1 = %d \n", puissance(5,1));
    printf("2^9 = %d \n", puissance(2,9));

    printf("(-2)^(-9) = %f \n", puissance_double(-2.0, -9));

    printf("12! = %d \n", fact(12));
    printf("7! = %d \n", fact(7));

    printf("fib(18) = %d \n", fib(18));
    carre_2(20,20,20);
    carre_evide_2(17,17,7);

    printf("Suivante syracuse de 2 est %d \n", suivant_syracuse(2));
    printf("Temps de vol pour 4 = %d\n", temps_de_vol(4));
    printf("nb vol > 20 : %d \n", compte_tdv());

    printf("Plus petit k tel que fib(k) > 743 : %d\n", arg_fib(743));
    printf("Plus petit k tel que fact(k) > 1709 ; %d\n", arg_fact(1709));

    printf("pgcd de 12, 8 = %d\n", pgcd(12,8));
    printf("pgcd de 13441, 33469 = %d\n", pgcd(13441,33469));

    decompose(12);
    decompose(18);
    decompose(1);
    affiche_decomposition(13441, 17);
    return 0;
}