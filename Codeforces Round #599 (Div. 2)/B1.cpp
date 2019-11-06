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
    ll co=0, p1, p2;
    for(ll i=0; i<n; i++){
        char a, b, c, d;
        if(s1[i]!=s2[i] && co==0){
            a=s1[i];
            b=s2[i];
            co++;
            p1=i;
        }
        else if(s1[i]!=s2[i] && co == 1){
            c=s1[i];
            d=s2[i];
            if(a==c && b==d){
                s1[p1]=d;
                s2[i]=a;
            }
            break;
        }
    }
    //cout<<s1<<" "<<s2<<endl;
    for(ll i=0; i<n; i++){
        if(s1[i]!=s2[i]){ cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;


}
int main()
{
    IOS
    ll t=1, test=1;
    cin>>t;
    while(test<=t){ functionn(test); test++; }






    return 0;
}

