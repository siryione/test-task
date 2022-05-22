#include <boost/process/exe.hpp>
#include <boost/process/args.hpp>
#include <boost/process/system.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>

#include <cstdlib>
#include <iostream>


int main(int argc, char const *argv[])
{
    namespace po = boost::program_options;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("period", po::value<int>()->default_value(1000), "set counter increase period") 
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    int period = vm["period"].as<int>();
    if (vm.count("period"))
    {
        std::cout << "Counter increase period was set to "  << period << "ms.\n";
    } 
    else
    {
        std::cout << "Counter increase period was not set.\n";
    }
    while(1)
    {
        boost::process::system(boost::process::exe="./child", boost::process::args={std::to_string(period)});
    }
    return 0;
}
