
#include <bits/stdc++.h>
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void fun()
{

}
int main()
{
    IOS
    ll test=1;
    cin>>test;
   //cout<<test<<endl;
    while(test--){
        ll n, s;
        cin>>n>>s;
        ll arr[n+1], mx=0, in=0, pr=0;
        ll sum=0;
        for(ll i=1; i<=n; i++){
                cin>>arr[i];
                sum+=arr[i];
        }
        if(sum<=s){
            cout<<0<<endl;
            continue;
        }
        if(arr[1]>s && arr[2]>s){
            cout<<0<<endl;
            continue;
        }
        ll f=0;
        sum=0; mx=0; in=1, pr=1;
        for(ll i=1; i<=n; i++){
            sum+=arr[i];
            if(arr[i]>mx){
                mx=arr[i];
                pr=in;
                in=i;
            }
            if(sum-mx==s){
                cout<<in<<endl;
                f=2;
                break;
            }
            if(sum-mx>s){
                if(mx==arr[i]){
                    cout<<pr<<endl;
                    f=2;
                    break;
                }
                else{
                    cout<<in<<endl;
                    f=2;
                    break;
                }
            }
        }
        if(f==0)cout<<in<<endl;

    }
    return 0;
}
