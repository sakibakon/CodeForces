#include<bits/stdc++.h>
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
priority_queue<ll, vector<ll>, greater<ll> >q;
vector<ll>gr[100005], ans;
bool visit[100005];
ll node, ver;
void bfs()
{
    memset(visit, false, sizeof visit);
    q.push(1);
    visit[1]=true;
    while(!q.empty()){

        ll u=q.top();
        q.pop();
        ans.push_back(u);

        for(ll i=0; i<gr[u].size(); i++){
            if( visit[ gr[u][i] ]==false ){
                visit[gr[u][i] ]=true;
                q.push( gr[u][i] );
            }
        }

    }

}
int main()
{
    IOS
    cin>>node>>ver;
    for(ll i=0; i<ver; i++){
        ll a, b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    bfs();
    for(ll i=0; i<ans.size(); i++)cout<<ans[i]<<" ";



    return 0;
}

