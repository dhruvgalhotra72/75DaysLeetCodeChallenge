class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2) return true;

        int k = s1.size();

        for(int i = k; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;        // new char add
            freq2[s2[i - k] - 'a']--;    // old char remove

            if(freq1 == freq2) return true;
        }

        return false;
    }
};