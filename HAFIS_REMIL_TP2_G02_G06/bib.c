
#include "bib.h"
/***                        MACHINE ABSTRAITE LnOF                              ***/

void Ouvrir(FLNOF *f,char *nomf,char mode){
    TEntete buf0;
    if(mode=='A'||mode=='a'){
            //le mode ancien le fichier existe
            //ouverture en mode rb+
            (*f).fich=fopen(nomf,"rb+");

            if((*f).fich==NULL){
                    printf("\n#ERREUR, dans l'ouverture du fichier en mode Ancien\n");
            }else{
             //initialisation du bloc d'entete: lecture du bloc d'entete a partir du fichier
           rewind((*f).fich);

           fread(&((*f).entete),sizeof(TEntete),1,(*f).fich);


            }
            }else{
        if(mode=='N'||mode=='n'){
                //ouverture en mode nouveau cad wb+
                //le fichier n'existe

            (*f).fich=fopen(nomf,"wb+");



        if((*f).fich==NULL){
                    printf("\n#ERREUR, dans l'ouverture du fichier en mode Nouveau\n");
            }else{
             //initialisation du bloc d'entete avec toutes les caracteristiques initiales et l'ecrire dans le fichier

            buf0.nbe=0;
            (buf0.Tete)=-1;
            (buf0.Queue)=-1;
            buf0.nbbloc=0;
            rewind((*f).fich);
           fwrite(&buf0,sizeof(TEntete),1,(*f).fich);
          (*f).entete=buf0;

            }

        }
        else{
            printf("\nERREUR dans le mode d'ouverture!\n");
        }

    }

}
void Fermer (FLNOF f){
rewind(f.fich);
fwrite(&(f.entete),sizeof(TEntete),1,f.fich);//ecrire le bloc d'entete avant de fermer
//le fichier il se peut qu'on a fait des mises a jours dans l'entete
fclose(f.fich);
}
void Aff_Entete(FLNOF *f,int i,int v){

if(i==1){//la tete du fichier(num du premier bloc de la liste)
(*f).entete.Tete=v;

}
if(i==2){//la queue du fichier(num du dernier bloc du fichier)
(*f).entete.Queue=v;
}
if(i==3){//le nombre d'enreg dans le fichier
(*f).entete.nbe=v;
}
if(i==4){//nombre de blocs dans le fichier
(*f).entete.nbbloc=v;
}

}

int Entete(FLNOF f,int i){
    int cpt ;

    if(i==1){//la tete du fichier(num du premier bloc de la liste)
       cpt=(f.entete.Tete);

}
if(i==2){//la queue du fichier(num du dernier bloc du fichier)
cpt=(f.entete.Queue);
}
if(i==3){//le nombre d'enreg dans le fichier
cpt=(f.entete.nbe);
}
if(i==4){
    cpt=(f.entete.nbbloc);
}

return cpt;
}

void Aff_Entete_cle(FLNOF *f,char *cle){

    strcpy((*f).entete.cle,cle);//focntionne

}

void Entete_cle(FLNOF f,char *cle){


    strcpy(cle,f.entete.cle);

}
void EcrireDir(FLNOF *f,int i,Tbloc buf){
    rewind((*f).fich);
    fseek((*f).fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc))),SEEK_SET);
    fwrite(&buf,sizeof(Tbloc),1,(*f).fich);
}

void LireDire(FLNOF f,int i, Tbloc *buf){
rewind(f.fich);

fseek(f.fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc))),SEEK_SET);

fread(&(*buf),sizeof(Tbloc),1,f.fich);
}
int AllocBloc(FLNOF f){
int i ;
if(Entete(f,1)!=-1){
        i=Entete(f,2)+1;//le numero de la queue actuelle +1
}
else{
//la queue=-1 => le fichier vide donc le premier bloc est de num =1
    i=1;
}
return i;

}

/**          MACHINE ABSTRAITE    TOF       **/

void Ouvriretof(FICHTOF *F,char *nomf,char mode){

    TEnteteInd buf;//buffer dans MC de bloc d'entete du fichier
    FILE *f;

    //mode="A" mode ancien (fichier existant)
    if((mode=='A')|| (mode=='a')){
            f=fopen(nomf,"rb+");//ouverture en mode lecture binaire
    if(f!=NULL){
        //preparer le bloc d'entete
        //Les caractéristiques (bloc0) seront lues en MC lors de l’ouverture.
        //le bloc0 sera LU dans le buffer de la MC
         (*F).fich=f;
        rewind((*F).fich);
        fread(&(*F).entete,sizeof(TEnteteInd),1,f);


    }
    else {
        printf("\n#ERREUR, dans l'ouverture du fichier en mode Ancien\n");
    }

    }
    //mode="N" fichier nouveau
    if((mode=='N') || (mode=='n')){//ouverture en mode nouveau (creer le fichier)
            f=fopen(nomf,"wb+");
    if(f!=NULL){
        //preparer le bloc d'entete
        //alouer un bloc0 et faire les initialisations
        //Les caractéristiques seront allouées en MC lors de le création

       buf.nbBloc=0;
       buf.nbcouples=0;
       buf.nbcouplesSupp=0;
        fwrite(&buf,sizeof(TEnteteInd),1,f);
        (*F).fich=f;
        (*F).entete=buf;

    }
    else{
       printf("\n#ERREUR, dans l'ouverture du fichier en mode Nouveau\n");
    }
}
}

void fermertof(FICHTOF F){
    //avant de fermer, mettre le bloc d'entete en MS
  rewind(F.fich);
    fwrite(&(F.entete),sizeof(TEnteteInd),1,(F.fich));
    fclose(F.fich);

}
/*Ecriture de buf dans le bloc numéro i de F*/
void EcrireDirtof(FICHTOF *F,int i,TblocInd1 buf){

    //deplacement a la position i
    rewind((*F).fich);
    fseek((*F).fich,((i-1)*sizeof(TblocInd1)+sizeof(TEnteteInd)),SEEK_SET);
    //ecriture
    fwrite(&buf,sizeof(TblocInd1),1,(*F).fich);


}
/*Lecture du bloc numéro i de F dans la variable buf*/
void LireDirtof(FICHTOF F,int i,TblocInd1 *buf){
 rewind(F.fich);
  fseek(F.fich,((i-1)*sizeof(TblocInd1)+sizeof(TEnteteInd)),SEEK_SET);
  fread(buf,sizeof(TblocInd1),1,F.fich);
}

/*Retourne la valeur de la caractéristique numéro i*/
int Entetetof( FICHTOF F , int i ) {

    if(i==1){
        //Retourne le nombre de blocs dans le fichier==au numero du dernier bloc
        return (F.entete.nbBloc);
    }

      if(i==3){
        //Retourne le nombre d'enregistrement supprimes logiquement dans le fichier
        return (F.entete.nbcouplesSupp);
    }
     if(i==2){
        //Retourne le nombre d'enreg dans tout le fichier
        return (F.entete.nbcouples);
    }
    else {return 0;}
}

/*Affecte v à la caractéristique numéro i*/
void Aff_entetetof(FICHTOF *F , int i , int v){
    if(i==1){
        //affecter ou mettre a jour le nombre de blocs dans le fichier
        (*F).entete.nbBloc=v;
    }
    if(i==3){
            //affecter ou mettre a jour le nombre d'enregistrements supprimer logiquement

         (*F).entete.nbcouplesSupp=v;
    }
    if(i==2){
        //affecter le nombre d'enregistrement
        (*F).entete.nbcouples=v;
    }

}

/** MACHINE ABSTRAITE SUR LES LISTES UNIDIRECTIONNELLES */

//Allouer( p ) - procédure qui alloue un nouveau maillon et affecte son adresse dans le pointeur p */
void Allouer (maillon *pointeur){
 *pointeur= (malloc(sizeof(struct maillon)));
 }
 //Aff-val( p,v ) - procédure qui affecte v dans le champ val du maillon pointé par p.
  void Aff_val(maillon *pt_m  ,int v){
     (*pt_m)->mat=v;}
 //Aff-adr( p,q ) - procédure qui affecte q dans le champ adr du maillon pointé par p.*/
  void Aff_adr( maillon *p,maillon q ){
      (*p)->suivant=q;
}
//Suivant( p ) : pointeur - fonction qui retourne le contenu du champs adr du maillon pointé par p*/
  maillon Suivant(maillon pointeur){
  return (pointeur->suivant);
   }
//Valeur(p) elle donne la valeur du champs valeur du mailoon pointé par p*/
  int Valeur(maillon pointeur){
return pointeur->mat;
  }
//liberer un maillon
void Liberer(maillon pointeur){
free(pointeur);//liberer l'espace occupe en MC
}
/***                   LES FONCTIONS UTILISEEs DANS LE MODULE DE  CHARGEMENT INITIAL                      ***/
/**REMARQUE: NE PAS METTRE SRAND(TIME(0)) DANS CES FONCTION CAR APRES ELLES SERONT DANS DES BOUCLES */
//generer un matricule aleatoire entre 111111 et 999999
int Mat_Alea(){

    int a,q;
    a=Alea(111,999);
    q=Alea(111,999);
    a=(a*1000)+q;
    return a;

}
//fonction qui genere   aleatoirement un nombre compris entre inf et sup
int Alea(int inf,int sup){

     return ( (rand()%(sup-inf+1))+inf);
}
//genere un nom/prenom aleatoirement de longueure comprise entre 4 et 30 caracteres
void NomPrenom_Alea(char* name){
int i,longueure,nb;
char tab[27]="abcdefghijklmnopqrstuvwxyz";
longueure=Alea(4,30);

for(i=0;i<longueure;i++){
nb=Alea(1,26);
 if (i==0){
    name[i]=tab[nb-1]-32;
 }
   else{
   name[i]=tab[nb-1];
 }
}
}
//fonction qui verifie si une annee est bissextile ou pas
bool an_bissextile(int annee){
bool bissextile;
//Si l'année est divisible par 4 et non-divisible par 100, c'est une année bissextile (elle a 366 jours).
//Si l'année est divisible par 400, c'est une année bissextile (elle a 366 jours).
//Sinon, l'année n'est pas bissextile (elle a 365 jours).

if(((annee%4==0) &&(annee%100!=0)) || (annee%400==0)){
    bissextile=true;
} else{
 bissextile=false;
}
return bissextile;

}
//genere aleatoirement une date ((focntion commune pour la date de naissance et la date de recrutement))

//choix =1 =>> date de naissance
//choix=2 =>> date de recrutement
Tdate Genrer_Date(int choix){
Tdate e;
if (choix==1){
    e.Annee=Alea(1953,1998); //pour generer l'annee de naissance

}
if(choix==2){
e.Annee=Alea(1985,2022);//pour generer l'annee de recrutement

}
 e.Mois=Alea(1,12);
 // generer le jour en focntion du mois car il y a des mois a 30, 31,29,28 jours
 switch(e.Mois){
 case 1:
     e.Jour=Alea(1,31);
     break;
 case 2 :
    if (an_bissextile(e.Annee)==true){
             e.Jour=Alea(1,29);
    }else{
            e.Jour=Alea(1,28);
    }
    break;
 case 3:
      e.Jour=Alea(1,31);
      break;
 case 4:
      e.Jour=Alea(1,30);
      break;
 case 5:
      e.Jour=Alea(1,31);
      break;
 case 6:
      e.Jour=Alea(1,30);
      break;
 case 7:
      e.Jour=Alea(1,31);
      break;
 case 8:
      e.Jour=Alea(1,31);
      break;
 case 9:
      e.Jour=Alea(1,30);
      break;
 case 10:
      e.Jour=Alea(1,31);
      break;
 case 11:
      e.Jour=Alea(1,30);
      break;
 case 12:
      e.Jour=Alea(1,31);
      break;

 }
  return e;
}
void Alea_Wilaya_Nais(char *lib){
//on utilise un tableau de chaine de caracteres de taille = 58
//chaque case contiendra une libellee d'une wiliya
//le numero aleatoire num correspond directement avec l'indice num-1 dans le tableau
 //initialisation du tableau
 char *tab_lib[]={"ADRAR","CHLEF","LAGHOUAT","OUM EL BOUAGHI","BATNA","BEJAIA","BISKRA","BECHAR","BLIDA","BOUIRA","TAMANRASSET","TEBESSA","TELEMCEN","TIARET","TIZI-OUZOU","ALGER","DJELFA","DJELFA","SETIF","SAIDA","SKIKDA","SIDI BEL ABBES","ANNABA","GUELMA","CONSTANTINE","MEDEA","MONSTAGANEM","M'SILA","MASCARA","OUARGLA","ORAN","BAYADH","ILLIZI","BORDJ BOU ARRERIDJ","BOUMERDES","TARF","TINDOUF","TISSEMSILT", "EL OUED","KHENCHELA","SOUK AHRAS","TIPAZA","MILA","AIN DEFLA","NAAMA","AIN TEMOUCHENT","GHARDAIA","RELIZANE","TIMIMOUN","BORDJ BADJI MOKHTAR","OULED DJELLAL","BENI ABBES","IN SALAH","IN GUEZZAM","TOUGGOURT","DJANET","EL M'GHAIR","EL MENIAA"};
int num ;
num=Alea(1,58);
strcpy(lib,tab_lib[num-1]);


}
int Sexe (){
// si la fonction retourne 1 cela veut dire masculin
// si la fonction retourne 2 cela veut dire feminin
   return Alea(1,2);
}
void Groupe_Sang(char* group_s){
int g_sang;
char *group[]={"O+","A+","B+","O-","A-","AB+","B-","AB-"};
g_sang=Alea(1,8);
strcpy(group_s,group[g_sang-1]);
}
void Generer_Grade(char* grade){
char *grades[]={"Professeur","Maitre de conferences Rang A","Maitre de conferences Rang B","Maitre assistant Rang A","Maitre assistant Rang B","Assistant"};
int g;
g=Alea(1,6);
strcpy(grade,grades[g-1]);
}
/*
void Specialite(char* filiere){
char *specialite[]={"Informatique","Architecture","Medecine","Veterinaire","Pharmacie","Mathematique","Physique","MEDECINE DENTAIRE",
"AGRICULTURE SAHARIENNE",
"AGRONOMIE",
"SCIENCES ET TECHNOLOGIES",
"SCIENCES DE LA MATIERE",
"SCIENCES DE LA NATURE ET DE LA VIE",
"SCIENCES ECONOMIQUES, DE GESTION ET COMMERCIALES",
"SCIENCES POLITIQUES",
"DROIT",
"LANGUE FRANCAISE",
"LANGUE ANGLAISE",
"SCIENCES HUMAINES",
"SCIENCES SOCIALES",
"SCIENCES ISLAMIQUES",
"LANGUE ET LITTERATURE ARABES",
"SCIENCES ET TECHNOLOGIES",
"GENIE CIVIL",
"TRAVAUX PUBLICS",
"GESTION DES TECHNIQUES URBAINES",
"GEOGRAPHIE ET AMENAGEMENT DU TERRITOIRE",
"GEOLOGIE",
"SCIENCES ET TECHNIQUES DES ACTIVITES PHYSIQUES ET SPORTIVES",
"TELECOMMUNICATIONS",
"SCIENCES ALIMENTAIRES",
"SCIENCES DE GESTION SCIENCES FINANCIERES ET COMPTABILITE",
"DES ENERGIES RENOUVELABLES D ENVIRONNEMENT DU DEVELOPPEMENT DURABL",
"SCIENCES VETERINAIRES",
"LANGUE ET CULTURE AMAZIGHES",
"TRADUCTION INTERPRETARIAT (ARABE, FRANCAIS, ANGLAIS)",
"HYDRAULIQUE",
"BIOTECHNOLOGIE",
"URBANISME",
"AERONAUTIQUE",
"GENIE DES PROCEDES",
"ENERGIES RENOUVELABLES",
"ELECTROTECHNIQUE",
"GENIE MECANIQUE",
"LANGUE ITALIENNE",
"MANAGEMENT",
"DES SCIENCES APPLIQUEES",
"GENIE INDUSTRIEL",
"GENIEBIOMEDICAL",
"LANGUE ESPAGNOLE",
"ARTS",
"METIERS DE LA VILLE GEOMETRE TOPOGRAPHE",
"LANGUE ALLEMANDE",
"TRADUCTION INTERPRETARIAT (ARABE, FRANCAIS, AMAZIGH)",
"JOURNALISME ET DES SCIENCES DE L INFORMATION",
"PHARMACIE",
"TRADUCTION INTERPRETARIAT (ARABE, FRANCAIS, ESPAGNOLE)",
"LANGUE RUSSE",
"OPTIQUE ET MECANIQUE DE PRECISION",
"INDUSTRIES PETROCHIMIQUES",
"GENIE MINIER",
"METALLURGIE",
"INGENIERIE DES TRANSPORTS",
"ELECTROMECANIQUE",
"HYDRAUCARBURES",
"HYGIENE ET SECURITE INDUSTRIELLE",
"GENIE MARITIME",
"AUTOMATIQUE",
"DES FORETS",
"HISTOIRE GEOGRAPHIE",
"MUSIQUE",
"PHILOSOPHIE"};
int s;
s=Alea(1,10);

strcpy(filiere,specialite[s-1]);
}*/


