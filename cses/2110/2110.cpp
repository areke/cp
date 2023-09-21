#include <bits/stdc++.h>
using namespace std;


struct SANode {
  int len;
  vector<int> next;
  int link;
  SANode(int l) {
    len = l;
    link = -1;
    next.assign(26, -1);
  }
};
 
struct SA {
  int n;
  vector<SANode*> v;
  int last = 0;
  int cnt = 0;

  int addNode(SANode* node) {
    v[cnt++] = node;
    return cnt - 1;
  }

  SA(string s) {
    n = s.length();
    v.assign(2 * n + 5, NULL);
    addNode(new SANode(0));
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      int p = last;
      auto cur = new SANode(i + 1);
      int curID = addNode(cur);
      while (p != -1 && v[p]->next[c] == -1) {
        v[p]->next[c] = curID;
        p = v[p]->link;
      }
      if (p == -1) {
        cur->link = 0;
      } else if (v[p]->next[c] != -1) {
        int q = v[p]->next[c];
        if (v[p]->len + 1 == v[q]->len) {
          cur->link = q;
        } else {
          auto clone = new SANode(v[p]->len + 1);
          clone->next = v[q]->next;
          clone->link = v[q]->link;
          int cloneID = addNode(clone); 
          v[q]->link = cloneID;
          cur->link = cloneID;
          int lst = p;
          while (lst != -1 && v[lst]->next[c] == q) {
            v[lst]->next[c] = cloneID;
            lst = v[lst]->link;
          }
        }
      } else {
        assert(false);
      }
      last = curID;
    }
  }
};


using ll = long long;

using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
#define sz(x) int(x.size())

const int INF = 1e9 + 5;

// T is a monoid and U are endomorphisms (T -> T)
template <typename T, typename U>
struct lazy_seg_t {
  struct internal_node {
    T x;
    U f;
    bool stale;
  };

  int n, k, height;
  T zero;
  U noop;

  vector<internal_node> tree;

  explicit lazy_seg_t(int n, T zero = T(), U noop = U())
    : n(n), zero(zero), noop(noop), tree(4 * n) {
    k = 1, height = 1;
    while (k < n)
      k <<= 1, ++height;
  }

  void build(std::vector<T> const& arr) {
    assert(sz(arr) == n);
    for (int i = 0; i < n; ++i)
      tree[i + k].x = arr[i];

    for (int i = k - 1; i > 0; --i)
      tree[i].x = tree[2 * i].x + tree[2 * i + 1].x;
  }

  void apply(int i, U const& f) {
    tree[i].x = f(tree[i].x);
    if (i < k) {
      tree[i].f = tree[i].f + f;
      tree[i].stale = true;
    }
  }

  void rebuild(int i) {
    for (int u = i / 2; u; u /= 2) {
      T comb = tree[2 * u].x + tree[2 * u + 1].x;
      tree[u].x = tree[u].f(comb);
    }
  }

  void propagate(int i) {
    for (int h = height; h > 0; --h) {
      int u = i >> h;
      if (tree[u].stale) {
        apply(2 * u, tree[u].f);
        apply(2 * u + 1, tree[u].f);
        tree[u].f = noop;
        tree[u].stale = false;
      }
    }
  }

  void update(int i, int j, U const& u) {
    i += k, j += k;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, u);
      if ((r & 1) == 0) apply(r--, u);
    }

    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    i += k, j += k;
    propagate(i), propagate(j);

    T l = zero, r = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) l = l + tree[i++].x;
      if ((j & 1) == 0) r = tree[j--].x + r;
    }

    return l + r;
  }
};

struct node_t {
  ll x;
  node_t operator+(node_t const& other) {
    return { x + other.x };
  }
};

struct update_t {
  ll x;

  node_t operator()(node_t const& node) const {
    return { node.x + x };
  }

  update_t operator+(update_t const& u) {
    return { x + u.x };
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  string s;
  cin >> s;
  int n = s.length();

  auto at = SA(s);


  vector<node_t> leaves(n + 1, {0});
  for (int i = 0; i < n + 1; ++i) {
    cin >> leaves[i].x;
  }

  lazy_seg_t<node_t, update_t> seg(n + 1);
  seg.build(leaves);
  for (int i = 1; i < at.cnt; i++) {
    seg.update(at.v[at.v[i]->link]->len + 1, at.v[i]->len, {1});
  }
  for (int i = 1; i <= n; i++) {
    cout << seg.query(i, i).x << " \n"[i == n];
  }




  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
