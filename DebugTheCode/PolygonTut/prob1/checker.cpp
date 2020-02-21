#include "testlib.h"

int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    int expectedAns = ans.readInt();
    int actualAns = ouf.readInt();

    if (expectedAns != actualAns) {
        quitf(_ok, "The hack case gives WA.");
    } else {
        quitf(_wa, "The hack case does not hack anything.");
    }
}