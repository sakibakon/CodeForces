/*==============================================*\
ID:          sakibakon

Name   : Md. Abu Sakib
Study  : CSTE, NSTU
Address: Gazipur, Dhaka, Bangladesh
Mail   : sakibakon1@gmail.com
FB     : Solaiman Rizbi Sakib
\*===============================================*/
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
    string s;
    cin>>s;
    ll ln=s.size();
    string s1;

    if(ln >=2){
        s1=s.substr(ln-2, 2);
        //cout<<s1<<endl;
        if(s1=="po"){cout<<"FILIPINO"<<endl;
        return;
        }
    }
    if(ln >=4 ){
        s1=s.substr(ln-4, 4);
        if(s1=="desu" || s1== "masu"){cout<<"JAPANESE"<<endl;
        return;}
    }
    if(ln >=5 ){
        s1=s.substr(ln-5, 5);
        if(s1=="mnida"){cout<<"KOREAN"<<endl;
        return;
        }
    }

    return;
}
int main()
{
    IOS
    ll test=1;
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
