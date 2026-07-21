#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ret;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      if (nums[i] > 0) break;

      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ret.push_back(vector<int>({ nums[i], nums[l++], nums[r--] }));
          while (l < r && nums[l] == nums[l - 1]) { l++; }
          while (l < r && nums[r] == nums[r + 1]) { r--; }
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }

    return ret;
  }
};
