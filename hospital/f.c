#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "h.h"


/************************************************PATIENT********************************/
patient *newpat(){
     int i,j; char q;
patient *pat=malloc(sizeof(patient));


     if(pat==NULL){
            exit(-1);
     }
          printf("\n\n***********patient*********\n");
          printf("donner le matricule:");
          scanf("%d",&pat->mat);
          printf("donner le nom:");
          scanf("%s",&pat->nom);
          printf("donner le prenom:");
          scanf("%s",&pat->prenom);
          printf("donner adresse:");
          scanf("%s",&pat->adresse);
          printf("donner l'age:");
          scanf("%d",&pat->age);
          printf("donner etat:");
          scanf("%s",&pat->etat);
          printf("nombre maladie:");
          scanf("%d",&j);

          if(j>0)
          {for(i=0;i<j;i++){
          printf("donnez la maladie N %d ",i+1);
          scanf("%s", &pat->maladie[i]);}
          }
          pat->p=InitialiserListeC();
          while (1){
            AjouterpatC(pat->p,newpatC());
            printf("quitter Q:");
            scanf(" %c",&q);
            if(q=='q')
            {break;}
            clrscr();
          }



return pat;

}


liste* Ajouterpat(liste *L, patient *p){

     element *e=malloc(sizeof(element));
     if(e==NULL){
            exit(-1);
       }
     e->data=*p;

    if(L==NULL){
    e->suivant=NULL;
    L->sommet=e;  }

    else{
     e->suivant=L->sommet;
     L->sommet=e;
      }

    return L;  }




liste *InitialiserListe(){
liste *L=malloc(sizeof(liste));
element *e=malloc(sizeof(element));
if(L==NULL || e==NULL){
        exit(-1);
}

e->data=*newpat();
e->suivant=NULL;
L->sommet=e;

return L;  }


void Afficherpat(patient p){
 int i=0;
       printf("\n\n***************** info patient******************\n");
         printf("Nom : %s \n", p.nom);
          printf("PRENOM: %s \n", p.prenom);
           printf("mat : %d \n", p.mat);
           printf("age : %d \n", p.age);
           printf("adresse : %s \n", p.adresse);
           printf("Etat : %s \n",p.etat);
           printf("maladies:");
           if(p.maladie[0]!=NULL)
           {for(i=0;i<3;i++){
            printf("%s\n",p.maladie[i]);
           }}
           AfficherlisteC(p.p);
            printf(" \n ***************** ****************************\n");
 }


patient Rechercherpat(liste *l,int matricule){
       element *courant=l->sommet;
        patient pat;

         while(courant!=NULL){
      if(courant->data.mat==matricule){
            pat=courant->data;
            Afficherpat(pat);}
            courant=courant->suivant;  }
            return pat; }



patient Modifierpat(liste *l,int matricule,int age,char n[15]){

char n1[]="guerie",n2[]="mort";
element *courant=l->sommet;
        patient pat;

         clrscr();
         while(courant!=NULL){
      if((courant->data.mat==matricule) && (courant->data.age==age) && (strcmp(courant->data.nom,n)==0) ){
            pat=courant->data;
            clrscr();
            Afficherpat(pat);
            clrscr();
printf("\n**********************************\n");
            printf("entrer nouvelle etat:");
            scanf("%s",&courant->data.etat);

            if(strcmp(courant->data.etat,n1)==0 || strcmp(courant->data.etat,n2)==0 )
            {
              Supprimerpat(l,courant->data.mat);
            }
            }
            courant=courant->suivant;  }
            return pat;


}


liste *Supprimerpat(liste *L,int mat){

      element *tmp,*tmp1;
      tmp=L->sommet;

      if(tmp!=NULL && tmp->data.mat==mat)
      {
         L->sommet=tmp->suivant;
         free(tmp);
         return L;
      }

       while(tmp!=NULL){

      if(tmp->data.mat==mat){

         tmp1->suivant=tmp->suivant;
         return L;

      }
      tmp1=tmp;
      tmp=tmp->suivant;


        }
        return L;

}


void Afficherliste(liste *l){
element *courant=l->sommet;

 if(l==NULL){
        exit(-1);
   }
   clrscr();
 while(courant!=NULL){


          printf("\n\n***********patient*********\n");
          printf("mat:");
          printf("%d",courant->data.mat);
          printf("\nnom:");
          printf("%s",courant->data.nom);
          printf("\nprenom:");
          printf("%s",courant->data.prenom);
          printf("\netat:");
          printf("%s",courant->data.etat);
          printf("\naffecter a:");
          printf("%s",courant->data.afect);
          printf("\n\n\n\n");

courant=courant->suivant;
  }
 printf("\n NULL \n");
  }







/********************************************************************************/
/*,***********************************************PATIENTCONTACT********************************/



listeC *InitialiserListeC(){
listeC *L=malloc(sizeof(listeC));
elementC *e=malloc(sizeof(elementC));
if(L==NULL || e==NULL){
        exit(-1);
}

e->data=*newpatC();
e->suivant=NULL;
L->sommet=e;
               return L;


}

