class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            check(s, i, i, start, maxLen);       // odd length
            check(s, i, i + 1, start, maxLen);   // even length
        }

        return s.substr(start, maxLen);
    }

    void check(string &s, int left, int right, int &start, int &maxLen) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        int len = right - left - 1;

        if(len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    }
};