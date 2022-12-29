#include <iostream>
#include <fstream>
#include "init.h"

using namespace std;

class christmas {

    using pii = pair<int, int>;
    basic_ostream<char> &out;

    static pii cvt(const pii &start, const int dir, const pii &vec, bool reverse = false) {
        if (reverse)
            switch (dir) {
                case 0:
                    return {start.first - vec.first, start.second + vec.second};
                case 1:
                    return {start.first - vec.second, start.second - vec.first};
                case 2:
                    return {start.first + vec.first, start.second - vec.second};
                case 3:
                    return {start.first + vec.second, start.second + vec.first};
                default:
                    return {-1, -1};
            }
        else
            switch (dir) {
                case 0:
                    return {start.first + vec.first, start.second + vec.second};
                case 1:
                    return {start.first + vec.second, start.second - vec.first};
                case 2:
                    return {start.first - vec.first, start.second - vec.second};
                case 3:
                    return {start.first - vec.second, start.second + vec.first};
                default:
                    return {-1, -1};
            }
    }

    vector<pii> reg;

    bool calculate(vector<pii> &now, int x, int y, int dir, bool rev) {
        reg.clear();
        for (const auto &regi: now) {
            auto ret = cvt({x, y}, dir, regi, rev);
            if (ret.first < 0 || ret.first > 6 || ret.second < 0 || ret.second > 6 ||
                map[ret.first][ret.second])
                return false;
            reg.emplace_back(ret);
        }
        return true;
    }

public:
    explicit christmas(basic_ostream<char> &out) : out(out) {}

    void printMap(decltype(map) &_map) {
        for (auto &i: _map) {
            for (auto &j: i)
                if (j == -1)
                    out << '0' << ' ';
                else
                    out << j << ' ';
            out << '\n';
        }
        out << flush;
    }

    vector<decltype(map)> ans;

    bool show = false;

    void run(int idx = 0) {
        if (!possible()) {
//            out << "impossible:\n";
//            printMap(map);
            return;
        }
        auto &now = blocks[idx].points;
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (map[i][j])
                    continue;
                bool rev = false;
                again:
                for (int dir = 0; dir < (turnable[idx] ? 4 : 2); ++dir) {
                    if (!calculate(now, i, j, dir, rev))
                        continue;
                    auto tmpreg = reg;
                    for (auto &regi: tmpreg)
                        map[regi.first][regi.second] = idx + 1;
//                    decltype(map) map3(7, vector<int>(7));
//                    for (auto &regi: tmpreg)
//                        map3[regi.first][regi.second] = idx + 1;
//                    printMap(map3);
                    if (idx == 7 && (ans.empty() || ans.back() != map)) {
                        ans.push_back(map);
                    } else {
                        run(idx + 1);
                    }
                    for (auto &regi: tmpreg)
                        map[regi.first][regi.second] = 0;
                }
                if (rev != reversible[idx]) {
                    rev = true;
                    goto again;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    ofstream file("./out.txt");
    christmas a(file);
    a.run();
//    file << "\n\n\n\nans:";
    int cnt = 0;
    for (auto i: a.ans) {
        file << "\n";
        a.printMap(i);
    }
}