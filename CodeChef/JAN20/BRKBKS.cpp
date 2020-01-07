#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int S, x, y, z;
        cin >> S >> x >> y >> z;

        int ans = 1;

        int temp = S;

        queue <int> v;
        v.push(x);
        v.push(y);
        v.push(z);

        while(!v.empty())
        {
            if(temp >= v.front())
            {
                temp -= v.front();
                v.pop();
            }

            else
            {
                ans++;
                temp = S;
            }
        }

        cout << ans << endl;
    }
}