patientC *newpatC(){

patientC *patC=malloc(sizeof(patientC));

if(patC==NULL){
            exit(-1);
     }

          printf("\n\n***********patientCONTACT*********\n");
          printf("donner le CIN:");
          scanf("%s",&patC->CIN);
          printf("donner le nom:");
          scanf("%s",&patC->nom);
          printf("donner le prenom:");
          scanf("%s",&patC->prenom);
          printf("donner adresse:");
          scanf("%s",&patC->adresse);
          printf("donner date debut:");
          scanf("%s",&patC->dateD);
          printf("donner date fin:");
          scanf("%s",&patC->dateF);
          printf("1:contamination introduite // 0:contamination locale:");
          scanf("%d",&patC->c);


return patC;

}

listeC *AjouterpatC(listeC *L,patientC *p){
elementC *e=malloc(sizeof(elementC));
     if(e==NULL){
            exit(-1);
       }
     e->data=*p;

    if(L==NULL){
    e->suivant=NULL;
    L->sommet=e;  }

    else{
     e->suivant=L->sommet;
     L->sommet=e;
      }

    return L;


}


patientC ModifierpatC(listeC *l,char n[20],char a[30]){

elementC *tmp=l->sommet;
patientC patC;
int i=0;
 if(l==NULL){
        exit(-1);
   }

 while(tmp!=NULL){
      if(strcmp(tmp->data.adresse,a)==0){
            patC=tmp->data;
            strcpy(tmp->data.afect,n);}


tmp=tmp->suivant;
  }
return patC;
}




void AfficherlisteC(listeC *l){
elementC *courant=l->sommet;
int i=0;
 if(l==NULL){
        exit(-1);
   }
 while(courant!=NULL){


          printf("\n\n***********patientCONTACT*********\n");
          printf("CIN:");
          printf("%s",courant->data.CIN);
          printf("\nnom:");
          printf("%s",courant->data.nom);
          printf("\nprenom:");
          printf("%s",courant->data.prenom);
          printf("\nadresse:");
          printf("%s",courant->data.adresse);
          printf("\ndate debut:");
          printf("%s",courant->data.dateD);
          printf("\ndate fin:");
          printf("%s",courant->data.dateF);
          printf("\naffecter a:");
          printf("%s",courant->data.afect);
          i=courant->data.c;
          if(i==1){
          printf("\ncontamination introduite");
          }
          else{printf("\ncontamination locale");
          }

courant=courant->suivant;
  }
 printf("\n NULL \n");
  }



/********************************************************************************/
/*,***********************************************HOPITAL********************************/



listeH *InitialiserListeH(){
listeH *L=malloc(sizeof(listeH));
elementH *e=malloc(sizeof(elementH));
if(L==NULL || e==NULL){
        exit(-1);
}

e->data=*newH();
e->suivant=NULL;
L->sommet=e;
               return L;


}

hopital *newH(){

hopital *H=malloc(sizeof(hopital));

if(H==NULL){
            exit(-1);
     }

          printf("\n\n***********hopital*********\n");
          printf("donner le nom:");
          scanf("%s",&H->nom);
          printf("donner l'adresse:");
          scanf("%s",&H->adresse);
          printf("donner nombre lit:");
          scanf("%d",&H->lit);
          printf("donner nombre salle:");
          scanf("%d",&H->salle);
          printf("donner nombre medcin:");
          scanf("%d",&H->med);



return H;

}

listeH *AjouterHOP(listeH *L,hopital *p){
elementH *e=malloc(sizeof(elementH));
     if(e==NULL){
            exit(-1);
       }
     e->data=*p;

    if(L==NULL){
    e->suivant=NULL;
    L->sommet=e;  }

    else{
     e->suivant=L->sommet;
     L->sommet=e;
      }

    return L;


}

void AfficherlisteH(listeH *l){
elementH *courant=l->sommet;
 if(l==NULL){
        exit(-1);
   }
 while(courant!=NULL){


          printf("\n\n***********Hopital*********\n");
          printf("Nom:");
          printf("%s",courant->data.nom);
          printf("\nAdresse:");
          printf("%s",courant->data.adresse);
          printf("\nnombre lit:");
          printf("%d",courant->data.lit);
          printf("\nnombre salle:");
          printf("%d",courant->data.salle);
          printf("\nnombre medcin:");
          printf("%d",courant->data.med);


courant=courant->suivant;
  }
 printf("\n NULL \n");
  }


hopital RechercherHOP(listeH *l,char n[15]){
       elementH *courant=l->sommet;
        hopital hop;
         while(courant!=NULL){
      if((strcmp(courant->data.nom,n)==0) ){
            hop=courant->data;
            AfficherHOP(hop);}
            courant=courant->suivant;  }
            return hop; }



