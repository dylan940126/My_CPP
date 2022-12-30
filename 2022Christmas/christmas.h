
#ifndef CLION_CHRISTMAS_H
#define CLION_CHRISTMAS_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;
using map_type = vector<vector<int>>;

class christmas {
    struct shape {
        unsigned long long size;
        bool reversible;
        bool turnable;
        vector<pii> points;

        shape(const vector<pii> &points, bool reversible, bool turnable) : reversible(reversible),
                                                                           turnable(turnable),
                                                                           points(points),
                                                                           size(points.size()) {}

        explicit shape(const vector<pii> &point) : shape(point, true, true) {}
    };

    inline int possibleRun(map_type &_map_, int x, int y) {
        if (x < 0 || x > 6 || y < 0 || y > 6 || _map_[x][y])
            return 0;
        _map_[x][y] = 1;
        return possibleRun(_map_, x - 1, y) +
               possibleRun(_map_, x + 1, y) +
               possibleRun(_map_, x, y + 1) +
               possibleRun(_map_, x, y - 1) + 1;
    }

    inline bool possible(int min_size) {
        auto _map_ = map;
        int ret = width * height;
        for (int x = 0; x < 7; ++x)
            for (int y = 0; y < 7; ++y) {
                if (_map_[x][y])
                    continue;
                if (possibleRun(_map_, x, y) < min_size)
                    return false;
            }
        return true;
    }

    static inline pii cvt(const pii &start, const int dir, const pii &vec, bool reverse = false) {
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

    vector<pii> preprocessing(vector<pii> &now, int x, int y, int dir, bool rev) {
        vector<pii> reg;
        for (const auto &regi: now) {
            auto ret = cvt({x, y}, dir, regi, rev);
            if (ret.first < 0 || ret.first > 6 || ret.second < 0 || ret.second > 6 ||
                map[ret.first][ret.second]) {
                return {};
            }
            reg.emplace_back(ret);
        }
        return reg;
    }

    vector<pii> place;


    vector<map_type> ans;

    unsigned long long width{}, height{};

public:
    double getProcess() {
        double ret = 0, now = 1;
        for (auto &i: place) {
            now /= double(height * width);
            ret += double(i.first * height + i.second) * now;
        }
        return ret;
    }

    const vector<map_type> &getAns() const {
        return ans;
    }

    vector<shape> blocks;
    map_type map;

    inline void add_block(vector<string> init_strings, bool line_symmetry, bool point_symmetry) {
        auto x0 = init_strings.front().find_first_of('+');
        vector<pii> new_shape;
        for (int i = 0; i < init_strings.size(); ++i) {
            auto _i = init_strings[i];
            for (int j = 0; j < _i.size(); ++j) {
                if (_i[j] == '+')
                    new_shape.emplace_back(i, j - x0);
            }
        }
        blocks.emplace_back(new_shape, !line_symmetry, !point_symmetry);
    }

    inline void setMap(const vector<string> &map) {
        christmas::map.clear();
        for (auto &i: map) {
            vector<int> map_line;
            for (auto &j: i) {
                if (j == 'X')
                    map_line.push_back(-1);
                else
                    map_line.push_back(0);
            }
            christmas::map.emplace_back(map_line);
        }
        height = map.size();
        width = map.front().size();
    }

//init operations before run
    inline void init() {
        std::sort(blocks.begin(), blocks.end(),
                  [](const shape &a, const shape &b) { return a.size < b.size; });
    }


    void run(int idx = 0) {
        if (idx == blocks.size()) {
            ans.push_back(map);
            return;
        }
        auto &now = blocks[idx];
        if (!possible(now.size)) {
            if (idx < 4)
                cout << '\r' << fixed << setprecision(1) << getProcess() * 100 << '%' << flush;
            return;
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (map[i][j])
                    continue;
                bool rev = false;
                again:
                for (int dir = 0; dir < (now.turnable ? 4 : 2); ++dir) {
                    auto reg = preprocessing(now.points, i, j, dir, rev);
                    if (reg.empty())
                        continue;
                    for (auto &regi: reg)
                        map[regi.first][regi.second] = idx + 1;
                    place.emplace_back(i, j);
                    run(idx + 1);
                    for (auto &regi: reg)
                        map[regi.first][regi.second] = 0;
                    place.pop_back();
                }
                if (rev != now.reversible) {
                    rev = true;
                    goto again;
                }
            }
        }
    }
};

basic_ostream<char> &operator<<(basic_ostream<char> &out, const map_type &map) {
    for (auto &i: map) {
        for (auto &j: i)
            if (j == -1)
                out << '0' << ' ';
            else
                out << j << ' ';
        out << '\n';
    }
    return out;
}

#endif //CLION_CHRISTMAS_H
