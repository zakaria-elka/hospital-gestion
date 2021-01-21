#include <stdio.h>
#include <stdlib.h>
#include "f.c"



int main(){
int i=0,j=0,mat,age; char q,q1,q3,q4,n[20];
liste *l; listeH *lh; listeHOT *lhot;
textcolor(4);
cprintf("bonjour tout d'abord il faut inialiser les principal liste:");
l=InitialiserListe();
clrscr();
lh=InitialiserListeH();
clrscr();
lhot=InitialiserListeHOT();
clrscr();
while(1){
clrscr();
textcolor(2);
cprintf("****************************MENU**************************\n");
printf("\n\t\t\t1: gerer patient");
printf("\n\n\t\t\t2: personne confine");
printf("\n\n\t\t\t3: gerer hopital");
printf("\n\n\t\t\t4: gerer hotel\n\n");
textcolor(2);
cprintf("\n\n\n********************************************************\n\n");
printf("\n\n***************VOTRE CHOIX:*******************\nchoix:");
scanf("%d",&i);



/********************************************************************************/
/********************************************************************************/
if(i==1)
{clrscr();
printf("\n\t\t\t1:Ajouter");
printf("\n\n\t\t\t2 RECHERCHER");
printf("\n\n\t\t\t3: MODIFIER");
printf("\n\n\t\t\t4: AFFICHER LES PATIENTS\n\n");
printf("choix:");
scanf("%d",&j);
if(j==1){
while(1)
{
clrscr();
Ajouterpat(l,newpat());
cprintf("quitte Q:");
scanf(" %c",&q1);
if(q1=='q')
{break;}
}

}

if(j==2){clrscr();
printf("mat:");
scanf("%d",&mat);
Rechercherpat(l,mat);
}


if(j==3){clrscr();
printf("mat:");
scanf("%d",&mat);
printf("age:");
scanf("%d",&age);
printf("nom:");
scanf("%s",&n);
stokC(l);
Modifierpat(l,mat,age,n);
}

if(j==4){clrscr();
AffectHOP(l,lh);
Afficherliste(l);
}



}

/********************************************************************************/
/********************************************************************************/

if(i==2)
{clrscr();
stokC(l);
printf("\n\n\t\t\tAFFICHAGE LES PERONNES confine\n\n");
AffectHOT(lhot);
AfficherPC();

}

/********************************************************************************/
/********************************************************************************/
if(i==3)
{clrscr();
printf("\n\t\t\t1:Ajouter");
printf("\n\n\t\t\t2 RECHERCHER");
printf("\n\n\t\t\t3: MODIFIER");
printf("\n\n\t\t\t4: AFFICHER LES hopital\n\n");
printf("choix:");
scanf("%d",&j);
if(j==1){
while(1)
{
clrscr();
AjouterHOP(lh,newH());
cprintf("quitte Q:");
scanf(" %c",&q3);
if(q3=='q')
{break;}
}

}

if(j==2){clrscr();
printf("mat:");
scanf("%d",&n);
RechercherHOP(lh,n);
}


if(j==3){
clrscr();
printf("nom:");
scanf("%s",&n);
ModifierHOP(lh,n);
}

if(j==4){clrscr();
AfficherlisteH(lh);
}



}


/********************************************************************************/
/********************************************************************************/
if(i==4)
{clrscr();
printf("\n\t\t\t1:Ajouter");
printf("\n\n\t\t\t2 RECHERCHER");
printf("\n\n\t\t\t3: AFFICHER LES hotels\n\n");
printf("choix:");
scanf("%d",&j);
clrscr();
if(j==1){
while(1)
{

AjouterHOT(lhot,newHOT());
cprintf("quitte Q:");
scanf(" %c",&q4);
if(q4=='q')
{clrscr();
    break;}
}

}

if(j==2)
    {clrscr();
printf("mat:");
scanf("%d",&n);
clrscr();
RechercherHOT(lhot,n);

}


if(j==3){
clrscr();
AfficherlisteHOT(lhot);

}



}





/********************************************************************************/
/********************************************************************************/
textcolor(4);
cprintf("quitte Q:");
scanf(" %c",&q);
if(q=='q')
{break;}


}



























return 0;


}
