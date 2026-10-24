class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char ss[256] = {0};
        char tt[256] = {0};

        for(int i = 0; i < s.length(); i++){
            char a = s[i], b = t[i];
            if(ss[a] != tt[b])
                return false;
            ss[a] = tt[b] = i + 1;
        }

        return true;
    }
};