class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ss, tt;
        for(int i = 0; i < s.length(); i++){
            if(ss.find(s[i]) != ss.end()){
                if(ss[s[i]] != t[i])
                    return false;
            }
            else
                ss[s[i]] = t[i];

            if(tt.find(t[i]) != tt.end()){
                if(tt[t[i]] != s[i])
                    return false;
            }
            else
                tt[t[i]] = s[i];
        }
        return true;
    }
};