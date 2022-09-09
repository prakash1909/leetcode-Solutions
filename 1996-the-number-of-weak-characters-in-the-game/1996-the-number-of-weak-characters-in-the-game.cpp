class Solution {
	static bool cmp(vector<int> &a, vector<int> &b) {
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	}
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int n = properties.size(), ans = 0, maxi = INT_MIN;
		sort(properties.begin(), properties.end(), cmp);

		for (int i = n - 1; i >= 0; --i) {
			if (properties[i][1] < maxi) ans++;
			maxi = max(maxi, properties[i][1]);
		}
		return ans;
	}
};