
#include "bib.h"
#include <stdarg.h>

/***************************** MODULES D'AFFICHAGE ***********************************************************************/

void Ouverture(){
    int x=30,y=15;

textcolor(LIGHTBLUE);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("                              _________________________________________________________________\n");
y++;

printf("                             |||______________________________________________________________|||\n");
y++;
printf("                             | |                                                              | |\n");
y++;
printf("                             | |                                                              | |\n");
y++;
textcolor(BLACK);


textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+5,y);printf("                     .&&&&.  .&&&&&&  (&&)                  ");
y++;
textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+25,y);printf("&&&  &&& &&&      &&&                   ");
y++;

textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+25,y);printf("&&&&&&&& .&&&&.   &&&                   ");
y++;

textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+25,y);printf("&&&.         &&&  &&&                   ");
y++;
textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+25,y);printf("'&&&&&   &&&&&&'  &&&                   ");
y++;

textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |--------------------------------------------------------------| |");
y++;
textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |");
textcolor(LIGHTBLUE);gotoxy(x+65,y);printf("| |");
textcolor(BLACK);gotoxy(x+8,y);printf(" Ecole Nationale Sup\x82rieure d'Informatique (ESI ex INI)  ");
y++;
textcolor(LIGHTBLUE);gotoxy(x,y);printf("| |--------------------------------------------------------------| |");
y++;

}








void home(){
    int x,y=0;
    char c=219;
    int marge=35;
    textbackground(WHITE);
    textcolor(BLACK);
    textbackground(WHITE);
    textcolor(BLUE);
gotoxy(1,y+5);    printf("                                  ");

gotoxy(marge,y+5);printf(" ___________________________________________________________________________________________\n");
gotoxy(1,y+6);    printf("                                  ");

gotoxy(marge,y+6);printf("/    _____________________________________________________________________________________    \\\n");
gotoxy(1,y+7);    printf("                                  ");

gotoxy(marge,y+7);printf("|   |                                                                                     |   |\n");
gotoxy(marge,y+7);printf("|   | >_");
y=wherey();
x=wherex();
textcolor(BLUE);
gotoxy(1,y);    printf("                                  ");

gotoxy(marge+5+5+3,y);printf("    _                                                                        |   |\n");
y=wherey();
x=wherex();
gotoxy(1,y);    printf("                                  ");


gotoxy(x+marge-1,y);printf("|   |           (_)                                                                       |   |\n");

y=wherey();
x=wherex();
gotoxy(1,y);    printf("                                  ");

gotoxy(x+marge-1,y);printf("|   |   ");
textcolor(BLACK);
gotoxy(x+marge-1+5+3,y);printf("___  ___ _");
textcolor(BLUE);
gotoxy(x+marge-1+5+3+10,y);printf("                                                                        |   |\n");

y=wherey();
x=wherex();
gotoxy(1,y);    printf("                                  ");

gotoxy(x+marge-1,y);
printf("|   |  ");
textcolor(BLACK);

gotoxy(x+marge-1+7,y);printf("/ _ \\/ __| |   Ecole Nationale Supérieure d'Informatique (Ex. INI)                 ");
textcolor(BLUE);

gotoxy(x+marge+89,y);printf("|   |\n");

y=wherey();
x=wherex();
gotoxy(1,y);    printf("                                  ");

gotoxy(x+marge-1,y);
printf("|   |  ");
textcolor(BLACK);
gotoxy(x+marge+4,y);
printf(" |  __/\\__ \\ |   Cycle preparatoire integre (2CPI)                                   ");
textcolor(BLUE);

gotoxy(x+marge+89,y);printf("|   |\n");



y=wherey();
x=wherex();
gotoxy(1,y);    printf("                                  ");

gotoxy(x+marge-1,y);
printf("|   |  ");
gotoxy(x+marge+4,y);
textcolor(BLACK);
printf("  \\___||___/_|                                                                       ");
textcolor(BLUE);

gotoxy(x+marge+89,y);printf("|   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");
gotoxy(marge,y);printf("|   |                                                                                     |   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);
printf("|   |   ");
gotoxy(marge+5+2,y);textcolor(RED);printf("Programe: ");
textcolor(BLACK);
gotoxy(marge+5+10+2,y);printf("Construction d'un fichier binaire contenant les informations relatives   ");
textcolor(BLUE);

gotoxy(x+marge+89,y);printf("|   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");


gotoxy(marge,y);
printf("|   |   ");
textcolor(BLACK);
gotoxy(marge+5+10+2-9,y);printf("         aux enseignants de tous les etablissements universitaires algeriens.     ");
textcolor(BLUE);

gotoxy(x+marge+89,y);printf("|   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");


gotoxy(marge,y);
printf("|   |   ");
gotoxy(marge+5+2,y);textcolor(RED);printf("Realise par:   ");
textcolor(BLACK);
gotoxy(marge+5+2+15,y);printf("HAFIS Mellissa   REMIL Maha Fatimazohra                              ");
textcolor(BLUE);
gotoxy(x+marge+89,y);printf("|   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");


gotoxy(marge,y);
printf("|   |   ");

textcolor(BLACK);
gotoxy(marge+5+2,y);printf("                Section A G02    Section B G06                                       ");
textcolor(BLUE);
gotoxy(x+marge+89,y);printf("|   |\n");

x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");


gotoxy(marge,y);
printf("|   |   ");

textcolor(BLACK);
gotoxy(marge+5+2,y);textcolor(RED);printf("Encadre par: ");


textcolor(BLACK);
gotoxy(marge+5+2+12,y);printf(" Dr. KERMI Adel                                                        ");
textcolor(BLUE);
gotoxy(x+marge+89,y);printf("|   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");
x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");


gotoxy(marge,y);
printf("|   |   ");

gotoxy(marge+5+2,y);textcolor(RED);
printf("Annee universitaire:");

textcolor(BLACK);
gotoxy(marge+5+2+12+8,y);printf(" 2022/2023                                                     ");
textcolor(BLUE);
gotoxy(x+marge+89,y);printf("|   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);printf("|   |                                                                                     |   |\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);

printf("|   |_____________________________________________________________________________________|   |\n");

x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);
printf("\\_____________________________________________________________________________________________/\n");


x=wherex();
y=wherey();
gotoxy(1,y);    printf("                                  ");

gotoxy(marge,y);
printf("                    \\________________________________________________/     \n");






}



//2-affichage des fenetres
void fenetre(){
    int y=5,x=1;
textcolor(LIGHTRED);

gotoxy(x,y);textbackground(LIGHTBLUE);printf("£££££££££££££££££££££££££££££££######################################################################\n");
y=y+1;
textbackground(BLACK);
gotoxy(x,y);printf("#");
gotoxy(x+100,y);printf("#");
y=y+1;
gotoxy(x,y);printf("#");
gotoxy(x+100,y);printf("#");
y=y+1;
gotoxy(x,y);printf("#####################################################################################################\n");

  }
//3-affichage du menu
/********************************************************************************************************/

//LIGHTMAGENTA,MAGENTA, LIGHTBLUE,BLUE, YELLOW
void bleu(){textbackground( LIGHTCYAN);}
void vert(){textcolor( BLUE);}
void noire(){textbackground(WHITE);}
void jaunet(){textcolor(BROWN);}
void noiret(){textcolor( BLACK);}
void bleut(){textcolor(BLUE);}
void rouget(){textcolor(RED);}

void menu_principal(){
    textcolor(BLUE);
     printf("\n\n");
    printf("     __  __                    _____      _            _             _ \n");
    printf("    |  \\/  |                  |  __ \\    (_)          (_)           | |\n");
    printf("    | \\  / | ___ _ __  _   _  | |__) | __ _ _ __   ___ _ _ __   __ _| |\n");
    printf("    | |\\/| |/ _ \\ '_ \\| | | | |  ___/ '__| | '_ \\ / __| | '_ \\ / _` | |\n");
    printf("    | |  | |  __/ | | | |_| | | |   | |  | | | | | (__| | |_) | (_| | |\n");
    printf("    |_|  |_|\\___|_| |_|\\__,_| |_|   |_|  |_|_| |_|\\___|_| .__/ \\__,_|_|\n");
    printf("                                                        | |            \n");
    printf("                                                        |_|            \n\n");

textcolor(BLACK);
}
void returnToMenu()
{
    //gotoxy(4,28);
    printf("\n\n");
    textcolor(BLACK);
    printf ("          +---------------------------------------------------------------------------------------------------------------------------+\n");
    printf ("          |                                        ");
    textcolor(BLACK);
    printf("[ ");
    textcolor(BLACK);
    printf ("ENTER");
    textcolor(BLACK);
    printf (" ] ");
    textcolor(BLACK);
    printf ("Pour revenir au MENU PRINCIPAL");
    textcolor(BLACK);
    printf("                                           |\n");
    printf ("          +---------------------------------------------------------------------------------------------------------------------------+\n");


    getch();
    system("cls");
}



int menu2(int max,...)


{
    int choi,o,i,v,d,y;
    char p[tmax];
    char **choix=NULL;
    choix=malloc(max*sizeof(p));
    va_list marker;
    va_start( marker,max);
    for (i=0; i<max; i++)
    {
        choix[i] = va_arg( marker,char*);
    }
    va_end( marker );
    d=wherey();
    y=d;
    textcolor (selected_color);
    textbackground (selected_background);
    printf("%s\n",choix[0]);
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    for (i=1; i<max; i++)
    {
        printf("%s\n",choix[i]);
    }
abbbbb:
    while((o=getch())==224)
    {
        v=getch();
        if(v==80 && y<d+max-1)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y++;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i+1]);
        }
        if(v==72 && y>d)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y--;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i-1]);
        }


    }
    if (o!=13)goto abbbbb;

    choi=y-d;
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    gotoxy(1,d+4);
    return choi+1;
    printf("\t|=======================================================================================================|\n");
}

void creation_fichier(){
 textcolor(BLUE);
    printf("\n\n");
    printf("       ____       __       _   _               _____ _      _     _           \n");
    printf("      / ___|_ __ /_/  __ _| |_(_) ___  _ __   |  ___(_) ___| |__ (_) ___ _ __ \n");
    printf("     | |   | '__/ _ \\/ _` | __| |/ _ \\| '_ \\  | |_  | |/ __| '_ \\| |/ _ \\ '__|\n");
    printf("     | |___| | |  __/ (_| | |_| | (_) | | | | |  _| | | (__| | | | |  __/ |   \n");
    printf("      \\____|_|  \\___|\\__,_|\\__|_|\\___/|_| |_| |_|   |_|\\___|_| |_|_|\\___|_|   \n\n");
    textcolor(BLACK);}

