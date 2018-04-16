void setvalue(point arr[][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            arr[i][j].pointed=0;
        }
    }
    if(arrowmode==1)
    {
        arr[0][0].pointed=1;

    }


    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            arr[i][j].value=sqr;
            arr[i][j].hidden=0;
        }
    }

}

void setminepos(point arr[][width],int p1,int p2,int firstt )
{
    int minex,miney,ch=0;
    time_t atime;
    time(&atime);
    for(int s=0; s<numofmines; s++)
    {
        srand(atime+ch);
        minex=(rand()%height);
        miney=(rand()%width);


        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if((i==minex&&j==miney&&arr[i][j].hidden==9)||(i==minex&&j==miney&&p1==i&&p2==j&&firstt==1))
                {
                    s--;
                    ch++;

                }
                else if(i==minex&&j==miney)
                {
                    arr[i][j].hidden=9;
                }
            }
        }
    }

}

void setnums(point arr[][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(arr[i][j].hidden==9)
            {
                for(int i2=i-1; i2<i-1+3&&i2<height; i2++)
                {
                    if(i2<0)
                    {
                        continue;
                    }
                    for(int j2=j-1; j2<j-1+3&&j2<width; j2++)
                    {
                        if(j2<0)
                        {
                            continue;
                        }
                        switch(arr[i2][j2].hidden)
                        {
                        case 9 :
                            break;
                        default:
                            arr[i2][j2].hidden++;
                            break;
                        }
                    }
                }

            }
        }
    }
}

char showhiddenforDM(point arr[][width],int x,int y)
{
    for(int a=0; a<height; a++)
    {
        for(int b=0; b<width; b++)
        {
            if(a==x&&b==y)
            {
                switch (arr[a][b].hidden)
                {
                case 9 :
                    return mn;
                    break;
                case 0 :
                    return' ';
                    break;
                default:
                    return (arr[a][b].hidden+'0');
                    break;//'0'=48 in ascci table converting num to char
                }
            }
        }
    }
}

void printscreenvale(point arr[][width])
{



//--------------------------------------------------------------first 2 lines
    printf("Flages left : %d ",numofmines-flgn);
    int mid=width/2;
    if(DM==1)
    {
        mid=width;
    }
    else
    {
        mid=(width/2)-2;
    }
    for(int i =0; i<mid; i++)
    {
        printf("    ");
    }
    if(gameover==0)
    {
        printf("^_^");
    }
    else if(gameover==1)
    {
        printf("-_-");
    }
    else if(gameover==2)
    {
        printf("^_^");
    }

    printf("\tnumber of %c is:%d \tnumber of moves :%d",uc,numofqm,numofmoves);


    printf("\n\t     ");
//-------------------------------------------------------------up numbers
    for(int i =0; i <width*2; i++)
    {
        if(DM==0&&i==width)
        {
            break;
        }
        if(i<width)
        {
            if(i<9)
            {
                printf("%d   ",i+1);
            }
            else if(i>=9)
            {
                printf("%2d  ",i+1);
            }
        }
        else if(i==width)
        {
            printf("          %2d   ",i+1-width);
        }
        else if(i>width)
        {
            if(i<9+width)
            {
                printf("%d   ",i+1-width);
            }
            else if(i>=9+width)
            {
                printf("%2d  ",i+1-width);
            }
        }
    }
    //---------------------------------------------------------------up dashes

    printf("\n\t     ");//3 spaces for 3d and 1 for near space
    for(int s=0; s<=width*2; s++)
    {
        if(DM==0&&s==width)
        {
            break;
        }
        else if(s==width)
        {
            printf("           ");
        }
        else printf("-   ");//+
    }
    printf("\n");
//------------------------------------------------------------------------values


    char which,whichn;

    for(int x=0; x<height; x++)
    {
        if(arr[x][0].pointed==1&&arrowmode==1)
        {
            whichn='>';   // rremove &&arrowmode==1 to point to last play point ;
        }
        else
        {
            whichn=' ';
        }
        printf("\t%3d|%c",x+1,whichn); // fl25er

        for(int y=0; y<width*2; y++)
        {
            if(DM==0&&y==width)
            {
                break;
            }
            if(y<width)
            {
                if(arr[x][y].pointed==1&&arrowmode==1)
                {
                    which='<';
                }
                else
                {
                    which=' ';
                }
                if(arr[x][y+1].pointed==1&&y!=width-1&&arrowmode==1)
                {
                    whichn='>';
                }
                else
                {
                    whichn=' ';
                }

                printf("%c%c|%c",arr[x][y].value,which,whichn);//+ 2blha - b3ha
            }
            else if(y==width)
            {
                printf("      %3d| %c | ",x+1,showhiddenforDM(arr,x,y-width));
            }
            else if(y>width)
            {
                printf("%c | ",showhiddenforDM(arr,x,y-width));
            }
        }

        printf("\n");
                        if(DM==0){

        printf("\t   |");

        for(int id=0;id<width;id++){
                printf("---|");


        }
        }else{

        printf("\t   |");

        for(int id=0;id<width;id++){
                printf("---|");}
        printf("          |");
        for(int id=0;id<width;id++){
                printf("---|");}
        }
printf("\n");
    }

    //-------------------------------------------------------------------   down dashes
/*
    printf("\t     ");
    for(int s=0; s<width*2; s++)
    {
        if(DM==0&&s==width)
        {
            break;
        }
        if(s==width)
        {
            printf("           ");
        }
        printf("-  ");
    }
    printf("\n");


*/

}

