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

ll f3[L];
ll f2[L];
ll f1[L];
ll c[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // f3[4] = 1;
    // f2[4] = 1;
    // f1[4] = 1;
    // c[4] = 2;
    f2[2] = 1;
    f1[1] = 1;
    f3[3] = 1;

    // cout << 2 << " " << 1 << " " << 1 << " " << 1 << endl;

    for(ll i=4; i<=20; i++)
    {
        c[i] = 2*i-6 + c[i-1] + c[i-2] + c[i-3];
        f3[i] = f3[i-1]+f3[i-2]+f3[i-3];
        f2[i] = f2[i-1]+f2[i-2]+f2[i-3];
        f1[i] = f1[i-1]+f1[i-2]+f1[i-3];

        cout << c[i] << " " << f3[i] << " " << f2[i] << " " << f1[i] << endl;
    }   

    return 0;
}