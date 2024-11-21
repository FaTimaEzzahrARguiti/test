#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    char rue[20], ville[20], code_postal[20];
}adresse;

//strucrure imbriqué
typedef struct{
    char nom[20];
    int age;
    adresse ad;
}Personne;


//ajouter une personne

void creer(Personne p[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("\nEntrez la personne N° %d\n", i + 1);

        printf("Entrez le nom :\n");
        scanf("%s", p[i].nom);

        printf("Entrez l'âge :\n");
        scanf("%d", &p[i].age);

        printf("Entrez la rue :\n");
        scanf("%s", p[i].ad.rue);

        printf("Entrez la ville :\n");
        scanf("%s", p[i].ad.ville);

        printf("Entrez le code postal :\n");
        scanf("%s", p[i].ad.code_postal);
    }
}
void afficher_personnes(Personne p[], int taille) {
        if (taille == 0) {
        printf("Aucune personne à afficher.\n");
        return;
    }
    for (int i = 0; i < taille; i++) {
        printf("\nPersonne N° %d\n", i + 1);
        printf("Nom : %s\n", p[i].nom);
        printf("Âge : %d\n", p[i].age);
        printf("Rue : %s\n", p[i].ad.rue);
        printf("Ville : %s\n", p[i].ad.ville);
        printf("Code postal : %s\n", p[i].ad.code_postal);
    }
}
int main()
{ int taille=0;
  int choix;
  Personne p[100];
  bool continuer = true;


    while (continuer) {
        printf("\n=== Menu ===\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher les personnes\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
            printf("Combien de personnes voulez-vous entrer ? ");
            scanf("%d", &taille);
            creer( p, taille);
                break;
            case 2:
                afficher_personnes(p, taille);
                break;
            case 3:
                printf("Au revoir !\n");
                continuer = false;
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
}

