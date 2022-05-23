#include "ChildProcess.hpp"

#include <chrono>
#include <thread>
#include <csignal>
#include <iostream>

ChildProcess cp;

void SignalHandler(int signum){
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    cp.fileWrite();
    std::cout << "Program gracefully finished!\n";
    exit(signum);  
}


int main(int argc, char *argv[])
{
    std::cout << "Starting \"Child\" process" << std::endl;

    std::signal(SIGINT, SignalHandler);
    std::signal(SIGTERM, SignalHandler);  
    try
    {
        cp.setCounter(cp.fileRead());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    int input = 0;
    try
    {
        input = std::stoi(argv[1]);
        if(input < 1 || input > 1000)
        {
            throw std::logic_error("Unexpected input");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    while(1)
    {
        cp.counterIncrease();
        std::cout << cp.getCounter() << "\n";
        const std::chrono::milliseconds period(input);
        std::this_thread::sleep_for(period);
    }  
    cp.fileWrite();
    return 0;
}
