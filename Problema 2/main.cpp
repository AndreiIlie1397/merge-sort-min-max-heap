/* C program for Merge Sort */
#include <iostream>
using namespace std;
int n, i;
void merge(int v[], int st, int mij, int dr)
{
    int i, j, k, n1=mij-st+1, n2=dr-mij;
    int L[n1], R[n2];
    for (i=0; i<n1; i++)
        L[i]=v[st+i];
    for (j=0; j<n2; j++)
        R[j]=v[mij+1+j];
    i=0;
    j=0;
    k=st;
    while(i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        v[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        v[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int v[], int st, int dr)
{
    if (st<dr)
    {
        int mij=(st+dr)/2;
        mergeSort(v, st, mij);
        mergeSort(v, mij+1, dr);
        merge(v, st, mij, dr);
    }
}
void afisare(int v[], int n)
{
    int i;
    for (i=0; i <n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    int *v=NULL;
    v=new int;
    cout<<"Introduceti numarul de elemente pe care doriti sa il sortati: ";
    cin>>n;
    cout<<"Introduceti elementele:"<<endl;
    for(i=0; i<n; i++)
        cin>>v[i];
    cout<<"Elementele nesortate:"<<endl;
    afisare(v, n);
    mergeSort(v, 0, n-1);
    cout<<"Elemetele sortate:"<<endl;
    afisare(v, n);
    delete []v;
    return 0;
}
