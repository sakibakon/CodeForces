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

int main()
{
    IOS
    ll a, b;
    cin>>a>>b;
    if(a==b){
        cout<<(10*a)+1<<" "<<(10*a)+2;
        return 0;
    }
    if(a+1==b){
        cout<<a<<" "<<b;
        return 0;
    }
    if(a==9 && b==1){
        cout<<9<<" "<<10;
        return 0;
    }
    cout<<-1;



    return 0;
}
