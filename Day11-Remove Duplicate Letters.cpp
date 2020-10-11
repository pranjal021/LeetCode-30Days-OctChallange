class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26,0);
        vector<int> isUsed(26,0);
        string str = "";
        
        for(auto x:s){
            count[x-'a']++;
        }
        
        for(auto x:s){
            count[x-'a']--;
            
            if(isUsed[x-'a'] == false){
                
                while(str.length()>0 && x<str.back() && count[str.back()-'a']>0){
                    isUsed[str.back()-'a'] = false;
                    str.pop_back();
                }
                
                str.push_back(x);
                isUsed[x-'a']=true;
                
            }
        }
        
        return str;
        
    }
};