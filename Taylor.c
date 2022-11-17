/*Questo file contiene:
1. Funzione ricorsiva per il calcolo di sin(x) tramite serie di taylor
2. conversione stringa in numero
3. divisione intera
4. fattoriale
5. calcolo valore minimo di un array
6. palindroma */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//sin(x) = sommatoria (k=0 -> n) (-1)^k * (x^(2k+1))/(2k+1)!

int converti(char stringa[]);
int divisione(int a, int b);

float taylor(float x, int k);
long double fattoriale(int k);

int minimo(int array[], int len);

void stampaArray(char stringa[]);
int palindroma(char s[], int start, int len);

int main(int argc, const char * argv[]) {

    int a[10] = {22,65,12,89,56,23,43,99,123,101};
    printf("Il valore minimo è: %d\n",minimo(a,10));
    //stampaArray("Ciao mondo");
    if(palindroma("itopinonavevanonipoti",0,strlen("itopinonaveanonipoti"))==0)
       printf("Non è palindroma\n");
    else
       printf("Palindroma\n");
    return 0;
}

int palindroma(char s[], int start, int len){
    if (len<=1)
        return 1;
    if (s[start]==s[start+len-1] && palindroma(s, start+1, len-2))
        return 1;
    else
        return 0;
}
void stampaArray(char stringa[]){
    if (*stringa == '\0'){
        printf("\n");
    }
    else{
        stampaArray(stringa+1);
        printf("%c",*stringa);
    }
}

int minimo(int array[], int len){
    if (len==1)
        return *array;
    else{
        int min = minimo(array+1, len-1);
        if (*array>min)
            return min;
        else
            return *array;
    }
}

int converti(char stringa[]){
    if (*stringa=='\0')
        return 0;
    
    return ((*stringa)-'0')*pow(10,strlen(stringa)-1) + converti(stringa+1);
}


int divisione(int a, int b){
    if (a<b)
        return 0;
    return 1+divisione(a-b, b);
}

float taylor(float x, int k){
    if (k==0)
        return x;
    
    return (pow(-1,k)*pow(x,2*k+1)/fattoriale(2*k+1))+taylor(x, k-1);
}

long double fattoriale(int k){
    if (k==0)
        return 1;
    else
        return k * fattoriale(k-1);
}
