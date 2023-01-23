#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int ac = 32;
    cout <<"\n          Char Dec Hex\n";
    
   int upper;

    for (upper = ac + 20; ac < upper && ac < 256; ++ac)
    {
        cout << "     " << (char)ac << setw(10) << dec << ac << setw(10) << hex << ac << endl;

        if (upper > 256 ) break;
    }
}
