#include <bits/stdc++.h>
#include "christmas.h"
using namespace std;
ofstream file;

int main() {
    ios::sync_with_stdio(false);
    file.open("./out.txt");
    christmas a;
    a.setMap({"X.....X",
              "......X",
              "X......",
              ".......",
              ".......",
              ".......",
              "...XXXX"});
    a.add_block({"+++", "+", "+"}, true, false);
    a.add_block({"++++", "+"}, false, false);
    a.add_block({"++++", " +"}, false, false);
    a.add_block({"++", " +++"}, false, false);
    a.add_block({"++", "+++"}, false, false);
    a.add_block({"+ +", "+++"}, true, false);
    a.add_block({" ++", " +", "++"}, false, true);
    a.add_block({"++", "++", "++"}, true, true);
    a.init();
    a.run();
    for (auto &i: a.getAns())
        file << i << '\n';
}