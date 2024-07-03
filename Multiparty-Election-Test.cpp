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

string names[6][16]={
    {"Communist Party","National Democratic Party","Labor, Liberty, Action","Socialist Labor Party","Labor Reform Party","Socialist United Front","Democratic Progressive Party","National Republican Party","National Congress of Unions","Worker's Party", "Democratic Worker's Party", "United Progressive Movement", "National-Progressive Party", "Socialist People's Movement", "Revolutionary Peaasant Party"},
    {"Socialist Party","Federation of Union Democrats","Greens","Social Democratic Party","Labor Party","Socialist United Front","Democratic Progressive Party","Socialists and Democrats","Yellow and Blue Alliance","National Republican Party", "Progressive Socialist Party", "United Progressive Movement", "Democratic Labor Intiative", "Socialist Republicans", "Forward Party"},
    {"Liberal Party","Democratic Party","Progressives","Center Party","Unity Party","Democratic Progressive Party","Socialists and Democrats","Yellow and Blue Alliance","Liberal Democratic Party","National Republican Party", "National Center Party", "Stability and Unity", "National List", "Progressive Conservative Party", "Rally for Democracy"},
    {"Conservative Party","Liberal Democrats","Democratic Action Party","Reform Party","National Conservative Movement","Yellow and Blue Alliance","Liberal Democratic Party","Tradition and Democracy","National Republican Party","Democratic Interests Alliance", "Federal Party", "United Farmer's Alliance", "Folk Party", "United Action Now!", "Constitutional Party"},
    {"Nationalist Party","National Action","Our Land","National Unity Front","Social Reform Movement","Tradition and Democracy","National Republican Party","Patriotic Renewal Front","New Nationalism","Conservative Labor Movement", "Traditionalist Action Party", "New Democratic Party", "National-Progressive Party", "Folk Party", "Renewal"}
};

string ideologies[6][6] = {
    {"Communism","Marxism","Populism","Market Socialism","Left Corporatism"},
    {"Socialism","Progressive Democracy","Populism","Religious Socialism","Social Liberalism"},
    {"Liberalism","Corporatism","Populism","Religious Liberalism","Big Tent"},
    {"Conservatism","Market Liberalism","Populism","Dynastic Democracy","Religious Conservatism"},
    {"Nationalism","Traditionalism","Fascism","Populism","Right Corporatism"},
};

string ideologies_call[6][6] = {
    {"Communist","Marxist","Leftist","Market Socialist","Left Corporatism"},
    {"Socialist","Progressive","Leftist","Religious Socialist","Social Liberal"},
    {"Liberal","Corporate","Centrist","Religious Liberal","United"},
    {"Conservative","Liberal Democratic","Rightist","Democratic","Libertarian"},
    {"Nationalist","Traditionalist","Fascist","Rightist","Right Corporatism"},
};

string dynasty[6][6] = {
    {"","","","",""},
    {"","","","",""},
    {"","","","",""},
    {"","","","",""},
    {"","","","",""},
};

int pp[11] = {0,0,0,0,0,0,0,0,0,0};

int age[11] = {0,0,0,0,0,0,0,0,0,0};

string backg[9] = {"Orator","Reformer", "Idealist", "Pragmatist", "Compromiser", "Bureaucrat", "Outsider", "Strongman"};
int par_bg[11]= {0,0,0,0,0,0,0,0,0,0};

int year = 1922;

string unput = "";

bool midterm = false; // if true, then there is a parliamentary election
bool prelec = true; // if true, then there is a presidential election

int population = 500000;

int par_support[11] = {0,0,0,0,0,0,0,0,0,0};
int par_support_percent[11] = {0,0,0,0,0,0,0,0,0,0};

int par_votes[11] ={0,0,0,0,0,0,0,0,0,0};
int par_votes_percent[11] = {0,0,0,0,0,0,0,0,0,0};

int par_seats[11] = {0,0,0,0,0,0,0,0,0,0};
int par_seats_percent[11] = {0,0,0,0,0,0,0,0,0,0};

int par_ideology[11] ={0,0,0,0,0,0,0,0,0,0};
int par_subideology[11] = {0,0,0,0,0,0,0,0,0,0};

int par_name[11] = {0,0,0,0,0,0,0,0,0,0};

int par_personality[11] = {0,0,0,0,0,0,0,0,0,0};

int presnum =11;
int pmnum =11;

string president = "";
string pressideo="", presbg="";

string primem = "";

string preshistory[100];
int presidents =0;

int govcomp[11] = {0,0,0,0,0,0,0,0,0,0};


string par_president[11] = {"","","","","","","","","",""};
int yelect =year;
int prevpres =11;
string par_primem[11] = {"","","","","","","","","",""};

int district = population/25000;

int prime[2];

int counted =0;

int tot_elec = 20*district;
int par_electors[11]={0,0,0,0,0,0,0,0,0,0};

int ly_pres = year;
int ly_pm = year;

string govcoalition[11];
int govmembers =0;
int govseats =0;
int gmemnum[11];

int parlec = 1922;

bool parallel = true;

int prsts=0; // president seats

int competence[11]={0,0,0,0,0,0,0,0,0,0};

int estatus =50;

bool isrunning[11]={true,true,true,true,true,true,true,true,true,true};

bool ismajor[11] = {false,false,false,false,false,false,false,false,false,false};

string oppocoalition[11];
int oppomembers =0;
int opposeats =0;
int oppomemnum[11];

bool govinpower = false;

int oppoleader = 11;

int termlength =0;

bool ingov[11] = {false,false,false,false,false,false,false,false,false,false};

bool oneparty[11] = {false,false,false,false,false,false,false,false,false,false};

int foundingyear[11] = {year,year,year,year,year,year,year,year,year,year};

int regions =0;
int r_dev[999];
int avdev=0;

int par_auth[11];

string curpm = "";
int govyear = year;
string ghistory[100];
int govs= 0;
int prevpm =11;
int prevdstr =0;
int pmyear =1920;

int dynfluence[6] = {0,0,0,0,0};
bool underdy[11] = {false,false,false,false,false,false,false,false,false,false};

int partiesincongress =0;

