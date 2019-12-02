#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    string s;
    cin >> s;

    ll ans = 0;

    ll len = sz(s);

    ll prev = 0;

    for(ll i=0; i<len-3; i++)
    {
        if(s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r')
        {
            ans+=((i+1 - prev)*(len - (i+2+1)));            
            prev = i+1;
        }
    }

    cout << ans << endl;


    return 0;
}