#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll a[5];

    for(ll i=0; i<5; i++)
    {
        cin >> a[i];
    }

    ll k;
    cin >> k;

    for(ll i=0; i<5; i++)
    {
        for(ll j=0; j<5; j++)
        {
            if(abs(a[i]-a[j]) > k)
            {
                cout << ":(" << endl;
                return 0;
            }
        }
    }

    cout << "Yay!" << endl;

    return 0;
}