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
	while (tests--) {
		int n;
		cin >> n;
		int d[100];
		for (int i = 0; i < n; i++) cin >> d[i];
		int a[100];
		for (int i = 0; i < n; i++) a[i] = -1;
		bool one = true;
		a[0] = d[0];
		for (int i = 1; i < n; i++) {
			for (int j = max(0, a[i - 1] - 100); j <= a[i - 1] + 100; j++) {
				if (abs(j - a[i - 1]) == d[i]) {
					if (a[i] != -1) one = false;
					a[i] = j;
				}
			}
		}
		if (one) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
