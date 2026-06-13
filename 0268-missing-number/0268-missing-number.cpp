//Missing Number in Different ways : Test all one by one
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int a:nums){
            freq[a]++;
        }
       
        for(int i = 0; i<=n; i++){
            if(freq[i] == 0){
                return i;
            }
        }
        
        return 0;
    
    }
};