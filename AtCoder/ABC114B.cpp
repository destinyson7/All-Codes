#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;

    ll m = 1e15;
    for(ll i=0; i<sz(s)-2; i++)
    {
        ll cur = 100*((ll)(s[i]-48));
        cur+=10*((ll)(s[i+1]-48));
        cur+=((ll)(s[i+2]-48));
        
        m = min(m, abs(753-cur));
    }

    cout << m << endl;

    return 0;
}