void setallhidtoval(point arr[][width])
{
    for(int a=0; a<height; a++)
    {
        for(int b=0; b<width; b++)
        {
            switch (arr[a][b].hidden)
            {
            case 9 :
                if(gameover==2)
                {
                    arr[a][b].value=flg;
                }
                else if(gameover==1&&arr[a][b].pointed==1)
                {
                    arr[a][b].value='!';
                }
                else if(gameover==1&&arr[a][b].value!=flg)
                {
                    arr[a][b].value='M';

                }
                else
                {
                    arr[a][b].value=mn;
                }
                break;
            case 0 :
                if(gameover==1&&arr[a][b].value==flg)
                {
                    arr[a][b].value='-';

                }
                else
                {
                    arr[a][b].value=' ';
                }
                break;
            default:
                arr[a][b].value=arr[a][b].hidden+'0';
                break;
            }
        }
    }
}

void spacecase(point arr[][width],int k,int l)
{

    arr[k][l].value=' ';
    for(int i=k-1; i<k-1+3&&i<height; i++)
    {
        if(i<0)
        {
            continue;
        }
        for(int j=l-1; j<l-1+3&&j<width; j++)
        {
            if(j<0)
            {
                continue;
            }
            switch(arr[i][j].hidden)
            {
            case 9 :
                break;
            case 0:
                if(arr[i][j].value==sqr||arr[i][j].value==flg||arr[i][j].value==uc)
                {
                    if(arr[i][j].value==flg)
                    {
                        flgn--;
                    }
                    spacecase(arr,i,j);
                }
                break;
            default:
                if(arr[i][j].value==flg)
                {
                    flgn--;
                }
                arr[i][j].value=arr[i][j].hidden+'0';
                break;
            }
        }
    }
}
void opencell (point arr[][width],int a,int b)
{
    switch(arr[a][b].hidden)
    {
    case 0:
        spacecase(arr,a,b);
        break;
    case 9:
        gameover=1;
        break;
    default:
        arr[a][b].value=arr[a][b].hidden+48;
        break;
    }
}
void solvecell(point arr[][width],int a,int b)
{
    int flagesAssociated=0;
    int flagesG=arr[a][b].value-48;
    for(int i=a-1; i<a-1+3&&i<height; i++)
    {
        if(i<0)
        {
            continue;
        }
        for(int j=b-1; j<b-1+3&&j<width; j++)
        {
            if(j<0)
            {
                continue;
            }
            if(arr[i][j].value==flg)
            {
                flagesAssociated++;
            }
        }
    }
    if(flagesAssociated==flagesG)
    {
        for(int i=a-1; i<a-1+3&&i<height; i++)
        {
            if(i<0)
            {
                continue;
            }
            for(int j=b-1; j<b-1+3&&j<width; j++)
            {
                if(j<0)
                {
                    continue;
                }
                if(arr[i][j].value==sqr||arr[i][j].value==uc)
                {
                    if(arr[i][j].value==uc)
                    {
                        numofqm--;
                    }
                    opencell(arr,i,j);
                }
            }
        }
    }
}

