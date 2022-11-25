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
		vector<int> a(n);
		vector<int> b(n);
		int maxi = -1;
		int maxInd = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > maxi) {
				maxi = a[i];
				maxInd = i;
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		maxInd = (maxInd - 1 + n) % n;
		for (int i = 0; i < n; i++) {
			int cur = a[(maxInd - i + n) % n];
			int curInd = (maxInd - i + n) % n;
			int next = a[(curInd + 1) % n];
			if (a[curInd] != b[curInd]) {
				if (cur <= next) {
					a[curInd] = max(min(next, b[curInd]), a[curInd]);	
				}
			}
		}
		int minDif = 1e9;
		for (int i = 0; i < n; i++) {
			minDif = min(minDif, (b[i] - a[i]));
		}
		if (minDif < 0) {
			cout << "NO" << endl;
			continue;
		}
		//cout << minDif << endl;
		for (int i = 0; i < n; i++) {
			a[i] += minDif;
		}
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				ind = i;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			int cur = a[(ind - i + n) % n];
			int curInd = (ind - i + n) % n;
			int next = a[(curInd + 1) % n];
			if (a[curInd] != b[curInd]) {
				if (cur <= next) {
					a[curInd] = max(min(next + 1, b[curInd]), a[curInd]);	
				} 
			}
		}
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) f = false;
		}
		if (f) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}