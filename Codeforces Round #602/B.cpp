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
    ll n, q=0;
    cin>>n;
    bool flg[n+5];
    ll arr[n];
    memset(flg, false, sizeof flg );
    for(ll i=0; i<n; i++)cin>>arr[i];
    ll mx=arr[0], po=1;
    flg[arr[0] ]=true;
    vector<ll>ans;
    ans.push_back(arr[0]);
    for(ll i=1; i<n; i++){
        if(arr[i]>mx){ ans.push_back(arr[i]); mx=arr[i]; flg[arr[i]]=true; }
        else{
            while(flg[po]==true)po++;
            if(po>arr[i]){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(po);
            flg[po]=true;
        }
    }
    for(ll i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
    cout<<endl;
    return;


}
int main()
{
    IOS
    ll test;
    cin>>test;
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
