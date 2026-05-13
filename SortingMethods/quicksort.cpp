#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
FILE *f=fopen("algsort.in","r");
ofstream g("algsort.out");
int v[500002],w[500002];

using namespace std;
int v[500002],w[500002];
void quicksort(int st,int dr)
{
    if( st < dr)
    {
        int i=st , j=dr , k , mij = (st+dr)/2,poz;
        for( k = st; k<=dr; k++)
        {
            if(v[k] < v[mij])
            {
                w[i++] = v[k];
            }
            else if( v[k] > v[mij])
            {
                w[j--] = v[k];
            }
        }
        for(k = i ; k <= j; k++)
            w[k] = v[mij];
        poz = (i+j)/2;
        for(i = st ; i <= dr; i++)
        {
            v[i] = w[i];
        }
        quicksort(st,poz);
        quicksort(poz+1,dr);
    }
}

int main()
{
    int n,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    quick_sort(1,n);
    for(i=1;i<=n;i++)
        g<<v[i]<<" ";
    return 0;
}