void fichier_mesres(){
    int x,y;

        printf("\n");
        textcolor(BLUE);

        printf("                            ______ _      _     _             __  __ ______  _____ _____   _____  \n");
        printf("                           |  ____(_)    | |   (_)           |  \\/  |  ____|/ ____|  __ \ / ____|  \n");
        printf("                           | |__   _  ___| |__  _  ___ _ __  |  \\/  | |__  | (___ | |__) | (___   \n");
        printf("                           | |    | | (__| | | | |  __/ |    | |  | | |____ ____) | | \\ \\ ____) | \n");
        printf("                           |_|    |_|\\___|_| |_|_|\\___|_|    |_|  |_|______|_____/|_|  \\_\\_____/  \n");
        textbackground(YELLOW);
        x=wherex();
        y=wherey();
        gotoxy(x+20+5,y);printf(">~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~<\n");
        textbackground(WHITE);
textcolor(BLACK);

    }
    void cdg(){
        textcolor(BLUE);

printf("  _____            _                      \n");
printf(" / ____|          | |                    \n");
printf(" | |     ___    __| | __ _  __ _  ___    \n");
printf(" | |    / _ \\ / _`  |/ _` |/ _` |/ _ \\  \n") ;
printf(" | |___| (_) | (_|  | (_| | (_| |  __/   \n");
printf(" \\_____ \\___/ \\__,_ |\\__,_|\\__, |\\___|   \n");
printf("                            __/ |        \n");
textcolor(BLACK);

    }

    void dcdg()
    {

textcolor(BLUE);
printf("  ______                     _     \n");
printf(" |  ____|                   | |     \n");
printf(" | |__   _ __   ___ ___   __| | __ _  __ _  ___ \n");
printf(" |  __| | '_ \\ / __/ _ \\ / _` |/ _` |/ _` |/ _ \\ \n");
printf(" | |____| | | | (_| (_) | (_| | (_| | (_| |  __/ \n");
printf(" |______|_| |_|\\___\\___/ \\__,_|\\__,_|\\__, |\\___| \n");
printf("                                      __/ |     \n");
printf("                                     |___/      \n ");

textcolor(BLACK);

    }





    void fin(){

char AsciiCode = 219;
int x,y;
    textcolor(BLACK);
    clrscr();
    printf ("\n\n\tSauvgrade des fichiers en cours [");
    for  (int i=0; i<=40; i++)
    {
        textcolor(BLUE);
        printf ("%c",219);Sleep(18);

    }
    textcolor(BLACK);
    printf ("] TERMINE \n\n\n\n");
    Sleep(300);

x=wherex();
y=wherey();
gotoxy(x+30,y);
    textcolor(RED);

  printf("             _     _              _   //\\  _\n ");
  x=wherex();
y=wherey();
gotoxy(x+30,y);
printf("    /\\     | |   (_)            | | |/ \\|| |  \n");
x=wherex();
y=wherey();
gotoxy(x+30,y);
printf("    /  \\    | |__  _  ___ _ __   | |_ ___ | |_ \n");
x=wherex();
y=wherey();
gotoxy(x+30,y);
printf("   / /\\ \\   | '_ \\| |/ _ \\ '_ \\  | __/ _ \\| __|\n");
x=wherex();
y=wherey();
gotoxy(x+30,y);
printf("  / ____ \\  | |_) | |  __/ | | | | || (_) | |_ \n");
x=wherex();
y=wherey();
gotoxy(x+30,y);
printf(" /_/    \\_\\ |_.__/|_|\\___|_| |_|  \\__\\___/ \\__|\n");
textcolor(BLACK);

}

