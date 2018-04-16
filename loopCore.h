void arrowwmode(point arr[][width],int *ap,int* bp,int *cp,int *menu1,int timeee)
{

    char a;
    *cp=10;
    int px,py;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(arr[i][j].pointed==1)
            {
                py=i;
                px=j;
                break;
            }
        }
    }
    printf("move the arrow  w->up , s->down , d->right , a->left\npress\no->open cell\nf->flag\np->uncertain sign\nu-> remove mark \nr->solve near cells\nq->Exit\nv->save and exit\n");
labelSIM:
    fflush(stdin);
    a=getch();

    switch (a)
    {
    case 'w':
        if(py==0)
        {
            goto labelSIM;
            break;
        }
        else
        {
            arr[py][px].pointed=0;
            arr[py-1][px].pointed=1;
            break;
        }
    case 's':
        if(py==height-1)
        {
            goto labelSIM;
            break;
        }
        else
        {
            arr[py][px].pointed=0;
            arr[py+1][px].pointed=1;
            break;
        }
    case 'd':
        if(px==width-1)
        {
            goto labelSIM;
            break;
        }
        else
        {
            arr[py][px].pointed=0;
            arr[py][px+1].pointed=1;
            break;
        }
    case 'a':
        if(px==0)
        {
            goto labelSIM;
            break;
        }
        else
        {
            arr[py][px].pointed=0;
            arr[py][px-1].pointed=1;
            break;
        }
    case 'f':
        *cp=0;
        break;
    case 'o':
        *cp=1;
        break;
    case 'p':
        *cp=3;
        break;
    case 'u':
        *cp=2;
        break;
    case 'r':
        *cp=4;
        break;
    case 'v':
                scanned=1;

        SAVET(arr,timeee);
        *menu1=12;
        break;
    case 'q':
        *menu1=12;
        break;
    default :
        printf("\n<>you entered undefined char -make sure that your keyboard is English!!");
        goto labelSIM;
        break;



    }
            scanned=1;

    *ap=py;
    *bp=px;




}



void *waiting (void *argi)
{

    blk *argnw=argi;


    time_t mytime;
    int diffint;
    point arr25[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            arr25[i][j].hidden=argnw->arr12[i][j].hidden;
            arr25[i][j].value=argnw->arr12[i][j].value;
            arr25[i][j].pointed=argnw->arr12[i][j].pointed;

        }
    }
    diffint=argnw->timee;
    while(scanned==0)
    {

        while((time(&mytime)-argnw->olda)-diffint<argnw->sleeptime&&scanned==0) //6000
        {
            Sleep(20);

            //printf("a7a elprocessor etfash5\n");                 problem ----------------------------
        }
        if(scanned==0)
        {


            clrscr();
            printf("minutes : %d   - seconds : %d\n",(time(&mytime)-argnw->olda)/60,(time(&mytime)-argnw->olda)%60);
            printscreenvale(arr25);


            if(argnw->arrM==1)
            {
                printf("move the arrow  w->up , s->down , d->right , a->left\npress\no->open cell\nf->flag\np->uncertain sign\nu-> remove mark \nr->solve near cells\nq->Exit\nv->save and exit\n");

            }
            else
            {
                printf("\n* just (0) to exit to the menu\n      (-1) to save and exit \nEnter the row then the column Then:  \n* 1 for click\n* 0 for flag ->F\n* 2 to remove a mark \n* 3 for uncertain ->?\n* 4 for open cell\n* For example (1 2 0) will flag the square at row 1 column 2\n");

            }

        }

        diffint=time(&mytime)-argnw->olda;
    }

}

void updateinf (point arr[][width], int *menu1,int *firsttime,int timeee,int old,int sleept)
{


    int a,b,c;
    pthread_t thr1;
    blk arg;
    arg.arrM=arrowmode;
    arg.timee=timeee;
    arg.olda=old;
    arg.sleeptime=sleept;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            arg.arr12[i][j].hidden=arr[i][j].hidden;
            arg.arr12[i][j].value=arr[i][j].value;
            arg.arr12[i][j].pointed=arr[i][j].pointed;

        }
    }
        scanned=0;


    pthread_create(&thr1,NULL,waiting,&arg);
