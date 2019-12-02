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
    
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    ll m1 = X;
    ll m3 = X;
    for(ll i=0; i<N; i++)
    {
        ll x;
        cin >> x;

        m1 = max(m1, x);
        m3 = min(m3, x);
    }

    ll m2 = Y;
    ll m4 = Y;
    for(ll i=0; i<M; i++)
    {
        ll x;
        cin >> x;

        m2 = max(m2, x);
        m4 = min(m4, x);
    }

    if(m1<m4)
    {
        cout << "No War" << endl;
    }

    else
    {
        cout << "War" << endl;
    }

    return 0;
}