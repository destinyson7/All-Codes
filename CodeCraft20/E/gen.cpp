#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int P = rnd.next(1, 7);
    int N = rnd.next(P + 1, 100000);
    int k = rnd.next(1, N - P);

    cout << N << " " << P << " " << k << endl;

    for(int i = 0; i < N; i++)
    {
        int temp = rnd.next(1, 1000000000);
        cout << temp;

        if(i < N - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < P; j++)
        {
            int temp = rnd.next(1, 1000000000);
            cout << temp;

            if(j < P - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}