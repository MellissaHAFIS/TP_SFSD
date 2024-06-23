

#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#define tmax 50
#define selected_color 4
#define selected_background 11
#define not_selected_color  0
#define not_selected_background 15
#define MAX_CHOIX 5
#define NB_CHOIX_PAR_LIGNE 3
#define DIMENSION_HAUT 9
#define DIMENSION_LARG 21
#define GAUCHE 75
#define HAUT 72
#define DROITE 77
#define BAS 80

/****************************************** FONCTIONS D'AFFICHAGE*****************************************/
void fenetre();
void Ouverture();
void home();

/*************************************************************************************************************/
void bleu();
void vert();
void noire();
void jaunet();
void noiret();
void bleut();
void rouget();
void menu_principal();
int menu2(int max,...);
void returnToMenu();
void creation_fichier();
void fichier_mesres();
void cdg();
void dcdg();
void fin();
void Ouverture2();
int ouinon();
int spes();
int reg();
void affb();
int reseau();
int typetab();
int willaya();
int abo();
int grad();
int dernier_dip();
int sex();


void ent();
void newprof();
void  transfert();
 void supm();
 void sups();
 void reseauest();
 void reseaucentre();
 void reseauouest();
void  requette();
void esg();

#endif // INTERFACE_H_INCLUDED
