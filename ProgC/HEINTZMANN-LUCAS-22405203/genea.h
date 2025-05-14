#ifndef GENEA_H
#define GENEA_H

#include "identite.h"
#include <stdio.h>

// Type for manipulating a genealogical tree
typedef struct sArbre* tArbre;

tArbre ArbreCreer(void);

void ArbreAfficher(tArbre Arbre);

void ArbreAjouterPersonne(tArbre Arbre, tIdentite Identite);

void ArbreLiberer(tArbre Arbre);

tArbre ArbreLirePersonnesFichier(char Fichier[]);

void ArbreAjouterLienParente(tArbre Arbre, int IdEnfant, int IdParent, char Parente);

int ArbreLireLienParentef(FILE *f, int *pIdEnfant, int *pIdParent, char *pParente);

tArbre ArbreLireLienParenteFichier(tArbre Arbre, char Fichier[]);

#endif /* GENEA_H */