string namegen(int x, int y)
{
    string consonant[24] = {"B","B","K","D","G","H","H","L","L","M","N","P","R","S","S","T","T","W","W","Y","Ch","Sh","J","Kw"};
    string lcc[24]= {"b","b","k","d","g","h","h","l","l","m","n","p","r","s","s","t","t","w","w","y","ch","sh","j","kw"};
        string vowel[13] = {"a","a","a","a","a","e","i","i","i","o","o","o","u"};
        string aftercon[11] = {"ng","ng","m","h","n","k","k","p","p","t","y"};
    
    int numcon = sizeof(consonant)/sizeof(string);
    int numlcc = sizeof(lcc)/sizeof(string);
    int numvow = sizeof(vowel)/sizeof(string);
    int numaftercon = sizeof(aftercon)/sizeof(string);
     
        string bloc1,bloc2, bloc3;
        string fname, lname;
    
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
    underdy[y] = false;
    if(rand()%100 < dynfluence[x])
    {
        lname = dynasty[x][rand()%5];
        underdy[y] = true;
    }
    return fname+ " " + lname;
}

void dygen()
{
    string consonant[20] = {"B","B","K","D","G","H","H","L","L","M","N","P","R","S","S","T","T","W","W","Y"};
    string lcc[20]= {"b","b","k","d","g","h","h","l","l","m","n","p","r","s","s","t","t","w","w","y"};
        string vowel[13] = {"a","a","a","a","a","e","i","i","i","o","o","o","u"};
    string bvow[13]= {"A","A","A","A","A","E","I","I","I","O","O","O","U"};
        string aftercon[11] = {"ng","ng","m","h","n","k","k","p","p","t","y"};
     
        string bloc1,bloc2, bloc3;
        string lname;
    
    for(int i=0; i!=5; i++)
    {
        for(int b=0; b!=5; b++)
        {
            
            if(rand()%10 <3)
            {
                bloc1 = bvow[rand()%13];
            }else
            {
                bloc1 = consonant[rand()%20] + vowel[rand()%13];
            }
            if(rand()%10 < 3)
            {
                bloc1 += aftercon[rand()%11];
            }
            
            if(rand()%10 <3)
            {
                bloc2 = vowel[rand()%13];
            }else
            {
                bloc2 = lcc[rand()%20] + vowel[rand()%13];
            }
            if(rand()%10 < 3)
            {
                bloc2 += aftercon[rand()%11];
            }
            
            
            if(rand()%10 <3)
            {
                bloc3 = vowel[rand()%13];
            }else
            {
                bloc3 = lcc[rand()%20] + vowel[rand()%13];
            }
            if(rand()%10 < 3)
            {
                bloc3 += aftercon[rand()%11];
            }
     
            dynasty[i][b] = bloc1;
            if(rand()%10<5)
            {
                dynasty[i][b] += bloc2;
            }
            if(rand()%10 < 5)
            {
                dynasty[i][b] += bloc3;
            }

        }
    }
}

void checkback(int i) //"Orator/","Reformer/", "Idealist", "Pragmatist", "Compromiser", "Bureaucrat/", "Outsider/", "Strongman/"
{
    if(backg[par_bg[i]] == "Reformer")
    {
        par_auth[i] /=2;
    }
    if(backg[par_bg[i]] == "Strongman")
    {
        par_auth[i] *= 1.5;
    }
    if(backg[par_bg[i]] == "Orator")
    {
        par_support[i] *= 1.5;
    }
    if(backg[par_bg[i]] == "Bureaucrat")
    {
        competence[i] +=3;
    }
    if(backg[par_bg[i]] == "Outsider")
    {
        par_support[i] *=1.25;
    }
}

void setup()
{
    dygen();
    for(int i=0; i!= 100; i++) {preshistory[i]="";}
    int dvsr = (rand()%15)+5;
    regions = district/dvsr;
    for(int i=0; i!=5; i++){dynfluence[i]= rand()%50;}
    for(int i=0; i!=regions; i++)
    {
        r_dev[i] = rand()%10;
    }
    population += (rand()%500000);
    for(int i=0; i!=10; i++)
    {
        par_ideology[i] = rand()%5;
        par_subideology[i] = rand()%5;
        par_name[i] = rand()%15;
        par_president[i] = namegen(par_ideology[i], i);
        par_primem[i] = namegen(par_ideology[i], i);
        par_personality[i] = rand()%100;
        par_bg[i] = rand()%8;
        par_support[i] = (rand()%100)+25;
        competence[i] = (rand()%10)-5;
        par_auth[i] = rand()%100;
        age[i] = (rand()%30)+25;
        
        checkback(i);
        
        if(par_ideology[i] == 0 || par_ideology[i] == 4)
        {
            par_support[i] /=5;
        } else if(par_ideology[i] == 1 || par_ideology[i] == 3)
        {
            par_support[i] /=2;
            par_auth[i] /=2;
        } else
        {
            par_support[i] *= 1.5;
            par_auth[i] /=5;
        }
        
        if(rand()%100 < par_personality[i])
        {
            par_support[i] *= 2;
        }
    }
}

void eco()
{
    int presseats =0;
    int equib = 10;
    if(midterm == true)
    {
        prsts = par_seats[presnum];
    }
    presseats = (prsts*100)/district;
    /*cout << prsts << endl;
    cout << district << endl;
    cout << presseats << endl;
    cout <<competence[presnum]*(presseats/10) << endl;
    cin>> unput;*/
    estatus += competence[presnum]*(presseats/10);
    
    
        estatus *=0.5;
        switch((year-parlec)/10)
        {
            case 1:
                estatus-=estatus*0.05;
                break;
            case 2:
                estatus-=estatus*0.1;
                break;
            case 3:
                estatus-=estatus*0.15;
                break;
            case 4:
                estatus-=estatus*0.2;
                break;
            case 5:
                estatus-=estatus*0.25;
                break;
            case 6:
                estatus-=estatus*0.3;
                break;
            case 7:
                estatus-=estatus*0.35;
                break;
            case 8:
                estatus-=estatus*0.4;
                break;
            case 9:
                estatus-=estatus*0.45;
                break;
            case 10:
                estatus-=estatus*0.5;
                break;
        }
    if(par_auth[presnum]>= 85)
    {
        estatus -= estatus*0.1;
    }
    
    if(rand()%10<=competence[presnum])
    {
        equib++;
    }
    
    if(estatus > 100)
    {
        estatus = 100;
    }
    if(estatus < -100)
    {
        estatus = -100;
    }
    
    if(estatus >equib)
    {
        estatus -=10;
    }
    if(estatus <equib)
    {
        estatus+=10;
    }
}

