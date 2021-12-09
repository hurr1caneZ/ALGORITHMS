#include <iostream>
#include <fstream>
#include <vector>
#include <string>
 
using namespace std;
 
int func_hash(int x)
{
    return x = abs(x % 100001);
}
 
int exists(vector< vector<int> >& hash_table, int x)
{
    int hash = func_hash(x);
    for (int i : hash_table[hash])
    {
        if (i == x)
        return 0;
    }
    return 1;
}
 
void insert(vector< vector<int> >& hash_table, int x)
{
    int hash = func_hash(x);
    if (exists(hash_table, x) == 1)
        hash_table[hash].push_back(x);
}
 
void deleted(vector< vector<int> >& hash_table, int x)
{
    int hash = func_hash(x);
    for (int i = 0; i < hash_table[hash].size(); i++)
    {
        if (hash_table[hash][i] == x)
        {
            hash_table[hash].erase(hash_table[hash].begin() + i);
            break;
        }
    }
}
 
int main()
{
    ifstream fin("set.in");
    ofstream fout("set.out");
    int n = 100001;
    vector < vector<int> > hash_table(n, vector<int>());
    string com;
    int x;
    while (fin)
    {
        fin >> com;
        if (!fin.eof())
        {
            if (com == "insert")
            {
                fin >> x;
                insert(hash_table, x);
            }
            else if (com == "delete")
            {
                fin >> x;
                deleted(hash_table, x);
            }
            else
            {
                fin >> x;
                if (exists(hash_table, x) == 0)
                    fout << "true\n";
                else
                    fout << "false\n";
            }
        }
    }
    return 0;
}