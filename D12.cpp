#include <iostream>
#include <cstdlib>
#include <ctime>
#define delay Delay(1 * 1000)
using namespace std;
int goal,dir,health,firststep,HP,failcount,orbnum;
int a1,a2,a3,a4,a5,a6,a7,a8,a9;
int place[9];
int num=0;
int flag=0;
int orb=0;
int current[9]={a1,a2,a3,a4,a5,a6,a7,a8,a9};
string path[1000];
void Delay(int time){
    clock_t now = clock();
    while (clock() - now < time);
}
void A1();
void A2();
void A3();
void A4();
void A5();
void A6();
void A7();
void A8();
void A9();
void A10();
void change(int goal);
void orbset(int want);
void orbfinish();
void A1(){
    orbset(orbnum);
    //cout<<"a1\n"<<health<<"\n";
    num++;
    int dir1;
    dir1=rand()%2;
    if(health<=0){
        A10();
    }
    else if(dir1==1){
        change(2);
        path[num]="right";
        A2();
    }
    else{
        change(4);
        path[num]="down";
        A4();
    }
    //cout<<"   "<<dir1<<"\n";
}
void A2(){
    orbset(orbnum);
    //cout<<"a2\n"<<health<<"\n";
    num++;
    int dir2;
    dir2=rand()%3;
    if(health<=0){
        A10();
    }
    else if(dir2==1){
        change(1);
        path[num]="left";
        A1();
    }
    else if(dir2==2){
        change(3);
        path[num]="right";
        A3();
    }
    else{
        change(5);
        path[num]="down";
        A5();
    }
    //cout<<"   "<<dir2<<"\n";
}
void A3(){
    orbset(orbnum);
    //cout<<"a3\n"<<health<<"\n";
    num++;
    int dir3;
    dir3=rand()%2;
    if(health<=0){
        A10();
    }
    else if(dir3==1){
        change(2);
        path[num]="left";
        A2();
    }
    else{
        change(6);
        path[num]="down";
        A6();
    }
    //cout<<"   "<<dir<<"\n";
}
void A4(){
    orbset(orbnum);
    //cout<<"a4\n"<<health<<"\n";
    num++;
    int dir4;
    dir4=rand()%3;
    if(health<=0){
        A10();
    }
    else if(dir4==1){
        change(1);
        path[num]="up";
        A1();
    }
    else if(dir4==2){
        change(5);
        path[num]="right";
        A5();
    }
    else{
        change(7);
        path[num]="down";
        A7();
    }
    //cout<<"   "<<dir<<"\n";
}
void A5(){
    orbset(orbnum);
    //cout<<"a5\n"<<health<<"\n";
    num++;
    int dir5;
    dir5=rand()%4;
    if(health<=0){
        A10();
    }
    else if(dir5==1){
        change(2);
        path[num]="up";
        A2();
    }
    else if(dir5==2){
        change(4);
        path[num]="left";
        A4();
    }
    else if(dir5==3){
        change(6);
        path[num]="right";
        A6();
    }
    else{
        change(8);
        path[num]="down";
        A8();
    }
    //cout<<"   "<<dir<<"\n";
}
void A6(){
    orbset(orbnum);
    //cout<<"a6\n"<<health<<"\n";
    num++;
    int dir6;
    dir6=rand()%3;
    if(health<=0){
        A10();
    }
    else if(dir6==1){
        change(3);
        path[num]="up";
        A3();
    }
    else if(dir6==2){
        change(5);
        path[num]="left";
        A5();
    }
    else{
        change(9);
        path[num]="down";
        A9();
    }
    //cout<<"   "<<dir<<"\n";
}
void A7(){
    orbset(orbnum);
    //cout<<"a7\n"<<health<<"\n";
    num++;
    int dir7;
    dir7=rand()%2;
    if(health<=0){
        A10();
    }
    else if(dir7==1){
        change(8);
        path[num]="right";
        A8();
    }
    else{
        change(4);
        path[num]="up";
        A4();
    }
    //cout<<"   "<<dir<<"\n";
}
void A8(){
    orbset(orbnum);
    //cout<<"a8\n"<<health<<"\n";
    num++;
    int dir8;
    dir8=rand()%3;
    if(health<=0){
        A10();
    }
    else if(dir8==1){
        change(5);
        path[num]="up";
        A5();
    }
    else if(dir8==2){
        change(7);
        path[num]="left";
        A7();
    }
    else{
        change(9);
        path[num]="right";
        A9();
    }
    //cout<<"   "<<dir<<"\n";
}
void A9(){
    orbset(orbnum);
    //cout<<"a9\n"<<health<<"\n";
    num++;
    int dir9;
    dir9=rand()%2;
    if(health<=0){
        A10();
    }
    else if(dir9==1){
        change(6);
        path[num]="up";
        A6();
    }
    else{
        change(8);
        path[num]="left";
        A8();
    }
    //cout<<"   "<<dir<<"\n";
}
void A10(){
    failcount++;
    //cout<<"\ndied\n";
    //cout<<"orb:"<<orb;
    //main gogo
}
void counting(int area){
    //cout<<"\narea: "<<area<<" ";
    if(area==1){
        //cout<<" -5 ";
        health=health-30;
    }
    else if(area==2){
        //cout<<" +1 ";
        health=health-55;
        orb++;
    }
    else if(area==3){
        //cout<<" nothing ";
        health=health-25;
        orb=orb-5;
        if(orb<=0){
            orb=0;
        }
    }
    else if(area==0){
        //cout<<" -530 ";
        health=health-530;
    }
}
void gogo(){
    for(int i=0;i<=8;i++){
        place[i]=current[i];
    }
    for(int i=0;i<=999;i++){
        path[i]=" ";
    }
    orb=0;
    num=0;
    firststep=rand()%4;
    //cout<<"firststep:"<<firststep<<"\n";
    //health=0;
    if(firststep==0){
        //cout<<"\nfirstup \n";
        change(2);
        path[0]="up";
        A2();
    }
    else if(firststep==1){
        //cout<<"\nfirstleft \n";
        change(4);
        path[0]="left";
        A4();
    }
    else if(firststep==2){
        //cout<<"\nfirstright \n";
        change(6);
        path[0]="right";
        A6();
    }
    else if(firststep==3){
        //cout<<"\nfirstdown \n";
        change(8);
        path[0]="down";
        A8();
    }
}
void change(int goal){
    goal--;
    //cout<<"goal:  "<<goal<<"  endl ";
    for(int i=0;i<=8;i++){
        place[i]++;
        //cout<<place[i]<<" ";
        //cout<<"goal: "<<goal;
        place[i]=place[i]%4;
        }
        if(place[goal]==0){
            place[goal]=4;
        }
        place[goal]--;
    //cout<<"\nchange:"<<place[5];
    counting(place[goal]);
}
void orbset(int want){
    if(orb==want){
            orbfinish();
            orb=100;
        }
}
void orbfinish(){
    orb=100;
    //cout<<"orbnum:  "<<orbnum<<"  num:  "<<num<<"\n";
    for(int i=0;i<=num;i++){
        cout<<path[i]<<" "<<endl;
    }
    flag=1;
}
int main(){
    srand(time(NULL)+getpid());
    cin>>HP>>orbnum;
    health=HP;
    //cout<<health;
    //1=nothing 2=+1orb -25hp 3=+5hp -5orb 4=-500hp
    for(int i=0;i<=8;i++)
        cin>>current[i];
    /* 1 2 3
       4 5 6
       7 8 9 */
    gogo();
    while(true){
            if(flag==1){
                    //cout<<"\nfailcount: "<<failcount<<"  ";
                break;
            }
            else if(health<=0){
            //cout<<"success";
            health=HP;
            gogo();
            //delay;
        }
    }
    /*for(int i=0;i<=100;i++){
        cout<<"\npath"<<i<<" "<<path[i];
    }*/
    cout<<"\nfailcount: "<<failcount;
    return 0;

}
/*
有3*3的格子 每個格子有4種狀態，每移動一次狀態會改變到下個狀態，移動到的那個不會改變狀態，
起始點在中央，在hp(1000)歸0前收集一定量物品，4種狀態分別事1:沒事 2:+1能量球，-25hp 3:+5hp -5能量球 4.-500hp，求出解
*/
