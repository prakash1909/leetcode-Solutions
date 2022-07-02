class Solution {
public:
long long int cal(int len, vector<int>& cuts) {
	cuts.push_back(len);
	long long int ans = 0, prevCut = 0, n = cuts.size();
	for(int i = 0; i < n; i++) {
		ans = max(cuts[i] - prevCut, ans);
		prevCut = cuts[i];
	}
	return ans;
}
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
	sort(horizontalCuts.begin(), horizontalCuts.end());
	sort(verticalCuts.begin(), verticalCuts.end());
	long long int a = cal(h, horizontalCuts);
	long long int b = cal(w, verticalCuts);
	int mod = 1e9 + 7;
	return (a * b) % mod;
}
};