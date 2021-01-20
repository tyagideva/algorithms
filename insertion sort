#include<iostream>
using namespace std;
int main()
{  
    int n,i,j,key,c=0;
    cout<<"Enter the size of the array :- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            c++;
            a[j+1]=a[j];
            j=j-1;
        }
        if(j>=0)
            c++;
        a[j+1]=key;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\nNumber of Comparisions :- "<<c;
    return 0;
}
