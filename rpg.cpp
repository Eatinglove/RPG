#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#define delay Delay(1 * 1000)
using namespace std;

int  X, Y, Z, potion, key=0,keyprice=5000;
string dungeonkey="未擁有";
int sword = 0, armor = 0;
int area = 1, areamax = 1;
void Delay(int time)
{
    clock_t now = clock();
    while (clock() - now < time);
}
struct stats
{
    int health, healthmax, money, att, def, lvl,exp,expmax;
};
stats player;
struct wood
{
    int Just_wood, Wowood, GOuOd, Gwood;
};
wood Wood;
struct stone
{
    int Cobblestone, Double_compressed_cobblestone, Sextuple_compressed_cobblestone, Octuple_compressed_cobblestone;
};
stone Stone;
struct food
{
    int Grass, Rice, Steak, GODLYFOOD;
};
food Food;
struct mineral
{
    int Iron, Gold, Emerald, Diamond;
};
mineral Mineral;
struct material
{
    int turtle, paper, eye, wing, horn;
};
material mobdrop;
material mobdropmax;
int levelup()
{
    if(player.lvl<10)
        return 500;
    else if(player.lvl<20)
        return 2500;
    else if(player.lvl<30)
        return 10000;
    else if(player.lvl<40)
        return 25000;
    else if(player.lvl<50)
        return 50000;
    else 
        return 100000;
}
void level(int z)
{
    player.exp=player.exp+z;
    while(player.exp>=player.expmax)
    {
        cout<<"Leveled up!!!\n攻擊+1\n防禦+1\n血量+5"<<endl;
        player.exp=player.exp-player.expmax;
        player.expmax=player.expmax+levelup();
        player.lvl++;
        player.att++;
        player.def++;
        player.healthmax=player.healthmax+5;
    }
}
void mdrop()
{
        int drop;
        drop = rand() % 100;
        if (90 <= drop)
        {
            if (area == 1 && mobdropmax.turtle>0)
            {
                cout << "你的到了一片龜殼" << endl;
                mobdrop.turtle=mobdrop.turtle+1;
                mobdropmax.turtle=mobdropmax.turtle-1;
            }
            if (area == 2 && mobdropmax.paper>0)
            {
                cout << "你得到了一張羊皮紙" << endl;
                mobdrop.paper=mobdrop.paper+1;
                mobdropmax.paper=mobdropmax.paper-1;
            }
            if (area == 3 && mobdropmax.eye>0)
            {
                cout << "你得到了一隻巨人之眼" << endl;
                mobdrop.eye=mobdrop.eye+1;
                mobdropmax.eye=mobdropmax.eye-1;
            }
            if (area == 4 && mobdropmax.wing>0)
            {
                cout << "你得到了一雙精靈翅膀" << endl;
                mobdrop.wing=mobdrop.wing+1;
                mobdropmax.wing=mobdropmax.wing-1;
            }
            if (area == 5 && mobdropmax.horn>0)
            {
                cout << "你的到了一跟惡魔之角" << endl;
                mobdrop.horn=mobdrop.horn+1;
                mobdropmax.horn=mobdropmax.horn-1;
            }
        }
}
void openwood(int tier)
{
    int a,b,c,d;
    a=rand()%2+1;
    b=rand()%3+1;
    c=rand()%5+1;
    d=rand()%10+1;
    if(tier==1)
    {       
        Wood.Just_wood=Wood.Just_wood+a;
        //Wood.Wowood=Wood.Wowood+a+1;
        cout<<"Just_wood+"<<a<<endl;
    }
    else if(tier == 2)
    {
        Wood.Just_wood=Wood.Just_wood+b;
        Wood.Wowood=Wood.Wowood+a;
        cout<<"Just_wood+"<<b<<"\nWowood+"<<a<<endl;
    }
    else if(tier == 3)
    {
        Wood.Just_wood=Wood.Just_wood+c;
        Wood.Wowood=Wood.Wowood+b;
        Wood.GOuOd=Wood.GOuOd+a;
        cout<<"Just_wood+"<<c<<"\nWowood+"<<b<<"\nGOuOd+"<<a<<endl;
    }
    else if(tier == 4)
    {
        Wood.Just_wood=Wood.Just_wood+d;
        Wood.Wowood=Wood.Wowood+c;
        Wood.GOuOd=Wood.GOuOd+b;
        Wood.Gwood=Wood.Gwood+a;
        cout<<"Just_wood+"<<d<<"\nWowood+"<<c<<"\nGOuOd+"<<b<<"\nGwood+"<<a<<endl;
    }
    else if(tier == 5)
    {
        Wood.Just_wood=Wood.Just_wood+5000;
        Wood.Wowood=Wood.Wowood+500;
        Wood.GOuOd=Wood.GOuOd+50;
        Wood.Gwood=Wood.Gwood+5;
        cout<<"Just_wood+5000\nWowood+500\nGOuOd+50\nGwood+5"<<endl;
    }
}
void openstone(int tier)
{
    int a,b,c,d;
    a=rand()%2+1;
    b=rand()%3+1;
    c=rand()%5+1;
    d=rand()%10+1;
    if(tier==1)
    {
        Stone.Cobblestone=Stone.Cobblestone+a;
        cout<<"Cobblestone+"<<a<<endl;
    }
    else if(tier==2)
    {
        Stone.Cobblestone=Stone.Cobblestone+b;
        Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+a;
        cout<<"Cobblestone+"<<b<<"\nDouble_compressed_cobblestone+"<<a<<endl;
    }
    else if(tier==3)
    {
        Stone.Cobblestone=Stone.Cobblestone+c;
        Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+b;
        Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone+a;
        cout<<"Cobblestone+"<<c<<"\nDouble_compressed_cobblestone+"<<b<<
        "\nSextuple_compressed_cobblestone+"<<a<<endl;
    }
    else if(tier==4)
    {
        Stone.Cobblestone=Stone.Cobblestone+d;
        Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+c;
        Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone+b;
        Stone.Octuple_compressed_cobblestone=Stone.Octuple_compressed_cobblestone+a;
        cout<<"Cobblestone+"<<d<<"\nDouble_compressed_cobblestone+"<<c<<
        "\nSextuple_compressed_cobblestone+"<<b<<"\nOctuple_compressed_cobblestone+"<<a<<endl;
    }
    else if(tier==5)
    {
        Stone.Cobblestone=Stone.Cobblestone+5000;
        Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+500;
        Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone+50;
        Stone.Octuple_compressed_cobblestone=Stone.Octuple_compressed_cobblestone+5;
        cout<<"Cobblestone+5000\nDouble_compressed_cobblestone+500"<<
        "\nSextuple_compressed_cobblestone+50\nOctuple_compressed_cobblestone+5"<<endl;
    }
}
void mobdropplus(int turtle,int eye,int paper,int wing,int horn)
{
    mobdrop.turtle=mobdrop.turtle+turtle;
    mobdrop.paper=mobdrop.paper+paper;
    mobdrop.eye=mobdrop.eye+eye;
    mobdrop.wing=mobdrop.wing+wing;
    mobdrop.horn=mobdrop.horn+horn;
    if(turtle!=0)
        cout<<"你獲得 "<<turtle<<" 龜殼"<<endl;
    if(paper!=0)
        cout<<"\n你獲得 "<<paper<<" 羊皮紙"<<endl;
    if(eye!=0)
        cout<<"\n你獲得 "<<eye<<" 巨人之眼"<<endl;
    if(wing!=0)
        cout<<"\n你獲得 "<<wing<<" 精靈翅膀"<<endl;
    if(horn!=0)
        cout<<"\n你獲得 "<<horn<<" 惡魔角"<<endl;
    mobdropmax.turtle=mobdropmax.turtle-turtle;
    mobdropmax.paper=mobdropmax.paper-paper;
    mobdropmax.eye=mobdropmax.eye-eye;
    mobdropmax.wing=mobdropmax.wing-wing;
    mobdropmax.horn=mobdropmax.horn-horn;
}
void mobdropsubs(int turtle, int eye,int paper, int wing,int horn)
{
    if(mobdropmax.turtle<turtle)
    {
        turtle=mobdropmax.turtle;
        mobdropmax.turtle=0;
    }
    if(mobdropmax.eye<eye)
    {
        eye=mobdropmax.eye;
        mobdropmax.eye=0;
    }
    if(mobdropmax.paper<paper)
    {
        paper=mobdropmax.paper;
        mobdropmax.paper=0;
    }
    if(mobdropmax.wing<wing)
    {
        wing=mobdropmax.wing;
        mobdropmax.wing=0;
    }
    if(mobdropmax.horn<horn)
    {
        horn=mobdropmax.horn;
        mobdropmax.horn=0;
    }
    mobdropplus(turtle,paper,eye,wing,horn);
}
void mobdropmaxarea(int turtle, int paper,int eye, int wing,int horn )
{
    switch(areamax)
    {
        case 1:
            paper=0;
            eye=0;
            wing=0;
            horn=0;
            break;
        case 2:
            eye=0;
            wing=0;
            horn=0;
            break;
        case 3:
            wing=0;
            horn=0;
            break;
        case 4:
            horn=0;
            break;
    }
    mobdropsubs(turtle,paper,eye,wing,horn);
}
void openmobdrop(int tier)
{
    int a,b,c,d,e;
    a=rand()%2;
    b=rand()%3;
    c=rand()%5;
    d=rand()%10;
    int turtle,paper,eye,wing,horn;
    if(tier==1)
    {
        turtle=paper=eye=wing=horn=a;
        mobdropmaxarea(a,a,a,a,a);       
    }
    else if(tier==2)
    {
        turtle=paper=b;
        eye=wing=horn=a;
        mobdropmaxarea(b,b,a,a,a);
    }
    else if(tier==3)
    {
        turtle=c;
        paper=eye=b;
        wing=horn=a;
        mobdropmaxarea(c,b,b,a,a);
    }
    else if(tier==4)
    {
        turtle=paper=d;
        eye=wing=c;
        horn=b;
        mobdropmaxarea(d,d,c,c,b);
    }
    else if(tier==5)
    {
        turtle=paper=eye=wing=horn=d;
        mobdropmaxarea(d,d,d,d,d);
    }
}
void open()
{
    int rarity,a,mobdroprng;
    rarity= rand()%1000;
    mobdroprng=rand()%100;
    if(rarity <750)
    {
        cout<<"You got a lootbox, normie lb and normie reward. You opened it."<<endl;
        openwood(1);
        openstone(1);
        if(mobdroprng>90)
            openmobdrop(1);
    }
    else if(rarity>=750 && rarity<900)
    {
        cout<<"You got a lootbox(but better and also bigger),"<<
        "bigger chest, more thing, better day. You open it carefully."<<endl;
        openwood(2);
        openstone(2);
        if(mobdroprng>75)
            openmobdrop(2);
    }
    else if(rarity>=900 && rarity<990)
    {
        cout<<"WAH!! You got a super lootbox, which is super good. You opened it gave you a SUPERise!!!"<<endl;
        openwood(3);
        openstone(3);
        if(mobdroprng>50)
            openmobdrop(3);
    }
    else if(rarity>=990 && rarity<999)
    {
        cout<<"OMG!! You got a GODLY lootbox, the GOD got boring watching you hunting all the time"
        <<" and decided to give this to you. You thanked the GOD and opened it."<<endl;
        openwood(4);
        openstone(4);
        if(mobdroprng>20)
            openmobdrop(4);
    }
    else if(rarity==999)
    {
        cout<<"WWOOWOWOOOWOOW You got a ???, you don't even know what is that!! "<< 
        "This must be the luckiest time of your life! \nAnd it opened itself. "<<endl;
        openwood(5);
        openstone(5);
        openmobdrop(5);
    }
}
void lb()
{
    int a;
    a=rand()%8;
    if(a>5)
        open();
    else
        return;
}
void hunt(stats a1, stats a2, stats a3, stats a4, stats a5)
{
    int mob;
    mob = rand() % 3;
    if(player.health==0)
        cout<<"先回血吧"<<endl;
    else if (mob == 0)
    {
        if (area == 1)
        {
            cout << "你遇到了mutant battery" << endl;
            X = player.att + player.def - a1.att - a1.def;
            Y = 20 + rand() % 10;
            Z = 5+rand()%10;
        }
        else if (area == 2)
        {
            cout << "你遇到了giant baseball bat" << endl;
            X = player.att + player.def - a2.att - a2.def;
            Y = 100 + rand() % 100;
            Z = 100+rand()%100;
        }
        else if (area == 3)
        {
            cout << "你遇到了wild sprayer" << endl;
            X = player.att + player.def - a3.att - a3.def;
            Y = 1000 + rand() % 1000;
            Z = 500+rand()%500;
        }
        else if (area == 4)
        {
            cout << "你遇到了scary grandma" << endl;
            X = player.att + player.def - a4.att - a4.def;
            Y = 5000 + rand() % 5000;
            Z = 1000+rand()%1000;
        }
        else
        {
            cout << "你遇到了hyper dragon" << endl;
            X = player.att + player.def - a5.att - a5.def;
            Y = 20000 + rand() % 20000;
            Z = 5000+rand()%5000;
        }
    }
    else if (mob == 1)
    {
        if (area == 1)
        {
            cout << "你遇到了undefined keyboard" << endl;
            X = player.att + player.def - a1.att - a1.def;
            Y = 20 + rand() % 10;
            Z = 5+rand()%10;
        }
        else if (area == 2)
        {
            cout << "你遇到了the yeee" << endl;
            X = player.att + player.def - a2.att - a2.def;
            Y = 100 + rand() % 100;
            Z = 100+rand()%100;
        }
        else if (area == 3)
        {
            cout << "你遇到了scary vacuum cleaner" << endl;
            X = player.att + player.def - a3.att - a3.def;
            Y = 1000 + rand() % 1000;
            Z = 500+rand()%500;
        }
        else if (area == 4)
        {
            cout << "你遇到了annoying gaki" << endl;
            X = player.att + player.def - a4.att - a4.def;
            Y = 5000 + rand() % 5000;
            Z = 1000+rand()%1000;
        }
        else
        {
            cout << "你遇到了idk flying object" << endl;
            X = player.att + player.def - a5.att - a5.def;
            Y = 20000 + rand() % 20000;
            Z = 5000+rand()%5000;
        }
    }
    else
    {
        mdrop();
        if (area == 1)
        {        
            cout << "你遇到了cute turtle" << endl;
            X = player.att + player.def - a1.att - a1.def;
            Y = 20 + rand() % 10;
            Z = 5+rand()%10;
        }
        else if (area == 2)
        {
            cout << "你遇到了flying lightning book" << endl;
            X = player.att + player.def - a2.att - a2.def;
            Y = 100 + rand() % 100;
            Z = 100+rand()%100;
        }
        else if (area == 3)
        {
            cout << "你遇到了little giant" << endl;
            X = player.att + player.def - a3.att - a3.def;
            Y = 1000 + rand() % 1000;
            Z = 500+rand()%500;
        }
        else if (area == 4)
        {
            cout << "你遇到了normie elf" << endl;
            X = player.att + player.def - a4.att - a4.def;
            Y = 5000 + rand() % 5000;
            Z = 1000+rand()%1000;
        }
        else
        {
            cout << "你遇到了evil devil" << endl;
            X = player.att + player.def - a5.att - a5.def;
            Y = 20000 + rand() % 20000;
            Z = 5000+rand()%5000;
        }
        //cout<<drop<<endl;
    }
    //cout<<X<<endl;
    if(X>0)
    {
        X=0;
    }
    if(X<=0)
    {
        if(player.health+X<=0)
        {
            player.health=0;
            cout<<"你死了(從商店購買傷藥吧)"<<endl;
        }
        else if(player.health+X>0)
        {
            player.health = player.health + X;
            player.money = player.money + Y;
            cout << "獲得" << Y << "元"
            << "獲得" << Z << "經驗"
            << "剩下" << player.health << "血" << endl; 
            lb(); 
            level(Z);
        }
    }
}
void help()
{
    cout << "請輸入你想查詢的指令" << endl;
    cout << "\nhunt chop pickaxe farm mine area craft forge recipe1 recipe2 dungeon mob goal inventory profile" << endl;
    string Help;
    getline(cin, Help);
    if (Help == "hunt")
        cout << "打怪指令，注意自身血量，以免死亡，可在商店購買傷藥回血" << endl;
    else if (Help == "chop")
        cout << "用來採集木頭的指令，在不同區域會有不同的掉落，要採集前建議到高區域能夠採到較好的資源" << endl;
    else if (Help == "pickaxe")
        cout << "用來採集而鵝卵石的指令，在不同區域會有不同的掉落，要採集前建議到高區域能夠採到較好的資源" << endl;
    else if (Help == "farm")
        cout << "用來採集食物的指令，在不同區域會有不同的掉落，要採集前建議到高區域能夠採到較好的資源" << endl;
    else if (Help == "mine")
        cout << "用來採集礦物的指令，在不同區域會有不同的掉落，要採集前建議到高區域能夠採到較好的資源" << endl;
    else if (Help == "area")
        cout << "區域，共有5個，要解鎖下一區域需先通過地牢" << endl;
    else if (Help == "recipe素材")
        cout << "資源合成表:\n"
        <<"Wowood=25 Just_wood   WOuOd=10 Wowood  Gwood=10 WOuOd\nDouble_compressed_cobblestone=15 Cobblestone\n"
        <<"Sextuple_compressed_cobblestone=10 Double_compressed_cobblestone\n"
        <<"Ocutple_compressed_cobblestone=10 Sextuple_compressed_cobblestone\nGold= 10 Iron    Emarald=10 Gold   Diamond=10 Emerald\n"
        <<"Rice=10 Grass   Steak=10 Rice   GODLYFOOD=10 Diamond"<<endl;
    else if (Help == "recipe裝備")
        cout << "裝備合成表:\n攻擊類\n"
        <<"桃木劍:\n50 Just Wood\n20 cobblestone\n100 Grass\n5 龜殼\n"
        <<"石中劍:\n200 Double compressed cobblestone\n50 Wowood\n20 Rice\n30 Gold\n15 羊皮紙\n" 
        <<"紅色斧頭:\n100 Sextuple compress cobblestone\n100 GOuOd\n100 Emerald\n20 巨人之眼\n"
        <<"乞丐大劍:\n1000 Just wood\n100 Wowood\n10 GOuOd\n1 Gwood\n10 精靈翅膀\n"
        <<"無敵戳戳:\n5 Gwood\n50 Sextuple compressed cobblestone\n5 Diamond\n20 惡魔角\n"
        <<"EX咖哩棒:\n10 Gwood\n10 Octuple compressed cobblestone\n10 Godly food\n10 Diamond\n\n"
        <<"防禦類:\n"
        <<"白甲:\n35 Cobblestone\n100 Grass\n50 Iron\n5 龜殼\n"
        <<"藍甲:\n200 Just wood\n100Double compressed cobblestone\n30 Steak\n50 Gold\n15 羊皮紙\n"
        <<"紫甲:\n100 GOuOd\n100 Sextuple compressed cobblestone\n100 Emerald\n20 巨人之眼\n"
        <<"金甲:\n1000 Cobblestone\n100 Double compresssed cobblestone\n10 Sextuple compressed cobblestone\n1 Octuple compressed cobblestone\n10 精靈翅膀\n"
        <<"紅甲:\n5 Gwood\n20 Sextuple compressed cobblestone\n10 Godly food\n1 Diamond\n30 惡魔角\n"
        <<"彩虹甲:\n100 龜殼\n100 羊皮紙\n100 巨人之眼\n100 精靈翅膀\n100 惡魔角" << endl;
    else if (Help == "dungeon")
        cout << "前往下一區域的唯一方法，已解鎖區域不需再次挑戰地牢" << endl;
    else if (Help == "mob")
        cout << "每個區域共有3種怪，只有一種會掉落必須素材，且是機率性掉落" << endl;
    else if (Help == "goal")
        cout << "遊戲目標是做出最後裝備，打敗最終魔王，為了收集裝備，需要打怪以獲得素材，也需採集一些資源" << endl;
    else if (Help == "inventory")
        cout << "查看自己身上物品" << endl;
    else if (Help == "profile")
        cout << "查看自己現在狀態" << endl;
    else if(Help=="craft")
        cout<<"合成裝備用的指令，建議合成裝備再去打地牢"<<endl;
    else if(Help=="forge")
        cout<<"合成物資用的指令，輸入forge以了解更多"<<endl;
}
void chop()
{
    int tree;
    int a,b,c,d;
    tree = rand() % 100;
    if (area == 1)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (tree < 80)
        {
            Wood.Just_wood = Wood.Just_wood +a;
            cout<<"Just_wood+"<<a<<endl;
        }
        if (80 <= tree && tree < 95)
        {
            Wood.Wowood = Wood.Wowood + b;
            cout<<"Wowood+"<<b<<endl;
        }
        if (95 <= tree)
        {
            Wood.GOuOd = Wood.GOuOd + c;
            cout<<"GOuOd+"<<c<<endl;
        }
    }
    if (area == 2)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (tree < 80)
        {
            Wood.Just_wood = Wood.Just_wood +a;
            cout<<"Just_wood+"<<a<<endl;
        }
        if (80 <= tree && tree < 95)
        {
            Wood.Wowood = Wood.Wowood + b;
            cout<<"Wowood+"<<b<<endl;
        }
        if (95 <= tree)
        {
            Wood.GOuOd = Wood.GOuOd + c;
            cout<<"GOuOd+"<<c<<endl;
        }
    }
    if (area == 3)
    {
        a=rand() % 8 + 3;
        b=rand() % 3 + 1;
        c=1;
        if (tree < 80)
        {
            Wood.Just_wood = Wood.Just_wood +a;
            cout<<"Just_wood+"<<a<<endl;
        }
        if (80 <= tree && tree < 95)
        {
            Wood.Wowood = Wood.Wowood + b;
            cout<<"Wowood+"<<b<<endl;
        }
        if (95 <= tree)
        {
            Wood.GOuOd = Wood.GOuOd + c;
            cout<<"GOuOd+"<<c<<endl;
        }
    }
    if (area == 4)
    {
        a=rand() % 15 + 5;
        b=rand() % 5 + 2;
        c=1;
        d=1;
        if (tree < 70)
        {
            Wood.Just_wood = Wood.Just_wood +a;
            cout<<"Just_wood+"<<a<<endl;
        }
        if (70 <= tree && tree < 85)
        {
            Wood.Wowood = Wood.Wowood + b;
            cout<<"Wowood+"<<b<<endl;
        }
        if (85 <= tree && tree < 95)
        {
            Wood.GOuOd = Wood.GOuOd + c;
            cout<<"GOuOd+"<<c<<endl;
        }
        if (95 <= tree)
        {
            Wood.Gwood = Wood.Gwood + d;
            cout<<"Gwood+1"<<endl;
        }
    }
    if (area == 5)
    {
        a= rand() % 20 + 10;
        b=rand() % 10 + 5;
        c=rand() % 2 + 1;
        d=1;
        if (tree < 70)
        {
            Wood.Just_wood = Wood.Just_wood +a;
            cout<<"Just_wood+"<<a<<endl;
        }   
        if (70 <= tree && tree < 85)
        {
            Wood.Wowood = Wood.Wowood + b;
            cout<<"Wowood+"<<b<<endl;
        }
        if (85 <= tree && tree < 90)
        {
            Wood.GOuOd = Wood.GOuOd + c;
            cout<<"GOuOd+"<<c<<endl;
        }
        if (90 <= tree)
        {
            Wood.Gwood = Wood.Gwood + d;
            cout<<"Gwood+1"<<endl;
        }        
    }
    //cout << tree << " " << Wood.Just_wood << " " << Wood.Wowood << " " << Wood.GOuOd << " " << Wood.Gwood << endl;
}
void mine()
{
    int rock;
    int a,b,c,d;
    rock = rand() % 100;
    if (area == 1)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (rock < 80)
        {
            Stone.Cobblestone = Stone.Cobblestone + a;
            cout<<"Cobblestone+"<<a<<endl;
        }
        if (80 <= rock && rock < 95)
        {
            Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone + b;
            cout<<"Double_compressed_cobblestone+"<<b<<endl;
        }
        if (95 <= rock )
        {
            Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone + c;
            cout<<"Sextuple_compressed_cobblestone+"<<c<<endl;
        }
    }
    if (area == 2)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (rock < 80)
        {
            Stone.Cobblestone = Stone.Cobblestone + a;
            cout<<"Cobblestone+"<<a<<endl;
        }
        if (80 <= rock && rock < 95)
        {
            Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone + b;
            cout<<"Double_compressed_cobblestone+"<<b<<endl;
        }
        if (95 <= rock )
        {
            Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone + c;
            cout<<"Sextuple_compressed_cobblestone+"<<c<<endl;
        }
    }
    if (area == 3)
    {
        a=rand() % 8 + 3;
        b=rand() % 3 + 1;
        c=1;
        if (rock < 80)
        {
            Stone.Cobblestone = Stone.Cobblestone + a;
            cout<<"Cobblestone+"<<a<<endl;
        }
        if (80 <= rock && rock < 95)
        {
            Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone + b;
            cout<<"Double_compressed_cobblestone+"<<b<<endl;
        }
        if (95 <= rock )
        {
            Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone + c;
            cout<<"Sextuple_compressed_cobblestone+"<<c<<endl;
        }
    }
    if (area == 4)
    {
        a=rand() % 15 + 5;
        b=rand() % 5 + 2;
        c=1;
        d=1;
        if (rock < 70)
        {
            Stone.Cobblestone = Stone.Cobblestone + a;
            cout<<"Cobblestone+"<<a<<endl;
        }
        if (70 <= rock && rock < 85)
        {
            Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone + b;
            cout<<"Double_compressed_cobblestone+"<<b<<endl;
        }
        if (85 <= rock && rock < 90)
        {
            Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone + c;
            cout<<"Sextuple_compressed_cobblestone+"<<c<<endl;
        }
        if (95 <= rock)
        {
            Stone.Octuple_compressed_cobblestone = Stone.Octuple_compressed_cobblestone + d;
            cout<<"Ocutple_compressed_cobblestone+1"<<endl;
        } 
    }
    if (area == 5)
    {
        a= rand() % 20 + 10;
        b=rand() % 10 + 5;
        c=rand() % 2 + 1;
        d=1;
        if (rock < 70)
        {
            Stone.Cobblestone = Stone.Cobblestone + a;
            cout<<"Cobblestone+"<<a<<endl;
        }
        if (70 <= rock && rock < 85)
        {
            Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone + b;
            cout<<"Double_compressed_cobblestone+"<<b<<endl;
        }    
        if (85 <= rock && rock < 90)
        {
            Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone + c;
            cout<<"Sextuple_compressed_cobblestone+"<<c<<endl;
        }
        if (90 <= rock)
        {
            Stone.Octuple_compressed_cobblestone = Stone.Octuple_compressed_cobblestone + d;
            cout<<"Ocutple_compressed_cobblestone+1"<<endl;
        }   
    }
    //cout << rock << " " << Stone.Cobblestone << " " << Stone.Double_compressed_cobblestone << " " << Stone.Sextuple_compressed_cobblestone << " " << Stone.Octuple_compressed_cobblestone << endl;
}
void farm()
{
    int eat;
    int a,b,c,d;
    eat = rand() % 100;
    if (area == 1)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (eat < 80)
        {
            Food.Grass = Food.Grass + a;
            cout<<"Grass+"<<a<<endl;
        }
        if (80 <= eat && eat < 95)
        {
            Food.Rice = Food.Rice + b;
            cout<<"Rice+"<<b<<endl;
        }
        if (95 <= eat )
        {
            Food.Steak = Food.Steak +c;
            cout<<"Steak+"<<c<<endl;
        }
    }
    if (area == 2)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (eat < 80)
        {
            Food.Grass = Food.Grass + a;
            cout<<"Grass+"<<a<<endl;
        }
        if (80 <= eat && eat < 95)
        {
            Food.Rice = Food.Rice + b;
            cout<<"Rice+"<<b<<endl;
        }
        if (95 <= eat )
        {
            Food.Steak = Food.Steak +c;
            cout<<"Steak+"<<c<<endl;
        }
    }
    if (area == 3)
    {
        a=rand() % 8 + 3;
        b=rand() % 3 + 1;
        c=1;
        if (eat < 80)
        {
            Food.Grass = Food.Grass + a;
            cout<<"Grass+"<<a<<endl;
        }
        if (80 <= eat && eat < 95)
        {
            Food.Rice = Food.Rice + b;
            cout<<"Rice+"<<b<<endl;
        }
        if (95 <= eat )
        {
            Food.Steak = Food.Steak +c;
            cout<<"Steak+"<<c<<endl;
        }
    }
    if (area == 4)
    {
        a=rand() % 15 + 5;
        b=rand() % 5 + 2;
        c=1;
        d=1;
        if (eat < 70)
        {
            Food.Grass = Food.Grass + a;
            cout<<"Grass+"<<a<<endl;
        }
        if (70 <= eat && eat < 85)
        {
            Food.Rice = Food.Rice + b;
            cout<<"Rice+"<<b<<endl;
        }
        if (85 <= eat && eat < 95)
        {
            Food.Steak = Food.Steak +c;
            cout<<"Steak+"<<c<<endl;
        }
        if (95 <= eat)
        {
            Food.GODLYFOOD = Food.GODLYFOOD + d;
            cout<<"GODLYFOOD+1"<<endl;
        }
    }
    if (area == 5)
    {
        a= rand() % 20 + 10;
        b=rand() % 10 + 5;
        c=rand() % 2 + 1;
        d=1;
        if (eat < 70)
        {
            Food.Grass = Food.Grass + a;
            cout<<"Grass+"<<a<<endl;
        }    
        if (70 <= eat && eat < 85)
        {
            Food.Rice = Food.Rice + b;
            cout<<"Rice+"<<b<<endl;
        }
        if (85 <= eat && eat < 90)
        {
            Food.Steak = Food.Steak +c;
            cout<<"Steak+"<<c<<endl;
        }    
        if (90 <= eat)
        {
            Food.GODLYFOOD = Food.GODLYFOOD + d;
            cout<<"GODLYFOOD+1"<<endl;
        }
    }
    //cout << eat << " " << Food.Grass << " " << Food.Rice << " " << Food.Steak << " " << Food.GODLYFOOD << endl;
}
void pickaxe()
{
    
    int jewel;
    int a,b,c,d;
    jewel = rand() % 100;
    if (area == 1)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (jewel < 80)
        {
            Mineral.Iron = Mineral.Iron + a;
            cout<<"Iron+"<<a<<endl;
        }
        if (80 <= jewel && jewel < 95)
        {
            Mineral.Gold = Mineral.Gold + b;
            cout<<"Gold+"<<b<<endl;
        }
        if (95 <= jewel)
        {
            Mineral.Emerald = Mineral.Emerald + c;
            cout<<"Emerald+"<<c<<endl;
        }
    }
    if (area == 2)
    {
        a=rand() % 4 + 1;
        b=rand() % 2 + 1;
        c=1;
        if (jewel < 80)
        {
            Mineral.Iron = Mineral.Iron + a;
            cout<<"Iron+"<<a<<endl;
        }
        if (80 <= jewel && jewel < 95)
        {
            Mineral.Gold = Mineral.Gold + b;
            cout<<"Gold+"<<b<<endl;
        }
        if (95 <= jewel)
        {
            Mineral.Emerald = Mineral.Emerald + c;
            cout<<"Emerald+"<<c<<endl;
        };
    }
    if (area == 3)
    {
        a=rand() % 8 + 3;
        b=rand() % 3 + 1;
        c=1;
        if (jewel < 80)
        {
            Mineral.Iron = Mineral.Iron + a;
            cout<<"Iron+"<<a<<endl;
        }
        if (80 <= jewel && jewel < 95)
        {
            Mineral.Gold = Mineral.Gold + b;
            cout<<"Gold+"<<b<<endl;
        }
        if (95 <= jewel)
        {
            Mineral.Emerald = Mineral.Emerald + c;
            cout<<"Emerald+"<<c<<endl;
        }
    }
    if (area == 4)
    {
        a=rand() % 15 + 5;
        b=rand() % 5 + 2;
        c=1;
        d=1;
        if (jewel < 70)
        {
            Mineral.Iron = Mineral.Iron + a;
            cout<<"Iron+"<<a<<endl;
        }
        if (70 <= jewel && jewel < 85)
        {
            Mineral.Gold = Mineral.Gold + b;
            cout<<"Gold+"<<b<<endl;
        }
        if (85 <= jewel && jewel < 95)
        {
            Mineral.Emerald = Mineral.Emerald + c;
            cout<<"Emerald+"<<c<<endl;
        }
        if (95 <= jewel)
        {
            Mineral.Diamond = Mineral.Diamond + d;
            cout<<"Diamond+1"<<endl;
        }
    }
    if (area == 5)
    {
        a= rand() % 20 + 10;
        b=rand() % 10 + 5;
        c=rand() % 2 + 1;
        d=1;
        if (jewel < 70)
        {
            Mineral.Iron = Mineral.Iron + a;
            cout<<"Iron+"<<a<<endl;
        }
        if (70 <= jewel && jewel < 85)
        {
            Mineral.Gold = Mineral.Gold + b;
            cout<<"Gold+"<<b<<endl;
        } 
        if (85 <= jewel && jewel < 90)
        {
            Mineral.Emerald = Mineral.Emerald + c;
            cout<<"Emerald+"<<c<<endl;
        }
        if (90 <= jewel)
        {
            Mineral.Diamond = Mineral.Diamond + d;
            cout<<"Diamond+1"<<endl;
        }
    }
    //cout << jewel << " " << Mineral.Iron << " " << Mineral.Gold << " " << Mineral.Emerald << " " << Mineral.Diamond << endl;
}
void inv()
{
    cout << "你目前有"
         << "\nJust_wood:" << Wood.Just_wood << "\nWowood:" << Wood.Wowood << "\nGOuOd:" << Wood.GOuOd << "\nGwood:" << Wood.Gwood << endl;
    cout << "\nCobblestne:" << Stone.Cobblestone << "\nDouble_compressed_cobblestone:" << Stone.Double_compressed_cobblestone << "\nSextuple_compressed_cobblestone:" << Stone.Sextuple_compressed_cobblestone << "\nOctuple_compressed_cobblestone:" << Stone.Sextuple_compressed_cobblestone << endl;
    cout << "\nGrass:" << Food.Grass << "\nRice:" << Food.Rice << "\nSteak:" << Food.Steak << "\nGODLYFOOD:" << Food.GODLYFOOD << endl;
    cout << "\nIron:" << Mineral.Iron << "\nGold:" << Mineral.Gold << "\nEmerald:" << Mineral.Emerald << "\nDiamond:" << Mineral.Diamond << endl;
    cout<< "\n龜殼:"<<mobdrop.turtle<<"\n羊皮紙:"<<mobdrop.paper<<"\n巨人之眼:"<<mobdrop.eye<<"\n精靈翅膀:"<<mobdrop.wing<<"\n惡魔角:"<<mobdrop.horn<<endl;
    cout<<"\n鑰匙:"<<dungeonkey<<"\n傷藥:"<<potion<<endl;
}
void craft()
{
    cout << "請輸入你想打造的裝備" << endl;
    string Craft, confirm;
    //        cin >> Craft;
    getline(cin, Craft);
    if (Craft == "桃木劍")
    {
        if (sword != 0 && sword != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Wood.Just_wood < 50 || Stone.Cobblestone < 20 || Food.Grass < 100 || mobdrop.turtle < 5)
            {
                cout << "請準備足夠材料\n50 Just Wood\n20 cobblestone\n100 Grass\n5 龜殼" << endl;
                return;
            }
            else
            {
                cout << "即將製作...桃木劍\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Just_wood = Wood.Just_wood - 50;
                    Stone.Cobblestone = Stone.Cobblestone - 20;
                    Food.Grass = Food.Grass - 100;
                    mobdrop.turtle = mobdrop.turtle - 5;
                    cout << "製作成功" << endl;
                    sword = 1;
                    //cout<<sword<<endl;
                    player.att=player.att+30;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "石中劍")
    {
        if (sword < 1)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (sword != 1 && sword != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Stone.Double_compressed_cobblestone < 200 || Wood.Wowood < 50 || Food.Rice < 30 || Mineral.Gold < 30)
            {
                cout << "請準備足夠材料\n200 Double compressed cobblestone\n50 Wowood\n20 Rice\n30 Gold\n15 羊皮紙" << endl;
                return;
            }
            else
            {
                cout << "即將製作...石中劍\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone - 200;
                    Wood.Wowood = Wood.Wowood - 50;
                    Food.Rice = Food.Rice - 30;
                    mobdrop.paper = mobdrop.paper - 15;
                    cout << "製作成功" << endl;
                    sword = 2;
                    player.att=player.att+400;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "紅色斧頭")
    {
        if (sword < 2)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (sword != 2 && sword != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Stone.Sextuple_compressed_cobblestone < 100 || Wood.GOuOd < 100 || Mineral.Emerald < 100 || mobdrop.eye < 20)
            {
                cout << "請準備足夠材料\n100 Sextuple compress cobblestone\n100 GOuOd\n100 Emerald\n20 巨人之眼" << endl;
                return;
            }
            else
            {
                cout << "即將製作...紅色斧頭\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone - 100;
                    Wood.GOuOd = Wood.GOuOd - 100;
                    Mineral.Emerald = Mineral.Emerald - 100;
                    mobdrop.eye - mobdrop.eye - 20;
                    sword = 3;
                    player.att=player.att+2000;
                    cout << "製作成功" << endl;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "乞丐大劍")
    {
        if (sword < 3)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (sword != 3 && sword != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Wood.Just_wood < 1000 || Wood.Wowood < 100 || Wood.GOuOd < 10 || Wood.Gwood < 1 || mobdrop.wing < 20)
            {
                cout << "請準備足夠材料\n1000 Just wood\n100 Wowood\n10 GOuOd\n1 Gwood\n10 精靈翅膀" << endl;
                return;
            }
            else
            {
                cout << "即將製作...乞丐大劍\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Just_wood = Wood.Just_wood - 1000;
                    Wood.Wowood = Wood.Wowood - 100;
                    Wood.GOuOd = Wood.GOuOd - 10;
                    Wood.Gwood = Wood.Gwood - 1;
                    mobdrop.wing = mobdrop.wing - 20;
                    sword = 4;
                    cout << "製作成功" << endl;
                    player.att=player.att+10000;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "無敵戳戳")
    {
        if (sword < 4)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (sword != 4 &&sword != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Wood.Gwood < 5 || Stone.Sextuple_compressed_cobblestone < 50 || Mineral.Diamond < 5 || mobdrop.horn < 20)
            {
                cout << "請準備足夠材料\n5 Gwood\n50 Sextuple compressed cobblestone\n5 Diamond\n20 惡魔角" << endl;
                return;
            }
            else
            {
                cout << "即將製作...無敵戳戳\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Gwood = Wood.Gwood - 5;
                    Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone - 50;
                    Mineral.Diamond = Mineral.Diamond - 5;
                    mobdrop.horn = mobdrop.horn - 50;
                    cout << "製作成功" << endl;
                    player.att=player.att+30000;
                    sword = 5;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "EX咖哩棒")
    {
        if (sword < 5)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (sword == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (Wood.Gwood < 10 || Stone.Octuple_compressed_cobblestone < 10 || Food.GODLYFOOD < 10 || Mineral.Diamond < 10)
            {
                cout << "請準備足夠材料\n10 Gwood\n10 Octuple compressed cobblestone\n10 Godly food\n10 Diamond" << endl;
                return;
            }
            else
            {
                cout << "即將製作...EX咖哩棒\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Gwood = Wood.Gwood - 10;
                    Stone.Octuple_compressed_cobblestone = Stone.Octuple_compressed_cobblestone - 10;
                    Food.GODLYFOOD = Food.GODLYFOOD - 10;
                    Mineral.Diamond = Mineral.Diamond - 10;
                    sword = 100;
                    cout << "製作成功" << endl;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "白甲")
    {
        if (armor != 0 && armor != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經製作最高等級的裝備了" << endl;
            return;
        }
        else
        {
            if (Stone.Cobblestone < 35 || Food.Grass < 50 || mobdrop.turtle < 5)
            {
                cout << "請準備足夠材料\n35 Cobblestone\n100 Grass\n50 Iron\n5 龜殼" << endl;
                return;
            }
            else
            {
                cout << "即將製作...白甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Stone.Cobblestone = Stone.Cobblestone - 35;
                    Food.Grass = Food.Grass - 50;
                    mobdrop.turtle = mobdrop.turtle - 5;
                    armor = 1;
                    cout << "製作成功" << endl;
                    player.def=player.def+30;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "藍甲")
    {
        if (armor < 1)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (armor != 1 && armor != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經製作最高等級的裝備了" << endl;
            return;
        }
        else
        {
            if (Wood.Just_wood < 200 || Stone.Double_compressed_cobblestone < 100 || Food.Steak < 50 || mobdrop.paper < 15)
            {
                cout << "請準備足夠材料\n200 Just wood\n100Double compressed cobblestone\n30 Steak\n50 Gold\n15 羊皮紙" << endl;
                return;
            }
            else
            {
                cout << "即將製作...藍甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Just_wood = Wood.Just_wood - 200;
                    Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone - 100;
                    Food.Steak = Food.Steak - 50;
                    mobdrop.paper = mobdrop.paper - 15;
                    armor = 2;
                    cout << "製作成功" << endl;
                    player.def=player.def+400;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "紫甲")
    {
        if (armor < 2)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (armor != 2 && armor != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經製作最高等級的裝備了" << endl;
            return;
        }
        else
        {
            if (Wood.GOuOd < 100 || Stone.Sextuple_compressed_cobblestone < 100 || Mineral.Emerald < 100 || mobdrop.eye < 20)
            {
                cout << "請準備足夠的材料\n100 GOuOd\n100 Sextuple compressed cobblestone\n100 Emerald\n20 巨人之眼" << endl;
                return;
            }
            else
            {
                cout << "即將製作...紫甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.GOuOd = Wood.GOuOd - 100;
                    Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone - 100;
                    Mineral.Emerald = Mineral.Emerald - 100;
                    mobdrop.eye = mobdrop.eye - 20;
                    armor = 3;
                    cout << "製作成功" << endl;
                    player.def=player.def+2000;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "金甲")
    {
        if (armor < 3)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (armor != 3 && armor != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經製作最高等級的裝備了" << endl;
            return;
        }
        else
        {
            if (Stone.Cobblestone < 1000 || Stone.Double_compressed_cobblestone < 100 || Stone.Sextuple_compressed_cobblestone < 10 || Stone.Octuple_compressed_cobblestone < 1)
            {
                cout << "請準備足夠的材料\n1000 Cobblestone\n100 Double compresssed cobblestone\n10 Sextuple compressed cobblestone\n1 Octuple compressed cobblestone\n10 精靈翅膀" << endl;
                return;
            }
            else
            {
                cout << "即將製作...金甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Stone.Cobblestone = Stone.Cobblestone - 1000;
                    Stone.Double_compressed_cobblestone = Stone.Double_compressed_cobblestone - 100;
                    Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone - 10;
                    Stone.Octuple_compressed_cobblestone = Stone.Octuple_compressed_cobblestone - 1;
                    armor = 4;
                    cout << "製作成功" << endl;
                    player.def=player.def+10000;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "紅甲")
    {
        if (armor < 4)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (armor != 4 && armor != 100)
        {
            cout << "你已經不需要再製作這個裝備了" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經製作最高等級的裝備了" << endl;
            return;
        }
        else
        {
            if (Wood.Gwood < 5 || Stone.Sextuple_compressed_cobblestone < 20 || Food.GODLYFOOD < 10 || Mineral.Diamond < 1 || mobdrop.horn < 30)
            {
                cout << "請準備足夠的材料\n5 Gwood\n20 Sextuple compressed cobblestone\n10 Godly food\n1 Diamond\n30 惡魔角" << endl;
                return;
            }
            else
            {
                cout << "即將製作...紅甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    Wood.Gwood = Wood.Gwood - 5;
                    Stone.Sextuple_compressed_cobblestone = Stone.Sextuple_compressed_cobblestone - 20;
                    Food.GODLYFOOD = Food.GODLYFOOD - 10;
                    Mineral.Diamond = Mineral.Diamond - 1;
                    mobdrop.horn = mobdrop.horn - 30;
                    armor = 5;
                    player.def=player.def+30000;
                    cout << "製作成功" << endl;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
    else if (Craft == "彩虹甲")
    {
        if (armor < 5)
        {
            cout << "請先製作上一級裝備" << endl;
            return;
        }
        else if (armor == 100)
        {
            cout << "你已經做了最高等級的武器了" << endl;
            return;
        }
        else
        {
            if (mobdrop.eye < 100 || mobdrop.horn < 100 || mobdrop.paper < 100 || mobdrop.turtle < 100 || mobdrop.wing < 100)
            {
                cout << "請準備足夠的材料\n100 龜殼\n100 羊皮紙\n100 巨人之眼\n100 精靈翅膀\n100 惡魔角" << endl;
                return;
            }
            else
            {
                cout << "即將製作...彩虹甲\n是/否" << endl;
                getline(cin, confirm);
                if (confirm == "是")
                {
                    mobdrop.eye = mobdrop.eye - 100;
                    mobdrop.horn = mobdrop.horn - 100;
                    mobdrop.paper = mobdrop.paper - 100;
                    mobdrop.turtle = mobdrop.turtle - 100;
                    mobdrop.wing = mobdrop.wing - 100;
                    armor = 100;
                    cout << "製作成功" << endl;
                    return;
                }
                else if (confirm == "否")
                {
                    cout << "製作取消" << endl;
                    return;
                }
                else if (confirm != "是" || confirm != "否")
                {
                    cout << "uhh...idk what are you trying to do lol" << endl;
                    return;
                }
            }
        }
    }
}
void heal()
{
    if (potion >= 1)
    {
        if (player.health != player.healthmax)
        {
            player.health = player.healthmax;
            potion = potion - 1;
            cout << "(麵包超人你的頭好了)你血量回滿了" << endl;
        }
        else if (player.health == player.healthmax)
            cout << "你的血量本來就是滿的?(’?`*)?" << endl;
    }
    else if (potion == 0)
        cout << "你可要先有傷藥才能治療你自己lmao\n(shop 購買傷藥)" << endl;
}
void changekeyprice()
{
    if(areamax==2)
        keyprice=25000;
    else if(areamax==3)
        keyprice=50000;
    else if(areamax==4)
        keyprice=75000;
    else if(areamax==5)
        keyprice=200000;
}
void fight(int attack, int blood, string boss)
{
    string command;
    int chance,lost,dragon,round=0,rng;
    cout << "you found an "<<boss<< " ! What do think you can do to it?" << endl;
    cout << "hit 120% attack 100% chance(hit it with anything you find on the ground) \n"
                << "dodge 200% attack 50% chance(You are too scared and your mind keep telling you that dodge is the bast idea\n"
                << "attack 400% attack 40% chance(You decided to hit it as hard as possible)" << endl;
    while (blood >= 0 )
    {
        dragon = rand()%50;
        lost = attack+dragon-player.def;
        rng=rand()%100;
        if(lost<=0)
            lost=1;
        player.health=player.health-lost;
        if(player.health<=0)
            player.health=0;
        getline(cin, command);
        if(command == "hit" || command == "dodge" || command == "attack")
        {
            round=round+1;
            cout<<"round "<<round<<endl;
            cout << "hit 120% attack 100%chance(hit it with anything you find on the ground) \n"
                << "dodge 200%attack 50%chance(You are too scared and your mind keep telling you that dodge is the bast idea\n"
                << "attack 400%attack 40%chance(You decided to hit it as hard as possible)" << endl;
        }
        if (command == "hit")
        {
            cout<<"you hit the dragon"<<endl;
            blood = blood - player.att * 1.2;
            cout << "you dealt " << player.att * 1.2 << " damage to the teenytiny dragon" << endl;
        }
        else if (command == "dodge")
        {
            chance = rand() % 100;
            if(chance>50)
            {
                cout<<"you dodged"<<endl;
                blood = blood - player.att * 2;
                cout << "you dealt " << player.att * 2 << " damage to the "<<boss<<  endl;
            }
            else
                cout<<"you failed lmao"<<endl;
        }
        else if (command == "attack")
        {
            chance = rand() % 100;
            if(chance>60)
            {
                cout<<"you attacked"<<endl;
                blood = blood - player.att * 4;
                cout << "you dealt " << player.att * 4 << " damage to the "<<boss << endl;
            }
            else
                cout<<"you failed lmao"<<endl;
        }
        if(blood<=0)
        {
            cout<<boss<<" is dead \nyou have unlocked the next area"<<endl;
            areamax++;
            changekeyprice();
            return;
        }
        if(command == "hit" || command == "dodge" || command == "attack" ||rng<95)
        {
            cout<< "the "<<boss<<" still has "<<blood<<" hp"<<endl;
            cout<< "the "<<boss<<" hits you \nyou lost "<<lost<<" hp\n";
            cout<<"you still remain "<<player.health<<" hp"<<endl;
        }
        else if(command == "hit" || command == "dodge" || command == "attack" ||rng>=95)
        {
            cout<< "the "<<boss<<" still has "<<blood<<" hp"<<endl;
            cout<< "the "<<boss<<" suddenly realize how to deal more damage on you"<<lost<<" hp\n";
            cout<<"you still remain "<<player.health-lost<<" hp"<<endl;
        }
        if(player.health<=0)
        {
            cout<<"you dead, better be luck next time"<<endl;
            return;
        }
    }
}
void dungeon()
{
    string enter;
    if (key == 0)
    {
        cout << "You need to have a key before entering the dungeon" << endl;
        return;
    }
    else
    {
        cout << "Seriously? Are you sure you're going to do that\nyes no" << endl;
        getline(cin, enter);
        if (enter == "yes" || enter == "y")
        {
            dungeonkey="未擁有";
            cout << "ypu entered the dungeon" << endl;
            if (areamax == 1)
            {
                fight(40,1000,"teenytiny dragon");
            }
            else if (areamax == 2)
            {
                fight(400,10000,"notsoyoung dragon");
            }
            else if (areamax == 3)
            {
                fight(2000,50000,"kindamature dragon");
            }
            else if (areamax == 4)
            {
                fight(10000,200000,"experienced dragon");
            }
            else if (areamax == 5)
            {
                fight(50000,1000000,"ooolllddd dragon");
            }
        }
        else if (enter == "no")
        {
            cout << "Alright come back anytime then" << endl;
            return;
        }
        else
        {
            cout << "Umm... you know you have to answer my question right? I guess you are not ready" << endl;
            return;
        }
    }
}
void profile()
{
    cout<<"\n攻擊:"<<player.att<<"\n防禦:"<<player.def<<"\n血量:"<<player.health<<"/"
    <<player.healthmax<<"\n等級:"<<player.lvl<<"經驗"<<player.exp<<"/"<<player.expmax<<"\n目前你有 "
    <<player.money<<" 元"<<"\n目前區域:area "<<area<<"\n最高區域:area "<<areamax<<endl;
}
void hax()
{
    Wood.Just_wood=100000;
    Wood.Wowood=100000;
    Wood.GOuOd=100000;
    Wood.Gwood=100000;
    Stone.Cobblestone=100000;
    Stone.Double_compressed_cobblestone=100000;
    Stone.Sextuple_compressed_cobblestone=100000;
    Stone.Octuple_compressed_cobblestone=100000;
    Food.Grass=100000;
    Food.Rice=100000;
    Food.Steak=100000;
    Food.GODLYFOOD=100000;
    Mineral.Iron=100000;
    Mineral.Gold=100000;
    Mineral.Emerald=100000;
    Mineral.Diamond=100000;
    mobdrop.turtle=100000;
    mobdrop.paper=100000;
    mobdrop.eye=100000;
    mobdrop.wing=100000;
    mobdrop.horn=100000;
    player.money=100000000;
}
void shop()
{
    int moneysub;
    string num,check;
    cout<<"歡迎來到商店，這裡有許多超值的好東西喔，你可以購買到回血用的傷藥跟打地牢用的鑰匙"
    <<"\n並且以最划算的價格購買到你想要的東西，雖然我不是冒險家，但這聽起來很不錯對吧"<<endl;
    cout<<"\n1.傷藥:25元"<<"\n2.地牢鑰匙:"<<keyprice<<"元\n\n3.Lootbox:150元\n4.Lootbox(but better and also bigger):2000元"
    <<"\n5.Super lootbox:10000元\n(lootbox一次只能買一個，建議多打怪比較實在喔，若打怪打累了可以買買箱子看運氣喔)"<<endl;
    cout<<"\n請輸入你想購買的物品編號"<<endl;
    getline(cin,num);
    if(num=="1")
    {
        cout<<"請輸入你想購買的數量"<<endl;
        cin>>moneysub;
        if(moneysub==0)
        {
            cout<<"你至少也買個一瓶也好"<<endl;
        }
        else if(moneysub*25>player.money)
           cout<<"你沒有足夠的錢"<<endl;
        else if(moneysub*25<=player.money)
        {
            player.money=player.money-moneysub*25;
            potion=potion+moneysub;
            cout<<"購買成功"<<endl;
        }    
    }
    else if(num=="2")
    {
        if(player.money>=keyprice &&key==0)
        {
            cout<<"確認購買 是/否"<<endl;
            getline(cin,check);
            if(check =="是")
            {
                cout<<"購買成功"<<endl;
                key=1;
                player.money=player.money-keyprice;
                dungeonkey="擁有";
            }
            else if(check=="否")
                cout<<"購買取消"<<endl;
            else
                cout<<"?"<<endl;
            
        }
        else if(key==1)
            cout<<"你已經有鑰匙了"<<endl;
        else if(player.money<keyprice)
            cout<<"你的錢似乎不太夠呢"<<endl;
    }
    else if(num=="3")
    {
        if(player.money>=150)
        {
            openwood(1);
            openstone(1);
            openmobdrop(1);
            player.money=player.money-150;
        }
        else if(player.money<150)
            cout<<"你的錢似乎不太夠呢"<<endl;
    }
    else if(num=="4")
    {
        if(player.money>=2000)
        {
            openwood(2);
            openstone(2);
            openmobdrop(2);
            player.money=player.money-2000;
        }
        else if(player.money<2000)
            cout<<"你的錢似乎不太夠呢"<<endl;
    }
    else if(num=="5")
    {
        if(player.money>10000)
        {
            openwood(3);
            openstone(3);
            openmobdrop(3);
            player.money=player.money-10000;
        }
        else if(player.money<10000)
            cout<<"你的錢似乎不太夠呢"<<endl;
    }
}
void move()
{
    cout<<"請打出你想去的區域的編號"<<endl;
    string I;
    int j;
    j=areamax;
    cin>>I;
    int i;
    try
    {
        i=stoi(I);
    }
    catch(invalid_argument)
    {
        cout<<"you must tell me a number, not a word"<<endl;
        return;
    }
    
    if(j>=i &&i>0)
    {
        cout<<"你已前往area"<<i<<endl;
        area=i;
    }
    else if(j<i &&i<6)
    {
        cout<<"尚未解鎖該區域"<<endl;
    }
    else if(i>=6 ||i<=0)
    {
        cout<<"沒有該區域"<<endl;
    }  

}
void verge(string second)
{
    cout<<"你要合成多少個"<<endl;
    int number;
    cin>>number;
    if(number==0)
    {
        cout<<"你沒合成任何東西"<<endl;
        return;
    }
    if(second=="Wowood")
    {
        if(Wood.Just_wood<25*number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Wood.Just_wood=Wood.Just_wood-number*25;
            Wood.Wowood=Wood.Wowood+number;
        }   
    }
    else if(second=="GOuOd")
    {
        if(Wood.Wowood<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Wood.Wowood=Wood.Wowood-number*10;
            Wood.GOuOd=Wood.GOuOd+number;
        }
    }
    else if(second=="Gwood")
    {
        if(Wood.GOuOd<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Wood.GOuOd=Wood.GOuOd-number*10;
            Wood.Gwood=Wood.Gwood+number;
        }
    }
    else if(second=="Double_compressed_cobblestone")
    {
        if(Stone.Cobblestone<number*15)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Stone.Cobblestone=Stone.Cobblestone-number*15;
            Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+number;
        }
    }
    else if(second=="Sextuple_compressed_cobblestone")
    {
        if(Stone.Double_compressed_cobblestone<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone-number*10;
            Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone+number;
        }
    }
    else if(second=="Octuple_compressed_cobblestone")
    {
        if(Stone.Sextuple_compressed_cobblestone<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone-number*10;
            Stone.Octuple_compressed_cobblestone=Stone.Octuple_compressed_cobblestone+number;
        }
    }
    else if(second=="Gold")
    {
        if(Mineral.Iron<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Mineral.Iron=Mineral.Iron-number*10;
            Mineral.Gold=Mineral.Gold+number;
        }
    }
    else if(second=="Emerald")
    {
        if(Mineral.Gold<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Mineral.Gold=Mineral.Gold-number*10;
            Mineral.Emerald=Mineral.Emerald+number;
        }
    }
    else if(second=="Diamond")
    {
        if(Mineral.Emerald<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Mineral.Emerald=Mineral.Emerald-number*10;
            Mineral.Diamond=Mineral.Diamond+number;
        }
    }
    else if(second=="Rice")
    {
        if(Food.Grass<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Food.Grass=Food.Grass-number*10;
            Food.Rice=Food.Rice+number;
        }
    }
    else if(second=="Steak")
    {
        if(Food.Rice<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Food.Rice=Food.Rice-number*10;
            Food.Steak=Food.Steak+number;
        }
    }
    else if(second=="GODLYFOOD")
    {
        if(Food.Steak<number*10)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"合成成功"<<endl;
            Food.Steak=Food.Steak-number*10;
            Food.GODLYFOOD=Food.GODLYFOOD+number;
        }
    }
    else
    {
        cout<<"我不知道你在說甚麼"<<endl;
        return;
    }
}
void dismantle(string second)
{
    cout<<"你要分解多少個"<<endl;
    int number;
    cin>>number;
    if(number==0)
    {
        cout<<"甚麼都不分解? 你一定是在開玩笑吧"<<endl;
        return;
    }
    else if(second=="Wowood")
    {
        if(Wood.Wowood<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Wood.Just_wood=Wood.Just_wood+number*20;
            Wood.Wowood=Wood.Wowood-number;
        }
    }
    else if(second=="GOuOd")
    {
        if(Wood.GOuOd<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Wood.Wowood=Wood.Wowood+number*8;
            Wood.GOuOd=Wood.GOuOd-number;
        }
    }
    else if(second=="Gwood")
    {
        if(Wood.Gwood<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Wood.GOuOd=Wood.GOuOd+number*8;
            Wood.Gwood=Wood.Gwood-number;
        }
    }
    else if(second=="Double_compressed_cobblestone")
    {
        if(Stone.Double_compressed_cobblestone<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Stone.Cobblestone=Stone.Cobblestone+number*12;
            Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone-number;
        }
    }
    else if(second=="Sextuple_compressed_cobblestone")
    {
        if(Stone.Sextuple_compressed_cobblestone<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Stone.Double_compressed_cobblestone=Stone.Double_compressed_cobblestone+number*8;
            Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone-number;
        }
    }
    else if(second=="Octuple_compressed_cobblestone")
    {
        if(Stone.Octuple_compressed_cobblestone<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Stone.Sextuple_compressed_cobblestone=Stone.Sextuple_compressed_cobblestone+number*8;
            Stone.Octuple_compressed_cobblestone=Stone.Octuple_compressed_cobblestone-number;
        }
    }
    else if(second=="Gold")
    {
        if(Mineral.Gold<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Mineral.Iron=Mineral.Iron+number*8;
            Mineral.Gold=Mineral.Gold-number;
        }
    }
    else if(second=="Emerald")
    {
        if(Mineral.Emerald<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Mineral.Gold=Mineral.Gold+number*8;
            Mineral.Emerald=Mineral.Emerald-number;
        }
    }
    else if(second=="Diamond")
    {
        if(Mineral.Diamond<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Mineral.Emerald=Mineral.Emerald+number*8;
            Mineral.Diamond=Mineral.Diamond-number;
        }
    }
    else if(second=="Rice")
    {
        if(Food.Rice<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Food.Grass=Food.Grass+number*8;
            Food.Rice=Food.Rice-number;
        }
    }
    else if(second=="Steak")
    {
        if(Food.Steak<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Food.Rice=Food.Rice+number*8;
            Food.Steak=Food.Steak-number;
        }
    }
    else if(second=="GODLYFOOD")
    {
        if(Food.GODLYFOOD<number)
            cout<<"數量不足"<<endl;
        else
        {
            cout<<"分解成功"<<endl;
            Food.Steak=Food.Steak+number*8;
            Food.GODLYFOOD=Food.GODLYFOOD-number;
        }
    }
    else
    {
        cout<<"你要分解甚麼"<<endl;
        return;
    }
}
void forge()
{
    string first,second;
    cout<<"這裡你可以把初階物資合成成更高階的物資，也可以把高階的物品分解\n說出你想合成/拆除的物品吧!(拆除只能拿到原來物品的80%\n"<<endl;
    cout<<"合成:\nWowood=25 Just_wood   WOuOd=10 Wowood  Gwood=10 WOuOd\nDouble_compressed_cobblestone=15 Cobblestone\n"
    <<"Sextuple_compressed_cobblestone=10 Double_compressed_cobblestone\n"
    <<"Ocutple_compressed_cobblestone=10 Sextuple_compressed_cobblestone\nGold= 10 Iron    Emarald=10 Gold   Diamond=10 Emerald\n"
    <<"Rice=10 Grass   Steak=10 Rice   GODLYFOOD=10 Diamond\n"<<endl;
    cout<<"Ex1:依序輸入 合成 Wowood 3 -->合成3個Wowood\nEx2:依序輸入 拆除 Gold 5 -->拆除5個Gold\n首先你要合成還是拆除"<<endl;
    getline(cin,first);
    if(first=="合成")
    {
        cout<<"你要合成哪個物品呢"<<endl;
        getline(cin,second);
        verge(second);
    }
    else if(first=="拆除")
    {
        cout<<"你要拆除哪個物品呢"<<endl;
        getline(cin,second);
        dismantle(second);
    }
    else
    {
        cout<<"錯誤輸入"<<endl;
        return;
    }
}
int main()
{
    srand(time(NULL));
    string Y, action;
    cout<<"(我):我是誰我在哪裡"; delay;
    cout<<"\n(迷之聲):哈哈哈"; delay;
    cout<<"\n(我):???"; delay;
    cout<<"\n(迷之聲):歡迎來到 EZ ADVENTURE"; delay;
    cout<<"\n(迷之聲)在這裡你要收集各種資源"; delay;
    cout<<"和裝備"; delay;
    cout<<"\n(迷之聲)打死最終魔王"; delay;
    cout<<"\n"; delay;
    cout<<"\n準備好了嗎我們開始吧"; delay;
    cout<<"\n(輸入yes以繼續)";
    player.healthmax = 100,
    player.health = 100,
    player.att = 1,
    player.def = 1,
    player.lvl = 1,
    player.money = 200;
    player.exp=0;
    player.expmax=500;
    stats a1;
    a1.att = 15 + rand() % 15,
    a1.def = 15 + rand() % 15;
    stats a2;
    a2.att = 300 + rand() % 100,
    a2.def = 300 + rand() % 100;
    stats a3;
    a3.att = 1000 + rand() % 500,
    a3.def = 1000 + rand() % 500;
    stats a4;
    a4.att = 5000 + rand() % 5000,
    a4.def = 5000 + rand() % 5000;
    stats a5;
    a5.att = 25000 + rand() % 10000,
    a5.def = 25000 + rand() % 10000;
    mobdropmax.turtle=100;
    mobdropmax.paper=130;
    mobdropmax.eye=140;
    mobdropmax.wing=120;
    mobdropmax.horn=150;

    while(true)
    {
        getline(cin,Y);
        if(Y == "yes")
        {
            cout<<"正在生成世界..."<<"\n0%"; delay; delay;
            cout<<"\n25%"; delay;
            cout<<"\n50%"; delay;
            cout<<"\n75%"; delay;
            cout<<"\n100%"; delay;
            cout<<"\n恭喜你已經可以開始冒險了(輸入help以獲得幫助)"<<endl;
            break;
        }
        else
        {
            cout<<"huh idk what r u doing silly"; delay;
            cout<<"\nR U READY???"<<endl;
        }
    }
    while (true)
    {
        getline(cin, action);
        if (action == "hunt")
            hunt(a1, a2, a3, a4, a5); 
        else if (action == "help")
            help();
        else if (action == "chop")
            chop();
        else if (action == "pickaxe")
            pickaxe();
        else if (action == "farm")
            farm();
        else if (action == "mine")
            mine();
        else if (action == "inventory" || action == "inv")
            inv();
        else if (action == "heal")
            heal();
        else if (action == "craft")
            craft();
        else if (action == "dungeon" || action == "dung")
            dungeon();
        else if (action == "profile" || action == "p")
            profile();
        else if(action == "hax")
            hax();
        else if(action=="shop")
            shop();
        else if(action =="move")
            move();
        else if(action== "forge")
            forge();
    }

    return 0;
}
