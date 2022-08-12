#include <iostream>
#include<cstring>
#include<Windows.h>
using namespace std;
class easy_level
{
protected:
    int word_len;   //riddle answer word lenght
    char* word;     //word (answer) through pointer
    string riddle, hint1;   //riddle and its hint(givibg length and vowels)
    char enter_word[20];    //word enter by player 
    int eword_len;          //length of ebtered word
    static int attempt;     //number of attempts provided
    static int right_attempt;   //right attempts
    static int wrong_attempt;       //wrong attempts
public:

    easy_level()        //default constructor
    {
        word_len = 0;
        word = NULL;
        riddle = "nohint";
        hint1 = "nohint";
        enter_word[0] = NULL;
        eword_len = 0;
    }
    easy_level(char* w, string r, string h)      //parameterized constructor
    {
        word = w;
        word_len = strlen(word);
        riddle = r;
        hint1 = h;
    }
    void input(char* w, string r, string h)       //data input fuction
    {
        word = w;
        word_len = strlen(word);
        riddle = r;
        hint1 = h;
    }
    void gameon()       //primary function
    {
    reenter:
        if (attempt == 0)
            goto stopp;
        cout << "\n\t\t\tGuess the word\n" << "Riddle :- \n\t * " << riddle << "\nHint :- \n\t  " << hint1 << endl;
        cin >> enter_word;
        eword_len = strlen(enter_word);
        if (eword_len == word_len)
        {
            int cmp = 0;
            for (int i = 0; enter_word[i] != NULL; i++)
            {
                if (enter_word[i] == word[i])
                    cmp++;
            }
            if (cmp == eword_len)
            {
                cout << "\nCongratulations! You guessed right word";
                right_attempt++;
                system("color 02");     //system("color BT");
            }
            else
            {
                wrong_attempt++;
                attempt--;
                system("color 0C");
                cout << "\a\nYou have entered wrong spellings or incorrect word and you have " << attempt << " more attempt to enter answers ";
                goto reenter;
            }
        }
        else
        {
            wrong_attempt++;
            attempt--;
            system("color 0C");
            cout << "\a\nYou have entered less characters and you have " << attempt << " more attempt to enter right answers ";
            goto reenter;
        }

    stopp:
        cout << endl;
    }
    void ouput()        //output function
    {
        cout << "\nWord is " << word << "\nLength=" << word_len << "\nHint is " << hint1 << "\nriddle is " << riddle;
    }
    static int getAttempt()     //gettor for attempts
    {
        return attempt;
    }
    static int getRAttempt()    //gettor for right attempts
    {
        return right_attempt;
    }
    static int getWAttempt()    //gettor for wrong attempts
    {
        return wrong_attempt;
    }
};
class medium_level :public easy_level       //Inherit class
{};
class hard_level :public easy_level      //Inherit class
{};
int easy_level::attempt = 3;        //assigning value to static variable
int easy_level::right_attempt = 0;
int easy_level::wrong_attempt = 0;

