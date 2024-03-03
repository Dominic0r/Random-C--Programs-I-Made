#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

string names[5][10]={
    {"Communist Party","National Democratic Party","Labor, Liberty, Action","Socialist Labor Party","Labor Reform Party","Socialist United Front - L","Democratic Progressive Party - L","National Republican Party - C","National Congress of Unions","Worker's Party"},
    {"Socialist Party","National Progressive Party","Greens","Social Democratic Party","Labor Party","Socialist United Front - M","Democratic Progressive Party - M","Socialists and Democrats - L","National Liberal Movement - L","National Republican Party - P"},
    {"Liberal Party","Democratic Party","Progressives","Center Party","Unity Party","Democratic Progressive Party - R","Socialists and Democrats - M","National Liberal Movement - M","Liberal Democratic Party - M","National Republican Party - L"},
    {"Conservative Party","Liberal Democrats","Democratic Action Party","Reform Party","National Conservative Movement","National Liberal Movement - R","Liberal Democratic Party - R","Tradition and Democracy - M","National Republican Party - R","Democratic Interests Alliance"},
    {"Nationalist Party","Democratic Alliance","Our Land","National Unity Front","Social Reform Movement","Tradition and Democracy - R","National Republican Party - N","Patriotic Renewal Front","New Nationalism","Conservative Labor Movement"}
};

string ideologies[5][5] = {
    {"Communism","Marxism","Populism","Market Socialism","National Communism"},
    {"Socialism","Progressive Democracy","Populism","Religious Socialism","Social Liberalism"},
    {"Liberalism","Corporatism","Populism","Religious Liberalism","Big Tent"},
    {"Conservatism","Market Liberalism","Populism","Dynastic Democracy","Libertarianism"},
    {"Nationalism","Traditionalism","National Socialism","National Conservatism","Corporatism"},
};
int year = 1948;

string unput = "";

bool midterm = false;

int population = 1500000;

int par_support[10] = {0,0,0,0,0,0,0,0,0,0};
int par_support_percent[10] = {0,0,0,0,0,0,0,0,0,0};

int par_votes[10] ={0,0,0,0,0,0,0,0,0,0};
int par_votes_percent[10] = {0,0,0,0,0,0,0,0,0,0};

int par_seats[10] = {0,0,0,0,0,0,0,0,0,0};
int par_seats_percent[10] = {0,0,0,0,0,0,0,0,0,0};

int par_ideology[10] ={0,0,0,0,0,0,0,0,0,0};
int par_subideology[10] = {0,0,0,0,0,0,0,0,0,0};

int par_name[10] = {0,0,0,0,0,0,0,0,0,0};

int par_personality[10] = {0,0,0,0,0,0,0,0,0,0};

int presnum =11;
int pmnum =11;

string president = "";
string primem = "";

string par_president[10] = {"","","","","","","","","",""};
int yelect =1948;
int prevpres =11;
string par_primem[10] = {"","","","","","","","","",""};

int district = population/25000;

int prime[2];

string govcoalition[10];
int govmembers =0;
int govseats =0;
int gmemnum[10];

string oppocoalition[10];
int oppomembers =0;
int opposeats =0;
int oppomemnum[10];

bool govinpower = false;

int oppoleader = 11;

int termlength =0;

int foundingyear[10] = {1948,1948,1948,1948,1948,1948,1948,1948,1948,1948};

string namegen()
{
    string consonant[20] = {"B","B","K","D","G","H","H","L","L","M","N","P","R","S","S","T","T","W","W","Y"};
        string vowel[13] = {"A","A","A","A","A","E","I","I","I","O","O","O","U"};
        string aftercon[11] = {"NG","NG","M","M","N","K","K","P","P","T","Y"};
     
        string bloc1,bloc2, bloc3;
        string fname, lname;
        bloc1 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc1 += aftercon[rand()%11];
            }
            bloc2 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc2 += aftercon[rand()%11];
            }
            bloc3 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc3 += aftercon[rand()%11];
            }
     
            fname = bloc1 + bloc2;
            if(rand()%10 < 5)
            {
                fname += bloc3;
            }
     
     
     
            bloc1 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc1 += aftercon[rand()%11];
            }
            bloc2 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc2 += aftercon[rand()%11];
            }
            bloc3 = consonant[rand()%20] + vowel[rand()%13];
            if(rand()%10 < 3)
            {
                bloc3 += aftercon[rand()%11];
            }
     
            lname = bloc1 + bloc2;
            if(rand()%10 < 5)
            {
                lname += bloc3;
            }
    return fname+ " " + lname;
}

