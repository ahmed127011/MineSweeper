
void clrscr()
{
    system("@cls||clear");
}





void fgetsh(char name[],FILE*fp1)
{
    int i=0;
    do
    {
        char a=fgetc(fp1);
        if (a=='\n'||feof(fp1))
        {

            break;

            }

        name[i]=a;
        i++;

    }
    while (!feof(fp1));
}
int length(char a[])
{
    int i=0;
    while (a[i]!='\0'&&a[i]!=' ')
        i++;
    return i;

}



void fullscrm(int a)  //a represents f it is the first line or not to make new lines
{
    a ? printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t"):printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
}
void windowmode(int a )
{
    a ? printf("\n\n\n\n\n\n\n\n\t\t\t\t\t"):printf("\n\n\n\t\t\t\t\t");
}


