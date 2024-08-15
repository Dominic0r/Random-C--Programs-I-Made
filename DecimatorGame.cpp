#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>

using namespace std;

// this was a small coding side-project I did in C++ all the way back in 2021

int point = 1000;
int level = point/1000;
int hp = 50;
int bullets = 25;
int money = 50;
int heat = 0;
int direction = 0;
int result;
int days =0;
int dmg = 0;//damage modifier
string sname;

bool israining = false;
int tme = 1;

bool ambush();
bool battle();
bool arrest();

string streetname()
{
    srand(time(NULL));
    game:
        string vcapital[5] = {"A","E","I","O","U"};
        string ccapital[21] = {"B","C","D","F","G","H","J","K","L","M","N","P","Q","R","S","T","V","W","X","Y","Z"};
        sname=ccapital[rand()%21]+vcapital[rand()%5]+ccapital[rand()%21]+ccapital[rand()%21]+vcapital[rand()%5]+ccapital[rand()%21]+" AREA";
        return sname;
        goto game;
}

void game()
{
    srand(time(NULL));
    int dec;
    int gain;
    game:
        if (hp<= 0)
        {
            cout << "YOU LOOSE" << endl;
        hp = 50;
        money = 25;
        heat = 0;
        sleep(2);
        }
        if(tme > 12)
        {
            tme = 1;
            days +=1;
        }
        if (heat < 0)
        {
            heat = 0;
        }
        level = point/1000;
        system("clear");
        if(heat >= 20)
        {
            arrest();
        }
        switch(rand()%5)
        {
        case 1:
            cout << "YOU WALK THROUGH AN ALLEYWAY IN THE "<< streetname() << endl;
            break;
        case 2:
            cout << "YOU PASS BY AN EMPTY STREET IN THE "<< streetname() << endl;
            break;
        case 3:
            cout << "YOU WALK UNDER AN OVERPASS IN THE "<< streetname() << endl;
            break;
        case 4:
            cout << "YOU WALK PAST A BUS STOP IN THE "<< streetname() << endl;
            break;
        default:
            cout << "YOU WALK PAST A NEON LIT STREET IN THE "<< streetname() << endl;
            break;
        }
        switch(rand()%5)
        {
        case 1:
        case 2:
            if(israining == true)
            {
                cout << "IT STOPS RAINING" << endl;
                israining = false;
                break;
            }
            cout << "IT STARTS RAININNG" << endl;
            israining = true;
            break;

        }
        buy:
    cout << "<<STATS>>" << endl;
    cout << "LEVEL " << level << endl;
    cout << point << " POINTS" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "DAMAGE MODIFIER>> " << dmg << "%" << endl;
        cout << "MONEY>> " << money << endl;
        cout << "HEAT>> " << heat << endl;
        cout << "CURRENT AREA>> " << sname << endl;
        cout << "DAYS PAST>> " << days << endl;
        switch(tme)
        {
        case 1:
        case 2:
        case 3:
            cout << "CURRENT TIME OF DAY>> MORNING" << endl;
            break;
        case 4:
        case 5:
        case 6:
            cout << "CURRENT TIME OF DAY>> MID DAY" << endl;
            break;
        case 7:
        case 8:
        case 9:
            cout << "CURRENT TIME OF DAY>> AFTERNOON" << endl;
            break;
        case 10:
        case 11:
        case 12:
             cout << "CURRENT TIME OF DAY>> NIGHT" << endl;
             break;
        }
        cout << "---------------------" << endl;
        cout << "OPTIONS" << endl;
        cout << "1>> BUY MEDIPAK FOR 10 MONEY" << endl;
        cout << "2>> BUY 10 BULLETS FOR 20 MONEY" << endl;
        cout << "3>> SELL 5 BULLETS FOR 10 MONEY" << endl;
        cout << "4>> STAY HERE" << endl;
        cout << "5>> INCREASE DAMAGE MODIFIER BY 1% FOR " << 100*level<< " MONEY" << endl;
        cout << "6>> CONTINUE WALKING" << endl;
        cin >> dec;
        switch(dec)
        {
        case 1:
                if(money < 10)
                {
                    cout << "YOU DO NOT HAVE ENOUGH MONEY" << endl;
                    system("clear");
                    goto buy;
                }
                money -= 10;
                hp += 20*level;
                cout << "YOU BOUGHT A MEDIPAK" << endl;
                system("clear");
                goto buy;
                break;
        case 2:
            if(money < 20)
                {
                    cout << "YOU DO NOT HAVE ENOUGH MONEY" << endl;
                    system("clear");
                    goto buy;
                }
                money -= 20;
                bullets += 10;
                system("clear");
                goto buy;
                break;
        case 3:
            if(bullets < 5)
            {
                cout << "YOU DO NOT HAVE ENOUGH BULLETS TO SELL" << endl;
                system("clear");
                goto buy;
            }
            bullets-= 5;
            money += 10;
            cout << "YOU SOLD 5 BULLETS" << endl;
            system("clear");
            goto buy;
            break;
        case 4:
            cout << "YOU DECIDE TO WAIT HERE" << endl;
            switch(rand()%20)
            {
            case 1:
            case 2:
            case 3:
                ambush();
                break;
            default:
                system("clear");
                tme += 1;
                goto buy;
                break;
            }
            break;
            case 5:
                if(money < 100*level)
                {
                    cout << "YOU DON'T HAVE ENOUGH MONEY" << endl;
                    goto buy;
                }
                money -= 100*level;
                dmg += 1;
                goto buy;
        }
        switch(rand()%24)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            case 9:
            cout << "YOU CONTINUE WALKING" << endl;
            break;
        case 10:
        case 11:
            cout << "YOU SEE A GANGSTER. ATTACK THEM?" << endl;
            cout << "8>> YES; 9>> NO" << endl;
            cin >> dec;
            switch(dec)
            {
            case 8:
                battle();
                break;
            case 9:
                default:
                cout << "YOU DECIDE NOT TO ATTACK THEM" << endl;
                heat -= 1*level;
                break;
            }
            break;
            case 12:
            case 13:
            case 14:
                cout << "YOU FOUND A WALLET" << endl;
                cout << "TAKE IT? (1- YES , 2-NO)" << endl;
                cin >> dec;
                switch (dec)
                {
                case 1:
                     gain = (rand()% 100)*level;
                money += gain;
                heat += 1*level;
                cout << "YOU GOT " << gain << " MONEY!" << endl;
                sleep(2);
                break;
                case 2:
                    cout << "YOU DECIDE TO LEAVE IT" << endl;
                    break;
                }
                break;
            case 15:
            case 16:
                cout << "YOU FOUND A MAG OF BULLETS" << endl;
                gain = (rand()%30)*level;
                bullets += gain;
                cout << "YOU GOT " << gain << " BULLETS!" << endl;
                sleep(2);
                break;
            case 17:
            case 18:
            case 19:
                case 20:
                cout << "YOU FOUND A MEDIPAK!" << endl;
                gain = (rand()%50)*level;
                hp += gain;
                cout << "YOU GAINED " << gain << " HP!" << endl;
                sleep(2);
            break;
                case 21:
                    cout << "YOU GOT HIT BY A STRAY BULLET" << endl;
                    gain = (rand()% 50)*level;
                    result = hp - gain;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
               cout << "<<STATS>>" << endl;
    cout << "LEVEL " << level << endl;
    cout << point << " POINTS" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "HEAT>> " << heat << endl;
        cout << "---------------------" << endl;
        cout << "OPTIONS" << endl;
        cout << "1>> BUY MEDIPAK FOR 10 MONEY" << endl;
        cout << "2>> BUY 10 BULLETS FOR 20 MONEY" << endl;
        cout << "3>> SELL 5 BULLETS FOR 10 MONEY" << endl;
        cout << "4>> CONTINUE WALKING" << endl;
                sleep(0.8);
            }
            system("clear");
            cout << "YOU GOT HIT BY A STRAY BULLET"<<endl;
                    cout << "YOU LOST " << gain << " HP!" << endl;
                    sleep(2);
                    break;
            default:
                ambush();
                break;
        }
                switch(rand()%4)
                {
                case 1:
                    if(direction == 2)
                    {
                        cout << "YOU DECIDED TO HEAD SOUTH" << endl;
                        direction=2;
                        break;
                    }
                    cout << "YOU DECIDED TO HEAD NORTH" << endl;
                    direction=1;
                    break;
                case 2:
                    if(direction == 1)
                    {
                        cout << "YOU DECIDED TO HEAD NORTH" << endl;
                        direction=1;
                        break;
                    }
                    cout << "YOU DECIDED TO HEAD SOUTH" << endl;
                    direction=2;
                    break;
                case 3:
                    if(direction == 4)
                    {
                        cout << "YOU DECIDED TO HEAD WEST" << endl;
                        direction=4;
                        break;
                    }
                    cout << "YOU DECIDED TO HEAD EAST" << endl;
                    direction = 3;
                    break;
                default:
                    if(direction == 3)
                    {
                        cout << "YOU DECIDED TO HEAD EAST" << endl;
                        direction=3;
                        break;
                    }
                    cout << "YOU DECIDED TO HEAD WEST" << endl;
                    direction=4;
                    break;
                }
                sleep(2);
                tme += 1;
        heat -= 1;
        money += 1*level;
    goto game;
}

