/**
 * @file genea.c
 * @brief Source file for the genea module
 */

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
     struct sFiche *pCourante = Arbre->pPremiere;
     
     while (pCourante != NULL)
     {
         if (IdentiteIdentifiant(pCourante->Identite) == Id)
         {
             return pCourante;
         }
         pCourante = pCourante->pSuivante;
     }
     
     return NULL;
 }
 
 tArbre ArbreCreer(void)
 {
     tArbre nouvelArbre = (tArbre)malloc(sizeof(struct sArbre));
     
     if (nouvelArbre != NULL)
     {
         nouvelArbre->pPremiere = NULL;
         nouvelArbre->pDerniere = NULL;
     }
     
     return nouvelArbre;
 }
 
 void ArbreAfficher(tArbre Arbre)
 {
     struct sFiche *pCourante = Arbre->pPremiere;
     
     while (pCourante != NULL)
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
         
         pCourante = pCourante->pSuivante;
     }
 }
 
 void ArbreAjouterPersonne(tArbre Arbre, tIdentite Identite)
 {
     struct sFiche *nouvelleFiche = (struct sFiche *)malloc(sizeof(struct sFiche));
     
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
     
     Arbre->pDerniere = nouvelleFiche;
 }
 
 void ArbreLiberer(tArbre Arbre)
 {
     struct sFiche *pCourante = Arbre->pPremiere;
     struct sFiche *pSuivante;
     
     while (pCourante != NULL)
     {
         pSuivante = pCourante->pSuivante;
         
         // Free the person's identity
         IdentiteLiberer(pCourante->Identite);
         
         // Free the record
         free(pCourante);
         
         pCourante = pSuivante;
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
     struct sFiche *pEnfant, *pParent;
     
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