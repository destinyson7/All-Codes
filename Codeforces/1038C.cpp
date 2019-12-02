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

vector <ll> a;
vector <ll> b;

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

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        b.pb(t);
    }

    sort(all(a));
    reverse(all(a));

    sort(all(b));
    reverse(all(b));

    ll scoreA = 0;
    ll scoreB = 0;

    ll i=0, j=0;

    while(i<n || j<n)
    {
        if(i<n && j<n && a[i]>=b[j])
        {
            scoreA+=a[i];
            i++;
        }

        else if(j==n)
        {
            scoreA+=a[i];
            i++;
        }

        else if(i==n)
        {
            j++;
        }

        else
        {
            j++;
        }

        if(i<n && j<n && b[j]>=a[i])
        {
            scoreB+=b[j];
            j++;
        }

        else if(i==n)
        {
            scoreB+=b[j];
            j++;
        }

        else if(j==n)
        {
            i++;
        }

        else
        {
            i++;
        }
    }

    cout << scoreA - scoreB << endl;

    return 0;
}