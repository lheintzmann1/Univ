/**
 * @file testidentite.c
 * @brief Test file for the identite module
 */

 #include "identite.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main(int argc, char *argv[])
 {
     tIdentite identite1, identite2;
     FILE *f;
 
     // Test 1: Create an identity manually and display it
     printf("Test 1: Create an identity manually and display it\n");
     identite1 = IdentiteCreer(16, "DUFF", "John", 'M', "13/12/2001");
     if (identite1 == NULL)
     {
         printf("Error creating identity\n");
         return EXIT_FAILURE;
     }
     IdentiteAfficher(identite1);
 
     // Test 2: Check getter functions
     printf("\nTest 2: Check getter functions\n");
     printf("Identifier: %d\n", IdentiteIdentifiant(identite1));
     printf("Last name: %s\n", IdentiteNom(identite1));
     printf("First name: %s\n", IdentitePrenom(identite1));
     printf("Gender: %c\n", IdentiteSexe(identite1));
     printf("Birth date: %s\n", IdentiteDateNaissance(identite1));
 
     // Test 3: Read an identity from a file and display it
     printf("\nTest 3: Read an identity from a file\n");
     f = fopen("personne.ind", "r");
     if (f == NULL)
     {
         printf("Error opening file\n");
         IdentiteLiberer(identite1);
         return EXIT_FAILURE;
     }
     identite2 = IdentiteLiref(f);
     if (identite2 == NULL)
     {
         printf("Error reading identity from file\n");
         fclose(f);
         IdentiteLiberer(identite1);
         return EXIT_FAILURE;
     }
     fclose(f);
     IdentiteAfficher(identite2);
 
     // Test 4: Free the identities
     printf("\nTest 4: Free the identities\n");
     IdentiteLiberer(identite1);
     IdentiteLiberer(identite2);
     printf("Identities freed successfully\n");
 
     return EXIT_SUCCESS;
 }