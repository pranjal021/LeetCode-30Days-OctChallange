class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)return 1;
        if(N==1)return 0;
    
        int compliment_ans = 0;
        int p=0;
        
        while(N){
            
            if(N%2 == 0) compliment_ans += (pow(2,p)); 
            //if (N%2 == 0), then its compliment digit is '1', so we will calculate ans
            //for the SET BIT;
            p++;
            N=N/2;
        }
        return compliment_ans;
    }
};