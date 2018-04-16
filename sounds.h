
void *welcomeS (){
int i;
x:
i=400;
for(int j=0;j<4;j++){
    Beep(i,360);
    Beep(i,350);
    Beep(i,360);
    Beep(i,600);

    Beep(i,200);
    if(j==3){Beep(i,1000);}else{
    Beep(i,200);Sleep(50);}
    i+=100;
if(enteredd==1){break;}
}
Sleep(4000);
i=400;
if(enteredd==0){
goto x;
}

}


void welcomesound(){

        pthread_t thr4;
    pthread_create(&thr4,NULL,welcomeS,NULL);

}




void *wons (){

Beep(350,300);
}


void winsound(){

        pthread_t thr5;
    pthread_create(&thr5,NULL,wons,NULL);

}



void *loses (){
int i=0;
while (enteredd==0){
    Beep(1200,300);
}
while(enteredd==2){
        Beep(500+i,50);
        Sleep(50);
i+=20;
if(i==100){i-=100;}
}

}




void losesound(){

        pthread_t thr7;
    pthread_create(&thr7,NULL,loses,NULL);

}
