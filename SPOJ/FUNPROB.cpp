#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;

    while(true)
    {
        cin >> N >> M;
    
        if(N*N + M*M == 0)
        {
            break;
        }

        double p = 0;

        if(N > M)
        {
            p = 0;
            cout << fixed << setprecision(6) << p << endl;
            continue;
        }

        if(N == 0)
        {
            p = 1;
            cout << fixed << setprecision(6) << p << endl;
            continue;
        }

        p = (double)(M+1-N)/(double)(M+1);

        cout << fixed << setprecision(6) << p << endl;
    }

    return 0;
}