/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const sorted_nums = [...nums].sort((a, b) => a - b);

  const ret = [];

  const N = sorted_nums.length;
  for (let i = 0; i + 2 < N; ++i) {
    if (i > 0 && sorted_nums[i] === sorted_nums[i - 1]) continue;
    if (sorted_nums[i] > 0) break;

    let l = i + 1,
      r = N - 1;

    while (l < r) {
      const sum = sorted_nums[i] + sorted_nums[l] + sorted_nums[r];
      if (sum < 0) l++;
      else if (sum > 0) r--;
      else {
        ret.push([sorted_nums[i], sorted_nums[l], sorted_nums[r]]);
        (l++, r--);
        while (l < r && sorted_nums[l] == sorted_nums[l - 1]) l++;
        while (l < r && sorted_nums[r] == sorted_nums[r + 1]) r--;
      }
    }
  }

  return ret;
};
