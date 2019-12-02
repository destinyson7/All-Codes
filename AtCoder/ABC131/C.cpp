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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll lcm = (C*D)/gcd(C, D);

    ll ans = 0;

    ans+=(B/C);
    ans-=((A-1)/C);

    ans+=(B/D);
    ans-=((A-1)/D);

    ans-=(B/lcm);
    ans+=((A-1)/lcm);

    cout << B-A+1-ans << endl;

    return 0;
}