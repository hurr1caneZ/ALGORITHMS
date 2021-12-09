#include <iostream>
#include <fstream>
 
using namespace std;
int main()
{
    int count1;
    int zapis;
    int i,j;
    freopen ("smallsort.in", "r", stdin);
    freopen ("smallsort.out", "w", stdout);
    cin>>count1;
    int a[count1];
    for (i=0; i<count1; i++)
    {
        cin>>a[i];
    }
    for (i=0; i<count1-1; i++)
    {
        for (j=0; j<count1-1; j++)
        {
            if (a[j]>a[j+1])
            {   zapis=a[j];
                a[j]=a[j+1];
                a[j+1]=zapis;
            }
        }
    }
        for (i=0; i<count1; i++)
            cout<<a[i]<<endl;
}