
   void printstartmenu(){
       printf("\n\n");
     fullscreenmode ? printf("                                "):printf(" ");
    printf("                                                 *         *   *  *      *   ******  \n");     fullscreenmode ? printf("                                "):printf(" ");
    printf("                                                 **       **      **     *   *        \n");fullscreenmode ? printf("                                "):printf(" ");
    printf("                                                 *  *   *  *   *  *  *   *   ******    \n");fullscreenmode ? printf("                                "):printf(" ");
    printf("                                                 *    *    *   *  *    * *   *        \n");fullscreenmode ? printf("                                "):printf(" ");
    printf("                                                 *         *   *  *      *   ******   \n\n");fullscreenmode ? printf("                                 "):printf(" ");


    printf("                             ******  *              *    ******   ******   ******   ******   ****** \n");fullscreenmode ? printf("                                 "):printf(" ");
    printf("                             *        *     *      *     *        *        *    *   *        *    * \n");fullscreenmode ? printf("                                 "):printf(" ");
    printf("                             ******    *   *  *   *      ******   ******   ******   ******   ******  \n");fullscreenmode ? printf("                                 "):printf(" ");
    printf("                                  *     * *    * *       *        *        *        *        *    *  \n");fullscreenmode ? printf("                                 "):printf(" ");
    printf("                             ******      *      *        ******   ******   *        ******   *     * ");

    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("~ New game  ->enter 1");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("~ load game  ->enter 2 ");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("~ Show scores' table ->enter 3");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("~ Settings  ->enter 4");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("~ About the game ->enter 5 ");
    fullscreenmode ? fullscrm(0):windowmode(0);
    printf("* Top score is : ");topScore();


    }

void woncolor(int txtc,int speedt,int DT)  //speedt=10 ,DT=100
{
    int F;
    if(fullscreenmode==1)
    {
        F=80;
    }
    else
    {
        F=40;
    }

    for(int i=0; i<50; i++)
    {
        if(fullscreenmode==0)
        {
            printf("\n\n\n\n\n\n\n");
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }


        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" ****** \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf("      * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" ****** \n");
       Sleep(speedt);
        clrscr();


    }
