// 標題:满足条件的子序列数目
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> mul;
    static const int mod = 1000000007;
public:
    int numSubseq(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int len = nums.size(), up = len - 1;
        for (int i = 0; i < len; ++i) {
            while (i <= up && nums[i] + nums[up] > target)
                --up;
            if (i > up)
                break;
            nums[i] = up - i;
        }
        int i = 0;
        long long ret = 0, pow = 1;
        for (int it = up; it >= 0; --it) {
            while (i < nums[it]) {
                pow <<= 1;
                if (pow >= mod)
                    pow -= mod;
                ++i;
            }
            ret += pow;
        }
        return ret % mod;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.numSubseq(*new vector<int>{2, 3, 3, 4, 6, 7}, 12);
}