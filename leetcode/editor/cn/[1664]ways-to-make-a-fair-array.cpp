.// 標題:生成平衡数组的方案数
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int waysToMakeFair(vector<int> &nums) {
        int r1 = 0, r0 = 0;
        unsigned long long int len = nums.size();
        for (int i = 0; i < len; i += 2)
            r1 += nums[i];
        for (int i = 1; i < len; i += 2)
            r0 += nums[i];
        int l0 = 0, l1 = 0, ret = 0;
        for (int i = 0; i < len; ++i) {
            if (i & 1) {
                r0 -= nums[i];
                if (l0 + r0 == l1 + r1)
                    ++ret;
                l1 += nums[i];
            } else {
                r1 -= nums[i];
                if (l0 + r0 == l1 + r1)
                    ++ret;
                l0 += nums[i];
            }
        }
        return ret;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.waysToMakeFair(*new vector<int>{2, 1, 6, 4});
}