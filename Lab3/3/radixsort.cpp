#include <fstream>
using namespace std;
 
string a[1000], arr[1000];
 
void radixsort(int ii, int n1)
{
    char z = 'a';
    int k = 0;
    for (int i = 0; i <= 26; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (a[j][ii] == z)
            {
                arr[k] = a[j];
                k++;
            }
        }
        z++;
    }
    for (int i = 0; i < n1; i++) { a[i] = arr[i]; }
}
 
int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    long n, m, k;
    fin >> n >> m >> k;
    for (int i = 0; i < n; i++) { fin >> a[i]; }
    for (int i = m - 1; i >= m - k; i--) { radixsort(i, n); }
    for (int i = 0; i < n; i++) { fout << a[i] << '\n'; }
    return 0;
}