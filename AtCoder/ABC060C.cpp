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

const ll L = 2e5+5;

vector <ll> t(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, T;
    cin >> N >> T;

    for(ll i=0; i<N; i++)
    {
        cin >> t[i];
    }
    
    ll rem = 0;

    for(ll i=1; i<N; i++)
    {
        if(t[i]-t[i-1]>T)
        {
            rem-=(T-t[i]+t[i-1]);
        }
    }

    cout << t[N-1]+T-rem << endl;

    return 0;
}