void timeup()
{
    if(parallel == false)
    {
        if(ly_pm+5 < ly_pres+4) // if the parliamentary election is closer
        {
            midterm = true;
            prelec = false;
            
            for(int i=0;  i!=10; i++)
            {
                age[i] += (ly_pm+5)-year;
            }
            
            year = ly_pm +5;
            ly_pm = year;

            
        }else if(ly_pm+5> ly_pres+4) // if the presidential election is closer
        {
            midterm = false;
            prelec = true;
            
            for(int i=0;  i!=10; i++)
            {
                age[i] += (ly_pres+4)-year;
            }
            
            year = ly_pres+4;
            ly_pres = year;
        }else if(ly_pm+5 == ly_pres+4) // if both elections happent he same year
        {
            if(year == 1922)
            {
                parallel = true;
                midterm = false;
                prelec = true;
                year = year+4;
                ly_pm = year;
                ly_pres = year;
            } else
            {
                parallel = true;
                midterm = true;
                prelec = false;
                year = year+4;
                ly_pm = year;
                ly_pres = year;
            }
            for(int i=0;  i!=10; i++)
            {
                age[i] += 4;
            }
            
        }
    } else
    {
        if(year == 1922)
        {
            parallel = false;
            midterm = true;
            prelec = false;
        }else
        {
            parallel = false;
            midterm = false;
            prelec = true;

        }
    }
}

void checkrun()
{
    partiesincongress =0;
    int score =0;
    int psp =0;
    int cands =0;
    int requirement =20;
    for(int i=0; i!=10; i++)
    {
        if(par_seats[i] >0)
        {
            partiesincongress++;
        }
    }
    
    for(int i=0; i!=10; i++)
    {
        score =0;
        psp=0;
        int totpp =1;
        for(int b=0;b!=10;b++){totpp+=pp[b];}
        psp = (par_seats[i]*100)/(district+1);
        score += (psp*0.25)+ (par_votes_percent[i]*0.25) + ((rand()%100)*0.25)+ (((pp[i]*100)/totpp)*0.25);
        
        
        if(ingov[i] && i != presnum)
        {
            score -= 10;
        }
        
        if(i == presnum)
        {
            score += 7;
        }
        
        if(par_auth[presnum]>=85 && i != presnum)
        {
            score -=5;
        }
        if(par_auth[presnum] >= 85 && i == presnum)
        {
            score += 7;
        }
        if(i == oppoleader)
        {
            score +=7;
        }
        
        switch(partiesincongress)
        {
            case 1: requirement = 0;
                break;
            case 2:requirement = 5;
                break;
            case 3: requirement = 10;
                break;
            case 4:requirement = 12;
                break;
            case 5:requirement = 15;
                break;
            case 6:requirement = 17;
                break;
            case 7:requirement = 20;
                break;
            case 9: requirement = 22;
                break;
            default:requirement = 25;
        }
        
        if(score >= requirement)
        {
            isrunning[i] = true;
            cands++;
            oneparty[i] = true;
            
        } else
        {
            isrunning[i] = false;
            par_support[i] =0;
        }
        /*cout << names[par_ideology[i]][par_name[i]] << " " << score;
        if(isrunning[i])
        {
            cout << " - Running" << endl;
        } else
        {
            cout << endl;
        }*/
        
    }
    
    if(cands>1)
    {
        for(int i=0; i!=10; i++)
        {
            oneparty[i] = false;
        }
    }
    
    
    //cin>> unput;
}

