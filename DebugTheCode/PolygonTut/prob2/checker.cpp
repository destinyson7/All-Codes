#include "testlib.h"
// https://codeforces.com/blog/entry/18431

bool isPrime(int n) {
    // fill yourself
}

// checker should minimize chances of undefined behavior
// always have range checks

// print largest prime below n
int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    int limit = inf.readInt();

    int jans = ans.readInt(2, limit - 1, "jans");
    int pans = ouf.readInt(2, limit - 1, "pans");

    if (!isPrime(pans)) {
        quitf(_wa, "Participant output is not prime");
    }

    if (!isPrime(jans)) {
        quitf(_fail, "Judge output is not prime");
    }

    // not required
    // if (pans >= limit) {
    //     quitf(_wa, "Participant output out of range");
    // }

    // if (jans >= limit) {
    //     quitf(_fail, "Judge output out of range");
    // }

    if (pans > jans) {
        quitf(_fail, "Participant has better answer");
    } else if (pans < jans) {
        quitf(_wa, "Judge has better answer");
    } else {
        quitf(_ok, "Found better answer");
    }
}