#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void cevents( int ID)
{
    switch(ID)
    {
        case 1: cout << "1 - Support Amy, 2 - Support Jane" << endl;
        break;
        case 2: cout << "1 - Support Amy, 2 - Support Jane" << endl;
        break;
        case 3: cout << "1 - Support Amy, 2 - Support Jane" << endl;
        break;
        case 4: cout << "1 - Support Amy, 2 - Support Jane" << endl;
        break;
    }
}

int evresults(int ID, int choice)
{
    switch(ID)
    {
        case 1:
        if(choice ==1)
        {
            return 1;
        } else
        {
            return 2;
        }
        break;
        case 2:
        if(choice ==1)
        {
            return 1;
        } else
        {
            return 2;
        }
        break;
        case 3:
        if(choice ==1)
        {
            return 1;
        } else
        {
            return 2;
        }
        break;
        case 4:
        if(choice ==1)
        {
            return 1;
        } else
        {
            return 2;
        }
        break;
    }
    return 0;
}



int main()
{
    srand(time(NULL));
    int eventId = 1;
    int unput =0;
    int Amy =10, Jane =10, frustration =75;
    int Balance = 50; 
    int k =Amy+Jane;
    int rs =0;
    for(int i=1; i!=5; i++)
    {
        cevents(i);
        cin >> unput;
        rs = evresults(i, unput);
        if(rs == 1) {Amy+=10;} else{Jane+=10;}
    }
    
    while(1 <5)
    {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "==========================================================================================" << endl;
    cout << "Amy's Influence: " << Amy << "          " << "Jane's Influence: " << Jane << endl;
    cout << "Balance of Power: " << Balance << " (0 == total Amy Control, 100 = total Jane Control)" << endl;
    cout << endl;
    cout << "Principal's Frustration: " << frustration << endl;
    cout << "==========================================================================================" << endl;
    cout << "1 = Intervene in Amy's side (+10 BOP to Amy, +5 frustration)" << endl;
    cout << "2 = Intervene in Jane's side (+10 BOP to Jane, +5 frustration)" << endl;
    cout << "3 = Call an early recess (+10 Amy Influence, +10 frustration)" << endl;
    cout << "4 = Delay the recess (+10 Jane Influence, +10 frustration)" << endl;
    cout << "5 = Do nothing (-5 frustration)" << endl;
    cout << endl;
    cin>> unput;
    switch(unput)
    {
        case 1:
        Balance -= 10;
        frustration +=5;
        break;
        case 2:
        Balance += 10;
        frustration += 5;
        break;
        case 3:
        Amy += 10;
        frustration += 10;
        break;
        case 4:
        Jane += 10;
        frustration += 10;
        break;
        default:
        break;
    }
    int j = rand()%k;
    if(j < Amy)
    {
        if(Amy >0)
        {
            Balance-=5;
            Amy -= 5;
        }
    } else
    {
        if(Jane >0)
        {
            Balance += 5;
            Jane -= 5;
        }
    }
    frustration -= 5;
    
    if(frustration >= 100)
    {
        cout << "Principal Intervention" << endl;
        break;
    }
    if(frustration <0)
    {
        frustration = 0;
    }
    if(Balance <=0)
    {
        cout << "Amy victory" << endl;
        break;
    }
    if(Balance >=100)
    {
        cout << "Jane Victory" << endl;
        break;
    }
    
    }
    
    return 0;
}
