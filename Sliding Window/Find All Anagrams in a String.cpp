/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

*/

class Solution {
public:
    bool maps_eq(unordered_map<char,int> &p_freq, unordered_map<char,int> &window) {
        
        int pmap_sz = p_freq.size();
        int w_sz = 0;
        
        for(auto it=window.begin(); it!=window.end(); ++it) 
            if(it->second > 0) w_sz++;
        
        if(pmap_sz != w_sz) return false;
        
        for(auto it=window.begin(); it!=window.end(); ++it) {
            
            if(it->second == 0) continue;
            if(p_freq.find(it->first)==p_freq.end() || p_freq[it->first]!=it->second) return false;
        }
        
        return true;
        
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        int p_sz = p.size();
        int s_sz = s.size();
        
        if(s_sz < p_sz) return res;
        
        unordered_map<char,int> p_freq;
        for(int i=0; i<p_sz; ++i) p_freq[p[i]]++;
        
        unordered_map<char,int> window;
        for(int i=0; i<p_sz; ++i) window[s[i]]++;
        if(maps_eq(p_freq,window)) res.push_back(0);
        
        for(int i=1; i<s_sz; ++i) {
            
            window[s[i-1]]--;
            if(i+p_sz-1 < s_sz) window[s[i+p_sz-1]]++;
            else break;
            
            if(maps_eq(p_freq,window)) res.push_back(i);
            
        }
        
        return res;
        
    }
};