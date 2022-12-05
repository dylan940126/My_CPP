// 標題:两数之和ok
#include <algorithm>
#include <vector>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> arr(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            arr[i] = i;
        sort(arr.begin(), arr.end(),
             [&nums](int a, int b) { return nums[a] < nums[b]; });
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int tmp = nums[arr[l]] + nums[arr[r]];
            if (tmp == target)
                return {arr[l], arr[r]};
            if (tmp < target)
                ++l;
            else
                --r;
        }
        return {0, 0};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
