class Solution {
public:
    // Builds the LPS (longest prefix suffix) array for KMP
    void longestPrefix(vector<int>& lps, string s) {
        int n = s.length();
        lps[0] = 0;
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Main function to return the shortest palindrome by adding characters in front
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Combine original + '*' + reversed to apply KMP
        string combined = s + '*' + rev;
        int n = combined.size();

        vector<int> lps(n);
        longestPrefix(lps, combined);

        // Characters in rev not part of the prefix are added in front
        return rev.substr(0, s.size() - lps[n - 1]) + s;
    }
};
