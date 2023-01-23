#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned char c = 0;
    unsigned int code = 0;

    cout <<"Enter a decimal char code : ";
    cin >> code;

    c = code;
    cout <<"The corresponding code is : " << c <<endl;

    //code = c;
    cout <<"Character codes :"
        <<"\nDecimal : " <<setw(3) << dec << code
        <<"\nOctal  : " <<setw(3) <<oct <<code
        <<"\nHexadec: " <<setw(3)<<hex <<code << endl;
        return 0;
}