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
        ll N;
        cin >> N;

        vector <double> k, c;

        double div = 0;

        for(ll i=0; i<N; i++)
        {
            double t;
            cin >> t;

            k.pb(t);

            div+=((double)1.00/k[i]);
        }

        double check = 0;

        for(ll i=0; i<N; i++)
        {
            double t;
            cin >> t;

            check+=((double)k[i]*t);

            c.pb(t);
        }

        if(check >= 0)
        {
            check/=(double)div;
        }

        else
        {
            check = -1.00;
            N = 0;
        }

        if(check == -1.00)
        {
            cout << -1 << " ";
        }

        else
        {
            double ans = (double)check*div*div;
            cout << fixed << setprecision(8) << sqrt(ans) << " ";
        }

        for(ll i=0; i<N; i++)
        {
            cout << fixed << setprecision(8) << (double)check/(k[i]*k[i]) - (double)c[i] << " ";
        }
        cout << endl;
    }

    return 0;
}