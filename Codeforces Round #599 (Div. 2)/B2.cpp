#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
void functionn(ll test)
{
    vector<pair<ll, ll> >vector_my;
    ll n, k;
    cin>>n;
    k=2*n;
    string s1, s2;
    cin>>s1>>s2;
    for(ll i=0; i<n; i++){
        if(s1[i]==s2[i])continue;
        else{
            ll fl=0;
            for(ll j=i+1; j<n; j++){
                if(s1[i]==s1[j]){
                    swap(s2[i],s1[j]);
                    vector_my.push_back(make_pair(j, i));
                    fl=1;
                    break;
                }
            }
            for(ll j=i+1; j<n && fl== 0; j++){
                if(s1[i]==s2[j]){
                    swap(s2[j],s1[j]);
                    vector_my.push_back(make_pair(j, j));
                    swap(s2[i],s1[j]);
                    vector_my.push_back(make_pair(j, i));
                    break;
                }
            }


        }
    }
    if(vector_my.size()>2*n){cout<<"NO"; return; }
    for(ll i=0; i<n; i++){
        if(s1[i]!=s2[i]){ cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
    cout<<vector_my.size()<<endl;
    for(ll i=0; i<vector_my.size(); i++){
        cout<<vector_my[i].first+1<<" "<<vector_my[i].second+1<<endl;
    }

}
int main()
{
    IOS
    ll t=1, test=1;
    cin>>t;
    while(test<=t){ functionn(test); test++; }






    return 0;
}

