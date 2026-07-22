#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};

using piN = pair<int, ListNode *>;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<piN, vector<piN>, greater<piN>> pq;
    for (auto *list : lists) {
      if (list) pq.push({ list->val, list });
    }

    ListNode head, *cur = &head;
    while (!pq.empty()) {
      auto [val, node] = pq.top();
      pq.pop();
      cur->next = node;
      cur = cur->next;
      if (node->next) {
        node = node->next;
        pq.push({ node->val, node });
      }
    }

    return head.next;
  }
};