void Ouverture2(){
int marge=30;
int x,y;
int c=219;

printf("\n\n\n\n");
textcolor(BLUE);
x=wherex();
y=wherey();
gotoxy(x+marge,y);

printf("                                  ___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("                             ___---___---___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("                       ___---___---    *    ---___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("                 ___---___---    o/ 0_/  @  o ^   ---___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("           ___---___--- @  i_e J-U /|  -+D O|-| (o) /   ---___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("     ___---___---    __/|  //\  /|  |\  /\  |\|  |_  __--oj   ---___---___\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("__---___---_________________________________________________________---___---__\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("===============================================================================\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);

printf(" ||||                                                                     ||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf(" |---------------------------------------------------------------------------|\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf(" |___-----___-----___-----___-----___-----___-----___-----___-----___-----___|\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("      ===             ===             ===             ===             ===\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |=====|         |=====|         |=====|         |=====|         |=====|\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    |||||||         |||||||         |||||||         |||||||         |||||||\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    (oOoOo)         (oOoOo)         (oOoOo)         (oOoOo)         (oOoOo)\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("    J#####L         J#####L         J#####L         J#####L         J#####L\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("   ZZZZZZZZZ       ZZZZZZZZZ       ZZZZZZZZZ       ZZZZZZZZZ       ZZZZZZZZZ\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("  ===========================================================================\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("__|_________________________________________________________________________|__\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("_|___________________________________________________________________________|_\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("|_____________________________________________________________________________|\n"); Sleep(150);
x=wherex();
y=wherey();
gotoxy(x+marge,y);
printf("_______________________________________________________________________________\n"); Sleep(150);
printf("\n\n");
textcolor(RED);
printf("                                 -> Ministere de l'Enseignement sup\x82rieur et de la Recherche scientifique <-           \n");


        printf("                                                 __  __ ______  _____ _____   _____  \n");
        printf("                                                |  \\/  |  ____|/ ____|  __ \ / ____|  \n");
        printf("                                                |  \\/  | |__  | (___ | |__) | (___   \n");
        printf("                                                | |  | | |____ ____) | | \\ \\ ____) | \n");
        printf("                                                |_|  |_|______|_____/|_|  \\_\\_____/  \n");
textcolor(BLACK);
printf("\n\n\n\n\n");
}



void newprof(){
    textcolor(BLUE);
printf("  _   _                       _                       _                         _ \n");
printf(" | \\ | |                     | |                     (_)                       | | \n");
printf(" |  \\| | ___  _   ___   _____| |   ___ _ __  ___  ___ _  __ _ _ __   __ _ _ __ | |_ \n");
printf(" | . ` |/ _ \\| | | \\ \\ / / _ \\ |  / _ \\ '_ \\/ __|/ _ \\ |/ _` | '_ \\ / _` | '_ \\| __|\n");
printf(" | |\\  | (_) | |_| |\\ V /  __/ | |  __/ | | \\__ \\  __/ | (_| | | | | (_| | | | | |_ \n");
printf(" |_| \\_|\\___/ \\__,_| \\_/ \\___|_|  \\___|_| |_|___/\\___|_|\\__, |_| |_|\\__,_|_| |_|\\__|\n");
printf("                                                         __/ |  \n");
printf("                                                        |___/   \n");
textcolor(BLACK);
}
void transfert(){
    textcolor(BLUE);

printf("  _______                   __          _         _ _                                   _                         _  \n");
printf(" |__   __|                 / _|        | |       | ( )                                 (_)                       | |\n");
printf("    | |_ __ __ _ _ __  ___| |_ ___ _ __| |_    __| |/ _   _ _ __     ___ _ __  ___  ___ _  __ _ _ __   __ _ _ __ | |_\n");
printf("    | | '__/ _` | '_ \\/ __|  _/ _ \\ '__| __|  / _` | | | | | '_ \\   / _ \\ '_ \\/ __|/ _ \\ |/ _` | '_ \\ / _` | '_ \\| __|\n");
printf("    | | | | (_| | | | \\__ \\ ||  __/ |  | |_  | (_| | | |_| | | | | |  __/ | | \\__ \\  __/ | (_| | | | | (_| | | | | |_ \n");
printf("    |_|_|  \\__,_|_| |_|___/_| \\___|_|   \\__|  \\__,_|  \\__,_|_| |_|  \\___|_| |_|___/\\___|_|\\__, |_| |_|\\__,_|_| |_|\\__|\n");
printf("                                                                                           __/ |  \n");
printf("                                                                                          |___/    \n");
textcolor(BLACK);
  }
void supm(){
textbackground(WHITE);
textcolor(BLUE);

printf(" __                                     _                   _ _                                  _                         _   \n");
printf("/ _\\_   _ _ __  _ __  _ __ ___  ___ ___(_) ___  _ __     __| ( )   _ _ __     ___ _ __  ___  ___(_) __ _ _ __   __ _ _ __ | |_ \n");
printf("\\ \\| | | | '_ \\| '_ \\| '__/ _ \\/ __/ __| |/ _ \\| '_ \\   / _` |/ | | | '_ \\   / _ \\ '_ \\/ __|/ _ \\ |/ _` | '_ \\ / _` | '_ \\| __|\n");
printf("_\\ \\ |_| | |_) | |_) | | |  __/\\__ \\__ \\ | (_) | | | | | (_| || |_| | | | | |  __/ | | \\__ \\  __/ | (_| | | | | (_| | | | | |_ \n");
printf("\\__/\\__,_| .__/| .__/|_|  \\___||___/___/_|\\___/|_| |_|  \\__,_| \\__,_|_| |_|  \\___|_| |_|___/\\___|_|\\__, |_| |_|\\__,_|_| |_|\\__|\n");
printf("         |_|   |_|                                                                                 |___/\n");

textcolor(BLACK);

}
void sups(){
    textcolor(BLUE);

 printf("   _____                                     _                   _ _                                        _       _ _ _ \n");
printf("  / ____|                                   (_)                 | ( )                                      (_)     | (_) |  \n");
printf(" | (___  _   _ _ __  _ __  _ __ ___  ___ ___ _  ___  _ __     __| |/ _   _ _ __   ___   ___ _ __   ___  ___ _  __ _| |_| |_ ___ \n");
printf("  \___ \| | | | '  _ \\| '_ \\| '__/ _ \\/ __/ __| |/ _ \\| '_ \\\   / _` | | | | | '_ \\ / _ \\ / __| '_ \\ / _ \\/ __| |/ _` | | | __/ _ \\ \n");
printf("  ____) | |_| | |_) | |_) | | |  __/\\__ \\__ \\ | (_) | | | | | (_| | | |_| | | | |  __/ \\__ \\ |_) |  __/ (__| | (_| | | | ||  __/      \n");
printf(" |_____/ \\__,_| .__/| .__/|_|  \\___||___/___/_|\\___/|_| |_|  \\__,_|  \\__,_|_| |_|\\___| |___/ .__/ \\___|\\___|_|\\__,_|_|_|\\__\\___| \n");
printf("              | |   | |                                                                    | | \n");
printf("              |_|   |_|                                                                    |_| \n");

textcolor(BLACK);
    }
    void reseauest(){

textcolor(BLUE);
    printf("  _____                                  _        _ _           _ \n");
printf(" |  __ \\                                | |      | ( )         | | \n");
printf(" | |__) |___  ___  ___  __ _ _   _    __| | ___  | |/  ___  ___| |_ \n");
printf(" |  _  // _ \\/ __|/ _ \\/ _` | | | |  / _` |/ _ \\ | |  / _ \\/ __| __|\n");
printf(" | | \\ \\  __/\\__ \\  __/ (_| | |_| | | (_| |  __/ | | |  __/\\__ \\ |_ \n");
printf(" |_|  \\_\\___||___/\\___|\\__,_|\\__,_|  \\__,_|\\___| |_|  \\___||___/\\__|\n");
textcolor(BLACK);
}
void reseaucentre(){
    textcolor(BLUE);

printf("  _____                                  _                        _            \n");
printf(" |  __ \\                                | |                      | |\n");
printf(" | |__) |___  ___  ___  __ _ _   _    __| |_   _    ___ ___ _ __ | |_ _ __ ___ \n");
printf(" |  _  // _ \\/ __|/ _ \\/ _` | | | |  / _` | | | |  / __/ _ \\ '_ \\| __| '__/ _ \\  \n");
printf(" | | \\ \\  __/\\__ \\  __/ (_| | |_| | | (_| | |_| | | (_|  __/ | | | |_| | |  __/ \n");
printf(" |_|  \\_\\___||___/\\___|\\__,_|\\__,_|  \\__,_|\\__,_|  \\___\\___|_| |_|\\__|_|  \\___|  \n");
textcolor(BLACK);

}


void reseauouest(){
    textcolor(BLUE);

printf("  _____                                  _        _ _                       _  \n");
printf(" |  __ \\                                | |      | ( )                     | |  \n");
printf(" | |__) |___  ___  ___  __ _ _   _    __| | ___  | |/  ___  _   _  ___  ___| |_ \n");
printf(" |  _  // _ \\/ __|/ _ \\/ _` | | | |  / _` |/ _ \\ | |  / _ \\| | | |/ _ \\/ __| __|\n");
printf(" | | \\ \\  __/\\__ \\  __/ (_| | |_| | | (_| |  __/ | | | (_) | |_| |  __/\\__ \\ |_ \n");
printf(" |_|  \\_\\___||___/\\___|\\__,_|\\__,_|  \\__,_|\\___| |_|  \\___/ \\__,_|\\___||___/\\__|\n");
textcolor(BLACK);
 }

void requette(){
    textcolor(BLUE);
printf("  _____                   //\\ _   _          __     _       _                       _ _      \n");
printf(" |  __ \\                 |/ \\| | | |         \\_\\   (_)     | |                     | | |  \n");
printf(" | |__) |___  __ _ _   _  ___| |_| |_ ___    __ _   _ _ __ | |_ ___ _ ____   ____ _| | | ___ \n");
printf(" |  _  // _ \\/ _` | | | |/ _ \\ __| __/ _ \\  / _` | | | '_ \\| __/ _ \\ '__\\ \\ / / _` | | |/ _ \\\n");
printf(" | | \\ \\  __/ (_| | |_| |  __/ |_| ||  __/ | (_| | | | | | | ||  __/ |   \\ V / (_| | | |  __/\n");
printf(" |_|  \\_\\___|\\__, |\\__,_|\\___|\\__|\\__\\___|  \\__,_| |_|_| |_|\\__\\___|_|    \\_/ \\__,_|_|_|\\___|\n");
printf("                | | \n");
printf("                |_|  \n");

textcolor(BLACK);
  }

void ent(){
textcolor(BLUE);
printf("  _      _            _       _             _          __ _      _     _     \n");
printf(" | |    ( )          | |     | |           | |        / _(_)    | |   (_)         \n");
printf(" | |    |/  ___ _ __ | |_ ___| |_ ___    __| |_   _  | |_ _  ___| |__  _  ___ _ __ \n");
printf(" | |       / _ \\ '_ \\| __/ _ \\ __/ _ \\  / _` | | | | |  _| |/ __| '_ \\| |/ _ \\ '__|\n");
printf(" | |____  |  __/ | | | ||  __/ ||  __/ | (_| | |_| | | | | | (__| | | | |  __/ |   \n");
printf(" |______|  \\___|_| |_|\\__\\___|\\__\\___|  \\__,_|\\__,_| |_| |_|\\___|_| |_|_|\\___|_|   \n");

          textcolor(BLACK);
}



int ouinon(){

textbackground(WHITE);

int c2,cpt1=1,choix;
   int y, up=77,down=75,margin=10;

 y=wherey();

    gotoxy(margin+13,y);bleu(); printf("|  Oui  |");noire();

    gotoxy(margin+13+5+5,y); printf("|  Non  |");





      do{
        c2=getch();
        if(c2==up){cpt1%=2;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=2;}
        noire();


   gotoxy(margin+13,y); if(cpt1==1)bleu();printf("|  Oui  |");noire();

    gotoxy(margin+23,y);if(cpt1==2)bleu(); printf("|  Non  |");noire();




} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}



int spes(){




textbackground(WHITE);


int c2,cpt1=1,choix;
   int y,tmp, up=80,down=72,margin=5;


    y=wherey();
    tmp=y;
     gotoxy(margin,y++); textcolor(BLUE); printf(" ===================================================== Liste des specialites =======================================================================================\n\n");noiret();
    y++;
gotoxy(margin+5,y++);bleu(); printf("01-Informatique\n");noire();
    y++;
    gotoxy(margin+5,y++); printf("02-Architecture\n");
    y++;
    gotoxy(margin+5,y++); printf("03-Medecine\n");
    y++;
    gotoxy(margin+5,y++);printf("04-Veterinaire\n");
    y++;
    gotoxy(margin+5,y++);printf("05-Pharmacie\n");
    y++;
    gotoxy(margin+5,y++); printf("06-Mathematique\n");
    y++;
    gotoxy(margin+5,y++); printf("07-Physique\n");
    y++;
    gotoxy(margin+5,y++); printf("08-Medecine dentaire\n");
    y++;
    gotoxy(margin+5,y++);  printf("09-Agriculture saharienne\n");
    y++;
    gotoxy(margin+5,y++);  printf("10-Agronomie\n");
    y++;
    gotoxy(margin+5,y++);printf("11-Sciences et technologies\n");
    y++;
    gotoxy(margin+5,y++);printf("12-Sciences de la matiere\n");
    y++;
    gotoxy(margin+5,y++);printf("13-Sciences de la nature et de la vie\n");
    y++;
    gotoxy(margin+5,y++);  printf("14-Sciences economoiques\n");
    y++;
   gotoxy(margin+5,y++); printf("15-Sciences politiques\n");
    y++;
   gotoxy(margin+5,y++); printf("16-Droit\n");
    y++;
   gotoxy(margin+5,y++); printf("17-Langue francaise\n");
    y++;
   gotoxy(margin+5,y++); printf("18-Langue anglaise\n");
    y++;
   gotoxy(margin+5,y++);printf("19-Sciences humaines\n");
    y++;
   gotoxy(margin+5,y++);printf("20-Sciences sociales\n");

//partie 2
    y=tmp+2;
    gotoxy(margin+5+38,y++); printf("21-Sciences islamiques\n");
    y++;
   gotoxy(margin+5+38,y++);printf("22-Langue et litterature arabes\n");
    y++;
   gotoxy(margin+5+38,y++);  printf("23-Sciences financieres et comptabilite\n");
    y++;
   gotoxy(margin+5+38,y++); printf("24-Genie civil\n");
   y++;
   gotoxy(margin+5+38,y++);  printf("25-Travaux publics\n");
    y++;
   gotoxy(margin+5+38,y++); printf("26-Gestion des techniques urbaines\n");
     y++;
  gotoxy(margin+5+38,y++); printf("27-Geographie et amenagement du territoire\n");
  y++;
  gotoxy(margin+5+38,y++); printf("28-Geologie\n");
  y++;
  gotoxy(margin+5+38,y++);printf("29-Science des activites physiques et sportives\n");
    y++;
   gotoxy(margin+5+38,y++); printf("30-Telecommunications\n");

    y++;
   gotoxy(margin+5+38,y++); printf("31-Sciences alimentaires\n");
    y++;
   gotoxy(margin+5+38,y++);printf("32-Sciences de gestion\n");
    y++;
   gotoxy(margin+5+38,y++); printf("33-Droit public\n");
    y++;
   gotoxy(margin+5+38,y++); printf("34-Sciences veterinaires\n");
    y++;
   gotoxy(margin+5+38,y++); printf("35-Langue et culture amazighes\n");
    y++;
   gotoxy(margin+5+38,y++); printf("36-Traduction interpretariat\n");
    y++;
   gotoxy(margin+5+38,y++); printf("37-Hydraulique\n");
y++;
 gotoxy(margin+5+38,y++); printf("38-Biotechnologie\n");
   y++;
   gotoxy(margin+5+38,y++); printf("39-Urabanisme\n");
    y++;
   gotoxy(margin+5+38,y++);printf("40-Aeronautique\n");



//partie3

  y=tmp+2;

  gotoxy(margin+91,y++); printf("41-Genie des procedes\n");
  y++;
  gotoxy(margin+91,y++);printf("42-Energies renouvelables\n");
  y++;
  gotoxy(margin+91,y++);printf("43-Electrotechnique\n");
  y++;
  gotoxy(margin+91,y++);printf("44-Genie macanique\n");
  y++;
  gotoxy(margin+91,y++); printf("45-Langue italienne\n");
  y++;
  gotoxy(margin+91,y++);printf("46-Management\n");
  y++;
  gotoxy(margin+91,y++);printf("47-Sciences appliquees\n");
  y++;
   gotoxy(margin+91,y++);printf("48-Genie industriel\n");
  y++;
   gotoxy(margin+91,y++); printf("49-Geniebiomedical\n");
  y++;
  gotoxy(margin+91,y++); printf("50-Langue espagnole\n");
  y++;
  gotoxy(margin+91,y++); printf("51-Arts\n");
  y++;
  gotoxy(margin+91,y++);printf("52-Metiers de la ville\n");
  y++;
  gotoxy(margin+91,y++);printf("53-Langue allmande\n");
  y++;
  gotoxy(margin+91,y++);printf("54-Microbiologie fondamentale et appliquee\n");
  y++;
  gotoxy(margin+91,y++);printf("55-Journalisme et sciences de l'information\n");
  y++;
  gotoxy(margin+91,y++);printf("56-Geophysique\n");
  y++;
  gotoxy(margin+91,y++);printf("57-Langue turque\n");
 y++;
 gotoxy(margin+91,y++);printf("58-Langue russe\n");
  y++;
  gotoxy(margin+91,y++);printf("59-Optique et macanique de precision\n");
  y++;
  gotoxy(margin+91,y++);printf("60-Industries petrochimiques\n");

//partie 4
  y=tmp+2;

  gotoxy(margin+100+30,y++);printf("61-Genie minier\n");
  y++;
  gotoxy(margin+100+30,y++);printf("62-Metallurgie\n");
  y++;
  gotoxy(margin+100+30,y++);printf("63-Ingenierie des transports\n");
  y++;
  gotoxy(margin+100+30,y++);printf("64-Electromecanique\n");
  y++;
   gotoxy(margin+100+30,y++);printf("65-Hydraucarbures\n");
  y++;
   gotoxy(margin+100+30,y++);printf("66-Hygiene et securite industrielle\n");
  y++;
   gotoxy(margin+100+30,y++);printf("67-Genie maritime\n");
  y++;
   gotoxy(margin+100+30,y++);printf("68-Automatique\n");
  y++;
  gotoxy(margin+100+30,y++);printf("69-Forets\n");
  y++;
  gotoxy(margin+100+30,y++);printf("70-Histoire geographie\n");
  y++;
  gotoxy(margin+100+30,y++);printf("71-Musique\n");
  y++;
 gotoxy(margin+100+30,y++);printf("72-Philosophie\n");



      do{
        c2=getch();
        if(c2==up){cpt1%=72;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=72;}
        noire();

       y=tmp;

    gotoxy(margin,y++); textcolor(BLUE); printf(" ===================================================== Liste des specialites =========================================\n\n");noiret();
    y++;
    gotoxy(margin+5,y++); if(cpt1==1)bleu(); printf("01-Informatique\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==2)bleu(); printf("02-Architecture\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==3)bleu(); printf("03-Medecine\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==4)bleu();printf("04-Veterinaire\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==5)bleu();printf("05-Pharmacie\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==6)bleu(); printf("06-Mathematique\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==7)bleu(); printf("07-Physique\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==8)bleu();printf("08-Medecine dentaire\n"); noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==9)bleu();printf("09-Agriculture saharienne\n"); noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==10)bleu();  printf("10-Agronomie\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==11)bleu();printf("11-Sciences et technologies\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==12)bleu(); printf("12-Sciences de la matiere\n");noire();
    y++;
    gotoxy(margin+5,y++);if(cpt1==13)bleu();printf("13-Sciences de la nature et de la vie\n"); noire();
     y++;
    gotoxy(margin+5,y++);if(cpt1==14)bleu(); printf("14-Sciences economoiques\n"); noire();
     y++;
    gotoxy(margin+5,y++);if(cpt1==15)bleu(); printf("15-Sciences politiques\n"); noire();
     y++;
    gotoxy(margin+5,y++);if(cpt1==16)bleu();  printf("16-Droit\n");noire();
     y++;
    gotoxy(margin+5,y++);if(cpt1==17)bleu(); printf("17-Langue francaise\n"); noire();

     y++;
    gotoxy(margin+5,y++);if(cpt1==18)bleu();printf("18-Langue anglaise\n"); noire();
     y++;
    gotoxy(margin+5,y++);if(cpt1==19)bleu();printf("19-Sciences humaines\n"); noire();

     y++;
    gotoxy(margin+5,y++);if(cpt1==20)bleu();printf("20-Sciences sociales\n"); noire();

    y=tmp+2;


    gotoxy(margin+5+38,y++);if(cpt1==21)bleu(); printf("21-Sciences islamiques\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==22)bleu();printf("22-Langue et litterature arabes\n");noire();
     y++;
    gotoxy(margin+5+38,y++);if(cpt1==23)bleu(); printf("23-Sciences financieres et comptabilite\n"); noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==24)bleu();printf("24-Genie civil\n"); noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==25)bleu(); printf("25-Travaux publics\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==26)bleu();printf("26-Gestion des techniques urbaines\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==27)bleu(); printf("27-Geographie et amenagement du territoire\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==28)bleu();printf("28-Geologie\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==29)bleu(); printf("29-Science des activites physiques et sportives\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==30)bleu();printf("30-Telecommunications\n");noire();
     y++;
    gotoxy(margin+5+38,y++);if(cpt1==31)bleu(); printf("31-Sciences alimentaires\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==32)bleu(); printf("32-Sciences de gestion\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==33)bleu(); printf("33-Droit public\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==34)bleu(); printf("34-Sciences veterinaires\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==35)bleu();printf("35-Langue et culture amazighes\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==36)bleu(); printf("36-Traduction interpretariat\n"); noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==37)bleu();printf("37-Hydraulique\n");noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==38)bleu(); printf("38-Biotechnologie\n"); noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==39)bleu();printf("39-Urabanisme\n"); noire();
    y++;
    gotoxy(margin+5+38,y++);if(cpt1==40)bleu();printf("40-Aeronautique\n");noire();

    y=tmp+2;

   gotoxy(margin+91,y++);if(cpt1==41)bleu(); printf("41-Genie des procedes\n");noire();
    y++;
    gotoxy(margin+91,y++);if(cpt1==42)bleu();printf("42-Energies renouvelables\n"); noire();
    y++;
    gotoxy(margin+91,y++);if(cpt1==43)bleu(); printf("43-Electrotechnique\n");noire();
    y++;
    gotoxy(margin+91,y++);if(cpt1==44)bleu();printf("44-Genie macanique\n");noire();
    y++;
    gotoxy(margin+91,y++);if(cpt1==45)bleu();printf("45-Langue italienne\n");noire();
    y++;
    gotoxy(margin+91,y++);if(cpt1==46)bleu();printf("46-Management\n"); noire();
    y++;
     gotoxy(margin+91,y++);if(cpt1==47)bleu();printf("47-Sciences appliquees\n");noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==48)bleu();printf("48-Genie industriel\n"); noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==49)bleu(); printf("49-Geniebiomedical\n"); noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==50)bleu(); printf("50-Langue espagnole\n");noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==51)bleu();printf("51-Arts\n"); noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==52)bleu(); printf("52-Metiers de la ville\n");noire();
      y++;
       gotoxy(margin+91,y++);if(cpt1==53)bleu();printf("53-Langue allmande\n") ;noire();
      y++;
       gotoxy(margin+91,y++);if(cpt1==54)bleu();printf("54-Microbiologie fondamentale et appliquee\n");noire();
      y++;
       gotoxy(margin+91,y++);if(cpt1==55)bleu(); printf("55-Journalisme et sciences de l'information\n");noire();
      y++;
       gotoxy(margin+91,y++);if(cpt1==56)bleu(); printf("56-Geophysique\n");noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==57)bleu(); printf("57-Langue turque\n");noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==58)bleu(); printf("58-Langue russe\n");noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==59)bleu();printf("59-Optique et macanique de precision\n"); noire();
      y++;
      gotoxy(margin+91,y++);if(cpt1==60)bleu();printf("60-Industries petrochimiques\n");noire();


      y=tmp+2;


 gotoxy(margin+100+30,y++);if(cpt1==61)bleu();printf("61-Genie minier\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==62)bleu();printf("62-Metallurgie\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==63)bleu();printf("63-Ingenierie des transports\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==64)bleu();printf("64-Electromecanique\n");noire();
  y++;
   gotoxy(margin+100+30,y++);if(cpt1==65)bleu();printf("65-Hydraucarbures\n");noire();
  y++;
   gotoxy(margin+100+30,y++);if(cpt1==66)bleu();printf("66-Hygiene et securite industrielle\n");noire();
  y++;
   gotoxy(margin+100+30,y++);if(cpt1==67)bleu();printf("67-Genie maritime\n");noire();
  y++;
   gotoxy(margin+100+30,y++);if(cpt1==68)bleu();printf("68-Automatique\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==69)bleu();printf("69-Forets\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==70)bleu();printf("70-Histoire geographie\n");noire();
  y++;
  gotoxy(margin+100+30,y++);if(cpt1==71)bleu();printf("71-Musique\n");noire();
  y++;
 gotoxy(margin+100+30,y++);if(cpt1==72)bleu();printf("72-Philosophie\n");noire();


} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}




int reg(){

textbackground(WHITE);

int c2,cpt1=1,choix;
   int y, up=77,down=75,margin=10;

 y=wherey();

    gotoxy(margin+13,y);bleu();printf("|   Centre   |");noire();

    gotoxy(margin+13+20,y); printf("|    Est     |");

    gotoxy(margin+13+20+20,y); printf("|    Ouest   |");





      do{
        c2=getch();
        if(c2==up){cpt1%=3;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=3;}
        noire();


   gotoxy(margin+13,y); if(cpt1==1)bleu();printf("|   Centre   |");noire();

    gotoxy(margin+13+20,y);if(cpt1==2)bleu();  printf("|    Est     |");noire();

 gotoxy(margin+13+20+20,y);if(cpt1==3)bleu();  printf("|    Ouest   |");noire();


} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}



void affb(){
    textcolor(BLUE);
printf("            __  __ _      _                               _     _            \n");
printf("     /\\    / _|/ _(_)    | |                             | |   | |           \n");
printf("    /  \\  | |_| |_ _  ___| |__   ___ _ __   _   _ _ __   | |__ | | ___   ___ \n");
printf("   / /\\ \\ |  _|  _| |/ __| '_ \\ / _ \\ '__| | | | | '_ \\  | '_ \\| |/ _ \\ / __|\n");
printf("  / ____ \\| | | | | | (__| | | |  __/ |    | |_| | | | | | |_) | | (_) | (__\n");
printf(" /_/    \\_\\_| |_| |_|\___ |_| |_|\\___|_|     \\__,_|_| |_| |_.__/|_|\\___/ \\___|\n");

textcolor(BLACK);
}

int typetab()
{
int c2,cpt1=1,choix;
   int y,tmp, up=80,down=72,margin=10;

     textbackground(WHITE);
     y=wherey();
    tmp=y;
    gotoxy(margin+13,y++);bleu();printf("|           Universites         |");noire();
     y++;
    gotoxy(margin+13,y++);  printf("|    Centres universitaires     |");

     y++;
    gotoxy(margin+13,y++); printf("|  Ecoles normales superieures  |");
     y++;
    gotoxy(margin+13,y++); printf("| Ecoles nationales superieures |");





      do{
        c2=getch();
        if(c2==up){cpt1%=4;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=4;}
       y=tmp;


    gotoxy(margin+13,y++); if(cpt1==1)bleu();printf("|           Universites         |");noire();
     y++;
    gotoxy(margin+13,y++);if(cpt1==2)bleu(); printf("|    Centres universitaires     |");noire();

     y++;
    gotoxy(margin+13,y++); if(cpt1==3)bleu(); printf("|  Ecoles normales superieures  |");noire();
     y++;
    gotoxy(margin+13,y++);if(cpt1==4)bleu();  printf("| Ecoles nationales superieures |");noire();


} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }

    return choix;
}



int reseau()
{


textbackground(WHITE);

int c2,cpt1=1,choix;
   int y,tmp, up=80,down=72,margin=10;

     y=wherey();
    tmp=y;
    int dec;
printf("  -Veuillez choisir la region de l'etablissement universitaire (utiliser les touches <- et -> )\n\n");
 dec=reg();
 if(dec==1){
    //centre
    clrscr();
    printf("\n\n -Veuillez choisir le type de l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

    dec=typetab();

if(dec==1){//univ


clrscr();
printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Universite de Bouira - Akli Mohand Oulhadj"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Universite de Djelfa - Ziane Achour");
y++;
gotoxy(margin+13,y++);printf("3-Universite de Ghardaia");
y++;
gotoxy(margin+13,y++);printf("4-Universite de Khemis Miliana - Djilali Bounaama");
y++;
gotoxy(margin+13,y++);printf("5-Universite Medea - Yahia Fares");
y++;
gotoxy(margin+13,y++);printf("6-Universite des sciences et de la technologie d'Alger, Houari Boumediene");
y++;
gotoxy(margin+13,y++);printf("7-Universite de Bejaia - Abderrahmane Mira");
y++;
gotoxy(margin+13,y++);printf("8-Universite de Boumerdes - M'hamed Bougara");
y++;
gotoxy(margin+13,y++);printf("9-Universite de Tizi Ouzou - Mouloud Maameri");
y++;
gotoxy(margin+13,y++);printf("10-Universite de Laghouat - Amar Telidji");
y++;
gotoxy(margin+13,y++);printf("11-Universite Blida 1 - Saad Dahlab");
y++;
gotoxy(margin+13,y++);printf("12-Universite de Blida 2 - Lounici Ali");
y++;
gotoxy(margin+13,y++);printf("13-Universite d'Alger 1 - Benyoucef Benkhedda");
y++;
gotoxy(margin+13,y++);printf("14-Universite d'Alger 2 - Abou el Kacem Saadallah");
y++;
gotoxy(margin+13,y++);printf("15-Universite d'Alger 3 - Brahim Soltane Chaibout");
y++;
gotoxy(margin+13,y++);printf("16-Universite de la Formation Continue");
y++;
gotoxy(margin+13,y++);printf("17-Universite de Tamenghasset ");


  do{
        c2=getch();
        if(c2==up){cpt1%=17;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=17;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Universite de Bouira - Akli Mohand Oulhadj"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Universite de Djelfa - Ziane Achour"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Universite de Ghardaia");  noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Universite de Khemis Miliana - Djilali Bounaama");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Universite Medea - Yahia Fares");  noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6-Universite des sciences et de la technologie d'Alger, Houari Boumediene"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Universite de Bejaia - Abderrahmane Mira"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==8)bleu();printf("8-Universite de Boumerdes - M'hamed Bougara"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==9)bleu();printf("9-Universite de Tizi Ouzou - Mouloud Maameri");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==10)bleu();printf("10-Universite de Laghouat - Amar Telidji"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==11)bleu();printf("11-Universite Blida 1 - Saad Dahlab"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==12)bleu();printf("12-Universite de Blida 2 - Lounici Ali");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==13)bleu();printf("13-Universite d'Alger 1 - Benyoucef Benkhedda");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==14)bleu();printf("14-Universite d'Alger 2 - Abou el Kacem Saadallah");  noire();
y++;
gotoxy(margin+13,y++);if(cpt1==15)bleu();printf("15-Universite d'Alger 3 - Brahim Soltane Chaibout"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==16)bleu();printf("16-Universite de la Formation Continue"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==17)bleu();printf("17-Universite de Tamenghasset ");  noire();
}
while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
      return choix;
    }

 }
 if(dec==2){//centre univ

 clrscr();
 printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Centre universitaire de Tipaza - Abdallah Morsli"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar");
y++;
gotoxy(margin+13,y++);printf("3-Centre universitaire d'Aflou");

  do{
        c2=getch();
        if(c2==up){cpt1%=3;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=3;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu(); printf("1-Centre universitaire de Tipaza - Abdallah Morsli"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Centre universitaire d'Aflou");noire();

}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+42;
      return choix;
    }


 }
  if(dec==3){//ecole normale sup


  clrscr();
  printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi");
y++;
gotoxy(margin+13,y++);printf("3-Ecole normale superieure de Laghouat - Taleb Abderrahmane");
y++;
gotoxy(margin+13,y++);printf("4-Ecole normale superieure de sourds muets");


  do{
        c2=getch();
        if(c2==up){cpt1%=4;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=4;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Ecole normale superieure de Laghouat - Taleb Abderrahmane");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Ecole normale superieure de sourds muets");noire();

}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+38;
      return choix;

    }


 }
  if(dec==4){//ecole nat sup


   clrscr();
   printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;
gotoxy(margin+13,y++);bleu();printf("1-Ecole Nationale Polytechnique"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole nationale superieure d'hydraulique - Arbaoui Abdellah");
y++;
gotoxy(margin+13,y++);printf("3-Ecole nationale superieure des travaux publics - Francis Jeanson");
y++;
gotoxy(margin+13,y++);printf("4-Ecole nationale superieure veterinaire - Rabie Bouchama");
y++;
gotoxy(margin+13,y++);printf("5-Ecole Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed");
y++;
gotoxy(margin+13,y++);printf("6-Ecole nationale superieure agronomique- Khalef Abdellah alias Kasdi Merbah");
y++;
gotoxy(margin+13,y++);printf("7-Ecole des hautes etudes commerciales");
y++;
gotoxy(margin+13,y++);printf("8-Ecole nationale superieure d'informatique");
y++;
gotoxy(margin+13,y++);printf("9-Ecole nationale superieure en statistique et en economie appliquee");
y++;
gotoxy(margin+13,y++);printf("10-Ecole Superieure de Commerce-Mouloud Kacem Nait Belkacem");
y++;
gotoxy(margin+13,y++);printf("11-Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral");
y++;
gotoxy(margin+13,y++);printf("12-Ecole nationale superieure de management");
y++;
gotoxy(margin+13,y++);printf("13-Ecole Nationale Superieure de Technologie");
y++;
gotoxy(margin+13,y++);printf("14-Ecole nationale superieure de journalisme et des sciences de l'information");
y++;
gotoxy(margin+13,y++);printf("15-Ecole Nationale Superieure des sciences politiques");
y++;
gotoxy(margin+13,y++);printf("16-Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger");
y++;
gotoxy(margin+13,y++);printf("17-Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger");
y++;
gotoxy(margin+13,y++);printf("18-Ecole Superieure de Gestion et d'Economie Numerique");
y++;
gotoxy(margin+13,y++);printf("19-Ecole Superieure en Sciences et Technologies de l'Informatique et du Numerique de Bejaia");
y++;
gotoxy(margin+13,y++);printf("20-Ecole Nationale Superieure en Intelligence Artificielle");
y++;
gotoxy(margin+13,y++);printf("21-Ecole Nationale Superieure en Mathematique");

  do{
        c2=getch();
        if(c2==up){cpt1%=21;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=21;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole Nationale Polytechnique");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Ecole nationale superieure d'hydraulique - Arbaoui Abdellah");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Ecole nationale superieure des travaux publics - Francis Jeanson");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Ecole nationale superieure veterinaire - Rabie Bouchama");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Ecole Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6-Ecole nationale superieure agronomique- Khalef Abdellah alias Kasdi Merbah"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Ecole des hautes etudes commerciales");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==8)bleu();printf("8-Ecole nationale superieure d'informatique");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==9)bleu();printf("9-Ecole nationale superieure en statistique et en economie appliquee");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==10)bleu();printf("10-Ecole Superieure de Commerce-Mouloud Kacem Nait Belkacem");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==11)bleu();printf("11-Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==12)bleu();printf("12-Ecole nationale superieure de management");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==13)bleu();printf("13-Ecole Nationale Superieure de Technologie");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==14)bleu();printf("14-Ecole nationale superieure de journalisme et des sciences de l'information");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==15)bleu();printf("15-Ecole Nationale Superieure des sciences politiques");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==16)bleu();printf("16-Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger ex EP SNV Alger");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==17)bleu();printf("17-Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==18)bleu();printf("18-Ecole Superieure de Gestion et d'Economie Numerique");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==19)bleu();printf("19-Ecole Superieure en Sciences et Technologies de l'Informatique et du Numerique de Bejaia");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==20)bleu();printf("20-Ecole Nationale Superieure en Intelligence Artificielle");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==21)bleu();printf("21-Ecole Nationale Superieure en Mathematique");noire();



}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+17;
      return choix;

    }


 }

 }






 if(dec==2){
    //est
    clrscr();
    printf("\n\n -Veuillez choisir le type de l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

    dec=typetab();


    if(dec==1){//univ


clrscr();
   printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);bleu();printf("1-Universite de Jijel - Mohammed Seddik Ben yahia"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Universite de Tebessa - Larbi Tebessi");
y++;
gotoxy(margin+13,y++);printf("3-Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi");
y++;
gotoxy(margin+13,y++);printf("4-Universite d'El Tarf - Chadli Bendjedid");
y++;
gotoxy(margin+13,y++);printf("5-Universite de Khenchela - Abbas Laghrour");
y++;
gotoxy(margin+13,y++);printf("6-Universite de Oum El Bouaghi - Larbi Ben M'hidi");
y++;
gotoxy(margin+13,y++);printf("7-Universite d'El Oued - Hamma Lakhdar");
y++;
gotoxy(margin+13,y++);printf("8-Universite de Souk Ahras - Mohammed-Cherif Messaadia");
y++;
gotoxy(margin+13,y++);printf("9-Universite de Annaba - Badji Mokhtar");
y++;
gotoxy(margin+13,y++);printf("10-Universite du 20 Aout 1955 de Skikda");
y++;
gotoxy(margin+13,y++);printf("11-Universite 8 Mai 1945 de Guelma");
y++;
gotoxy(margin+13,y++);printf("12-Universite de Batna 1 - Hadj Lakhder");
y++;
gotoxy(margin+13,y++);printf("13-Universite de Biskra - Mohamed Khider");
y++;
gotoxy(margin+13,y++);printf("14-Universite de M'sila - Mohamed Boudiaf");
y++;
gotoxy(margin+13,y++);printf("15-Universite de Ouargla - Kasdi Merbah");
y++;
gotoxy(margin+13,y++);printf("16-Universite des sciences islamiques Emir Abdelkader de Constantine");
y++;
gotoxy(margin+13,y++);printf("17-Universite de Setif 1 - Ferhat Abbas");
y++;
gotoxy(margin+13,y++);printf("18-Universite de Setif 2 - Mohamed Lamine Debaghine");
y++;
gotoxy(margin+13,y++);printf("19-Universite de Constantine 1 - Freres Mentouri");
y++;
gotoxy(margin+13,y++);printf("20-Universite de Constantine 2 - Abdelhamid Mehri");
y++;
gotoxy(margin+13,y++);printf("21-Universite de Constantine 3 -Salah Boubnider");
y++;
gotoxy(margin+13,y++);printf("22-Universite de Batna 2 - Mustapha Ben Boulaid");

do{
        c2=getch();
        if(c2==up){cpt1%=22;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=22;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Universite de Jijel - Mohammed Seddik Ben yahia"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Universite de Tebessa - Larbi Tebessi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Universite d'El Tarf - Chadli Bendjedid");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Universite de Khenchela - Abbas Laghrour");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6-Universite de Oum El Bouaghi - Larbi Ben M'hidi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Universite d'El Oued - Hamma Lakhdar");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==8)bleu();printf("8-Universite de Souk Ahras - Mohammed-Cherif Messaadia");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==9)bleu();printf("9-Universite de Annaba - Badji Mokhtar");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==10)bleu();printf("10-Universite du 20 Aout 1955 de Skikda");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==11)bleu();printf("11-Universite 8 Mai 1945 de Guelma");noire();

