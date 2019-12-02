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

vector <ll> t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        t.pb(a);
    }

    ll first = 0;
    ll second = 0;

    ll alice = 0;
    ll bob = n-1;

    ll timea = 0;
    ll timeb = 0;

    while(alice <= bob)
    {
        while(timea<=timeb)
        {
            timea+=t[alice];
            alice++;
            first++;

            if(alice > bob)
            {
                break;
            }
        }

        if(alice>bob)
        {
            break;
        }

        while(timeb<timea)
        {
            timeb+=t[bob];
            bob--;
            second++;

            if(bob<alice)
            {
                break;
            }
        }

        if(alice > bob)
        {
            break;
        }
    }

    cout << first << " " << second << endl;

    return 0;
}