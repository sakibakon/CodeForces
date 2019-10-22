#include <bits/stdc++.h>
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define ll              long long
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define ull             unsigned long long
using namespace std;
string s1,s2, ans;
ll dp[35][35];
ll dp2[35][35][65];
ll sz1,sz2,len;
ll LCS(ll i, ll j)
{
    if(i>=sz1 || j>=sz2)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    ll ret=0;
    if(s1[i]==s2[j]){ ret=1+LCS(i+1,j+1); }
    else { ret=max(LCS(i+1,j),LCS(i,j+1)); }
    dp[i][j]=ret;
    return dp[i][j];
}
/// print LCS;
void printLCS(ll i, ll j)
{
    if( i>=sz1 || j>=sz2 ){ cout<<ans<<endl; return; }
    if(s1[i]==s2[j]){
        ans+=s1[i];
        printLCS(i+1, j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1] )printLCS(i+1, j);
        else printLCS(i, j+1);
    }
}

string ansALL;
void printAll(int i,int j)
{
	if( i>=sz1 || j>=sz2 ){
		cout<<ansALL<<endl;
		return;
	}
	if(s1[i]==s2[j]){
		ansALL+=s1[i];
		printAll(i+1,j+1);
		ansALL.erase(ansALL.end()-1); //Delete last character
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1])printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1])printAll(i,j+1);
		else{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}



/*
Second Part::::
The function I have defined to do the work has three parameters.
First is the present index of first string, second is the present index of
second string and third is the number of characters we have taken till now.
Case are:
If the two characters are same then proceed to the next characters by
unique(i+1,j+1,num+1). If two characters are not same then proceed by calling
like follow: ret=unique(i+1,j,num+1)+unique(i,j+1,num+1).
The base case is more important in my technique::::
If any of the string got finished then what you will do?
My answer is, in common you add all the remaining letters from given
strings with the num value from paremeter. If it is equal to length
from first part then return 1(right approach:) ) else return 0(wrong approach :().
*/
ll cnt_str(int i, int j, int l)
{
    if(i>=sz1){
        l+=sz2-j;
        if(l==len) return 1;
        else return 0;
    }
    if(j>=sz2){
        l+=sz1-i;
        if(l==len) return 1;
        else return 0;
    }
    if(dp2[i][j][l]!=-1) return dp2[i][j][l];
    ll ret=0;
    if(s1[i]==s2[j]){ ret=cnt_str(i+1,j+1,l+1); }
    else{ ret+=cnt_str(i+1,j,l+1)+cnt_str(i,j+1,l+1); }
    dp2[i][j][l]=ret;
    return ret;
}

int main()
{
    CIN;
    int t, te=1;
    cin>>t;
    while(te<=t){
        ans="";
        cin>>s1>>s2;
        sz1=s1.size(); sz2=s2.size();
        cout<<"Case "<<te<<": ";
        ms(dp,-1); ms(dp2,-1);
        len=sz1+sz2-LCS(0,0);
        printLCS(0, 0);
        printAll(0, 0);
        cout<<len<<" "; cout<<cnt_str(0,0,0)<<endl;
        te++;
    }
    return 0;
}
