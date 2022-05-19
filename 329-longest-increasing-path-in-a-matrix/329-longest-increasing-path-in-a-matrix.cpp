class Solution {
public:
    struct node {
        int r, c, v;   // location and value of each node 
    };
    
    int f_max(int a, int b) {
        if(a > b) return a;
        else return b;
    }
       
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row size
        int m = matrix[0].size(); // column size
        int maxv[200][200]; // save max length at a location
        int mv[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 4 directions
        
        vector<node> list; // save location and value
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                list.push_back({i, j, matrix[i][j]});
                maxv[i][j] = 1;
            }
        }
        
        // sort list based on value of nodes
        sort(list.begin(), list.end(), [](node a, node b){
            return a.v < b.v; 
        });
        
        int nr, nc; // new location
        int ans = 1; // answer
        for (node cur : list) {
            for (int i=0; i<4; i++) {
                nr = cur.r + mv[i][0];
                nc = cur.c + mv[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >=m) continue; // if new location is out of boundary
                if(matrix[cur.r][cur.c] >= matrix[nr][nc]) continue; // if new location value is less than previous value
                maxv[nr][nc] = f_max(maxv[cur.r][cur.c] + 1, maxv[nr][nc]); // update max value at the new location
                ans = f_max(ans, maxv[nr][nc]); // update max value at answer
            }
        }
        // return answer
        return ans;
    }
};