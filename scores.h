

typedef struct
{
    int score;
    char name[100];//value which will be printed
    char date[100];
    int numOfScores;
} playerscore;

void topScore()
{
    FILE*fp1=fopen("score.txt","r");
    fseek(fp1,0,SEEK_END);
    if(ftell(fp1)==0)
    {
        printf("Not Yet");
    }
    else{
    FILE*fp2=fopen("score.txt","r");
    char name[100],date[100];
    int score;
    fgets(name,100,fp2);
    fscanf(fp2,"%d",&score);
    char a=fgetc(fp2);
    for(int i=0;i<100;i++){
        date[i]='#';
    }int p=0;
    fgetsh(date,fp2);
    for(int i=0;i<100;i++){
        if(date[i]=='#'){break;}
        p++;
    }

printf("%d     AT:",score);
             for(int i=0;i<p;i++){

              printf("%c",date[i]);

    }

    printf("   BY THE AWESOME:%s",name);
fclose(fp2);}
fclose(fp1);
}
void ranko()
{
    playerscore arr[100];
    int counter=0;
    FILE*fp2=fopen("score.txt","r");
        fflush(fp2);
        for(int i=0; !feof(fp2); i++,counter++)
        {
            fgets(arr[i].name,15,fp2);
            fscanf(fp2,"%d",&arr[i].score);
            char a=fgetc(fp2);
            fgetsh(arr[i].date,fp2);

        }
        counter--;
        fclose(fp2);

    clrscr();
    printf("   Player        |   Score  |Date\n");
    printf("-------------------------------------------------------------------------\n");
    for(int i=0;i<counter;i++)
    {
        int len=length(arr[i].name);
        for(int j=0;j<len-1;j++)
            printf("%c",arr[i].name[j]);
        for(int j=len-1;j<15;j++)
            printf(" ");
        printf("|%-10d|%s\n",arr[i].score,arr[i].date);
        printf("-------------------------------------------------------------------------\n");
    }

}
void SaveScore(int score)
{
    char name [150];
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
            printf("Invalid Symbol\n\n");
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
    for(int i=0; name[i]!='\0'; i++)
    {
        if(islower(name[i]))
            name[i]=name[i]+('A'-'a');
    }
    if(DM==1){
            strcat(name,"(DM)");

    }



    playerscore arr[100];
    time_t  t = time(NULL);
    struct tm tm = *localtime(&t);
    int flag =0,counter=0;
    FILE*fp2=fopen("score.txt","r");

        for(int i=0; !feof(fp2); i++,counter++)
        {
            fgets(arr[i].name,100,fp2);
            fscanf(fp2,"%d",&arr[i].score);
            char a=fgetc(fp2);
            fgets(arr[i].date,100,fp2);

        }
        counter--;
        fclose(fp2);
        int occure;
        for(int i=0;i<counter;i++)
        {
            char temp[100];
            strcpy(temp,arr[i].name);
            if(strncmp(temp,name,length(temp)-1)==0&&length(temp)-1==length(name))
            {
                occure=i;
                flag=1;
                break;
            }
        }
        FILE*writer =fopen("score.txt","w");
        if(flag==1)
        {
            strncpy(name,arr[occure].name,length(arr[occure].name)-1);
            if (score<arr[occure].score)
            {
                score=arr[occure].score;
            }
        }
        int the_flag=0;
        for(int i=0; i<counter; i++)
        {
            if(flag==1&&i==occure)
            {
                continue;
            }
            if (arr[i].score>score||the_flag==1)
            {
                fputs(arr[i].name,writer);
                fprintf(writer,"%d\n",arr[i].score);
                fputs(arr[i].date,writer);
            }
            else
            {

                fputs(name,writer);

		fprintf(writer,"\n%d\n",score);
                fprintf(writer,"%d\\%d-%d:%d\n",tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
                i--;
                the_flag=1;
            }
        }
        if (the_flag==0)
        {
                fputs(name,writer);
                fprintf(writer,"\n%d\n",score);
                fprintf(writer,"%d\\%d-%d:%d\n",tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
        }



fclose(writer);}


/*
typedef struct
{
    int score;
    char name[100];//value which will be printed
    char date[100];
    int numOfScores;
} playerscore;

void topScore()
{
    FILE*fp2=fopen("score.txt","r");
    char name[100],date[100];
    int score;
    fgetsh(name,fp2);
    fscanf(fp2,"%d",&score);
    char a=fgetc(fp2);
    fgets(date,100,fp2);
printf("%d    BY THE AWESOME:%s     AT:%s",score,name,date);
fclose(fp2);
}
void ranko()
{
    playerscore arr[100];
    int counter=0;
    FILE*fp2=fopen("score.txt","r");

        for(int i=0; !feof(fp2); i++,counter++)
        {
            fgetsh(arr[i].name,fp2);
            fscanf(fp2,"%d",&arr[i].score);
            char a=fgetc(fp2);
            fgetsh(arr[i].date,fp2);

        }
        counter--;
        fclose(fp2);

    clrscr();
    printf("Player      |   Score  |Date\n");
    printf("-------------------------------------------------------------------------\n");
    for(int i=0;i<counter;i++)
    {
        printf("  %-10s|%-10d|%s\n",arr[i].name,arr[i].score,arr[i].date);
        printf("-------------------------------------------------------------------------\n");
    }

}
void SaveScore(int score)
{
    char name [150];
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
            printf("Invalid Symbol\n\n");
        }
        gets(name);
        fl=1;
        for(int i=0; name[i]!='\0'; i++)
        {
            if (name[i]=='@'||name[i]==' ')
                fl=0;
        }
    }
    while(fl==0);
    for(int i=0; name[i]!='\0'; i++)
    {
        if(islower(name[i]))
            name[i]=name[i]+('A'-'a');
    }
    playerscore arr[100];
    time_t  t = time(NULL);
    struct tm tm = *localtime(&t);
    int flag =0,counter=0;
    FILE*fp2=fopen("score.txt","r");

        for(int i=0; !feof(fp2); i++,counter++)
        {
            fgets(arr[i].name,100,fp2);
            fscanf(fp2,"%d",&arr[i].score);
            char a=fgetc(fp2);
            fgets(arr[i].date,100,fp2);

        }
        counter--;
        fclose(fp2);
        int occure;
        for(int i=0;i<counter;i++)
        {
            char temp[100];
            strcpy(temp,arr[i].name);
            if(strncmp(temp,name,length(temp)-1)==0&&length(temp)-1==length(name))
            {
                occure=i;
                flag=1;
                break;
            }
        }
        FILE*writer =fopen("score.txt","w");
        if(flag==1)
        {
            strncpy(name,arr[occure].name,length(arr[occure].name)-1);
            if (score<arr[occure].score)
            {
                score=arr[occure].score;
            }
        }
        int the_flag=0;
        for(int i=0; i<counter; i++)
        {
            if(flag==1&&i==occure)
            {
                continue;
            }
            if (arr[i].score>score||the_flag==1)
            {
                fputs(arr[i].name,writer);
                fprintf(writer,"%d\n",arr[i].score);
                fputs(arr[i].date,writer);
            }
            else
            {
                fputs(name,writer);
                fprintf(writer,"\n%d\n",score);
                fprintf(writer,"%d\\%d-%d:%d\n",tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
                i--;
                the_flag=1;
            }
        }
        if (the_flag==0)
        {
                fputs(name,writer);
                fprintf(writer,"\n%d\n",score);
                fprintf(writer,"%d\\%d-%d:%d\n",tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
        }



fclose(writer);}
*/
