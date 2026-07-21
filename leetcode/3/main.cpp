#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

template <typename T, typename V> using U_Map = unordered_map<T, V>;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int N = s.length();
    if (N == 0) return 0;

    U_Map<char, int> m;
    m.insert({ s[0], 0 });

    int left = 0;
    int answer = 1;
    for (int i = 1; i < N; i++) {
      if (m.contains(s[i])) { left = max(left, m[s[i]] + 1); }
      m[s[i]] = i;

      answer = max(answer, i - left + 1);
    }

    return answer;
  }
};
