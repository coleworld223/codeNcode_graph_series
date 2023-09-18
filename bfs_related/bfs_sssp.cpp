#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    // int tests; cin >> tests;
    int tests = 1;

    auto solve = [&] () {
        ll n, m; cin >> n >> m;

        vector <vector <ll>> adj (n);

        for (ll i = 0; i < m; i++) {
            ll u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <ll> dis (n, -1), par (n);

        auto bfs = [&] (ll node) {
            queue <ll> q;
            q.push(node);
            par[node] = -1;
            dis[node] = 0;

            while (!q.empty()) {
                ll c_node = q.front(); q.pop();
                for (auto child : adj[c_node]) {
                    if (dis[child] == -1) {
                        q.push(child);
                        par[child] = c_node;
                        dis[child] = dis[c_node] + 1;
                    }
                }
            }
        };

        bfs (0);

        for (ll i = 0; i < n; i++) {
            cout << i << " :" << dis[i] << endl;
        }

        vector <vector <ll>> path (n);

        for (ll i = 0; i < n; i++) {
            vector <ll> tmp;
            ll at = i;
            while (at != -1) {
                tmp.push_back(at);
                at = par[at];
            }
            path[i] = tmp;
        }

        for (ll i = 0; i < n; i++) {
            for (auto val : path[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
