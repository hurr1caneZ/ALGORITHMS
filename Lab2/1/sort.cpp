#include <fstream>
#include <iostream>
 
using namespace std;
 
 
long n, result[30000000], a[30000000];
 
void mergeSort(long left, long right)
{
    if (left < right)
    {
        long mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        long i = 0, j = 0;
        while (left + i <= mid && mid + 1 + j <= right)
        {
            if (a[left + i] > a[mid + 1 + j])
            {
                result[i + j] = a[mid + 1 + j];
                j++;
            }
            else
            {
                result[i + j] = a[left + i];
                i++;
            }
        }
        while (left + i <= mid)
        {
            result[i + j] = a[left + i];
            i++;
        }
 
        while (mid + 1 + j <= right)
        {
            result[i + j] = a[mid + 1 + j];
            j++;
        }
 
        for (i = 0; i < right - left + 1; i++)
        {
            a[left + i] = result[i];
        }
    }
}
 
int main()
{
    ifstream fin; fin.open("sort.in");
    ofstream fout; fout.open("sort.out");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        fout << a[i] << ' ';
    }
    fin.close();
    fout.close();
    return 0;
}