#ifndef CHILD_H
#define CHILD_H

#include <fstream>

class ChildProcess
{
private:
    int counter;
    std::fstream file; 
    std::string file_name = "result.txt";
public:
    void counterIncrease();
    void fileWrite();
    int fileRead();
    int getCounter();
    void setCounter(int c);
    ~ChildProcess();
};

#endif
