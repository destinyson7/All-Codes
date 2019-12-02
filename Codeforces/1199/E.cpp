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
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll n, m;
        cin >> n >> m;

        vector <ll> matching;
        vector <bool> done(3*n+5, false);

        // Find any matching
        for(ll i=0; i<m; i++)
        {
            ll u, v;
            cin >> u >> v;

            if(!done[u] && !done[v])
            {
                matching.pb(i+1);

                done[u] = true;
                done[v] = true;
            }
        }

        // If size of matching >= n, then print this answer
        if(sz(matching) >= n)
        {
            cout << "Matching" << endl;

            for(ll i=0; i<n; i++)
            {
                cout << matching[i] << " ";
            }
            cout << endl;
        }

        // Else, the other unmatched vertices must form an independent set. So, its size must be greater than n, if matching is not present as the total number of vertices are 3n
        else
        {
            cout << "IndSet" << endl;

            ll req = n;
            n*=3;

            for(ll i=1; i<=n; i++)
            {
                if(req && !done[i])
                {
                    done[i] = true;
                    req--;
                    cout << i << " ";
                }

                else if(!req)
                {
                    break;
                }
            }
            cout << endl;
        }
    }


    return 0;
}