fflush(stdin);

    if(arrowmode==0)
    {
        printf("\n* just (0) to exit to the menu\n      (-1) to save and exit \nEnter the row then the column Then:  \n* 1 for click\n* 0 for flag ->F\n* 2 to remove a mark \n* 3 for uncertain ->?\n* 4 for open cell\n* For example (1 2 0) will flag the square at row 1 column 2\n");
        char line[50];


        a=-2,b=-1,c=-1;

        while(a>height||a<-1)
        {
            a=-2;
            fflush(stdin);
            scanf("%d",&a);


            if(a>height||a<-1)
            {
                printf("\n<>Error,wrong value was entered\n");
            }
        }
        if(a==0)
        {
            fflush(stdin);
            printf("* Are you sure that you wan to exit ?\nyou will lose the progress you made!\n1 yes,sure\n2 continue game\n");

        }
        while(a==0)
        {
            scanned=1;
            fflush(stdin);

            gets(line);

            if(isdigit(line[0])&&line[0]-48==1)
            {
                (*menu1=12);
                return 1;
            }
            else if(isdigit(line[0])&&line[0]-48==2)
            {
                return 1;
            }
            else
            {
                printf("<>The input you entered isn't defined by the system\n");
            }

        }
        if(a==-1)
        {
            scanned=1;
            SAVET(arr,timeee);
            *menu1=12;
            return 0;
        }
        while(b>width||b<=0||c<0||c>4)
        {
            b=-1;
            c=-1;
            scanf("%d %d",&b,&c);scanned=1;
            if(b>width||b<=0||c<0||c>4)
            {
                fflush(stdin);
                printf("<>Error :you may entered an alpha char or out of range number\n");
                Sleep(1000);
                return 0;
            }

        }



        clrscr();
        a--;
        b--;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                arr[i][j].pointed=0;
            }
        }
        arr[a][b].pointed=1;

    }
    else
    {
        arrowwmode(arr,&a,&b,&c,menu1,timeee);

    }


    scanned=1;

    if(*firsttime==1&&c==1&&(arr[a][b].value!=flg||arr[a][b].value!=uc))               //firsttim
    {

        if(arr[a][b].hidden==9)
        {

            for(int i=0; i<height; i++)
            {
                for(int j=0; j<width; j++)
                {
                    if(arr[i][j].value!=flg&&arr[i][j].value!=uc)
                    {
                        arr[i][j].value=sqr;
                    }
                    arr[i][j].hidden=0;
                }
            }

            arr[a][b].pointed=1;
            setminepos(arr,a,b,1);
            setnums(arr);
        }

        printIt(arr);
        *firsttime=0;

    }

    if(c==1&&arr[a][b].value!=sqr)
    {
        c=99;   //ignores a click to flag
    }

    if(c==1)
    {

        opencell(arr,a,b);
        numofmoves++;
    }

    else if (c==0&&(arr[a][b].value==sqr||arr[a][b].value==uc)&&flgn<numofmines)
    {
        arr[a][b].value=flg;
        flgn++;
        numofmoves++;
    }
    else if(c==2&&(arr[a][b].value==flg||arr[a][b].value==uc))
    {
        if(arr[a][b].value==flg)
        {
            flgn--;
        }
        else if(arr[a][b].value==uc)
        {
            numofqm--;
        }
        arr[a][b].value=sqr;
        numofmoves++;
    }
    else if(c==3&&(arr[a][b].value==sqr||arr[a][b].value==flg))
    {
        if(arr[a][b].value==flg)
        {
            flgn--;
        }
        numofqm++;
        numofmoves++;
        arr[a][b].value=uc;
    }
    else if(c==4&&arr[a][b].value>48&&arr[a][b].value<57)
    {
        solvecell(arr,a,b);
        numofmoves++;
    }
    int welldone=0;
    int opened=0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(arr[i][j].hidden==9&&arr[i][j].value==flg)
            {
                welldone++;
            }
            if(arr[i][j].value!=sqr&&arr[i][j].value!=uc&&arr[i][j].value!=flg)
            {
                opened++;
            }
        }
    }
    if(welldone==numofmines||opened==(width*height)-numofmines)
    {
        gameover=2;
    }
    else
    {
        welldone=0;
        opened=0;
    }
}
