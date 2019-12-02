#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 2e5+5;

vector <ll> start;

vector <ll> ans(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll cur = 0;
    ll m = -1;
    ll total = 0;

    for(ll i=0; i<sz(s); i++)
    {
        if(s[i]=='(')
        {
            if(cur==0)
            {
                start.pb(i);
            }

            total++;
            cur++;

            m = max(m, cur);
        }

        else
        {
            cur = 0;
        }
    }

    cur = 0;
    ll f1 = 0;
    ll f2 = 0;

    ll cx = 0;
    ll cy = 0;
    for(ll i=0; i<sz(s); i++)
    {
        if(i==start[cur])
        {
            // if(!f1)
            // {
            //     f2^=1;
            // }

            // f1 = 0;
            ans[cx++] = f1;
            cout << f1;
            f1^=1;
            cur++;
        }

        else if(s[i]=='(')
        {
            ans[cx++] = f1;
            cout << f1;
            f1^=1;
        }

        else
        {
            cout << ans[cy];
            cy++;
        }
    }
    cout << endl;

    // cout << m << endl;

    return 0;
}