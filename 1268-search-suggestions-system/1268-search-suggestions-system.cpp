class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
		//simple declarations
        int n = searchWord.length();
        int m = products.size();
		vector<string> temp_array_name;
        vector<vector<string>> ans(n, temp_array_name);
		
		//Just one sort deals with the condition of smallest element first
        sort(products.begin(),products.end());
        
        int j = 0;
        vector<string> dos;
		//dos will store the ever changing subset of strings which are prefixes to searchWord
		
		//For the initial subset with first character matching
        while(j<m)
        {
            if(searchWord[0]==products[j][0])
            {
                dos.push_back(products[j]);
                if(ans[0].size()<3)
                {
                    ans[0].push_back(products[j]);
                }
            }
            j++;
        }
        
		//for all the next characters we simply keep choosing from dos
		//as we are done choosing, we replace dos by the shortened subset
        for(int i=1; i<n; i++)
        {
            int k = 0;
            vector<string> temp;
            while(k<dos.size())
            {
                if(dos[k].size()>i)
                {
                    if(dos[k][i]==searchWord[i])
                    {
                        //cout<<"for i = "<<i<<" word="<<dos[k]<<endl;
                        temp.push_back(dos[k]);
                        if(ans[i].size()<3)
                        {
                            ans[i].push_back(dos[k]);
                        }
                    }
                }
                    
                k++;
            }
            dos = temp;
        }
        
        return ans;
        
    }
};