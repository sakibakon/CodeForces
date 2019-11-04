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
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        ll arr[n+5];
        arr[0]=0;
        for(ll i=1; i<=n; i++){
                cin>>arr[i];
        }
        ll co=n-1;
        bool flag[105];
        map<ll, map<ll, ll> >mp;
        memset(flag, false , sizeof flag);
        for(ll j=1; j<=n && co>0; j++){
            for(ll k=j; k<=n && co>0; k++){
                if(arr[k]==j){
                    while(arr[k]<arr[k-1] && co>0 && k>1){
                            if(!mp[k][k-1]){
                                    swap(arr[k], arr[k-1]);
                                    //flag[k]=true; flag[k-1]=true;
                                    mp[k][k-1]=1;
                                    k--;
                                    co--;
                            }
                            else break;
                    }
                    break;
                }
            }
            //if(co<0)break;
        }
        for(ll i=1; i<=n; i++)cout<<arr[i]<<" ";
        cout<<endl;



    }



    return 0;
}
