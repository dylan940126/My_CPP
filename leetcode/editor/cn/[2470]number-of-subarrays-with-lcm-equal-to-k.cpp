// 標題:最小公倍数为 K 的子数组数目
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarrayLCM(vector<int> &nums, int k) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k % nums[i])
                continue;
            int lcm = nums[i], j = i;
            while (lcm < k && j < nums.size()-1)
                lcm = std::lcm(lcm, nums[++j]);
            while (lcm == k) {
                ++ret;
                if(j==nums.size()-1)
                    break;
                lcm = std::lcm(lcm, nums[++j]);
            }
        }
        return ret;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.subarrayLCM(*new vector<int>{1}, 1);
}