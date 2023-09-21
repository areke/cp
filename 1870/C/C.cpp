#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<set<int> > v(k + 1);

    multiset<int> all;
    
    for (int i = 0; i < n; i++) {
      v[a[i]].insert(i + 1);
      all.insert(i + 1);
    }
    vector<long long> res(k);
    for (int i = 0; i < k; i++) {
      if (v[i + 1].empty()) {
        res[i] = 0;
      } else {
        long long low = *all.begin();
        long long high = *all.rbegin();
        long long w = (high - low + 1);
        res[i] = 2 * w;
      }
      for (int x : v[i + 1]) {
        all.erase(all.find(x));
      }
    }
    for (int i = 0; i < k; i++) {
      cout << res[i] << " \n"[i == k - 1];
    }


  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
