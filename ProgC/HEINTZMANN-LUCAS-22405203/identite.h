/**
 * @file identite.h
 * @brief Header file for the identite module
 */

 #ifndef IDENTITE_H
 #define IDENTITE_H
 
 #include <stdio.h>
 
 #define LG_DATE 10 // Number of characters in a date in the format DD/MM/YYYY
 
 // Type for manipulating a person's identity
 typedef struct sIdentite* tIdentite;
 
 /**
  * @brief Creates an identity with the given information
  * @param Id The person's identifier
  * @param Nom The person's last name
  * @param Prenom The person's first name
  * @param Sexe The person's gender ('F' or 'M')
  * @param DateNais The person's birth date in the format DD/MM/YYYY
  * @return The created identity or NULL in case of memory allocation problem
  */
 tIdentite IdentiteCreer(int Id, char *Nom, char *Prenom, char Sexe, char DateNais[]);
 
 /**
  * @brief Returns the person's identifier
  * @param Identite The person's identity
  * @return The person's identifier
  */
 int IdentiteIdentifiant(tIdentite Identite);
 
 /**
  * @brief Returns the address of the first character of the person's last name
  * @param Identite The person's identity
  * @return The address of the first character of the person's last name
  */
 char *IdentiteNom(tIdentite Identite);
 
 /**
  * @brief Returns the address of the first character of the person's first name
  * @param Identite The person's identity
  * @return The address of the first character of the person's first name
  */
 char *IdentitePrenom(tIdentite Identite);
 
 /**
  * @brief Returns the person's gender
  * @param Identite The person's identity
  * @return The person's gender ('F' or 'M')
  */
 char IdentiteSexe(tIdentite Identite);
 
 /**
  * @brief Returns the address of the first character of the person's birth date
  * @param Identite The person's identity
  * @return The address of the first character of the person's birth date
  */
 char *IdentiteDateNaissance(tIdentite Identite);
 
 /**
  * @brief Displays the person's identity on the screen
  * @param Identite The person's identity
  */
 void IdentiteAfficher(tIdentite Identite);
 
 /**
  * @brief Frees the memory used by the person's identity
  * @param Identite The person's identity
  */
 void IdentiteLiberer(tIdentite Identite);
 
 /**
  * @brief Reads a person's identity from a text file
  * @param f The file pointer
  * @return The created identity or NULL if there's nothing to read or if there's a memory allocation problem
  */
 tIdentite IdentiteLiref(FILE *f);
 
 #endif /* IDENTITE_H */