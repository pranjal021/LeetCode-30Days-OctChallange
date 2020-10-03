class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        
        if(k==0){
            for(auto x: m){
                if(x.second>1) count++;
            }
            return count;
        }
        
        for(auto x:m){
            if(m.count(x.first-k)) count++;
        }
        
        return count;
    }
};