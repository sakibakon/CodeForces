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
        ll n, q;
        cin>>n>>q;
        ll arr[n+5];
        arr[0]=0;
        string s;
        cin>>s;
        ll co=q;
        ll j=0;
        while(s[j]=='0' && j<n)j++;
        for(ll k=j; k<n && co>0; k++){
            if(s[k]=='0'){
                if(k-j<=co){
                    s[k]='1';
                   s[j]='0';
                    co-=k-j;
                    j++;
                }
                else{
                    s[k]='1';
                    s[k-co]='0';
                    break;
                }
            }
        }
        cout<<s<<endl;



    }



    return 0;
}
