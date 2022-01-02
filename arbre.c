#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

struct Noeud
{
    int valeur;
    struct Noeud* gauche ;
    struct Noeud* droit ;
}TNoeud;


typedef struct Noeud* TArbre;


TArbre NouvelArbreVide( void )
{
    return NULL;
}



void Ajouter( TArbre* arbre , int val )
{
    if( *arbre == NULL )
    {
        *arbre = ( TArbre )malloc( sizeof( TNoeud ) );
        (*arbre)->valeur = val ;
        (*arbre)->gauche = NULL ;
        (*arbre)->droit = NULL ;
    }
    else
    {
        if( val < (*arbre)->valeur )
        {
                Ajouter( &(*arbre)->gauche , val ) ;
        }
        else
        {
                Ajouter( &(*arbre)->droit , val ) ;
        }
    }
}


int chercher(TArbre arbre,int v)
 {
    int trouve=false;

        while(arbre&&!trouve)
        {
            if(arbre->valeur==v)
                trouve=true;
            else
            {

                if(v<arbre->valeur)
                    arbre=arbre->gauche;
                else
                    arbre=arbre->droit;

            }

        }

    return trouve;

}

void AfficherValeur( TArbre arbre )
{
    if( arbre != NULL )
    {
        printf( "%d--" , arbre->valeur ) ;
        AfficherValeur( arbre->gauche ) ;
        AfficherValeur( arbre->droit ) ;
    }

}



int NombreElements( TArbre arbre )
{
    if( arbre == NULL )
    {
        return (0) ;
    }
    else
    {
        return( 1 + NombreElements( arbre->gauche ) + NombreElements( arbre->droit ) ) ;
    }
}


int Hauteur( TArbre arbre )
{
    int hg=0,hd=0,h=0 ;
    if( arbre == NULL )
         h=0;
    else
    {
        hg = Hauteur( arbre->gauche ) ;
        hd = Hauteur( arbre->droit ) ;

           h=(hg>hd?hg:hd)+1;
    }
    return h;
}



int SupElement(TArbre* arbre, int info)
{


    TArbre temp=NULL;
    TArbre temp2=NULL;
    int infotemp=0;
    int ElementSupprime=false;

    if(*arbre == NULL)
            ElementSupprime=false;
        else
        {
            if((*arbre)->valeur<info)
                ElementSupprime=SupElement(&(*arbre)->droit,info);

            else if((*arbre)->valeur>info)
                ElementSupprime=SupElement(&(*arbre)->gauche,info);

            else
            {
                ElementSupprime=true;
                if((*arbre)->gauche==NULL)
                {
                    temp=*arbre;
                    (*arbre)=(*arbre)->droit;
                    free(temp);
                }
                else
                {
                    if((*arbre)->droit==NULL)
                    {
                        temp=*arbre;
                        (*arbre)=(*arbre)->gauche;
                        free(temp);
                    }
                    else
                    {

                        temp=(*arbre);

                        temp=temp->droit;
                        while(temp->gauche)
                        {
                            temp2=temp;
                            temp=temp->gauche;

                        }

                        infotemp=temp->valeur;
                        if(temp->droit)
                        {
                            temp2->gauche=temp->droit;
                            free(temp);
                        }

                        (*arbre)->valeur=infotemp;
                        ElementSupprime=true;

                    }
                }


            }


        }

    return ElementSupprime;


}
