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
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res = "";
	bool f = false;
	vector<int> starts;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			f = true;
		}
		if (f) res += s[i];
	}
	if (!f) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < res.length(); i++) {
		if (res[i] == '0') {
			starts.push_back(i);
			break;
		}
	}
	for (int ind : starts) {
		int l = res.length() - ind;
		string best = "";
		int bestInd = 0;

		for (int i = 0; i < min(100, l); i++) {
			best += res[ind + i];
		}
		//cout << res << " " << best << " " << ind << endl;
		for (int i = 0; i < res.length() - l + 1; i++) {
			string t = "";
			for (int j = 0; j < best.length(); j++) {
				if (res[i + j] == '1' || res[ind + j] == '1') {
					t += '1';
				} else {
					t += '0';
				}
			}
			if (best < t) {
				best = t;
				bestInd = i;
				//cout <<t << " " << i << endl;
			}
		}
		
		//cout << best << endl;
		string ret = "";
		if (res[ind] == '1' || best[0] == '1') {
			for (int i = 0; i < ind; i++) {
				ret += res[i];
			}
			for (int i = 0; i < l; i++) {
				if (res[ind + i] == '1' || res[bestInd + i] == '1') {
					ret += '1';
				} else {
					ret += '0';
				}
			}
			res = ret;
			break;
		}
	}
	cout << res << endl;
	return 0;
}