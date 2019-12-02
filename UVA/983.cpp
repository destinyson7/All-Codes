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

const ll L = 1e3+5;

ll mat[L][L];
ll col[L][L];
ll pref[L][L];
ll ans[L][L];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll N, M;

    ll t = 0;

    while(cin >> N >> M)
    {
        if(t)
        {
            cout << endl;
        }

        t++;

        for(ll i=N-1; i>=0; i--)
        {
            for(ll j=0; j<N; j++)
            {
                cin >> mat[i][j];
            }
        }

        for(ll j=0; j<N; j++)
        {
            for(ll i=0; i<N; i++)
            {
                if(!i)
                {
                    col[i][j] = mat[i][j];
                }

                else
                {
                    col[i][j] = col[i-1][j] + mat[i][j];
                }
            }
        }

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<N; j++)
            {
                if(j)
                {
                    pref[i][j] = pref[i][j-1] + col[i][j];
                }

                else
                {
                    pref[i][j] = col[i][j];
                }
            }
        }  

        ll sum = 0;

        for(ll i=0; i<N-M+1; i++)
        {
            for(ll j=0; j<N-M+1; j++)
            {
                ans[i][j] = pref[i+M-1][j+M-1];
                
                if(i)
                {
                    ans[i][j]-=pref[i-1][j+M-1];
                }

                if(j)
                {
                    ans[i][j]-=pref[i+M-1][j-1];
                }

                if(i && j)
                {
                    ans[i][j]+=pref[i-1][j-1];
                }
                
                sum+=ans[i][j];
            }
        }

        for(ll i=N-M; i>=0; i--)
        {
            for(ll j=0; j<N-M+1; j++)
            {
                cout << ans[i][j] << endl;
            }
        }

        cout << sum << endl;
    }

    return 0;
}