void update()
{
    
    
    tot_elec = district*20;
    int pad = population*0.1;
    population += rand()%pad+1;
    district = population/25000;
    
    
    
    if(underdy[presnum] == true)
    {
        dynfluence[par_ideology[presnum]] += 10;
        for(int i=0; i!=5; i++){dynfluence[i]+=3;}
    }

    
    
    pp[presnum]+=10;
    pp[pmnum]+=5;
    pp[oppoleader]+=10;
    for(int i=0; i!=5; i++){dynfluence[i]-=2;if(dynfluence[i] <10){dynfluence[i] = 10;} if(dynfluence[i] > 90){dynfluence[i] = 90;}}
    for(int i =0; i!=10;i++)
    {
        if((year - foundingyear[i]) - ((par_seats[i]*100)/(district+1)) > rand()%100 && i != presnum && i != pmnum && prelec == false)
        {
            par_ideology[i] = rand()%5;
            par_subideology[i] = rand()%5;
            par_name[i] = rand()%15;
            par_auth[i] = rand()%100;
            par_president[i] = namegen(par_ideology[i], i);
            par_primem[i] = namegen(par_ideology[i], i);
            par_personality[i] = rand()%100;
            par_support[i] = (rand()%100)+25;
            par_bg[i] = rand()%8;
            foundingyear[i] = year;
            pp[i] =0;
            age[i] = (rand()%30)+25;
            checkback(i);
            
            
            if(estatus <0)
            {
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] *=1.5;
                } else if(par_ideology[i] == 1 || par_ideology[i] == 3)
                {
                    par_support[i] /=2;
                    par_auth[i] /=2;
                } else
                {
                    par_support[i] /= 5;
                    par_auth[i] /=5;
                }
            }else
            {
                
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] /=5;
                } else if(par_ideology[i] == 1 || par_ideology[i] == 3)
                {
                    par_support[i] /=2;
                    par_auth[i] /=2;
                } else
                {
                    par_support[i] *= 1.5;
                    par_auth[i] /=5;
                }
            }
            competence[i] = (rand()%10)-5;
            isrunning[i] = false;
        }
        int threshold =0;
        if(par_auth[i] >= 85)
        {
            threshold = 75;
        } else
        {
            threshold =60;
        }
        if(i == presnum)
        {
            if(par_auth[i] < 85)
            {
                if(year -yelect >= 4 || threshold + (rand()%25) < age[i])
                {
                    par_president[i] = namegen(par_ideology[i], i);
                    if(rand()%district<par_seats[i])
                    {
                        par_president[i] = par_primem[i];
                    }
                    pp[i] =pp[i]/2;
                    par_personality[i] = rand()%100;
                    par_subideology[i] = rand()%5;
                    competence[i] = (rand()%10)-5;
                    par_bg[i] = rand()%8;
                    int oldauth = par_auth[i]/10;
                    par_auth[i] = (rand()%100)+oldauth;
                    age[i] = (rand()%30)+25;
                    checkback(i);
                }
            } else
            {
                if(threshold + (rand()%25) < age[i])
                {
                    par_president[i] = namegen(par_ideology[i], i);
                    if(rand()%district<par_seats[i])
                    {
                        par_president[i] = par_primem[i];
                    }
                    pp[i] =pp[i]/2;
                    par_personality[i] = rand()%100;
                    par_subideology[i] = rand()%5;
                    competence[i] = (rand()%10)-5;
                    par_bg[i] = rand()%8;
                    int oldauth = par_auth[i]/10;
                    par_auth[i] = (rand()%100)+oldauth;
                    age[i] = (rand()%30)+25;
                    checkback(i);
                }
            }
        } else
        {
            if(threshold + (rand()%25) < age[i])
            {
                par_president[i] = namegen(par_ideology[i], i);
                if(rand()%district<par_seats[i])
                {
                    par_president[i] = par_primem[i];
                }
                pp[i] =pp[i]/2;
                par_personality[i] = rand()%100;
                par_subideology[i] = rand()%5;
                competence[i] = (rand()%10)-5;
                par_bg[i] = rand()%8;
                int oldauth = par_auth[i]/10;
                par_auth[i] = (rand()%100)+oldauth;
                age[i] = (rand()%30)+25;
                checkback(i);
            }
        }
        
        int leadseatper = (par_seats[pmnum] *100)/district;
        
        if(rand()%50 > (leadseatper-(year-pmyear)))
        {
            pmyear =year;
            par_primem[i] = namegen(par_ideology[i], i);
            par_personality[i] += (rand()%50)-25;
            if(par_personality[i] > 100)
            {
                par_personality[i] =100;
            } else if(par_personality[i] < 0)
            {
                par_personality[i] = 0;
            }
        }
        
        pp[i] += 5;
        
        
        
        if(rand()%10<5)
        {
            competence[i]++;
        }else
        {
            competence[i]--;
        }
        if(competence[i]>5)
        {
            competence[i] =5;
        }
        if(competence[i]<-5)
        {
            competence[i] = -5;
        }
        
        if(i== presnum && par_auth[i] > 85)
        {
            competence[i]--;
        }
        
        par_support[i] = (rand()%((100+ (par_support[i]/10))+ par_votes_percent[i])+1)- ((year - yelect)/10);
        par_support[i] += (par_seats[i]*100)/district;
        if(i == presnum || i == pmnum || i == oppoleader)
        {
            par_support[i] += par_support[i]*0.1;
        }
        par_support[i]+=pp[i];
        
        if(i == presnum && year - parlec >4)
        {
            switch((year-parlec)/10)
            {
                case 1:
                    par_support[i] *= 0.75;
                    break;
                case 2:
                    par_support[i] *= 0.7;
                    break;
                case 3:
                    par_support[i] *= 0.65;
                    break;
                case 4:
                    par_support[i] *= 0.6;
                    break;
                case 5:
                    par_support[i] *= 0.55;
                    break;
                case 6:
                    par_support[i] *= 0.5;
                    break;
                case 7:
                    par_support[i] *= 0.45;
                    break;
                case 8:
                    par_support[i] *= 0.4;
                    break;
                case 9:
                    par_support[i] *= 0.35;
                    break;
                case 10:
                    par_support[i] *= 0.3;
                default:
                    par_support[i] += 0;
            }
            
        }
        
        if(i!=presnum && year-parlec >4)
        {
            switch((year-parlec)/10)
            {
                case 1:
                    par_support[i] += par_support[presnum]* 0.2;
                    break;
                case 2:
                    par_support[i] += par_support[presnum]* 0.25;
                    break;
                case 3:
                    par_support[i] += par_support[presnum]* 0.3;
                    break;
                case 4:
                    par_support[i] += par_support[presnum]* 0.35;
                    break;
                case 5:
                    par_support[i] += par_support[presnum]* 0.4;
                    break;
                case 6:
                    par_support[i] += par_support[presnum]* 0.45;
                    break;
                case 7:
                    par_support[i] += par_support[presnum]* 0.5;
                    break;
                case 8:
                    par_support[i] += par_support[presnum]* 0.55;
                    break;
                case 9:
                    par_support[i] += par_support[presnum]* 0.6;
                    break;
                case 10:
                    par_support[i] += par_support[presnum]* 0.65;
                default:
                    par_support[i] += 0;
            }
        }
        
        switch(estatus/25)
        {
            case -4:
            case -3:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] += par_support[i]*0.50;
                } else
                {
                    par_support[i] -= par_support[i]*0.50;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] += par_support[i]*0.10;
                } else
                {
                    par_support[i] -= par_support[i]*0.10;
                }
                
                if(i == presnum)
                {
                    par_support[i] -=par_support[i]*0.15;
                }
                
                break;
            case -2:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] += par_support[i]*0.25;
                } else
                {
                    par_support[i] -= par_support[i]*0.25;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] += par_support[i]*0.05;
                } else
                {
                    par_support[i] -= par_support[i]*0.05;
                }
                
                if(i == presnum)
                {
                    par_support[i] -=par_support[i]*0.10;
                }
                break;
            case -1:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] += par_support[i]*0.1;
                } else
                {
                    par_support[i] -= par_support[i]*0.1;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] += par_support[i]*0.01;
                } else
                {
                    par_support[i] -= par_support[i]*0.01;
                }
                
                if(i == presnum)
                {
                    par_support[i] -=par_support[i]*0.1;
                }
                break;
            case 0:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] -= par_support[i]*0.05;
                } else
                {
                    par_support[i] += par_support[i]*0.05;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] -= par_support[i]*0.005;
                } else
                {
                    par_support[i] += par_support[i]*0.005;
                }
                
                if(i == presnum)
                {
                    par_support[i] -=par_support[i]*0.01;
                }
                break;
            case 1:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] -= par_support[i]*0.1;
                } else
                {
                    par_support[i] += par_support[i]*0.1;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] -= par_support[i]*0.01;
                } else
                {
                    par_support[i] += par_support[i]*0.01;
                }
                
                if(i == presnum)
                {
                    par_support[i] +=par_support[i]*0.05;
                }
                break;
            case 2:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] -= par_support[i]*0.25;
                } else
                {
                    par_support[i] += par_support[i]*0.25;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] -= par_support[i]*0.05;
                } else
                {
                    par_support[i] += par_support[i]*0.05;
                }
                
                if(i == presnum)
                {
                    par_support[i] +=par_support[i]*0.10;
                }
                break;
            case 3:
            case 4:
                if(par_ideology[i] == 0 || par_ideology[i] == 4)
                {
                    par_support[i] -= par_support[i]*0.50;
                } else
                {
                    par_support[i] += par_support[i]*0.50;
                }
                
                if(par_auth[i] >= 60)
                {
                    par_support[i] -= par_support[i]*0.10;
                } else
                {
                    par_support[i] += par_support[i]*0.10;
                }
                
                if(i == presnum)
                {
                    par_support[i] +=par_support[i]*0.15;
                }
                break;
        }
        
        if(presnum == i)
        {
            if(presnum != pmnum)
            {
                par_support[i] *= 0.75;
            }
        }
        if(oneparty[i] == true && par_auth[i] <85)
        {
            par_support[i] /= 2;
        }
        
        
            par_support_percent[i] =0;
            par_votes_percent[i] =0;
            par_votes[i] =0;
            par_seats[i] =0;
        
    }
    
    for(int i=0; i!=10; i++)
    {
        oneparty[i] = false;
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
    
    for(int i=0;i!=10;i++){par_votes[i]=0;}
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
    bool hasvoted = false;
    int totvotes =0;
    //cout << "N";
    string debug_input = "";
    
    
    while(rempop >population*0.25)
    {
        if(midterm == true && prelec == false)
        {
            cout << year << " Parliamentary Election" << endl;
        }else if (midterm == false && prelec == true)
        {
            cout << year << " Presidential Election" << endl;
        }else if(midterm == true && prelec == true){
            cout << year << " General Election" << endl;
        }
        cout << endl;
        cout << "President: " << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << pressideo << " | " << presbg << ")" << " | Elected: " << yelect << endl;
        cout << "Prime Minister: " << primem << " (" << names[par_ideology[pmnum]][par_name[pmnum]]<< " | " << ideologies[par_ideology[pmnum]][par_subideology[pmnum]] << ")" << endl;
        cout << endl;
        chance = rand()%100;
        int rpp = rempop*0.1;
        tickremove = rand()%(rpp+1);
        /*while(!hasvoted)
        {
            for(int i=0; i!=10; i++)
            {
                //cout << "prevstack: " << prevstack << endl;
                //cout << "stack: " << stack << endl;
                //cout << "chance: " << chance << endl;
                //cin>> debug_input;
                if(chance > prevstack && chance < stack)
                {
                    hasvoted = true;
                    if(i == presnum || i == pmnum || i == oppoleader)
                    {
                        tickremove += tickremove* 1.5;
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
        }*/
        int regular =0;
        int myon =0;
        float cut = 0;
        int partido[5] = {0,0,0,0,0};
        int factions[10] = {0,0,0,0,0,0,0,0,0,0};
        int otheradd=0;

        for(int i=0; i!=10; i++)
        {
            for(int y=0; y!=5; y++)
            {
                if(par_ideology[i] == y)
                {
                    partido[y]++;
                }
            }
            for(int y=0; y!=10;y++)
            {
                if(par_name[i] == par_name[y])
                {
                    factions[i]++;
                }
            }
        }
        
        for(int i=0; i!=10; i++)
        {
            if((!midterm && isrunning[i] == true) || midterm)
            {
                
                cut = (float) par_support_percent[i]/1000;
                regular =0;
                myon = rempop*cut;
                myon+=1;
                regular = rand()%myon;
                if(ismajor[i] == true)
                {
                    regular += regular*0.75;
                }
                if(i == presnum&& (rand()%15)+85 < par_auth[i])
                {
                    regular+= regular;
                }
                if(i == presnum)
                {
                    regular += regular*0.50;
                }
                if(i == oppoleader)
                {
                    regular+= regular*0.75;
                }
                int regadd =regular;
                
                //regadd = regular/(partido[par_ideology[i]]+1);
                //regadd = regadd/ ((factions[i]*2)+1);
                if(rand()%100 == chance)
                {
                    regadd += rand()%(tickremove+1);
                }
                if(midterm)
                {
                    for(int b=0; b!=10;b++)
                    {
                        if(par_ideology[i] == par_ideology[b])
                        {
                            otheradd=0;
                            otheradd =regular/(partido[par_ideology[i]]+1);
                            par_votes[b] += otheradd;
                            tickremove += otheradd;
                            /*if(!midterm && !isrunning[b])
                             {
                             par_votes[b] -= otheradd;
                             tickremove -= otheradd;
                             }*/
                            regadd +=regular/(partido[par_ideology[i]]+1);
                        }
                        if(par_name[i] == par_name[b])
                        {
                            otheradd=0;
                            otheradd =regular/ ((factions[i]*2)+1);
                            par_votes[b] += otheradd;
                            tickremove += otheradd;
                            /*if(!midterm && !isrunning[b])
                             {
                             par_votes[b] -= otheradd;
                             tickremove -= otheradd;
                             }*/
                            regadd +=regular/ ((factions[i]*2)+1);
                        }
                        
                    }
                }
                tickremove += regadd;
                par_votes[i] += regadd;
                /*if(!midterm && !isrunning[i])
                 {
                 par_votes[i] =0;
                 tickremove -= regadd;
                 }*/
            }
        }
        
        //cout << "G";
        hasvoted = false;
        if(tickremove > rempop)
        {
            tickremove = rempop*0.15;
        }
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
            if((!midterm && isrunning[i]) || midterm)
            {
                //cout << i << endl;
                cout << par_president[i] << " (" <<names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")" << endl;
                //cout << par_support_percent[i] << endl;
                cout << par_votes[i] << " votes (" << par_votes_percent[i] << "%)" << endl;
                for(int b=0; b!= par_votes_percent[i]/2; b++)
                {
                    cout << "|";
                }
                cout << endl;
                cout << endl;
            }
        }
        //cout << "A";
        cout << "Remaining Voters: " << rempop << endl;
        if(totvotes >=population)
        {
            totvotes =0;
        }
        cout << "Total votes counted: " << population-rempop << " / " << population << endl;
        sleep(1);
        system("clear");
    }
    //cout << "P";
    
}

