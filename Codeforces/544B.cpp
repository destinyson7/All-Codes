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
    
    ll n, k;
    cin >> n >> k;

    // if(n&1)
    // {
        ll t = 0;
        
        if(n&1)
        {
            t = (n/2)*n + n/2 + 1;
        }

        else
        {
            t = (n*n)/2;
        }

        if(t < k)
        {
            cout << "NO" << endl;
        }

        else
        {
            cout << "YES" << endl;

            for(ll i=0; i<n; i++)
            {
                for(ll j=0; j<n; j++)
                {
                    if(i&1)
                    {
                        if(j&1)
                        {
                            if(k)
                            {
                                cout << "L";
                                k--;
                            }

                            else
                            {
                                cout << "S";
                            }
                        }

                        else
                        {
                            cout << "S";
                        }
                    }

                    else
                    {
                        if(j&1)
                        {
                            cout << "S";
                        }

                        else
                        {
                            if(k)
                            {
                                cout << "L";
                                k--;
                            }

                            else
                            {
                                cout << "S";
                            }
                        }
                    }
                }

                cout << endl;
            }
        }
    // }

    return 0;
}