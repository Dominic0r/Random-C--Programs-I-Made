#include <iostream>
using namespace std;

int Bars[5] = {5,5,5,5,5};
string inp = "";



int Bar1() //Extrovert - Introver E -  I
{
    int result =5;
    cout << "Do you feel energized by spending time with a large group of people" << endl; // Extrovert Question 1
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you feel drained after spending time in large social gatherings" << endl; // Introvert Question 1
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }
    
    
    cout << "Do you often initiate conversations in social settings" << endl; // Extrovert Question 2
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you prefer one-on-one conversations over group discussions" << endl; // Introvert Question 2
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you prefer brainstorming ideas with others rather than working alone" << endl; // Extrovert Question 3
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you often need time alone to recharge after being around people" << endl; // Introvert Question 3
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you enjoy attending parties and other social events regularly" << endl; // Extrovert Question 4
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you feel more comfortable expressing yourself through writing rather than speaking" << endl; // Introvert Question 4
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you find it easy to make new friends wherever you go" << endl; // Extrovert Question 5
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you prefer deep conversations with a few close friends rather than small talk with acquaintances" << endl; // Introvert Question 5
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }
    return result;
}

int Bar2() // Sensing - iNtuition S - N
{
    int result =5;
    
    cout << "Do you tend to focus on the details rather than the big picture" << endl; // Sensing Question 1
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you often think about future possibilities and potential outcomes" << endl; // Introvert Question 1
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you rely on your past experiences when making decisions" << endl; // Sensing Question 2
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you enjoy brainstorming creative ideas and exploring new concepts" << endl; // Intuition Question 2
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you enjoy hands-on activities that engage your senses" << endl; // Sensing Question 3
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you sometimes rely on your gut instincts when making decisions" << endl; // Intuition Question 3
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you prefer practical solutions to problems rather than exploring abstract ideas" << endl; // Sensing Question 4
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you enjoy discussing theories and abstract concepts" << endl; // Intuition Question 4
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you trust information that you can verify through your senses" << endl; // Sensing Question 5
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you tend to see patterns and connections between seemingly unrelated things" << endl; // Intuition Question 5
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    return result;
}

int Bar3() // Thinking - Feeling T - F
{
    int result =5;
    
    cout << "Do you prioritize logical reasoning and analysis when making decisions" << endl; // Thinking Question 1
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you prioritize harmony and empathy in your interactions with others" << endl; // Feeling Question 1
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you prefer to evaluate situations based on facts rather than emotions" << endl; // Thinking Question 2
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you often consider how your decisions will impact the feelings of those involved" << endl; // Feeling Question 2
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you find it easy to detach yourself emotionally when solving problems" << endl; // Thinking Question 3
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you find it easy to empathize with others and understand their perspectives" << endl; // Feeling Question 3
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you prefer giving feedback that focuses on objective criteria rather than personal opinions" << endl; // Thinking Question 4
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you prefer making decisions that align with your personal values and beliefs" << endl; // Feeling Question 4
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you believe it's important to maintain consistency and fairness in your decision-making" << endl; // Thinking Question 5
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you enjoy expressing your emotions openly and connecting with others on an emotional level" << endl; // Feeling Question 5
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    return result;
}

int Bar4() // Judging - Perception J - P
{
    int result =5;
    
    cout << "Do you prefer to have a clear plan and structure for your day" << endl; // Judging Question 1
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you enjoy adapting to new situations and embracing unexpected opportunities" << endl; // Perception Question 1
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you feel uncomfortable when things are left open-ended or unresolved" << endl; // Judging Question 2
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you often procrastinate on making decisions until the last minute" << endl; // Perception Question 2
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you like to make decisions quickly and efficiently" << endl; // Judging Question 3
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you find it easy to go with the flow and adjust your plans as needed" << endl; // Perception Question 3
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    
    cout << "Do you find it satisfying to check tasks off your to-do list as you complete them" << endl; // Judging Question 4
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "Do you enjoy exploring different options before settling on a final decision" << endl; // Perception Question 4
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    cout << "Do you prefer to follow a schedule rather than being spontaneous" << endl; // Judging Question 5
    cin>> inp;
    if(inp == "1")
    {
        result++;
    }
    cout << "" << endl; // Perception Question 5
    cin>> inp;
    if(inp == "0")
    {
        result--;
    }

    return result;
}


int main()
{
    string final="";
    Bars[0] = Bar1();
    Bars[1] = Bar2();
    Bars[2] = Bar3();
    Bars[3] = Bar4();
    
    if(Bars[0] >5)
    {
        final += "E";
    }else
    {
        final += "I";
    }
    
    if(Bars[1] >5)
    {
        final += "S";
    }else
    {
        final += "N";
    }
    
    if(Bars[2] >5)
    {
        final += "T";
    }else
    {
        final += "F";
    }
    
    if(Bars[3] >5)
    {
        final += "J";
    }else
    {
        final += "P";
    }
    
    cout << "Your Final Result is: " << final << endl;
}
