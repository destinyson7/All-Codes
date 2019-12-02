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

const ll L = 105;

vector <ll> a(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i];
    }

    ll cur = -100;
    ll cost = 1e15;

    while(cur<=100)
    {
        ll temp = 0;
        for(ll i=0; i<N; i++)
        {
            temp+=((cur-a[i])*(cur-a[i]));
        }

        cost = min(cost, temp);

        cur++;
    }

    cout << cost << endl;

    

    return 0;
}