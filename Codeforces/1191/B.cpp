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
    
    string f, s, t;
    cin >> f >> s >> t;

    if(f==s && s==t)
    {
        cout << 0 << endl;
        return 0;
    }

    if(f[1] == s[1] && s[1] == t[1])
    {
        vector <ll> v = {f[0]-48, s[0]-48, t[0]-48};
        sort(all(v));

        if(v[1] == v[0]+1)
        {
            if(v[2] == v[1]+1)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    if(f == s || s == t || f == t)
    {
        cout << 1 << endl;
        return 0;
    }

    // vector <ll> v = {f[0]-48, s[0]-48, t[0]-48};
    // sort(all(v));

    if(f[1] == s[1])
    {
        if(abs((ll)(f[0]-48) - (ll)(s[0]-48)) == 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    if(f[1] == t[1])
    {
        if(abs((ll)(f[0]-48) - (ll)(t[0]-48)) == 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    if(s[1] == t[1])
    {
        if(abs((ll)(s[0]-48) - (ll)(t[0]-48)) == 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    if(f[1] == s[1])
    {
        if(abs((ll)(f[0]-48) - (ll)(s[0]-48)) == 2)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    if(f[1] == t[1])
    {
        if(abs((ll)(f[0]-48) - (ll)(t[0]-48)) == 2)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    if(s[1] == t[1])
    {
        if(abs((ll)(s[0]-48) - (ll)(t[0]-48)) == 2)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 2 << endl;

    return 0;
}