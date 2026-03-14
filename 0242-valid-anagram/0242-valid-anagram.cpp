class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> ms;
        for(int i=0;i<s.length();i++){
            ms[s[i]]++;
        }
        map<char,int> mt;
        for(int i=0;i<t.length();i++){
            mt[t[i]]++;
        }
        if(ms==mt)
        return true;
        else
        return false;
    }
};