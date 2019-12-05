#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
void fun()
{
    ll n;
    cin>>n;
    ll array_a[n];
    for(ll i=0; i<n; i++)cin>>array_a[i];
    ll g=1, s=1, b=0;
    if(n<6){ cout<<0<<" "<<0<<" "<<0<<endl; return;}
    for(ll i=1; i<n/2; i++){
        while(array_a[i]==array_a[i-1] && i<n/2){ g++; i++; }
        i++;
        while( (array_a[i]==array_a[i-1] || s<=g) && i<n/2){ s++; i++; }
        while(i<n/2){ b++; i++; }
        break;
    }
    ll po=g+s+b;
    ll fk=po-1;
    while(array_a[po]>=array_a[fk] ){b--; fk--; }
    if(g<b && g<s ){
        cout<<g<<" "<<s<<" "<<b<<endl;
    }
    else cout<<0<<" "<<0<<" "<<0<<endl;
}
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--)fun();
    return 0;
}