y++;
gotoxy(margin+13,y++);if(cpt1==12)bleu();printf("12-Universite de Batna 1 - Hadj Lakhder");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==13)bleu();printf("13-Universite de Biskra - Mohamed Khider");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==14)bleu();printf("14-Universite de M'sila - Mohamed Boudiaf");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==15)bleu();printf("15-Universite de Ouargla - Kasdi Merbah");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==16)bleu();printf("16-Universite des sciences islamiques Emir Abdelkader de Constantine");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==17)bleu();printf("17-Universite de Setif 1 - Ferhat Abbas");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==18)bleu();printf("18-Universite de Setif 2 - Mohamed Lamine Debaghine");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==19)bleu();printf("19-Universite de Constantine 1 - Freres Mentouri");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==20)bleu();printf("20-Universite de Constantine 2 - Abdelhamid Mehri");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==21)bleu();printf("21-Universite de Constantine 3 -Salah Boubnider");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==22)bleu();printf("22-Universite de Batna 2 - Mustapha Ben Boulaid");noire();
}
while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+45;
      return choix;

    }


 }
 if(dec==2){//centre univ






 clrscr();
    printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Centre Universitaire de Mila - Abdelhafid Boussouf"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Centre Universitaire de Barika - Si El Haoues");


  do{
        c2=getch();
        if(c2==up){cpt1%=2;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=2;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu(); printf("1-Centre Universitaire de Mila - Abdelhafid Boussouf"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Centre Universitaire de Barika - Si El Haoues");noire();


}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+80;
      return choix;

    }


 }


  if(dec==3){//ecole normale sup


      clrscr();
         printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;



gotoxy(margin+13,y++);bleu();printf("1-Ecole normale superieure de Constantine -Assia Djebar"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole normale superieure d'enseignement technologique de Skikda");
y++;
gotoxy(margin+13,y++);printf("3-Ecole normale superieure de setif - Messaoud Zeghar");
y++;
gotoxy(margin+13,y++);printf("4-Ecole normale superieure de Bou Saada");
y++;
gotoxy(margin+13,y++);printf("5-Ecole normale superieure de Ouargla");


  do{
        c2=getch();
        if(c2==up){cpt1%=5;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=5;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole normale superieure de Constantine -Assia Djebar"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu(); printf("2-Ecole normale superieure d'enseignement technologique de Skikda");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu(); printf("3-Ecole normale superieure de setif - Messaoud Zeghar");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu(); printf("4-Ecole normale superieure de Bou Saada");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu(); printf("5-Ecole normale superieure de Ouargla");noire();

}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+75;
      return choix;

    }


 }
  if(dec==4){//ecole nat sup


   clrscr();
      printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);bleu();printf("1-Ecole nationale superieure des mines et de la metallurgie - Amar Laskri"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole Nationale Polytechnique de Constantine- Malek Bennabi");
y++;
gotoxy(margin+13,y++);printf("3-Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar");
y++;
gotoxy(margin+13,y++);printf("4-Ecole Superieure des Sciences de Gestion de Annaba ex - EPSECG Annaba");
y++;
gotoxy(margin+13,y++);printf("5-Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba");
y++;
gotoxy(margin+13,y++);printf("6-Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine");
y++;
gotoxy(margin+13,y++);printf("7-Ecole nationale superieure des forets - Khenchela");
y++;
gotoxy(margin+13,y++);printf("8-Ecole nationale superieure des energies renouvelables, environnement et developpement durable - Batna");



  do{
        c2=getch();
        if(c2==up){cpt1%=8;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=8;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole nationale superieure des mines et de la metallurgie - Amar Laskri"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Ecole Nationale Polytechnique de Constantine- Malek Bennabi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Ecole Superieure des Sciences de Gestion de Annaba ex - EPSECG Annaba");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Ecole Superieure des Technologies Industrielles de Annaba ex EP ST Annaba");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu(); printf("6-Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Ecole nationale superieure des forets - Khenchela");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==8)bleu();printf("8-Ecole nationale superieure des energies renouvelables, environnement et developpement durable - Batna");noire();



}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+67;
      return choix;

    }


 }
 }






 if(dec==3){
    //ouest
    clrscr();
        printf("\n\n -Veuillez choisir le type de l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

    dec=typetab();



    if(dec==1){//univ



clrscr();
   printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);bleu();printf("1-Universite de Bechar - Mohamed Tahri"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Universite de Mascara - Mustapha Stambouli");
y++;
gotoxy(margin+13,y++);printf("3-Universite de Saida - Tahar Moulay");
y++;
gotoxy(margin+13,y++);printf("4-Universite de Tlemcen - Abou Bekr Belkaid");
y++;
gotoxy(margin+13,y++);printf("5-Universite d'Adrar - Ahmed Draya");
y++;
gotoxy(margin+13,y++);printf("6-Universite de Tiaret - Ibn Khaldoun");
y++;
gotoxy(margin+13,y++);printf("7-Universite Sidi Bel Abbes - Djillali Liabes");
y++;
gotoxy(margin+13,y++);printf("8-Universite de Mostaganem - Abdelhamid Ibn Badis");
y++;
gotoxy(margin+13,y++);printf("9-Universited'Oran1 - Ahmed Ben Bella");
y++;
gotoxy(margin+13,y++);printf("10-Universite Mohamed Boudiaf des sciences et de la technologie - Mohamed Boudiaf d'Oran");
y++;
gotoxy(margin+13,y++);printf("11-Universite d'Oran 2 - Mohamed Ben Ahmed");
y++;
gotoxy(margin+13,y++);printf("12-Universite de Chlef - Hassiba Benbouali");
y++;
gotoxy(margin+13,y++);printf("13-Universite de Tissemsilt");
y++;
gotoxy(margin+13,y++);printf("14-Universite de Ain Temouchent");
y++;
gotoxy(margin+13,y++);printf("15-Universite de Relizane");


do{
        c2=getch();
        if(c2==up){cpt1%=15;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=15;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'universite ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Universite de Bechar - Mohamed Tahri"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Universite de Mascara - Mustapha Stambouli");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Universite de Saida - Tahar Moulay");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Universite de Tlemcen - Abou Bekr Belkaid");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Universite d'Adrar - Ahmed Draya");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6-Universite de Tiaret - Ibn Khaldoun");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Universite Sidi Bel Abbes - Djillali Liabes");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==8)bleu();printf("8-Universite de Mostaganem - Abdelhamid Ibn Badis");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==9)bleu();printf("9-Universited'Oran1 - Ahmed Ben Bella");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==10)bleu();printf("10-Universite Mohamed Boudiaf des sciences et de la technologie - Mohamed Boudiaf d'Oran");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==11)bleu();printf("11-Universite d'Oran 2 - Mohamed Ben Ahmed");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==12)bleu();printf("12-Universite de Chlef - Hassiba Benbouali");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==13)bleu();printf("13-Universite de Tissemsilt");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==14)bleu();printf("14-Universite de Ain Temouchent");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==15)bleu();printf("15-Universite de Relizane");noire();


}
while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+82;
      return choix;

    }


 }




 if(dec==2){//centre univ

   clrscr();
      printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Centre universitaire de Naama - Ahmed Salhi"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Centre universitaire d'El Bayadh - Nour Bachir");
y++;
gotoxy(margin+13,y++);printf("3-Centre universitaire de Tindouf-Ali Kafi");
y++;
gotoxy(margin+13,y++);printf("4-Centre universitaire de Maghnia");


  do{
        c2=getch();
        if(c2==up){cpt1%=4;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=4;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir le centre universitaire ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu(); printf("1-Centre universitaire de Naama - Ahmed Salhi");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Centre universitaire d'El Bayadh - Nour Bachir");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Centre universitaire de Tindouf-Ali Kafi");noire();

y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Centre universitaire de Maghnia");noire();



}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+108;
      return choix;

    }


 }
  if(dec==3){//ecole normale sup


    clrscr();
       printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;



gotoxy(margin+13,y++);bleu();printf("1-Ecole Normale Superieure de Mostaganem"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole Normale Superieure d'Oran");
y++;
gotoxy(margin+13,y++);printf("3-Ecole normale superieure de Bechar");



  do{
        c2=getch();
        if(c2==up){cpt1%=3;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=3;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole normale superieure ========================\n\n");noiret();
y++;


gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole Normale Superieure de Mostaganem"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Ecole Normale Superieure d'Oran");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu(); printf("3-Ecole normale superieure de Bechar");noire();

}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+105;
      return choix;

    }



 }
  if(dec==4){//ecole nat sup


   clrscr();
      printf("  -Veuillez choisir l'etablissement universitaire (utiliser les touches /\\et \\/ )\n\n");

y=wherey();
tmp=y;
gotoxy(margin,y++); vert(); printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);bleu();printf("1-Ecole Nationale Polytechnique d'Oran - Maurice Audin"); noire();
y++;
gotoxy(margin+13,y++);printf("2-Ecole Superieure d'Informatique (Sidi Bel Abbes)- 08 Mai 1945");
y++;
gotoxy(margin+13,y++);printf("3-Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen");
y++;
gotoxy(margin+13,y++);printf("4-Ecole Superieure d'Economie d'Oran  ex EPSECG Oran");
y++;
gotoxy(margin+13,y++);printf("5-Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran");
y++;
gotoxy(margin+13,y++);printf("6-Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem");
y++;
gotoxy(margin+13,y++);printf("7-Ecole Superieure des sciences Biologiques d' Oran ex EP SNV Oran");



  do{
        c2=getch();
        if(c2==up){cpt1%=7;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=7;}
        noire();

        y=tmp;

gotoxy(margin,y++); vert();  printf(" ========================== Choisir l'ecole nationale superieure ========================\n\n");noiret();
y++;

gotoxy(margin+13,y++);if(cpt1==1)bleu();printf("1-Ecole Nationale Polytechnique d'Oran - Maurice Audin"); noire();
y++;
gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2-Ecole Superieure d'Informatique (Sidi Bel Abbes)- 08 Mai 1945");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==3)bleu();printf("3-Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4-Ecole Superieure d'Economie d'Oran  ex EPSECG Oran");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5-Ecole Superieure en Genie Electrique et Energetique d'Oran ex EP ST Oran");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6-Ecole Superieure Agronomique de Mostaganem ex EP SNV Mostaganem");noire();
y++;
gotoxy(margin+13,y++);if(cpt1==7)bleu();printf("7-Ecole Superieure des sciences Biologiques d' Oran ex EP SNV Oran");noire();



}while(c2!=13);
    if(c2==13)
    {
      choix = cpt1+97;
      return choix;

    }



 }
 }

}

