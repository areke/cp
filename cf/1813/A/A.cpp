#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <map>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
vector<long double> l, d;
vector<int> qmin, qbase, qmax;
list<vector<long double> > old_bad;
list<vector<long double> > old_base_bad;
int shadow_size_delta = 500;
int lookback = 500;

template<class T> struct Seg {
	const T ID = 0;
	T comb(T a, T b) {
		return a + b;
	}
	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}
	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	T query(int l, int r) {
		if (l > r) return 0;
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

struct Cache {
	int max_size = 0;
	int cur_size = 0;
	public: 
		void init(int sz) {
		  cur_size = 0;
			max_size = sz;
		}
		virtual int get(int k) = 0;

		virtual int evict() = 0;
	
		virtual void put(int k, int v) = 0;
 

};

struct LFUCache : Cache {
	int minFreq;
	unordered_map<int, pair<int, int>> m; //key to {value,freq};
	unordered_map<int, list<int>::iterator> mIter; //key to list iterator;
	unordered_map<int, list<int>>  fm;  //freq to key list;
public:

		
    int get(int key) {
			if(m.count(key)==0) return -1;
			return m[key].first;
    }

		int evict() {
			int val = m[fm[minFreq].front()].first;
			m.erase( fm[minFreq].front() );
			mIter.erase( fm[minFreq].front() );
			fm[minFreq].pop_front();
			cur_size--;
			return val;
		}

    void put(int key, int value) {
			int storedValue = -1;
			if (m.count(key)) {
				fm[m[key].second].erase(mIter[key]);
				m[key].second++;
				fm[m[key].second].push_back(key);
				mIter[key]=--fm[m[key].second].end();
				if (fm[minFreq].size()==0 ) minFreq++;
			}
			if (storedValue != -1) {
				m[key].first=value;
				return;
			}
			m[key]={value, 1};
			fm[1].push_back(key);
			mIter[key]=--fm[1].end();
			minFreq=1;
			cur_size++;
    }

};
 
struct LRUCache : Cache {

 
	unordered_map<int, list<pair<int, int> >::iterator> m;
	list<pair<int, int> > l;
	int get(int k) {
		if (!m.count(k)) return -1;
		return (*(m[k])).second;
	}
 
	int evict() {
		assert(!l.empty());
		m.erase(m.find(l.back().first));
		int ret = l.back().second;
		l.pop_back();
		cur_size--;
		return ret;
	}
 
	void put(int k, int v) {
		l.push_front({k, v});
		m[k] = l.begin();
		cur_size++;
	}
};

struct multiCache {
	int timestamp = 0;

	vector<Cache*> lrus, base_lrus, shadow_queues;
	long double total_bad, total_base_bad;
	vector<long double> base_bad, bad, lookback_base_bad;
	vector<int> target_sizes;
	Seg<int> seg;
	vector<Seg<int> > seg2;
	int max_size, num_tenants = 0;
	int cur_size = 0;
public:
	virtual int put (int u, int p) = 0;
	virtual ~multiCache() {};

	virtual void init(int n, int q, int m) {
		num_tenants = n;
		max_size = q;
		lrus.resize(n), base_lrus.resize(n), shadow_queues.resize(n), target_sizes.assign(n, 0);
		seg.init(m + 1);
		seg2.resize(n);
		for (int i = 0; i < n; i++) {
			seg2[i].init(m + 1);
		}
		bad.assign(n, 1), base_bad.assign(n, 1), lookback_base_bad.assign(n, 1);
		total_bad = n;
		total_base_bad = n;
	}

	virtual long double cost() = 0;
	
};
 
struct multiLRU : multiCache {
	map<pair<int, int>, int> last_accessed_time;
	list<pair<int, int> > all_queue;
	list<pair<int, int> > bad_queue;
	set<int> access_times;
	void init(int n, int q, int m) {
		multiCache::init(n, q, m);
		for (int i = 0; i < n; i++) {
			lrus[i] = new LRUCache();
			base_lrus[i] = new LRUCache();
			shadow_queues[i] = new LRUCache();
		}
		for (int i = 0; i < n; i++) {
			lrus[i]->init(target_sizes[i]);
			base_lrus[i]->init(qbase[i]);
			shadow_queues[i]->init(min(qmax[i], target_sizes[i] + shadow_size_delta));
		}
	}

	int put(int u, int p) {
		timestamp++;
		int last = last_accessed_time[{u, p}];
		int higher = seg.query(last, timestamp);
		if (last != 0) {
			seg.upd(last, 0);
		} else {
			higher = 1e9;
		}
		seg.upd(timestamp, 1);
		all_queue.push_front({u, higher});
		if (all_queue.size() > 5 * sqrt(timestamp)) {
			pair<int, int> last_higher = all_queue.back();
			if (last_higher.second != 1e9) {
				seg2[last_higher.first].upd(last_higher.second, seg2[last_higher.first].query(last_higher.second, last_higher.second) - 1);
			}
			all_queue.pop_back();
			pair<int, int> last_bad = bad_queue.back();
			bad_queue.pop_back();
			lookback_base_bad[last_bad.first] -= last_bad.second;
		}
		last_accessed_time[{u, p}] = timestamp;
		if (higher != 1e9) {
			seg2[u].upd(higher, seg2[u].query(higher, higher) + 1);
		}
		int ret = lrus[u]->get(p);

		bool in_target_queue = ret != -1;
		
		if (!in_target_queue) {
			bad[u]++;
			total_bad++;
		}
		if (base_lrus[u]->get(p) == -1) {
			if (base_lrus[u]->cur_size == base_lrus[u]->max_size) base_lrus[u]->evict();
			base_lrus[u]->put(p, p);
			total_base_bad++;
			base_bad[u]++;
			lookback_base_bad[u]++;
			bad_queue.push_front({u, 1});
		} else {
			bad_queue.push_front({u, 0});
		}


		//cout << dcdt << endl;
		// (2x-2c-1)/c^2 
		//resize_targets(u, min((long double)10, max((long double)-10, -dcdt)));

		if (ret != -1) {
			old_base_bad.push_back(base_bad);
			old_bad.push_back(bad);
			return ret;
		}
		ret = cur_size;
		if (lrus[u]->cur_size == qmax[u]) {
			ret = lrus[u]->evict();
			cur_size--;
		} else if (cur_size == max_size) {
			vector<pair<long double, int> > v(num_tenants);
			int to_evict = -1;
			for (int i = 0; i < num_tenants; i++) {
				long double sbad = seg2[i].query(lrus[i]->cur_size + shadow_size_delta + 1, seg2[i].n - 1);
				long double curbad = seg2[i].query(lrus[i]->cur_size + 1, seg2[i].n - 1);
				long double lowbad = seg2[i].query(max(0, lrus[i]->cur_size - shadow_size_delta), seg2[i].n - 1);
				//cout << sbad << " " << curbad << " " << min(seg2[u].n - 1, lrus[u]->cur_size) << " " << min(seg2[u].n - 1, target_sizes[u] + shadow_size_delta) << " " << base_bad[u] << endl;
				// need to figure out how to handle zeroing out even if curbad > lookback_base_bad

				// need to take into account the fraction that are bad * how many we expect to see.
				long double range = max(1, min(lrus[i]->cur_size + shadow_size_delta + 1, seg2[i].n - 1) - max(0, lrus[i]->cur_size - shadow_size_delta));
				long double cs = max((long double)0, (sbad / lookback_base_bad[i]) - 1);
				cs *= cs;
				long double c = max((long double)0, (lowbad / lookback_base_bad[i]) - 1);
				c *= c;
				long double multi = max((long double) 1, (bad[i] - base_bad[i]));
				long double dcdt = (c - cs) * l[i] * multi / range / qbase[i];
				v[i] = {dcdt, i};
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < num_tenants; i++) {
				if (lrus[u]->cur_size < qmax[u] && lrus[v[i].second]->cur_size > qmin[v[i].second]) {
					to_evict = v[i].second;
					break;
				} 
			}
			assert(to_evict != -1);
			ret = lrus[to_evict]->evict();
			cur_size--;
		}
		assert(cur_size < max_size);
		lrus[u]->put(p, ret);
		cur_size++;
		old_base_bad.push_back(base_bad);
		old_bad.push_back(bad);
		return ret;
	}

	long double cost() {
		return 0;
	}
};
 
 

int main() {
	int n, q, m;
	cin >> n >> q >> m;
	l.resize(n), d.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	qmin.resize(n), qbase.resize(n), qmax.resize(n);
 
	for (int i = 0; i < n; i++) {
		cin >> qmin[i] >> qbase[i] >> qmax[i];
	}

	vector<multiCache*> multiCaches = {new multiLRU()};
	for (int i = 0; i < multiCaches.size(); i++) {
		multiCaches[i]->init(n, q, m);
	}

	multiCache* currentCache = multiCaches[0];
	long double total_base_bad = n;
	long double total_bad = n;
	for (int i = 0; i < m; i++) {
		int u, p;
		cin >> u >> p;
		u--;
		int res = currentCache->put(u, p) + 1;
		assert(1 <= res && res <= q);
		cout << res << endl;
		cout.flush();
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}