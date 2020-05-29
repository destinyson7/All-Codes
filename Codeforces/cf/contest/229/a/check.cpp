#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, i, j, inp, price, sold = 0;
    vector<ll> A;

    cin >> N;
    for(i = 0; i < N; i++) {
        cin >> inp;
        A.push_back(inp);
    }

    sold = A[0] - 1;
    A[0] = 1;
    price = 2;

    // cout << 1 << " ";

    for (i = 0; i < N; i++) {
        if (A[i] == price) {
            price += 1;
        }
        else if (A[i] > price) {
            sold += (A[i]-1)/price;
            A[i] = price-1;
        }
        // cout << price << " ";

    }
    cout << endl;
    cout << sold << '\n' ;
    
    return 0;
}
