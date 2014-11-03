#include "bulba.h"

#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;

const char* USAGE = "\
USAGE: rank FILE\n\
";
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, USAGE);
        return 2;
    }
    set<pokemon> ordered = report(argv[1]);
    for (auto it = ordered.rbegin(); it != ordered.rend(); it++) {
        cout << *it << endl;
    }
    return 0;
}
