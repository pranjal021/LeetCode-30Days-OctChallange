class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A == B)
            return (set<char>(A.begin(),A.end()).size()  < A.size());
        
        
        int n = A.length();
        int l=0;
        int e = n-1;
        
        while(l<n && A[l]==B[l])
            l++;
        
        while(e>=0 && A[e]==B[e])
            e--;
        
        if(l<e)
            swap(A[l],A[e]);
        
        return A==B;
    }
};