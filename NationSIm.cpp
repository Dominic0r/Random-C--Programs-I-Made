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
#include <stdlib.h>

std::string  names[6][18]={
    {"Communist Party","National Democratic Party","Labor, Liberty, Action","Socialist Labor Party","Labor Reform Party","Socialist United Front","Democratic Progressive Party","National Republican Party","National Congress of Unions","Worker's Party", "Democratic Worker's Party", "United Progressive Movement", "National-Progressive Party", "Socialist People's Movement", "Revolutionary Peaasant Party","Independents", "Popular Front"},
    {"Socialist Party","Federation of Union Democrats","Greens","Social Democratic Party","Labor Party","Socialist United Front","Democratic Progressive Party","Socialists and Democrats","Yellow and Blue Alliance","National Republican Party", "Progressive Socialist Party", "United Progressive Movement", "Democratic Labor Intiative", "Socialist Republicans", "Forward Party","Independents", "Progressive Action Bloc"},
    {"Liberal Party","Democratic Party","Progressives","Center Party","Unity Party","Democratic Progressive Party","Socialists and Democrats","Yellow and Blue Alliance","Liberal Democratic Party","National Republican Party", "National Center Party", "Stability and Unity", "National List", "Progressive Conservative Party", "Rally for Democracy", "Independents", "Unionist Party"},
    {"Conservative Party","Liberal Democrats","Democratic Action Party","Reform Party","National Conservative Movement","Yellow and Blue Alliance","Liberal Democratic Party","Tradition and Democracy","National Republican Party","Democratic Interests Alliance", "Federal Party", "United Farmer's Alliance", "Folk Party", "United Action Now!", "Constitutional Party","Independents", "National Conservative Assembly"},
    {"Nationalist Party","National Action","Our Land","National Unity Front","Social Reform Movement","Tradition and Democracy","National Republican Party","Patriotic Renewal Front","New Nationalism","Conservative Labor Movement", "Traditionalist Action Party", "New Democratic Party", "National-Progressive Party", "Folk Party", "Renewal","Independents", "National Tutelage Party"}
};

std::string  subideologies[6][6] = {
    {"Communism","Marxism","Populism","Market Socialism","Left Corporatism"},
    {"Socialism","Progressive Democracy","Populism","Religious Socialism","Social Liberalism"},
    {"Liberalism","Corporatism","Populism","Religious Liberalism","Big Tent"},
    {"Conservatism","Market Liberalism","Populism","Dynastic Democracy","Religious Conservatism"},
    {"Nationalism","Traditionalism","Fascism","Populism","Right Corporatism"},
};

int year = 1922;
int month =0;

int presnum, vpnum, pmnum, sennum;

std::string uput =0; // user input

int elstatus= 0; // 0 = presidential, 1 = parliamentary, 3 = senate


int prescount = 6; // standard is 48
int pmcount = 6; // standard is 60
int sencount = 6; // standard is 36

std::string  mon_name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};



int yearpreselec = 1922;
int yearpmelec = 1922;
int yearsenelec = 1922;


//nation
class nation{
public:
    int economy = 50;
    int gdp = 50; // in millions
    int population = 1000000;
    int districts = population/25000;
    int propseats = districts*0.25;
    
    int states = districts/2;
    int stability = 75;
    
    int authoritarianism = 20;
};

class crisis{
public:
    bool ecocrash = false;
    bool corscandal = false;
    bool war = false;
    bool attack = false;
};



//parties
class party {
public:
    int ideology[20]={11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11}; // for name1
    int name2[20]={11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11};
    
