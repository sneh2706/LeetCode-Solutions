/*

Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer K such that she can eat all the bananas within H hours.

*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int n = piles.size(), lo=1, hi=1000000000;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            int total = 0;
            for(int p: piles)
                total += (p+mid-1)/mid;
            
            if(total>H)
                lo = mid+1;
            else
                hi = mid;
        }
        
        return lo;
    }
};
