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

vector <ll> p(15);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    ll sum = 0;
    ll m = p[0];
    for(ll i=0; i<N; i++)
    {
        cin >> p[i];

        sum+=p[i];
        m = max(m, p[i]);
    }

    cout << sum - m/2 << endl;
    

    return 0;
}