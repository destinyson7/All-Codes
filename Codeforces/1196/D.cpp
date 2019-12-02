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
    
    ll q;
    cin >> q;

    string req = "RGB";

    while(q--)
    {
        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        ll ans = k;

        ll cur = 0;

        for(ll i=0; i<k; i++)
        {
            if(s[i]!=req[i%3])
            {
                cur++;
            }
        }

        ans = cur;

        for(ll i=k; i<n; i++)
        {
            if(s[i-k]!=req[(i-k)%3])
            {
                cur--;
            }

            if(s[i]!=req[i%3])
            {
                cur++;
            }

            ans = min(ans, cur);
        }

        cur = 0;

        for(ll i=0; i<k; i++)
        {
            if(s[i]!=req[(i+1)%3])
            {
                cur++;
            }
        }

        ans = min(ans, cur);

        for(ll i=k; i<n; i++)
        {
            if(s[i-k]!=req[(i-k+1)%3])
            {
                cur--;
            }

            if(s[i]!=req[(i+1)%3])
            {
                cur++;
            }

            ans = min(ans, cur);
        }

        cur = 0;

        for(ll i=0; i<k; i++)
        {
            if(s[i]!=req[(i+2)%3])
            {
                cur++;
            }
        }

        ans = min(ans, cur);

        for(ll i=k; i<n; i++)
        {
            if(s[i-k]!=req[(i-k+2)%3])
            {
                cur--;
            }

            if(s[i]!=req[(i+2)%3])
            {
                cur++;
            }

            ans = min(ans, cur);
        }

        cout << ans << endl;
    }


    return 0;
}