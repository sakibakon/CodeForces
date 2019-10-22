/*{
    input:
    3 1
    2 1
    2 9
    2 7
    1 5
    output:
    1 5
    2 9
    2 7
    2 1
    3 1
}*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> arr, a, p;
bool comp(const ll& x, const ll& y )
{
    if(a[x] != a[y] )return a[x]<a[y];
    return p[x]>p[y];
}
int main()
{

    for(ll i=0; i<5; i++ ){
        ll x, y;
        cin>>x>>y;
        arr.push_back(i);
        a.push_back(x);
        p.push_back(y);
    }
    sort(arr.begin(), arr.end(), comp);
    for(ll i=0; i<5; i++ ){
        cout<<a[arr[i] ]<<" "<<p[arr[i]]<<endl;
    }
}
