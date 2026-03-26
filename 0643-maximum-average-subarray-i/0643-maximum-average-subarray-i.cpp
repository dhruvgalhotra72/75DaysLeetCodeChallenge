class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;
        
        // Step 1: First window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        double maxSum = windowSum;
        
        // Step 2: Slide the window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];       // add next element
            windowSum -= nums[i - k];   // remove previous element
            
            maxSum = max(maxSum, windowSum);
        }
        
        // Step 3: Return average
        return maxSum / k;
    }
};