void setup()
{
    population += (rand()%1000000)- (rand()%1000000);
    for(int i=0; i!=10; i++)
    {
        par_ideology[i] = rand()%5;
        par_subideology[i] = rand()%5;
        par_name[i] = rand()%10;
        par_president[i] = namegen();
        par_primem[i] = namegen();
        par_personality[i] = rand()%100;
        
        par_support[i] = (rand()%100)+25;
        if(rand()%100 < par_personality[i])
        {
            par_support[i] *= 2;
        }
    }
}

void update()
{
    year+=5;
    midterm = !midterm;
    int pad = population*0.1;
    population += rand()%pad+1;
    district = population/25000;
    for(int i =0; i!=10;i++)
    {
        if((year - foundingyear[i]) - ((par_seats[i]*100)/(district+1)) > rand()%100 && i != presnum && i != pmnum)
        {
            par_ideology[i] = rand()%5;
            par_subideology[i] = rand()%5;
            par_name[i] = rand()%10;
            par_president[i] = namegen();
            par_primem[i] = namegen();
            par_personality[i] = rand()%100;
            par_support[i] = (rand()%100)+25;
            foundingyear[i] = year;
        }
        
        if(rand()%50 > par_votes_percent[i])
        {
            par_president[i] = namegen();
            par_primem[i] = namegen();
            par_personality[i] = rand()%100;
        }
        
        par_support[i] = (rand()%((100+ (par_support[i]/10))+ par_votes_percent[i])+1)- (year - yelect);
        par_support[i] += (par_seats[i]*100)/district;
        if(i == presnum || i == pmnum || i == oppoleader)
        {
            par_support[i] += 50;
        }
        par_support_percent[i] =0;
        par_votes_percent[i] =0;
        par_votes[i] =0;
        par_seats[i] =0;
    }
    govmembers =0;
    oppomembers =0;
    govseats =0;
    opposeats =0;
    
    
}

