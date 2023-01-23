#include <iostream>
using namespace std;


void print_arg(string strArg);


int main(int arg_count, char *args[]) {

    if (arg_count > 1) {
        string name(args[1]);
        print_arg(name);
    }
    else
    {
        std::cout<<"no arguments received."<<std::endl;
    }
    return 0;
}


void print_arg(string strArg) {
    cout<<"****************"<<endl;
    cout<<strArg<< std::endl;
    cout<<"****************"<<endl;
}