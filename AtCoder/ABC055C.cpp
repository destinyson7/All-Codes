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
    
    ll N, M;
    cin >> N >> M;

    if(M <= 2*N)
    {
        cout << M/2 << endl;
    }

    else
    {
        cout << N + (M-2*N)/4 << endl;
    }

    return 0;
}