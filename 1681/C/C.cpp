#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		vector<pair<int, int> > moves;
		for (int i = 0; i < n; i++) {
			int mini = 1e5;
			int minj = i;
			for (int j = i; j < n; j++) {
				if (a[j] < mini) {
					mini = a[j];
					minj = j;
				} else if (a[j] == mini) {
					if (b[j] < b[minj]) {
						minj = j;
					}
				}
			}

			if (minj != i) {
				moves.push_back(make_pair(i, minj));
				swap(a[i], a[minj]);
				swap(b[i], b[minj]);
			}
		}	
		bool val = true;
		for (int i = 1; i < n; i++) {
			if (b[i] < b[i - 1]) val = false;
		}
		if (val) {
			cout << moves.size() << endl;
			for (auto it : moves) {
				cout << it.first + 1 << " " << it.second+ 1<< endl;
			}
		} else {
			cout << -1 << endl;
		}

	}
	return 0;
}
