#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n = 1500;
  cout << n << " " << n << endl;
  int cur = 0;
  int next = 1;
  for (int i = 0; i < n; i++) {
    if (rand() % 40 == 0) next++;
    if (next % 20 == 0) cur = 0;
    else cur = 1;
    cout << cur << " \n"[i == n - 1];
  }

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
