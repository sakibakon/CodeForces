#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 1000005
#define mod 1000000007
using namespace std;
ll super_max=1000000000000;
ll f_num=0;
ll poww(ll base, ll po )
{
  ll ans=1;
  for(ll j=1; j<=po; j++)ans*=base;
  return ans;
}
ll with_base_10(ll base, string s)
{
    ll sz=s.size(), ans=0, tm=0;
    for(ll i=sz-1; i>=0 ; i--){
        ll num;
        if(s[i]>='0' && s[i]<='9')num=s[i]-'0';
        if(s[i]>='A' && s[i]<='Z')num=s[i]-'A'+10;
        ans+=num*poww(base, tm++);
        if(ans>super_max)return ans;
    }
    return ans;

}
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        f_num = -1;
        vector<string>without_base;
        vector<string>with_base[40];
        for(ll i=0; i<n; i++){
            ll base;
            string s;
            cin>>base>>s;
            //base=-1;
            if(base != -1 && f_num == -1 )f_num=with_base_10(base, s);
            if(base== -1)without_base.push_back(s);
            else with_base[base].push_back(s);
        }
        //cout<<f_num<<endl;
        if(f_num != -1){
            for(ll i=2; i<=36 && f_num != -1; i++){
                for(ll j=0; j<with_base[i].size(); i++ ){
                    if(f_num != with_base_10(i, with_base[i][j])){f_num= -1; break; }
                }
            }
            for(ll i=0; i<without_base.size() && f_num != -1; i++){
                ll base=0;
                string s=without_base[i];
                for(ll j=0; j<without_base[i].size(); j++){ //check max for base
                    ll num;
                    if(s[j]>='0' && s[j]<='9')num=s[j]-'0';
                    else if(s[j]>='A' && s[j]<='Z')num=s[j]-'A'+10;
                    base=max(base, num);
                }
                base++;
               // cout<<base<<endl;
               //base=2;
                for(ll j=base; j<=36; j++){
                    ll skb=with_base_10(j, without_base[i]);
                    if(f_num == skb ){ //cout<<j<<endl;
                            break; }
                    if(j==36 || f_num<skb || skb> super_max ){ f_num=-1; break; }
                }

            }

        }
        else{///all with -1;
            //cout<<"all -1 "<<endl;
            for(ll ii=2; ii<=36 ; ii++){
                f_num=with_base_10(ii, without_base[0]);
                if(f_num>super_max){ f_num=-1; break; }
                //if(ii==35)cout<<f_num<<endl;
                ll flg=0;
                for(ll i=1; i<without_base.size() && f_num != -1; i++){
                    ll base=0;
                    string s=without_base[i];
                    for(ll j=0; j<s.size(); j++){ //check max for base
                        ll num=0;
                        if(s[j]>='0' && s[j]<='9')num=s[j] - '0';
                        else if(s[j]>='A' && s[j]<='Z')num=s[j]-'A'+10;
                        base=max(base, num);
                       // cout<<num<<"num-base "<<base<<endl;
                    }
                    base++;
                   // cout<<s<<" "<<s.size()<<endl;
                    //cout<<base<<"base"<<endl;
                   // base=2;
                    for(ll j=base; j<=36; j++){
                        ll skb=with_base_10(j, without_base[i]);
                        if(f_num == skb ){ //cout<<j<<" "<<skb<<endl;
                                break; }
                        if(j==36 || f_num<skb || skb> super_max ){//cout<<j<<"+ "<<skb<<endl;
                         f_num=-1; break; }
                    }
                    if(f_num != -1 && i== without_base.size()-1)flg=1;

                }
                if(flg==1)break;
            }

        }
        if(f_num>super_max)cout<<-1<<endl;
        else cout<<f_num<<endl;



    }


    return 0;
}
