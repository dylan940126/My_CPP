#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool squareIsWhite(string &coordinates) {
        return ((coordinates[0] - 'a') & 1) ^ ((coordinates[1] - '1') & 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
