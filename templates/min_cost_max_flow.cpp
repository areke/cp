

typedef pair<int, int>		  pii;
typedef vector<int>			 vi;	 /// adjlist without weight
typedef vector<pii>			 vii;	/// adjlist with weight
typedef vector<pair<int,pii>>   vpip;   /// edge with weight
typedef long long			   ll;

#define mp  make_pair
#define ff  first
#define ss  second
#define pb  push_back
#define sz(x)   (int)(x).size()


const int MOD = 1e9+7;  // 998244353;
const int MX  = 2e5+5;   //
const ll INF = 1e18;	//

#define MAXV 300007
#define MAXE 100007

const int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1}; /// 4 directions

struct NODE {
	int x, y;
	int val;
	int visited;
	bool operator< (NODE b) const { return (x == b.x) ? (y < b.y) : (x < b.x); }
};
struct EDGE {
	int from, to;
	ll weight;
	bool operator<(EDGE other) const { return weight < other.weight; }
};

/**
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
 	* It is possible to choose negative edge costs such that the first 
 	* run of Dijkstra is slow, but this hasn't been an issue in the past. 
 	* Edge weights $\ge 0$ for every subsequent run. To get flow through 
 	* original edges, assign ID's during \texttt{ae}.
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$ 
 	* if caps are integers and $F$ is max flow.
 * Source: GeeksForGeeks
 	* https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg.pdf
 	* running time is only pseudo-polynomial; see https://codeforces.com/blog/entry/70740
 	* https://en.wikipedia.org/wiki/Johnson%27s_algorithm (to get non-negative weights)
 	* https://codeforces.com/contest/1316/submission/72472865 
 		* mango_lassi, min cost circulation w/ capacity scaling
 * Verification: https://codeforces.com/contest/164/problem/C
 	* https://codeforces.com/contest/316/problem/C2
 		* TLEs, don't use priority queue
 */
struct MCMF {
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to, rev; F flo, cap; C cost; };
	int N0;
	vector<C> p, dist;
	vii pre;
	vector<vector<Edge>> adj;

	void init(int _N) {
		N0 = _N;
		p.resize(N0); dist.resize(N0); pre.resize(N0); adj.resize(N0);
	}
	void ae(int u, int v, F cap, C cost) {
		assert(cap >= 0);
		adj[u].pb({v,sz(adj[v]),  0,cap,cost});
		adj[v].pb({u,sz(adj[u])-1,0,0,  -cost});
	}
	bool path(int s, int t) { // send flow through lowest cost path
		dist.assign(N0,INF);
		using T = pair<C, int>;	 // (distance, vtx)
		priority_queue<T, vector<T>, greater<T>> todo;
		todo.push({dist[s] = 0,s});
		while (sz(todo)) { // Dijkstra
			T x = todo.top(); todo.pop();
			if (x.ff > dist[x.ss]) continue;
			for(auto e : adj[x.ss]) { // all weights should be non-negative
				if (e.flo < e.cap && ( dist[e.to] > x.ff+e.cost+p[x.ss]-p[e.to]) ) {
					dist[e.to] = x.ff + e.cost + p[x.ss]-p[e.to]; // pi function
					pre[e.to]={x.ss, e.rev};
					todo.push({dist[e.to],e.to});
				}
			}
		} // if costs are doubles, add some EPS so you don't traverse ~0-weight cycle repeatedly
		return dist[t] != INF; // true if augmenting path
	}
	pair<F,C> calc(int s, int t, bool hasNegCost = false) {
		assert(s != t);
		if(hasNegCost) { // take care negative flow
			for(int k=0; k<N0; k++) for(int i=0; i<N0; i++) for(auto e : adj[i]) // Bellman-Ford, 0 index
				if (e.cap && (p[e.to] > p[i]+e.cost) ) p[e.to] = p[i]+e.cost;
		}

		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			for(int i=0; i<N0; i++) p[i] += dist[i]; // don't matter for unreachable
			F df = INF;
			for (int x = t; x != s; x = pre[x].ff) {
				Edge& e = adj[pre[x].ff][adj[x][pre[x].ss].rev];
				if(df > e.cap-e.flo) df = e.cap-e.flo;
			}
			// if we want to do fixed flow target K, just limit totFlow to upto K
			// df = min(df, K - totFlow; and break after the backtrack df adjustment if we can reach K in this iteration
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = pre[x].ff) {
				Edge& e = adj[x][pre[x].ss];
				e.flo -= df;
				adj[pre[x].ff][e.rev].flo += df;
			}
		} // get max flow you can send along path
		return {totFlow, totCost};
	}
};