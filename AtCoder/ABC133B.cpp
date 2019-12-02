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

const ll L = 10+5;

ll pts[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, D;
    cin >> N >> D;

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<D; j++)
        {
            cin >> pts[i][j];
        }
    }

    ll ans = 0;

    for(ll i=0; i<N; i++)
    {
        for(ll j=i+1; j<N; j++)
        {
            ll dis = 0;

            for(ll k=0; k<D; k++)
            {
                dis+=((pts[i][k]-pts[j][k])*(pts[i][k]-pts[j][k]));
            }

            ll root = sqrt(dis);

            if(root*root == dis)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;



    return 0;
}