void Specialite(char* filiere){
char *specialite[]={"Informatique",
    "Architecture",
    "Medecine",
    "Veterinaire",
    "Pharmacie",
    "Mathematique",
    "Physique",
    "Medecine dentaire",
"Agriculture saharienne",
"Agronomie",
"Sciences et technologies",
"Sciences de la matiere",
"Sciences de la nature et de la vie",
"Sciences economoiques",
"Sciences politiques",
"Droit",
"Langue francaise",
"Langue anglaise",
"Sciences humaines",
"Sciences sociales",
"Sciences islamiques",
"Langue et litterature arabes",
"Sciences financieres et comptabilite",
"Genie civil",
"Travaux publics",
"Gestion des techniques urbaines",
"Geographie et amenagement du territoire",
"Geologie",
"Science des activites physiques et sportives",
"Telecommunications",
"Sciences alimentaires",
"Sciences de gestion",
"Droit public",
"Sciences veterinaires",
"Langue et culture amazighes",
"Traduction interpretariat",
"Hydraulique",
"Biotechnologie",
"Urabanisme",
"Aeronautique",
"Genie des procedes",
"Energies renouvelables",
"Electrotechnique",
"Genie macanique",
"Langue italienne",
"Management",
"Sciences appliquees",
"Genie industriel",
"Geniebiomedical",
"Langue espagnole",
"Arts",
"Metiers de la ville",
"Langue allmande",
"Microbiologie fondamentale et appliquée",
"Journalisme et sciences de l'information",
"Geophysique",
"Langue turque",
"Langue russe",
"Optique et macanique de precision",
"Industries petrochimiques",
"Genie minier",
"Metallurgie",
"Ingenierie des transports",
"Electromecanique",
"Hydraucarbures",
"Hygiene et securite industrielle",
"Genie maritime",
"Automatique",
"Forets",
"Histoire geographie",
"Musique",
"Philosophie"};
int s;
s=Alea(1,72);

strcpy(filiere,specialite[s-1]);
}

void Generer_Diplome(char* dernier_diplome ){
char *diplome[]={"Doctorat d Etat","Doctorat en sciences","Doctorat D-LMD","PhD","Habilitation Universitaire","Magistere"};
int d;
d=Alea(1,6);
strcpy(dernier_diplome,diplome[d-1]);
}

/*
void Generer_Etab(char *etab){

FILE *f;//fichier texte contenant les 112 etablissements
int num,i=1;
char chaine[256];
f=fopen("etablissements .txt","r");
//nb_etac=112(define)
num=Alea(1,nb_etab);//num=code de l'etablissement =numero de sa ligne dans le fichier etablissements.txt

while(i<=num && !feof(f)){
    fgets(chaine,sizeof(chaine),f);
    i++;
}
chaine[strlen(chaine)-1]=' ';//remplacer le \n par le blanc (pour l'affichage)
strcpy(etab,chaine);

fclose(f);
}

*/


void Generer_Etab(char *etab){
int num,i=1;
char chaine[256];
char *etablissment[]={"U.de Bouira-Akli Mohand Oulhadj",
"U.de Djelfa-Ziane Achour",
"U.de Ghardaia",
"U.de Khemis Miliana-Djilali Bounaama",
"U.Medea-Yahia Fares",
"U.des sciences et de la technologie d'Alger, Houari Boumediene",
"U.de Bejaia-Abderrahmane Mira",
"U.de Boumerdes-M'hamed Bougara",
"U.de Tizi Ouzou-Mouloud Maameri",
"U.de Laghouat-Amar Telidji",
"U.de Blida 1-Saad Dahlab",
"U.de Blida 2-Lounici Ali",
"U.d'Alger 1-Benyoucef Benkhedda",
"U.d'Alger 2-Abou el Kacem Saâdallah",
"U.d'Alger 3-Brahim Soltane Chaibout",
"U.de la Formation Continue",
"U.de Tamenghasset",
"E.N.Polytechnique",
"E.N.S.d'hydraulique-Arbaoui Abdellah",
"E.N.S.des travaux publics-Francis Jeanson",
"E.N.S.veterinaire-Rabie Bouchama",
"E.Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed",
"E.N.S.agronomique-Khalef Abdellah alias Kasdi Merbah",
"E.des hautes etudes commerciales",
"E.N.S.d'informatique",
"E.N.S.en statistique et en economie appliquee",
"E.S.de Commerce-Mouloud Kacem Nait Belkacem",
"E.N.S.des sciences de la mer et de l'amenagement du littoral",
"E.N.S.de management",
"E.N.S.de Technologie",
"E.N.S.de journalisme et des sciences de l'information",
"E.N.S.des sciences politiques",
"E.N.S.de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger",
"E.S.des Sciences appliquees d'Alger ex EP ST Alger",
"E.S.de Gestion et d'Economie Numerique",
"E.S.en Sciences et Technologies de l'Informatique et du Numerique de Bejaia",
"E.N.S.en Intelligence Artificielle",
"E.N.S.en Mathematique",
"E.N.S.de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili",
"E.N.S.de Kouba - Mohamed Bachir El Ibrahimi",
"E.N.S.de Laghouat - Taleb Abderrahmane",
"E.N.S.de sourds muets",
"C.U.de Tipaza - Abdallah Morsli",
"C.U.d'Illizi-Cheikh Amoud ben Mokhtar",
"C.U.d'Aflou",
"U.de Jijel - Mohammed Seddik Ben yahia",
"U.de Tebessa - Larbi Tebessi",
"U.de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi",
"U.d'El Tarf - Chadli Bendjedid",
"U.de Khenchela - Abbas Laghrour",
"U.de Oum El Bouaghi - Larbi Ben M'hidi",
"U.d'El Oued - Hamma Lakhdar",
"U.de Souk Ahras - Mohammed-Cherif Messaadia",
"U.de Annaba - Badji Mokhtar",
"U.du 20 Août 1955 de Skikda",
"U.8 Mai 1945 de Guelma",
"U.de Batna 1 - Hadj Lakhder",
"U.de Biskra - Mohamed Khider",
"U.de M'sila - Mohamed Boudiaf",
"U.de Ouargla - Kasdi Merbah",
"U.des sciences islamiques Emir Abdelkader de Constantine",
"U.de Setif 1 - Ferhat Abbas",
"U.de Setif 2 - Mohamed Lamine Debaghine",
"U.de Constantine 1 - Freres Mentouri",
"U.de Constantine 2 - Abdelhamid Mehri",
"U.de Constantine 3 -Salah Boubnider",
"U.de Batna 2 - Mustapha Ben Boulaid",
"E.N.S.des mines et de la metallurgie-Amar Laskri",
"E.N.Polytechnique de Constantine-Malek Bennabi",
"E.N.S.de Biotechnologie de Constantine-Tewfik Khaznadar",
"E.N.S.des Sciences de Gestion de Annaba ex-EPSECG Annaba",
"E.S.des Technologies Industrielles de Annaba ex EP ST Annaba",
"E.S.de Comptabilite et de Finance de Constantine ex EPSECG Constantine",
"E.N.S.des forets-Khenchela",
"E.N.S.des energies renouvelables, environnement et developpement durable - Batna",
"E.N.S.de Constantine-Assia Djebar",
"E.N.S.d'enseignement technologique de Skikda",
"E.N.S.de setif-Messaoud Zeghar",
"E.N.S.de Bou Saada",
"E.N.S.de Ouargla",
"C.U.de Mila-Abdelhafid Boussouf",
"C.U.de Barika-Si El Haoues",
"U.de Bechar-Mohamed Tahri",
"U.de Mascara-Mustapha Stambouli",
"U.de Saida-Tahar Moulay",
"U.de Tlemcen-Abou Bekr Belkaid",
"U.d'Adrar-Ahmed Draya",
"U.de Tiaret-Ibn Khaldoun",
"U.Sidi Bel Abbes-Djillali Liabes",
"U.de Mostaganem-Abdelhamid Ibn Badis",
"U.d'Oran1-Ahmed Ben Bella",
"U.Mohamed Boudiaf des sciences et de la technologie-Mohamed Boudiaf d'Oran",
"U.d'Oran 2-Mohamed Ben Ahmed",
"U.de Chlef-Hassiba Benbouali",
"U.de Tissemsilt",
"U.de Ain Temouchent",
"U.de Relizane",
"E.N.Polytechnique d'Oran - Maurice Audin",
"E.S.d'Informatique (Sidi Bel Abbes)- 08 Mai 1945",
"E.S.des Sciences Appliquees de Tlemcen ex EP ST Tlemcen",
"E.S.de Management de Tlemcen ex EPSECG Tlemcen",
"E.S.d'Economie d'Oran  ex EPSECG Oran",
"E.S.en Genie Electrique et Energetique d'Oran ex EP ST Oran",
"E.S.Agronomique de Mostaganem ex EP SNV Mostaganem",
"E.S.des sciences Biologiques d' Oran ex EP SNV Oran",
"E.N.S.de Mostaganem",
"E.N.S.d'Oran",
"E.N.S.de Bechar",
"C.U.de Naama-Ahmed Salhi",
"C.U.d'El Bayadh-Nour Bachir",
"C.U.de Tindouf-Ali Kafi",
"C.U.de Maghnia"};


//f=fopen("etablissements .txt","r");
//nb_etac=112(define)
num=Alea(1,nb_etab);//num=code de l'etablissement =numero de sa ligne dans le fichier etablissements.txt

strcpy(etab,etablissment[num-1]);
}

void Chargement_Init(int n,Tcouple *tab1,Tcouples2 *tab2,Tcouple_tabInd3 *tab3,int *nbre_liredire,int *nbre_ecriredire){
Tenreg e;
Tcouple cp;
Tadr adresse;
Tbloc buf;
*nbre_liredire=0;
*nbre_ecriredire=0;
FLNOF f;
Ouvrir(&f,"ENSEIGNANT-MESRS.bin",'N');

int  i=1,j=0,k,i_sauv;
int cpt=0;// le nombre de blocs da,s le fichier
char temp2[long_np],temp5[long_np],temp[long_np],temp7[long_np],temp6[long_np];
char temp1[4];
char temp3[long_max];
char temp4[long_wilaya];
int pos;
bool trouve,grade_correct=false;
maillon t,ptr,tmpt,p,q;
int a,w;//de 1 à nb_etab=112 , acces a tabInd3 ce fait : *(tabInd3+(a-1))=.....
//a=code de l'etablissement donc on fera un acces directe a sa position dans la table
//table d'index pour l'index1
//allocation de la table d'index selon le matricule a n case
                                // ((chaque case a un enregistrement  Tcouple(tab dynamique)

buf.prec=-1;
buf.suiv=-1;
srand(time(0));
for(k=1;k<=n;k++){

trouve=true;
while(trouve==true){
// Initialisation d'un enregistement
   e.Matricule=Mat_Alea();
  Rech_tab1(e.Matricule,tab1,(k-1),&trouve,&pos);


}
NomPrenom_Alea(temp2);
   strcpy(e.Nom,temp2);
   NomPrenom_Alea(temp5);
   strcpy(e.Prenom,temp5);
   e.Date_Naissance= Genrer_Date(1);
   Alea_Wilaya_Nais(temp4);
   strcpy(e.Wilaya_Naissance,temp4);
   e.Sexe=Sexe();
   Groupe_Sang(temp1);
   strcpy(e.Groupe_Sanguin,temp1);
   e.Date_Recrutement=Genrer_Date(2);
   grade_correct=false;
   while(grade_correct==false){
   Generer_Grade(temp7);
    grade_correct=controle_grade(temp7,e.Date_Naissance.Annee);
    if(grade_correct==false){
        grade_correct=false;
    }else{
      grade_correct=true;
    }
   }
   strcpy(e.Grade,temp7);
    Specialite(temp);
    strcpy(e.Specialite,temp);
    Generer_Diplome(temp6);
    strcpy(e.Dernier_Diplome,temp6);
    Generer_Etab(temp3);//a code de l'etablissemnt univ
    strcpy(e.Etablissement_Univ,temp3);

if (j<b){//---ajout d'un enreg
        //preparation de l'adresse de cet enreg
       adresse.numb=i;
        adresse.dep=j;
     //preparation du couple   (matricule,adresse) a mettre dans la table index1
       cp.cle=e.Matricule;
        cp.supp=false;
        cp.adresse=adresse;
    //ajout d'un couple (matricule,adresse) a la table d'indexe1

 Insertab1(tab1,k-1,pos,cp);
    /*inserer dans tab index3*/
a=Recuperer_code_etab(e.Etablissement_Univ);

          if((*(tab3+(a-1))).tete==NULL){
            //creation de la liste et affectation de la tete
            Allouer(&ptr);
            Aff_adr(&ptr,NULL);//initialement ptr est a NULL
            Aff_val(&ptr,e.Matricule);
            (*(tab3+(a-1))).tete=ptr;

            //printf("le numero du bloc=%d,la position =%d\n",(*(tab3+(a-1)).
          }else{
          //la liste existe donc ajout d'une nouvelle adresse càd nouveau maillon a la liste
          Allouer(&ptr);
          Aff_val(&ptr,e.Matricule);
          //on sauvgarde la tete
           tmpt=(*(tab3+(a-1))).tete;//mise a jour de la tete car on fait une insertion par la tete
          Aff_adr(&ptr,tmpt);
          (*(tab3+(a-1))).tete=ptr;
          }
    /*insertion dans la table index2*/
     w=Recuperer_code_Specialite(e.Specialite);

     if((*(tab2+(w-1))).tete==NULL){

         Allouer(&p);
         Aff_adr(&p,NULL);

         Aff_val(&p,e.Matricule);
        (*(tab2+(w-1))).tete=p;
         }else{
           Allouer(&p);
          Aff_val(&p,e.Matricule);
          q=(*(tab2+(w-1))).tete;
          Aff_adr(&p,q);
          (*(tab2+(w-1))).tete=p;
         }
    /******************************/
     buf.t[j]=e;
      j++;
}else{
if (i==1){
    Aff_Entete(&f,1,i);
}
 Aff_Entete(&f,2,i);
i_sauv=i;
i=AllocBloc(f);
buf.suiv=i;
buf.nb=j;
EcrireDir(&f,i_sauv,buf);
*(nbre_ecriredire)=(*nbre_ecriredire)+1;
cpt++;
buf.t[0]=e;
buf.prec=i_sauv;
        adresse.numb=i;
        adresse.dep=0;
        cp.cle=e.Matricule;
        cp.supp=false;
        cp.adresse=adresse;
 Insertab1(tab1,k-1,pos,cp);
/***************************************************************************/
  a=Recuperer_code_etab(e.Etablissement_Univ);
              t=(*(tab3+(a-1))).tete;//la tete de la liste des adresse des enreg qui ont un code_etab==a

          if((*(tab3+(a-1))).tete==NULL){
            //creation de la liste et affectation de la tete
            Allouer(&ptr);
            Aff_adr(&ptr,NULL);//initialement q est a NULL
            Aff_val(&ptr,e.Matricule);

            (*(tab3+(a-1))).tete=ptr;
          }else{
          //la liste existe donc ajout d'une nouvelle adresse càd nouveau maillon a la liste
          Allouer(&ptr);
          Aff_val(&ptr,e.Matricule);
          //on sauvgarde la tete

           tmpt=(*(tab3+(a-1))).tete;//mise a jour de la tete car on fait une insertion par la tete
          Aff_adr(&ptr,tmpt);
          (*(tab3+(a-1))).tete=ptr;
          }
    /*insertion dans la table index2*/
     w=Recuperer_code_Specialite(e.Specialite);

     if((*(tab2+(w-1))).tete==NULL){

         Allouer(&p);
         Aff_adr(&p,NULL);

         Aff_val(&p,e.Matricule);
        (*(tab2+(w-1))).tete=p;
         }else{
           Allouer(&p);
          Aff_val(&p,e.Matricule);
          q=(*(tab2+(w-1))).tete;
          Aff_adr(&p,q);
          (*(tab2+(w-1))).tete=p;
         }

        j=1;
        buf.suiv=-1;
}

}
if (i==1){
    Aff_Entete(&f,1,i);
}
buf.nb=j;
buf.suiv=-1;
EcrireDir(&f,i,buf);
*(nbre_ecriredire)=(*nbre_ecriredire)+1;
cpt++;
Aff_Entete(&f,2,i);
Aff_Entete(&f,3,n);
Aff_Entete(&f,4,cpt);

Fermer(f);
}


void Rech_tab1(int valeur, Tcouple *tab, int taille, bool *trouv, int *k)
{
    //valeur est le matricule=cle de recherche
    //tab la table d'index1
    //taille la taille de la table
    //k la position de la valeur si elle existe
    //sinon ou elle devra existe

     int bi = 0, bs = taille -1;
    (*trouv) = false;


    while ((bi<=bs) && (!(*trouv))){

        (*k) = (bi + bs) / 2;

        if (  (tab[(*k)]).cle== valeur)
        {
            *trouv = true;
        }
        else if (valeur <  (tab[(*k)]).cle )
        {
            bs = (*k) - 1;
        }
        else
        {
            bi = (*k) + 1;
        }
    }

    if (bi>bs)
    {
        (*k) = bi;
         (*trouv) = false;
    }
}

void Insertab1(Tcouple *tab,int taille,int pos,Tcouple e)
{
    int j;
    j=taille;

    while(j>pos){
        tab[j]=tab[j-1];
        j--;
    }
    tab[pos]=e;
}

