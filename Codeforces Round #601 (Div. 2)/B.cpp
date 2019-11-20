#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100050
#define mod 1000000007
using namespace std;
ll super_max=9000000000000000000;

void solv()
{
    ll n, m;
        cin>>n>>m;
        ll arr[n], tarr[n];
        for(ll i=0; i<n; i++){
                cin>>arr[i];
                tarr[i]=arr[i];
        }
        sort(tarr, tarr+n);
        ll a1, a2;
        for(ll i=0; i<n; i++){
            if(arr[i]==tarr[0]){
                a1=i+1;
                break;
            }
        }
        for(ll i=0; i<n; i++){
            if(i==a1-1)continue;
            if(arr[i]==tarr[1]){
                a2=i+1;
                break;
            }
        }
        ll ans=0;
        vector<ll>v;
        if(n==2)cout<<-1<<endl;
        else if(m<n)cout<<-1<<endl;
        else{
            ll tm=m;
            ll co=1;
            for(ll i=1; i<n; i++){
                v.push_back(i);
                v.push_back(i+1);
                ans+=arr[i-1]+arr[i];
                //cout<<i<<" "<<i+1<<endl;
                m--;
            }
            v.push_back(n);
            v.push_back(1);
            ans+=arr[0]+arr[n-1];
            //cout<<n<<" "<<1<<endl;
            m--;
            while(m--){
                v.push_back(a1);
                v.push_back(a2);
                ans+=arr[a1-1]+arr[a2-1];
                //cout<<a1<<" "<<a2<<endl;
            }
            cout<<ans<<endl;
            for(ll i=0; i<v.size()-1; i+=2){
                cout<<v[i]<<" "<<v[i+1]<<endl;
            }

        }

}
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--)
    {
        solv();
    }






    return 0;
}

