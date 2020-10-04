class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }else{
            return a[0]<b[0];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0)return 0;
        
        sort(intervals.begin(),intervals.end(),comp);
        
        int count =1;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>= start && intervals[i][1]<=end){
                continue;
            }else{
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
                count++;
            }
        }
        
        return count;        
    }
};


//to understand the concept more,
//refer to this youtube video :: https://youtu.be/EbF3TJsobD0