    int subideo[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int auth[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int comp[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // competence
    int militancy[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int seats[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int proportional[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool haspar[20] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    
    int senate[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool hassen[20] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    
    
    std::string  leader[20] = {"","","","","","","","","","","","","","","","","","","",""}; // for president
    int lead_age[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    std::string  veep[20] = {"","","","","","","","","","","","","","","","","","","",""}; // vice-president
    int vp_age[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    std::string  prime[20] = {"","","","","","","","","","","","","","","","","","","",""};// for prime minister
    int pri_age[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    std::string sena[20] = {"","","","","","","","","","","","","","","","","","","",""};
    int sen_age[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    bool government[20] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    
    bool isrunning[20] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    
    int polpo[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int support[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int votes[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int electors[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int shares[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // government shares
};



class elections
{
public:
    
    bool checkrun(int i)
    {
        party par;
        int points = 0;
            if(par.support[i] >= par.support[presnum]/2)
            {
                return true;
            } else
            {
                return false;
            }
    }
    
    void preselec()
    {
        
    }
    
    void pmelec()
    {
        
    }
    
    void senelec()
    {
        
    }
};

class pollsters
{
public:
    party par;
    int parpct[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int pctg = 100;
    bool isdone = false;
    
    int winnum = 0;
    int winvotes= 0;
    
    int pardiv[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int wins[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    void initia()
    {
        for(int i=0;i!=20;i++){pardiv[i] = par.support[i];}
    }
    
    void farright()
    {
        initia();
        
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            if(par.ideology[winnum] == 4)
            {
                if(pctg-1 > 2)
                {
                    wins[winnum]+= 2;
                    pctg -= 2;
                }
            } else if (par.ideology[winnum] == 3)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            }
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
    
    void right()
    {
        initia();
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            if(par.ideology[winnum] == 3)
            {
                if(pctg-1 > 2)
                {
                    wins[winnum]+= 2;
                    pctg -= 2;
                }
            } else if (par.ideology[winnum] == 2)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            } else if (par.ideology[winnum] == 4)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            }
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
    
    void center()
    {
        initia();
        
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            if(par.ideology[winnum] == 2)
            {
                if(pctg-1 > 2)
                {
                    wins[winnum]+= 2;
                    pctg -= 2;
                }
            } else if (par.ideology[winnum] == 1)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            } else if (par.ideology[winnum] == 3)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            }
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
    
    void left()
    {
        initia();
        
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            if(par.ideology[winnum] == 1)
            {
                if(pctg-1 > 2)
                {
                    wins[winnum]+= 2;
                    pctg -= 2;
                }
            } else if (par.ideology[winnum] == 0)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            } else if (par.ideology[winnum] == 2)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            }
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
    
    void farleft()
    {
        initia();
        
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            if(par.ideology[winnum] == 0)
            {
                if(pctg-1 > 2)
                {
                    wins[winnum]+= 2;
                    pctg -= 2;
                }
            } else if (par.ideology[winnum] == 1)
            {
                if(pctg-1 > 1)
                {
                    wins[winnum]+= 1;
                    pctg -= 1;
                }
            }
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
    
    void official()
    {
        initia();
        
        do
        {
            for(int i=0; i!=20; i++)
            {
                if(pardiv[i] >= winvotes)
                {
                    winnum = i;
                    winvotes = pardiv[i];
                }
            }
            
            wins[winnum]++;
            pardiv[winnum] = 0;
            pardiv[winnum] = par.support[winnum]/wins[winnum];
            
            winnum = 0;
            winvotes = 0;
            
            pctg--;
            
            if(pctg <= 0)
            {
                isdone = true;
            }
            
        }while(!isdone);
    }
};

std::string namegen()
{
    std::string consonant[24] = {"B","B","K","D","G","H","H","L","L","M","N","P","R","S","S","T","T","W","W","Y","Ch","Sh","J","Kw"};
    std::string lcc[24]= {"b","b","k","d","g","h","h","l","l","m","n","p","r","s","s","t","t","w","w","y","ch","sh","j","kw"};
    std::string vowel[13] = {"a","a","a","a","a","e","i","i","i","o","o","o","u"};
    std::string aftercon[11] = {"ng","ng","m","h","n","k","k","p","p","t","y"};
    
    int numcon = sizeof(consonant)/sizeof(std::string );
    int numlcc = sizeof(lcc)/sizeof(std::string );
    int numvow = sizeof(vowel)/sizeof(std::string );
    int numaftercon = sizeof(aftercon)/sizeof(std::string );
     
    std::string  bloc1,bloc2, bloc3;
    std::string  fname, lname;
    
        bloc1 = consonant[rand()%numcon] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc1 += aftercon[rand()%numaftercon];
            }
            bloc2 = lcc[rand()%numlcc] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc2 += aftercon[rand()%numaftercon];
            }
            bloc3 = lcc[rand()%numlcc] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc3 += aftercon[rand()%numaftercon];
            }
     
            fname = bloc1;
            if(rand()%10<5)
            {
                fname += bloc2;
            }
            if(rand()%10 < 5)
            {
                fname += bloc3;
            }
     
     
     
            bloc1 = consonant[rand()%numcon] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc1 += aftercon[rand()%numaftercon];
            }
            bloc2 = lcc[rand()%numlcc] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc2 += aftercon[rand()%numaftercon];
            }
            bloc3 = lcc[rand()%numlcc] + vowel[rand()%numvow];
            if(rand()%10 < 3)
            {
                bloc3 += aftercon[rand()%numaftercon];
            }
     
            lname = bloc1;
            if(rand()%10<5)
            {
                    lname += bloc2;
            }
            if(rand()%10 < 5)
            {
                lname += bloc3;
            }
    
    return fname+ " " + lname;
}

void setup1() // party generation
{
    party par;
    for(int i=0; i !=20; i++)
    {
        par.leader[i] = namegen();
        par.veep[i] = namegen();
        par.prime[i] = namegen();
        par.sena[i] = namegen();
        
        par.lead_age[i] = (rand()%30)+25;
        par.vp_age[i] = (rand()%30)+25;
        par.pri_age[i] = (rand()%30)+25;
        par.sen_age[i] = (rand()%30)+25;
                    
        par.ideology[i] = rand()%6;
        par.name2[i] = rand()%17;
        par.subideo[i] = rand()%6;
        
        par.auth[i] = (rand()%90)+10;
        par.comp[i] = (rand()%90)+10;
        par.militancy[i] = (rand()%15)+20;
        par.support[i] = (rand()%90)+10;
    }
}

void genvp(int i)
{
    party par;
    par.veep[i] = namegen();
    par.vp_age[i] = (rand()%30)+25;
}

void genpm(int i)
{
    party par;
    par.prime[i] = namegen();
    par.pri_age[i] = (rand()%30)+25;
}

void gensen(int i)
{
    party par;
    par.sena[i] = namegen();
    par.sen_age[i] = (rand()%30)+25;
}


void dispsenate()
{
    party par;
    std::cout << "=====SENATE=====" << std::endl;
    std::cout << std::endl;
    for(int i=0; i!=5; i++)
    {
        if(par.senate[i] >0)
        {
            std::cout << names[par.ideology[i]][par.name2[i]] << " " << par.senate[i] << " seats" << std::endl;
        }
    }
    
}

void disppar()
{
    party par;
    std::cout << "=====PARLIAMENT=====" << std::endl;
    std::cout << std::endl;
    for(int i=0; i!=5; i++)
    {
        if(par.seats[i] >0)
        {
            std::cout << names[par.ideology[i]][par.name2[i]] << " " << par.seats[i] + par.proportional[i] << " seats" << std::endl;
        }
    }
    
}

void polls() // actual election polling
{
    
}

void opinions() //opinion polling
{
    
}

class updates
{
public:
    void updateeco()
    {
        
    }

    void updatestability()
    {
        
    }

    void updateauth()
    {
        
    }

};



void checkstats()
{
    elections el;
    switch(elstatus)
    {
        case 0: el.preselec();
            break;
        case 1: el.pmelec();
            break;
        case 2: el.senelec();
            break;
        default:
            std::cout << "ELSTATUS ERROR" << std::endl;
            void abort(void);
    }
}

void yearly();

void checkage();

void monthly()
{
    if(month == 11)
    {
        month = 0;
        yearly();
    } else
    {
        month++;
    }
    prescount--;
    pmcount--;
    sencount--;
    if(prescount ==0)
    {
        elstatus = 0;
        polls();
        checkstats();
        // PRESIDENTIAL ELECTION
    }
    if(pmcount == 0)
    {
        elstatus = 1;
        polls();
        checkstats();
        //PARLIAMENTARY ELECTION
    }
    if(sencount == 0)
    {
        elstatus =2;
        polls();
        checkstats();
        //SENATE ELECTION
    }
    
    checkage();
    
}

void genpres(int i)
{
    party par;
    par.lead_age[i] = (rand()%30)+25;
    par.leader[i] = par.veep[i];
    
    par.auth[i] = (rand()%90)+10;
    par.comp[i] = (rand()%90)+10;
    par.subideo[i] = rand()%6;
    genvp(i);
}

void checkage()
{
    party par;
    for(int i=0; i!=20; i++)
    {
        if((rand()%20)+65 < par.lead_age[i])
        {
            genpres(i);
            
        }
        
        if((rand()%20)+65 < par.vp_age[i])
        {
            genvp(i);
            
        }
        
        if((rand()%20)+65 < par.pri_age[i])
        {
            genpm(i);
            
        }
        
        if((rand()%20)+65 < par.sen_age[i])
        {
            gensen(i);
            
        }
        
    }
}

void yearly()
{
    party par;
    year++;
    for(int i=0; i!=20; i++)
    {
        par.lead_age[i]++;
        par.vp_age[i]++;
        par.pri_age[i]++;
        par.sen_age[i]++;
        
        
        
        
    }
    
}



void gendisp()
{
    nation nat;
    crisis cri;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Month: " << mon_name[month] << std::endl;
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "President: " << std::endl;
    std::cout << "Vice-President: " << std::endl;
    std::cout << "Prime Minister: " << std::endl;
    std::cout << "First Senator: " << std:: endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "1 - Display Parliamentary Composition" << std::endl;
    std::cout << "2 - Display Senate Composition" << std::endl;
    std::cout << "3 - Show Opinion Polls" << std::endl;
    std::cout << "4 - Next Month" << std::endl;
}



int main()
{
    srand((unsigned)time(NULL));
    mloop:
    gendisp();
    std::cout << std::endl;
gam:
std::cin >> uput;
if(uput == "1")
{
    disppar();
}else if(uput == "2")
{
    dispsenate();
}else if(uput == "3")
{
    opinions();
}else if (uput == "4")
{
    monthly();
    system("clear");
    goto mloop;
}else
{
    goto gam;
}
    
}
