/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

*/

class Solution {
public:
    string minWindow(string str1, string str2) 
    {

      int m = str1.size(), n = str2.size();
      if(m==0 || n==0) return "";
    
      string str;
      int minlen = INT_MAX, left=0, count=0;
    
      unordered_map<char,int> lettercount;
    
      for(int i=0; i<str2.size(); ++i)
      lettercount[str2[i]]++;
    
      for(int right=0; right<str1.size(); ++right)
      {
        if(--lettercount[str1[right]]>=0)
        count++;
        
        while(count==str2.size())
        {
            if(minlen>right-left+1)
            {
                minlen = right-left+1;
                str = str1.substr(left,right-left+1);
            }
            
            if(++lettercount[str1[left]]>0)
            --count;
        
            ++left;
        }
      }
    
    return str;
    }
};