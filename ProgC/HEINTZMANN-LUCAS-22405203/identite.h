#ifndef IDENTITE_H
#define IDENTITE_H
 
#include <stdio.h>
 
#define LG_DATE 10 // Number of characters in a date in the format DD/MM/YYYY
 
// Type for manipulating a person's identity
typedef struct sIdentite* tIdentite;
 
tIdentite IdentiteCreer(int Id, char *Nom, char *Prenom, char Sexe, char DateNais[]);

int IdentiteIdentifiant(tIdentite Identite);

char *IdentiteNom(tIdentite Identite);

char *IdentitePrenom(tIdentite Identite);

char IdentiteSexe(tIdentite Identite);

char *IdentiteDateNaissance(tIdentite Identite);

void IdentiteAfficher(tIdentite Identite);

void IdentiteLiberer(tIdentite Identite);

tIdentite IdentiteLiref(FILE *f);

#endif /* IDENTITE_H */