#include <iostream>
#include <queue>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;

template <typename T> using Vec = vector<T>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

constexpr ll MOD = 1e9 + 9;

struct Edge {
  int to;
  ll cost;

  bool operator>(const Edge &right) const {
    if (cost == right.cost) return to < right.to;
    return cost > right.cost;
  }
};

ll solve(const Vec<Vec<Edge>> &adj, const int N, const int S, const int E) {
  priority_queue<Edge, Vec<Edge>, greater<Edge>> pq;
  Vec<ll> dist(N + 1, LINF);
  Vec<int> dp(N + 1, 0);

  pq.emplace(Edge{ S, 0 }), dist[S] = 0, dp[S] = 1;

  while (!pq.empty()) {
    const auto [cur, cur_dist] = pq.top();
    pq.pop();

    if (cur_dist > dist[cur]) continue;

    for (const auto &[next, next_cost] : adj[cur]) {
      ll next_dist = cur_dist + next_cost;
      if (next_dist < dist[next]) {
        dist[next] = next_dist, dp[next] = dp[cur];
        if (next != E) pq.emplace(Edge{ next, next_dist });
      } else if (next_dist == dist[next]) {
        dp[next] = (dp[next] + dp[cur]) % MOD;
      }
    }
  }

  return dp[E];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, S, E;
  cin >> N >> M >> S >> E;

  Vec<Vec<Edge>> adj(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    ll cost;
    cin >> u >> v >> cost;

    adj[u].emplace_back(Edge{ v, cost });
    adj[v].emplace_back(Edge{ u, cost });
  }

  cout << solve(adj, N, S, E) << endl;

  return 0;
}