winsound();

    for(int i=0; i<50; i++)
    {
        if(fullscreenmode==0)
        {
            printf("\n\n\n\n\n\n\n");
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" *    *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" ****** \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" *    *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" ******   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf("      *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" ******   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" ****** \n");

        Sleep(speedt);
        clrscr();
    }

winsound();


    for(int i=0; i<50; i++)
    {
        if(fullscreenmode==0)
        {
            printf("\n\n\n\n\n\n\n");
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" *    *   ******   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" *    *   *    *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" ******   *    *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf("      *   *    *   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" *    * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        printf(" ******   ******   ");
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf(" ****** \n");

        Sleep(speedt);
        clrscr();
    }



winsound();


    if(fullscreenmode==0)
    {
        printf("\n\n\n\n\n\n\n");
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    for(int i=0; i<F; i++)
    {
        printf(" ");
    }
    printf(" *    *   ******    *    * \n");
    for(int i=0; i<F; i++)
    {
        printf(" ");
    }
    printf(" *    *   *    *    *    * \n");
    for(int i=0; i<F; i++)
    {
        printf(" ");
    }
    printf(" ******   *    *    *    * \n");
    for(int i=0; i<F; i++)
    {
        printf(" ");
    }
    printf("      *   *    *    *    * \n");
    for(int i=0; i<F; i++)
    {
        printf(" ");
    }
    printf(" ******   ******    ****** \n\n");

    for(int i=0; i<F-5; i++)
    {
        printf(" ");
    }
    system("COLOR F9");
    printf("  *              *   ******  *      *  \n");
    for(int i=0; i<F-5; i++)
    {
        printf(" ");
    }
    Beep(300,DT);
    system("COLOR 05");
    printf("   *     *      *    *    *  * *    *  \n");
    for(int i=0; i<F-5; i++)
    {
        printf(" ");
    }
    Beep(300,DT);
    system("COLOR F4");
    printf("    *   *  *   *     *    *  *   *  *  \n");
    for(int i=0; i<F-5; i++)
    {
        printf(" ");
    }
    Beep(300,DT);
    system("COLOR 03");
    printf("     * *    * *      *    *  *    * *  \n");
    for(int i=0; i<F-5; i++)
    {
        printf(" ");
    }
    Beep(300,DT);
    system("COLOR F7");
    printf("      *      *       ******  *      *  \n");
    Beep(300,DT);
    system("COLOR 0A");




    Sleep(2000);

        clrscr();

    switch(txtc)
    {
  case 1:

                system("COLOR 0A");//-------DC
                break;
            case 2:

                system("COLOR 1B");//-----------DC
                break;
            case 3:

                system("COLOR 3E");//------------DC
                break;
            case 0:

                system("COLOR 5F");//------------DC
                break;
            case 4 :

                system("COLOR 1F");//------------DC
                break;
            default:break;
    }
}



void losecolor(int txtc,float R,int S1,int S2)
{

    for(int y =0; y<=25*R; y++)
    {
        for(int x=0; x<50*R; x++)
        {
            if(x==5*R&&y<25*R&&y>10*R)
            {
                printf("#");
            }
            else if(x==10*R&&y<25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==15*R&&y<25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==20*R&&y<25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==25*R&&y<25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==30*R&&y<25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==35*R&&y<=25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==40*R&&y<=25*R&&y>20*R)
            {
                printf("#");
            }
            else if(x==45*R&&y<=25*R&&y>20*R)
            {
                printf("#");
            }
            else if(y==20*R&&x>5*R&&x<=10*R)
            {
                printf("#");
            }
            else if(y==20*R&&x>=15*R&&x<=20*R)
            {
                printf("#");
            }
            else if(y==20*R&&x>=25*R&&x<=30*R)
            {
                printf("#");
            }
            else if(y==20*R&&x>=35*R&&x<=45*R)
            {
                printf("#");
            }
            else if(y==25*R&&x>5*R&&x<=10*R)
            {
                printf("#");
            }
            else if(y==25*R&&x>=15*R&&x<=20*R)
            {
                printf("#");
            }
            else if(y==25*R&&x>=25*R&&x<=30*R)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n\t\t");
    }
    system("COLOR 60");
    Sleep(S1);
    system("COLOR 40");
    Sleep(S2);
    system("COLOR 07");
    switch(txtc)
    {
  case 1:

                system("COLOR 0A");//-------DC
                break;
            case 2:

                system("COLOR 1B");//-----------DC
                break;
            case 3:

                system("COLOR 3E");//------------DC
                break;
            case 0:

                system("COLOR 5F");//------------DC
                break;
            case 4 :
                system("COLOR 1F");//------------DC
                break;
            default:break;
    }

}



int flagi=1,flingo=0;
void printhello();
void dot()
{
    while(flingo==0)
    {
        for(int i=0; i<3; i++)
        {
            if(flingo==1)
            {
                break;
            }
            printf(" .");
            Sleep(1000);
        }


        if(flingo==0)
        {
            flagi=0;
            clrscr();
            printhello();
        }
    }

}

void printhello()
{

    if(flagi==1){
                    system("COLOR 0F");

        int F=21;


    for(int i=0; i<50; i++)
    {

            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
 for(int p=0; p<F; p++)
        {
            printf(" ");
        }

        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }

        printf(" *              * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf("  *     *      * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf("   *   *  *   * \n");
        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf("    * *    * * \n");


        for(int p=0; p<F; p++)
        {
            printf(" ");
        }
        for(int j=50; j>=i; j--)
        {
            printf(" ");
        }
        printf("     *      * \n");

        Sleep(3);
          if(i!=49){
         clrscr();
          }

    }
    Sleep(500);
    clrscr();
    }
    //-------------------------------------
    printf("\n\n\n\n\n\n\n\n\n\n\n\n                        ");
    printf("*              *    ******   *        ******   ******   *         *   ****** \n");
    printf("                        ");
    printf(" *     *      *     *        *        *        *    *   **       **   *      \n");
    printf("                        ");
    printf("  *   *  *   *      ******   *        *        *    *   *  *   *  *   ****** \n");
    printf("                        ");
    printf("   * *    * *       *        *        *        *    *   *    *    *   *      \n");
    printf("                        ");
    printf("    *      *        ******   ******   ******   ******   *         *   ****** \n");

    if(flagi==1)
    {
        system("COLOR 0F");
        Sleep(1000);
        system("COLOR 1F");
        Sleep(400);
        system("COLOR 2F");
        Sleep(400);
        system("COLOR 4F");
        Sleep(400);
        system("COLOR 5F");
        Sleep(400);
        system("COLOR 6F");
        Sleep(400);
        system("COLOR 07");
        Sleep(300);
        system("COLOR 0F");
        Sleep(300);
        system("COLOR 07");
        Sleep(300);
        system("COLOR 0F");
        Sleep(300);
        system("COLOR 07");
        Sleep(300);
        system("COLOR 0F");
        Sleep(300);
        system("COLOR 07");
        Sleep(300);
        system("COLOR 0F");
        Sleep(300);
        system("COLOR 07");
        Sleep(300);
        system("COLOR 0F");
        Sleep(1000);


    }
    printf("                               ");

    printf("TO MINESWEEPER Game \n\n");
    printf("                                          ");
    printf("Made by Abdelrahman Ahmed and Ahmed Khaled\n");
    system("COLOR 0A");
    printf("\n\n                                           ");
    printf("     press any key to continue");
    if(flagi==1)
    {
        void (*ptr)();
        ptr=&dot;
        pthread_t thread1;
        pthread_create(&thread1,NULL,dot,NULL);
        getch();
        enteredd=1;
        flingo=1;
        clrscr();
    }




}