void polls()
{
    int supporttotal =0;
    //cout << "A";
    for(int i=0; i!=10;i++)
    {
        supporttotal += par_support[i];
    }
    //cout <<"B";
    for(int i=0; i!=10;i++)
    {
        par_support_percent[i] = (par_support[i]*100)/(supporttotal+1);
        
    }
    //cout << "A";
    int tickremove =0;
    int rempop = population;
    int chance = rand()%100;
    int stack = par_support_percent[0];
    int prevstack =0;
    bool hasvoted = false;
    int totvotes =0;
    //cout << "N";
    string debug_input = "";
    
    while(rempop >population*0.15)
    {
        if(midterm)
        {
            cout << year << " Parliamentary Election" << endl;
        } else{
            cout << year << " General Election" << endl;
        }
        cout << endl;
        cout << "President: " << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << ideologies[par_ideology[presnum]][par_subideology[presnum]] << ")" << endl;
        cout << "Prime Minister: " << primem << " (" << names[par_ideology[pmnum]][par_name[pmnum]]<< " | " << ideologies[par_ideology[pmnum]][par_subideology[pmnum]] << ")" << endl;
        cout << endl;
        chance = rand()%100;
        int rpp = rempop*0.1;
        tickremove = rand()%(rpp+1);
        while(!hasvoted)
        {
            for(int i=0; i!=10; i++)
            {
                /*cout << "prevstack: " << prevstack << endl;
                cout << "stack: " << stack << endl;
                cout << "chance: " << chance << endl;
                cin>> debug_input;*/
                if(chance > prevstack && chance < stack)
                {
                    hasvoted = true;
                    if(i == presnum || i == pmnum || i == oppoleader)
                    {
                        tickremove *= 1.5;
                    }
                    par_votes[i]+=tickremove;
                    break;
                } else{
                    prevstack = stack;
                    if(i <9)
                    {
                        stack += par_support_percent[i+1];
                    }
                }
                
            }
        }
        //cout << "G";
        hasvoted = false;
        rempop-= tickremove;
        totvotes =0;
        
        for(int i=0; i!=10;i++)
        {
            totvotes += par_votes[i];
        }
        //cout<<"-";
        for(int i=0; i!=10;i++)
        {
            par_votes_percent[i] = (par_votes[i]*100)/(totvotes+1);
        }
        //cout << "Z";
        for(int i=0; i!=10; i++)
        {
            //cout << i << endl;
            cout << par_president[i] << " - " <<names[par_ideology[i]][par_name[i]] << " (" << ideologies[par_ideology[i]][par_subideology[i]] << ")" << endl;
            //cout << par_support_percent[i] << endl;
            cout << par_votes[i] << " votes (" << par_votes_percent[i] << "%)" << endl;
            for(int b=0; b!= par_votes_percent[i]/2; b++)
            {
                cout << "|";
            }
            cout << endl;
            cout << endl;
        }
        //cout << "A";
        cout << "Remaining Voters: " << rempop << endl;
        cout << "Total votes counted: " << totvotes << " / " << population << endl;
        sleep(1);
        system("clear");
    }
    //cout << "P";
    
}

void preselec()
{
    int winnum =0, winvotes =0;
    for(int i=0; i!=10; i++)
    {
        if(par_votes[i] > winvotes)
        {
            winnum = i;
            winvotes = par_votes[i];
        }
    }
    if(winnum != presnum)
    {
        prevpres = presnum;
        yelect = year;
    }
    president = par_president[winnum];
    presnum = winnum;
}

void seatdistrib()
{
    int tickremove =0;
    int remdists = district;
    int points[10]= {0,0,0,0,0,0,0,0,0,0};
    int votedivide[10];
    for(int i=0;i!=10;i++){votedivide[i]=par_votes[i];}
    int winnum =0;
    int winvotes =0;
    while(remdists >0)
    {
        for(int i=0; i!= 10;i++)
        {
            if(votedivide[i] > winvotes)
            {
                winvotes = votedivide[i];
                winnum = i;
            }
        }
        
        tickremove = (((rand()%(remdists)*0.10)*100)/(remdists+1))+1;
        tickremove += par_votes_percent[winnum]/20;
        if(remdists-tickremove <0)
        {
            tickremove = remdists;
        }
        /*cout << tickremove << endl;
        cout << remdists << endl;
        string debug_input = "";
        cin>> debug_input;*/
        remdists-=tickremove;
        par_seats[winnum]+=tickremove;
        votedivide[winnum] = par_votes[winnum]/ (points[winnum]+1);
        points[winnum]++;
        winvotes=0;
        winnum=0;
    }
}