void Affichage_Initial(FLNOF f,char *nom_fichier,int *nbre_liredire,int *nbre_ecriredire){
int i,j,cp=1;
int x,y;
Tbloc buf;
char chaine[20];
*nbre_liredire=0;
*nbre_ecriredire=0;
clrscr();
fichier_mesres();
printf("\n\n\n");
i=1;
if(Entete(f,3)!=0){
afficher_entete(f);
while (i!=-1){
    LireDire(f,i,&buf);
    *(nbre_liredire)=(*nbre_liredire)+1;
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

    textbackground(YELLOW);
    textcolor(BLACK);

y=wherey() ;
x=wherex();
gotoxy(x+5,y);
 printf("|==========================|\n");textbackground(WHITE);
   y=wherey() ;
 x=wherex();
gotoxy(x+5,y);
 textbackground(YELLOW);
printf("|Precedent: ");
gotoxy(17,y);printf("%3d",buf.prec);
gotoxy(17+3,y);printf("             |\n");textbackground(WHITE);

   y=wherey() ;
   x=wherex();
gotoxy(x+5,y);
textbackground(YELLOW);
 printf("|==========================|\n");
 textbackground(WHITE);
    textcolor(RED);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                V\n");sleep(1);
    textcolor(BLACK);
sleep(0);
printf(" |=========================================================================================================================================|\n");
textbackground(YELLOW);
textcolor(BLACK);

y=wherey() ;
x=wherex();
gotoxy(x+1,y);

printf("|    Numero du bloc: ");
gotoxy(22,y);printf("%3d",i);
gotoxy(25,y);printf("    |  Nombre d'enseigants: ");
gotoxy(52,y);printf("%4d",buf.nb);
gotoxy(56,y);printf("                                                                                    |\n");

textbackground(WHITE);

printf(" |=========================================================================================================================================|\n");
printf(" |                                                                                                                                         |\n");


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
    j=0;

    while(j<buf.nb){
            if(buf.t[j].Sexe==1){
                strcpy(chaine,"Masculin");
            }else{
             strcpy(chaine,"Feminin");
            }


printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");

y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");
gotoxy(x+4,y);
textbackground(LIGHTCYAN);
textcolor(RED);

printf("| Deplacement: ");
gotoxy(x+4+15,y);printf("%4d",j);
gotoxy(x+4+4+10+2+2+1,y);
printf("|            Champ              |                   Information                                                  |");


textbackground(WHITE);
gotoxy(x+137,y);
textcolor(BLACK);
printf("  |\n");
y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");

printf("  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");
textcolor(BLACK);
x=wherex();
printf(" |  |                  |< Matricule                   >|");
 y=wherey();
gotoxy(x+57,y);printf("%d",buf.t[j].Matricule);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
printf(" |  |                  |< Nom                         >|");
y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Nom);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Prenom                      >|");

y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Prenom);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
printf(" |  |                  |< Date de naissance           >|");
y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Naissance.Jour,buf.t[j].Date_Naissance.Mois,buf.t[j].Date_Naissance.Annee);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Wilaya de naissance         >|");

y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Wilaya_Naissance);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Sexe                        >|");
  y=wherey();
gotoxy(x+57,y);printf("%s",chaine);
gotoxy(x+123,y);printf("             |  |\n");
   x=wherex();

       printf(" |  |                  |< Groupe sanguin              >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Groupe_Sanguin);
gotoxy(x+123,y);printf("             |  |\n");
 x=wherex();

       printf(" |  |                  |< Date de recrutement         >|");

 y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Recrutement.Jour,buf.t[j].Date_Recrutement.Mois,buf.t[j].Date_Recrutement.Annee);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Grade                       >|");
 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Grade);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Specialite                  >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Specialite);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Dernier diplome             >|");
        y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Dernier_Diplome);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();


printf(" |  |                  |< Etablissement universitaire >|");
y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Etablissement_Univ);
gotoxy(x+123,y);printf("             |  |\n");

       printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");


    printf(" |                                                                                                                                         |\n");



        cp++;
        j++;
        if(j%10==0 && j!=buf.nb){
            system("pause");
        }
    }
    i=buf.suiv;


    //-----------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------

     printf(" |=========================================================================================================================================|\n");
       /*bloc suivant*/
       textbackground(WHITE);
    textcolor(RED);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                V\n");sleep(1);
     textbackground(YELLOW);
    textcolor(BLACK);
sleep(0);
y=wherey() ;
x=wherex();
gotoxy(x+4+28,y);
 printf("|==========================|\n");
   y=wherey() ;
 x=wherex();
gotoxy(x+4+28,y);
printf("|Suivant: ");
gotoxy(17-2+28,y);printf("%3d",buf.suiv);
gotoxy(17-2+3+28,y);printf("              |\n");

   y=wherey() ;
   x=wherex();
gotoxy(x+4+28,y);
 printf("|==========================|\n");

 textbackground(WHITE);
    textcolor(BLACK);
     printf("\n\n\n");


   system("pause");


    printf("\n\n\n");


//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

}

textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                      =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",(*nbre_liredire));
textcolor(BLUE);
printf("                                      =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_ecriredire));
}
else{
    printf(" --> Le fichier est vide\n");
}

}

/*********************** Modules sur le fichier d'index 1 (selon le matricule) **********************************/

// -1-Module de recherche (cle de recherche le matricule) dans le fichier d'index
// -2-Module de insertion (cle de recherche le matricule) dans le fichier d'index
// -3-Module de suppression logique (cle de recherche le matricule) dans le fichier d'index
// -4-Module de chargement du fichier d'index a partir de la table d'index


// 3-afficher le contenu du fichier d'index1
void Afficher_Index1(FICHTOF f,int *nbre_lireindex1,int *nbre_ecrireindex1)
{//le fichier est ouvert en main
int i,j;
*nbre_lireindex1=0;
*nbre_ecrireindex1=0;
TblocInd1 buf;
if(Entetetof(f,1)!=0){
printf("\n-->Le nombre d'enregistrement dans le fichier est:  %d\n\n",Entetetof(f,2));
printf("-->Le nombre de blocs dans le fichier est:  %d\n",Entetetof(f,1));
printf("-->Le nombre d'enregistrements supprime logiqueement dans le fichier est:  %d\n",f.entete.nbcouplesSupp);

printf("    |---------------------------------------------------------------------|\n");
printf("    | Entree  |     Matricule    | Efface |  Numero du bloc | Deplacement | \n");
printf("    |---------------------------------------------------------------------|\n");
//2eme façon d'afficher
i=1;//indice des bloc
while(i<=f.entete.nbBloc){
     LireDirtof(f,i,&buf);
     *(nbre_lireindex1)=(*nbre_lireindex1)+1;
        j=0;

        while(j<buf.nbcouples){


printf("    |  (%d,%d)  |      %d      |   %d    |         %d       |       %d     |\n",i,j,buf.Tabcouples[j].cle,buf.Tabcouples[j].supp,buf.Tabcouples[j].adresse.numb,buf.Tabcouples[j].adresse.dep);

          j++;
        }

    i++;
}
textcolor(BLUE);
printf("\n\n     Le cout total de cette procedure :\n");
printf("                                          =>Le nombre de Liredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_lireindex1));
textcolor(BLUE);
printf("                                          =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d",(*nbre_ecrireindex1));

}

else{
    printf("  --> Le fichier index1 est vide \n");
}
}
/*******************  Modules sur le fichier d'index 2 (selon le code de la specialite) *****************************/

void EcrireDir_Ind2(FLNOF *f,int i,Tbloc2_index2 buf){
    rewind((*f).fich);
    fseek((*f).fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc2_index2))),SEEK_SET);
    fwrite(&buf,sizeof(Tbloc2_index2),1,(*f).fich);
}
void LireDire_Ind2(FLNOF f,int i, Tbloc2_index2 *buf){
rewind(f.fich);
fseek(f.fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc2_index2))),SEEK_SET);
fread(&(*buf),sizeof(Tbloc2_index2),1,f.fich);
}
void EcrireDirtof_Ind2(FICHTOF *F,int i,Tbloc1_index2 buf){

    //deplacement a la position i
    rewind((*F).fich);
    fseek((*F).fich,((i-1)*sizeof(Tbloc1_index2)+sizeof(TEnteteInd)),SEEK_SET);
    //ecriture
    fwrite(&buf,sizeof(Tbloc1_index2),1,(*F).fich);


}
/*Lecture du bloc numéro i de F dans la variable buf*/
void LireDirtof_Ind2(FICHTOF F,int i,Tbloc1_index2 *buf){
 rewind(F.fich);
  fseek(F.fich,((i-1)*sizeof(Tbloc1_index2)+sizeof(TEnteteInd)),SEEK_SET);
  fread(buf,sizeof(Tbloc1_index2),1,F.fich);
}


void charger_index2_specialite(FICHTOF* f1,Tcouples2 *tabIndex2,FLNOF* f2,int *nbre_lireindex2,int *nbre_ecrireindex2){

int i,i1,i2,j,k,i_sauv2,cpt=0;
Tbloc1_index2 buf1;
Tbloc2_index2 buf2;
int nb_adresse;
*nbre_lireindex2=0;
*nbre_ecrireindex2=0;
maillon pt;
Tcouple3 e;
bool debut;//indiquera le debut d'une liste d'adresse (nouvelle liste de blocs dans f32)
//DEBUT



j=0;//j est utilisé pour parcourir les enregistrements des blocs de f1
i1=1;// i1 est utilisé pour parcourir les blocs de f1
i2=1;// i2 est utilisé pour parcourir les blocs de f2
// i est utilisé pour parcourir le tableau index2 dans la memoire centrale

for (i=0;i<72;i++){
        buf1.tab1[j].Code_Specialite=(*(tabIndex2+(i))).Code_spe;

        buf1.tab1[j].supp=false;
        pt=(*(tabIndex2+(i))).tete;

      if(pt==NULL){
         buf1.tab1[j].tete=-1;// ya pas de liste bloc
         buf1.tab1[j].nb_adr=0;// y a aucune adresse qui a code_etab comme etablissement

      }
      else{
           k=0;
           debut=true;//debut d'une nouvelle liste
          nb_adresse=0;
           pt=(*(tabIndex2+(i))).tete;

        while(pt!=NULL){

            nb_adresse++;
            e.mat=(pt->mat);
            e.efface=false;

           if(k<b){
            buf2.tab2[k]=e;
            k++;

           }
           else{
            //le buf2 est plein

            buf2.nbe=b;
            i_sauv2=i2;

            if(i1==1 && i2==1){
                Aff_Entete(&(*f2),1,i2);
                 Aff_Entete(&(*f2),2,i2);
                 }

            //la tete de la liste
            if(debut==true){
                buf1.tab1[j].tete=i2;//la tete de la liste (numero du premier bloc de cette liste)
                debut=false;
            }
            i2=AllocBloc((*f2));

            Aff_Entete(&(*f2),2,i2);//mise a jour de la queue
            buf2.suiv=i2;
            EcrireDir_Ind2(&(*f2),i_sauv2,buf2);
            *(nbre_ecrireindex2)=(*nbre_ecrireindex2)+1;
            buf2.tab2[0]=e;
            buf2.suiv=-1;
            k=1;
            cpt++;
           }

              pt=Suivant(pt);
        }//orange
        buf1.tab1[j].nb_adr=nb_adresse;
        if(debut==true){
            buf1.tab1[j].tete=i2;
            debut=false;
            if(i1==1 && i2==1 ){
                Aff_Entete(&(*f2),1,i2);
                Aff_Entete(&(*f2),2,i2);
            }
        }
        //ecriture du dernier buf (la queue d'une liste)
        buf2.nbe=k;
        buf2.suiv=-1;//car ce buffer represente la queue d'une liste
        EcrireDir_Ind2(&(*f2),i2,buf2);
                  *(nbre_ecrireindex2)=(*nbre_ecrireindex2)+1;


        if(i<72){
            i2=AllocBloc(*f2);

            Aff_Entete(&(*f2),2,i2);//mise a jour de la queue du fichier f2
            buf2.suiv=-1;
             }
         }

      //le parcour dans f31
      if(j<(m1-1)){
        j=j+1;

      }else{
      //j1==m-1 => buf1 est plein
      buf1.nbe=m1;
      EcrireDirtof_Ind2(&(*f1),i1,buf1);
                  *(nbre_ecrireindex2)=(*nbre_ecrireindex2)+1;

      i1=i1+1;
      j=0;
      }

}
//ecriture du dernier buffer du fichier f31

if(j!=0){
    buf1.nbe=j;
    EcrireDirtof_Ind2(&(*f1),i1,buf1);
                *(nbre_ecrireindex2)=(*nbre_ecrireindex2)+1;

}

//les entetes des fichiers f31 et f32
//1)- sur le fichier f31(tof)
Aff_entetetof(&(*f1),1,i1);//nombre de bloc;
Aff_entetetof(&(*f1),2,72);//nombre d'enregistrement (chaque etablissement est un enreg) ;
Aff_entetetof(&(*f1),3,0);//initialement au chargement ils sont tous

//2)-sur le fichier des adresses f32(lnof)
Aff_Entete(&(*f2),4,i2);//nombre de blocs;
Aff_Entete(&(*f2),3,cpt);//nombre d'enregistremement dans tout le fichiers;

fermertof(*f1);
Fermer(*f2);

}



//-2- module de creation du fichier d'index 1 (cle=matricule) a partir de la table d'index allouee en MC
void Charger_index1(FICHTOF *f,int n,Tcouple *tab,int *nbre_lireindex1,int *nbre_ecrireindex1 ){
    //n est la taille de la table etegalement le nombre d'enregistrement qui seront insere dans le fichier index
    //parcourir la table d'indexe (tableau de Tcouple)
    //remplir buf l'ecrire dans le fichier f s'il est plein
    //la table d'indexe est ordonnee


     //variables
    int i,j,k,cpt;//i=> indice des blocs, j=>indice de la donnee dans le tableau, k=>comptage du nombre d'enregistrement ecrits
    TblocInd1 buf;
    Tcouple d;//la donnee(information)
    *nbre_lireindex1=0;
    *nbre_ecrireindex1=0;

cpt=0;//pour compter le nombre d'enregistrements(tcouple) supprime
  i=1;
  j=0;
  //la table a n cases => n enregsitrements
  if(n!=0){
  for(k=1;k<=n;k++){

    //lire la donnee a partir de la table  d'index allouee en MC
    d=(*(tab+(k-1)));

   if(j<b1){//on n'a pas etteint le nombre maximal d'enregistrements (tableau pas 100% rempli )
    //affecter la donnee dans le tableau
    if(d.supp==true){cpt=cpt+1;}
    buf.Tabcouples[j]=d;

    j++;

   }
   else{
        buf.nbcouples=j;//nombre d'enregistrements dans le buf
        EcrireDirtof(&(*f),i,buf);
        *(nbre_ecrireindex1)=(*nbre_ecrireindex1)+1;
        i++;
        if(d.supp==true){cpt=cpt+1;}
        buf.Tabcouples[0]=d; //car on a lu une donnee et le bloc i-1 est plein donc il faut la mettre dans le prochain bloc i*/
        j=1;//car la prochaine donnee a lire sera la 2eme dans le bloc i
        }
}
//le dernier bloc
buf.nbcouples=j;
EcrireDirtof(&(*f),i,buf);
        *(nbre_ecrireindex1)=(*nbre_ecrireindex1)+1;

Aff_entetetof(&(*f),1,i);//nb bloc
Aff_entetetof(&(*f),2,n);//nb enreg
Aff_entetetof(&(*f),3,cpt);//initialement le nombre d'enreg supprimes logiquement =0

}
}


/*******************  Modules sur le fichier d'index 3 (selon le code des etablissement universitaires) *************/
//les modules ecriredir et liredir vont changer car meme si le fichier des adresses est organise en fnof
//mais la structure de l'enregistrement a change
//donc ouvrire et fermer et aff_entete et entete ne changent pas sauf ecriredir et liredir
void EcrireDir_Ind3(FLNOF *f,int i,Tbloc2_index3 buf){
    rewind((*f).fich);
    fseek((*f).fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc2_index3))),SEEK_SET);
    fwrite(&buf,sizeof(Tbloc2_index3),1,(*f).fich);
}

void LireDire_Ind3(FLNOF f,int i, Tbloc2_index3 *buf){
rewind(f.fich);
fseek(f.fich,(sizeof(TEntete)+((i-1)*sizeof(Tbloc2_index3))),SEEK_SET);
fread(&(*buf),sizeof(Tbloc2_index3),1,f.fich);
}
void EcrireDirtof_Ind3(FICHTOF *F,int i,Tbloc1_index3 buf){

    //deplacement a la position i
    rewind((*F).fich);
    fseek((*F).fich,((i-1)*sizeof(Tbloc1_index3)+sizeof(TEnteteInd)),SEEK_SET);
    //ecriture
    fwrite(&buf,sizeof(Tbloc1_index3),1,(*F).fich);


}
/*Lecture du bloc numéro i de F dans la variable buf*/
void LireDirtof_Ind3(FICHTOF F,int i,Tbloc1_index3 *buf){
 rewind(F.fich);
  fseek(F.fich,((i-1)*sizeof(Tbloc1_index3)+sizeof(TEnteteInd)),SEEK_SET);
  fread(buf,sizeof(Tbloc1_index3),1,F.fich);
}


