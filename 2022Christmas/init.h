//
// Created by suen3 on 12/28/2022.
//

#ifndef CLION_INIT_H
#define CLION_INIT_H

#include <vector>

using namespace std;
using pii = pair<int, int>;

struct shape {
    vector<pii> points;

    explicit shape(const initializer_list<pii> &point) : points(point) {}
};

vector<shape> blocks{shape{{0, 0}, //+++
                           {0, 1}, //+
                           {0, 2}, //+
                           {1, 0}, //
                           {2, 0}},
                     shape{{0, 0}, //++
                           {0, 1}, // +
                           {1, 1}, // +
                           {2, 1}, // +
                           {3, 1}},
                     shape{{0, 0}, // +
                           {1, -1},//++
                           {1, 0}, // +
                           {2, 0}, // +
                           {3, 0}},
                     shape{{0, 0}, // +
                           {1, -1},//++
                           {1, 0}, //+
                           {2, -1},//+
                           {3, -1}},
                     shape{{0, 0}, //++
                           {0, 1}, //+++
                           {1, 0}, //
                           {1, 1}, //
                           {1, 2}},
                     shape{{0, 0}, //+ +
                           {0, 2}, //+++
                           {1, 0}, //
                           {1, 1}, //
                           {1, 2}},
                     shape{{0, 0}, // ++
                           {0, 1}, // +
                           {1, 0}, //++
                           {2, -1},//
                           {2, 0}},
                     shape{{0, 0}, //++
                           {0, 1}, //++
                           {1, 0}, //++
                           {1, 1}, //
                           {2, 0}, //
                           {2, 1}}};

vector<bool> reversible{false, true, true, true, true, false, true, false};
vector<bool> turnable{true, true, true, true, true, true, false, false};
vector<vector<int>> map{{-1, 0, 0, 0,  0,  0,  -1},
                        {0,  0, 0, 0,  0,  0,  -1},
                        {-1, 0, 0, 0,  0,  0,  0},
                        {0,  0, 0, 0,  0,  0,  0},
                        {0,  0, 0, 0,  0,  0,  0},
                        {0,  0, 0, 0,  0,  0,  0},
                        {0,  0, 0, -1, -1, -1, -1}};

int possibleRun(decltype(map) &_map_, int x, int y) {
    if (x < 0 || x > 6 || y < 0 || y > 6 || _map_[x][y])
        return 0;
    int ans = 1;
    _map_[x][y] = 1;
    ans += possibleRun(_map_, x - 1, y);
    ans += possibleRun(_map_, x + 1, y);
    ans += possibleRun(_map_, x, y + 1);
    ans += possibleRun(_map_, x, y - 1);
    return ans;
}

bool possible() {
    auto _map_ = map;
    for (int x = 0; x < 7; ++x)
        for (int y = 0; y < 7; ++y) {
            if (_map_[x][y])
                continue;
            int tmp=possibleRun(_map_, x, y);
            if (tmp < 5)
                return false;
        }
    return true;
}

#endif //CLION_INIT_H
