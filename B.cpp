#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 100005
#define mod 1000000007
using namespace std;
struct point{
  ll x, y, z, arr_po;
};
ll sz[9];
//vector<point>ptn;
bool com_point(point a, point b)
{
    if(a.x<b.x)return true;
    if(a.x>b.x)return false;
    if(a.y<b.y)return true;
    if(a.y>b.y)return false;
    if(a.z<b.z)return false;
    return true;
}
int main()
{
    IOS
    ll test, n;
    cin>>n;
    point ptn[n+5];
    for(ll i=0; i<n; i++){
            ll a, b, c, cor=0;
            cin>>a>>b>>c;
            /*
            if(a>=0 && b>=0 && c>= 0)cor=0;
            if(a>=0 && b>=0 && c< 0)cor=1;
            if(a>=0 && b<0 && c>= 0)cor=2;
            if(a>=0 && b<0 && c< 0)cor=3;
            if(a<0 && b>=0 && c>= 0)cor=4;
            if(a<0 && b>=0 && c< 0)cor=5;
            if(a<0 && b<0 && c>= 0)cor=6;
            if(a<0 && b<0 && c< 0)cor=7;
            */
            ptn[i].x=a;
            ptn[i].y=b;
            ptn[i].z=c;
            ptn[i].arr_po=i+1;
    }
    sort(ptn, ptn+n, com_point );
    for(ll i=0; i<n; i++){
        if(ptn[i].arr_po==-1)continue;
        for(ll j=i+1; j<n; j++){
            ll flg=0;
            if(ptn[j].arr_po==-1)continue;
            for(ll k=i+1; k<n; k++){
                if(ptn[k].arr_po==-1)continue;
                if( (j==k && k != n-1) )continue;
                ll mx=max(ptn[i].x, ptn[j].x), my=max(ptn[i].y, ptn[j].y), mz=max(ptn[i].z, ptn[j].z);
                ll mix=min(ptn[i].x, ptn[j].x ), miy=min(ptn[i].y, ptn[j].y ), miz=min(ptn[i].z, ptn[j].z );
                ll xx=ptn[k].x, yy=ptn[k].y, zz=ptn[k].z;
                if( j != k && ((xx>=mix && xx<=mx) || (yy>=miy && yy<=my) || (zz>=miz && zz<=mz)) )break;
                if(j==n-1){
                    flg=1;
                    cout<<i+1<<" "<<j+1<<endl;
                    ptn[j].arr_po=-1;
                }
            }
            if(flg==1)break;
        }
    }
   // sort(ptn, ptn+n, com_point );

   // for(ll i=0; i<n; i++)cout<<ptn[i].x<<" "<<ptn[i].y<<" "<<ptn[i].z<<" "<<ptn[i].arr_po<<endl;
   // for(ll i=0; i<n; i+=2)cout<<ptn[i].arr_po<<" "<<ptn[i+1].arr_po<<endl;

    return 0;
}
