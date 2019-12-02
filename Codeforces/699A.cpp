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
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector <ll> x(n+5);

    for(ll i=0; i<n; i++)
    {
        cin >> x[i];
    }

    ll m = 1e15;

    for(ll i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            continue;
        }

        else
        {
            if(s[i] == 'R')
            {
                m = min(m, (x[i+1]-x[i])/2);
            }
        }
    }

    if(m == 1e15)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << m << endl;
    }

    return 0;
}