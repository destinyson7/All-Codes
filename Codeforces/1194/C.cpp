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

bool f = true;

bool dp(string s, string t, multiset <char> ms, ll i, ll j, ll len1, ll len2)
{
    // cout << i << " " << j << endl;

    if(i == len1 && j == len2)
    {
        return true;
    }

    if(i == len1+1)
    {
        return false;
    }

    if(s[i] == t[j])
    {
        return dp(s, t, ms, i+1, j+1, len1, len2);
    }

    if(ms.find(t[j]) != ms.end())
    {
        ms.erase(ms.lower_bound(t[j]));

        return dp(s, t, ms, i, j+1, len1, len2);
    }

    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll q;
    cin >> q;

    while(q--)
    {
        f = true;

        string s, t, p;
        cin >> s >> t >> p;

        ll len1 = sz(s);
        ll len2 = sz(t);

        multiset <char> ms;

        for(ll i=0; i<sz(p); i++)
        {
            ms.insert(p[i]);
        }

        if(dp(s, t, ms, 0, 0, len1, len2))
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}