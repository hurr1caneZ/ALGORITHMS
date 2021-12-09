#include <fstream>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    ifstream fin("sortland.in");
    ofstream fout("sortland.out");
    fin >> n;
    int bedniyid, sredniyid, bogatiyid;
    double M[10000];
    for (int i = 0; i < n; i++)
    {
        fin >> M[i];
    }
    double sort[10000];
    for (int i = 0; i < n; i++)
    {
        sort[i] = M[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && sort[j - 1] > sort[j]; j--)
        {
            swap(sort[j - 1], sort[j]);
        }
    }
    double bedniy = sort[0], sredniy = sort[n / 2], bogatiy = sort[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (bedniy == M[i])
        {
            bedniyid = i;
        }
        if (sredniy == M[i])
        {
            sredniyid = i;
        }
        if (bogatiy == M[i])
        {
            bogatiyid = i;
        }
    }
    fout << bedniyid + 1 << " " << sredniyid + 1 << " " << bogatiyid + 1;
    fin.close();
    fout.close();
    return 0;
}