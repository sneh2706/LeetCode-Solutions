class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        int n = A.size();
        unordered_map<int,int> umap1;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
                umap1[A[i]+B[j]]++;
        }
        
        int counts = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int sum = C[i]+D[j];
                sum = -1*sum;
                if(umap1.find(sum)!=umap1.end())
                    counts += umap1[sum];
            }
        }
        
        return counts;
    }
};


// class Solution {
// public:
//     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
//     {
//         int n = A.size();
//         unordered_map<int,int> umap1,umap2;
//         for(int i=0; i<n; ++i)
//         {
//             for(int j=0; j<n; ++j)
//             {
//                 umap1[A[i]+B[j]]++;
//                 umap2[C[i]+D[j]]++;
//             }
//         }
        
//         int counts = 0;
//         for(auto it=umap1.begin(); it!=umap1.end(); ++it)
//         {
//             int x = (*it).first;
//             int y = (*it).second;
//             int z = -1*x , t;
//             if(umap2.find(z)==umap2.end())
//                 t=0;
//             else
//                 t = umap2[z];
            
//             counts += (t*y);
//         }
        
//         return counts;
//     }
// };