void Charger_index3(FICHTOF *f31,FLNOF *f32,Tcouple_tabInd3 *tab,int *nbre_lireindex3,int *nbre_ecrireindex3){

// le fichier index 3 est compose de 2 fichier
//un fichier de structure TOF f31
//un fichier de structure LnOF f32 comme un fichier en zone de debordement
//f32 contiendra plusieurs listes (listes de bloc) chaque liste i correspond a une liste d'adreese de la cle i
//car l'attribut de cet index est une cle a valeur non unique (le code de l'etablissemnt)
/*variables*/
int i1,j1;//pour f31
int i2,i2_sauv,j2;//pour f32;
int k;//le parcour de la table d'index en entree
int cpt;
int nb_adresse;
maillon ptr;
Tdonnee donnee;
*nbre_lireindex3=0;
*nbre_ecrireindex3=0;
bool debut;//indiquera le debut d'une liste d'adresse (nouvelle liste de blocs dans f32)
Tbloc1_index3 buf1;//buffer pour le fichier f31 (tof)
Tbloc2_index3 buf2;//buffer pour le fichier f32 (lnof)
int d;
/*debuut*/
i1=1;
i2=1;
j1=0;
cpt=0;
Allouer(&ptr);

for(k=1;k<=nb_etab;k++){

        buf1.tab1[j1].Code_Etab_Univ= (*(tab+(k-1))).code_etab;
        buf1.tab1[j1].supp= false;//etablissement non suprrime
      //maintenat, on paroucure la liste du des adresses
      ptr=(*(tab+k-1)).tete;
      if(ptr==NULL){

         buf1.tab1[j1].tete=-1;// ya pas de liste bloc
         buf1.tab1[j1].nb_adr=0;// y a aucune adresse qui a code_etab comme etablissement

      }
      else{

            j2=0;
           debut=true;//debut d'une nouvelle liste
          nb_adresse=0;
        while(ptr!=NULL){

            nb_adresse++;
            d=Valeur(ptr);
            donnee.mat=d;
           donnee.efface=false;
           if(j2<b){
            buf2.tab2[j2]=donnee;
            j2++;
           }
           else{
            //le buf2 est plein
            buf2.nbe=b;
            i2_sauv=i2;
            //la tete du fichier des adresses f32 est la tete de la premiere liste du fichier
            //sa queue est le queue de la derniere liste du fichier
            if(i1==1 && i2==1){
                Aff_Entete(&(*f32),1,i2);
                Aff_Entete(&(*f32),2,i2);
            }
            //la tete de la liste
            if(debut==true){
                buf1.tab1[j1].tete=i2;//la tete de la liste (numero du premier bloc de cette liste)
                debut=false;
            }
            i2=AllocBloc((*f32));
            Aff_Entete(&(*f32),2,i2);//mise a jour de la queue

            buf2.suiv=i2;
            EcrireDir_Ind3(&(*f32),i2_sauv,buf2);
            *(nbre_ecrireindex3)=(*nbre_ecrireindex3)+1;
            buf2.tab2[0]=donnee;
            buf2.suiv=-1;
            j2=1;
            cpt++;
           }
           ptr=Suivant(ptr);
        }//orange
          buf1.tab1[j1].nb_adr=nb_adresse;
        if(debut==true){
            buf1.tab1[j1].tete=i2;
            debut=false;
            if(i1==1 && i2==1){
                Aff_Entete(&(*f32),1,i2);
                Aff_Entete(&(*f32),2,i2);
            }

        }
        //ecriture du dernier buf (la queue d'une liste)
        buf2.nbe=j2;
        buf2.suiv=-1;//car ce buffer represente la queue d'une liste
        EcrireDir_Ind3(&(*f32),i2,buf2);
                    *(nbre_ecrireindex3)=(*nbre_ecrireindex3)+1;

        if(k<nb_etab){
            i2=AllocBloc(*f32);
            Aff_Entete(&(*f32),2,i2);//mise a jour de la queue du fichier f32
            buf2.suiv=-1;
        }

      }

      //le parcour dans f31
      if(j1<(m-1)){
        j1=j1+1;

      }else{
      //j1==m-1 => buf1 est plein
      buf1.nbe=m;
      EcrireDirtof_Ind3(&(*f31),i1,buf1);
                  *(nbre_ecrireindex3)=(*nbre_ecrireindex3)+1;

      i1=i1+1;
      j1=0;
      }

}
//ecriture du dernier buffer du fichier f31

if(j1!=0){
    buf1.nbe=j1;
    EcrireDirtof_Ind3(&(*f31),i1,buf1);
                *(nbre_ecrireindex3)=(*nbre_ecrireindex3)+1;

}
//les entetes des fichiers f31 et f32
//1)- sur le fichier f31(tof)
Aff_entetetof(&(*f31),1,i1);//nombre de bloc;
Aff_entetetof(&(*f31),2,nb_etab);//nombre d'enregistrement (chaque etablissement est un enreg) ;
Aff_entetetof(&(*f31),3,0);//initialement au chargement ils sont tous

//2)-sur le fichier des adresses f32(lnof)
Aff_Entete(&(*f32),4,i2);//nombre de blocs;
Aff_Entete(&(*f32),3,cpt);//nombre d'enregistremement dans tout le fichiers;
fermertof(*f31);
Fermer(*f32);

}
void Afficher_Index3(FICHTOF f31,FLNOF f32,int *nbre_lireindex3,int *nbre_ecrireindex3){
int n;
int code,nb_ad,bloctete;
int i1=1,i2,j1,j2;
*nbre_lireindex3=0;
*nbre_ecrireindex3=0;
 Tbloc1_index3 buf1;
 Tbloc2_index3 buf2;
 n=Entetetof(f31,1);//nombre de blocs
 printf("   ______________________________________________________________________________________________________________________\n");
 printf("   | Entree dans l'index |  Code de l'etablissement  |  Nombre d'adresses  | Numero du bloc tete  | Etablissement efface |\n");
 printf("   |_____________________|___________________________|_____________________|______________________|______________________|\n");
 while(i1<=n){

        LireDirtof_Ind3(f31,i1,&buf1);
        *(nbre_lireindex3)=(*nbre_lireindex3)+1;
       j1=0;
       while(j1<buf1.nbe){
        code=buf1.tab1[j1].Code_Etab_Univ;
        nb_ad=buf1.tab1[j1].nb_adr;
        bloctete=buf1.tab1[j1].tete;


 printf("   ______________________________________________________________________________________________________________________\n");
 printf("   |   (%d,%d)           |          %d               |  %d                 |       %d             |        %d            |\n",i1,j1,code,nb_ad,bloctete,buf1.tab1[j1].supp);
 printf("   |___________________|____________________________|_____________________|______________________|______________________|\n");
if(bloctete==-1){
    printf("      ---->> | -1  |\n\n");
}else{
//on parcoure la liste des bloc qui represnetent la lsite des adresses
i2=bloctete;
printf("      ---->> La liste des adresses \n\n");
printf("           |                                                    |   Effacee   |\n");
while(i2!=-1){
    LireDire_Ind3(f32,i2,&buf2);
            *(nbre_lireindex3)=(*nbre_lireindex3)+1;

    j2=0;
    while(j2<buf2.nbe){

        printf("          |                         %d                        |       %d     |\n", buf2.tab2[j2].mat,buf2.tab2[j2].efface);
        j2++;
    }
    i2=buf2.suiv;
}
}
 j1++;}
i1++;}
textcolor(BLUE);
printf("\n\n     Le cout total de cette procedure :\n");
printf("                                          =>Le nombre de Liredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_lireindex3));
textcolor(BLUE);
printf("                                          =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d",(*nbre_ecrireindex3));


}


int Recuperer_code_etab(char *etab){
char *etablissment[]={"U.de Bouira-Akli Mohand Oulhadj",
"U.de Djelfa-Ziane Achour",
"U.de Ghardaia",
"U.de Khemis Miliana-Djilali Bounaama",
"U.Medea-Yahia Fares",
"U.des sciences et de la technologie d'Alger, Houari Boumediene",
"U.de Bejaia-Abderrahmane Mira",
"U.de Boumerdes-M'hamed Bougara",
"U.de Tizi Ouzou-Mouloud Maameri",
"U.de Laghouat-Amar Telidji",
"U.de Blida 1-Saad Dahlab",
"U.de Blida 2-Lounici Ali",
"U.d'Alger 1-Benyoucef Benkhedda",
"U.d'Alger 2-Abou el Kacem Saâdallah",
"U.d'Alger 3-Brahim Soltane Chaibout",
"U.de la Formation Continue",
"U.de Tamenghasset",
"E.N.Polytechnique",
"E.N.S.d'hydraulique-Arbaoui Abdellah",
"E.N.S.des travaux publics-Francis Jeanson",
"E.N.S.veterinaire-Rabie Bouchama",
"E.Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed",
"E.N.S.agronomique-Khalef Abdellah alias Kasdi Merbah",
"E.des hautes etudes commerciales",
"E.N.S.d'informatique",
"E.N.S.en statistique et en economie appliquee",
"E.S.de Commerce-Mouloud Kacem Nait Belkacem",
"E.N.S.des sciences de la mer et de l'amenagement du littoral",
"E.N.S.de management",
"E.N.S.de Technologie",
"E.N.S.de journalisme et des sciences de l'information",
"E.N.S.des sciences politiques",
"E.N.S.de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger",
"E.S.des Sciences appliquees d'Alger ex EP ST Alger",
"E.S.de Gestion et d'Economie Numerique",
"E.S.en Sciences et Technologies de l'Informatique et du Numerique de Bejaia",
"E.N.S.en Intelligence Artificielle",
"E.N.S.en Mathematique",
"E.N.S.de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili",
"E.N.S.de Kouba - Mohamed Bachir El Ibrahimi",
"E.N.S.de Laghouat - Taleb Abderrahmane",
"E.N.S.de sourds muets",
"C.U.de Tipaza - Abdallah Morsli",
"C.U.d'Illizi-Cheikh Amoud ben Mokhtar",
"C.U.d'Aflou",
"U.de Jijel - Mohammed Seddik Ben yahia",
"U.de Tebessa - Larbi Tebessi",
"U.de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi",
"U.d'El Tarf - Chadli Bendjedid",
"U.de Khenchela - Abbas Laghrour",
"U.de Oum El Bouaghi - Larbi Ben M'hidi",
"U.d'El Oued - Hamma Lakhdar",
"U.de Souk Ahras - Mohammed-Cherif Messaadia",
"U.de Annaba - Badji Mokhtar",
"U.du 20 Août 1955 de Skikda",
"U.8 Mai 1945 de Guelma",
"U.de Batna 1 - Hadj Lakhder",
"U.de Biskra - Mohamed Khider",
"U.de M'sila - Mohamed Boudiaf",
"U.de Ouargla - Kasdi Merbah",
"U.des sciences islamiques Emir Abdelkader de Constantine",
"U.de Setif 1 - Ferhat Abbas",
"U.de Setif 2 - Mohamed Lamine Debaghine",
"U.de Constantine 1 - Freres Mentouri",
"U.de Constantine 2 - Abdelhamid Mehri",
"U.de Constantine 3 -Salah Boubnider",
"U.de Batna 2 - Mustapha Ben Boulaid",
"E.N.S.des mines et de la metallurgie-Amar Laskri",
"E.N.Polytechnique de Constantine-Malek Bennabi",
"E.N.S.de Biotechnologie de Constantine-Tewfik Khaznadar",
"E.N.S.des Sciences de Gestion de Annaba ex-EPSECG Annaba",
"E.S.des Technologies Industrielles de Annaba ex EP ST Annaba",
"E.S.de Comptabilite et de Finance de Constantine ex EPSECG Constantine",
"E.N.S.des forets-Khenchela",
"E.N.S.des energies renouvelables, environnement et developpement durable - Batna",
"E.N.S.de Constantine-Assia Djebar",
"E.N.S.d'enseignement technologique de Skikda",
"E.N.S.de setif-Messaoud Zeghar",
"E.N.S.de Bou Saada",
"E.N.S.de Ouargla",
"C.U.de Mila-Abdelhafid Boussouf",
"C.U.de Barika-Si El Haoues",
"U.de Bechar-Mohamed Tahri",
"U.de Mascara-Mustapha Stambouli",
"U.de Saida-Tahar Moulay",
"U.de Tlemcen-Abou Bekr Belkaid",
"U.d'Adrar-Ahmed Draya",
"U.de Tiaret-Ibn Khaldoun",
"U.Sidi Bel Abbes-Djillali Liabes",
"U.de Mostaganem-Abdelhamid Ibn Badis",
"U.d'Oran1-Ahmed Ben Bella",
"U.Mohamed Boudiaf des sciences et de la technologie-Mohamed Boudiaf d'Oran",
"U.d'Oran 2-Mohamed Ben Ahmed",
"U.de Chlef-Hassiba Benbouali",
"U.de Tissemsilt",
"U.de Ain Temouchent",
"U.de Relizane",
"E.N.Polytechnique d'Oran - Maurice Audin",
"E.S.d'Informatique (Sidi Bel Abbes)- 08 Mai 1945",
"E.S.des Sciences Appliquees de Tlemcen ex EP ST Tlemcen",
"E.S.de Management de Tlemcen ex EPSECG Tlemcen",
"E.S.d'Economie d'Oran  ex EPSECG Oran",
"E.S.en Genie Electrique et Energetique d'Oran ex EP ST Oran",
"E.S.Agronomique de Mostaganem ex EP SNV Mostaganem",
"E.S.des sciences Biologiques d' Oran ex EP SNV Oran",
"E.N.S.de Mostaganem",
"E.N.S.d'Oran",
"E.N.S.de Bechar",
"C.U.de Naama-Ahmed Salhi",
"C.U.d'El Bayadh-Nour Bachir",
"C.U.de Tindouf-Ali Kafi",
"C.U.de Maghnia"};

int i=0;
bool trouv=false;
while ((trouv==false)&&(i<111)){
     if (strcmp(etablissment[i],etab)==0){
        trouv=true ;
    }else{
    i++;
    }
}
return (i+1);
}


int Recuperer_code_Specialite(char *Specialite){
char *specialite[]={"Informatique",
    "Architecture",
    "Medecine",
    "Veterinaire",
    "Pharmacie",
    "Mathematique",
    "Physique",
    "Medecine dentaire",
"Agriculture saharienne",
"Agronomie",
"Sciences et technologies",
"Sciences de la matiere",
"Sciences de la nature et de la vie",
"Sciences economoiques",
"Sciences politiques",
"Droit",
"Langue francaise",
"Langue anglaise",
"Sciences humaines",
"Sciences sociales",
"Sciences islamiques",
"Langue et litterature arabes",
"Sciences financieres et comptabilite",
"Genie civil",
"Travaux publics",
"Gestion des techniques urbaines",
"Geographie et amenagement du territoire",
"Geologie",
"Science des activites physiques et sportives",
"Telecommunications",
"Sciences alimentaires",
"Sciences de gestion",
"Droit public",
"Sciences veterinaires",
"Langue et culture amazighes",
"Traduction interpretariat",
"Hydraulique",
"Biotechnologie",
"Urabanisme",
"Aeronautique",
"Genie des procedes",
"Energies renouvelables",
"Electrotechnique",
"Genie macanique",
"Langue italienne",
"Management",
"Sciences appliquees",
"Genie industriel",
"Geniebiomedical",
"Langue espagnole",
"Arts",
"Metiers de la ville",
"Langue allmande",
"Microbiologie fondamentale et appliquée",
"Journalisme et sciences de l'information",
"Geophysique",
"Langue turque",
"Langue russe",
"Optique et macanique de precision",
"Industries petrochimiques",
"Genie minier",
"Metallurgie",
"Ingenierie des transports",
"Electromecanique",
"Hydraucarbures",
"Hygiene et securite industrielle",
"Genie maritime",
"Automatique",
"Forets",
"Histoire geographie",
"Musique",
"Philosophie"};
int i=0;
bool trouv=false;
while ((trouv==false)&&(i<71)){
    if (strcmp(specialite[i],Specialite)==0){
        trouv=true;
    }else{
    i++;
    }
}
return (i+1);
}

// Ce module est utilisé pour faire l'ecrasement lors la suppression dans le fichier selon le matricule

void Ecraser_mat(FLNOF *f,Tadr adresse,int *mat_ecrasant,int *nbre_liredire,int *nbre_ecriredire){
//Variables:
Tbloc buf3,buf4;
bool ecriture=false;
int tmp;// pour sauvegarder le precedent du bloc

  if (Entete(*f,4)==1){      //s'il ya un seul bloc dans le fichier
   LireDire((*f),1,&buf3); //1=adresse.numb
   *(nbre_liredire)=(*nbre_liredire)+1;

  if (buf3.nb==1){
 // s'il y a un seul enregistrement il suffit juste de mettre a jour l'entete du fichier sans reecrire le bloc car il devient vide
        Aff_Entete(&(*f),1,-1);
        Aff_Entete(&(*f),2,-1);
        Aff_Entete(&(*f),4,Entete((*f),4)-1);
        //apres la suppression le bloc devient vide
    }else{

        // s'il ya plusieurs enregistrements dans le seul bloc du fichier
      if (adresse.dep!=buf3.nb-1){
       buf3.t[adresse.dep]=buf3.t[buf3.nb-1];
       }
       //sinon l'enreg a supprime est le dernier de ce buf alors il suffira de decrementer son nombre d'enrg
      (*mat_ecrasant)= buf3.t[buf3.nb-1].Matricule;
      buf3.nb--;
      EcrireDir(&(*f),1,buf3);
      *(nbre_ecriredire)=(*nbre_ecriredire)+1;
    }

}else{
// le nombre du blocs est superieur a 1
if(adresse.numb==Entete(*f,2)){//le suppression se fait dans la dernier bloc du fichier (queue)
LireDire(*f,Entete(*f,2),&buf4);
   *(nbre_liredire)=(*nbre_liredire)+1;

if(adresse.dep!=buf4.nb-1){

     (*mat_ecrasant)=buf4.t[buf4.nb-1].Matricule;
    }
    buf4.t[adresse.dep]=buf4.t[buf4.nb-1];
   buf4.nb--;
//on decremente le nombre d'enreg dans le fichier
   if(buf4.nb==0){
//si le bloc se vide
//1-on doit mettre a jour la queue qui devient le bloc precedent
    Aff_Entete(&(*f),4,Entete(*f,4)-1);
    Aff_Entete(&(*f),2,buf4.prec);
    tmp=buf4.prec;
    LireDire(*f,buf4.prec,&buf4);// on doit mettre a jour le bloc precedent(qui est devenu la queue) en changeant son suivant
      *(nbre_liredire)=(*nbre_liredire)+1;

    buf4.suiv=-1;
    EcrireDir(&(*f),tmp,buf4);//recriture du precedent qui est devenu la queue du fichier
          *(nbre_ecriredire)=(*nbre_ecriredire)+1;

    } else{

     EcrireDir(&(*f),Entete(*f,2),buf4);
          *(nbre_ecriredire)=(*nbre_ecriredire)+1;

      }
}else{

LireDire(*f,adresse.numb,&buf3);//lecture du bloc ou se fera l'ecrasement d'un enreg
   *(nbre_liredire)=(*nbre_liredire)+1;

LireDire(*f,Entete(*f,2),&buf4);//lecture de la queue
   *(nbre_liredire)=(*nbre_liredire)+1;

buf3.t[adresse.dep]=buf4.t[buf4.nb-1];
(*mat_ecrasant)=buf4.t[buf4.nb-1].Matricule;
buf4.nb--;


   if(buf4.nb==0){
//si le bloc se vide
//1-on doit mettre a jour la queue qui devient le bloc precedent
    Aff_Entete(&(*f),4,Entete(*f,4)-1);
    Aff_Entete(&(*f),2,buf4.prec);//la queue devient le precedent bloc de la queue actuelle
    tmp=buf4.prec;//on sauvgarde le numero du precedent
    LireDire(*f,buf4.prec,&buf4);// on doit mettre a jour le bloc precedent(qui est devenu la queue) en changeant son suivant
     *(nbre_liredire)=(*nbre_liredire)+1;

    buf4.suiv=-1;
    if(tmp==adresse.numb){
        EcrireDir(&(*f),adresse.numb,buf4);
           *(nbre_ecriredire)=(*nbre_ecriredire)+1;

        ecriture=true;//si ecriture=vrai cela veut dire que c'est pas la peine de reecrire buf3 car buf3=buf4
    }else{
      //buf3<>buf4
    EcrireDir(&(*f),tmp,buf4);
          *(nbre_ecriredire)=(*nbre_ecriredire)+1;

    }

   }else{

     EcrireDir(&(*f),Entete(*f,2),buf4);
          *(nbre_ecriredire)=(*nbre_ecriredire)+1;


   }
    if (ecriture==false ){
        EcrireDir(&(*f),adresse.numb,buf3);
             *(nbre_ecriredire)=(*nbre_ecriredire)+1;

    }
}
}
Aff_Entete(&(*f),3,Entete(*f,3)-1);


}


void Liberer_tab2(Tcouples2 *tab2){
 maillon p,q;
 int i;
 for(i=0;i<72;i++){
    p=(*(tab2+i)).tete;

    while(p!=NULL){
        q=Suivant(p);
        free(p);
        p=q;

    }
 }
  }

void Liberer_tab3(Tcouple_tabInd3 *tab3){
 maillon p,q;
 int i;
 for(i=0;i<112;i++){
    p=(*(tab3+i)).tete;
   while(p!=NULL){
        q=Suivant(p);
        free(p);
        p=q;

    }
 }

   }

   /****** Module de suppression d'un enregistrement "enseignant" donne par le matricule *****/
   //fonction1: remplir la table d'index1 a partir du fichier index1 (car les manipulation sont en MC)

void RemplirTab1(FICHTOF f,Tcouple *tab1,int taille,int *nbre_lireindex1,int *nbre_ecrireindex1){

    int i,j,k;
    TblocInd1 buf;
i=1;
k=0;
*nbre_lireindex1=0;
*nbre_ecrireindex1=0;
while(i<=Entetetof(f,1)){
    LireDirtof(f,i,&buf);
    *nbre_lireindex1++;
    j=0;
    while(j<buf.nbcouples){


        tab1[k]=buf.Tabcouples[j];

        j++;
        k++;
}
    i=i+1;
}

}
//fonction2: remplir la table d'index2
void RemplirTab2(FICHTOF f21,FLNOF f22,Tcouples2 *tab2,int *nbre_lireindex2,int *nbre_ecrireindex2)
{
 Tbloc1_index2 buf1;
 Tbloc2_index2 buf2;
 maillon p,q;
 int i2,j,j2,code;
 *nbre_lireindex2=0;
 *nbre_ecrireindex2=0;
LireDirtof_Ind2(f21,1,&buf1);
*nbre_lireindex2++;
j=0;

while(j<buf1.nbe){
    if(buf1.tab1[j].tete!=-1){
            code=buf1.tab1[j].Code_Specialite;

            i2=buf1.tab1[j].tete;

            /****** Remplissage d'une liste d'adresse ******/
            while(i2!=-1){

                j2=0;
                LireDire_Ind2(f22,i2,&buf2);
                *nbre_lireindex2++;
                while(j2<buf2.nbe){
                        //la liste des adresse contient au moins 1 adresse
                        Allouer(&p);
                        Aff_val(&p,buf2.tab2[j2].mat);
                        Aff_adr(&p,NULL);
                        if(i2==buf1.tab1[j].tete && j2==0){
                            //le tete de la liste est p
                           (*(tab2+(code-1))).tete=p;

                        }else{
                        Aff_adr(&q,p);
                        }
                        q=p;
                        j2++;


                }
                i2=buf2.suiv;
            }

    }
    j++;
}

 }

 //fonction3- remplir la table d'index3 a partir du fichier index3
 //fonction2: remplir la table d'index2
void RemplirTab3(FICHTOF f31,FLNOF f32,Tcouple_tabInd3 *tab3,int *nbre_lireindex3,int *nbre_ecrireindex3)
{
 Tbloc1_index3 buf1;
 Tbloc2_index3 buf2;
 maillon p,q;
 *nbre_lireindex3=0;
 *nbre_ecrireindex3=0;
 int i2,j,j2,code;

LireDirtof_Ind3(f31,1,&buf1);
*nbre_lireindex3++;
j=0;
while(j<buf1.nbe){

    if(buf1.tab1[j].tete!=-1){
            code=buf1.tab1[j].Code_Etab_Univ;

            i2=buf1.tab1[j].tete;

            /****** Remplissage d'une liste d'adresse ******/
            while(i2!=-1){
                j2=0;

                LireDire_Ind3(f32,i2,&buf2);
                *nbre_lireindex3++;
                while(j2<buf2.nbe){
                        //la liste des adresse contient au moins 1 adresse
                        Allouer(&p);
                        Aff_val(&p,buf2.tab2[j2].mat);
                        Aff_adr(&p,NULL);
                        if(i2==buf1.tab1[j].tete && j2==0){
                            //le tete de la liste est p
                            (*(tab3+(code-1))).tete=p;

                        }else{
                        Aff_adr(&q,p);
                        }
                        q=p;
                        j2++;

                }
                i2=buf2.suiv;
            }

    }
j++;
}

 }
//fonction suppDecal => supprime par decalage un couple(cle,adresse) dans la table d'index1
void SuppDecal(Tcouple *tab1,int *taille,int position,int mat){
//quand on supprime un couple la taille de la table diminue
bool trouve;
int k,mpos;
//avant de passer aux decalages il faut changer l'adresse de l'ecrasant
//car sa position dans le fichier  de donnee a change
//son matricule est m
if((*taille)>1){
  Rech_tab1(mat,tab1,(*taille),&trouve,&mpos);
}
(*(tab1+(mpos))).adresse=(*(tab1+(position))).adresse;
k=position+1;
while(k<=((*taille)-1)){
    (*(tab1+(k-1)))=(*(tab1+(k)));
    k=k+1;
}

(*taille)=(*taille)-1;


 }

 void Supp_mat(FLNOF *f,int mat,Tcouple *tab1,int *taille,int *nbre_liredire,int *nbre_ecriredire){

 //la table d'index est utilise en MC
 int pos;
 bool trouv;
 Tcouple entree;
 int mecrasant;

 //-rechercher l'adresse dans tab
 Rech_tab1(mat,tab1,(*taille),&trouv,&pos);
 if(trouv==true){
    entree=tab1[pos];
   Ecraser_mat(&(*f),entree.adresse,&mecrasant,&(*nbre_liredire),&(*nbre_ecriredire));
   //l'enregistrement de cle mat est supprime physiquement dans le fichier de donnees f
   //et comme en manipule une table d'index en MC alors nous allons supprime physiquement aussi
   //son entree dans la table d'index
   //ainsi on evitra les suppressions logique dans le fichier index (apres tout on va sauvgarder la table dans le fichier index)

 SuppDecal(tab1,&(*taille),pos,mecrasant);//la taille sera taille-1 car on lui a supprime une donnee
 //Attention: les mises a jours du nombre d'enreg et les blocs sont gerees dans le module ecraser_mat
 }

}



 /************************************* Supprimer une specialite donnee ************************************/

void Supp_specialite(FLNOF *f,int code,Tcouples2 *tab2,Tcouple *tab1,int *taille,int *nbre_liredire,int *nbre_ecriredire)
{

    //tab2 la table d'index2 rempli dans le main
    //tab1 la table d'index1 rempli en main  et taille c'est ça taille=nb enreg dans le fichier index1 et = nb_enreg fichier
    //car la seule table qui est felxible est table1 a chaque suppresion et insertion elle modifie comme c'est l'index primaire


    maillon p,tete;
    int matricule;



    tete=(*(tab2+(code-1))).tete;
    p=tete;

        while(p!=NULL){
        //on parcoure maillon par maillon
        //et on recupere matricule par matricule
        //on le donne au module supprimer par matricule
        matricule=Valeur(p);
        Supp_mat(&(*f),matricule,tab1,&(*taille),&(*nbre_liredire),&(*nbre_ecriredire));
        p=Suivant(p);
    }


    //la mise a jour de l'index secondaire a verifier avec m.hidouci
    //a la sortie de ce module on doit mettre a jour le nombre d'adreese dans la case nb_adresse qui deviendra 0
    //ainsi que la tete de la liste
   //mais c'est juste pour l'affichage mais pour les recherche et tout ça va juste nous eviter d'acceder a sa liste poiur rien


}


/*************************** Codage d'un fichier binaire ************************************/
void Coder_fichier_bin(FLNOF f,FLNOF *fc,char *cle,int *nbre_liredire,int *nbre_ecriredire){

int i,i2,i2_sauv,j;
Tbloc buf1,buf2;
Tenreg e;
int clecodee;



i=Entete(f,1);//la tete du fichier en entree
buf2.prec=-1;
buf2.suiv=-1;
i2=1;
while(i!=-1){
    LireDire(f,i,&buf1);
    *(nbre_liredire)=(*nbre_liredire)+1;
    j=0;
    while(j<buf1.nb){
            e=buf1.t[j];
            Coder_Enreg(&e,cle);
            buf2.t[j]=e;
            j++;
    }
    buf2.nb=j;
    if(i==Entete(f,1)){
        //buf2 est la tete c'est le premier bloc a etre remplie suite au codage de la tete du fichier f
        Aff_Entete(&(*fc),1,i2);//forcement i2=1;
        Aff_Entete(&(*fc),2,i2);
        i2_sauv=i2;
        if(buf1.suiv!=-1){

        i2=AllocBloc((*fc));
        buf2.suiv=i2;

        }
        EcrireDir(&(*fc),i2_sauv,buf2);
        *(nbre_ecriredire)=(*nbre_ecriredire)+1;
        buf2.prec=i2_sauv;
       buf2.suiv=-1;
    }else{
        //buf2 est un autre bloc suite au codage d'un autre bloc du fichier f;
        Aff_Entete(&(*fc),2,i2);
         i2_sauv=i2;
        if(buf1.suiv!=-1){

        i2=AllocBloc((*fc));
        buf2.suiv=i2;
       }
       EcrireDir(&(*fc),i2_sauv,buf2);
               *(nbre_ecriredire)=(*nbre_ecriredire)+1;

        buf2.prec=i2_sauv;
       buf2.suiv=-1;
    }
    i=buf1.suiv;
}
Aff_Entete(&(*fc),3,Entete(f,3));
Aff_Entete(&(*fc),4,Entete(f,4));

Aff_Entete_cle(&(*fc),cle);



}

void Coder_Enreg(Tenreg *e,unsigned char *cle){

int s;
int taille=strlen(cle);
unsigned char ch[long_max];
//codage du Matricule;

s=(*e).Matricule;
s=s+taille+cle[0]+cle[taille-1];
(*e).Matricule=s;
  //codeage du Nom[long_np];
 strcpy(ch,(*e).Nom);
 codage(ch,cle);
  strcpy((*e).Nom,ch);
   //codage  Prenom[long_np];
   strcpy(ch,(*e).Prenom);
 codage(ch,cle);
  strcpy((*e).Prenom,ch);
  // codage de  la Date_Naissance;
  //l'annee
  s=(*e).Date_Naissance.Annee;
 s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Naissance.Annee=s;
  //le mois
s=(*e).Date_Naissance.Mois;
s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Naissance.Mois=s;
  //le jour
  s=(*e).Date_Naissance.Jour;
s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Naissance.Jour=s;
   //codage de la  Wilaya_Naissance[long_wilaya];
   strcpy(ch,(*e).Wilaya_Naissance);
 codage(ch,cle);
  strcpy((*e).Wilaya_Naissance,ch);
  //codage du Sexe;
  s=(*e).Sexe;
s=s+taille+cle[0]+cle[taille-1];
(*e).Sexe=s;
 // codage du Groupe_Sanguin[4];
  strcpy(ch,(*e).Groupe_Sanguin);
 codage(ch,cle);
  strcpy((*e).Groupe_Sanguin,ch);

//  codage Date_Recrutement;
 //l'annee
  s=(*e).Date_Recrutement.Annee;
s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Recrutement.Annee=s;
  //le mois
s=(*e).Date_Recrutement.Mois;
s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Recrutement.Mois=s;
  //le jour
  s=(*e).Date_Recrutement.Jour;
s=s+taille+cle[0]+cle[taille-1];
(*e).Date_Recrutement.Jour=s;


//codage du  Grade[long_np];
strcpy(ch,(*e).Grade);
 codage(ch,cle);
  strcpy((*e).Grade,ch);
  //codage de la Specialite[long_np];
strcpy(ch,(*e).Specialite);


 codage(ch,cle);
  strcpy((*e).Specialite,ch);
  //codage du Dernier_Diplome[long_np];
  strcpy(ch,(*e).Dernier_Diplome);
 codage(ch,cle);
  strcpy((*e).Dernier_Diplome,ch);
  //codage de l'etablissement_Univ[long_max];
strcpy(ch,(*e).Etablissement_Univ);
 codage(ch,cle);
  strcpy((*e).Etablissement_Univ,ch);
}


void codage(  unsigned char ligne[], unsigned char mot[])
 {
// unsigned char 0 -> +255
int i = 0, j = 0;

while ( i<strlen(ligne) ) {

if (ligne[i] >= 32 && ligne[i] < 127)
{
 ligne[i] = ligne[i] + mot[j];
 while ( ligne[i] > 126 ){
ligne[i] = ligne[i] - 127 + 32;}
 i++;
 j++;
if (j==strlen(mot)){j = 0; }

    }
 else
i++;
}}

void decodage( signed char ligne[], signed char mot[])
{
int i = 0, j = 0;
while ( i<strlen(ligne))
if ( ligne[i] >= 32 && ligne[i] < 127 ) {
ligne[i] = ligne[i] - mot[j];
 while ( ligne[i] < 32 )
ligne[i] = 127 - 32 + ligne[i];
 i++;
 j++;
 if (j==strlen(mot)) j = 0;
}
else
 i++;
}

void Decoder_Enreg(Tenreg *e,unsigned char *cle){

int s;
int taille=strlen(cle);
unsigned char ch[long_max];
//decodage du Matricule;

s=(*e).Matricule;
s=s-taille-cle[0]-cle[taille-1];
(*e).Matricule=s;
  //codeage du Nom[long_np];
 strcpy(ch,(*e).Nom);
 decodage(ch,cle);
  strcpy((*e).Nom,ch);
   //codage  Prenom[long_np];
   strcpy(ch,(*e).Prenom);
 decodage(ch,cle);
  strcpy((*e).Prenom,ch);
  // codage de  la Date_Naissance;
  //l'annee
  s=(*e).Date_Naissance.Annee;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Naissance.Annee=s;
  //le mois
s=(*e).Date_Naissance.Mois;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Naissance.Mois=s;
  //le jour
  s=(*e).Date_Naissance.Jour;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Naissance.Jour=s;
   //decodage de la  Wilaya_Naissance[long_wilaya];
   strcpy(ch,(*e).Wilaya_Naissance);
 decodage(ch,cle);
  strcpy((*e).Wilaya_Naissance,ch);
  //decodage du Sexe;
  s=(*e).Sexe;
s=s-taille-cle[0]-cle[taille-1];
(*e).Sexe=s;
 // decodage du Groupe_Sanguin[4];
  strcpy(ch,(*e).Groupe_Sanguin);
 decodage(ch,cle);
  strcpy((*e).Groupe_Sanguin,ch);

//  decodage Date_Recrutement;
 //l'annee
  s=(*e).Date_Recrutement.Annee;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Recrutement.Annee=s;
  //le mois
s=(*e).Date_Recrutement.Mois;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Recrutement.Mois=s;
  //le jour
  s=(*e).Date_Recrutement.Jour;
s=s-taille-cle[0]-cle[taille-1];
(*e).Date_Recrutement.Jour=s;


//decodage du  Grade[long_np];
strcpy(ch,(*e).Grade);
 decodage(ch,cle);
  strcpy((*e).Grade,ch);
  //decodage de la Specialite[long_np];
strcpy(ch,(*e).Specialite);
 decodage(ch,cle);
  strcpy((*e).Specialite,ch);
  //decodage du Dernier_Diplome[long_np];
  strcpy(ch,(*e).Dernier_Diplome);
 decodage(ch,cle);
  strcpy((*e).Dernier_Diplome,ch);
  //decodage de l'etablissement_Univ[long_max];
strcpy(ch,(*e).Etablissement_Univ);
 decodage(ch,cle);
  strcpy((*e).Etablissement_Univ,ch);
}

void Decoder_fichier_bin(FLNOF f,FLNOF *fc,int *nbre_liredire,int *nbre_ecriredire){

int i,i2,i2_sauv,j;
Tbloc buf1,buf2;
Tenreg e;

int clecodee;
char cle[30];
i=Entete(f,1);//la tete du fichier en entree
buf2.prec=-1;
buf2.suiv=-1;
i2=1;
Entete_cle(f,cle);//recuperation de la cle de codage pour decoder le fichier f
while(i!=-1){
    LireDire(f,i,&buf1);
    *(nbre_liredire)=(*nbre_liredire)+1;
    j=0;
    while(j<buf1.nb){
            e=buf1.t[j];
            Decoder_Enreg(&e,cle);
            buf2.t[j]=e;
            j++;
    }
    buf2.nb=j;
    if(i==Entete(f,1)){
        //buf2 est la tete c'est le premier bloc a etre remplie suite au codage de la tete du fichier f
        Aff_Entete(&(*fc),1,i2);//forcement i2=1;
        Aff_Entete(&(*fc),2,i2);
        i2_sauv=i2;
        if(buf1.suiv!=-1){

        i2=AllocBloc((*fc));
        buf2.suiv=i2;

        }
        EcrireDir(&(*fc),i2_sauv,buf2);
        *(nbre_ecriredire)=(*nbre_ecriredire)+1;
        buf2.prec=i2_sauv;
       buf2.suiv=-1;
    }else{
        //buf2 est un autre bloc suite au codage d'un autre bloc du fichier f;
        Aff_Entete(&(*fc),2,i2);
         i2_sauv=i2;
        if(buf1.suiv!=-1){

        i2=AllocBloc((*fc));
        buf2.suiv=i2;
       }
       EcrireDir(&(*fc),i2_sauv,buf2);
              *(nbre_ecriredire)=(*nbre_ecriredire)+1;

        buf2.prec=i2_sauv;
       buf2.suiv=-1;
    }
    i=buf1.suiv;
}
Aff_Entete(&(*fc),3,Entete(f,3));
Aff_Entete(&(*fc),4,Entete(f,4));

Aff_Entete_cle(&(*fc),cle);//la cle de codage et decodage

}
/*************************** Modification de l'etablissement d'un enreg ***********************************/
void Modifer_etab(FLNOF *f,int mat,int code_etab,Tcouple *tab1,Tcouple_tabInd3 *tab3,int *nbre_liredire,int *nbre_ecriredire){
   int pos,ancien;
   bool trouv,trouv2;
   Tbloc buf;
   int i,j;
   char etab[long_max];
   trouv=false;
   maillon p,prec;



  //rechercher l'adresse de l'enreg qui a le matricule mat
  Rech_tab1(mat,tab1,Entete((*f),3),&trouv,&pos) ;
  if(trouv==true){
         i=tab1[pos].adresse.numb;
    j=tab1[pos].adresse.dep;
   LireDire((*f),i,&buf);
   *(nbre_liredire)=(*nbre_liredire)+1;
   ancien=Recuperer_code_etab(buf.t[j].Etablissement_Univ);
    Etablissement(etab,code_etab);
    strcpy(buf.t[j].Etablissement_Univ,etab);
   EcrireDir(&(*f),i,buf);
   *(nbre_ecriredire)=(*nbre_ecriredire)+1;
   //modification de l'index secondaire index3

   //1-rechercher le maillon correspondant au code ancien et au matricule mat
   p=(*(tab3+(ancien-1))).tete;
   prec=NULL;
   trouv2=false;
   while(p!=NULL && trouv2!=true){
    if(Valeur(p)==mat){
        trouv2=true;

        //liberer ce maillon
        if(    (p==   (*(tab3+(ancien-1))).tete)   ){
         (*(tab3+(ancien-1))).tete=Suivant(p);
          Aff_adr(&p,NULL);
          Liberer(p);
        }else{
        Aff_adr(&prec,Suivant(p));
        Aff_adr(&p,NULL);
        Liberer(p);
        }

    }else{
    prec=p;
    p=Suivant(p);
    }
   }
   //2-ajouter un maillon dans l'etablissement dont le code est code_etab
   //insertion dans la tete
    p=(*(tab3+(code_etab-1))).tete;
    Allouer(&prec);
    Aff_val(&prec,mat);
    Aff_adr(&prec,p);
    (*(tab3+(code_etab-1))).tete=prec;

  }





}
void Etablissement(char *etab,int code_etab){
char *etablissment[]={"U.de Bouira-Akli Mohand Oulhadj",
"U.de Djelfa-Ziane Achour",
"U.de Ghardaia",
"U.de Khemis Miliana-Djilali Bounaama",
"U.Medea-Yahia Fares",
"U.des sciences et de la technologie d'Alger, Houari Boumediene",
"U.de Bejaia-Abderrahmane Mira",
"U.de Boumerdes-M'hamed Bougara",
"U.de Tizi Ouzou-Mouloud Maameri",
"U.de Laghouat-Amar Telidji",
"U.de Blida 1-Saad Dahlab",
"U.de Blida 2-Lounici Ali",
"U.d'Alger 1-Benyoucef Benkhedda",
"U.d'Alger 2-Abou el Kacem Saâdallah",
"U.d'Alger 3-Brahim Soltane Chaibout",
"U.de la Formation Continue",
"U.de Tamenghasset",
"E.N.Polytechnique",
"E.N.S.d'hydraulique-Arbaoui Abdellah",
"E.N.S.des travaux publics-Francis Jeanson",
"E.N.S.veterinaire-Rabie Bouchama",
"E.Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed",
"E.N.S.agronomique-Khalef Abdellah alias Kasdi Merbah",
"E.des hautes etudes commerciales",
"E.N.S.d'informatique",
"E.N.S.en statistique et en economie appliquee",
"E.S.de Commerce-Mouloud Kacem Nait Belkacem",
"E.N.S.des sciences de la mer et de l'amenagement du littoral",
"E.N.S.de management",
"E.N.S.de Technologie",
"E.N.S.de journalisme et des sciences de l'information",
"E.N.S.des sciences politiques",
"E.N.S.de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger",
"E.S.des Sciences appliquees d'Alger ex EP ST Alger",
"E.S.de Gestion et d'Economie Numerique",
"E.S.en Sciences et Technologies de l'Informatique et du Numerique de Bejaia",
"E.N.S.en Intelligence Artificielle",
"E.N.S.en Mathematique",
"E.N.S.de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili",
"E.N.S.de Kouba - Mohamed Bachir El Ibrahimi",
"E.N.S.de Laghouat - Taleb Abderrahmane",
"E.N.S.de sourds muets",
"C.U.de Tipaza - Abdallah Morsli",
"C.U.d'Illizi-Cheikh Amoud ben Mokhtar",
"C.U.d'Aflou",
"U.de Jijel - Mohammed Seddik Ben yahia",
"U.de Tebessa - Larbi Tebessi",
"U.de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi",
"U.d'El Tarf - Chadli Bendjedid",
"U.de Khenchela - Abbas Laghrour",
"U.de Oum El Bouaghi - Larbi Ben M'hidi",
"U.d'El Oued - Hamma Lakhdar",
"U.de Souk Ahras - Mohammed-Cherif Messaadia",
"U.de Annaba - Badji Mokhtar",
"U.du 20 Août 1955 de Skikda",
"U.8 Mai 1945 de Guelma",
"U.de Batna 1 - Hadj Lakhder",
"U.de Biskra - Mohamed Khider",
"U.de M'sila - Mohamed Boudiaf",
"U.de Ouargla - Kasdi Merbah",
"U.des sciences islamiques Emir Abdelkader de Constantine",
"U.de Setif 1 - Ferhat Abbas",
"U.de Setif 2 - Mohamed Lamine Debaghine",
"U.de Constantine 1 - Freres Mentouri",
"U.de Constantine 2 - Abdelhamid Mehri",
"U.de Constantine 3 -Salah Boubnider",
"U.de Batna 2 - Mustapha Ben Boulaid",
"E.N.S.des mines et de la metallurgie-Amar Laskri",
"E.N.Polytechnique de Constantine-Malek Bennabi",
"E.N.S.de Biotechnologie de Constantine-Tewfik Khaznadar",
"E.N.S.des Sciences de Gestion de Annaba ex-EPSECG Annaba",
"E.S.des Technologies Industrielles de Annaba ex EP ST Annaba",
"E.S.de Comptabilite et de Finance de Constantine ex EPSECG Constantine",
"E.N.S.des forets-Khenchela",
"E.N.S.des energies renouvelables, environnement et developpement durable - Batna",
"E.N.S.de Constantine-Assia Djebar",
"E.N.S.d'enseignement technologique de Skikda",
"E.N.S.de setif-Messaoud Zeghar",
"E.N.S.de Bou Saada",
"E.N.S.de Ouargla",
"C.U.de Mila-Abdelhafid Boussouf",
"C.U.de Barika-Si El Haoues",
"U.de Bechar-Mohamed Tahri",
"U.de Mascara-Mustapha Stambouli",
"U.de Saida-Tahar Moulay",
"U.de Tlemcen-Abou Bekr Belkaid",
"U.d'Adrar-Ahmed Draya",
"U.de Tiaret-Ibn Khaldoun",
"U.Sidi Bel Abbes-Djillali Liabes",
"U.de Mostaganem-Abdelhamid Ibn Badis",
"U.d'Oran1-Ahmed Ben Bella",
"U.Mohamed Boudiaf des sciences et de la technologie-Mohamed Boudiaf d'Oran",
"U.d'Oran 2-Mohamed Ben Ahmed",
"U.de Chlef-Hassiba Benbouali",
"U.de Tissemsilt",
"U.de Ain Temouchent",
"U.de Relizane",
"E.N.Polytechnique d'Oran - Maurice Audin",
"E.S.d'Informatique (Sidi Bel Abbes)- 08 Mai 1945",
"E.S.des Sciences Appliquees de Tlemcen ex EP ST Tlemcen",
"E.S.de Management de Tlemcen ex EPSECG Tlemcen",
"E.S.d'Economie d'Oran  ex EPSECG Oran",
"E.S.en Genie Electrique et Energetique d'Oran ex EP ST Oran",
"E.S.Agronomique de Mostaganem ex EP SNV Mostaganem",
"E.S.des sciences Biologiques d' Oran ex EP SNV Oran",
"E.N.S.de Mostaganem",
"E.N.S.d'Oran",
"E.N.S.de Bechar",
"C.U.de Naama-Ahmed Salhi",
"C.U.d'El Bayadh-Nour Bachir",
"C.U.de Tindouf-Ali Kafi",
"C.U.de Maghnia"};

  strcpy(etab,etablissment[code_etab-1]);
}
void retourner_specialite(char *spec,int code_spe){
char *specialite[]={"Informatique",
    "Architecture",
    "Medecine",
    "Veterinaire",
    "Pharmacie",
    "Mathematique",
    "Physique",
    "Medecine dentaire",
"Agriculture saharienne",
"Agronomie",
"Sciences et technologies",
"Sciences de la matiere",
"Sciences de la nature et de la vie",
"Sciences economoiques",
"Sciences politiques",
"Droit",
"Langue francaise",
"Langue anglaise",
"Sciences humaines",
"Sciences sociales",
"Sciences islamiques",
"Langue et litterature arabes",
"Sciences financieres et comptabilite",
"Genie civil",
"Travaux publics",
"Gestion des techniques urbaines",
"Geographie et amenagement du territoire",
"Geologie",
"Science des activites physiques et sportives",
"Telecommunications",
"Sciences alimentaires",
"Sciences de gestion",
"Droit public",
"Sciences veterinaires",
"Langue et culture amazighes",
"Traduction interpretariat",
"Hydraulique",
"Biotechnologie",
"Urabanisme",
"Aeronautique",
"Genie des procedes",
"Energies renouvelables",
"Electrotechnique",
"Genie macanique",
"Langue italienne",
"Management",
"Sciences appliquees",
"Genie industriel",
"Geniebiomedical",
"Langue espagnole",
"Arts",
"Metiers de la ville",
"Langue allmande",
"Microbiologie fondamentale et appliquée",
"Journalisme et sciences de l'information",
"Geophysique",
"Langue turque",
"Langue russe",
"Optique et macanique de precision",
"Industries petrochimiques",
"Genie minier",
"Metallurgie",
"Ingenierie des transports",
"Electromecanique",
"Hydraucarbures",
"Hygiene et securite industrielle",
"Genie maritime",
"Automatique",
"Forets",
"Histoire geographie",
"Musique",
"Philosophie"};
strcpy(spec,specialite[code_spe-1]);

}
void retourner_wilaya(char *wilaya,int code_wilaya){
 char *tab_lib[]={"ADRAR","CHLEF","LAGHOUAT","OUM EL BOUAGHI","BATNA","BEJAIA","BISKRA","BECHAR","BLIDA","BOUIRA","TAMANRASSET","TEBESSA","TELEMCEN","TIARET","TIZI-OUZOU","ALGER","DJELFA","DJELFA","SETIF","SAIDA","SKIKDA","SIDI BEL ABBES","ANNABA","GUELMA","CONSTANTINE","MEDEA","MONSTAGANEM","M'SILA","MASCARA","OUARGLA","ORAN","BAYADH","ILLIZI","BORDJ BOU ARRERIDJ","BOUMERDES","TARF","TINDOUF","TISSEMSILT", "EL OUED","KHENCHELA","SOUK AHRAS","TIPAZA","MILA","AIN DEFLA","NAAMA","AIN TEMOUCHENT","GHARDAIA","RELIZANE","TIMIMOUN","BORDJ BADJI MOKHTAR","OULED DJELLAL","BENI ABBES","IN SALAH","IN GUEZZAM","TOUGGOURT","DJANET","EL M'GHAIR","EL MENIAA"};
 strcpy(wilaya,tab_lib[code_wilaya-1]);
}
void retourner_groupsang(char *sang,int code_sang){
char *group[]={"O+","A+","B+","O-","A-","AB+","B-","AB-"};
strcpy(sang,group[code_sang-1]);
}
void retourner_grade(char *grade,int code_grade){
char *grades[]={"Professeur","Maitre de conferences Rang A","Maitre de conferences Rang B","Maitre assistant Rang A","Maitre assistant Rang B","Assistant"};
strcpy(grade,grades[code_grade-1]);
}
void retourner_diplome(char *dernier_diplome,int code_diplome){
char *diplome[]={"Doctorat d Etat","Doctorat en sciences","Doctorat D-LMD","PhD","Habilitation Universitaire","Magistere"};
strcpy(dernier_diplome,diplome[code_diplome-1]);
}
bool control_date(int jour,int mois,int annee,int choix){
    bool m7,m2,m3,m4,m5,m6,mn;
if(mois>0 && mois<13){
    m7=true;
}else{
    textcolor(RED);
    printf("\n-Erreur !L'annee ne contient que 12 mois au maximum\n");

m7=false;
}
//Si le choix egale a 1 => la date de naissance
//Si le choix egale a 2=>la date de recrutement
if(choix==1){
if(annee>=1953 && annee<=1998){
    m2=true;
}else{
    textcolor(RED);
    printf("\nErreur !L'annee de naissance doit etre entre 1953 et 1998\n");
m2=false;
}
}
if(choix==2){
  if(annee>=1985 && annee<=2022){
    m2=true;
}else{
    textcolor(RED);
    printf("\nErreur!L'annee de recrutement doit etre entre 1985 et 2022\n");
m2=false;
}
}
if(jour>=1 && jour<=31){
    m3=true;
}else{
m3=false;
printf("\nErreur!Le mois contient que 31 jours au max.\n");
}
if(m7==true && m2==true && m3==true){
    if( mois==4 || mois==6 || mois==9 || mois==11 ){
            if(jour<=30){
                m4=true;
            }else{
            m4=false;
            printf("\nErreur!Les mois :avril,juin,septembre,novembre contiennent au max 30 jours\n");
            }
    }else{
    if( mois==1 || mois==3 || mois==5 || mois==7|| mois==8||mois==10||mois==12 ){
            if(jour<=31){
                m4=true;
            }else{
            m4=false;
            }
    }
    }
    if(mois==2){
        if(jour<=28 && an_bissextile(annee)==false){
            m5=true;
        }
       if(jour>28 && an_bissextile(annee)==false){
        m5=false;
        printf("\nErreur!L'annee que vous avez saisie n'est pas bissextille ,fevrieir contient au max 28 jours\n");
        }
        if(jour<=29 && an_bissextile(annee)==true){
            m6=true;
        }
        if(jour>29  && an_bissextile(annee)==true){
          m6=false;
          printf("\nErruer!L'annee que vous avez saisie est  bissextille ,fevrieir contient au max 29 jours\n");

        }
    }
}
if((m7==true && m2==true && m3==true && m4==true)||(m7==true && m2==true && m3==true && m5==true)||(m7==true && m2==true && m3==true && m6==true) ){
    mn=true;
}else{
mn=false;
}
return mn;
}
bool controle_grade(char *grade,int date_naissance){
int age,day,month,year;
bool m7=false,m2=false,m3=false,m4=false,mn=false,m5=false,m6=false;
date_sys(&day,&month,&year);
age=year-date_naissance;
if(strcmp("Professeur",grade)==0){
  if(age>=31){
    m7=true;
  } else{
   m7=false;
  }
}
if(strcmp("Maitre de conferences Rang A",grade)==0){
    if(age>=26){
        m2=true;
    }else{
     m2=false;
    }
}
if(strcmp("Maitre de conferences Rang B",grade)==0){
    if(age>=25){
        m3=true;
    }else{
    m3=false;
    }
}
if(strcmp("Maitre assistant Rang A",grade)==0){
    if(age>=25){
        m4=true;
    }else{
    m4=false;
    }
}
if(strcmp("Maitre assistant Rang B",grade)==0){
    if(age>=24){
        m5=true;
    }else{
    m5=false;
    }
}
if(strcmp("Assistant",grade)==0){
    if(age>=24){
        m6=true;
    }else{
     m6=false;
    }
}
if(m7==true||m2==true||m3==true||m4==true||m5==true||m6==true){
    mn=true;
}else{
 mn=false;
}
return mn ;
}
void Ajout_Enseignant(Tcouple *tab1,int *n,Tcouples2 *tab2,Tcouple_tabInd3 *tab3,int *matri,int *nbre_liredire,int *nbre_ecriredire,bool *trouve){
FLNOF f;

Tenreg e;
bool matricule=false,correct=false,correct_recru=false,grade_correct=false;
int pos;
Tbloc buf;
Tcouple t;
int i=0,i2,j,s,k,spe,ville,group,x,g;
*nbre_liredire=0;
*nbre_ecriredire=0;
maillon p,q;
*trouve=false;
Tadr adresse;
char chaine[long_max];
Ouvrir(&f,"ENSEIGNANT-MESRS.bin",'A');
(*n)=Entete(f,3);
printf("\n-Veuillez entrer les renseignemants necessaires de l'enseignant que vous voulez ajouter:\n");

while(matricule==false){
 printf("\n-Veuillez donner le matricule de l'enseignant que vous souhaitez ajouter: ");
scanf("%d",&e.Matricule);
if(controle_mat(e.Matricule)==false){
    matricule=false;
    textcolor(RED);
    printf("-Erreur! Veuillez entrer un matricule entre 111111 et 999999: \n");
    textcolor(BLACK);
}else{
matricule=true;
*matri=e.Matricule;
}
}
Rech_tab1(e.Matricule,tab1,(*n),&(*trouve),&pos);
if((*trouve)==true){
         clrscr();
        textcolor(RED);

    printf("\n\n-Vous ne pouvez pas ajouter cet enseingant , il existe deja\n");
textcolor(BLACK);
}else{
puts("\n-Veuillez donner le nom de l'enseignant que vous souhaitez ajouter: ");
getchar();
//gets(e.Nom);
printf("\nLe nom :");
fgets(e.Nom,128,stdin);
k=strlen(e.Nom)-1;
if(e.Nom[k]=='\n'){
    e.Nom[k]='\0';
}

puts("\n-Veuillez donner le prenom de l'enseignant que vous souhaitez ajouter: ");
//getchar();
printf("\nLe prenom :");
gets(e.Prenom);

printf("\n-Veuillez donner la date de naissance de l'enseignant: ");
printf("\n");
while(correct==false){
textcolor(BLACK);
printf(" Le jour: ");
scanf("%d",&(e.Date_Naissance.Jour));
printf(" Le mois: ");
scanf("%d",&(e.Date_Naissance.Mois));
printf(" L'annee: ");
scanf("%d",&(e.Date_Naissance.Annee));
correct=control_date(e.Date_Naissance.Jour,e.Date_Naissance.Mois,e.Date_Naissance.Annee,1);
if(correct==false){
    textcolor(RED);
    printf("\n-Veuillez donner une autre date correcte: ");
    printf("\n");

}else{
textcolor(BLACK);
}
}
clrscr();
printf("-Veuillez cliquer sur le nom de la wilaya de naissance de l'enseignant :\n\n ");

ville=willaya();
printf("\n\n");
textcolor(BLACK);
retourner_wilaya(e.Wilaya_Naissance,ville);
clrscr();
printf("-Veuillez cliquer sur le sexe que vous voulez choisir:\n\n ");
e.Sexe=sex();

textcolor(BLACK);
clrscr();

printf("-Veuillez cliquer sur le groupe sanguin que vous voulez choisir: ");
group=abo();
retourner_groupsang(e.Groupe_Sanguin,group);

textcolor(BLACK);
clrscr();

puts("\n-Veuillez entrer la date de recrutement de l'enseignant: ");
while(correct_recru==false){
        textcolor(BLACK);
printf(" Le jour: ");
scanf("%d",&(e.Date_Recrutement.Jour));
printf(" Le mois: ");
scanf("%d",&(e.Date_Recrutement.Mois));
printf(" L'annee: ");
scanf("%d",&(e.Date_Recrutement.Annee));
correct_recru=control_date(e.Date_Recrutement.Jour,e.Date_Recrutement.Mois,e.Date_Recrutement.Annee,2);
if(correct_recru==false){
    textcolor(RED);
    printf("\n-Veuillez entrer une autre date correcte\n");
}
else{
    textcolor( BLACK );
}
}
clrscr();
printf("-Veuillez cliquer sur le grade de l'enseignant: ");
while(grade_correct==false){
g=grad();
clrscr();
retourner_grade(e.Grade,g);

grade_correct=controle_grade(e.Grade,e.Date_Naissance.Annee);
if(grade_correct==false){
    textcolor(RED);
    printf("-Veuillez cliquer sur un autre grade compatible avec l'age de l'enseignant\n");
}else{
    textcolor(BLACK);
}

}
clrscr();

printf("-Veuillez cliquer sur la specialite de l'enseignant:\n ");
spe=spes();
retourner_specialite(e.Specialite,spe);
clrscr();

printf("-Veuillez cliquer sur le dernier diplome de l'enseignant: ");
retourner_diplome(e.Dernier_Diplome,dernier_dip());
clrscr();

printf("-Veuillez cliquer sur l'etablissemnt de l'enseignant: ");
x=reseau();
Etablissement(e.Etablissement_Univ,x);

    i=Entete(f,2);
  LireDire(f,i,&buf);
  *(nbre_liredire)=(*nbre_liredire)+1;
  if(buf.nb<b){
     buf.t[buf.nb]=e;
     j=buf.nb;
     buf.nb++;
     EcrireDir(&f,Entete(f,2),buf);
     *(nbre_ecriredire)=(*nbre_ecriredire)+1;

     Aff_Entete(&f,3,Entete(f,3)+1);
  }else{
    i2=i;


    i=AllocBloc(f);

    buf.suiv=i;
    EcrireDir(&f,i2,buf);
         *(nbre_ecriredire)=(*nbre_ecriredire)+1;

    buf.t[0]=e;
    buf.nb=1;
    buf.prec=i2;
    buf.suiv=-1;
    EcrireDir(&f,i,buf);
         *(nbre_ecriredire)=(*nbre_ecriredire)+1;

    j=0;
    Aff_Entete(&f,2,i);
    Aff_Entete(&f,3,Entete(f,3)+1);
    Aff_Entete(&f,4,Entete(f,4)+1);
  }
// Mise a jour de l'index numero 1
t.cle=e.Matricule;
t.adresse.numb=i;
t.adresse.dep=j;
t.supp=false;
Insertab1(tab1,(*n)+1,pos,t);
(*n)=(*n)+1;
adresse.numb=i;
adresse.dep=j;
// Mise a jour de l'index numero 2

s=Recuperer_code_Specialite(e.Specialite);

if((*(tab2+(s-1))).tete==NULL){
         Allouer(&p);
         Aff_adr(&p,NULL);
         Aff_val(&p,e.Matricule);
        (*(tab2+(s-1))).tete=p;
         }else{
           Allouer(&p);
          Aff_val(&p,e.Matricule);
          q=(*(tab2+(s-1))).tete;
          Aff_adr(&p,q);
          (*(tab2+(s-1))).tete=p;
         }
//Mise a jour de l'index numero 3
 s=Recuperer_code_etab(e.Etablissement_Univ);


            if((*(tab3+(s-1))).tete==NULL){
            //creation de la liste et affectation de la tete
            Allouer(&p);
            Aff_adr(&p,NULL);//initialement q est a NULL
            Aff_val(&p,e.Matricule);
            (*(tab3+(s-1))).tete=p;
           }else{
          //la liste existe donc ajout d'une nouvelle adresse càd nouveau maillon a la liste
          Allouer(&p);
          Aff_val(&p,e.Matricule);
          //on sauvgarde la tete
           q=(*(tab3+(s-1))).tete;//mise a jour de la tete car on fait une insertion par la tete
          Aff_adr(&p,q);
          (*(tab3+(s-1))).tete=p;
          }
}
Fermer(f);
clrscr();

printf("\n\n                           ~~~~~~~~~~>> Felicitations! <<~~~~~~~~~~~\n");
printf("                           L'enseignant a ete bien ajoute au fichier     \n");
textcolor(BLUE);
printf("\n");
printf("=>Le cout total de cette procedure:\n");
printf("                                   =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",(*nbre_liredire));
textcolor(BLUE);
printf("                                   =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_ecriredire));
}
// LES controles de saisie

int controle_mat(int matricule){
// la fonction qui verifie si le matriciule est entre 111111 et 999999
if( matricule<111111 || matricule>999999){
    return false;
}else{
  return true;
}
}
//Cette fonctionner retourne la date da systeme qui sera utilisée pour calculer l'ancienneté
void date_sys(int *day,int *month,int *year)
{
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  *day = local->tm_mday;
  *month = local->tm_mon + 1;
  *year = local->tm_year + 1900;

}
void affichage_anciennete(int anciennete_inf,int anciennete_sup,char* etab,Tcouple_tabInd3 *tabInd3,Tcouple *tab,int n,int *nbre_liredire,int *nbre_ecriredire){
FLNOF f;
Ouvrir(&f,"ENSEIGNANT-MESRS.bin",'A');
int i,j,anciennete_enreg,year,day,month,cp=0,code,pos;
Tbloc buf;
maillon p;
char chaine[20];
bool trouv=false;
*nbre_liredire=0;
*nbre_ecriredire=0;

i=1;
date_sys(&day,&month,&year);
code=Recuperer_code_etab(etab);
p=tabInd3[code-1].tete;
while(p!=NULL){

       Rech_tab1(p->mat,tab,n,&trouv,&pos);
        if (trouv==true){
        LireDire(f,tab[pos].adresse.numb,&buf);
        (*nbre_liredire)=(*nbre_liredire)+1;
         j=tab[pos].adresse.dep;


      anciennete_enreg=(year-buf.t[j].Date_Recrutement.Annee);
      if(anciennete_enreg>=anciennete_inf && anciennete_enreg<=anciennete_sup) {
            cp++;
          if(cp%20!=0){
              textcolor(BLUE);textbackground(YELLOW);
            printf("\n|================================================> L'enseignant numero %d  <===============================================================|\n",cp);textbackground(WHITE);
           textcolor(BLACK);

           printf("\n");
           //l'enreg est buf.t[j]

         afficherE(buf.t[j],j);


          }else{
          system("pause");
           textcolor(BLUE);textbackground(YELLOW);
            printf("\n|================================================> L'enseignant numero %d  <===============================================================|\n",cp);textbackground(WHITE);
           textcolor(BLACK);
             printf("\n");

         afficherE(buf.t[j],j);


          }



         }
      }

      p=Suivant(p);
    }
textcolor(BLUE);
printf("\n   => Resume de la requette: \n");
textcolor(BLACK);



printf("        Le nombre d'enseignant travaillant dans l'etablissement '%s'\n        ayant une anciennete entre %d et %d ans est: %d enseignants sur %d enseignants d'Algerie\n\n",etab,anciennete_inf,anciennete_sup,cp,Entete(f,3));

textcolor(BLUE);
printf("   =>Le cout total de cette procedure:\n");
printf("                                           =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",(*nbre_liredire));
textcolor(BLUE);
printf("                                           =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_ecriredire));
system("pause");

Fermer(f);
}

void Consultation_region(Tcouple_tabInd3 *tabInd3 ,Tcouple *tab,int n,int *nbre_liredire,int *nbre_ecriredire){
FLNOF f;
Ouvrir(&f,"ENSEIGNANT-MESRS.bin",'A');
int i=0,j=0,pos=0,cpt,region;

maillon p=NULL;
Tbloc buf;
char chaine[20];
bool trouv=false;


printf("Veuillez entrer la region: \n ");


region=reg();

if(region==1){
        cpt=0;
        clrscr();
reseaucentre();
printf("\n\n");

   while(i<=44){

       p=tabInd3[i].tete;
     while(p!= NULL){
        Rech_tab1(p->mat,tab,n,&trouv,&pos);
        if (trouv==true){
                cpt++;

        LireDire(f,tab[pos].adresse.numb,&buf);
        *(nbre_liredire)=(*nbre_liredire)+1;

         j=tab[pos].adresse.dep;

if(cpt%20!=0){
        textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

         afficherE(buf.t[j],j);

}else{
system("pause");
 textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

         afficherE(buf.t[j],j);


}


        }
        p=Suivant(p);

    }
    i++;
   }

   textcolor(BLUE);
printf("\n   => Resume de la requette: \n");
textcolor(BLACK);
printf("        Le nombre d'enseignants travaillant dans la region du centre d'Algerie est: %d enseignants sur %d enseignants d'Algerie\n\n",cpt,Entete(f,3));


}else{
if(region==2){
        clrscr();
reseauest();
printf("\n\n");
    cpt=0;
    i=45;
     while(i<=81){
    p=tabInd3[i].tete;
    while(p!= NULL){
        Rech_tab1(p->mat,tab,n,&trouv,&pos);
        if (trouv==true){
                cpt++;
        LireDire(f,tab[pos].adresse.numb,&buf);
               *(nbre_liredire)=(*nbre_liredire)+1;

         j=tab[pos].adresse.dep;

if(cpt%20!=0){
        textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

                  afficherE(buf.t[j],j);


}else{


    system("pause");
     textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

                  afficherE(buf.t[j],j);

}





        }
        p=Suivant(p);

    }
    i++;
   }
   textcolor(BLUE);
printf("\n   => Resume de la requette: \n");
textcolor(BLACK);
printf("        Le nombre d'enseignants travaillant dans la region du centre d'Algerie est: %d enseignants sur %d enseignants d'Algerie\n\n",cpt,Entete(f,3));


}else{
 if(region==3){
        clrscr();
 reseauouest();
 printf("\n\n");

     cpt=0;
    i=82;
     while(i<=111){
    p=tabInd3[i].tete;
    while(p!= NULL){
        Rech_tab1(p->mat,tab,n,&trouv,&pos);
        if (trouv==true){
                cpt++;
        LireDire(f,tab[pos].adresse.numb,&buf);
                *(nbre_liredire)=(*nbre_liredire)+1;

         j=tab[pos].adresse.dep;

if(cpt%20!=0){
        textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

         // afficher_enreg(f,buf.t[j].Matricule,tab,n,&(*nbre_liredire),&(*nbre_ecriredire));
                  afficherE(buf.t[j],j);


}else{
system("pause");
 textcolor(BLUE);textbackground(YELLOW);
printf("\n ================================================> L'enseignant numero %d  <===============================================================",cpt);textbackground(WHITE);
textcolor(BLACK);
printf("\n");

        //  afficher_enreg(f,buf.t[j].Matricule,tab,n,&(*nbre_liredire),&(*nbre_ecriredire));
                 afficherE(buf.t[j],j);



}



        }
        p=Suivant(p);

    }
    i++;
   }
    textcolor(BLUE);
printf("\n   => Resume de la requette: \n");
textcolor(BLACK);
printf("        Le nombre d'enseignants travaillant dans la region du centre d'Algerie est: %d enseignants sur %d enseignants d'Algerie\n\n",cpt,Entete(f,3));



 }
}
}


printf("                -> la consulatation est terminee <-\n");
textcolor(BLUE);
printf("\n");
printf("=>Le cout total de cette procedure:\n");
printf("                                   =>Le nombre de Liredire  : ");
textcolor(BLACK);
printf("%d\n",(*nbre_liredire));
textcolor(BLUE);
printf("                                   =>Le nombre de Ecriredire: ");
textcolor(BLACK);
printf("%d\n",(*nbre_ecriredire));

system("pause");
Fermer(f);
}

//affichage de l'entete
void afficher_entete(FLNOF f)
{

 int x,y;
 int marge=15;
 ent();
 printf("\n\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);
 textbackground(YELLOW);
 printf("[============================================================================================================]\n");
  x=wherex();
y=wherey();
 gotoxy(x+marge,y);
 printf("|                                                                                                            |\n");
  x=wherex();
y=wherey();
 gotoxy(x+marge,y);
printf("| < La tete du fichier                        :");
x=wherex();
y=wherey();
gotoxy(marge+x-15,y);printf("                                                            ");
gotoxy(marge+x+10,y);printf("%6d",Entete(f,1));
gotoxy(marge+x+45+1+3+11-15,y);printf("> |\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);
printf("| < La queue du fichier                       :");
x=wherex();
y=wherey();
gotoxy(marge+x-15,y);printf("                                                            ");

gotoxy(marge+x+10,y);printf("%6d",Entete(f,2));
gotoxy(marge+x+45+1+3+11-15,y);printf("> |\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);

printf("| < Le nombre d'enregistrements               :");
x=wherex();
y=wherey();
gotoxy(marge+x-15,y);printf("                                                            ");

gotoxy(marge+x+10,y);printf("%6d",Entete(f,3));
gotoxy(marge+x+45+1+3+11-15,y);printf("> |\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);
printf("| < Le nombre de blocs                        :");
x=wherex();
y=wherey();
gotoxy(marge+x-15,y);printf("                                                            ");

gotoxy(marge+x+10,y);printf("%6d",Entete(f,4));
gotoxy(marge+x+45+1+3+11-15,y);printf("> |\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);
printf("| < La cle de codage et decodage du fichier   :");
x=wherex();
y=wherey();
gotoxy(marge+x-15,y);printf("                                                            ");

gotoxy(marge+x+10,y);printf("*************");
gotoxy(marge+x+45+1+3+11-15,y);printf("> |\n");
 x=wherex();
y=wherey();
 gotoxy(x+marge,y);
 printf("|                                                                                                            |\n");
  x=wherex();
y=wherey();
 gotoxy(x+marge,y);

 printf("[============================================================================================================]\n\n\n");
 textbackground(WHITE);

}
void afficher_enreg(FLNOF f,int mat,Tcouple *tab,int tai,int *nbre_liredire,int *nbre_ecriredire)
{
    int pos;
    bool trouv;
    int i,j;
    Tbloc buf;
    char chaine[20];
    int x,y;




 //rechercher l'adresse de l'enreg
 Rech_tab1(mat,tab,tai,&trouv,&pos) ;


 if(trouv==true){

   i=tab[pos].adresse.numb;
   j=tab[pos].adresse.dep;

   LireDire(f,i,&buf);
   *(nbre_liredire)=(*nbre_liredire)+1;
    if(buf.t[j].Sexe==1){
                strcpy(chaine,"Masculin");
            }else{
             strcpy(chaine,"Feminin");
            }


printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");

y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");
gotoxy(x+4,y);
textbackground(LIGHTCYAN);
textcolor(RED);

printf("| Deplacement: ");
gotoxy(x+4+15,y);printf("%4d",j);
gotoxy(x+4+4+10+2+2+1,y);
printf("|            Champ              |                   Information                                                  |");


textbackground(WHITE);
gotoxy(x+137,y);
textcolor(BLACK);
printf("  |\n");
y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");

printf("  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");
textcolor(BLACK);
x=wherex();
printf(" |  |                  |< Matricule                   >|");
 y=wherey();
gotoxy(x+57,y);printf("%d",buf.t[j].Matricule);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
printf(" |  |                  |< Nom                         >|");
y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Nom);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Prenom                      >|");

y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Prenom);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
printf(" |  |                  |< Date de naissance           >|");
y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Naissance.Jour,buf.t[j].Date_Naissance.Mois,buf.t[j].Date_Naissance.Annee);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Wilaya de naissance         >|");

y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Wilaya_Naissance);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Sexe                        >|");
  y=wherey();
gotoxy(x+57,y);printf("%s",chaine);
gotoxy(x+123,y);printf("             |  |\n");
   x=wherex();

       printf(" |  |                  |< Groupe sanguin              >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Groupe_Sanguin);
gotoxy(x+123,y);printf("             |  |\n");
 x=wherex();

       printf(" |  |                  |< Date de recrutement         >|");

 y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Recrutement.Jour,buf.t[j].Date_Recrutement.Mois,buf.t[j].Date_Recrutement.Annee);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Grade                       >|");
 y=wherey();


gotoxy(x+57,y);printf("%s",buf.t[j].Grade);


gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Specialite                  >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Specialite);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Dernier diplome             >|");
        y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Dernier_Diplome);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();


printf(" |  |                  |< Etablissement universitaire >|");
y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Etablissement_Univ);
gotoxy(x+123,y);printf("             |  |\n");

       printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");



 }else{
 printf("  -L'enseignant recheche n'existe pas dans le fichier.\n ");
 }
}

void afficher_bloc(FLNOF f,int i,int *nbre_liredire,int *nbre_ecriredire)
{

  int j;
  int cp;
  Tbloc buf;
  LireDire(f,i,&buf);
  *(nbre_liredire)=(*nbre_liredire)+1;
  int x,y;
  char chaine[20];
textbackground(YELLOW);
textcolor(BLACK);


y=wherey() ;
x=wherex();
gotoxy(x+5,y);
 printf("|==========================|\n");textbackground(WHITE);
   y=wherey() ;
 x=wherex();
gotoxy(x+5,y);
 textbackground(YELLOW);
printf("|Precedent: ");
gotoxy(17,y);printf("%3d",buf.prec);
gotoxy(17+3,y);printf("             |\n");textbackground(WHITE);

   y=wherey() ;
   x=wherex();
gotoxy(x+5,y);
textbackground(YELLOW);
 printf("|==========================|\n");
 textbackground(WHITE);
    textcolor(RED);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                V\n");sleep(1);
    textcolor(BLACK);
sleep(0);
printf(" |=========================================================================================================================================|\n");
textbackground(YELLOW);
textcolor(BLACK);

y=wherey() ;
x=wherex();
gotoxy(x+1,y);

printf("|    Numero du bloc: ");
gotoxy(22,y);printf("%3d",i);
gotoxy(25,y);printf("    |  Nombre d'enseigants: ");
gotoxy(52,y);printf("%4d",buf.nb);
gotoxy(56,y);printf("                                                                                    |\n");

textbackground(WHITE);

printf(" |=========================================================================================================================================|\n");
printf(" |                                                                                                                                         |\n");


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
    j=0;

    while(j<buf.nb){
            if(buf.t[j].Sexe==1){
                strcpy(chaine,"Masculin");
            }else{
             strcpy(chaine,"Feminin");
            }


printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");

y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");
gotoxy(x+4,y);
textbackground(LIGHTCYAN);
textcolor(RED);

printf("| Deplacement: ");
gotoxy(x+4+15,y);printf("%4d",j);
gotoxy(x+4+4+10+2+2+1,y);
printf("|            Champ              |                   Information                                                  |");


textbackground(WHITE);
gotoxy(x+137,y);
textcolor(BLACK);
printf("  |\n");
y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");

printf("  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");
textcolor(BLACK);
x=wherex();
printf(" |  |                  |< Matricule                   >|");
 y=wherey();
gotoxy(x+57,y);printf("%d",buf.t[j].Matricule);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
printf(" |  |                  |< Nom                         >|");
y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Nom);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Prenom                      >|");

y=wherey();
 gotoxy(x+57,y);printf("%s",buf.t[j].Prenom);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
printf(" |  |                  |< Date de naissance           >|");
y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Naissance.Jour,buf.t[j].Date_Naissance.Mois,buf.t[j].Date_Naissance.Annee);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Wilaya de naissance         >|");

y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Wilaya_Naissance);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Sexe                        >|");
  y=wherey();
