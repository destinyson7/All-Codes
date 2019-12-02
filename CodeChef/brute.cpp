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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    

    ll a = 19;

    while(a < 1000)
    {
        ll temp = a;

        ll sum = 0;
        while(temp)
        {
            sum+=temp%10;
            temp/=10;
        }

        if(sum%10)
        {
            cout << a << endl;
        }

        a+=9;
    }    

    return 0;
}