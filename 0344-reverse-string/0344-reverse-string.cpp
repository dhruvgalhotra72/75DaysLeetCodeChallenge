class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseStringHelper(s, 0, s.size() - 1);
    }

    void reverseStringHelper(vector<char>& s, int left, int right) {
        if (left >= right) return;
        swap(s[left], s[right]);
        reverseStringHelper(s, left + 1, right - 1);
    }
};
