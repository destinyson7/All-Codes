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

vector <ll> dp(105, 0);

bool solve(ll n, ll k)
{
    if(n<0)
    {
        return true;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    if((n>=1 && solve(n-1, k) == 0) || (n>=2 && solve(n-2, k) == 0) || (n>=k && solve(n-k, k) == 0))
    {
        dp[n] = 1;

        return true;
    }

    dp[n] = 0;
    return false;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    

    for(ll i=3; i<=100; i++)
    {
        for(ll j=0; j<=100; j++)
        {
            dp[j] = -1;
        }

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[i] = 1;

        cout << "k: " << i << endl;

        for(ll j=0; j<=100; j++)
        {
            if(solve(j, i))
            {
                cout << "W";
            }

            else
            {
                cout << "L";
            }
        }
        cout << endl << endl;
    }


    return 0;
}