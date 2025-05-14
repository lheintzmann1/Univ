#include "genea.h"
#include <stdlib.h>
#include <string.h>

// Private structure for a genealogical tree
struct sArbre
{
    struct sFiche *pPremiere; // Address of the first record
    struct sFiche *pDerniere; // Address of the last record
};

// Private structure for a record associated with each individual in the tree
struct sFiche
{
    tIdentite Identite;       // Access to the person's identity information
    struct sFiche *pPere;     // Address of the father's record
    struct sFiche *pMere;     // Address of the mother's record
    struct sFiche *pSuivante; // Address of the next record
};

// Private function to find a person in the tree by identifier
static struct sFiche *ArbreTrouverPersonne(tArbre Arbre, int Id)
{
    struct sFiche *pCourante = Arbre->pPremiere; // Start with the first record
    
    while (pCourante != NULL) // Traverse the list
    {
        if (IdentiteIdentifiant(pCourante->Identite) == Id) // Check if the identifier matches
        {
            return pCourante; // Return the address of the record if found
        }
        pCourante = pCourante->pSuivante; // Move to the next record
    }
    
    return NULL; // Return NULL if the person is not found
}

tArbre ArbreCreer(void)
{
    tArbre nouvelArbre = (tArbre)malloc(sizeof(struct sArbre)); // Allocate memory for the tree structure
    
    if (nouvelArbre != NULL)
    {
        nouvelArbre->pPremiere = NULL; // Initialize the first record to NULL
        nouvelArbre->pDerniere = NULL; // Initialize the last record to NULL
    }
    
    return nouvelArbre; // Return the address of the new tree
}

void ArbreAfficher(tArbre Arbre)
{
    struct sFiche *pCourante = Arbre->pPremiere; // Start with the first record
    
    while (pCourante != NULL) // Traverse the list
    {
        // Display the person's identity
        IdentiteAfficher(pCourante->Identite);
        
        // Display the father's identity or "unknown"
        printf("\tPère : ");
        if (pCourante->pPere != NULL)
        {
            IdentiteAfficher(pCourante->pPere->Identite);
        }
        else
        {
            printf("inconnu\n");
        }
        
        // Display the mother's identity or "unknown"
        printf("\tMère : ");
        if (pCourante->pMere != NULL)
        {
            IdentiteAfficher(pCourante->pMere->Identite);
        }
        else
        {
            printf("inconnue\n");
        }
        
        pCourante = pCourante->pSuivante; // Move to the next record
    }
}

void ArbreAjouterPersonne(tArbre Arbre, tIdentite Identite)
{
    struct sFiche *nouvelleFiche = (struct sFiche *)malloc(sizeof(struct sFiche)); // Allocate memory for the new record
    
    if (nouvelleFiche == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed when adding person with ID %d\n", IdentiteIdentifiant(Identite));
        return;
    }
    
    nouvelleFiche->Identite = Identite;
    nouvelleFiche->pPere = NULL;
    nouvelleFiche->pMere = NULL;
    nouvelleFiche->pSuivante = NULL;
    
    // Add the record at the end of the list
    if (Arbre->pPremiere == NULL)
    {
        Arbre->pPremiere = nouvelleFiche;
    }
    else
    {
        Arbre->pDerniere->pSuivante = nouvelleFiche;
    }
    
    Arbre->pDerniere = nouvelleFiche; // Update the last record pointer
}

void ArbreLiberer(tArbre Arbre)
{
    struct sFiche *pCourante = Arbre->pPremiere; // Start with the first record
    struct sFiche *pSuivante; // Pointer to the next record
    
    while (pCourante != NULL)
    {
        pSuivante = pCourante->pSuivante; // Store the address of the next record
        
        // Free the person's identity
        IdentiteLiberer(pCourante->Identite);
        
        // Free the record
        free(pCourante);
        
        pCourante = pSuivante; // Move to the next record
    }
    
    // Free the tree
    free(Arbre);
}

tArbre ArbreLirePersonnesFichier(char Fichier[])
{
    FILE *f;
    tArbre arbre;
    tIdentite identite;
    
    // Open the file
    f = fopen(Fichier, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", Fichier);
        return NULL;
    }
    
    // Create the tree
    arbre = ArbreCreer();
    if (arbre == NULL)
    {
        fclose(f);
        return NULL;
    }
    
    // Read the identities from the file and add them to the tree
    while ((identite = IdentiteLiref(f)) != NULL)
    {
        ArbreAjouterPersonne(arbre, identite);
    }
    
    // Close the file
    fclose(f);
    
    return arbre;
}

void ArbreAjouterLienParente(tArbre Arbre, int IdEnfant, int IdParent, char Parente)
{
    struct sFiche *pEnfant, *pParent; // Pointers to the child and parent records
    
    // Find the child and parent records
    pEnfant = ArbreTrouverPersonne(Arbre, IdEnfant);
    pParent = ArbreTrouverPersonne(Arbre, IdParent);
    
    // Check if both records were found
    if (pEnfant == NULL)
    {
        fprintf(stderr, "Error: Child with ID %d not found in the tree\n", IdEnfant);
        return;
    }
    
    if (pParent == NULL)
    {
        fprintf(stderr, "Error: Parent with ID %d not found in the tree\n", IdParent);
        return;
    }
    
    // Add the parental link
    if (Parente == 'P')
    {
        pEnfant->pPere = pParent;
    }
    else if (Parente == 'M')
    {
        pEnfant->pMere = pParent;
    }
    else
    {
        fprintf(stderr, "Error: Invalid parental link type '%c'\n", Parente);
    }
}

int ArbreLireLienParentef(FILE *f, int *pIdEnfant, int *pIdParent, char *pParente)
{
    char ligne[100];
    
    // Read a line from the file
    if (fgets(ligne, sizeof(ligne), f) == NULL || ligne[0] == '\n')
    {
        return 0;
    }
    
    // Parse the line
    if (sscanf(ligne, "%d %d %c", pIdEnfant, pIdParent, pParente) != 3)
    {
        return 0;
    }
    
    return 1;
}

tArbre ArbreLireLienParenteFichier(tArbre Arbre, char Fichier[])
{
    FILE *f;
    int idEnfant, idParent;
    char parente;
    
    // Open the file
    f = fopen(Fichier, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", Fichier);
        return NULL;
    }
    
    // Read the parental links from the file and add them to the tree
    while (ArbreLireLienParentef(f, &idEnfant, &idParent, &parente))
    {
        ArbreAjouterLienParente(Arbre, idEnfant, idParent, parente);
    }
    
    // Close the file
    fclose(f);
    
    return Arbre;
}