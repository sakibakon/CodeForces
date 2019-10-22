#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
const ll MOD = (ll)1e9+7;
using namespace std;
ll poww(ll base, ll po )
{
  ll ans=1;
  for(ll j=1; j<=po; j++)ans*=base;
  return ans;
}
int main()
{
    cout<<poww(3, 4);
}