void display1()
{
    int secc = 500;

    cout << "\n\n\a\t\t\t\t\t ******=========================" << endl;
    cout << "\t\t\t\t\t |                 *                    *" << endl;
    cout << "\t\t\t\t\t |             WELCOME  TO              *" << endl;
    cout << "\t\t\t\t\t *          WORD RIDDLE GAME!           |" << endl;
    cout << "\t\t\t\t\t *                 *                    |" << endl;
    cout << "\t\t\t\t\t =========================******" << endl;
    system("color F1");     //system("color BT");
    Sleep(secc);            //time suspend
    system("color F2");
    Sleep(secc);
    system("color F3");
    Sleep(secc);
    system("color F4");
    Sleep(secc);
    system("color F5");
    Sleep(secc);
    system("color F6");
    Sleep(secc);
    system("color F8");
    Sleep(secc);
    system("color 02");
}
int main()
{
    system("color F0");     //system("color BT");
    display1();

    string arr[7] = { "The king of jungle","What has to be broken before you can use it?","I shave every day, but my beard stays the same. What am I?"," I am tall when I am young, and I am short when I’m old. What am I?","What can you break, even if you never pick it up or touch it?","What gets wet while drying?","The more of this there is, the less you see. What is it?" };
    string arr1[7] = { "*io*","e**","*a**a*","*a***e","**o*i*e","*o*e*","*a***e**" };
    char arr2[7][10] = { {'l','i','o','n'},
                        {'e','g','g'},
                        {'b','a','r','b','a','r'},
                         {'c','a','n','d','l','e'},
                        {'p','r','o','m','i','s','e'},
                        {'t','o','w','e','l'},
                        {'d','a','r','k','n','e','s','s'} };
    easy_level a[7];
    for (int i = 0; i <= 6; i++)
    {
        a[i].input(&arr2[i][0], arr[i], arr1[i]);
    }

    string arrr[7] = { "What is full of holes but still holds water?","What is always in front of you but cannot be seen?","David parents have three sons: Snap, Crackle, and what is the name of the third son?","What has one head, one foot and four legs?","What has a head and a tail but no body?","What building has the most stories?","A word I know, six letters it contains, remove one letter and 12 remains. What is it?" };
    string arrr1[7] = { "**o**e","*u*u*e","*avi*","*e*","*oi*","*i*a**","*o*e**" };
    char arrr2[7][10] = { {'s','p','o','n','g','e'},
                        {'f','u','t','u','r','e'},
                        {'d','a','v','i','d'},
                        {'b','e','d'},
                        {'c','o','i','n'},
                        {'l','i','b','r','a','r','y' },
                        { 'd','o','z','e','n','s' } };
    medium_level b[7];
    for (int i = 0; i <= 6; i++)
    {
        b[i].input(&arrr2[i][0], arrr[i], arrr1[i]);
    }

    string arra[7] = { "I am an odd number. Take away a letter and I become even. What number am I?","What can fill a room but takes up no space?"," If you drop me I am sure to crack, but give me a smile and I will always smile back. What am I?","People make me, save me, change me, raise me. What am I?","What can run but never walks, has a mouth but never talks, has a head but never weeps, has a bed but never sleeps?"," The person who makes it has no need of it; the person who buys it has no use for it. The person who uses it can neither see nor feel it. What is it?","I have lakes with no water, mountains with no stone and cities with no buildings. What am I?" };
    string arra1[7] = { "*e*e*","*i***","*i**o*","*o*e*","*i*e*","*o**i*","*a*" };
    char arra2[7][10] = { {'s','e','v','e','n'},
                            {'l','i','g','h','t'},
                            {'m','i','r','r','o','r'},
                            {'m','o','n','e','y'},
                            {'r','i','v','e','r'},
                            {'c','o','f','f','i','n'},
                            {'m','a','p'} };
    hard_level c[7];
    for (int i = 0; i <= 6; i++)
    {
        c[i].input(&arra2[i][0], arra[i], arra1[i]);
    }

start:
    cout << "\n\t\tChoose your Level \n\t1.Enter 'e' or 'E' for 'EASY LEVEL'\n\t2.Enter 'm' or 'M' for 'MEDIIUM LEVEL'\n\t3.Enter 'h' or 'H' for 'HARD LEVEL'\n";
    char level;
    cin >> level;
levelswitch:
    switch (level)
    {
    case 'e':
    case 'E':
        cout << "\t\t\t   EASY LEVEL\n";
        for (int o = 0; o <= 6; o++)
        {
            a[o].gameon();
        }
        if (easy_level::getAttempt() > 0)
        {
            char next_level;
        ask:
            cout << "\n\tDo you want to play next level ,if yes enter 'y'or 'Y' ,if no enter 'n' or 'N'\n";
            cin >> next_level;
            switch (next_level)
            {
            case 'y':
            case 'Y':
                level = 'm';
                goto levelswitch;
                break;
            case 'n':
            case 'N':
                goto endgame;
                break;
            default:
                goto ask;
                break;
            }
        }
    endgame:
        break;
    case 'm':
    case 'M':
        cout << "\t\t\t   MEDIUM LEVEL\n";
        for (int o = 0; o <= 6; o++)
        {
            b[o].gameon();
        }
        if (easy_level::getAttempt() > 0)
        {
            char next_level;
        ask1:
            cout << "\n\tDo you want to play next level ,if yes enter 'y'or 'Y' ,if no enter 'n' or 'N'\n";
            cin >> next_level;
            switch (next_level)
            {
            case 'y':
            case 'Y':
                level = 'h';
                goto levelswitch;
                break;
            case 'n':
            case 'N':
                goto endgame1;
                break;
            default:
                goto ask1;
                break;
            }
        }
    endgame1:
        break;
    case 'h':
    case 'H':
        cout << "\t\t\t   HARD LEVEL\n";
        for (int o = 0; o <= 6; o++)
        {
            c[o].gameon();
        }
        break;
    default:
        goto start;
        break;
    }

    int total_right = easy_level::getRAttempt();
    int total_wrong = easy_level::getWAttempt();
    char name[20];
    cout << "\n\t Enter yout name =";
    cin >> name;

    system("cls");
    system("color F6");
    cout << "\n\tname= " << name << "\t\tTotal right attempts= " << total_right << "\t\tTotal wrong attempts= " << total_wrong;

    return 0;
}