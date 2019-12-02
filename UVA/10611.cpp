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
    
    ll N;
    cin >> N;

    set <ll> h;

    for(ll i=0; i<N; i++)
    {
        ll a;
        cin >> a;

        h.insert(a);
    }

    ll Q;
    cin >> Q;

    while(Q--)
    {
        ll a;
        cin >> a;

        auto i = h.lower_bound(a);
        if(i == h.begin())
        {
            cout << "X" << " ";
        }

        else
        {
            i--;

            cout << *i << " ";
        }

        auto it = h.upper_bound(a);

        if(it == h.end())
        {
            cout << "X" << endl;
        }        

        else
        {
            cout << *it << endl;
        }
    }

    return 0;
}