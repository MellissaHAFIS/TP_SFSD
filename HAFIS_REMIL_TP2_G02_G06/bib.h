

#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "conio.h"
#include "interface.h"
#define b  1024 //nombre maximal d'enregistrements dans le bloc
#define b1 100   //nombre maximal d'enregistrements dans le bloc du fichier inndex1
#define m 113  //le nombre maximal d'enregistrements dans les bloc des fichiers TOF utilises
#define m1 73  //le nombre maximal d'enregistrements dans les bloc des fichiers TOF utilises
#define nb_etab 112//nombre d'etablissements
#define long_np 64 //longueur maximale  du nom et prenom  et autres
#define long_wilaya 21 //longueur max d'une wilaya
#define long_max 128 //longueure maximale des chaines

/********************************** LES STRUCTURES DE DONNEES **************************************/
//structure d'une date
typedef struct Tdate  Tdate;
struct Tdate{
int Annee;
int Mois;
int Jour;
};
//structure de l'enregistrement du fichier  contenant les 12 champs
typedef struct Tenreg Tenreg;
struct Tenreg{
   int  Matricule;
   char  Nom[long_np];
   char  Prenom[long_np];
   Tdate Date_Naissance;
  char Wilaya_Naissance[long_wilaya];
  int Sexe;
  char Groupe_Sanguin[4];
  Tdate Date_Recrutement;
  char Grade[long_np];
  char Specialite[long_np];
  char Dernier_Diplome[long_np];
  char Etablissement_Univ[long_max];

};
//structure du bloc du fichier
typedef struct Tbloc Tbloc;
struct Tbloc {
   Tenreg t[b];//tableau de taille max = b d'enreg de type Tenreg
   int nb;//nombre d'enreg existants dans le bloc
   int suiv;//numero du bloc suivant (-1 pour nil)
   int prec;//numero du bloc precedent (-1 pour nil)

   };
//structure de l'entete du fichier
typedef struct TEntete TEntete;
struct TEntete{

int  Tete;//1-la tete du fichier (num du bloc representant la tete)
int Queue;//2-la queue du fichier (num du bloc representant la queue)
int nbe;//3-nombre d'enregistrements total dans le fichier
int nbbloc;//4-nombre de blocs dans le fichier
char  cle[30];//la cle de codage/decodage
};
//la structure du fichier
typedef struct FLNOF FLNOF;
struct FLNOF{
FILE *fich;
TEntete entete;
  };
/************************** LES STRUCTURES D'INDEX **************************************************************************/
//-la structure de l'adresse
typedef struct Tadr Tadr;
struct  Tadr{
     int numb;//le numero de bloc
     int dep;//le deplacement dans le bloc
     };
//-la structure de l'entete des fichiers d'index de structure TOF
typedef struct TEnteteInd TEnteteInd;
struct TEnteteInd {
int nbBloc;//nombre de bloc dans le fichier
int nbcouples;//nombre de couples(enreg) inseres
int nbcouplesSupp;//nombre  de couples supprimes logiquement;---------->>>>>>> a voir!
};
//la structure du fichier TOF pour le fichier d'index
//le fichier est ordonne=> recherche dichotomique, insertion avec decalages, suppression logique
typedef struct  FICHTOF FICHTOF;
struct FICHTOF{
    FILE *fich;
    TEnteteInd entete;
};
/** les structures de la liste utilisee en MC (creation de la table d'index selon une cle a valeurs multiples)**/
typedef struct maillon *maillon;//cette structuresera utilisee pour index2 et index3
struct maillon{
 int mat;
 maillon suivant;
 };
typedef struct  Tcouple_tabInd3 Tcouple_tabInd3;//structure dans la table d'index en MC
struct  Tcouple_tabInd3{
int code_etab;//le numero representant d'un etablissement
maillon tete;//la tete de liste des adresses de la cle (qui est dans le champ code_etab) "elle peut etre nil"
 };
/*(1)- Selon le maticule: les structures du fichier index1  ((fichier d'index dense sur le matricule(cle) avec acces TOF))*/
typedef struct Tcouple Tcouple;
  struct Tcouple{
      int cle;//c'ets le matricule de chaque enregistrement du fichier
      Tadr adresse;
      bool supp;//0(faux) => non supprime , 1(vrai)=> supprime
  };

 typedef struct TblocInd1 TblocInd1;
 struct TblocInd1{
      Tcouple Tabcouples[b1];//tableau de couple (cle,adresse)
      int nbcouples;//nbe
  };
  /*(2)- Selon la specialite */
  typedef struct Tcouples2 Tcouples2;
struct Tcouples2{
 int Code_spe;
 maillon tete;
};

typedef struct Tenreg_index2 Tenreg_index2;
struct Tenreg_index2{
int  Code_Specialite;
int tete;//le bloc de la specialité dans le fichier index2
int nb_adr;
bool supp;//pour la suppression logique
};
typedef struct  Tbloc1_index2 Tbloc1_index2;
struct Tbloc1_index2{
Tenreg_index2 tab1[m1];
int nbe;// le nombre d'enregisrement dans chaque bloc
};

