#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T, typename V> using Map = unordered_map<T, V>;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    Map<string, vector<string>> m;
    m.reserve(strs.size());

    for (const auto &str : strs) {
      auto key = str;
      sort(key.begin(), key.end());

      m[std::move(key)].push_back(str);
    }

    vector<vector<string>> answer;
    answer.reserve(m.size());
    for (auto &[_, v] : m) { answer.push_back(std::move(v)); }

    return answer;
  }
};
