class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        
        int dp[nums.size()];
        
        //1.rob first house, cant rob last house 
        dp[0]=nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size()-1;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans1 = dp[nums.size()-2];
        
        //2. rob the second house, till last house
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans2 = dp[nums.size()-1];
        return max(ans1,ans2);
    }
};