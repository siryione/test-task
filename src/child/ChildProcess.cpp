#include "ChildProcess.hpp"


#include <string>
#include <vector>


ChildProcess::~ChildProcess()
{
    file.close();
}

void ChildProcess::setCounter(int c) {counter = c;}

void ChildProcess::fileWrite()
{
    file.open(file_name, std::ios_base::out | std::ios_base::trunc);
    if(file.is_open())
    {
        file << counter;
    }
}

int ChildProcess::fileRead()
{
    file.open(file_name, std::ios_base::in);
        if(file.is_open())
        {
            file >> counter;
            file.close();
        }
    return counter;
}

void ChildProcess::counterIncrease() {++counter;}
