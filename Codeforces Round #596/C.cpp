#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
ll super_max=9000000000000000000;
ll f_num=0;
ll poww(ll base, ll po )
{
  ll ans=1;
  for(ll j=1; j<=po; j++)ans*=base;
  return ans;
}
ll ans(ll n, ll p, ll co)
{
    ll mx=500;
    if(n==0 || co > 4)return co;
    for(ll i=0; i<29 ;i++){
        ll tmp=poww(2, i)+p;
        ll tn=n-tmp;
        mx=min(mx, ans(tn, p, co+1));
    }
    return mx;

}
int main()
{
    IOS
    ll n, p;
    cin>>n>>p;
    cout<<ans(n, p, 0);



    return 0;
}
