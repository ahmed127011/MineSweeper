

void custom()
{
    height=-1;width=-1;
    while(height>45||height<=0)
    {
    printf("-Enter the height:\n->");
fflush(stdin);
    scanf("%d",&height);

if(height>45||height<=0)
    {

        printf("<>error,max height is 45.\n");
        }
    }

    while(width>45||width<=0){
    printf("-Enter the width:\n->");
    fflush(stdin);

    scanf("%d",&width);
    if(width>45||width<=0)
    {

        printf("<>error ,max width is 45.\n");
    }
    }
    if(width>20&&DM==1){printf("<>Developer mode will turn off automatically because the width is more than 20.\n");DM=0;}
    printf("-Enter number of mines (enter -1 for default formula):");
    scanf("%d",&numofmines);
    if(numofmines>(height*width)||numofmines<=0)
    {
               if(numofmines!=-1) {printf("<>DEFAULT number of mines is %d which is 1+height * width/10 and cant be less than or equal 0",1+(height*width)/10);getch();}
        numofmines=1+(height*width)/10;

        fflush(stdin);
    }

    clrscr();
}


void startup (int rplyflg,int *txtc,int*sleept)
{
    if(rplyflg==1)
    {
        goto labelreply;
    }
mylabel://------->>





    printstartmenu();




    char line[50];
    fflush(stdin);
    do
    {
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("->");
        gets(line);
        if(!isdigit(line[0])||line[1]!='\0'||line[0]-48<1||line[0]-48>5)
        {
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("<>Error ,YOU may entered non digit input\n");
        }
    }
    while(!isdigit(line[0])||line[1]!='\0'||line[0]-48<1||line[0]-48>5);

    int temp=line[0]-48;

    clrscr();//---------
if(temp==5){
    clrscr();
    printf("Minesweeper has its origins in the earliest mainframe games of the 1960s and 1970s.\nThe earliest ancestor of Minesweeper was Jerimac Ratliff's Cube.\nThe basic gameplay style became a popular segment of the puzzle game genre during the 1980s\n\n\n");printf("----------------------------------------------------------------------------------------------------------");
printf("\nIn this game we added some features , sound effects and animations .\n\n\n\n");
       printf("1)We tried to make playing easier so we added arrow mode .\nIt enables the user to to move an arrow through the gird and choose the order he want with one click .\n\n\n");
       printf("2)We also made it available to change the the sleep time of the game.\n\n\n");
       printf("3)Fullscreen mode will center the the game labels to fit a full screen to make the game better to see and control.\n\n\n");
       printf("4)To discover the game more and more ,Developer mode would help as it shows the solution beside the you while playing.\n");
       printf("BUT be careful your score will be saved with the suffix DM .\nand if you saved and load it , it will also be in Developer mode so don\'t try to cheat.\n\n\n");
       printf("5)playing with the same color is quite boring so you are free to choose the style you want from settings.\n\n\n");
       printf("6)concerning the the style you can change also the cell char or flag or question mark or even the mine to whatever char you want.\n\n\n");
       printf("7)according to the games you saved or the scores , you can reset all of these from settings.\n\n\n\n\n");printf("----------------------------------------------------------------------------------------------------------\n");
       printf("controlling the game:\n\n\n");
       printf("The regular mode :\nEnter the number of the row followed by space then space then the number of the order\nit will be declared more during the game.\n\n\n");
       printf("The arrow mode :\njust use   w (up), s(down), d(right), a(left) and (o) to open ,(f) to flag ... (others will be shown during play) \n\n\n\n\n");printf("----------------------------------------------------------------------------------------------------------\n");
       printf("\nMade by :\nAbdelrahman Ahmed Mohamed ( 37 )\nAhmed khaled Abdelsayed ( 5 )\n\n\n\n");
       printf("press any key to go back ...");
       Sleep(2000);
       fflush(stdin);
       getch();
       fflush(stdin);

       clrscr();
       goto mylabel;

}
    else if(temp==1)
    {

labelreply://-------->
    temp=-1;
        fullscreenmode ? fullscrm(1):windowmode(1);
        printf("~ Easy -> 1");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("~ Mid -> 2");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("~ Hard -> 3");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("~ custom -> 4");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("~ back -> 0");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("->");

        fflush(stdin);
        scanf("%d",&temp);
        clrscr();//---------
        switch (temp)
        {
        case 0:
            goto mylabel;
            break;
        case 1:
            width=10;
            height=10;
            break;
        case 2:
            width=15;
            height=15;
            break;
        case 3:
            width=20;
            height=20;

            break;
        case 4 :
            custom();
            break;
        default:
            printf("<>error");
            Sleep(1000);
            clrscr();
            goto labelreply;
            break;
        }
        if(temp!=4){
        numofmines=1+(width*height)/10;
        }


    }
    else if(temp==2)
    {
        loadd=1;

    }else if(temp==3){
        clrscr();
    ranko();
    printf("\npress any key to go back ...\n");
    getch();
    clrscr();
    goto mylabel;
    }
    else if (temp==4)
    {
mylabel2:
        fullscreenmode ? fullscrm(1):windowmode(1);
        printf("# Change Game colors ->1");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# Full screen mode On/off ->2");
        fullscreenmode?printf("\t>>Active"):printf(" ");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# Developer MODE(shows the hidden values) On/off ->3");
        DM?printf("\t>>Active"):printf(" ");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# Change game shapes ->4");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# Switch to/from arrow mode(preferred in small sizes) ->5");
        arrowmode?printf("\t>>Active"):printf(" ");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# set sleep time ->6");
        printf("\t (%d)",*sleept);
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# clear saving or scores history ->7");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("# Back ->0");
        fullscreenmode ? fullscrm(0):windowmode(0);
        printf("->");
        int temp2;
        temp2=0;
        char line [50];
        while(1)
        {
            fflush(stdin);
            gets(line);

            if(isdigit(line[0])&&line[0]-48<=7&&line[0]-48>-1&&line[1]=='\0')
            {
                break;
            }
            else
            {
                fullscreenmode ? fullscrm(0):windowmode(0);
                printf("<>Error, the input you entered is not defined");
                fullscreenmode ? fullscrm(0):windowmode(0);
                printf("->");
            }
        }

        temp2=line[0]-48;
        clrscr();

        if (temp2==1)
        {
            labelnew:
            temp2=2;
            fullscreenmode ? fullscrm(1):windowmode(1);
            printf("# green text with black background->1");
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# aqua text with blue background->2");
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# yellow text with aqua background ->3");
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# white text with purple background ->4");
fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# white text with blue background ->5\n");
            fullscreenmode ? fullscrm(0):windowmode(0);

            printf("->");
            fflush(stdin);
            scanf("%d",&temp2);
            clrscr();//---------
            switch(temp2)
            {
            case 1:
                *txtc=1;
                system("COLOR 0A");//-------DC
                break;
            case 2:
                *txtc=2;
                system("COLOR 1B");//-----------DC
                break;
            case 3:
                *txtc=3;
                system("COLOR 3E");//------------DC
                break;
            case 4:
                *txtc=0;
                system("COLOR 5F");//------------DC
                break;
            case 5 :
                *txtc=4;
                system("COLOR 1F");//------------DC
                break;
            default:

                fullscreenmode ? fullscrm(0):windowmode(0);
                printf("<>undefined input");
                Sleep(2000);
                clrscr();
                goto labelnew;
                break;
            }

            goto mylabel2;
        }
        else if (temp2==2)
        {
            if(fullscreenmode==1)
            {
                fullscreenmode=0;
            }
            else
            {
                fullscreenmode=1;
            };
            clrscr();
            goto mylabel2;
        }
        else if(temp2==3)
        {
            if(DM==1)
            {
                DM=0;
            }
            else
            {
                DM=1;
            }
            clrscr();
            goto mylabel2;
        }
        else if(temp2==4)
        {
            clrscr();
mylabels:
            fullscreenmode ? fullscrm(1):windowmode(1);
            printf("# Cell cover ->1    current ( %c )",sqr);
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# Mine ->2    current ( %c )",mn);
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# Flag ->3    current ( %c )",flg);
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# uncertain sign ->4    current ( %c )",uc);
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# Reset ->5");
            fullscreenmode ? fullscrm(0):windowmode(0);
            printf("# Back ->0");
            char temp3[50];
            int t=0;
            fflush(stdin);
            while(1)
            {
                fflush(stdin);
                fullscreenmode ? fullscrm(0):windowmode(0);
                printf("->");
                gets(temp3);
                if(isdigit(temp3[0])&&temp3[0]-48<=5&&temp3[0]-48>0&&temp3[1]=='\0')
                {
                    t=temp3[0]-48;
                    break;
                }
                else if(isdigit(temp3[0])&&temp3[0]-48<=5&&temp3[0]-48==0&&temp3[1]=='\0')
                {
                    clrscr();
                    goto mylabel2;
                    break;
                }
                else
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("<>Error\n");
                }
            }
            if(t!=5)
            {
                SS:
                fullscreenmode ? fullscrm(0):windowmode(0);
                printf("* Enter the new char(space or numbers are not allowed) :");
                fflush(stdin);
                gets(temp3);
                if(temp3[0]==' '||temp3[1]!='\0'||(temp3[0]>='0'&&temp3[0]<='9'))
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("<>ERROR");
                    goto SS;
                }
            }
            switch(t)
            {
            case 1 :
                if(temp3[0]!=mn&&temp3[0]!=flg&&temp3[0]!=uc)
                {
                    sqr=temp3[0];
                }
                else
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("<>Repeated shape !");
                    Sleep(2000);
                }
                break;
            case 2:
                if(temp3[0]!=sqr&&temp3[0]!=flg&&temp3[0]!=uc)
                {
                    mn=temp3[0];
                }
                else
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("<>Repeated shape !");
                    Sleep(2000);
                }
                break;
            case 3:
                if(temp3[0]!=mn&&temp3[0]!=sqr&&temp3[0]!=uc)
                {
                    flg=temp3[0];
                }
                else
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("<>Repeated shape !");
                    Sleep(2000);
                }
                break;
            case 4:
                if(temp3[0]!=mn&&temp3[0]!=flg&&temp3[0]!=sqr)
                {
                    uc=temp3[0];
                }
                else
                {
                    fullscreenmode ? fullscrm(0):windowmode(0);
                    printf("Repeated shape !");
                    Sleep(2000);
                }
                break;
            default:
                sqr='X',mn='*',flg='F',uc='?';
                break;
            }

            clrscr();
            goto mylabels;

        }
        else if(temp2==5)
        {
            switch(arrowmode)
            {
            case 0 :
                arrowmode=1;
                break;
            case 1:
                arrowmode=0;
                break;
            default:
                arrowmode=0;
                break;
            }
            clrscr();
            goto mylabel2;
        }
        else if(temp2==6)
        {
            clrscr();
            printf("* Enter sleep time in seconds(minimum is 5 sec) :");
            int test;
            test=5;
            while(test!=1||*sleept<5||*sleept>10000000)
            {
                if(  test==0||*sleept<5||*sleept>10000000)
                {
                    clrscr();
                    printf("<>Error\n* Enter sleep time in seconds (minimum is 5 sec):");
                }
                fflush(stdin);
                test=scanf("%d",sleept);
                fflush(stdin);
            }
            clrscr();
            goto mylabel2;
        }
        else if(temp2==7){
            clearHistory();
            clrscr();
            goto mylabel;
        }
        else if (temp2==0)
        {

            clrscr();
            goto mylabel;
        }
        else
        {
            clrscr();
            goto mylabel;
        }
    }





}
