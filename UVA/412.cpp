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
        ll N;
        cin >> N;

        if(!N)
        {
            break;
        }

        vector <ll> data;

        for(ll i=0; i<N; i++)
        {
            ll a;
            cin >> a;

            data.pb(a);
        }

        ll coprime = 0;

        for(ll i=0; i<N; i++)
        {
            for(ll j=i+1; j<N; j++)
            {

                if(gcd(data[i], data[j]) == 1)
                {
                    coprime++;
                }
                
            }
        }

        if(!coprime)
        {
            cout << "No estimate for this data set." << endl;
        }

        else
        {
            // cout << coprime << endl;
            
            ll tot = (N*(N-1))/2;

            cout << fixed << setprecision(6) << sqrt((6.0*tot)/coprime) << endl;
        }
    }


    return 0;
}