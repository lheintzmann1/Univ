/**
 * @file testgenea.c
 * @brief Test file for the genea module
 */

 #include "genea.h"
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[])
 {
     tArbre arbre;
     
     // Check the number of arguments
     if (argc != 3)
     {
         fprintf(stderr, "Usage: %s fichier-personnes fichier-liens-parente\n", argv[0]);
         return EXIT_FAILURE;
     }
     
     // Create the tree from the persons file
     arbre = ArbreLirePersonnesFichier(argv[1]);
     if (arbre == NULL)
     {
         fprintf(stderr, "Error creating the tree from file %s\n", argv[1]);
         return EXIT_FAILURE;
     }
     
     // Add the parental links from the parental links file
     if (ArbreLireLienParenteFichier(arbre, argv[2]) == NULL)
     {
         fprintf(stderr, "Error adding parental links from file %s\n", argv[2]);
         ArbreLiberer(arbre);
         return EXIT_FAILURE;
     }
     
     // Display the tree
     printf("Genealogical tree:\n");
     ArbreAfficher(arbre);
     
     // Free the tree
     ArbreLiberer(arbre);
     
     return EXIT_SUCCESS;
 }