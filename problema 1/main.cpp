#include <iostream>
using namespace std;
int max(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int n, s, t, p, i;
    int *v=NULL;
    v=new int;
    cout<<"Introduceti numarul de elemente ale sirului: ";
        cin>>n;
        cout<<"Introduceti elementele sirului:"<<endl;
        cin>>v[0];
        s=v[0];
        t=v[0];
        p=max(0, v[0]);
        for(i=1; i<n; i++)
        {
            cin>>v[i];
            t=max(v[i], t+v[i]);
            s=max(s, t);
            p=p+max(0, v[i]);
        }
        cout<<endl;
        cout<<"Suma numerelor din subsirul contiguu(subsirul cu cea mai mare suma): ";
        cout<<s<<endl;
        cout<<"Suma elemetelor din subsirul non-contiguu(suma nr pozitive): ";
        if(s<0)
            cout<<s;
        else
            cout<<p;
        cout<<endl;
        delete []v;
    return 0;
}
