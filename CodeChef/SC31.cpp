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

        // vector <string> v;
        vector <int> cnt(10, 0);

        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;

            // v.push_back(s);

            for(int j = 0; j < 10; j++)
            {
                if(s[j] == '1')
                {
                    cnt[j]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < 10; i++)
        {
            if(cnt[i] & 1)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}