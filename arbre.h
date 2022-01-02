#ifndef ARBRE_H_INCLUDED
#définir ARBRE_H_INCLUDED
/*
struct Noeud
{
    int valeur;
    struct Noeud* gauche ;
    struct Noeud* droit ;
}TNoeud;

creer un arbre vide
TArbre NouvelArbreVide( void);

Ajouter un noeud
param val valeur du noeud
void Ajouter( TArbre* arbre , int val );

Chercher un noeud dans l'arbre
param TArbre arbre dans lequel il faut chercher
param v valeur a chercher
int chercher(TArbre arbre,int v);

Afficher l'arbre
param TArbre arbre a affiché 
void AfficherValeur( TArbre arbre );

Calcule le nombre d'élément
param TArbre
int NombreElements( TArbre arbre );

Calculer la hauteur d'un arbre;
param TArbre 
int Hauteur( TArbre arbre );

Supprimer un élément
param TArbre 
param info valeur de l'élément a supprimer;
#endif  // ARBRE_H_INCLUDED
