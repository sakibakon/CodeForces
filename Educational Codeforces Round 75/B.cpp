#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
ll super_min=9000000000000000000;
ll f_num=0;
ll poww(ll base, ll po )
{
  ll ans=1;
  for(ll j=1; j<=po; j++)ans*=base;
  return ans;
}
ll z=-1, o=-1;
isPalindrom(ll len, ll zero, ll one)
{
    if(len%2==0){
        if(one+zero==len && one%2==0 && zero%2==0){
            z=zero;
            o=one;
            return true;
        }
        else{
            if(one%2==0 && zero%2==0){
                z=zero;
                o=len-zero;
                return true;
            }
            if(one%2==1 && zero%2==0){
                z=zero;
                o=len-zero;
                if(o<=one)return true;
                else return false;
            }
            if(one%2==0 && zero%2==1){
                o=one;
                z=len-o;
                if(z<=zero)return true;
                else return false;
            }
            if(one%2==1 && zero%2==1){
                z=zero-1;
                o=len-z;
                if(o<=one)return true;
                else return false;
            }

        }
    }

}
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--){
        ll lenth[100];
        ll n, one=0, zero=0;
        cin>>n;
        vector<ll>jor, bijor;
        for(ll i=0; i<n; i++){
            string s;
            cin>>s;
            if(s.size()%2==0)jor.push_back(s.size());
            else bijor.push_back(s.size());
            for(ll j=0; j<s.size(); j++){
                if(s[j]=='0')zero++;
                else one++;
            }
        }
        ll k=0;
       // cout<<"ok"<<endl;
        for(ll mm=0; mm<jor.size(); mm++)lenth[k++]=jor[mm];
        for(ll mm=0; mm<bijor.size(); mm++)lenth[k++]=bijor[mm];
        //sort(lenth, lenth+n);
        //cout<<fun(0, zero, one);
       //for(ll i=0; i<n; i++)cout<<lenth[i]<<" ";
       // cout<<endl;
        ll ans=0;
        for(ll i=0; i<n; i++){
            //cout<<zero<<" "<<one<<endl;
            if(one>=lenth[i]){
                ans++;
                one-=lenth[i];
            }
            else if(zero>=lenth[i]){
                ans++;
                zero-=lenth[i];
            }
            else if(isPalindrom(lenth[i], zero, one)){
                ans++;
                one-=o;
                zero-=z;
            }
            z=-1; o=-1;

        }
    cout<<ans<<endl;
    }
    return 0;
}
