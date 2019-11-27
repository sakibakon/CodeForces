#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
void fun()
{
    string s;
        ll n, k;
        cin>>n>>k;
        cin>>s;
        char ch[2]={'(', ')' };
        vector<ll>ans;
        for(ll i=0; i<n; i++){
            char tem = ch[i%2];
            if(s[i]==tem)continue;
            ll p1=i+1, p2;
            for(ll j=i; j<n; j++){
                if(s[j]==tem){
                    p2=j+1;
                   // cout<<p1<<" "<<p2<<endl;
                    ans.push_back(p1); p1--;
                    ans.push_back(p2); p2--;
                    while(p1<=p2){swap(s[p1], s[p2]); p1++; p2--; }
                    break;
                }
            }
            //cout<<s<<endl;
        }
        ll tm=( (k)*2), kk=1;
        while(true){
            if(tm+kk>n-1)break;
            ans.push_back(tm);
            ans.push_back(tm+kk);
            kk++;
            tm++;
        }
        cout<<ans.size()/2<<endl;
        for(ll i=0; i<ans.size(); i+=2)cout<<ans[i]<<" "<<ans[i+1]<<endl;
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
