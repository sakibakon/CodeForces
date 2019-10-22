#include <bits/stdc++.h>
#define N 100000
#define ll long long int
using namespace std;
bool is_prime(long long int n) {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if ((n % 2 == 0) || (n % 3 == 0)) return false;
    long long int i = 5;
    while (i*i <= n) {
      if ((n % i == 0) || (n % (i + 2) == 0)) return false;
      i = i + 6;
    }
    return true;
}
bool isPrime(char c)
{
    return (c == '2' || c == '3' || c == '5' || c == '7');
}
void decrease(string& s, ll i)
{
    if (s[i] <= '2') {
        s.erase(i, 1);
        s[i] = '7';
    }

    else if (s[i] == '3')
        s[i] = '2';
    else if (s[i] <= '5')
        s[i] = '3';
    else if (s[i] <= '7')
        s[i] = '5';
    else
        s[i] = '7';

    return;
}

string primeDigits(string s)
{
    for (ll i = 0; i < s.length(); i++) {
        if (!isPrime(s[i])) {
            while (s[i] <= '2' && i >= 0)
                i--;
            if (i < 0) {
                i = 0;
                decrease(s, i);
            }
            else
                decrease(s, i);
            for (ll j = i + 1; j < s.length(); j++)
                s[j] = '7';

            break;
        }
    }

    return s;
}
ll num(string s1)
{
    ll sum=0, tam, tam1=1;
    for(ll k=s1.size()-1; k>=0; k--){
        tam=s1[k]-'0';
        tam=tam*tam1;
        sum+=tam;
        tam1=tam1*10;
    }
    return sum;

}

int main()
{
    //sive();
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        string s;
        cin>>s;
        while(1){
                s=primeDigits(s);
                ll fuck=num(s);
                if( is_prime(fuck) ){
                    cout<<"Case "<<i<<": "<<fuck<<endl;
                    break;
                }
                ll l=s.size();
                s[l-1]-=('2'-'1');
        }

    }


    return 0;
}
