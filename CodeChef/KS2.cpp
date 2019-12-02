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
 
    ll T;
    cin >> T;

    while(T--)
    {
        ull N;
        cin >> N;

        ull a = 10*N;

        while(1)
        {
            ull temp = a;

            ull sum = 0;

            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }

            if(sum%10 == 0)
            {
                break;
            }

            a++;
        }
        

        cout << a << endl;
    }   

    return 0;
}