void preselec()
{
    int winnum =0, winvotes =0;
    int invot[10];
    int points[10];
    int all =20;
    int avgpctg =0;
    for(int i=0; i!=10; i++){avgpctg+=par_votes_percent[i];}
    avgpctg = avgpctg/10;
    for(int i=0; i!=10; i++)
    {
        par_electors[i] =0;
        invot[i] = par_votes[i];
        points[i] =0;
    }
    int remelec = tot_elec;
    while(remelec >0)
    {
        for(int i=0; i!=10; i++)
        {
            if(invot[i] > winvotes && par_votes_percent[i] > avgpctg)
            {
                    winnum = i;
                    winvotes = invot[i];
            }
        }
        int remove =0;
        remove = (rand()%20)+1;
        if(all >0)
        {
            remove += remove *all;
            all--;
        }
        
        if(winnum == pmnum && rand()%100 < par_auth[winnum] && par_auth[winnum] >=85)
        {
            remove += remove *10;
        }
        
        if(remove > remelec)
        {
            remove = remelec;
        }
        points[winnum]++;
        par_electors[winnum] += remove;
        remelec -= remove;
        invot[winnum]= par_votes[winnum]/(points[winnum]+1);
        winnum =0;
        winvotes =0;
    }
    
    for(int i=0; i!=10; i++)
    {
        if(par_electors[i] > winvotes)
        {
            winnum = i;
            winvotes = par_electors[i];
        }
    }
    if(par_electors[winnum] <= tot_elec/2&& year !=1922)
    {
        winnum = pmnum;
    }
    
    
    if(president != par_president[winnum])
    {
        string yelstring = to_string(yelect), yestring = to_string(year);
        preshistory[presidents] = president + " (" + names[par_ideology[presnum]][par_name[presnum]] + " | " +pressideo + " | " + presbg+ ") " + yelstring + " - " + yestring;
        prevpres = presnum;
        presidents++;
        pressideo = ideologies[par_ideology[winnum]][par_subideology[winnum]];
        presbg = backg[par_bg[winnum]];
        yelect = year;
        
        string yelstring1 = to_string(govyear);
        ghistory[govs] = president + " - " + primem + " Government (" + yelstring1 + " - " + yestring + ") - ";
        if(govinpower)
        {
            ghistory[govs] += "Pro-President Government";
        } else
        {
            ghistory[govs] += "Opposition Government";
        }
        govs++;
        govyear = year;
        
    }
    if(names[par_ideology[presnum]][par_name[presnum]] != names[par_ideology[winnum]][par_name[winnum]])
    {
        parlec = year;
    }
    
    president = par_president[winnum];
    presnum = winnum;
    
    
    par_auth[presnum] += rand()%((year-yelect)+1);
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
    int wins = 10;
    int windiv =0;
    while(remdists >0)
    {
        for(int i=0; i!= 10;i++)
        {
            if(par_auth[presnum] <85)
            {
                if(votedivide[i] > winvotes)
                {
                    winvotes = votedivide[i];
                    winnum = i;
                }
            } else
            {
                if(votedivide[i] > winvotes && par_ideology[i] == par_ideology[presnum] && (par_ideology[presnum] ==4 || par_ideology[presnum] ==0))
                {
                    winvotes = votedivide[i];
                    winnum = i;
                } else if (votedivide[i] > winvotes && (par_ideology[presnum] <4 || par_ideology[presnum] >0))
                {
                    winvotes = votedivide[i];
                    winnum = i;
                }
            }
        }
        
        tickremove = rand()%((par_votes_percent[winnum]/10)+1);
        if(wins >1)
        {
            windiv = district/10+ ((100-par_votes_percent[winnum])/10);
            tickremove += (tickremove*wins)/windiv;
            wins--;
        }
        /*if(winnum == presnum && rand()%100 < par_auth[winnum] && par_votes_percent[winnum] > 50)
        {
            tickremove += tickremove*1.5;
        }*/
        if(remdists-tickremove <0)
        {
            tickremove = remdists;
        }
        //tickremove = 1;
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
    for(int i=0; i!=10; i++)
    {
        if(par_auth[presnum] <85)
        {
            par_seats[i] += (((district*par_votes_percent[i])/100)*25)/100;
        } else
        {
            if(par_ideology[i]== par_ideology[presnum] && (par_ideology[presnum] ==0 || par_ideology[presnum] == 4))
            {
                par_seats[i] += (((district*par_votes_percent[i])/100)*25)/100;
            } else
            {
                par_seats[presnum] += (((district*par_votes_percent[i])/100)*25)/100;
            }
        }
    }
    district =0;
    for(int i=0; i!=10; i++){district+=par_seats[i];}
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
            oppoleader = i;
        }
    }
    gmemnum[govmembers] = gov;
    govcoalition[govmembers] = names[par_ideology[gov]][par_name[gov]];
    govmembers++;
    govseats += par_seats[gov];
    ingov[gov] = true;
    
        oppomemnum[oppomembers] = opponum;
        oppocoalition[oppomembers] = names[par_ideology[opponum]][par_name[opponum]];
        oppomembers++;
        opposeats += par_seats[opponum];
        oppoleader = opponum;
    ingov[opponum] = false;
    
    
    
    int govpoints = 0, oppopoints =0;
    for(int i=0; i!=10; i++)
    {
        if(i != gov && i != opponum && i != presnum)
        {
            
            govpoints += 20* abs(par_ideology[gov] - par_ideology[i]);
            oppopoints += 20* abs(par_ideology[opponum] - par_ideology[i]);
            
            govpoints += abs(par_personality[gov] - par_personality[i]);
            oppopoints += abs(par_personality[opponum] - par_personality[i]);
            
            if(backg[par_bg[gov]] == "Pragmatist")
            {
                govpoints -= 50;
            }
            
            if(backg[par_bg[opponum]] == "Pragmatist")
            {
                oppopoints -= 50;
            }
            
            if(backg[par_bg[gov]] == "Strongman")
            {
                govpoints += 50;
            }
            if(backg[par_bg[opponum]] == "Strongman")
            {
                oppopoints += 50;
            }
            
            if(backg[par_bg[i]] == "Compromiser" && backg[par_bg[opponum]] == backg[par_bg[i]] )
            {
                govpoints-=25;
            }
            
            if(backg[par_bg[i]] == "Compromiser" && backg[par_bg[opponum]] == backg[par_bg[i]] )
            {
                oppopoints-=25;
            }
            
            if(par_ideology[gov] == par_ideology[i])
            {
                govpoints -= 10;
            } else if(par_ideology[opponum] == par_ideology[i])
            {
                oppopoints -= 10;
            }
            if(par_seats[presnum]> district/2 && par_auth[presnum]<65)
            {
                govpoints += 50;
            }
            if(par_auth[presnum] > 65)
            {
                govpoints-=100;
            }
            if(govpoints <= oppopoints)
            {
                gmemnum[govmembers] = i;
                govcoalition[govmembers] = names[par_ideology[i]][par_name[i]];
                govmembers++;
                govseats += par_seats[i];
                ingov[i] = true;
            }else if(oppopoints < govpoints)
            {
                oppomemnum[oppomembers] = i;
                oppocoalition[oppomembers] = names[par_ideology[i]][par_name[i]];
                oppomembers++;
                opposeats += par_seats[i];
                ingov[i] = false;
            }

        }
        govpoints =0;
        oppopoints =0;
        

    }
    
    if(govseats >= opposeats)
    {
        govinpower = true;
    } else
    {
        govinpower = false;
    }
    
}

