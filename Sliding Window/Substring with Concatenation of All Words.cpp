/*

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of 
substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

*/

class Solution {
public:
    bool equal(unordered_map<string,int> &substr_freq, unordered_map<string,int> &wrd_freq) {
        
        if(substr_freq.size() != wrd_freq.size()) return false;
        for(auto it=substr_freq.begin(); it!=substr_freq.end(); ++it) {
            
            if(wrd_freq.find(it->first)==wrd_freq.end() || it->second!=wrd_freq[it->first])
                return false;
            
        }
        
        return true;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        int wrd_sz = words.size();
        if(wrd_sz == 0) return res;
        
        int k = words[0].size();
        
        unordered_map<string,int> wrd_freq;
        for(int i=0; i<wrd_sz; ++i) wrd_freq[words[i]]++;
        
        int s_sz = s.size();
        for(int i=0; i<s_sz; ++i) {
            
            if(i+(k*wrd_sz)-1 >= s_sz) break;
            unordered_map<string,int> substr_freq;
            
            int j=i;
            for(int times=0; times<wrd_sz; ++times) {
                substr_freq[s.substr(j,k)]++;
                j += k;
            }
            
            if(equal(substr_freq,wrd_freq)) res.push_back(i);
            
        }
        
        return res;
        
    }
};