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
    ll rvr, wd, jmp;
    cin>>rvr>>wd>>jmp;
    ll arr[wd];
    for(ll i=0; i<wd; i++)cin>>arr[i];
    ll sum[wd+5];
    sum[wd]=0;
    for(ll i=wd-1; i>=0; i--){
        sum[i]=sum[i+1]+arr[i];
    }
    ll ned=rvr-sum[0];
    if(ned>(jmp-1)*(wd+1) ){cout<<"NO"<<endl; return 0; }
    ll ans[rvr];
    memset(ans, 0, sizeof ans);
    ll an=0;
    for(ll i=0; i<wd; i++){
        ll tjmp=jmp-1;
        while(tjmp>0 && ned>0){
            ans[an++]=0; ned--; tjmp--;
        }
        tjmp=arr[i];
        while(tjmp>0){
            ans[an++]=i+1; tjmp--;
        }
    }
    cout<<"YES"<<endl;
    for(ll i=0; i<rvr; i++)cout<<ans[i]<<" ";


    return 0;
}
