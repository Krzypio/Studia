//@Autor Krzysztof Piotrowski 2019-11-14

#include <stdio.h>
#include <stdlib.h>

//Prototyp funkcji
int poprawnie_wczytaj_liczbe();

int main()
{
    printf("--WDI. ALGORYTMY I STRUKTURY DANYCH. ZAD 12.--\n");
    printf("Pobieranie liczb calkowitych od uzytkownika. Przerwij piszac '-1'\n");

    //Obliczenia: Ile pamieci zaalokowac?
    int rozmiar_elementu = sizeof(int);
    int liczba_elementow = 10;
    int rozmiar_tablicy = rozmiar_elementu*liczba_elementow;

    //Alokowanie pamieci na tablice
    int* tablica = malloc(rozmiar_tablicy);

    //petla wczytywania liczb i powiekszania tablicy
    int licznik = 0;    //licznik wprowadzonych liczb
    int liczba = 0;     //wartosc wprowadzonej liczby
    while (-1 != liczba){
        liczba = poprawnie_wczytaj_liczbe();    //funkcja zadeklarowana nizej
        if (-1 != liczba){
            licznik++;
            //powiekszanie tablicy
            if (licznik > liczba_elementow){
                liczba_elementow++;
                rozmiar_tablicy = rozmiar_elementu*liczba_elementow;
                tablica = realloc(tablica, rozmiar_tablicy);
                printf("Powiekszanie tablicy do %i elementow\n", licznik);
            }//if
            tablica[licznik-1] = liczba;
        }//if
    }//while

    //Wyswietl odwrotna tablice
    printf("\nOdwrtotna tablica wprowadzonych wartosci: \n");
    int i=licznik;
    for(i; i>0; i--){
        //wyswietlanie przecinka
        if (i != licznik){
            printf(", ");
        }//of
        printf("%d", tablica[i-1]);
    };
    printf("\n");

    printf("\nKoniec programu");
    return 0;
}

int poprawnie_wczytaj_liczbe(){
    int bufor = 0;
    int poprawnosc = 0;
    //sprawdzanie poprawnosci wprowadzenia liczby
    while (0 == poprawnosc) {
        printf("Wprowadz liczbe: ");
        poprawnosc = scanf("%d", &bufor);   //1 poprawnie, 0 zle
        if (0 == poprawnosc) {
            printf("\tInput is not an integer!\n");
        }
        fflush(stdin);  //wyczysc bufor wejœcia
    }//while
    return bufor;
}//poprawnie_wczytaj_liczbe