typedef struct Tcouple3 Tcouple3;
struct Tcouple3{//comme maillon
int mat;
bool efface;
};
typedef struct Tbloc2_index2 Tbloc2_index2;
struct Tbloc2_index2{
Tcouple3 tab2[b];
int nbe;
int suiv;
};

/*(3)- Selon l'etablissement univ: les structures du fichier index2 ((fichier d'index dense a valeurs multiples avec acces TOF et LnOF))*/
//le fichier index3 est compose de 2 parties
//car la cle=code de l'etablissemnt univ est a valeur multiple donc pour chaque cle il y a une liste d'adresse
//1ere: un fichier organise en TOF d'enreg (code de l'etablissemnt univ , tete de liste des adresses)
//2eme: un fichier organise en LnOF d'enref(num du bloc,deplacement)=Tadr
// Structure de l'index des Etablissements
typedef struct Tenreg_index3 Tenreg_index3;
struct Tenreg_index3{
int Code_Etab_Univ;
int tete;// le bloc a partir duquel commence les couples dans le fichier index3LNOF(tete de liste )
int nb_adr;//nombre d'adresse (d'enreg) qui ont cette cle code_etab=nombre de maillons
bool supp;//booleen qui indique que un etablissement est totalement supprime (logiquement )
};
typedef struct Tdonnee Tdonnee;
struct Tdonnee{
int mat;
bool efface; //pour l'effacement d'un senreg
};

//la structure du bloc dans la 1ere partie du fichier index3
typedef struct  Tbloc1_index3 Tbloc1_index3;
struct Tbloc1_index3{
Tenreg_index3 tab1[m];
int nbe;// le nombre d'enregisrement dans chaque bloc
};
//la  structure du bloc dans la 2eme partie du fichier index3
typedef struct Tbloc2_index3 Tbloc2_index3;
struct Tbloc2_index3{
Tdonnee tab2[b];//tableau des adresses d'une cle donnee formant la liste des adresse de la cle
int nbe;//nombre d'enregistrements=nb_adr
int suiv;//le numero du prochain bloc
};


/************************************** la machine Abstraite sur les listes ****************************/
void Allouer (maillon *pointeur);
void Aff_val(maillon *pt_m,int v);
void Aff_adr( maillon *p,maillon q );
maillon Suivant(maillon pointeur);
int Valeur(maillon pointeur);
void Liberer(maillon pointeur);
/************************************** la machine Abstraite LnOF****************************************/
void Ouvrir(FLNOF *f,char *nomf,char mode);
void Fermer (FLNOF f);
void Aff_Entete(FLNOF *f,int i,int v);
int Entete(FLNOF f,int i);
void EcrireDir(FLNOF *f,int i,Tbloc buf);
void LireDire(FLNOF f,int i, Tbloc *buf);
int AllocBloc(FLNOF f);
void Entete_cle(FLNOF f,char *cle);
void Aff_Entete_cle(FLNOF *f,char *cle);

/************************************** la machine Abstraite TOF****************************************/
void Ouvriretof(FICHTOF *F,char *nomf,char mode);
void fermertof(FICHTOF F);
void EcrireDirtof(FICHTOF *F,int i,TblocInd1 buf);
void LireDirtof(FICHTOF F,int i,TblocInd1 *buf);
int Entetetof( FICHTOF F , int i );
void Aff_entetetof(FICHTOF *F , int i , int v);
/************************************* LES FONCTIONS de CHARGEMENT *********************************/
int Alea(int inf,int sup);
int Mat_Alea();
void NomPrenom_Alea(char* name);
bool an_bissextile(int annee);
Tdate Genrer_Date(int choix);
void Alea_Wilaya_Nais(char *lib);
int Sexe();
void Groupe_Sang(char* group_s);
void Generer_Grade(char* grade);
void Specialite(char* filiere);
void Generer_Etab(char *etab);
void Chargement_Init(int n,Tcouple *tab1,Tcouples2 *tab2,Tcouple_tabInd3 *tab3,int *nbre_liredire,int *nbre_ecriredire);


/********************** affichage initiales*************************************************************/
void Affichage_Initial(FLNOF f,char *nom_fichier,int *nbre_liredire,int *nbre_ecriredire);
/*********************** autres modules ****************************************************************/
void Rech_tab1(int valeur, Tcouple *tab, int taille, bool *trouv, int *k);
void Insertab1(Tcouple *tab,int taille,int pos,Tcouple e);

void Ecraser_mat(FLNOF *f,Tadr adresse,int *mat_ecrasant,int *nbre_liredire,int *nbre_ecriredire);
int Recuperer_code_Specialite(char *Specialite);
 int Recuperer_code_etab(char *etab);
 /***************** module de supprimer un enreg donne par le matricule ****************************/
void RemplirTab1(FICHTOF f,Tcouple *tab1,int taille,int *nbre_lireindex1,int *nbre_ecrireindex1);
void RemplirTab2(FICHTOF f21,FLNOF f22,Tcouples2 *tab2,int *nbre_lireindex2,int *nbre_ecrireindex2);
void RemplirTab3(FICHTOF f31,FLNOF f32,Tcouple_tabInd3 *tab3,int *nbre_lireindex3,int *nbre_ecrireindex3);

