
#include <stdio.h>
#include <stdlib.h>

int main()
{
    menu();
    return 0;
}

struct livre
{
    int id;
    char titre[50];
    char auteur[20];
    int prix;
    int quantite;
};
struct livre livre1[200];
int compteur = 0;
int ID;
int IDrecherche;
char TITRErecherche[50];
int IDdel;
int i, j;

// function pour ajouter un livre
void add_nouvelle_livre()
{
    printf("===============================AJOUTER UN LIVRE===============================");
    printf("\n entrer un identifiant unique :");
    scanf("%d", &livre1[compteur].id);
    printf("\n Entrer le titre de livre :");
    getchar();
    gets(livre1[compteur].titre);
    printf("\n Entrer l'auteur de ce livre : ");
    gets(livre1[compteur].auteur);
    printf("\n Entrer le prix de ce livre : ");
    scanf("%d", &livre1[compteur].prix);

    do
    {
        printf("\n Entrer la quantite de ce livre (minimum 1) : ");
        scanf("%d", &livre1[compteur].quantite);

        if (livre1[compteur].quantite < 1)
        {
            printf("Erreur : La quantite doit être au moins 1. Veuillez réessayer.\n");
        }
    }
    while (livre1[compteur].quantite < 1);    // Répéter tant que la quantité est inférieure à 1

    compteur++;
}

// function pour afficher les livres disponibles
void Affichage_livre_disponible()
{
    printf("===============================AFFICHAGE DES LIVRES DISPONIBLES===============================");
    printf("\n Voici les livres qui sont disponibles :\n");
    for (i = 0; i < compteur; i++)
    {
        printf("\n livre %d: \n id = %d \n titre = %s \n auteur = %s \n prix = %d \n quantitee = %d ", i + 1, livre1[i].id, livre1[i].titre, livre1[i].auteur, livre1[i].prix, livre1[i].quantite);
    }
}

// function pour chercher des livres par son titre
void recherche_livre_par_titre()
{
    printf("===============================RECHERCHER LIVRE PAR SON TITRE===============================");
    int found = 0;

    printf("\n Entrer le titre du livre que vous voulez : ");
    scanf("%s", &TITRErecherche);
    for (i = 0; i < compteur; i++)
    {
        if (strcasecmp(livre1[i].titre, TITRErecherche) == 0)
        {
            found = 1;
            printf("\n livre %d: \n id = %d \n titre = %s \n auteur = %s \n prix = %d \n quantite = %d ", i + 1, livre1[i].id, livre1[i].titre, livre1[i].auteur, livre1[i].prix, livre1[i].quantite);
        }
    }
    if (!found)
        printf("Ce livre avec le titre suivant : %s n'existe pas", TITRErecherche);
}

// function pour update la quantité d'un livre
void Modifier_quantite()
{
    printf("===============================MODIFICATION DE LA QUANTITE D'UN LIVRE===============================");
    int found = 0;
    printf("\n Entrer ID de le livre que vous voulez modifier leur quantité : \n");
    scanf("%d", &ID);

    for (i = 0; i < compteur; i++)
    {

        if (livre1[i].id == ID)
        {
            found = 1;
            do
            {
                printf("\n Entrer une nouvelle quantitée pour ce livre (minimum 1) : ");
                scanf("%d", &livre1[i].quantite);

                if (livre1[i].quantite < 1)
                {
                    printf("Erreur : La quantite doit être au moins 1. Veuillez réessayer.\n");
                }
            }
            while (livre1[i].quantite < 1);

            printf("la quantiteé du livre %s est modifier avec success",livre1[i].titre);
            break;
        }

    }
    if (!found)
    {
        printf("le livre avec ID %d n'existe pas ", ID);
    }
}
//function pour supprimer un livre
void Supprimer_livre()
{
    printf("===============================SUPPRIMER D'UN LIVRE===============================");
    int found = 0;
    printf("\n Entrer ID de le livre que vous voulez supprimer : ");
    scanf("%d",&IDdel);
    for(i=0; i<compteur; i++)
    {
        if(livre1[i].id == IDdel)
        {
            found = 1;
            for(int N=i;N<compteur;N++){
                livre1[N] = livre1[N+1];
            }
        }
        compteur--;
        printf("le livre de ID = %d est supprimer avec success.",IDdel);
        break;
    }
    if(!found)
    {
        printf("le livre avec ID = %d n'existe pas.",IDdel);
    }
}

//function pour afficher le nombre totale des livres
void Afficher_nombre_total()
{
    printf("===============================NOMBRE TOTAL DES LIVRES===============================");
    printf("\n le nombre totale des livres est :%d",compteur);
}

int menu()
{

    int choix;

    do
    {
        printf("\n===================================== GESTION DE de Stock =====================================\n");
        printf("choisissez un choix : \n 1.Ajouter un livre au stock :\n 2.Afficher tous les livres disponibles :\n 3.Rechercher un livre par son titre :\n 4.Modifier la quantitee dun livre: \n 5.Supprimer un livre du stock: \n 6.Afficher le nombre total de livres en stock :\n 7.quitter\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            add_nouvelle_livre();
            break;
        case 2:
            Affichage_livre_disponible();
            break;
        case 3:
            recherche_livre_par_titre();
            break;
        case 4:
            Modifier_quantite();
            break;
        case 5:
            Supprimer_livre();
            break;
        case 6:
            Afficher_nombre_total();
            break;
        }
    }
    while (choix != 7);
}