hopital ModifierHOP (listeH *l,char n[15]){

elementH *courant=l->sommet;
        hopital hop;
         clrscr();
         while(courant!=NULL){
      if(strcmp(courant->data.nom,n)==0){
            hop=courant->data;
            clrscr();
            AfficherHOP(hop);
            clrscr();
printf("\n**********************************\n");
            printf("entrer nombre lit:");
            scanf("%d",&courant->data.lit);

            }
            courant=courant->suivant;  }
            return hop;


}


void AfficherHOP(hopital H){
 int i=0;
       printf("\n\n***************** info hopital******************\n");
         printf("Nom : %s \n", H.nom);
          printf("adresse: %s \n", H.adresse);
           printf("Nombre lit: %d \n", H.lit);
           printf("Nombre salle: %d \n", H.salle);
           printf("Nombre medcin : %d \n", H.med);
           printf(" \n ***************** ****************************\n");
 }



patient AffectHOP(liste *l,listeH *lh)
{elementH *tmpH;
element *tmp;
patient pat;
tmpH=lh->sommet;
tmp=l->sommet;


 if(l==NULL || lh==NULL){
        exit(-1);
   }

 while(tmpH!=NULL){

    if(tmpH->data.lit!=0){

      while(tmp!=NULL){
        if(strcmp(tmp->data.adresse,tmpH->data.adresse)==0){
            pat=tmp->data;
            strcpy(tmp->data.afect,tmpH->data.nom);}



          tmp=tmp->suivant;
        }

      }
       tmpH=tmpH->suivant;
    }


return pat;
}

/******************************HOTEL**********************/
/******************************HOTEL**********************/



listeHOT *InitialiserListeHOT(){
listeHOT *L=malloc(sizeof(listeHOT));
elementHOT *e=malloc(sizeof(elementHOT));
if(L==NULL || e==NULL){
        exit(-1);
}

e->data=*newHOT();
e->suivant=NULL;
L->sommet=e;
               return L;


}

hotel *newHOT(){

hotel *H=malloc(sizeof(hotel));

if(H==NULL){
            exit(-1);
     }

          printf("\n\n***********hotel*********\n");
          printf("donner le nom:");
          scanf("%s",&H->nom);
          printf("donner l'adresse:");
          scanf("%s",&H->adresse);
          printf("donner la capacite:");
          scanf("%d",&H->capacite);




return H;

}

listeHOT *AjouterHOT(listeHOT *L,hotel *p){
elementHOT *e=malloc(sizeof(elementHOT));
     if(e==NULL){
            exit(-1);
       }
     e->data=*p;

    if(L==NULL){
    e->suivant=NULL;
    L->sommet=e;  }

    else{
     e->suivant=L->sommet;
     L->sommet=e;
      }

    return L;


}

void AfficherlisteHOT(listeHOT *l){
elementHOT *courant=l->sommet;
 if(l==NULL){
        exit(-1);
   }
 while(courant!=NULL){


          printf("\n\n***********Hotel*********\n");
          printf("Nom:");
          printf("%s",courant->data.nom);
          printf("\nAdresse:");
          printf("%s",courant->data.adresse);
          printf("\ncapacité:");
          printf("%d",courant->data.capacite);


courant=courant->suivant;
  }
 printf("\n NULL \n");
  }


hotel RechercherHOT(listeHOT *l,char n[15]){
       elementHOT *courant=l->sommet;
        hotel hot;
         while(courant!=NULL){
      if((strcmp(courant->data.nom,n)==0) ){
            hot=courant->data;
            AfficherHOT(hot);}
            courant=courant->suivant;  }
            return hot; }



void AfficherHOT (hotel H){

       printf("\n\n***************** info hotel******************\n");
         printf("Nom : %s \n", H.nom);
          printf("adresse: %s \n", H.adresse);
           printf("Nombre lit: %d \n", H.capacite);
           printf(" \n ***************** ****************************\n");
 }



void AffectHOT(listeHOT *lh)
{int i=2;
elementHOT *tmpH;
tmpH=lh->sommet;



if(lh==NULL){
        exit(-1);
   }

printf("\n***************\n");
while(tmpH!=NULL){

while(i<pp->i)
 {ModifierpatC(pp[i-2].p,tmpH->data.nom,tmpH->data.adresse);

 i++;
 }



tmpH=tmpH->suivant;
}



 }























/***********************************************************/
/***********************************************************/
listeC *stokC(liste *p){

element *courant=p->sommet;
pp=(elementPC*)malloc(2*sizeof(elementPC));
pp->i=2;

 if(p==NULL || pp==NULL){
        exit(-1);
   }

 while(courant!=NULL){

   pp[pp->i-2].p=courant->data.p;

pp->i=pp->i+1;
pp=(elementPC*)realloc(pp,pp->i*sizeof(elementPC));
courant=courant->suivant;
  }
 printf("\n NULL \n");

}


void AfficherPC()
{int i=0;

do{

  AfficherlisteC(pp[i].p);

i=i+1;
}while(i<=pp->i);

}






