class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            // If character already seen and inside current window
            if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right; // update last seen index
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};