
#define H_H_INCLUDED

/************************************************PATIENT********************************/
/************************************************PATIENT********************************/
typedef struct{

char nom[20];
char prenom[20];
char adresse[30];
int age,mat;
char maladie[3][10];
char etat[8];
char afect[20];
struct listeC *p;

}patient;



typedef struct
{
patient data;
struct element *suivant;

}element;


typedef struct{
     element *sommet;

}liste;

/************************************************PATIENTCCC********************************/
/************************************************PATIENTCCC********************************/

typedef struct{

char nom[20];
char prenom[20];
char CIN[10];
char dateD[10];
char dateF[10];
int  c;
char adresse[30];
char afect[20];

}patientC;



typedef struct
{
patientC data;
struct elementC *suivant;

}elementC;


typedef struct{
     elementC *sommet;

}listeC;



/************************************************HOPITAL********************************/
/************************************************HOPITAL********************************/


typedef struct{

char nom[20];
char adresse[30];
int lit;
int salle;
int med;


}hopital;



typedef struct
{
hopital data;
struct elementH *suivant;

}elementH;


typedef struct{
     elementH *sommet;

}listeH;


/****************************************************************/
typedef struct
{
struct listeC *p;
    int i;
}elementPC;
elementPC *pp;
/***********************************HOTEL******************************************/
/***********************************HOTEL******************************************/

typedef struct{

char nom[20];
char adresse[30];
int capacite;



}hotel;



typedef struct
{
hotel data;
struct elementHOT *suivant;

}elementHOT;


typedef struct{
     elementHOT *sommet;

}listeHOT;







/************************************************HOPITAl********************************/
/************************************************HOPITAL********************************/

listeH *InitialiserListeH();
hopital *newH();
listeH *AjouterHOP(listeH *L, hopital *p);
void AfficherHOP(hopital H);
hopital RechercherHOP(listeH *l,char n[15]);
hopital ModifierHOP  (listeH *l,char n[15]);
patient AffectHOP(liste *l,listeH *lh);






/************************************************PATIENT********************************/
/************************************************PATIENT********************************/

liste *InitialiserListe();
patient *newpat();
liste *Ajouterpat(liste *L, patient *p);
patient Rechercherpat(liste *l,int matricule);
patient Modifierpat(liste *l,int matricule,int age,char n[15]);
void Afficherpat(patient p);
liste *Supprimerpat(liste *L,int mat);
void Afficherliste(liste *l);

/************************************************PATIENTCCCC********************************/
/************************************************PATIENTCCCC********************************/

listeC *InitialiserListeC();
patientC *newpatC();
listeC  *AjouterpatC(listeC *L, patientC *p);
void AfficherlisteC(listeC *l);
patientC ModifierpatC(listeC *l,char n[20],char a[30]);

/*********************************/
listeC *stokC(liste *p);
void AfficherPC();

/************************************HOTEL***********************/
/************************************HOTEL***********************/


listeHOT *InitialiserListeHOT();
hotel *newHOT();
listeHOT *AjouterHOT(listeHOT *L,hotel *p);
void AfficherlisteHOT(listeHOT *l);
hotel RechercherHOT(listeHOT *l,char n[15]);
void AfficherHOT (hotel H);
void AffectHOT(listeHOT *lh);


#endif // H_H_INCLUDED