gotoxy(x+57,y);printf("%s",chaine);
gotoxy(x+123,y);printf("             |  |\n");
   x=wherex();

       printf(" |  |                  |< Groupe sanguin              >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Groupe_Sanguin);
gotoxy(x+123,y);printf("             |  |\n");
 x=wherex();

       printf(" |  |                  |< Date de recrutement         >|");

 y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",buf.t[j].Date_Recrutement.Jour,buf.t[j].Date_Recrutement.Mois,buf.t[j].Date_Recrutement.Annee);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Grade                       >|");
 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Grade);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Specialite                  >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Specialite);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Dernier diplome             >|");
        y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Dernier_Diplome);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();


printf(" |  |                  |< Etablissement universitaire >|");
y=wherey();
gotoxy(x+57,y);printf("%s",buf.t[j].Etablissement_Univ);
gotoxy(x+123,y);printf("             |  |\n");

       printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");


    printf(" |                                                                                                                                         |\n");



        cp++;
        j++;
        if(j%10==0 && j!=buf.nb){
            system("pause");
        }
    }



    //-----------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------

     printf(" |=========================================================================================================================================|\n");
       /*bloc suivant*/
       textbackground(WHITE);
    textcolor(RED);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                |\n");sleep(1);
    printf("                                V\n");sleep(1);
     textbackground(YELLOW);
    textcolor(BLACK);
