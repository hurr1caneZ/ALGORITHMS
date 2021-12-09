#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream fin("aplusb.in");
    ofstream fout("aplusb.out");
    int a;
    int b;
    fin>>a>>b;
    fout<<a+b;
    return 0;
}