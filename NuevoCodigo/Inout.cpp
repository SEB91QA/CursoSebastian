
#include<iostream>

int main(int argc, char *argv[])
{


    std::cout << argc << std::endl;

    for(int i = 0; i < argc; i++) std::cout << argv[i] << std::endl;

    int param1 = atoi(argv[1]);
    float param2 = std::stof(argv[2]);
    std::string param3 = argv[3];


    std::cout << " "  << param1 << " "  << param2 << " " << param3 << std::endl;


    return 0;

}
