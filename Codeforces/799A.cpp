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
    
    ll n, t, k, d;
    cin >> n >> t >> k >> d;

    ll t1 = 0;

    t1 = t*(n/k);

    if(n%k)
    {
        t1+=t;
    }

    ll t2 = 0;

    ll cakes = 0;

    while(t2<d)
    {
        t2+=t;
        cakes+=k;

        if(cakes >= n)
        {
            break;
        }
    }

    // cout << t2 << " " << cakes << endl;

    if(cakes<n)
    {
        // t2-=t;

        if(t2!=d)
        {
            ll tempt = d;

            // cout << cakes << " " << t2 << " " << tempt << endl;

            while(1)
            {
                if(cakes >= n)
                {
                    break;
                }

                cakes+=k;
                tempt+=t;

                if(cakes>=n)
                {
                    t2 = tempt;
                    break;
                }

                cakes+=k;
                t2+=t;
            }
        }

        else
        {
            // cakes+=k;

            while(1)
            {
                if(cakes>=n)
                {
                    break;
                }

                t2+=t;
                cakes+=2*k;
            }
        }
    }

    // cout << t1 << " " << t2 << endl;

    if(t2 < t1)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }

    return 0;
}