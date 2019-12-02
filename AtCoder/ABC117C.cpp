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

const ll L = 1e5+5;

vector <ll> x(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<M; i++)
    {
        cin >> x[i];
    }   

    sort(all(x));

    // unique(x.begin(), x.begin()+sz(x));

    for(ll i=0; i<M; i++)
    {
        
    }


    return 0;
}