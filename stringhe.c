/* Questo file contiene gli esercizi ricorsivi per 
1. Sostituzione di una parola all'interno del testo
2. aggiunta alla fine del testo di una parola
3. Conta i carattere in un testo
4. Conta l'occorrenza di una parola in un testo*/

#include <stdio.h>
#include <string.h>

//Ricorsione
int lunghezzaStringa(char str[]);
void modificaTestoRic(char testo[], char parola[], char parolaDaInserire[]);
void modificaTesto(char testo[], char parola[], char parolaDaInserire[]);
void aggiungi(char testo[], char daAggiungere[]);

int conta(char testo[], char c);
int contaParola(char testo[], char parola[]);
void contaParola2(char testo[], char parola[], int *cont);

int main(int argc, const char * argv[]) {
    char testo[1000];
   
    int conteggio = 0;
    
    
    printf("Inserisci il testo: ");
    gets(testo);
    
    //modificaTesto(testo, "saluti", "mahalo");
    //modificaTestoRic(testo, "saluti", "mahalo");
    printf("La lettera i compare %d volte\n",conta(testo, 'i'));
    printf("La parola %s compare %d volte\n","ciao",contaParola(testo, "ciao"));
    
    printf("%s\n",testo);
    
    contaParola2(testo, "ciao", &conteggio);
    printf("La parola %s compare %d volte\n","ciao",
        conteggio);
    return 0;
}

int lunghezzaStringa(char str[]){
    if (str[0]=='\0')
        return 0;
    return 1+lunghezzaStringa(str[1]);
}

void modificaTestoRic(char testo[], char parola[], char parolaDaInserire[]){
    
    if (strstr(testo,parola)==NULL)
        return;
    else {
        testo = strstr(testo,parola);
        strncpy(testo, parolaDaInserire, strlen(parolaDaInserire));
        modificaTestoRic(testo, parola, parolaDaInserire);
    }
}

void modificaTesto(char testo[], char parola[], char parolaDaInserire[]){
    while(strstr(testo, parola)!=NULL){
        testo = strstr(testo, parola);
        strncpy(testo,parolaDaInserire,strlen(parolaDaInserire));
    }
    if (testo!=NULL)
        aggiungi(testo,parolaDaInserire);
}

void aggiungi(char testo[], char daAggiungere[]){
    strcat(testo, " ");
    strcat(testo, daAggiungere);
}

int conta(char testo[], char c){
    if (*testo == '\0')
        return 0;
    else {
        if (*testo == c)
            return 1+conta(testo+1,c);
        else
            return conta(testo+1,c);
    }
    
}


int contaParola(char testo[], char parola[]){
    if (strstr(testo,parola)==NULL)
        return 0;
    testo = strstr(testo,parola);
    return 1+contaParola(testo+strlen(parola), parola);
    
}

void contaParola2(char testo[], char parola[], int *cont){
    if (strstr(testo,parola)==NULL)
        return;
    
    (*cont)++;
    testo = strstr(testo,parola);
    contaParola2(testo+strlen(parola), parola, cont);
}