void esg(){


textcolor(BLUE);

printf(" ______                _                         _   \n");
printf("|  ____|              (_)                       | |   \n");
printf("| |__   _ __  ___  ___ _  __ _ _ __   __ _ _ __ | |_  \n");
printf("|  __| | '_ \\/ __|/ _ \\ |/ _` | '_ \\ / _` | '_ \\| __|\n");
printf("| |____| | | \\__ \\  __/ | (_| | | | | (_| | | | | |_ \n");
printf("|______|_| |_|___/\\___|_|\\__, |_| |_|\\__,_|_| |_|\\__| \n");
printf("                          __/ |\n");
printf("                         |___/ \n");

textcolor(BLACK);
      }





//*************************************** les fonctions de selections dynamiques

//selection des wilayas

int willaya()
{


textbackground(WHITE);


int c2,cpt1=1,choix;
   int y, up=80,down=72,margin=10,tmp;

   y=wherey();
   tmp=y;

    gotoxy(margin,y++); vert(); printf(" ========================== Liste des wilayas  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++);bleu(); printf("1- Adrar \n");noire();
    y++;
    gotoxy(margin+13,y++); printf("2- Chlef\n");
    y++;
    gotoxy(margin+13,y++); printf("3- Laghouat\n");
    y++;
    gotoxy(margin+13,y++);printf("4- Oum El Bouaghi\n");
    y++;
    gotoxy(margin+13,y++);printf("5- Batna\n");
    y++;
    gotoxy(margin+13,y++); printf("6- Bejaia\n");
    y++;
    gotoxy(margin+13,y++); printf("7- Biskra\n");
    y++;
    gotoxy(margin+13,y++); printf("8- Bechar\n");
    y++;
    gotoxy(margin+13,y++);  printf("9- Blida\n");
    y++;
    gotoxy(margin+13,y++);  printf("10- Bouira\n");
    y++;
    gotoxy(margin+13,y++);printf("11-Tamanrasset\n");
    y++;
    gotoxy(margin+13,y++);printf("12- Tebessa\n");
    y++;
    gotoxy(margin+13,y++);printf("13- Telemcen\n");


    y=tmp+2;
    gotoxy(margin+13+20,y++);  printf("14- Tiaret\n");
    y++;
   gotoxy(margin+13+20,y++); printf("15- Tizi-Ouzou\n");
    y++;
   gotoxy(margin+13+20,y++); printf("16- Alger\n");
    y++;
   gotoxy(margin+13+20,y++); printf("17- Djelfa\n");
    y++;
   gotoxy(margin+13+20,y++); printf("18- Jijel\n");
    y++;
   gotoxy(margin+13+20,y++);printf("19- Setif\n");
    y++;
   gotoxy(margin+13+20,y++);printf("20- Saida\n");
    y++;
   gotoxy(margin+13+20,y++); printf("21- Skikda\n");
    y++;
   gotoxy(margin+13+20,y++);printf("22- Sidi Bel Abbes\n");
    y++;
   gotoxy(margin+13+20,y++);  printf("23- Annaba\n");
    y++;
   gotoxy(margin+13+20,y++); printf("24- Guelma\n");
    y++;
   gotoxy(margin+13+20,y++);  printf("25- Constantine\n");
    y++;
   gotoxy(margin+13+20,y++); printf("26- Medea\n");
    y=tmp+2;
   gotoxy(margin+13+20+23,y++); printf("27- Monstaganem\n");
    y++;
   gotoxy(margin+13+20+23,y++);printf("28- M'Sila\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("29- Mascara\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("30- Ouargla\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("31- Oran\n");
    y++;
   gotoxy(margin+13+20+23,y++);printf("32- Bayadh\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("33- Illizi\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("34- Bordj Bou Arreridj\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("35- Boumerdes\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("36- Taref\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("37- Tindouf\n");
    y++;
   gotoxy(margin+13+20+23,y++); printf("38- Tissemsilt\n");
   y++;
   gotoxy(margin+13+20+23,y++); printf("39- El Oued\n");
   y=tmp+2;
   gotoxy(margin+13+20+23+23,y++);printf("40- Khenchela\n");
   y++;
  gotoxy(margin+13+20+23+23,y++); printf("41- Souk Ahras\n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("42- Tipaza\n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("43- Mila\n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("44- Ain Defla\n");
  y++;
  gotoxy(margin+13+20+23+23,y++); printf("45- Naama\n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("46- Ain Temouchent \n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("47- Ghardaya\n");
  y++;
   gotoxy(margin+13+20+23+23,y++);printf("48- Relizane\n");
  y++;
   gotoxy(margin+13+20+23+23,y++); printf("49- Timimoune\n");
  y++;
  gotoxy(margin+13+20+23+23,y++); printf("50- Bordj Badji Moukhtar\n");
  y++;
  gotoxy(margin+13+20+23+23,y++); printf("51- Ouled Djellal\n");
  y++;
  gotoxy(margin+13+20+23+23,y++);printf("52- Beni Abbes\n");
  y=tmp+2;
  gotoxy(margin+13+20+23+23+23,y++);printf("53- Ain Salah\n");
  y++;
  gotoxy(margin+13+20+23+23+23,y++);printf("54- In Guezzam\n");
  y++;
  gotoxy(margin+13+20+23+23+23,y++);printf("55- Touggourt\n");
  y++;
  gotoxy(margin+13+20+23+23+23,y++);printf("56- Djanet\n");
  y++;
  gotoxy(margin+13+20+23+23+23,y++);printf("57- M'Ghair\n");
  y++;
  gotoxy(margin+13+20+23+23+23,y++);printf("58- El Meniaa\n");


      do{
        c2=getch();
        if(c2==up){cpt1%=58;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=58;}
        noire();

        y=tmp;

    gotoxy(margin,y++); vert(); printf(" ========================== Listes de wilayas  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++); if(cpt1==1)bleu(); printf("1- Adrar \n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("2- Chlef\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==3)bleu(); printf("3- Laghouat\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==4)bleu();printf("4- Oum El Bouaghi\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==5)bleu();printf("5- Batna\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==6)bleu();printf("6- Bejaia\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==7)bleu(); printf("7- Biskra\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==8)bleu(); printf("8- Bechar\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==9)bleu(); printf("9- Blida\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==10)bleu(); printf("10- Bouira\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==11)bleu(); printf("11-Tamanrasset\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==12)bleu(); printf("12- Tebessa\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==13)bleu(); printf("13- Telemcen\n");noire();

    y=tmp+2;
    gotoxy(margin+13+20,y++);if(cpt1==14)bleu(); printf("14- Tiaret\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==15)bleu(); printf("15- Tizi-Ouzou\n");noire();
     y++;
    gotoxy(margin+13+20,y++);if(cpt1==16)bleu(); printf("16- Alger\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==17)bleu(); printf("17- Djelfa\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==18)bleu(); printf("18- Jijel\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==19)bleu(); printf("19- Setif\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==20)bleu(); printf("20- Saida\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==21)bleu(); printf("21- Skikda\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==22)bleu(); printf("22- Sidi Bel Abbes\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==23)bleu(); printf("23- Annaba\n");noire();
     y++;
    gotoxy(margin+13+20,y++);if(cpt1==24)bleu(); printf("24- Guelma\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==25)bleu(); printf("25- Constantine\n");noire();
    y++;
    gotoxy(margin+13+20,y++);if(cpt1==26)bleu(); printf("26- Medea\n");noire();
    y=tmp+2;
    gotoxy(margin+13+20+23,y++);if(cpt1==27)bleu(); printf("27- Monstaganem\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==28)bleu(); printf("28- M'Sila\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==29)bleu(); printf("29- Mascara\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==30)bleu(); printf("30- Ouargla\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==31)bleu(); printf("31- Oran\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==32)bleu(); printf("32- Bayadh\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==33)bleu(); printf("33- Illizi\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==34)bleu(); printf("34- Bordj Bou Arreridj\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==35)bleu(); printf("35- Boumerdes\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==36)bleu(); printf("36- Taref\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==37)bleu(); printf("37- Tindouf\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==38)bleu(); printf("38- Tissemsilt\n");noire();
    y++;
    gotoxy(margin+13+20+23,y++);if(cpt1==39)bleu(); printf("39- El Oued\n");noire();
    y=tmp+2;
     gotoxy(margin+13+20+23+23,y++);if(cpt1==40)bleu(); printf("40- Khenchela\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==41)bleu(); printf("41- Souk Ahras\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==42)bleu(); printf("42- Tipaza\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==43)bleu(); printf("43- Mila\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==44)bleu(); printf("44- Ain Defla\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==45)bleu(); printf("45- Naama\n");noire();
      y++;
       gotoxy(margin+13+20+23+23,y++);if(cpt1==46)bleu(); printf("46- Ain Temouchent \n");noire();
      y++;
       gotoxy(margin+13+20+23+23,y++);if(cpt1==47)bleu(); printf("47- Ghardaya\n");noire();
      y++;
       gotoxy(margin+13+20+23+23,y++);if(cpt1==48)bleu(); printf("48- Relizane\n");noire();
      y++;
       gotoxy(margin+13+20+23+23,y++);if(cpt1==49)bleu(); printf("49- Timimoune\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==50)bleu(); printf("50- Bordj Badji Moukhtar\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==51)bleu(); printf("51- Ouled Djellal\n");noire();
      y++;
      gotoxy(margin+13+20+23+23,y++);if(cpt1==52)bleu(); printf("52- Beni Abbes\n");noire();
      y=tmp+2;
      gotoxy(margin+13+20+23+23+23,y++);if(cpt1==53)bleu();printf("53- Ain Salah\n");noire();
      y++;
      gotoxy(margin+13+20+23+23+23,y++);if(cpt1==54)bleu();printf("54- In Guezzam\n");noire();
      y++;
       gotoxy(margin+13+20+23+23+23,y++);if(cpt1==55)bleu();printf("55- Touggourt\n");noire();
      y++;
      gotoxy(margin+13+20+23+23+23,y++);if(cpt1==56)bleu();printf("56- Djanet\n");noire();
      y++;
      gotoxy(margin+13+20+23+23+23,y++);if(cpt1==57)bleu();printf("57- M'Ghair\n");noire();
      y++;
      gotoxy(margin+13+20+23+23+23,y++);if(cpt1==58)bleu();printf("58- El Meniaa\n");noire();



} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}


//selection du groupe sanguin
int abo(){

textbackground(WHITE);


int c2,cpt1=1,choix;
   int y=2, up=77,down=75,margin=10;

/*char *group[]={"O+","A+","B+","O-","A-","AB+","B-","AB-"};
*/

    gotoxy(margin,y++); vert();printf("             ========================== Choisir le groupe sanguin  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y);bleu(); printf("|  O+  |");noire();

    gotoxy(margin+13+5+5,y); printf("|  A+  |");

    gotoxy(margin+13+5+5+5+5,y); printf("|  B+  |");

   gotoxy(margin+13+5+5+5+5+10,y); printf("|  O-  |");

    gotoxy(margin+13+5+5+5+5+5+15,y); printf("|  A-  |");

    gotoxy(margin+13+5+5+5+5+5+5+20,y); printf("|  AB+ |");

    gotoxy(margin+13+5+5+5+5+5+5+30,y); printf("|  B-  |");

    gotoxy(margin+13+5+5+5+5+5+5+5+35,y);printf("|  AB- |");




      do{
        c2=getch();
        if(c2==up){cpt1%=8;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=8;}
        noire();

        y=2;

    gotoxy(margin,y++); vert(); printf("             ========================== Choisir le groupe sanguin  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y); if(cpt1==1)bleu();  printf("|  O+  |");noire();

    gotoxy(margin+23,y);if(cpt1==2)bleu(); printf("|  A+  |"); noire();

    gotoxy(margin+33,y);if(cpt1==3)bleu(); printf("|  B+  |"); noire();

    gotoxy(margin+43,y);if(cpt1==4)bleu(); printf("|  O-  |");noire();

    gotoxy(margin+53,y);if(cpt1==5)bleu();printf("|  A-  |");noire();

    gotoxy(margin+63,y);if(cpt1==6)bleu();printf("|  AB+ |");noire();

    gotoxy(margin+73,y);if(cpt1==7)bleu(); printf("|  B-  |");noire();

    gotoxy(margin+83,y);if(cpt1==8)bleu();printf("|  AB- |");noire();


} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}


//le grade
int grad()
{



int c2,cpt1=1,choix;
   int y=2, up=80,down=72,margin=10;



    gotoxy(margin,y++); vert();  printf("              ========================== Choisir le grade  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++);bleu(); printf("Professeur(e)\n");noire();
    y++;
    gotoxy(margin+13,y++); printf("Assistant(e)\n");
    y=4;
    gotoxy(margin+13+15,y++); printf("Maitre de conferences Rang A\n");
    y++;
    gotoxy(margin+13+15,y++);printf("Maitre de conferences Rang B\n");
    y=4;
    gotoxy(margin+13+30+15,y++);printf("Maitre assistant(e) Rang A\n");
    y++;
    gotoxy(margin+13+30+15,y++); printf("Maitre assistant(e) Rang B\n");

      do{
        c2=getch();
        if(c2==up){cpt1%=6;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=6;}
        noire();

        y=2;

    gotoxy(margin,y++); vert();  printf("              ========================== Choisir le grade  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++); if(cpt1==1)bleu(); printf("Professeur(e)\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==2)bleu();printf("Assistant(e)\n");noire();
    y=4;
    gotoxy(margin+13+15,y++);if(cpt1==3)bleu();printf("Maitre de conferences Rang A\n");noire();
    y++;
    gotoxy(margin+13+15,y++);if(cpt1==4)bleu() ; printf("Maitre de conferences Rang B\n");noire();
    y=4;
    gotoxy(margin+13+30+15,y++);if(cpt1==5)bleu();printf("Maitre assistant(e) Rang A\n");noire();
    y++;
    gotoxy(margin+13+30+15,y++);if(cpt1==6)bleu();printf("Maitre assistant(e) Rang B\n");noire();


} while(c2!=13);
    if(c2==13)
    {
    switch (cpt1){
       case 1:
      choix = 1;
      break;
      case 2:
      choix = 6;
      break;
      case 3:
      choix = 2;
      break;
      case 4:
      choix = 3;
      break;
      case 5:
      choix =4;
      break;
      case 6:
      choix =5;
      break;

      }
    }
    return choix;

}

//le dernier diplome
int dernier_dip()
{

int c2,cpt1=1,choix;
   int y=2, up=80,down=72,margin=10;



textbackground(WHITE);
    gotoxy(margin,y++); textcolor(BLUE); printf("                      ========================== Choisir le dernier diplome  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++);bleu(); printf("|      Doctorat d'Etat       |\n");noire();
    y++;
    gotoxy(margin+13,y++);        printf("|    Doctorat en sciences    |\n");
    y=4;
    gotoxy(margin+13+30+2,y++);     printf("|       Doctorat D-LMD       |\n");
    y++;
    gotoxy(margin+13+30+2,y++);     printf("|            PhD             |\n");
    y=4;
    gotoxy(margin+13+30+30+4,y++);  printf("| Habilitation Universitaire |\n");
    y++;
    gotoxy(margin+13+30+30+4,y++);  printf("|          Magistere         |\n");

      do{
        c2=getch();
        if(c2==up){cpt1%=6;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=6;}
        noire();

        y=2;

    gotoxy(margin,y++); textcolor(BLUE); printf("                      ========================== Choisir le dernier diplome  ========================\n\n");noiret();
    y++;
    gotoxy(margin+13,y++); if(cpt1==1)bleu();printf("|      Doctorat d'Etat       |\n");noire();
    y++;
    gotoxy(margin+13,y++);if(cpt1==2)bleu(); printf("|    Doctorat en sciences    |\n");noire();
    y=4;
    gotoxy(margin+13+30+2,y++);if(cpt1==3)bleu(); printf("|       Doctorat D-LMD       |\n");noire();
    y++;
    gotoxy(margin+13+30+2,y++);if(cpt1==4)bleu() ;  printf("|            PhD             |\n");noire();
    y=4;
    gotoxy(margin+13+30+30+4,y++);if(cpt1==5)bleu();printf("| Habilitation Universitaire |\n");noire();
    y++;
    gotoxy(margin+13+30+30+4,y++);if(cpt1==6)bleu();printf("|          Magistere         |\n");noire();


} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}

int sex()
{


int c2,cpt1=1,choix;
   int y=2, up=77,down=75,margin=10;

textbackground(WHITE);

    gotoxy(margin,y++); vert(); printf("            ========================== choisir le sexe ======================\n\n");noiret();
    y++;
    //noiret();
    gotoxy(margin+13,y);bleu(); printf("| Masculin |");noire();
    gotoxy(margin+13+50,y); printf("| Feminin |");



      do{
        c2=getch();
        if(c2==up){cpt1%=2;cpt1++;}
        if(c2==down){cpt1--;if(cpt1==0)cpt1=2;}
        noire();

        y=2;

    gotoxy(margin,y++); vert(); printf("            ========================== choisir le sexe ======================\n\n");noiret();
    y++;
    //noiret();
    gotoxy(margin+13,y); if(cpt1==1)bleu();printf("| Masculin |"); noire();

    gotoxy(margin+13+50,y);if(cpt1==2)bleu(); printf("| Feminin |");noire();



} while(c2!=13);
    if(c2==13)
    {
      choix = cpt1;
    }
    return choix;

}


