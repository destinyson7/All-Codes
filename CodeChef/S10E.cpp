#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        vector <int> p;

        for(int i = 0; i < N; i++)
        {
            int a;
            cin >> a;

            p.push_back(a);
        }

        int ans = 0;

        for(int i = 0; i < N; i++)
        {
            int j = i - 1;

            bool f = true;
            while(j >= 0 && i - j <= 5)
            {
                if(p[i] >= p[j])
                {
                    f = false;
                    break;
                }

                j--;
            }

            if(f)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}