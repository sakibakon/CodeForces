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
    ll test=1;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        string arr[n];
        bool co[10]={false};
        for(ll i=0; i<n; i++){
                cin>>arr[i];
                co[arr[i][0]-'0']=true;
        }
        int po=0, ans=0;
        for(ll i=1; i<n; i++){
            for(ll j=0; j<i; j++){
                if(arr[i]==arr[j]){
                    while(co[po]==true)po++;
                    arr[i][0]='0'+po;
                    ans++;
                    co[po]=true;
                    break;
                }
            }
        }
        cout<<ans<<endl;
        for(ll i=0; i<n; i++)cout<<arr[i]<<endl;
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
