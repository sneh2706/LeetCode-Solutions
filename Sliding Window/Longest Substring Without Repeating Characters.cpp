/*

Given a string, find the length of the longest substring without repeating characters.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        if(n<=1)
            return n;
        
        unordered_map<char,int> umap;
        int maxm = 0;
        int i=0, j=0;
        
        while(j<n) {
            if(umap[str[j]]==0) {
                umap[str[j]]++;
                j++;
            }
            else {
                if(j-i > maxm) {
                    maxm = j-i;
                }
                char x = str[j];
                while(i<=j) {
                    if(str[i]!=x) {
                        umap[str[i]]--;
                        i++;
                    }
                    else {
                        umap[str[i]]--;
                        i++;
                        break;
                    }
                }
            }
        }
        
        maxm = max(maxm,n-i);
        return maxm;
    }
};