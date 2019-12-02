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

const ll L = 2e5+5;

vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    sort(all(a));

    ll start = 0;
    ll end = 0;

    ll cur = 0;

    while(end<n && a[end]-a[start]<=5)
    {
        end++;
    }

    cur = end-start;

    while(end<n)
    {
        if(a[end]-a[start]<=5)
        {
            cur = max(cur, end-start+1);
            end++;
        }

        else
        {
            start++;
        }
    }

    cout << cur << endl;

    return 0;
}