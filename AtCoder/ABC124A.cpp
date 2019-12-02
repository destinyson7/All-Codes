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
    
    ll A, B;
    cin >> A >> B;

    ll m = max(A, B);

    if(m-1 >= min(A, B))
    {
        cout << 2*m-1 << endl;
    }

    else
    {
        cout << A+B << endl;
    }

    return 0;
}