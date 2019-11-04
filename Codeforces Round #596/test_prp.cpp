#include<bits/stdc++.h>
using namespace std;
const int N = 2000007;
int count[N];
int a[N];
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		int n,k,d,ans=0,m=10000000;
		cin>>n>>k>>d;
		int count[k];
		//int a[n+1];
		for(i=1;i<=k;i++){
			count[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(i=1;i<=n;i++)
		{
			count[a[i]]++;
			if(count[a[i]]==1){
				ans++;
			}
			if(i-d>=0){
				m = min(m,ans);
			}
			if(i-d>=1){
				count[a[i-d]]--;
				if(count[a[i-d]]==0) ans--;
				m = min(m,ans);
			}
		}
		cout<<m<<endl;
	}
}