bool arrest()
{
        int damage;
    srand(time(NULL));
    level = point/1000;
    int enemy= 50 * level;
    int result = enemy - damage;
    int dec;
    cout << "A POLICE OFFICER AMBUSHES YOU" << endl;
    game:
        if(enemy <= 0)
        {
            cout << "YOU WON" << endl;
            point += 500/level;
            money += (rand()%501)*level;
            heat -= heat;
            sleep(2);
            return true;
        }
        switch(rand()%3)
        {
        case 1:
            cout << "THE POLICE OFFICER HIT YOU WITH THEIR BATTON" << endl;
            damage = (rand()% 11)*level;
            result = hp - damage;

             while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "THE POLICE OFFICER HIT YOU WITH THEIR BATTON" << endl;
            cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
            sleep(3);
            break;
        case 2:
            cout << "THE POLICE OFFICER SHOT YOU" << endl;
            damage = (rand()%36)*level;
            result = hp - damage;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;
                sleep(0.8);
            }
            cout << "THE POLICE OFFICER SHOT YOU" << endl;
             cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
             sleep(3);
             break;
        default:
            cout << "THE POLICE OFFICER HEALED " << 10*level << " POINTS" << endl;
            enemy += 10*level;
            break;
        }
             if(hp <= 0)
    {
        cout << "YOU LOOSE" << endl;
        hp = 50*level;
        money = 25*level;
        heat = 0;
        sleep(2);
        return false;
    }
        damage = 0;
        cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;
        cin >> dec;
        switch(dec)
        {
        case 1:
            cout << "YOU ATTACKED THE POLICE OFFICER WITH A KNIFE" << endl;
            damage = (rand()% 11)*level;
            damage += damage *dmg/100;
            result = enemy - damage;
            heat += 1*level;
                       while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 2:
            if(bullets < 5)
            {
                cout << "YOU DO NOT HAVE ENOUGH BULLETS!" << endl;
                goto game;
            }
            bullets -= 5;
            cout << "YOU SHOT THE POLICE OFFICER" << endl;
            damage = (rand()% 26) * level;
            damage += damage *dmg/100;
            result = enemy - damage;
            heat += 2*level;
            while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }

            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 3:
            if (money < 10)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 10;
            hp += 20*level;
            cout << "YOU HEALED YOURSELF" << endl;
            break;
        case 4:
            if (money < 20)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 20;
            bullets += 10;
            cout << "YOU HAVE BOUGHT 10 BULLETS" << endl;
            break;
        default:
            cout << "PLEASE CHOOSE BETWEEN 1 AND 2 ONLY!" << endl;
            goto game;
            break;
        }
        sleep(3);
        tme +=1;
        system("clear");
        goto game;
}

