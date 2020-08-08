/*

Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n = letters.size(), lo= 0, hi = n-1, mid;
        while(lo<hi)
        {
            mid = lo+(hi-lo)/2;
            if(letters[mid]>target)
                hi = mid;
            else
                lo = mid+1;
        }
        
        
        if(target<letters[0])
            return letters[0];
        else if(target>=letters[n-1])
            return letters[0];
        
        return letters[lo];
        
    }
};
