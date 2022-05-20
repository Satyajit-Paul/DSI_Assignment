#include <bits/stdc++.h>
#include "instruction.h"

using namespace std;

int main()
{
    /**
    Instruction *instruction1, *instruction2;
    instruction1 = new Instruction();
    instruction2 = new Instruction("I Love You");
    instruction1->setter("KUET");


    cout << "The 1st Instruction: " << instruction1->getter() << endl;
    cout << "The 2nd Instruction: " << instruction2->getter() << endl;

    Instruction ins("My Name Is Khan !!!");
    cout << "The 3rd Instruction: " << ins.getter() << endl;

    Instruction *temp;
    temp = instruction1;

    ///delete instruction1;

    cout << "Value of temp: " << temp->getter() << endl;

    ///delete instruction2;

    ///instruction = new Instruction();
    ///instruction
    ///instruction = new Instruction();
    **/
    fstream file;

    file.open("input.txt", ios :: in);

    if(file.is_open())
    {
        string s;

        while(getline(file, s))
        {
            ///cout << s << endl;
            ///s += ' ';
            Instruction *instruction;
            instruction = new Instruction(s);

            if(instruction->isValid())
            {
                fstream writer;

                writer.open("output.txt", ios :: app);

                if(writer.is_open())
                {
                    writer << instruction->getter() << endl;

                    writer.close();
                }
                else
                {
                    cout << "Output file is not opened !!!" << endl;
                }


            }

            delete instruction;
        }

    }
    else
    {
        cout << "The file is not opened !!!" << endl;
    }

    file.close();

    return 0;
}
