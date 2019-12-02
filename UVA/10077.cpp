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
    
    while(true)
    {
        ll m, n;
        cin >> m >> n;

        if(m == 1 && n == 1)
        {
            break;
        }

        pair <ll, ll> lp, rp;
        pair <ll, ll> cur;

        lp = mp(0, 1);
        rp = mp(1, 0);

        cur = mp(1, 1);

        double frac = (double)m/n;
        
        while(true)
        {
            double temp = (double)cur.ff/cur.ss;

            if(temp == frac)
            {
                cout << endl;
                break;
            }

            else if(frac > temp)
            {
                cout << "R";
                lp = cur;
                cur = mp(lp.ff + rp.ff, lp.ss + rp.ss);
            }

            else
            {
                cout << "L";
                rp = cur;
                cur = mp(lp.ff + rp.ff, lp.ss + rp.ss);
            }
        }
    }


    return 0;
}