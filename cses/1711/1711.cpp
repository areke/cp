#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    // return set of ints representing the edges.
    // note that this will need to get deduplicated separately. see cses/1695 for usage
		vector<int> getCut() {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			bfs();
			set<int> st;
			for (int i = 0; i < n; i++) {
				if (level[i] != -1) st.insert(i);
			}
			vector<int> res;
			for (int i = 0; i < n; i++) {
				bool iin = st.find(i) != st.end();
				for (int j : adj[i]) {
					bool jin = st.find(edges[j].u) != st.end();
					if (iin != jin) {
						res.push_back(j);
					}
				}
			}
			return res;
		}

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void dfs(int x, int t, vector<set<int> > & v, vector<int> & path, vector<int> & res, vector<bool> & vis) {
	if (vis[x]) return;
	if (!res.empty()) return;
	vis[x] = true;
	path.push_back(x);
	if (x == t) {
		res = path;
		return;
	}
	for (int n : v[x]) {
		dfs(n, t, v, path, res, vis);
	}
	path.pop_back();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Dinic dinic(n, 0, n - 1);
	set<pair<int, int> > s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		dinic.add_edge(x, y, 1);
		s.insert({x, y});
	}
	cout << dinic.flow() << endl;
	vector<set<int> > v(n);
	for (auto it : dinic.edges) {
		if (it.flow == it.cap && s.find({it.v, it.u}) != s.end()) {
			v[it.v].insert(it.u);
		}
	} 

	vector<vector<int> > res;
	while (true) {
		vector<int> path;
		vector<int> found;
		vector<bool> vis(n, 0);
		dfs(0, n - 1, v, path, found, vis);
		if (found.empty()) break;
		res.push_back(found);
		for (int i = 1; i < found.size(); i++) {
			v[found[i - 1]].erase(v[found[i - 1]].find(found[i]));
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].size() << endl;
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] + 1 << " \n"[j == res[i].size() - 1];
		}
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
