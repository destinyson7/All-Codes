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

    deque <char> q;

    if(n&1)
    {
        q.pb(s[0]);

        bool f = false;

        for(ll i=1; i<n; i++)
        {
            if(!f)
            {
                q.push_front(s[i]);
            }

            else
            {
                q.pb(s[i]);
            }

            f^=1;
        }
    }

    else
    {
        bool f = false;

        for(ll i=0; i<n; i++)
        {
            if(!f)
            {
                q.push_front(s[i]);
            }

            else
            {
                q.pb(s[i]);
            }

            f^=1;
        }
    }
    
    while(!q.empty())
    {
        cout << q.front();
        q.pop_front();
    }
    cout << endl;


    return 0;
}