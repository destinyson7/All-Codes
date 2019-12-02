#include <bits/stdc++.h>

using namespace std;

int a[10];

int main()
{
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[3] = 5;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    a[9] = 6;

    int T;
    cin >> T;

    while(T--)
    {
        int A, B;
        cin >> A >> B;

        int num = A + B;

        int ans = 0;

        while(num)
        {
            ans += a[num%10];
            num /= 10;
        }

        cout << ans << endl;
    }

    return 0;
}