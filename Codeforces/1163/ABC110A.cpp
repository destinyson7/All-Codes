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
    
    ll A, B, C;
    cin >> A >> B >> C;

    ll x = 10*max(A, max(B, C));

    if(A==max(A, max(B, C)))
    {
        cout << x+B+C << endl;
    }

    else if(B==max(A, max(B, C)))
    {
        cout << x+A+C << endl;
    }

    else
    {
        cout << x+A+B << endl;
    }


    return 0;
}