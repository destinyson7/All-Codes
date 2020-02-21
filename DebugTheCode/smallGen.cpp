#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    cout << 2 << "\n";

    int cnt = 0;

    string s = "";

    while(cnt < 100000 - 10)
    {
        int a = rnd.next(0, 3);

        s += "1";

        for(int i = 0; i < a; i++)
        {
            s += "0";
        }        
        
        s += "1";

        cnt += (a + 2);
    }

    cout << cnt << endl;
    cout << s << endl;

    return 0;
}