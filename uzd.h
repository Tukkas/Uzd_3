#ifndef UZD_H_INCLUDED
#define UZD_H_INCLUDED

struct Studentas
{
    char vardas[25];
    char pavarde[25];
    char dalykas[25];
    float vidurkis;
};

int eiluciuKiekis(char *filename);
struct Studentas *atmintiesIsskyrimas(int lines);
void nuskaitymas(struct Studentas *studentPtr, int lines, char *filename);
void skirtingiDalykai(struct Studentas *studentPtr, int lines);
void spausdinimas(struct Studentas *studentPtr, int lines, char *filename);

#endif // UZD_H_INCLUDED
