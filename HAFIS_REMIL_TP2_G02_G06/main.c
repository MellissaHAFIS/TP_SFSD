
#include "bib.h"
int main()
{

char nom_fichier[32];
strcpy(nom_fichier,"ENSEIGNANT-MESRS.bin");
char nom_fichiercode[32];
strcpy(nom_fichiercode,"ENSEIGNANT-MESRS_code.bin");
char nom_fichierdecode[32];
strcpy(nom_fichierdecode,"ENSEIGNANT-MESRS_decode.bin");


FLNOF f,fcode,fdecode;
char nom_fichier_ind1[32]="fichier_indexe1.bin";
FICHTOF findex1;


char nom_fichier_ind3_1[32]="fichier_indexe3_1.bin";
FICHTOF findex31;
char nom_fichier_ind3_2[32]="fichier_indexe3_2.bin";
FLNOF findex32;

char nom_fichier_ind2_1[32]="fichier_indexe2_1.bin";
FICHTOF findex21;
char nom_fichier_ind2_2[32]="fichier_indexe2_2.bin";
FLNOF findex22;
//table d'index pour l'index1
Tcouple *tabind1=malloc(150000*sizeof(Tcouple));

//table d'index pour l'index2
Tcouples2 *tabIndex2=malloc(72*sizeof(Tcouples2));
//table d'index pour l'index3
Tcouple_tabInd3 *tabInd3=malloc(nb_etab*sizeof(Tcouple_tabInd3));
char decision[1];
char continuer[1];
char key[30];
bool trouve=false;
int x,a,n,i,z,l,stop;
Tcouples2 cp2;
int nbre_liredire=0,nbre_ecriredire=0,nbre_lireindex1=0,nbre_ecrireindex1=0,nbre_lireindex2=0,nbre_ecrireindex2=0,nbre_lireindex3=0,nbre_ecrireindex3=0;

/******************/
int arreter=1;
int reponse;
int choix,choix2;
   int y=50;

//initialisation de la table d'index 2

 for (x=0;x<72;x++){
        cp2.Code_spe=x+1;
        cp2.tete=NULL;
        *(tabIndex2+x)=cp2;
}

//initialisation de la table d'index3 ->> ordonnee suivant les codes des etablissements car c'est la cle de l'index 3 <<--
for(a=1;a<=nb_etab;a++){
  (*(tabInd3+(a-1))).code_etab=a;
  (*(tabInd3+(a-1))).tete=NULL;
}

//__________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________


textbackground(WHITE);
textcolor(BLACK);

home();
printf("\n\n");

    textcolor(BLACK);
    printf("                                                               APPUYER SUR ENTER POUR COMMENCER ");
    getchar() ;
    system("cls");

//__________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________


Ouverture2();

 textcolor(BLACK);
    printf("                                                 APPUYER SUR ENTER POUR COMMENCER ");
    getchar() ;
    system("cls");

textcolor(BLACK);
while(arreter!=0){
clrscr();
menu_principal();
textbackground(WHITE);
            printf("\n\n");
            textcolor(15);
            textcolor(BLUE);
            printf("\t                         -->  Veuillez faire un choix dans le menu suivant  <--                \n\n") ;
            printf("\n\n\n");

            textbackground(WHITE);
            textcolor(BLACK);
            printf("\t|=======================================================================================================|\n");textcolor(BLACK);
            printf("\t|");textcolor(BLUE);
            printf("\t                                Menu                                                            ");textcolor(BLACK);
            printf("|\n");
            textcolor(BLACK);
            printf("\t|=======================================================================================================|\n");

          choix=menu2(8,"\t|choix 1  : Chargement initiale du fichier ENSEIGNANT-MESRS.bin                                         |",
                        "\t|choix 2  : Ajout d'un nouvel enseignant                                                                |",
                        "\t|choix 3  : Modification de l'etablissement universitaire d'un enseignant en raison de sa mutation      |",
                        "\t|choix 4  : Suppression d'un enregistrement donne par le matricule                                      | ",
                        "\t|choix 5  : Suppression de tous les enregistrements relatifs a une specialite donnee                    |",
                        "\t|choix 6  : Codage et encodage du fichier ENSEIGNANT-MESRS.bin                                          |",
                        "\t|choix 7  : Affichage et options                                                                        |",
                        "\t|choix 0  : Quitter                                                                                     |");
                        textcolor(BLACK);


//------------------------------------------------------------------
printf("\n\n\n\n\n\n\n\n\n\n\n\n");
if(choix==8){


          arreter= 0 ;
            printf("\n\n\n\n");
            fin();

            printf("\n\n\n\n");

}



if(choix==1){

clrscr();
creation_fichier();
Ouvriretof(&findex31,nom_fichier_ind3_1,'N');
Ouvrir(&findex32,nom_fichier_ind3_2,'N');


Ouvriretof(&findex21,nom_fichier_ind2_1,'N');
Ouvrir(&findex22,nom_fichier_ind2_2,'N');



printf("\n\n  -Donner le nombre d'enregistrement n= ");
scanf("%d",&n);//si n devient tres grand le programme s'arret

Chargement_Init(n,tabind1,tabIndex2,tabInd3,&nbre_liredire,&nbre_ecriredire);

Ouvrir(&f,nom_fichier,'A');
Fermer(f);
//charger le fichier f avec n enreg
//remplir les 3 tables d'index que nous allons utiliser dans la suit du programme




     textcolor(BLACK);

    printf ("\n\n\tChargement du fichier en cours [");
    for  (int i=0; i<=40; i++)
    {
        textcolor(BLUE);
        printf ("%c",219);Sleep(18);

    }
    textcolor(BLACK);
    printf ("] Termine \n\n");

printf("\n\n");
textcolor(BLACK);
textcolor(BLUE);
printf("     Le cout total du chargement initial :\n");
printf("                                          =>Le nombre de Liredire: ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                          =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d",nbre_ecriredire);

charger_index2_specialite(&findex21,tabIndex2,&findex22,&nbre_lireindex2,&nbre_ecrireindex2);
Liberer_tab2(tabIndex2);//liberation de la table d'index2 de la MC

fermertof(findex21);
Fermer(findex22);

Charger_index3(&findex31,&findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);
Liberer_tab3(tabInd3);//liberation de la tbale d'index 3 de la MC

fermertof(findex31);
Fermer(findex32);
Fermer(f);


printf("\n\n  -Voulez-vous afficher le contenu du fichier cree?\n\n");
choix2=ouinon();
if(choix2==1){
//1-ouverture du fichier de donnee en mode ancien pour l'affichage
clrscr();
fichier_mesres();
Ouvrir(&f,nom_fichier,'A');
Affichage_Initial(f,nom_fichier,&nbre_liredire,&nbre_ecriredire);  // affichage de son contenu avant l'epuration
Fermer(f);

}else{
if(choix2==2)
{textcolor(BLUE);
    printf("\n\n        ~~~~~~~~~~>> Felicitations! <<~~~~~~~~~~~\n");
   printf("            Fichier ENSEIGNANT-MESRS.bin cree avec succes.\n");
   textcolor(BLACK);
}else{
    textcolor(RED);
printf(" Code entre faux!\n");
textcolor(BLACK);
}
}

Ouvriretof(&findex1,nom_fichier_ind1,'N');
Charger_index1(&findex1,n,tabind1,&nbre_lireindex1,&nbre_ecrireindex1);//remplissage d'un fichier (d'index1) par la table index1


//affichage du fichier index1 pour savoir si la procedure focntionne correctment
printf("\n\n  -Voulez-vous afficher le fichier index1?\n\n");

    choix2=ouinon();

if(choix2==1){
Afficher_Index1(findex1,&nbre_lireindex1,&nbre_ecrireindex1);

fermertof(findex1);
}else{

if(choix2==2){
textcolor(BLUE);
    printf("\n\n        ~~~~~~~~~~>> Felicitations! <<~~~~~~~~~~~\n");
    printf("                 Fichier index1 cree avec succes.\n");
textcolor(BLACK);


}else{

    textcolor(RED);
printf("Code entre faux! \n");
textcolor(BLACK);

}

fermertof(findex1);
}

returnToMenu();
}


if(choix==4){
        nbre_liredire=0;
        nbre_ecriredire=0;

   clrscr();
   supm();

    Ouvriretof(&findex1,nom_fichier_ind1,'A');//ouverture du fichier index1 en mode ancien
    n=Entetetof(findex1,2);
    //remplissage de la table index1 pour les manipulation en MC
    RemplirTab1(findex1,tabind1,n,&nbre_lireindex1,&nbre_ecrireindex1);
    fermertof(findex1);
    //la table est bien repmlie et correctement j'ai verifie

    stop=1;
while(stop==1) {
    Ouvrir(&f,nom_fichier,'A');
    printf("\n\n -Veuillez donner le matricule de l'enseignant que vous souhaitez supprimer: ");
    scanf("%d",&i);


  while(i>999999 || i<111111){
    textcolor(RED);
    printf(" -Erreur! Veuillez entrer un matricule entre 111111 et 999999: \n");
    textcolor(BLACK);
    scanf("%d",&i);
   }


clrscr();
printf("\n\n\n");
textcolor(RED);
printf("                                               -Etes-vous certain de vouloir supprimer cet enseignant?\n\n");
textcolor(BLACK);
l=ouinon();
if(l==1){
Supp_mat(&f,i,tabind1,&n,&nbre_liredire,&nbre_ecriredire);
textcolor(BLUE);
printf("\n");

}
   Fermer(f);

    printf("\n\n -Voulez-vous supprimer un autre enregistrement?\n\n");
    reponse=ouinon();
    if(reponse==1){
      stop=1;
      clrscr();
      supm();
    }else{
        stop=0;
    }

}

    //apres avoir terminer toutes les suppresions souhaitees
    //on sauvgarde la table d'index dans le son fichier index

     Ouvriretof(&findex1,nom_fichier_ind1,'N');
     Charger_index1(&findex1,n,tabind1,&nbre_lireindex1,&nbre_ecrireindex1);
     fermertof(findex1);


     printf("\n\n -Voulez-vous verifier la suppression?\n\n");
    reponse=ouinon();
    if(reponse==1){

clrscr();
esg();
printf("\n\n");
Ouvrir(&f,nom_fichier,'A' );
afficher_entete(f);
Fermer(f);

    }
    printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
returnToMenu();

}


if(choix==5){
         nbre_liredire=0;
        nbre_ecriredire=0;


clrscr();
sups();

Ouvriretof(&findex1,nom_fichier_ind1,'A');//ouverture du fichier index1 en mode ancien

Ouvriretof(&findex21,nom_fichier_ind2_1,'A');
Ouvrir(&findex22,nom_fichier_ind2_2,'A');

n=Entetetof(findex1,2);//n=taille de la table d'index 1
//remplissage de la table index1 pour les manipulation en MC

RemplirTab1(findex1,tabind1,n,&nbre_lireindex1,&nbre_ecrireindex1);
RemplirTab2(findex21,findex22,tabIndex2,&nbre_lireindex2,&nbre_ecrireindex2);

 stop=1;
while(stop==1) {
Ouvrir(&f,nom_fichier,'A');//ouverture d'un fichier existant en mode ancien
printf(" -Veuillez cliquer sur le nom de la specialite que vous voulez supprimer \n\n");
z=spes();

clrscr();
printf("\n\n");
textcolor(RED);
printf("                              -Etes-vous certain de vouloir supprimer cette specialite?\n\n");
textcolor(BLACK);
l=ouinon();
if(l==1){
 Supp_specialite(&f,z,tabIndex2,tabind1,&n,&nbre_liredire,&nbre_ecriredire);

}

Fermer(f);

 printf("\n\n -Voulez-vous supprimer une autre specialite?\n\n");
    reponse=ouinon();
    if(reponse==1){
      stop=1;
      clrscr();
      supm();
    }else{
        stop=0;
    }

}
Liberer_tab2(tabIndex2);

printf("\n\n -Voulez-vous verifier la suppression?\n\n");
    reponse=ouinon();
    if(reponse==1){

clrscr();
Ouvrir(&f,nom_fichier,'A' );
afficher_entete(f);
Fermer(f);

    }

fermertof(findex1);
 Ouvriretof(&findex1,nom_fichier_ind1,'N');//MISE A JOUR DE L 'INDEX 1
 Charger_index1(&findex1,n,tabind1,&nbre_lireindex1,&nbre_ecrireindex1);
fermertof(findex1);
 Fermer(findex22);
fermertof(findex21);
printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
returnToMenu();


}



if(choix==6){
        nbre_liredire=0;
        nbre_ecriredire=0;

        clrscr();

    //un sous menu pour choisir codage ou decodage

    textbackground(WHITE);
            printf("\n\n");
            textcolor(15);
            textcolor(BLUE);
            printf("\t                         -->  Veuillez faire un choix dans le menu suivant  <--                \n\n") ;
            printf("\n\n\n");
            textcolor(15);
            textbackground(WHITE);

            textcolor(BLACK);
            printf("\t|======================================================|\n");textcolor(BLACK);
            printf("\t|");textcolor(BLUE);
            printf("\t                  Sous menu                    ");textcolor(BLACK);
            printf("|\n");
            textcolor(BLACK);
            printf("\t|======================================================|\n");
    choix2=menu2(3,     "\t|1- Codage du fichier ENSEIGNANT-MESRS.bin             |",
                        "\t|2- Encodage du fichier  ENSEIGNANT-MESRS_code.bin     |",
                        "\t|0- Quitter                                            |");

        if(choix2==1){
        clrscr();
        cdg();
    printf("\n\n  -Veuillez donner la cle de codage: ");
    scanf(" %s",key);
    while(strlen(key)>=30){
        textcolor(RED);
        printf("    -> Veuillez donnner SVP une cle dont la taille est inferieure strictement a 30 caracteres: ");
        textcolor(BLACK);
        scanf(" %s",key);

    }
    Ouvrir(&f,nom_fichier,'A');
    Ouvrir(&fcode,nom_fichiercode,'N');
    Coder_fichier_bin(f,&fcode,key,&nbre_liredire,&nbre_ecriredire);
   Fermer(f);
    Fermer(fcode);

     textcolor(BLACK);
   printf ("\n\n\tCodage du fichier ENSEIGNANT-MESRS.bin en cours [");
    for  (int i=0; i<=40; i++)
    {
        textcolor(BLUE);
        printf ("%c",219);Sleep(18);

    }
    textcolor(BLACK);
    printf ("] Termine \n\n");
    printf("\n");
    textcolor(BLUE);

printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);

returnToMenu();



        }



if(choix2==2){
    Ouvrir(&fcode,nom_fichiercode,'A');
    Ouvrir(&fdecode,nom_fichierdecode,'N');

    Decoder_fichier_bin(fcode,&fdecode,&nbre_liredire,&nbre_ecriredire);
     textcolor(BLACK);

    printf ("\n\n\tDecodage du fichier ENSEIGNANT-MESRS_code.bin en cours [");
    for  (int i=0; i<=40; i++)
    {
        textcolor(BLUE);
        printf ("%c",219);Sleep(18);

    }
    textcolor(BLACK);
    printf ("] Termine \n\n");
     Fermer(fdecode);
    Fermer(fcode);
printf("\n\n -Voulez-vous afficher le fichier encode?\n\n");
    reponse=ouinon();
    if(reponse==1){

clrscr();
Ouvrir(&fdecode,nom_fichierdecode,'A');
Affichage_Initial(fdecode,nom_fichierdecode,&nbre_liredire,&nbre_ecriredire);
Fermer(fdecode);
    }
printf("\n\n\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
    returnToMenu();


}
if(choix2==3){
returnToMenu();

}

}

if(choix==2){
        nbre_liredire=0;
        nbre_ecriredire=0;

    clrscr();
    newprof();

Ouvriretof(&findex31,nom_fichier_ind3_1,'A');
Ouvrir(&findex32,nom_fichier_ind3_2,'A');
Ouvriretof(&findex1,nom_fichier_ind1,'A');

RemplirTab1(findex1,tabind1,Entetetof(findex1,2),&nbre_lireindex1,&nbre_ecrireindex1);

RemplirTab3(findex31,findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);

Ouvriretof(&findex21,nom_fichier_ind2_1,'A');
Ouvrir(&findex22,nom_fichier_ind2_2,'A');
RemplirTab2(findex21,findex22,tabIndex2,&nbre_lireindex2,&nbre_ecrireindex2);
fermertof(findex31);
Fermer(findex32);
fermertof(findex21);
Fermer(findex22);
fermertof(findex1);


Ajout_Enseignant(tabind1,&n,tabIndex2,tabInd3,&z,&nbre_liredire,&nbre_ecriredire,&trouve);


if(trouve==false){
Ouvriretof(&findex1,nom_fichier_ind1,'N');
Charger_index1(&findex1,n,tabind1,&nbre_lireindex1,&nbre_ecrireindex1);
fermertof(findex1);


Ouvriretof(&findex31,nom_fichier_ind3_1,'N');
Ouvrir(&findex32,nom_fichier_ind3_2,'N');
Charger_index3(&findex31,&findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);

Ouvriretof(&findex21,nom_fichier_ind2_1,'N');
Ouvrir(&findex22,nom_fichier_ind2_2,'N');
charger_index2_specialite(&findex21,tabIndex2,&findex22,&nbre_lireindex2,&nbre_ecrireindex2);



printf("\n  -Voulez-vous verifier l'ajout de cet enseignant?\n");
reponse=ouinon();
}
if(reponse==1){//oui
        clrscr();
  //1-consulter l'entete du fichier
  //2-consulter l'enseignant ajoute
  //3-consulter le fichier

textbackground(WHITE);
            printf("\n\n");
            textcolor(15);
            textcolor(BLUE);
            printf("\t                         -->  Veuillez faire un choix dans le menu suivant  <--                \n\n") ;
            printf("\n\n\n");
            textcolor(15);
            textbackground(WHITE);

            textcolor(BLACK);
            printf("\t|=================================================|\n");textcolor(BLACK);
            printf("\t|");textcolor(BLUE);
           printf("\t                  Sous menu               ");textcolor(BLACK);
            printf("|\n");
            textcolor(BLACK);
            printf("\t|=================================================|\n");

    choix2=menu2(4,     "\t|1- Consulter l'entete du fichier                 |",
                        "\t|2- Consulter l'enseignant ajoute                 |",
                        "\t|3- Consulter l'entete du fichier et l'enseignant |",
                        "\t|0- Quitter                                       |");


if(choix2==1){
clrscr();
Ouvrir(&f,nom_fichier,'A' );
afficher_entete(f);
Fermer(f);
}
if(choix2==2){
       nbre_liredire=0;
        nbre_ecriredire=0;

    clrscr();

 Ouvrir(&f,nom_fichier,'A' );
     esg();
    printf("\n\n");
afficher_enreg(f,z,tabind1,n,&nbre_liredire,&nbre_ecriredire);
printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
Fermer(f);
}
if(choix2==3){
         nbre_liredire=0;
        nbre_ecriredire=0;

    clrscr();

  Ouvrir(&f,nom_fichier,'A' );
 afficher_entete(f);
printf("\n\n\n\n");
    esg();
    printf("\n\n");
afficher_enreg(f,z,tabind1,n,&nbre_liredire,&nbre_ecriredire);
printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
Fermer(f);
}
}
returnToMenu();

}
if(choix==3){
        nbre_liredire=0;
        nbre_ecriredire=0;

        stop=1;



Ouvriretof(&findex1,nom_fichier_ind1,'A');

Ouvriretof(&findex31,nom_fichier_ind3_1,'A');
Ouvrir(&findex32,nom_fichier_ind3_2,'A');
n=Entetetof(findex1,2);
RemplirTab1(findex1,tabind1,n,&nbre_lireindex1,&nbre_ecrireindex1);

RemplirTab3(findex31,findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);


fermertof(findex31);
Fermer(findex32);

fermertof(findex1);

while(stop==1){

clrscr();
transfert();
Ouvrir(&f,nom_fichier,'A');
printf("\n  -Veuillez cliquer sur le nouvel etablissement: \n\n");
x=reseau();
printf("\n\n\n  -Veuillez donner le matricule de cet enseigant: ");
scanf("%d",&z);

while(z>999999 || z<111111){
    textcolor(RED);
    printf(" -Erreur! Veuillez entrer un matricule entre 111111 et 999999: \n");
    textcolor(BLACK);
    scanf("%d",&z);
   }

clrscr();
printf("\n\n\n");
textcolor(RED);
printf("                                               -Etes-vous certain de vouloir modifier l'etablissement  d'exercice de cet enseignant?\n\n");
textcolor(BLACK);
l=ouinon();
if(l==1){
        Modifer_etab(&f,z,x,tabind1,tabInd3,&nbre_liredire,&nbre_ecriredire);


}

Fermer(f);


printf("\n\n  -Voulez-vous verifier la modification de  l'etablissement de cet enseignant?\n");
reponse=ouinon();
if(reponse==1){
//oui
clrscr();
esg();
    printf("\n\n");
Ouvrir(&f,nom_fichier,'A');
afficher_enreg(f,z,tabind1,n,&nbre_liredire,&nbre_ecriredire);
Fermer(f);
}
//non

printf("\n\n -Voulez-vous modifier l'etablissement d'un autre enseignant?\n\n");
    reponse=ouinon();
    if(reponse==1){
      stop=1;
      clrscr();
      transfert();
    }else{
        stop=0;
    }


 }//stop
 Ouvriretof(&findex31,nom_fichier_ind3_1,'N');
Ouvrir(&findex32,nom_fichier_ind3_2,'N');
Charger_index3(&findex31,&findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);
printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
returnToMenu();

}

if(choix==7){

//sous menu des affichages
clrscr();
textbackground(WHITE);


            printf("\n\n");
            textcolor(15);
            textcolor(BLUE);
            printf("\t                         -->  Veuillez faire un choix dans le menu suivant  <--                \n\n") ;
            printf("\n\n\n");
            textcolor(15);
            textbackground(WHITE);
            textcolor(BLACK);
            printf("\t|==================================================================================================|\n");textcolor(BLACK);
            printf("\t|");textcolor(BLUE);
            printf("\t                                Menu                                                       ");textcolor(BLACK);
            printf("|\n");
            textcolor(BLACK);
            printf("\t|==================================================================================================|\n");

choix2=menu2(8,         "\t|1- Affichage du fichier ENSEIGNANT-MESRS.bin                                                      |",
                        "\t|2- Consultation de tous les enseignants travaillant dans une region donnee (Ouest, Centre et Est) |",
                        "\t|3- Affichage de tous les enseignants travaillant dans un etablissement donne selon une anciennete |",
                        "\t|4- Consultation d'un enseignant                                                                   |",
                        "\t|5- Affichage d'un bloc donne du fichier                                                           |",
                        "\t|6- Affichage de l'entete du fichier ENSEIGNANT-MESRS.bin                                          |",
                        "\t|7- Affichage externe et//ou interne des trois premiers blocs du fichier                           |",
                        "\t|0- Quitter                                                                                        |");

if(choix2==3){
     nbre_liredire=0;
        nbre_ecriredire=0;

        clrscr();
requette();
printf("\n\n");



Ouvriretof(&findex1,nom_fichier_ind1,'A');
n=Entetetof(findex1,2);
Ouvriretof(&findex31,nom_fichier_ind3_1,'A');
Ouvrir(&findex32,nom_fichier_ind3_2,'A');
RemplirTab1(findex1,tabind1,n,&nbre_lireindex1,&nbre_ecrireindex1);
RemplirTab3(findex31,findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);
fermertof(findex31);
Fermer(findex32);
fermertof(findex1);
int h,mm;
printf("Affichage de tous les enseignants travaillant dans un etablissement donne ayant une anciennete entre deux valeurs donnees (Requete a intervalle).\n\n");
printf("   -Veuillez donner les deux bornes de l'intervalle: \n\n");

printf("              -La borne inferieure: ");
scanf("%d",&h);
printf("              -La borne superieure: ");
scanf("%d",&mm);

while(mm<=h){
        textcolor(RED);
printf("   -Veuillez donner une borne superieure strictement a la borne inferieure  %d: ",h);
 textcolor(BLACK);
 printf("              -La borne superieure: ");
scanf("%d",&mm);
}


char Etab[long_max];


printf("\n  -Veuillez cliquer sur l'etablissement\n\n");
x=reseau();
Etablissement(Etab,x);

clrscr();
requette();
printf("\n");
affichage_anciennete(h,mm,Etab,tabInd3,tabind1,n,&nbre_liredire,&nbre_ecriredire);
returnToMenu();
}


if(choix2==2){
         nbre_liredire=0;
        nbre_ecriredire=0;

        clrscr();
        requette();
        printf("\n\n");
  Ouvrir(&f,nom_fichier,'A');
n=Entete(f,3);
Fermer(f);
Ouvriretof(&findex1,nom_fichier_ind1,'A');

Ouvriretof(&findex31,nom_fichier_ind3_1,'A');
Ouvrir(&findex32,nom_fichier_ind3_2,'A');
RemplirTab1(findex1,tabind1,Entetetof(findex1,1),&nbre_lireindex1,&nbre_ecrireindex1);
RemplirTab3(findex31,findex32,tabInd3,&nbre_lireindex3,&nbre_ecrireindex3);
fermertof(findex31);
Fermer(findex32);
fermertof(findex1);

 Consultation_region(tabInd3,tabind1,n,&nbre_liredire,&nbre_ecriredire);

 returnToMenu();

 }
 if(choix2==1){
      nbre_liredire=0;
        nbre_ecriredire=0;

      nbre_liredire=0;
        nbre_ecriredire=0;

clrscr();
    Ouvrir(&f,nom_fichier,'A');
    Affichage_Initial(f,nom_fichier,&nbre_liredire,&nbre_ecriredire);
    Fermer(f);


    returnToMenu();

 }
 if(choix2==4){
         nbre_liredire=0;
        nbre_ecriredire=0;



    Ouvriretof(&findex1,nom_fichier_ind1,'A');//ouverture du fichier index1 en mode ancien
    n=Entetetof(findex1,2);

    //remplissage de la table index1 pour les manipulation en MC
    RemplirTab1(findex1,tabind1,n,&nbre_lireindex1,&nbre_ecrireindex1);
    fermertof(findex1);

    //la table est bien repmlie et correctement j'ai verifie
clrscr();

esg();
    printf("\n\n");
   printf("  -Veuillez donner le matricule de l'enseignant: ");
   scanf("%d",&z);
   while(z>999999 || z<111111){
        textcolor(RED);
    printf(" -Erreur! Veuillez entrer un matricule entre 111111 et 999999: \n");
   textcolor(BLACK);
    scanf("%d",&z);
   }
Ouvrir(&f,nom_fichier,'A');
clrscr();
esg();
printf("\n\n");
afficher_enreg(f,z,tabind1,n,&nbre_liredire,&nbre_ecriredire);
Fermer(f);
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);
returnToMenu();
 }
 if(choix2==5){
         nbre_liredire=0;
        nbre_ecriredire=0;

     clrscr();

      stop=1;
while(stop==1) {
     Ouvrir(&f,nom_fichier,'A');
     printf("  -Le fichier contient %d blocs.",Entete(f,4));
     printf("    ->Veuillez donner le nomero du bloc que vous souhaitez afficher: ");
     scanf("%d",&z);

     while(z>Entete(f,4) || z<1){
            textcolor(RED);
        printf(" -Veuillez donner un numero entre 1 et %d : ",Entete(f,4));
     textcolor(BLACK);
        scanf("%d",&z);
     }
clrscr();
affb();
printf("\n\n");
    afficher_bloc(f,z,&nbre_liredire,&nbre_ecriredire);
     Fermer(f);
     printf("\n\n");

system("pause");

      printf("\n\n\n\n -Voulez-vous afficher un autre bloc?\n\n");
    reponse=ouinon();
    if(reponse==1){
      stop=1;
      clrscr();

    }else{
        stop=0;
    }


     }
  printf("\n");
textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",nbre_liredire);
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",nbre_ecriredire);

   returnToMenu();
 }
 if(choix2==6){

Ouvrir(&f,nom_fichier,'A');
clrscr();

printf("\n\n");
afficher_entete(f);
Fermer(f);


   returnToMenu();
 }
 if(choix2==7){
    Ouvrir(&f,nom_fichier,'A');
afficher3B(f);
Fermer(f);
printf("\n\n");
   returnToMenu();

 }
 if(choix2==8){
   returnToMenu();
 }
   }



  }//arreter


return 0;

}
