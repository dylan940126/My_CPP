// 標題:和为目标值且不重叠的非空子数组的最大数目
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxNonOverlapping(vector<int> &nums, int target) {
        unordered_set<int> sub;
        sub.insert(0);
        int ret = 0, sum = 0;
        for (int &i: nums) {
            if (sub.count((sum += i) - target))
                sub.clear(), sub.insert(0), sum = 0, ++ret;
            else
                sub.insert(sum);
        }
        return ret;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    cout << sol.maxNonOverlapping(*new vector<int>{0, 0, 0}, 0);
}