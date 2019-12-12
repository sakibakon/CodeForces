#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
ll super_max=9000000000000000000;
ll poww(ll base, ll power_number );///return (base ^ power_number);
ll big_mod(ll b, ll p, ll m); ///return (b^p)%m;
ll mod_string_number(string str, ll mod_num); ///return str%mod_num;
void fun()
{
    ll l=0, r=0, u=0, d=0;
    string s;
    cin>>s;
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='U')u++;
        if(s[i]=='D')d++;
        if(s[i]=='L')l++;
        if(s[i]=='R')r++;
    }
    u=min(u, d);
    l=min(l,r);
    if(u==0 && l>0){cout<<2<<endl; cout<<"LR"<<endl; }
    else if(l==0 && u>0){ cout<<2<<endl; cout<<"UD"<<endl; }
    else if(l==0 && u==0)cout<<0<<endl;
    else{
        cout<<(2*l)+(2*u)<<endl;
        for(ll i=0; i<u; i++)cout<<"U";
        for(ll i=0; i<l; i++)cout<<"R";
        for(ll i=0; i<u; i++)cout<<"D";
        for(ll i=0; i<l; i++)cout<<"L";
        cout<<endl;
    }

}
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--)fun();
    return 0;
}

///All are Function
ll poww(ll base, ll power_number )
{
  ll num1=1;
  for(ll j=1; j<=power_number; j++)num1*=base;
  return num1;
}
ll big_mod(ll b, ll p, ll m)
{
    if(p==0)return 1;
    if(p%2==0){
        ll c = big_mod(b, p/2, m);
        return ( (c%m)*(c%m) )%m;
    }
    else{
        return ((b%m)*(big_mod(b, p-1, m)))%m;
    }
}
ll mod_string_number(string str, ll mod_num)
{
    ll res = 0;
    for (ll i = 0; i < str.length(); i++)
         res = (res*10 + (ll)str[i] - '0') %mod_num;
    return res;
}
