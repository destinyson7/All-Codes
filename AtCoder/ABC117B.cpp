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

    ll sum = 0;
    ll m = 0;
    for(ll i=0; i<N; i++)
    {
        ll a;
        cin >> a;

        sum+=a;

        m = max(m, a);
    }   

    if(2*m < sum)
    {
        cout << "Yes" << endl;
    }

    else
    {
        cout << "No" << endl;
    }

    return 0;
}