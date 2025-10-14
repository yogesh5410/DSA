class Solution {
public:

    bool isAnagram(string s, string t) {
        vector<int> f1(26, 0), f2(26, 0);
        if(s.size()!=t.size()) return false;
        for(char ch : s) f1[ch-'a']++;
        for(char ch : t) f2[ch-'a']++;
        for(int i=0; i<26; i++) if(f1[i]!=f2[i]) return false;
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        for(int i=1; i<n; i++) {
            if(isAnagram(words[i-1], words[i])) {
                words.erase(words.begin() + i);
                n--;
                i--;
            }
        }

        return words;
    }
};