void govcompcalc()
{
    for(int i =0; i!=10; i++){govcomp[i] = 0;}
    int pscore[10] = {0,0,0,0,0,0,0,0,0,0};
    int winvotes =0;
    int winnum = 11;
    int points[10] = {1,1,1,1,1,1,1,1,1,1};
    for(int i=0; i!=10; i++)
    {
        
            pscore[i] = par_seats[i];
        
    }
    int gco =0;
    while(gco<100)
    {
        for(int i=0; i!=10; i++)
        {
                if(pscore[i] > winvotes)
                {
                    winvotes = pscore[i];
                    winnum = i;
                }
        }
        if(govseats >= opposeats)
        {
            if(ingov[winnum])
            {
                govcomp[winnum]+=10;
                gco +=10;
            } else
            {
                govcomp[winnum] +=5;
                gco+=5;
            }
        } else
        {
            if(!ingov[winnum])
            {
                govcomp[winnum]+=10;
                gco +=10;
            } else
            {
                govcomp[winnum] +=5;
                gco+=5;
            }
        }
        
        if(gco > 100)
        {
            int c = gco-100;
            govcomp[winnum]-= c;
        }
        
        points[winnum]++;
        pscore[winnum] = par_seats[winnum]/points[winnum];
        winvotes =0;
        winnum = 11;
    }
}