void coalitionform()
{
    int gov =11, winseats =0, opponum =11;
    
    gov = presnum;
    winseats =0;
    for(int i=0;i!=10;i++)
    {
        if(par_seats[i] > winseats && i != gov && i != presnum && abs(par_ideology[i]-par_ideology[gov]) >0)
        {
            winseats = par_seats[i];
            opponum = i;
        }
    }
    gmemnum[govmembers] = gov;
    govcoalition[govmembers] = names[par_ideology[gov]][par_name[gov]];
    govmembers++;
    govseats += par_seats[gov];
    
        oppomemnum[oppomembers] = opponum;
        oppocoalition[oppomembers] = names[par_ideology[opponum]][par_name[opponum]];
        oppomembers++;
        opposeats += par_seats[opponum];
        oppoleader = opponum;
    
    
    
    int govpoints = 0, oppopoints =0;
    for(int i=0; i!=10; i++)
    {
        if(i != gov && i != opponum && i != presnum)
        {
            govpoints += 20* abs(par_ideology[gov] - par_ideology[i]);
            oppopoints += 20* abs(par_ideology[opponum] - par_ideology[i]);
            
            govpoints += abs(par_personality[gov] - par_personality[i]);
            oppopoints += abs(par_personality[opponum] - par_personality[i]);
            
            if(par_ideology[gov] == par_ideology[i])
            {
                govpoints -= 10;
            } else if(par_ideology[opponum] == par_ideology[i])
            {
                oppopoints -= 10;
            }
            if(par_seats[presnum]> district/2)
            {
                govpoints += 50;
            }
            if(govpoints <= oppopoints)
            {
                gmemnum[govmembers] = i;
                govcoalition[govmembers] = names[par_ideology[i]][par_name[i]];
                govmembers++;
                govseats += par_seats[i];
            }else if(oppopoints < govpoints)
            {
                oppomemnum[oppomembers] = i;
                oppocoalition[oppomembers] = names[par_ideology[i]][par_name[i]];
                oppomembers++;
                opposeats += par_seats[i];
            }

        }
        govpoints =0;
        oppopoints =0;
        

    }
    
    if(govseats >= opposeats)
    {
        primem = par_primem[gov];
        govinpower = true;
        pmnum = gov;
    } else
    {
        primem = par_primem[opponum];
        govinpower = false;
        pmnum = opponum;
    }
    
}



int main()
{
    srand((unsigned)time(NULL));
    //cout << "A";
    setup();
    game:
    //cout << "L";
    polls();
    //cout << "F";
    if(!midterm)
    {
        preselec();
    }
    //cout << "R";
    seatdistrib();
    //cout << "E";
    coalitionform();
    
    /*for(int i=0; i!=10; i++)
    {
        cout <<names[par_ideology[i]][par_name[i]] << endl;
        cout << par_president[i] << "\n" << par_primem[i] << endl;
        cout << ideologies[par_ideology[i]][par_subideology[i]] << endl;
        cout << "\n==========\n" << endl;
    }*/
    if(!midterm)
    {
        cout << year << " General Election" << endl;
    } else
    {
        cout << year << " Parliamentary Election" << endl;
    }
    cout << "President: " << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << ideologies[par_ideology[presnum]][par_subideology[presnum]] << ")" << endl;
    cout << "Prime Minister: " << primem << " (" << names[par_ideology[pmnum]][par_name[pmnum]]<< " | " << ideologies[par_ideology[pmnum]][par_subideology[pmnum]] << ")" << endl;
    cout << endl;
    
    cout << "Government Coalition: " << govseats << " seats" << endl;
    for(int i=0; i!=govmembers; i++)
    {
        cout << govcoalition[i] << " (" << ideologies[par_ideology[gmemnum[i]]][par_subideology[gmemnum[i]]] << ")"<< endl;
    }
    cout << "\n==========\n" << endl;
    
    
        cout << "Opposition Coalition: " << opposeats << " seats" << endl;
        for(int i=0; i!=oppomembers; i++)
        {
            cout << oppocoalition[i] << " (" << ideologies[par_ideology[oppomemnum[i]]][par_subideology[oppomemnum[i]]] << ")" << endl;
        }
    
    
    cout << endl;
    for(int i=0; i!=10; i++)
    {
        cout <<names[par_ideology[i]][par_name[i]] << " (" << ideologies[par_ideology[i]][par_subideology[i]] << ")" << ": " << par_seats[i] << endl;
        cout << par_votes[i] << " votes (" << par_votes_percent[i] << "%)" << endl;
        for(int b=0; b!= par_votes_percent[i]/2; b++)
        {
            cout << "|";
        }
        cout << endl;
        cout << endl;
    }
    cin >> unput;
    update();
    goto game;
    return 0;
}
