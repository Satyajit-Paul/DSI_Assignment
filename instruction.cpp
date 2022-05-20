#include <bits/stdc++.h>
#include "instruction.h"


using namespace std;

/**
bool operadSeparator(char ch)
{
    bool checker;

    if(ch == ',')
    {
        checker = true;
    }
    else
    {
        checker = false;
    }

    return checker;
}

bool endOperad(char ch)
{
    bool checker;

    if(ch == ' ' || ch == '\n' || ch == '#')
    {
        checker = true;
    }
    else
    {
        checker = false;
    }

    return checker;
}
**/

bool isNumber(string s)
{
    bool b, checker;

    b = true;

    for(int i = 0; i < s.size(); i++)
    {
        if(!(s[i] >= 48 && s[i] <= 57))
        {
            b = false;
        }
    }

    if(b)
    {
        checker = true;
    }
    else
    {
        checker = false;
    }

    return checker;
}

bool isRegister(string s)
{
    bool b1, b2, checker;

    if(s[0] >= 97 && s[0] <= 122)
    {
        b1 = true;
    }
    else
    {
        b1 = false;
    }

    b2 = true;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9')
        {
            b2 = false;
        }
    }

    if(b1 && b2)
    {
        checker = true;
    }
    else
    {
        checker = false;
    }

    return checker;
}

bool isValidOperand(string s)
{
    bool checker;

    checker = false;

    if(s[s.size() - 1] == ',' || s[s.size() - 1] == '\n' || s[s.size() - 1] == ' ' || s[s.size() - 1] == '#')
    {
        s.erase(s.end() - 1);

        if(isNumber(s) || isRegister(s))
        {
            checker = true;
        }
        else
        {
            checker = false;
        }
    }

    return checker;
}


Instruction :: Instruction()
{
    this->s = "";
    ///cout << "Default Constructor Invoked!!!" << endl;
}

Instruction :: Instruction(string s)
{
    this->s = s;
    ///cout << "Parameterized Constructor Invoked!!!" << endl;
}

void Instruction :: setter(string s)
{
    this->s = s;
}

string Instruction :: getter()
{
    return this->s;
}

Instruction :: ~Instruction()
{
    ///cout << "Destructor Invoked !!!" << endl;
}

bool Instruction :: isValid()
{
    bool checker;

    if(this->s[0] == '#')
    {
        checker = false;
    }
    else
    {
        stringstream ss(this->s);

        string optr;
        ss >> optr;

        if(isValidOperator(optr))
        {
            vector <string> oprnd;
            string temp;


            if(optr == "add" || optr == "addi" || optr == "sub" || optr == "subi")
            {
                while(ss >> temp)
                {
                    oprnd.push_back(temp);
                }

                if(oprnd.size() == 3)
                {
                    int count = 0;
                    oprnd[2] += ' ';

                    for(int i = 0; i < 3; i++)
                    {
                        if(isValidOperand(oprnd[i]))
                        {
                            count++;
                            ///cout << oprnd[i] << endl;
                        }
                    }

                    if(count == 3)
                    {
                        checker = true;
                    }
                    else
                    {
                        checker = false;
                    }
                }
                else
                {
                    checker = false;
                }
            }
            else if(optr == "la" || optr == "li")
            {
                while(ss >> temp)
                {
                    oprnd.push_back(temp);
                }

                if(oprnd.size() == 2)
                {
                    int count = 0;
                    oprnd[1] += ' ';

                    for(int i = 0; i < 2; i++)
                    {
                        if(isValidOperand(oprnd[i]))
                        {
                            count++;
                        }
                    }

                    if(count == 2)
                    {
                        checker = true;
                    }
                    else
                    {
                        checker = false;
                    }
                }
                else
                {
                    checker = false;
                }
            }
            else
            {
                while(ss >> temp)
                {
                    oprnd.push_back(temp);
                }

                if(oprnd.size() == 0)
                {
                    checker = true;

                    /**
                    cout << "The Operands are: ";
                    for(int i = 0; i < 0; i++)
                    {
                        cout << oprnd[i] << " ";
                    }
                    cout << endl;
                    **/
                }
                else
                {
                    checker = false;
                }
            }

        }
        else
        {
            checker = false;
        }
    }

    return checker;
}

bool Instruction :: isValidOperator(string optr)
{
    bool checker;
    if(optr == "add" || optr == "addi" || optr == "sub" || optr == "subi" || optr == "la" || optr == "li" || optr == "ecall")
    {
        checker = true;
    }
    else
    {
        checker = false;
    }

    return checker;
}