void Supp_mat(FLNOF *f,int mat,Tcouple *tab1,int *taille,int *nbre_liredire,int *nbre_ecriredire);
void SuppDecal(Tcouple *tab1,int *taille,int position,int mat);
/******************* module de suppresion d'une specialite ****************************************/
void retourner_specialite(char *spec,int code_spe);


/********************************** Fonctions sur le fichier index1 **********************************/
// 1-module de recherche dans le fichier d'index1 (cle de recherche=le matricule)
void RechInd1_mat(FICHTOF f,int c,bool *trouve,int *i,int *j);
// 2-module de chargement (creation) du fichier d'index1 a partir de la table d'index
void Charger_index1(FICHTOF *f,int n,Tcouple *tab,int *nbre_lireindex1,int *nbre_ecrireindex1);

// 3-module d'affichage de l'index 1
void Afficher_Index1(FICHTOF f,int *nbre_lireindex1,int *nbre_ecrireindex1);
/********************************** focntion sur le fichier index 2*************************************/
void EcrireDir_Ind2(FLNOF *f,int i,Tbloc2_index2 buf);
void LireDire_Ind2(FLNOF f,int i, Tbloc2_index2 *buf);
void EcrireDirtof_Ind2(FICHTOF *F,int i,Tbloc1_index2 buf);
void LireDirtof_Ind2(FICHTOF F,int i,Tbloc1_index2 *buf);
void charger_index2_specialite(FICHTOF* f1,Tcouples2 *tabIndex2,FLNOF* f2,int *nbre_lireindex2,int *nbre_ecrireindex2);
/********************************** Fonctions sur le fichier index3 **********************************/
void EcrireDir_Ind3(FLNOF *f,int i,Tbloc2_index3 buf);
void LireDire_Ind3(FLNOF f,int i, Tbloc2_index3 *buf);
void LireDirtof_Ind3(FICHTOF F,int i,Tbloc1_index3 *buf);
void EcrireDirtof_Ind3(FICHTOF *F,int i,Tbloc1_index3 buf);
void Charger_index3(FICHTOF *f31,FLNOF *f32,Tcouple_tabInd3 *tab,int *nbre_lireindex3,int *nbre_ecrireindex3);
void Afficher_Index3(FICHTOF f31,FLNOF f32,int *nbre_lireindex3,int *nbre_ecrireindex3);
// 2-module de chargement (creation) du fichier d'index2 a partir de sa table d'index
void Liberer_tab3(Tcouple_tabInd3 *tab3);
void Liberer_tab2(Tcouples2 *tab2);
void Consultation_region(Tcouple_tabInd3 *tabInd3 ,Tcouple *tab,int n,int *nbre_liredire,int *nbre_ecriredire);
void affichage_anciennete(int anciennete_inf,int anciennete_sup,char* etab,Tcouple_tabInd3 *tabInd3,Tcouple *tab,int n,int *nbre_liredire,int *nbre_ecriredire);

void retourner_wilaya(char *wilaya,int code_wilaya);
void retourner_groupsang(char *sang,int code_sang);
void retourner_grade(char *grade,int code_grade);
void retourner_diplome(char *dernier_diplome,int code_diplome);
bool control_date(int jour,int mois,int annee,int choix);
bool controle_grade(char *grade,int date_naissance);
void date_sys(int *day,int *month,int *year);

void Coder_fichier_bin(FLNOF f,FLNOF *fc,char *cle,int *nbre_liredire,int *nbre_ecriredire);

void Coder_Enreg(Tenreg *e,unsigned char *cle);
void codage(  unsigned char ligne[], unsigned char mot[]);
void decodage( signed char ligne[], signed char mot[]);
void Decoder_Enreg(Tenreg *e,unsigned char *cle);
void Ajout_Enseignant(Tcouple *tab1,int *n,Tcouples2 *tab2,Tcouple_tabInd3 *tab3,int *matri,int *nbre_liredire,int *nbre_ecriredire,bool *trouve);

void Modifer_etab(FLNOF *f,int mat,int code_etab,Tcouple *tab1,Tcouple_tabInd3 *tab3,int *nbre_liredire,int *nbre_ecriredire);
void Supp_specialite(FLNOF *f,int code,Tcouples2 *tab2,Tcouple *tab1,int *taille,int *nbre_liredire,int *nbre_ecriredire);

void Etablissement(char *etab,int code_etab);
void Decoder_fichier_bin(FLNOF f,FLNOF *fc,int *nbre_liredire,int *nbre_ecriredire);

void afficher_entete(FLNOF f);
void afficher_enreg(FLNOF f,int mat,Tcouple *tab,int tai,int *nbre_liredire,int *nbre_ecriredire);

void afficher_bloc(FLNOF f,int i,int *nbre_liredire,int *nbre_ecriredire);
void afficherE(Tenreg e,int j);
void afficher3B(FLNOF f);

#endif // BIB_H_INCLUDED
