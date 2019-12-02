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
    
    ll N;
    cin >> N;

    ll x = 1;
    ll y = 1;

    for(ll i=0; i<N; i++)
    {
        ll T, A;
        cin >> T >> A;
        // cin >> T[i] >> A[i];
        ll x2, y2;
        if(x%T==0)
        {
            x2 = x/T;
        }

        else
        {
            x2 = x/T + 1;
        }

        if(y%A==0)
        {
            y2 = y/A;
        }

        else
        {
            y2 = y/A + 1;
        }

        ll m = max(x2, y2);

        x = T*m;
        y = A*m;
    }    

    cout << x+y << endl;
    

    return 0;
}