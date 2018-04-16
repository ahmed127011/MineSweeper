void printIt(point arr[][width])
{
    FILE* fp1=fopen("solved.txt","w");
    for(int i=0;i<=width;i++)
    {
        if(i==0)
            fprintf(fp1,"  ||");
        else
        fprintf(fp1,"%3d|",i);
    }

for(int a=0; a<height; a++)
    {
        fprintf(fp1,"\n");
        for(int k=0;k<=width;k++)
            fprintf(fp1,"----");
        fprintf(fp1,"\n");
        fprintf(fp1,"%2d||",a+1);

        for(int b=0; b<width; b++)
        {

                switch (arr[a][b].hidden)
                {
                case 9 :
                    fprintf(fp1,"%3c|",mn);
                    break;
                case 0 :
                    fprintf(fp1,"   |");
                    break;
                default:
                    fprintf(fp1,"%3d|",arr[a][b].hidden);
                    break;//'0'=48 in ascci table converting num to char
                }

        }
    }
fclose(fp1);

}


void findFiles()
{
    FILE *fcheck=fopen("saves.txt","r");
    if(fcheck==NULL)
    {
        FILE *fmake=fopen("saves.txt","w");
    }
    FILE *fcheck1=fopen("names.txt","r");
    if(fcheck1==NULL)
    {
        FILE *fmake=fopen("names.txt","w");
    }
    FILE *fcheck2=fopen("score.txt","r");
    if(fcheck2==NULL)
    {
        FILE *fmake=fopen("score.txt","w");
    }
    fclose(fcheck);
    fclose(fcheck1);
    fclose(fcheck2);

}
int loadHeightWidth(char name[])
{
    FILE *fp1=fopen("names.txt","r");
    int numOfNames;
    char names[150][100];
    for(numOfNames=0; !feof(fp1); numOfNames++)
    {
        fgetsh(names[numOfNames],fp1);

    }

    if(numOfNames==0||ftell(fp1)==0)
    {
        printf("No saves were found Here!!\n\n");
        Sleep(3000);
        return 0;
    }
    else
    {
rechoose:
        printf("Choose the name you saved with or enter 0 to go back:\n\n");

        for(int i=0; i<numOfNames-1; i++)
        {

            printf("%-25s-------> %d\n\n\n",names[i],i+1);
        }
        int n;
        scanf("%d",&n);
        if(n==0){return 0;}//===================================================
        if(n>numOfNames-1||n<1)
        {
            clrscr();
            printf("please choose a valid number\n\n");
            goto rechoose;
        }
        else
        {
            strcpy(name,names[n-1]);
        }
        FILE *fp2=fopen("saves.txt","r");
        int theFlag=0;
        while(!feof(fp2))
        {
            char temp[100];
            fgets(temp,100,fp2);
            int templen=length(temp)-1;
            if(temp[0]=='@')
            {
                for(int i=0; i<templen; i++)
                    temp[i]=temp[i+1];
                if(strncmp(name,temp,length(temp)-2)==0)
                {
                    theFlag=1;
                    break;
                }
            }

        }

        if (theFlag==1)
        {
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&height);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&width);
            fclose(fp2);
        }
    }
    return 1;
}








void loadIt(point arr[][width],char name[],int *time)
{
FILE *fp2=fopen("saves.txt","r");
        int theFlag=0;
        while(!feof(fp2))
        {
            char temp[100];
            fgets(temp,100,fp2);
            int templen=length(temp)-1;
            if(temp[0]=='@')
            {
                for(int i=0; i<templen; i++)
                    temp[i]=temp[i+1];
                if(strncmp(name,temp,length(temp)-2)==0)
                {
                    theFlag=1;
                    break;
                }
            }

        }

        if (theFlag==1)
        {
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&height);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&width);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&flgn);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofmoves);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofqm);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofmines);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",time);
 		while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&DM);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                {
                    a=fgetc(fp2);

                    break;
                }
            }
            char temp[100][100];
            for(int i=0; i<height; i++)
            {
                fgetsh(temp[i],fp2);

            }
            for(int i=0; i<height; i++)
            {
                for(int j=0; j<width; j++)
                    arr[i][j].hidden=temp[i][j]-48;
            }

            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                {
                    a=fgetc(fp2);
                    break;
                }

            }
            for(int i=0; i<height; i++)
            {
                char temp[100];
                fgetsh(temp,fp2);
                for(int j=0; j<width; j++)
                {
                    if(temp[j]=='s')
                    arr[i][j].value=sqr;
                   else if(temp[j]=='m')
                    arr[i][j].value=mn;
                    else if(temp[j]=='f')
                    arr[i][j].value=flg;
                    else if(temp[j]=='u')
                    arr[i][j].value=uc;
                    else if(temp[j]==' ')
                    arr[i][j].value=' ';
                    else
                        arr[i][j].value=temp[j];
                }
            }
        }


        fclose(fp2);

}

