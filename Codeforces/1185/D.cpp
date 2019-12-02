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

vector <pll> b;

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

        b.pb(mp(t, i+1));
    }

    sort(all(b));

    ll terms = 2;
    ll first = b[0].ff;

    ll failed = 0;

    ll d1 = b[1].ff - b[0].ff;

    ll f = 0;

    ll remove = -1;

    for(ll i=2; i<n; i++)
    {
        if(b[i].ff == (first + (terms)*d1))
        {
            terms++;
        }

        else
        {
            failed++;

            if(failed == 1)
            {
                remove = b[i].ss;
            }

            if(failed == 2)
            {
                f = 1;
                break;
            }
        }
    }

    if(!f)
    {
        if(remove != -1)
        {
            cout << remove << endl;
            return 0;
        }

        else
        {
            cout << b[n-1].ss << endl;
            return 0;
        }
    }

    terms = 2;
    first = b[0].ff;

    failed = 1;

    ll d2 = b[2].ff - b[0].ff;

    f = 0;

    remove = b[1].ss;

    for(ll i=3; i<n; i++)
    {
        if(b[i].ff == (first + (terms)*d2))
        {
            terms++;
        }

        else
        {
            failed++;

            if(failed == 1)
            {
                remove = b[i].ss;
            }

            if(failed == 2)
            {
                f = 1;
                break;
            }
        }
    }

    if(!f)
    {
        if(remove != -1)
        {
            cout << remove << endl;
            return 0;
        }

        else
        {
            cout << b[n-1].ss << endl;
            return 0;
        }
    }

    terms = 2;
    first = b[1].ff;

    failed = 1;

    ll d3 = b[2].ff - b[1].ff;

    f = 0;

    remove = b[0].ss;

    for(ll i=3; i<n; i++)
    {
        if(b[i].ff == (first + (terms)*d3))
        {
            terms++;
        }

        else
        {
            failed++;

            if(failed == 1)
            {
                remove = b[i].ss;
            }

            if(failed == 2)
            {
                f = 1;
                break;
            }
        }
    }

    if(!f)
    {
        if(remove != -1)
        {
            cout << remove << endl;
            return 0;
        }

        else
        {
            cout << b[n-1].ss << endl;
            return 0;
        }
    }

    else
    {
        cout << -1 << endl;
    }



    return 0;
}