void govform()
{
    int points[10]= {0,0,0,0,0,0,0,0,0,0};
    int memnum[10]= {0,0,0,0,0,0,0,0,0,0};
    int votedivide[10] = {0,0,0,0,0,0,0,0,0,0};
    int memcount = 0;
    if(govinpower)
    {
        memcount = govmembers;
        for(int i=0;i!=memcount;i++){votedivide[i]=par_seats[gmemnum[i]]*100;memnum[i]=gmemnum[i];}
    } else
    {
        memcount = oppomembers;
        for(int i=0;i!=memcount;i++){votedivide[i]=par_seats[oppomemnum[i]]*100;memnum[i]=oppomemnum[i];}
    }
    int winnum =0;
    int winvotes =0;
    for(int b =0; b!= 11; b++)
    {
        for(int i=0; i!=memcount; i++)
        {
            if(votedivide[i] > winvotes && votedivide[i] > 0)
            {
                winnum =i;
                winvotes = votedivide[i];
            }
        }
        points[winnum]++;
        if(govinpower)
        {
            votedivide[winnum] =(par_seats[gmemnum[winnum]]*100)/ (points[winnum]+1);
        } else
        {
            votedivide[winnum] =(par_seats[oppomemnum[winnum]]*100)/ (points[winnum]+1);
        }
        winnum = 11;
        winvotes =0;
    }
    
        for(int i=0; i!=memcount; i++)
        {
            if(points[i] > winvotes)
            {
                winnum = memnum[i];
                winvotes = points[i];
            }
        }
    
    
    if(primem != par_primem[winnum] && prelec == false)
    {
        string yelstring = to_string(govyear), yestring = to_string(year);
        ghistory[govs] = president + " - " + primem + " Government (" + yelstring + " - " + yestring + ") - ";
        if(govinpower)
        {
            ghistory[govs] += "Pro-President Government";
        } else
        {
            ghistory[govs] += "Opposition Government";
        }
        prevpm = pmnum;
        govs++;
        govyear = year;
    }
    
    pmnum = winnum;
    primem = par_primem[winnum];
    
    /*if(govinpower)
    {
        for(int i=0; i!=11; i++)
        {
            for(int b =0; b!=govmembers; b++)
            {
                if(votedivide[b]> winvotes)
                {
                    winnum = b;
                    winvotes = votedivide[b];
                }
            }
            points[winnum]++;
            votedivide[winnum] = par_seats[gmemnum[memnum[winnum]]]/ (points[winnum]+1);
            winnum = 11;
            winvotes = 0;
        }
        for(int b =0; b!=govmembers; b++)
        {
            if(points[b]> winvotes)
            {
                winnum = b;
                winvotes = points[b];
            }
        }
        
    }*/
}

void checkmajors()
{
    int totseats = (district*25)/100;
    int minthresh = totseats*0.1;
    bool val[10]= {false,false,false,false,false,false,false,false,false,false};
    for(int i=0; i!=10; i++)
    {
        if(par_seats[i] >= minthresh)
        {
            val[i] = true;
        }
    }
    
    int confm[3] = {0,0,0};
    int cfseats[3] = {0,0,0};
    for(int i=0; i!=10; i++)
    {
        if(par_seats[i] > cfseats[0] && par_seats[i] > cfseats[1] && par_seats[i] > cfseats[2] && val[i] == true)
        {
            confm[2] = confm[1];
            confm[1] = confm[0];
            confm[0] = i;
            
            cfseats[2] = cfseats[1];
            cfseats[1] = cfseats[0];
            cfseats[0] = par_seats[i];
        } else if(par_seats[i] < cfseats[0] && par_seats[i] > cfseats[1] && par_seats[i] > cfseats[2] && val[i] == true)
        {
            confm[2] = confm[1];
            confm[1] = i;
            
            cfseats[2] = cfseats[1];
            cfseats[1] = par_seats[i];
        } else if(par_seats[i] < cfseats[0] && par_seats[i] < cfseats[1] && par_seats[i] > cfseats[2] && val[i] == true)
        {
            confm[2] = i;
            confm[2] = par_seats[i];
        }
    }
    for(int i=0; i!=1; i++)
    {
        ismajor[i] = false;
    }
    for(int i=0; i!=3;i++)
    {
        ismajor[confm[i]] = true;
    }
}