sleep(0);
y=wherey() ;
x=wherex();
gotoxy(x+4+28,y);
 printf("|==========================|\n");
   y=wherey() ;
 x=wherex();
gotoxy(x+4+28,y);
printf("|Suivant: ");
gotoxy(17-2+28,y);printf("%3d",buf.suiv);
gotoxy(17-2+3+28,y);printf("              |\n");

   y=wherey() ;
   x=wherex();
gotoxy(x+4+28,y);
 printf("|==========================|\n");

 textbackground(WHITE);
    textcolor(BLACK);




}




void afficherE(Tenreg e,int j)
{


    char chaine[20];
    int x,y;







    if(e.Sexe==1){
                strcpy(chaine,"Masculin");
            }else{
             strcpy(chaine,"Feminin");
            }


printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");

y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");
gotoxy(x+4,y);
textbackground(LIGHTCYAN);
textcolor(RED);

printf("| Deplacement: ");
gotoxy(x+4+15,y);printf("%4d",j);
gotoxy(x+4+4+10+2+2+1,y);
printf("|            Champ              |                   Information                                                  |");


textbackground(WHITE);
gotoxy(x+137,y);
textcolor(BLACK);
printf("  |\n");
y=wherey();
x=wherex();
gotoxy(x+1,y);
printf("|");

printf("  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");
textcolor(BLACK);
x=wherex();
printf(" |  |                  |< Matricule                   >|");
 y=wherey();
gotoxy(x+57,y);printf("%d",e.Matricule);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
printf(" |  |                  |< Nom                         >|");
y=wherey();
 gotoxy(x+57,y);printf("%s",e.Nom);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Prenom                      >|");

y=wherey();
 gotoxy(x+57,y);printf("%s",e.Prenom);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
printf(" |  |                  |< Date de naissance           >|");
y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",e.Date_Naissance.Jour,e.Date_Naissance.Mois,e.Date_Naissance.Annee);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Wilaya de naissance         >|");

