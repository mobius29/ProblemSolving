/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  const n = s.length;
  if (n == 0) return 0;

  const m = new Map();
  m.set(s[0], 0);

  let answer = 1,
    left = 0;

  for (let i = 1; i < n; i++) {
    if (m.has(s[i])) left = Math.max(left, m.get(s[i]) + 1);
    m.set(s[i], i);

    answer = Math.max(answer, i - left + 1);
  }

  return answer;
};
