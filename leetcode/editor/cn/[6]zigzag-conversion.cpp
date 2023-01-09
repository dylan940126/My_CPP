// 標題:Z 字形变换
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        bool down = true;
        int n = 0;
        for (char &i: s) {
            if (down) {
                if (n >= numRows - 1)
                    down = false, n = numRows - 1;
            } else if (n <= 0)
                down = true, n = 0;
            ans[n].push_back(i);
            if (down)
                ++n;
            else
                --n;
        }
        s.clear();
        for (string &i: ans)
            s += i;
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution sol;
    cout << sol.convert("AB", 1);
}