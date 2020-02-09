#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int display_size=16;
void left()
{
    cout<<"for Left:--"<<endl;
    cout<<endl;
    string ans=v[0];
    int len=v[0].size();
    for(int i=1; i<v.size(); i++){
        if(len+v[i].size()+1<=display_size){
            ans+=" ";
            ans+=v[i];
            len+=v[i].size()+1;
        }
        else{
            ans+='\t\n';
            ans+=v[i];
            len=v[i].size();
        }
    }
    cout<<ans<<endl;


}
void right()
{
    cout<<"for right:--"<<endl;
    cout<<endl;
    string ans="";
    string temporal=v[0];
    int len=v[0].size();
    for(int i=1; i<v.size(); i++){
        if(len+v[i].size()+1<=display_size){
            temporal+=" ";
            temporal+=v[i];
            len+=v[i].size()+1;
        }
        else{
            temporal+='\t\n';
            for(int j=0; j<display_size-len; j++)temporal=" "+temporal;
            ans+=temporal;
            temporal=v[i];
            len=v[i].size();
        }
    }
    if(temporal.size()>0){
        for(int j=0; j<display_size-len; j++)temporal=" "+temporal;
        ans+=temporal;
    }
    cout<<ans<<endl;

}
int main()
{
    freopen("in.txt", "r", stdin);
    int num_of_word;
    cin>>num_of_word;
    while(num_of_word--)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    left();
    right();
}
