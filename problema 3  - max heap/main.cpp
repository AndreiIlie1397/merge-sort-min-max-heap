#include <iostream>
using namespace std;

void max_heap(int *a, int i, int n)
{
    int j, aux;
    aux=a[i];
    j=2*i;
    while (j<=n)
    {
        if (j<n && a[j+1]<a[j])
            j=j+1;
        if (aux<a[j])
            break;
        else if (aux>=a[j])
        {
            a[j/2]=a[j];
            j=2*j;
        }
    }
    a[j/2]=aux;
    return;
}
void heapsort(int *a, int n)
{
    int i, aux;
    for (i=n; i>= 2; i--)
    {
        aux=a[i];
        a[i]=a[1];
        a[1]=aux;
        max_heap(a, 1, i-1);
    }
}
void build_max_heap(int *v, int n)
{
    int i;
    for(i=n/2; i>=1; i--)
    {
        max_heap(v, i, n);
    }
}
int main ()
{
    int n, i, v[100];
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    for(i=1; i<=n; i++)
    {
    cout<<" Introduceti elementul: ";
    cin>>v[i];
    }
    build_max_heap(v, n);
    heapsort(v, n);
    for(i=1; i<=n; i++)
        cout<<v[i]<<" ";
    return 0;
}
