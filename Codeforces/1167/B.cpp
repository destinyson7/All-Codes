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

const ll L = 1e5+5;

ll f[] = {4, 8, 15, 16, 23, 42};
ll o[10];
ll final[10];

vector <pair <ll, ll> > store;


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    cout << "? " << 1 << " " << 2 << endl;
    fflush(stdout);
    cin >> o[0];

    cout << "? " << 2 << " " << 3 << endl;
    fflush(stdout);
    cin >> o[1];

    cout << "? " << 4 << " " << 5 << endl;
    fflush(stdout);
    cin >> o[2];

    cout << "? " << 5 << " " << 6 << endl;
    fflush(stdout);
    cin >> o[3];

    ll flag = 0;
    for(ll i=0; i<6; i++)
    {
        for(ll j=0; j<6; j++)
        {
            if(i!=j)
            {
                if(f[i]*f[j]==o[0])
                {
                    store.pb(mp(f[i], f[j]));
                    flag = 1;
                    break;
                }
            }
        }

        if(flag)
        {
            break;
        }
    }

    flag = 0;
    for(ll i=0; i<6; i++)
    {
        for(ll j=0; j<6; j++)
        {
            if(i!=j)
            {
                if(f[i]*f[j]==o[1])
                {
                    store.pb(mp(f[i], f[j]));
                    flag = 1;
                    break;
                }
            }
        }

        if(flag)
        {
            break;
        }
    }

    flag = 0;
    for(ll i=0; i<6; i++)
    {
        for(ll j=0; j<6; j++)
        {
            if(i!=j)
            {
                if(f[i]*f[j]==o[2])
                {
                    store.pb(mp(f[i], f[j]));
                    flag = 1;
                    break;
                }
            }
        }

        if(flag)
        {
            break;
        }
    }

    flag = 0;
    for(ll i=0; i<6; i++)
    {
        for(ll j=0; j<6; j++)
        {
            if(i!=j)
            {
                if(f[i]*f[j]==o[3])
                {
                    store.pb(mp(f[i], f[j]));
                    flag = 1;
                    break;
                }
            }
        }

        if(flag)
        {
            break;
        }
    }

    if(store[0].ff == store[1].ff || store[0].ff == store[1].ss)
    {
        final[1] = store[0].ff;
        final[0] = o[0]/final[1];
        final[2] = o[1]/final[1];
    }

    else 
    {
        final[1] = store[0].ss;
        final[0] = o[0]/final[1];
        final[2] = o[1]/final[1];
    }

    if(store[2].ff == store[3].ff || store[2].ff == store[3].ss)
    {
        final[4] = store[2].ff;
        final[3] = o[2]/final[4];
        final[5] = o[3]/final[4];
    }

    else 
    {
        final[4] = store[2].ss;
        final[3] = o[2]/final[4];
        final[5] = o[3]/final[4];
    }

    cout << "! " << final[0] << " " << final[1] << " " << final[2] << " " << final[3] << " " << final[4] << " " << final[5] << endl; 
    fflush(stdout);

    return 0;
}