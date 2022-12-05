// 標題:寻找两个正序数组的中位数ok
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int len = nums1.size() + nums2.size(), l = 0, r = 0;
        auto next = [&]() {
            if (l == nums1.size())
                ++r;
            else if (r == nums2.size())
                ++l;
            else if (nums1[l] < nums2[r])
                ++l;
            else
                ++r;
        };
        auto get = [&]() {
            if (l == nums1.size())
                return nums2[r];
            else if (r == nums2.size())
                return nums1[l];
            return min(nums1[l], nums2[r]);
        };
        for (int i = 0; i < (len - 1) / 2; ++i)
            next();
        if (len & 1)
            return get();
        else {
            int tmp = get();
            next();
            return double (tmp + get()) / 2;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution sol;
    sol.findMedianSortedArrays({1, 2}, {3, 4});
}