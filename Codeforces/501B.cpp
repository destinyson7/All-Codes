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

const ll L = 1e3+5;

map <string, string> m;

vector < pair <string, string> > store;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll q;
    cin >> q;

    while(q--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if(!m.count(s1))
        {
            m[s1] = s1;
        }

        m[s2] = m[s1];
        m[s1] = s1;
    }

    for(auto i: m)
    {
        if(i.ff != i.ss)
        {
            store.pb(mp(i.ss, i.ff));
        }
    }

    cout << sz(store) << endl;

    for(auto i: store)
    {
        cout << i.ff << " " << i.ss << endl;
    }


    return 0;
}