#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "uzd.h"

int main()
{
    struct Studentas *studentPtr;
    char filename[25];
    int lines;

    printf("Iveskite failo pavadinima: ");
    scanf("%s", filename);

    while (access(filename, F_OK) != 0)
    {
        printf("Failas nerastas. Sukurkite faila arba iveskite nauja pavadinima: ");
        scanf("%s", filename);
    }

    //Apskaiciuojame eiluciu kieki
    //-------------------
    lines = eiluciuKiekis(filename);
    //-------------------
    //Iskiriame atminti strukturoms saugoti
    //-------------------
    studentPtr = atmintiesIsskyrimas(lines);
    //-------------------
    //Nuskaitome duomenis is failo
    //-------------------
    nuskaitymas(studentPtr, lines, filename);
    //-------------------
    //Spausdiname i failus
    //-------------------
    skirtingiDalykai(studentPtr, lines);

    free(studentPtr);

    return 0;
}

