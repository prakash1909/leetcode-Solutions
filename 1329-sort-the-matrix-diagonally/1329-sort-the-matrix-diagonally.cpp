class Solution {
public:

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int i=0,j=0; int m=mat.size(),n=mat[0].size();
	//upper diagonals
    while(i<m && j<n){
        vector<int> v;
        int k=i,l=j;
        while(k<m && l<n){
            v.push_back(mat[k][l]);
            k++,l++;
        }
        sort(v.begin(),v.end());
        k=i,l=j; int ind=0;
        while(k<m && l<n){
            mat[k][l]=v[ind++];
            k++,l++;
        }
        j++;
    }
	//lower diagonals
    i=1,j=0;
    while(i<m && j<n){
        vector<int> v;
        int k=i,l=j;
        while(k<m && l<n){
            v.push_back(mat[k][l]);
            k++,l++;
        }
        sort(v.begin(),v.end());
        k=i,l=j; int ind=0;
        while(k<m && l<n){
            mat[k][l]=v[ind++];
            k++,l++;
        }
        i++;
    }
    return mat;
}
};