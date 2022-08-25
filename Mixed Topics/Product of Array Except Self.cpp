class Solution {
public:
    vector<int> productExceptSelf(vector<int>& leftToRight) {
        int n = leftToRight.size();
        vector<int> rightToLeft(n,leftToRight[n-1]);
        for(int i=n-2; i>=0; --i) {
            rightToLeft[i] = leftToRight[i] * rightToLeft[i+1];
        }
        for(int i=1; i<n; ++i) {
            leftToRight[i] *= leftToRight[i-1];
        }     
        for(int i=0; i<n; ++i) {
            if(i==0) {
                rightToLeft[i] = rightToLeft[i+1];
            }
            else if(i==n-1) {
                rightToLeft[i] = leftToRight[i-1];
            }
            else{
                rightToLeft[i] = rightToLeft[i+1]*leftToRight[i-1];
            }
        }
        return rightToLeft;
    }
};
