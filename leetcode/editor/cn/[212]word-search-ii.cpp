// 標題:单词搜索 II
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    using pii = pair<int, int>;
public:
    bool run(int x, int y, const string &str, int idx, int no) {
        if (idx == str.size())
            return true;
        if (x < 0 || x >= xmax || y < 0 || y >= ymax || gone[x][y] || (*board_)[x][y] != str[idx])
            return false;
        gone[x][y] = true;
        bool ret = (no != 1 && run(x - 1, y, str, idx + 1, 0)) ||
                   (no != 0 && run(x + 1, y, str, idx + 1, 1)) ||
                   (no != 3 && run(x, y - 1, str, idx + 1, 2)) ||
                   (no != 2 && run(x, y + 1, str, idx + 1, 3));
        gone[x][y] = false;
        return ret;
    }

    int xmax, ymax;

    vector<vector<bool>> gone;

    const vector<vector<char>> *board_;

    vector<string> findWords(const vector<vector<char>> &board, const vector<string> &words) {
        board_ = &board;
        xmax = board.size(), ymax = board[0].size();
        gone.assign(xmax, vector<bool>(ymax, false));
        vector<vector<pii>> map_(26);
        for (int i = 0; i < xmax; ++i)
            for (int j = 0; j < ymax; ++j)
                map_[board[i][j] - 'a'].emplace_back(i, j);
        vector<string> ans;
        for (auto &str: words) {
            if (any_of(str.begin(), str.end(), [&](const char &i) { return map_[i - 'a'].empty(); }))
                continue;
            auto now = map_[str[0] - 'a'];
            if (any_of(now.begin(), now.end(), [&](pii &cood) {
                return run(cood.first, cood.second, str, 0, -1);
            }))
                ans.push_back(str);
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    vector<vector<char>> a{{'o', 'a', 'a', 'n'},
                           {'e', 't', 'a', 'e'},
                           {'i', 'h', 'k', 'r'},
                           {'i', 'f', 'l', 'v'}};
    auto ans = sol.findWords(a, {"oath", "pea", "eat", "rain"});
    for (auto i: ans)
        cout << i;
}