y=wherey();
gotoxy(x+57,y);printf("%s",e.Wilaya_Naissance);
gotoxy(x+123,y);printf("             |  |\n");

x=wherex();
       printf(" |  |                  |< Sexe                        >|");
  y=wherey();
gotoxy(x+57,y);printf("%s",chaine);
gotoxy(x+123,y);printf("             |  |\n");
   x=wherex();

       printf(" |  |                  |< Groupe sanguin              >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",e.Groupe_Sanguin);
gotoxy(x+123,y);printf("             |  |\n");
 x=wherex();

       printf(" |  |                  |< Date de recrutement         >|");

 y=wherey();
gotoxy(x+57,y);printf("%d/%d/%d",e.Date_Recrutement.Jour,e.Date_Recrutement.Mois,e.Date_Recrutement.Annee);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Grade                       >|");
 y=wherey();


gotoxy(x+57,y);printf("%s",e.Grade);


gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Specialite                  >|");

 y=wherey();
gotoxy(x+57,y);printf("%s",e.Specialite);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();
       printf(" |  |                  |< Dernier diplome             >|");
        y=wherey();
gotoxy(x+57,y);printf("%s",e.Dernier_Diplome);
gotoxy(x+123,y);printf("             |  |\n");
x=wherex();


printf(" |  |                  |< Etablissement universitaire >|");
y=wherey();
gotoxy(x+57,y);printf("%s",e.Etablissement_Univ);
gotoxy(x+123,y);printf("             |  |\n");

       printf(" |  |-----------------------------------------------------------------------------------------------------------------------------------|  |\n");




}



