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

vector <float> v;
vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll sum = 0;

    for(ll i=0; i<n; i++)
    {
        float t;
        cin >> t;

        v.pb(t);
        a.pb((ll)t);
        
        sum+=a[i];
    }

    if(sum == 0)
    {
        for(ll i=0; i<n; i++)
        {
            cout << a[i] << endl;
        }

        return 0;
    }

    else if(sum > 0)
    {
        bool f = false;

        for(ll i=0; i<n; i++)
        {
            if(!f && v[i]!=(ll)v[i])
            {
                if(v[i]<0)
                {
                    a[i]--;
                    sum--;
                }
            }

            if(sum == 0)
            {
                f=true;
                break;
            }

        }
    }

    else
    {
        bool f = false;

        // cout << "here" << endl;

        for(ll i=0; i<n; i++)
        {
            // cout << a[i] << " " << (ll)v[i] << endl;
            if(!f && v[i]!=(ll)v[i])
            {
                if(v[i]>0)
                {
                    // cout << "i" << i << endl;
                    a[i]++;
                    sum++;
                }
            }

            if(sum == 0)
            {
                f=true;
                break;
            }
        }
    }

    for(ll i=0; i<n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}