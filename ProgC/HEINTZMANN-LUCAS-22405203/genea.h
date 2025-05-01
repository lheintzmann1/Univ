/**
 * @file genea.h
 * @brief Header file for the genea module
 */

 #ifndef GENEA_H
 #define GENEA_H
 
 #include "identite.h"
 #include <stdio.h>
 
 // Type for manipulating a genealogical tree
 typedef struct sArbre* tArbre;
 
 /**
  * @brief Creates an empty genealogical tree
  * @return The created tree or NULL in case of memory allocation problem
  */
 tArbre ArbreCreer(void);
 
 /**
  * @brief Displays the genealogical tree on the screen
  * @param Arbre The genealogical tree
  */
 void ArbreAfficher(tArbre Arbre);
 
 /**
  * @brief Adds a person to the genealogical tree
  * @param Arbre The genealogical tree
  * @param Identite The person's identity
  */
 void ArbreAjouterPersonne(tArbre Arbre, tIdentite Identite);
 
 /**
  * @brief Frees the memory used by the genealogical tree
  * @param Arbre The genealogical tree
  */
 void ArbreLiberer(tArbre Arbre);
 
 /**
  * @brief Creates a genealogical tree from a file containing persons' identities
  * @param Fichier The file name
  * @return The created tree or NULL in case of problem
  */
 tArbre ArbreLirePersonnesFichier(char Fichier[]);
 
 /**
  * @brief Adds a parental link in the genealogical tree
  * @param Arbre The genealogical tree
  * @param IdEnfant The child's identifier
  * @param IdParent The parent's identifier
  * @param Parente The parental link type ('P' for father or 'M' for mother)
  */
 void ArbreAjouterLienParente(tArbre Arbre, int IdEnfant, int IdParent, char Parente);
 
 /**
  * @brief Reads a parental link from a file
  * @param f The file pointer
  * @param pIdEnfant Pointer to store the child's identifier
  * @param pIdParent Pointer to store the parent's identifier
  * @param pParente Pointer to store the parental link type
  * @return 1 if the reading was successful, 0 otherwise
  */
 int ArbreLireLienParentef(FILE *f, int *pIdEnfant, int *pIdParent, char *pParente);
 
 /**
  * @brief Adds parental links to a genealogical tree from a file
  * @param Arbre The genealogical tree
  * @param Fichier The file name
  * @return The modified tree or NULL in case of problem
  */
 tArbre ArbreLireLienParenteFichier(tArbre Arbre, char Fichier[]);
 
 #endif /* GENEA_H */