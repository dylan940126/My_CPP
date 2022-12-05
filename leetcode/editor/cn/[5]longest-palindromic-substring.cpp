// 標題:最长回文子串ok
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(const string &s) {
        short l = 0, ansLen = 0, len = s.size();
        for (short mid = 0; mid < len; ++mid) {
            short ex = 0;
            while (mid - ex >= 0 && mid + ex < len && s[mid - ex] == s[mid + ex]) ++ex;
            --ex;
            if (ansLen < 2 * ex + 1)
                l = mid - ex, ansLen = 2 * ex + 1;
        }
        for (short mid = 0; mid < len - 1; ++mid) {
            short ex = 0;
            while (mid - ex >= 0 && mid + 1 + ex < len && s[mid - ex] == s[mid + 1 + ex]) ++ex;
            --ex;
            if (ansLen < 2 * ex + 2)
                l = mid - ex, ansLen = 2 * ex + 2;
        }
        return s.substr(l, ansLen);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.longestPalindrome("ccc");
}