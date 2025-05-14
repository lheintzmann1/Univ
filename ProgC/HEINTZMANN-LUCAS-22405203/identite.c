#include "identite.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 80

// Private structure for a person's identity
struct sIdentite
{
    int Identifiant; // Unique identifier
    char *Nom; // Last name (dynamically allocated string)
    char *Prenom; // First name (dynamically allocated string)
    char Sexe; // 'F' or 'M'
    char DateNaissance[LG_DATE + 1]; // Birth date in the format DD/MM/YYYY
};

tIdentite IdentiteCreer(int Id, char *Nom, char *Prenom, char Sexe, char DateNais[])
{
    tIdentite nouvelleIdentite = NULL;

    // Allocate memory for the identity structure
    nouvelleIdentite = (tIdentite)malloc(sizeof(struct sIdentite));
    if (nouvelleIdentite == NULL)
    {
        return NULL;
    }

    // Initialize the identifier and gender
    nouvelleIdentite->Identifiant = Id;
    nouvelleIdentite->Sexe = Sexe;

    // Allocate memory for the last name and copy it
    nouvelleIdentite->Nom = (char *)malloc((strlen(Nom) + 1) * sizeof(char));
    if (nouvelleIdentite->Nom == NULL)
    {
        free(nouvelleIdentite);
        return NULL;
    }
    strcpy(nouvelleIdentite->Nom, Nom);

    // Allocate memory for the first name and copy it
    nouvelleIdentite->Prenom = (char *)malloc((strlen(Prenom) + 1) * sizeof(char));
    if (nouvelleIdentite->Prenom == NULL)
    {
        free(nouvelleIdentite->Nom);
        free(nouvelleIdentite);
        return NULL;
    }
    strcpy(nouvelleIdentite->Prenom, Prenom);

    // Copy the birth date
    strncpy(nouvelleIdentite->DateNaissance, DateNais, LG_DATE);
    nouvelleIdentite->DateNaissance[LG_DATE] = '\0';

    return nouvelleIdentite;
}

int IdentiteIdentifiant(tIdentite Identite)
{
    return Identite->Identifiant;
}

char *IdentiteNom(tIdentite Identite)
{
    return Identite->Nom;
}

char *IdentitePrenom(tIdentite Identite)
{
    return Identite->Prenom;
}

char IdentiteSexe(tIdentite Identite)
{
    return Identite->Sexe;
}

char *IdentiteDateNaissance(tIdentite Identite)
{
    return Identite->DateNaissance;
}

void IdentiteAfficher(tIdentite Identite)
{
    printf("[%d] %s %s, %c, %s\n", 
           Identite->Identifiant, 
           Identite->Nom, 
           Identite->Prenom, 
           Identite->Sexe, 
           Identite->DateNaissance);
}

void IdentiteLiberer(tIdentite Identite)
{
    if (Identite != NULL)
    {
        // Free the dynamically allocated strings
        if (Identite->Nom != NULL)
        {
            free(Identite->Nom);
        }
        if (Identite->Prenom != NULL)
        {
            free(Identite->Prenom);
        }
        // Free the identity structure
        free(Identite);
    }
}

tIdentite IdentiteLiref(FILE *f)
{
    char ligne[MAX_LINE_LENGTH + 1]; // Buffer for reading lines
    int id;
    char sexe;
    char nom[MAX_LINE_LENGTH + 1];
    char prenom[MAX_LINE_LENGTH + 1];
    char dateNaissance[LG_DATE + 1];

    if (fgets(ligne, sizeof(ligne), f) == NULL || ligne[0] == '\n') return NULL; // Read the identifier
    id = atoi(ligne); // Convert the identifier to an integer (ASCII to int)

    if (fgets(nom, sizeof(nom), f) == NULL) return NULL; // Read the last name
    nom[strcspn(nom, "\n")] = '\0'; // Remove the newline character

    if (fgets(prenom, sizeof(prenom), f) == NULL) return NULL; // Read the first name
    prenom[strcspn(prenom, "\n")] = '\0'; // Remove the newline character

    if (fgets(ligne, sizeof(ligne), f) == NULL) return NULL; // Read the sex
    sexe = ligne[0]; // Get the first character of the line

    if (fgets(ligne, sizeof(ligne), f) == NULL) return NULL; // Read the birth date
    ligne[strcspn(ligne, "\n")] = '\0'; // Remove the newline character
    strncpy(dateNaissance, ligne, LG_DATE); // Copy the date
    dateNaissance[LG_DATE] = '\0'; // Ensure null termination

    return IdentiteCreer(id, nom, prenom, sexe, dateNaissance); // Create the identity and return it
}