void disp_parlo()
{
    cout << "President: " << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << pressideo<< " | " << presbg << ")" << " | Elected: " << yelect << endl;
    cout << "Prime Minister: " << primem << " (" << names[par_ideology[pmnum]][par_name[pmnum]]<< " | " << ideologies[par_ideology[pmnum]][par_subideology[pmnum]] << ")" << endl;
    cout << endl;
    bool istotal =false;
    for(int i=0; i!=10; i++)
    {
        if(govcomp[i] == 100)
        {
            istotal = true;
        }
    }
    
    int tgcomp =0, tocomp =0;
    for(int i=0; i!=10; i++)
    {
        if(ingov[i])
        {
            tgcomp+= govcomp[i];
        }else{
            tocomp+= govcomp[i];
        }
        
    }
    
    if(istotal)
    {
        cout << "Government Composition" << endl;
        for(int i=0; i!=10; i++)
        {
            if(govcomp[i] >0 && ingov[i])
            {
                cout << par_president[i] << " (" << names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << ")"<< ": " << govcomp[i] << "%" << endl;
            }
        }
    }else
    {
        cout << "=====Joint Government Composition=====" << endl;
        cout << "Supportive Parties in Government (" << tgcomp << "%)" << endl;
            for(int i=0; i!=10; i++)
            {
                if(govcomp[i] >0 && ingov[i])
                {
                    cout << par_president[i] << " (" << names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")"<< ": " << govcomp[i] << "%" << endl;
                }
            }
        if(tocomp >0)
        {
            cout << endl;
            cout << "Opposition Parties in Government (" << tocomp << "%)" << endl;
            for(int i=0; i!=10; i++)
            {
                if(govcomp[i] >0 && !ingov[i])
                {
                    cout << par_president[i] << " (" << names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")"<< ": " << govcomp[i] << "%" << endl;
                }
                
            }
        }
    }
    cout << endl;
        cout << "\n==========\n" << endl;
    

    cout << "Government Coalition: " << govseats << " seats" << endl;
    for(int i=0; i!=10; i++)
    {
        if(par_seats[i] > 0 && ingov[i] == true)
        {
            cout << par_president[i] << " (" << names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")"<< ": " << par_seats[i] << " seats"<< endl;
        }
        
    }
    cout << "\n==========\n" << endl;
    if(opposeats >0)
    {
        cout << "Opposition Coalition: " << opposeats << " seats" << endl;
        for(int i=0; i!=10; i++)
        {
            if(par_seats[i] > 0 && ingov[i] == false)
            {
                cout << par_president[i] << " (" << names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old"  << ")"<< ": " << par_seats[i] << " seats"<< endl;
            }
        }
    }
    
    
    cout << endl;
    for(int i=0; i!=10; i++)
    {
        if(par_seats[i] >0)
        {
            cout << par_president[i] << " (" <<names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")" << ": " << par_seats[i] << " seats" << endl;
            if(prelec == true && par_electors[i] >0)
            {
                cout << par_electors[i] << " / " << tot_elec << " electoral votes" << endl;
            }
            cout << par_votes[i] << " votes (" << par_votes_percent[i] << "%)" << endl;
            for(int b=0; b!= par_votes_percent[i]/2; b++)
            {
                cout << "|";
            }
            cout << endl;
            cout << endl;
        }
    }
}

void disp_pres()
{
    cout << endl;
    cout << "President: " << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << pressideo<< " | " << presbg << " | " << age[presnum] << " Years old" << " | Elected: " << yelect << endl;
    cout << "Prime Minister: " << primem << " (" << names[par_ideology[pmnum]][par_name[pmnum]]<< " | " << ideologies[par_ideology[pmnum]][par_subideology[pmnum]] << " | " << age[pmnum] << " Years old" << ")" << endl;
    cout << endl;

    for(int i=0; i!=10; i++)
    {
        if(par_electors[i]>0)
        {
            cout << par_president[i] << " (" <<names[par_ideology[i]][par_name[i]] << " | " << ideologies[par_ideology[i]][par_subideology[i]] << " | " << backg[par_bg[i]] << " | " << age[i] << " Years old" << ")" << ": " << par_electors[i]<< " / " << tot_elec << " electoral votes" << endl;
                cout << par_votes[i] << " votes (" << par_votes_percent[i] << "%)" << endl;
                for(int b=0; b!= par_votes_percent[i]/2; b++)
                {
                    cout << "|";
                }
                cout << endl;
                cout << endl;
        }
        
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
    if(prelec)
    {
        preselec();
    }
    if(midterm)
    {
        //cout << "R";
        seatdistrib();
        //cout << "E";
        coalitionform();
        
        govform();
        
        govcompcalc();
        
        
        checkmajors();
    }
    
    /*for(int i=0; i!=10; i++)
    {
        cout <<names[par_ideology[i]][par_name[i]] << endl;
        cout << par_president[i] << "\n" << par_primem[i] << endl;
        cout << ideologies[par_ideology[i]][par_subideology[i]] << endl;
        cout << "\n==========\n" << endl;
    }*/
    if(midterm == true && prelec == false)
    {
        cout << year << " Parliamentary Election" << endl;
        disp_parlo();
    }else if (midterm == false && prelec == true)
    {
        cout << year << " Presidential Election" << endl;
        disp_pres();
    }else if(midterm == true && prelec == true){
        cout << year << " General Election" << endl;
        disp_parlo();
    }
    //cout<< "\n\nAverage Development Level: " << avdev << "%" << endl;
    cout << "The Economy is ";
    switch(estatus/25)
    {
        case 4:
            cout << "Booming" << endl;
            break;
        case 3:
            cout << "Booming" << endl;
            break;
        case 2:
            cout << "Rapidly Growing" << endl;
            break;
        case 1:
            cout << "Steadily Growing" << endl;
            break;
        case 0:
            cout << "Stable" << endl;
            break;
        case -1:
            cout << "Stagnating" << endl;
            break;
        case -2:
            cout << "Receding" << endl;
            break;
        case -3:
            cout << "Depressing" << endl;
            break;
        case -4:
            cout << "Depressing" << endl;
            break;
    }
    //cout << estatus << endl;
    
    kami:
    
    cin >> unput;
    if(unput == "display")
    {
        for(int i=0; i!= presidents; i++)
        {
            cout << preshistory[i+counted] << endl;
        }
        cout << president << " (" << names[par_ideology[presnum]][par_name[presnum]] << " | " << pressideo<< " | " << presbg<< " | " << age[presnum] << ") " << yelect << " - Present" << endl;
        goto kami;
    } else if (unput == "govs")
    {
        for(int i=0; i!= govs; i++)
        {
            cout << ghistory[i+counted] << endl;
        }
        cout << president << " - " << primem << " Government (" << govyear << " - Present) - ";
        if(govinpower)
        {
            cout <<"Pro-President Government" << endl;
        } else
        {
            cout <<  "Opposition Government" << endl;;
        }
        goto kami;
    }
    
    if(midterm)
    {
        checkrun();
    }
    if(parallel == false)
    {
        eco();
        update();
        
    }
    timeup();
    goto game;
    return 0;
}
