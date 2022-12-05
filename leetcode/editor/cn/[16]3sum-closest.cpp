// 標題:最接近的三数之和ok
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 3; i < nums.size(); ++i) {
            int l = 0, r = i - 1, find = target - nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == find) { return target; }
                if (abs(nums[l] + nums[r] - find) < abs(ans - target))
                    ans = nums[l] + nums[r] + nums[i];
                if (nums[l] + nums[r] < find)
                    ++l;
                else
                    --r;
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution sol;
    vector<int> arr{0, 0, 0};
    cout << sol.threeSumClosest(arr, 1);
}