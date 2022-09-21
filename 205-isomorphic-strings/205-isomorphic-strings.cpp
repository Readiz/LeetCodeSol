class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        char visitedA[300] = {0, }, visitedB[300] = {0, };
        char s1 = 1, s2 = 1;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] >= 30) {
                if (visitedA[s[i]] == 0) {
                    visitedA[s[i]] = s1++;
                }
                s[i] = visitedA[s[i]];
            }
        }
        for(int i = 0; i < t.size(); ++i) {
            if (t[i] >= 30) {
                if (visitedB[t[i]] == 0) {
                    visitedB[t[i]] = s2++;
                }
                t[i] = visitedB[t[i]];
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};