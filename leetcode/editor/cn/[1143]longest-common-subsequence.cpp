// 標題:最长公共子序列
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(const string &text1, const string &text2) {
        int m = text1.size(), n = text2.size();
        int dp[m][n];
        dp[0][0] = text1[0] == text2[0];
        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i - 1][0] || (text1[i] == text2[0]);
        for (int i = 1; i < n; ++i)
            dp[0][i] = dp[0][i - 1] || (text2[i] == text1[0]);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        return dp[m - 1][n - 1];
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("bsbininm", "jmjkbkjkv");
}