bool ambush()
{
    int damage;
    srand(time(NULL));
    level = point/1000;
    int enemy= 30 * level;
    int result = enemy - damage;
    int dec;
    cout << "YOU GOT AMBUSHED" << endl;
    game:
        if(enemy <= 0)
        {
            cout << "YOU WON" << endl;
            point += 100/level;
            money += (rand()%51)*level;
            sleep(2);
            return true;
        }
        switch(rand()%3)
        {
        case 1:
            cout << "THE GANGSTER STABBED YOU" << endl;
            damage = (rand()% 11)*level;
            result = hp - damage;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
             cout << "THE GANGSTER STABBED YOU" << endl;
            cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
            sleep(3);
            break;
        case 2:
            cout << "THE GANGSTER SHOT YOU" << endl;
            damage = (rand()%26)*level;
            result = hp - damage;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "THE GANGSTER SHOT YOU" << endl;
             cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
             sleep(3);
             break;
        default:
            cout << "THE GANGSTER HEALED " << 10*level << " POINTS" << endl;
            enemy += 10*level;
            break;
        }
             if(hp <= 0)
    {
        cout << "YOU LOOSE" << endl;
        hp = 50;
        money = 25;
        heat = 0;
        sleep(2);
        return false;
    }
        damage = 0;
        cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT(deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;
        cin >> dec;
        switch(dec)
        {
        case 1:
            cout << "YOU STABBED THE GANGSTER" << endl;
            damage = (rand()% 11)*level;
            damage += damage *dmg/100;
            result = enemy - damage;
                       while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 2:
            if(bullets < 5)
            {
                cout << "YOU DO NOT HAVE ENOUGH BULLETS!" << endl;
                goto game;
            }
            bullets -= 5;
            cout << "YOU SHOT THE GANGSTER" << endl;
            damage = (rand()% 26) * level;
            damage += damage *dmg/100;
            result = enemy - damage;
                      while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            heat += 1*level;
            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 3:
            if (money < 10)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 10;
            hp += 20*level;
            cout << "YOU HEALED YOURSELF" << endl;
            break;
        case 4:
            if (money < 20)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 20;
            bullets += 10;
            cout << "YOU HAVE BOUGHT 10 BULLETS" << endl;
            break;
        default:
            cout << "PLEASE CHOOSE BETWEEN 1 AND 2 ONLY!" << endl;
            goto game;
            break;
        }
        sleep(3);
        tme +=1;
        system("clear");
        goto game;
}

bool battle()
{
    system("clear");
    cout << "YOU ATTACKED THE GANGSTER" << endl;
    srand(time(NULL));
    int damage =0;
    level = point/1000;
    int enemy= 30 * level;
    int result = enemy - damage;
    int dec;
    game:
        if(hp <= 0)
    {
        cout << "YOU LOOSE" << endl;
        hp = 50;
        money = 25;
        heat = 0;
        sleep(2);
        return false;
    }
        cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT(deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;
        cin >> dec;
        switch(dec)
        {
        case 1:
            cout << "YOU STABBED THE GANGSTER" << endl;
            damage = (rand()% 11)*level;
            damage += damage *dmg/100;
            result = enemy - damage;
                      while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 2:
            if(bullets < 5)
            {
                cout << "YOU DO NOT HAVE ENOUGH BULLETS!" << endl;
                goto game;
            }
            bullets -= 5;
            cout << "YOU SHOT THE GANGSTER" << endl;
            damage = (rand()% 26) * level;
            damage += damage *dmg/100;
            result = enemy - damage;
                       while(enemy >= result)
            {
                system("clear");
                enemy -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            heat += 1*level;
            cout << "YOU DEALT " << damage+1 << " DAMAGE!" << endl;
            sleep(3);
            break;
        case 3:
            if (money < 10)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 10;
            hp += 20*level;
            cout << "YOU HEALED YOURSELF" << endl;
            break;
        case 4:
            if (money < 20)
            {
                cout << "YOU DO NOT HAVE ENOUGH MONEY!" << endl;
                goto game;
            }
            money -= 20;
            bullets += 10;
            cout << "YOU HAVE BOUGHT 10 BULLETS" << endl;
            break;
        default:
            cout << "PLEASE CHOOSE BETWEEN 1 AND 2 ONLY!" << endl;
            goto game;
            break;
        }
        if(enemy <= 0)
        {
            cout << "YOU WON" << endl;
            point += 200/level;
            money += (rand()%101)*level;
            heat += 5;
            sleep(2);
            return true;
        }
        switch(rand()%3)
        {
        case 1:
            cout << "THE GANGSTER STABBED YOU" << endl;
            damage = (rand()% 11)*level;
            result = hp - damage;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "THE GANGSTER STABBED YOU" << endl;
            cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
            sleep(3);
            break;
        case 2:
            cout << "THE GANGSTER SHOT YOU" << endl;
            damage = (rand()%26)*level;
            result = hp - damage;
            while(hp >= result)
            {
                system("clear");
                hp -=1;
                cout << "<<STATS>>" << endl;
        cout << "YOUR HP>> " << hp << endl;
        cout << "YOUR BULLETS>> " << bullets << endl;
        cout << "MONEY>> " << money << endl;
        cout << "---------------------" << endl;
        cout << "ENEMY HP>> " << enemy<< endl;
        cout << "---------------------" << endl;
        cout << endl;
        cout << "<<OPTIONS>>" << endl;
        cout << "1>> STAB(deals maximum of 10  x level)" << endl;
        cout << "2>> SHOOT (deals maximum of 25 x level but costs 5 bullets)" << endl;
        cout << "3>> HEALS 20 X LEVEL(COSTS 10 MONEY TO HEAL)"<< endl;
        cout << "4>> BUY 10 BULLETS(COSTS 20 MONEY TO BUY BULLETS)" << endl;

                sleep(0.8);
            }
            cout << "THE GANGSTER SHOT YOU" << endl;
             cout << "YOU SUSTAINED " << damage+1 << " HITPOINTS" << endl;
             sleep(3);
             break;
        default:
            cout << "THE GANGSTER HEALED "<< 10*level << " POINTS" << endl;
            enemy += 10*level;
            break;
        }
        sleep(3);
        tme +=1;
        system("clear");
        goto game;
}

int main()
{
    int dec;
    game:
        cout << "<<<<<DECIMATOR 1.8.9>>>>>" << endl;
        cout << "PRESS ANY BUTTON THEN ENTER TO PLAY" << endl;
        cin >> dec;
        game();
        goto game;
}
