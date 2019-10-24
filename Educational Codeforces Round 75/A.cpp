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
    for(ll i=0; i<test; i++){
        string s;
        cin>>s;
        ll chk[27];
        memset(chk, 0, sizeof chk);
        for(ll j=0; j<s.size(); j++){
            ll tm=0;
            while(s[j]==s[j+1] && j+1 < s.size() ){ tm++; j++; }
            ll lt=s[j]-'a';
            if(tm%2==0)chk[lt]=1;
            //cout<<tm<<" ";
        }
       // return 0;
        for(ll j=0; j<27; j++){
            char a='a'+j;
            if(chk[j])cout<<a;
        }
        cout<<endl;
    }



    return 0;
}