void afficher3B(FLNOF f){

clrscr();
//affichage  exeterne

int marge=5,x,y;
int tmpy;
Tbloc buf;
int i;
int lire=0,ecr=0;
int cpt;

int l;
if(Entete(f,4)>=3){
printf("\n\n -Voulez-vous afficher l'organisation interne des 3 premiers blocs?\n\n");
l=ouinon();
if(l==1){



        system("cls");

printf(" \n\n\n                         --<< Affichage internes des 3 premiers bloc du fichier >>-- \n\n");


i=Entete(f,1);



if(i!=-1){
afficher_bloc(f,i,&lire,&ecr);

}

printf("\n\n\n");
LireDire(f,i,&buf);
i=buf.suiv;

if(i!=-1){
afficher_bloc(f,i,&lire,&ecr);

}
printf("\n\n\n");


LireDire(f,i,&buf);
i=buf.suiv;

if(i!=-1){
afficher_bloc(f,i,&lire,&ecr);

}
printf("\n\n\n");
textcolor(BLACK);


printf("  -Le cout de cet affichage est: \n\n");
textcolor(BLUE);
printf("                => Nombre de LireDir: %d\n",lire);
printf("                => Nombre de EcrireDir: %d\n",ecr);
textcolor(BLACK);
printf("\n\n\n");


}

printf("\n\n -Voulez-vous afficher l'organisation externe des 3 premiers blocs?\n\n");
l=ouinon();
if(l==1){
system("cls");
printf("\n\n\n                          --<< Affichage externe des 3 premiers bloc du fichier >>-- \n\n");

textcolor(BLACK);
LireDire(f,Entete(f,1),&buf);

textbackground(YELLOW);

y=wherey() ;
x=wherex();
gotoxy(x+5,y);
 printf("|==========================|\n");textbackground(WHITE);
   y=wherey() ;
 x=wherex();
gotoxy(x+5,y);
 textbackground(YELLOW);
printf("|Precedent: ");
gotoxy(17,y);printf("%3d",buf.prec);
gotoxy(17+3,y);printf("             |\n");textbackground(WHITE);

   y=wherey() ;
   x=wherex();
gotoxy(x+5,y);
textbackground(YELLOW);
 printf("|==========================|\n");
 textbackground(WHITE);
    textcolor(RED);
    printf("                                |\n");//sleep(1);
    printf("                                |\n");//sleep(1);
    printf("                                |\n");//sleep(1);
    printf("                                V\n");//sleep(1);
    textcolor(BLACK);
sleep(0);
 tmpy=wherey() ;
 y=wherey() ;

gotoxy(marge,y);
printf("=====================================\n");
 y=wherey() ;

gotoxy(marge,y);printf("| Nb_enreg: %4d",buf.nb);
gotoxy(marge+16+30-5-5,y);printf("|\n");y=wherey() ;

gotoxy(marge,y);printf("=====================================\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|                                   |\n");y=wherey() ;

gotoxy(marge,y);printf("|===================================|\n");y=wherey() ;

y=wherey() ;

gotoxy(marge,y);printf("| Suivant: %4d",buf.suiv);
gotoxy(marge+16+30-5-5,y);printf("|\n");y=wherey() ;

gotoxy(marge,y);printf("|===================================|\n");y=wherey() ;
gotoxy(marge,y);printf("                                    |");y=wherey() ;
textcolor(RED);
y=wherey();
x=wherex();
gotoxy(x+marge-10+5,y-2);printf("============>\n");
textcolor(BLACK);


int tmp;
tmp=buf.suiv;
LireDire(f,tmp,&buf);

y=tmpy;
gotoxy(marge+50,y);printf("=====================================\n");
 y=wherey() ;

gotoxy(marge+50,y);printf("| Nb_enreg: %4d",buf.nb);
gotoxy(marge+16+50+30-5-5,y);printf("|\n");
 y=wherey() ;

gotoxy(marge+50,y);printf("=====================================\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+50,y);printf("|===================================|\n"); y=wherey() ;


gotoxy(marge+50,y);printf("| Suivant: %4d",buf.suiv);
gotoxy(marge+50+16+30-5-5,y);printf("|\n");y=wherey() ;


gotoxy(marge+50,y);printf("|===================================|\n"); y=wherey() ;





gotoxy(marge+50,y);
printf("                                     ");


textcolor(RED);
y=wherey();
x=wherex();
gotoxy(x,y-2);printf("============>\n");
textcolor(BLACK);


tmp=buf.suiv;
LireDire(f,tmp,&buf);

y=tmpy;
gotoxy(marge+100,y);printf("=====================================\n");
 y=wherey() ;

gotoxy(marge+100,y);printf("| Nb_enreg: %4d",buf.nb);
gotoxy(marge+16+100+30-5-5,y);printf("|\n");
 y=wherey() ;

gotoxy(marge+100,y);printf("=====================================\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|                                   |\n"); y=wherey() ;

gotoxy(marge+100,y);printf("|===================================|\n"); y=wherey() ;


gotoxy(marge+100,y);printf("| Suivant: %4d",buf.suiv);
gotoxy(marge+100+16+30-5-5,y);printf("|\n");y=wherey() ;


gotoxy(marge+100,y);printf("|===================================|\n"); y=wherey() ;

}

}else{
printf("\n\n  -Le fichier a moins de 3 blocs. \n\n");
}

}