void deleteIt(char name[])
{
    int namelen=length(name),counter=0;
    char temp[100][1000];
    FILE *f1=fopen("saves.txt","r");
    for(int i=0; !feof(f1); i++)
    {
        char line [100];
        fgets(line,100,f1);
        if(line[0]=='@')
        {
            int flag=0;
            for(int j=0; j<namelen; j++)
            {
                if(name[j]!=line[j+1])
                {
                    flag=1;
                    break;
                }
            }
            if (flag!=1)
            {
                while(1)
                {
                    fgets(line,100,f1);
                    if (line[0]=='@'||feof(f1))
                    {
                        break;
                    }
                }
            }
        }
        strcpy(temp[i],line);
        counter++;
    }
    fclose(f1);
    FILE *f2=fopen("saves.txt","w");
    for(int i=0; i<counter-1; i++)
    {
        fputs(temp[i],f2);
    }
    fclose(f2);
    FILE *fnames=fopen("names.txt","r");
    char tempname[100][1000];
    int names=0;
    while(!feof(fnames))
    {
        char line[100];
        fgets(line,100,fnames);
        if((strncmp(line,name,length(line)-1)!=0)&&(line[0]!='\n'))
        {
            strcpy(tempname[names],line);
            names++;
            printf("%d ",names);
        }
    }
    fclose(fnames);
    FILE* fp3=fopen("names.txt","w");
    for(int i=0; i<names; i++)
    for(int i=0; i<names; i++)
        fputs(tempname[i],fp3);

}
void saveIt(point arr[][width],char name[],int timee)
{
    //hidden value
    FILE *fp1=fopen("saves.txt","a");
    fprintf(fp1,"@");
    fputs(name,fp1);
    fprintf(fp1,"\nheight:%d\nwidth:%d",height,width);
    fprintf(fp1,"\nflags:%d\nnumber of moves:%d\nquestion marks:%d\nmines:%d\ntime:%d\ndeveloper mode:%d",flgn,numofmoves,numofqm,numofmines,timee,DM);
    fprintf(fp1,"\nhidden:");
    for(int i=0; i<height; i++)
    {
        //changing the symbols
        fprintf(fp1,"\n");
        for(int j=0; j<width; j++)
        {
            fputc(arr[i][j].hidden+48,fp1);
        }
    }
    fprintf(fp1,"\nvalue:");
    for(int i=0; i<height; i++)
    {
        fprintf(fp1,"\n");
        for(int j=0; j<width; j++)
        {
            if(arr[i][j].value==sqr)
                fputc('s',fp1);
            else if(arr[i][j].value==mn)
                fputc('m',fp1);
             else if(arr[i][j].value==flg)
                fputc('f',fp1);
            else if(arr[i][j].value==uc)
                fputc('u',fp1);
            else if(arr[i][j].value==' ')
                fputc(' ',fp1);
                else
                    fputc(arr[i][j].value,fp1);

        }
    }

    fprintf(fp1,"\n");
    fclose(fp1);
    FILE *fp2=fopen("names.txt","a");
    time_t  t = time(NULL);
    struct tm tm = *localtime(&t);
   if(ftell(fp2)==0)
    {
        fprintf(fp2,"%s %d\\%d %d:%d\n",name,tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

    }
     else
    {
        fprintf(fp2,"\n%s %d\\%d %d:%d",name,tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
    }
    fclose(fp2);

}
void SAVET(point arr[][width],int time)
{
    FILE *fp2;
    fp2=fopen("names.txt","r");
    char name[150];
    int fl=1;
     printf("Enter your Name (without any spaces or \"@\" symbol):\n\n");
    do
    {

        if(fl==0)
        {
            if(fl==0)
            {
                printf("Invalid Symbol\n\n");
            }
        }
        fflush(stdin);
        gets(name);
        fl=1;
        for(int i=0; name[i]!='\0'; i++)
        {
            if (name[i]=='@'||name[i]==' '||name[i]=='\t')
                fl=0;
        }
        if(length(name)==0)
            fl=0;
    }
    while(fl==0);

reSearch:
    fseek(fp2,0,SEEK_SET);
    int flag=0;
    for(int i=0; name[i]!='\0'; i++)
    {
        if(islower(name[i]))
            name[i]=name[i]+('A'-'a');
    }
    while(!feof(fp2))
    {
        char temp[100];
        fgets(temp,100,fp2);
        if(strncmp(temp,name,length(temp)-1)==0&&length(temp)==length(name))
        {
            flag=1;
            break;
        }


    }
    if(flag==1)


    {
        clrscr();
        printf("Name is saved before \n\nSave with different name--> 1\n\ngo to main menu-->2\n\n");
        char dec[2];
        dec[1]='\0';
reprint:
        gets(dec);
        if(dec[1]!='\0')
            printf("error making decision");
        if(dec[0]=='1')
        {
            printf("please enter the name\n");
            gets(name);
            goto reSearch;
        }
        else if (dec[0]=='2')
        {
            return 0;
        }
        else
        {
            printf("Unknown decision\n\nPlease enter 1 or 2\n\n");
            goto reprint;
        }

    }
    else if (flag==0)
    {
        saveIt(arr,name,time);
    }

}
void clearHistory()
{
    clrscr();
    printf("clear save history ------> 1\nclear score history ------> 2\nclear score and save---->3\n Or press any key to go back ");
    char a;
    a=getchar();
        FILE *fp1;
FILE *fp2;
    FILE *fp3;

    switch (a){
case '1':
    fp1=fopen("saves.txt","w");
    fclose(fp1);
    fp2=fopen("names.txt","w");
    fclose(fp2);
    break;
case '2':
    fp3=fopen("score.txt","w");
    fclose(fp3);
    break;
case '3':
    fp1=fopen("saves.txt","w");
    fclose(fp1);
    fp2=fopen("names.txt","w");
    fclose(fp2);
    fp3=fopen("score.txt","w");
    fclose(fp3);
    break;
    default:
        return 0;
        break;}
}



/*
int loadHeightWidth(char name[])
{
    FILE *fp1=fopen("names.txt","r");
    int numOfNames;
    char names[150][100];
    for(numOfNames=0; !feof(fp1); numOfNames++)
    {
        fgetsh(names[numOfNames],fp1);

    }

    if(numOfNames==0||ftell(fp1)==0)
    {
        printf("No saves were found Here!!\n\n");
        Sleep(3000);
        return 0;
    }
    else
    {
rechoose:
        printf("Choose the name you saved with or enter 0 to go back:\n\n");

        for(int i=0; i<numOfNames; i++)
        {

            printf("%-25s-------> %d\n\n\n",names[i],i+1);
        }
        int n;
        scanf("%d",&n);
        if(n==0){return 0;}//===================================================
        if(n>numOfNames||n<1)
        {
            clrscr();
            printf("please choose a valid number\n\n");
            goto rechoose;
        }
        else
        {
            strcpy(name,names[n-1]);
        }
        FILE *fp2=fopen("saves.txt","r");
        int theFlag=0;
        while(!feof(fp2))
        {
            char temp[100];
            fgets(temp,100,fp2);
            int templen=length(temp)-1;
            if(temp[0]=='@')
            {
                for(int i=0; i<templen; i++)
                    temp[i]=temp[i+1];
                if(strncmp(name,temp,length(temp)-2)==0)
                {
                    theFlag=1;
                    break;
                }
            }

        }

        if (theFlag==1)
        {
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&height);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&width);
            fclose(fp2);
        }
    }
    return 1;
}








void loadIt(point arr[][width],char name[],int *time)
{
FILE *fp2=fopen("saves.txt","r");
        int theFlag=0;
        while(!feof(fp2))
        {
            char temp[100];
            fgets(temp,100,fp2);
            int templen=length(temp)-1;
            if(temp[0]=='@')
            {
                for(int i=0; i<templen; i++)
                    temp[i]=temp[i+1];
                if(strncmp(name,temp,length(temp)-2)==0)
                {
                    theFlag=1;
                    break;
                }
            }

        }

        if (theFlag==1)
        {
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&height);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&width);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&flgn);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofmoves);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofqm);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",&numofmines);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                    break;
            }
            fscanf(fp2,"%d",time);
            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                {
                    a=fgetc(fp2);

                    break;
                }
            }
            char temp[100][100];
            for(int i=0; i<height; i++)
            {
                fgetsh(temp[i],fp2);

            }
            for(int i=0; i<height; i++)
            {
                for(int j=0; j<width; j++)
                    arr[i][j].hidden=temp[i][j]-48;
            }

            while(!feof(fp2))
            {
                char a=fgetc(fp2);
                if (a==':')
                {
                    a=fgetc(fp2);
                    break;
                }

            }
            for(int i=0; i<height; i++)
            {
                char temp[100];
                fgetsh(temp,fp2);
                for(int j=0; j<width; j++)
                {
                    arr[i][j].value=temp[j];
                }
            }
        }


        fclose(fp2);

}

void deleteIt(char name[])
{
    int namelen=length(name),counter=0;
    char temp[100][1000];
    FILE *f1=fopen("saves.txt","r");
    for(int i=0; !feof(f1); i++)
    {
        char line [100];
        fgets(line,100,f1);
        if(line[0]=='@')
        {
            int flag=0;
            for(int j=0; j<namelen; j++)
            {
                if(name[j]!=line[j+1])
                {
                    flag=1;
                    break;
                }
            }
            if (flag!=1)
            {
                while(1)
                {
                    fgets(line,100,f1);
                    if (line[0]=='@'||feof(f1))
                    {
                        break;
                    }
                }
            }
        }
        strcpy(temp[i],line);
        counter++;
    }
    fclose(f1);
    FILE *f2=fopen("saves.txt","w");
    for(int i=0; i<counter-1; i++)
    {
        fputs(temp[i],f2);
    }
    fclose(f2);
    FILE *fnames=fopen("names.txt","r");
    char tempname[100][1000];
    int names=0;
    while(!feof(fnames))
    {
        char line[100];
        fgets(line,100,fnames);
        if((strncmp(line,name,length(line)-1)!=0)&&(line[0]!='\n'))
        {
            strcpy(tempname[names],line);
            names++;
            printf("%d ",names);
        }
    }
    fclose(fnames);
    FILE* fp3=fopen("names.txt","w");
    for(int i=0; i<names; i++)
        fputs(tempname[i],fp3);

}
void saveIt(point arr[][width],char name[],int timee)
{
    //hidden value
    FILE *fp1=fopen("saves.txt","a");
    fprintf(fp1,"@");
    fputs(name,fp1);
    fprintf(fp1,"\nheight:%d\nwidth:%d",height,width);
    fprintf(fp1,"\nflags:%d\nnumber of moves:%d\nquestion marks:%d\nmines:%d\ntime:%d",flgn,numofmoves,numofqm,numofmines,timee);
    fprintf(fp1,"\nhidden:");
    for(int i=0; i<height; i++)
    {
        //changing the symbols
        fprintf(fp1,"\n");
        for(int j=0; j<width; j++)
        {
            fputc(arr[i][j].hidden+48,fp1);
        }
    }
    fprintf(fp1,"\nvalue:");
    for(int i=0; i<height; i++)
    {
        fprintf(fp1,"\n");
        for(int j=0; j<width; j++)
        {

            fputc(arr[i][j].value,fp1);
        }
    }

    fprintf(fp1,"\n");
    fclose(fp1);
    FILE *fp2=fopen("names.txt","a");
    time_t  t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp2,"\n%s %d\\%d %d:%d",name,tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
    fclose(fp2);

}
void SAVET(point arr[][width],int time)
{
    FILE *fp2;
    fp2=fopen("names.txt","r");
    char name[150];
    int fl=1;
    do
    {
        if(fl==0)
        {
            clrscr();
        }


        printf("Enter your Name (without any spaces or \"@\" symbol):\n\n");
        if(fl==0)
        {
            if(fl==0)
            {
                printf("Invalid Symbol\n\n");
            }
        }
        fflush(stdin);
        gets(name);
        fl=1;
        for(int i=0; name[i]!='\0'; i++)
        {
            if (name[i]=='@'||name[i]==' ')
                fl=0;
        }
    }
    while(fl==0);

reSearch:
    fseek(fp2,0,SEEK_SET);
    int flag=0;
    for(int i=0; name[i]!='\0'; i++)
    {
        if(islower(name[i]))
            name[i]=name[i]+('A'-'a');
    }
    while(!feof(fp2))
    {
        char temp[100];
        fgets(temp,100,fp2);
        if(strncmp(temp,name,length(temp)-1)==0&&length(temp)==length(name))
        {
            flag=1;
            break;
        }


    }
    if(flag==1)


    {
        clrscr();
        printf("Name is saved before \n\nSave with different name--> 1\n\nSave and neglect the old one-->2\n\n");
        char dec[2];
        dec[1]='\0';
reprint:
        gets(dec);
        if(dec[1]!='\0')
            printf("error making decision");
        if(dec[0]=='1')
        {
            printf("please enter the name\n");
            gets(name);
            goto reSearch;
        }
        else if (dec[0]=='2')
        {
            deleteIt(name);
            saveIt(arr,name,time);

        }
        else
        {
            printf("Unknown decision\n\nPlease enter 1 or 2\n\n");
            goto reprint;
        }

    }
    else if (flag==0)
    {
        saveIt(arr,name,time);
    }

}*/

