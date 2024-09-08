#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVRES 100
#define MAX_TITRE 50

int main()
{
    int Choix;
    char titre[MAX_LIVRES][MAX_TITRE];
    char auteur[MAX_LIVRES][MAX_TITRE];
    int prix[MAX_LIVRES];
    int quantite[MAX_LIVRES];
    int Nombrelivre = 0;
    do
    {
        printf("\n");
        printf("1: Ajouter un livre au stock:\n ");
        printf("2: Afficher tous les livres disponibles\n ");
        printf("3: Rechercher un livre par son titr\n ");
        printf("4: Mettre a jour la quantité d'un livre\n ");
        printf("5: Supprimer un livre du stock\n ");
        printf("6: Afficher le nombre total de livres en stock\n ");
        printf("\n ");
        printf("entrer nombre de votre choix: ");
        scanf("%d", &Choix);
        printf("\n ");

        if (Choix == 1)
        {
            if (Nombrelivre < MAX_LIVRES)
            {
                printf("Titre du livre: ");
                scanf("%s", titre[Nombrelivre]);
                printf("auteur du livre: ");
                scanf("%s", auteur[Nombrelivre]);
                printf("prix du livre: ");
                scanf("%d", &prix[Nombrelivre]);
                printf("quantite du livre: ");
                scanf("%d", &quantite[Nombrelivre]);
                Nombrelivre++;
            }
            else
            {
                printf("stock plien!");
            }
        }
        else if (Choix == 2)
        {
            for (int i = 0; i < Nombrelivre; i++)
            {
                printf("titre: %s, auteur: %s, prix: %d, quantite: %d\n", titre[i], auteur[i], prix[i], quantite[i]);
            }
        }
        else if (Choix == 3)
        {
            char titrerech[MAX_TITRE];
            int trouve = 0;
            printf("Titre du livre rechercher: ");
            scanf("%s", titrerech);
            for (int i = 0; i < Nombrelivre; i++)
            {
                int j = 0;
                while (titre[i][j] == titrerech[j] && titrerech[j] != '\0')
                {
                    j++;
                }
                if (titrerech[j] == '\0' && titre[i][j] == '\0')
                {
                    printf("Livre trouvé - Titre: %s, Auteur: %s, Prix: %d, Quantité: %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    trouve = 1;
                    break;
                }
            }
            if (!trouve)
            {
                printf("Livre non trouvé.\n");
            }
        }
        else if (Choix == 4)
        {
            char titrerech[MAX_TITRE];
            int nouvelleQnt;
            int trouve = 0;
            printf("Titre du livre à mettre à jour: ");
            scanf("%s", titrerech);
            for (int i = 0; i < Nombrelivre; i++)
            {
                int j = 0;
                while (titre[i][j] == titrerech[j] && titrerech[j] != '\0')
                {
                    j++;
                }
                if (titrerech[j] == '\0' && titre[i][j] == '\0')
                {
                    printf("Nouvelle Quantite");
                    scanf("%d", &nouvelleQnt);
                    quantite[i] = nouvelleQnt;
                    printf("Quantite Mise A Jour");
                    trouve = 1;
                    break;
                }
            }
            if (!trouve)
            {
                printf("Livre non trouvé.\n");
            }
        }
        else if (Choix == 5)
        {
            char titrerech[MAX_TITRE];
            int trouve = 0;
            printf("Titre du livre supprimer");
            scanf("%s", titrerech);
            for (int i = 0; i < Nombrelivre; i++)
            {
                int j = 0;
                while (titre[i][j] == titrerech[j] && titrerech[j] != '\0')
                {
                    j++;
                }
                if (titrerech[j] == '\0' && titre[i][j] == '\0')
                {
                    for (int k = i; k < Nombrelivre - 1; k++)
                    {
                        for (int b = 0; b < MAX_TITRE; b++)
                        {
                            titre[k][b] = titre[k + 1][b];
                            auteur[k][b] = auteur[k + 1][b];
                        }
                        prix[k] = prix[k + 1];
                        quantite[k] = quantite[k + 1];
                    }
                    Nombrelivre--;
                    printf("livre supprime\n");
                    trouve = 1;
                    break;
                }
            }
            if (!trouve)
            {
                printf("livre non trouve\n");
            }
        }
        else if (Choix == 6)
        {
            int total = 0;
            for (int i = 0; i < Nombrelivre; i++)
            {
                total = total + quantite[i];
            }
            printf("Total quantite des livres est: %d", total);
        }
        else
        {
            printf("Choix Non Valide!!\n");
        }
    } while (Choix != 6);

    return 0;
}
