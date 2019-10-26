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
ll trk[1000009];
int main()
{
    IOS
    ll test;
    cin>>test;
    memset(trk, 0, sizeof trk);
    while(test--)
    {
        ll n, k, d;
        cin>>n>>k>>d;
        //set<ll>st;
        ll arr[n+5], co=0;
       // memset(trk, 0, sizeof trk);
        ll mn=d+6;
        for(ll i=0; i<n; i++){
            cin>>arr[i];
            trk[ arr[i] ]++;
            if(i<d-1){
                if(trk[ arr[i] ]==1)co++;
                //st.insert(arr[i]);
            }
            else{
                if(trk[ arr[i] ]==1)co++;
                //st.insert(arr[i]);
                //ll sz=st.size();
                mn=min(mn, co);
                trk[ arr[i-d+1] ]--;
                if(trk[ arr[i-d+1] ]<=0){
                    //cout<<"erase "<<arr[i-d+1]<<" ";
                    //st.erase(arr[i-d+1]);
                    co--;
                }

            }
            if(i==n-1){
                ll tm=i-d+1;
                while(tm<n)trk[arr[tm++] ]=0;
            }
            //cout<<i<<" "<<mn<<endl;
        }
        cout<<mn<<endl;

    }



    return 0;
}
