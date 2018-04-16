#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include "Global.h" //global variables
#include "structs.h"// structures
#include "animation.h"//animation
#include "indepFunctions.h"// functions cold be used in any othr code
#include "myFiles.h"// functions which save and load
#include "mainLine.h" //the start menu list and settings
#include "GameLogic.h"// the logic of the game (open cell , empty cell ,etc)
#include "loopCore.h"// taking input fro the user during the game and update the data
#include "scores.h" // save and load the score
#include "sounds.h"// play sound



int main()
{

findFiles(); // checks if the files of the system are exists or not if not it makes new files
//welcomesound(); // plays start sound
//printhello(); // welcome animation


system("COLOR 3f");//------------DC   the background color
    int replayflag=0,menu=0,txtc=4,n,sleept=60;

label1:


    flgn=0;
    numofmoves=0;
    numofqm=0;
    startup(replayflag,&txtc,&sleept);


    char name[150];
    int timeloaded;
    int firsttime;

    if(loadd==1)
    {

        int flag;
        flag=2;
        flag=loadHeightWidth(name);// gets the height and width if we will load an array
        if(flag!=1)
        {
            loadd=2;
            clrscr();
            goto label1;
        }
    }

    point screen[height][width];

    if(loadd==1)
    {

        loadIt(screen,name,&timeloaded);//load the array
        clrscr();
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                screen[i][j].pointed=0;
            }
        }
        if(arrowmode==1)
        {
            screen[0][0].pointed=1;
        }
    }

    else
    {
        setvalue(screen);                        // set default  shapes for the game
        setminepos(screen,0,0,0);              // set the positions of mines randomly
        setnums(screen);                   // set numbers around the mines
    }
    time_t current;
    time_t old;
    int oldi;
    if(loadd==1)
    {
        oldi=time(&old)-timeloaded;   // loading time
        firsttime=0;
        loadd=0;
    }
    else
    {
        oldi=time(&old);
        firsttime=1;
    }
            if(width>20){printIt(screen);}

    while(gameover==0)
    {
        n=time(&current)-oldi;
        printf("minutes : %d   - seconds : %d\n",n/60,n%60);
        printscreenvale(screen);                          // prints the screen value or unopened cells
        updateinf(screen,&menu,&firsttime,n,oldi,sleept); // gets info from the user and updates the screen



        if(menu==12)
        {
            menu=0;
            flgn=0;
            clrscr();
            goto label1;

        }
        clrscr();

    }
    if (gameover==1)            // lose case
    {enteredd=0;
        losesound();
        char text []="FIRE IN THE HOOOOOLE";
        char textA [20];

        for(int i=0; i<20; i++)
        {
            textA[i]=text[i];
            printf("\n\n\n\n\n\n\n\n\n");
            fullscreenmode ? fullscrm(1):windowmode(1);

            for(int j=0; j<=i; j++)
            {
                printf("%c",textA[j]);
            }
            printf("->");
            for(int j=0; j<=20-i; j++)
            {
                printf("%c",' ');
            }
            printf("(((((%c)))))",mn);
            Sleep(100);
            clrscr();

        }

        enteredd=2;
        printf("\a\n\n");
        losecolor(txtc,1,100,150);
        clrscr();
        printf("\n");
        losecolor(txtc,2,100,150);
        clrscr();
        printf("");
        losecolor(txtc,3,100,150);
        clrscr();


        setallhidtoval(screen);         // prepare to show the puzzle as he has already lost
        int temp33=DM;
        DM=0;
        int temp22=arrowmode;
        arrowmode=1;
        printscreenvale(screen)  ;       // showing the hidden
        arrowmode=temp22;
        DM=temp33;

        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("____YOU LOST____");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("      -_-");
        enteredd=1;
    }
    else if (gameover==2)// winning case
    {
        n=time(&current)-oldi;

       //    woncolor(txtc,1,300);

        long long tempa,tempb;
        tempa=1;
        tempb=1;

         long double score =0;

        score=((double)pow(width,4)*pow(height,4)/((double)numofmoves*n));

        setallhidtoval(screen);         // prepare to show the puzzle as he lost already

        int temp33=DM;
        DM=0;
        printscreenvale(screen);         // showing the hidden
        DM=temp33;
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("   ***you won***" );
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("        ^_^");
        fullscreenmode ? fullscrm(0):windowmode(0);
        if(DM==0)
        {
            printf("your score is : %.2llf\n",score );
        }
        else
        {
            printf(">>your score using \"Developer mode\" is : %.2llf \n",score );

        }

                fullscreenmode ? fullscrm(0):windowmode(0);

        fflush(stdin);
        SaveScore(score);
        clrscr();
        ranko();
        printf("\nHere is your place in scores' table .\n");
fflush(stdin);


    }





    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("# click 1 to play again");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("# click 2 to go to main menu");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("# click 0 to exit");
    int temp3;
    temp3=-1;
    while(temp3<0||temp3>2){

    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("->");
    fflush(stdin);
    scanf("%d",&temp3);
    if(temp3<0||temp3>2){fullscreenmode ? fullscrm(0):windowmode(0);printf("<>Error\n");}
    }
    clrscr();
    switch(temp3)
    {
    case 1:
        replayflag=1;
        gameover=0;
        goto label1;
        break;
    case 2:
        replayflag=2;
        gameover=0;
        goto label1;
        break;
    case 0:
    default:
        break;

    }

    return  0;
}
