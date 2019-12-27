#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll super_max=9000000000000000000;
ll poww(ll base, ll power_number );///return (base ^ power_number);
ll big_mod(ll b, ll p, ll m); ///return (b^p)%m;
ll mod_string_number(string str, ll mod_num); ///return str%mod_num;
void fun()
{
    ll n, s;
    cin>>n>>s;
    ll t_arr[n+1], maxx=0, in=0, pr=0;
    ll summm=0;
    for(ll i=1; i<=n; i++){
            cin>>t_arr[i];
            summm+=t_arr[i];
    }
    if(summm<=s){
        cout<<0<<endl;
        return;
    }
    if(t_arr[1]>s && t_arr[2]>s){
        cout<<1<<endl;
        return;
    }
    summm=0; maxx=0; in=1, pr=1;
    for(ll i=1; i<=n; i++){
        summm+=t_arr[i];
        if(t_arr[i]>maxx){
            maxx=t_arr[i];
            pr=in;
            in=i;
        }
        if(summm-maxx==s){
            cout<<in<<endl;
            return;
        }
        if(summm-maxx>s){
            if(maxx==t_arr[i]){
                cout<<pr<<endl;
                return;
            }
            else{
                cout<<in<<endl;
                return;
            }
        }
    }
    cout<<in<<endl;

    return;
}
int main()
{
    IOS
    ll test=1;
    cin>>test;
   //cout<<test<<endl;
    while(test--){
        fun();
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
