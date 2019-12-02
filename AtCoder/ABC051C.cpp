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
    
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    ll cnt = 0;

    while(cnt < tx-sx)
    {
        cout << "R";
        cnt++;
    }

    cnt = 0;
    while(cnt < ty-sy)
    {
        cout << "U";
        cnt++;
    }

    cnt = 0;
    while(cnt < tx - sx)
    {
        cout << "L";
        cnt++;
    }

    cnt = 0;
    while(cnt < ty-sy+1)
    {
        cout << "D";
        cnt++;
    }

    cnt=0;
    while(cnt < tx-sx+1)
    {
        cout << "R";
        cnt++;
    }

    cnt = 0;
    while(cnt < ty-sy+1)
    {
        cout << "U";
        cnt++;
    }

    cout << "LU";

    cnt = 0;
    while(cnt < tx - sx+1)
    {
        cout << "L";
        cnt++;
    }

    cnt = 0;
    while(cnt < ty-sy+1)
    {
        cout << "D";
        cnt++;
    }

    cout << "R";

    cout << endl;


    return 0;
}