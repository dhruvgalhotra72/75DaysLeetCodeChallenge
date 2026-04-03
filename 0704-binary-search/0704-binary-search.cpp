class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==target)
        return 0;

        int beg = 0,end=nums.size()-1;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                beg = mid+1;
            }
        }
        return -1;
    }
};