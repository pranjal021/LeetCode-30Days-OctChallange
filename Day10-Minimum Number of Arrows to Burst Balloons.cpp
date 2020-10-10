class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        });
        
        int n = points.size();
        int ans = 1;
        if(n==0)return 0;
        int prev = points[0][1];
        for(int i=1;i<n;i++){
            if(prev>=points[i][0])continue;
            ans++;
            prev = points[i][1];
        }
        return ans;
    }
};