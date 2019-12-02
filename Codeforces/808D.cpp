#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

ll a[L];

// map <ll, ll> m;
unordered_map <ll, ll> firstHalf;
unordered_map <ll, ll> secondHalf;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    firstHalf.reserve(2*n);
    secondHalf.reserve(2*n);

    ll sum = 0;
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        sum+=a[i];

        secondHalf[a[i]]++;
    }

    // cout << sum << endl;
    
    ll cur = 0;

    if(sum&1)
    {
        cout << "NO" << endl;
        return 0;
    }

    ll goal = sum/2;

    for(ll i=0; i<n; i++)
    {
        firstHalf[a[i]]++;
        secondHalf[a[i]]--;

        cur+=a[i];

        // cout << "cur: " << cur << " at i: " << i << endl;

        if(cur==goal)
        {
            cout << "YES" << endl;
            return 0;
        }

        if(cur < goal)
        {;
            ll t = goal - cur;

            if(secondHalf[t] > 0)
            {
                cout << "YES" << endl;
                return 0;
            }
        }

        else
        {
            ll t = cur - goal;

            // cout << " " << t << endl;

            if(firstHalf[t] > 0)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }    

    cout << "NO" << endl;
    return 0;

    return 0;
}