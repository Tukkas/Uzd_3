#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uzd.h"

int eiluciuKiekis(char *filename)
{
    int ch, count = 0;
    FILE* fptr = fopen(filename, "r");

    if (fptr != NULL)
    {
        do
        {
            ch = fgetc(fptr);

            if(ch == '\n') count++;
        }
        while (ch != EOF);
    }

    fclose(fptr);
    return count;
}

struct Studentas *atmintiesIsskyrimas(int lines)
{
    struct Studentas *studentPtr;

    studentPtr = (struct Studentas*) malloc(lines * sizeof(struct Studentas));

    return studentPtr;

}

void nuskaitymas(struct Studentas *studentPtr, int lines, char *filename)
{
    FILE *fptr;

    if (studentPtr != NULL)
    {
        fptr = fopen(filename,"r");
        if (fptr != NULL)
        {
            for(int i = 0; i < lines; ++i)
            {
                fscanf(fptr,"%s %s %s %f", (studentPtr+i)->vardas, (studentPtr+i)->pavarde, (studentPtr+i)->dalykas, &(studentPtr+i)->vidurkis);
            }
        }
        fclose(fptr);
    }
}

void skirtingiDalykai(struct Studentas *studentPtr, int lines)
{
    int printId = 1;

    for (int i = 0; i < lines; i++)
    {
        printId = 1;
        for (int j = 0; j < i; j++)
        {
            if (strcmp((studentPtr+i)->dalykas, (studentPtr+j)->dalykas) == 0)
            {
                printId = 0;
            }
        }
        if (printId != 0) spausdinimas(studentPtr, lines, (studentPtr+i)->dalykas);
    }
}

void spausdinimas(struct Studentas *studentPtr, int lines, char *filename)
{
    strncat(filename, ".txt", 5);
    FILE *fptr;
    fptr = fopen(filename,"w");
    filename[strlen(filename)-4] = '\0';

    if (fptr != NULL)
    {
        for(int i = 0; i < lines; i++)
        {
            if (strcmp(filename, (studentPtr+i)->dalykas) == 0 && (studentPtr+i)->vidurkis > 8.5)
            {
                fprintf(fptr, "%-15s %-15s %-15s %-6.2f \n", (studentPtr+i)->vardas, (studentPtr+i)->pavarde, (studentPtr+i)->dalykas, (studentPtr+i)->vidurkis);
            }
        }
    }

    fclose(fptr);
}
