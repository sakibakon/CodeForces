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
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--){
        string s;
        ll f=0;
        cin>>s;
        if(s[0]=='?'){
            if(s[1]=='a')s[0]='b';
            else if(s[1]=='b')s[0]='a';
            else if(s[1]=='c')s[0]='a';
            else s[0]='a';
        }
        for(ll i=1; i<s.size()-1; i++){
            if(s[i]=='?' && s[i+1]=='?'){
                if(s[i-1]=='a')s[i]='b';
                else if(s[i-1]=='b')s[i]='a';
                else if(s[i-1]=='c')s[i]='a';
                continue;
            }
            else if(s[i]=='?' && s[i+1]!='?'){
                if( (s[i-1]=='a' && s[i+1]=='b') || (s[i+1]=='a' && s[i-1]=='b') )s[i]='c';
                else if((s[i-1]=='a' && s[i+1]=='c') || (s[i+1]=='a' && s[i-1]=='c'))s[i]='b';
                else if((s[i-1]=='c' && s[i+1]=='b') || (s[i+1]=='c' && s[i-1]=='b'))s[i]='a';
                else if(s[i-1]=='c' && s[i+1]=='c')s[i]='a';
                else if(s[i-1]=='b' && s[i+1]=='b')s[i]='a';
                else if((s[i-1]=='a' && s[i+1]=='a'))s[i]='b';
            }
        }
        if(s[s.size()-1 ]=='?'){
            ll i=s.size()-1;
            if(s[i-1]=='a')s[i]='b';
            else if(s[i-1]=='b')s[i]='a';
            else if(s[i-1]=='c')s[i]='a';
        }
        for(ll i=0; i<s.size()-1; i++){
            if(s[i]==s[i+1]){
                cout<<-1<<endl;
                f=1;
                break;

            }
        }
        if(f==0)cout<<s<<endl;


    }
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
