class Solution {
public:
     
	 // Fn to extract Contents from the string
    vector<string> extractContent(string &s){
        
        bool flg=0;
        vector<string> ans;
        string content="";
        for(char &c:s){
            if(c==')'){
                ans.push_back(content);
                flg=0;
                content.clear();
            }
            if(flg)
                content.push_back(c);
            if(c=='(')
                flg=1;
                
        }
        return ans;
    }
    
	// Fn to extract paths from the string
    vector<string> extractPath(string &s){
        
        bool flg=0;
        vector<string> ans;
        string path="";
        string head="";
        int n=s.size();
        int i=0;
        for(;i<n;i++){
            if(s[i]==32){
                head.push_back('/');
                break;
            }
            head.push_back(s[i]);
        }
        for(;i<n;i++){
            if(s[i]=='('){
                flg=0;
                ans.push_back(head+path);
                path.clear();
            }
            if(flg)
                path.push_back(s[i]);
            if(s[i]==32)
                flg=1;   
        }
        return ans;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      
        map<string,vector<string>> mp;    // store content and paths
        vector<vector<string>> ans;
        vector<string> content;       // to store content
        vector<string> path;          // to store paths
        for(auto &s:paths){
           content=extractContent(s);  // extracting content 
           path=extractPath(s);            // extracting paths
		   
           for(int i=0;i<content.size();i++)
                mp[content[i]].push_back(path[i]);
            
        }
        for(auto &it:mp){
            if(it.second.size() > 1)               // if duplicate 
                ans.push_back(it.second);
        }
        return ans;
    }
};