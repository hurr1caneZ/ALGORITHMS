#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
 
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
 
 
void heapsort(int a[], int n)
{
 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
 
 
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
 
        heapify(a, i, 0);
    }
}
 
int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++) { fin >> arr[i]; }
    heapsort(arr, n);
    for (int i = 0; i < n; i++) { fout << arr[i] << " "; }
    fin.close();
    fout.close();
    return 0;
}