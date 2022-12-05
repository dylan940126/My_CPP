// 標題:和至少为 K 的最短子数组ok
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//
class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        deque<pair<int, long long>> dq;
        dq.push_back({-1, 0});
        long long sum = 0;
        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (!dq.empty() && sum - dq.front().second >= k) {
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
            while (!dq.empty() && sum <= dq.back().second)
                dq.pop_back();
            dq.push_back({i, sum});
        }
        return ans == nums.size() + 1 ? -1 : ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    vector<int> arr{84, -37, 32, 40, 95};
    cout << solution.shortestSubarray(arr, 167);
}
