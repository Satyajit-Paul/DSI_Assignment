#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED


#include <bits/stdc++.h>

using namespace std;

class Instruction
{
protected:
    string s;
public:
    Instruction();
    Instruction(string s);
    void setter(string s);
    string getter();
    bool isValid();
    bool isValidOperator(string optr);
    ~Instruction();
};

#endif // INSTRUCTION_H_INCLUDED
