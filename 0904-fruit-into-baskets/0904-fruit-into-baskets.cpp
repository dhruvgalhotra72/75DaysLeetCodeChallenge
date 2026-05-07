class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;
            
            // If more than 2 types of fruits, shrink window
            while (count.size() > 2) {
                count[fruits[left]]--;
                
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                
                left++;
            }
            
            // Update maximum window size
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};