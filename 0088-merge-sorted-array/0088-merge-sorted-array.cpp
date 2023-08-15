class Solution
{
    public:
    
    
        void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
        {
        
            
            int i = n-1;
            int j = m-1;
            int k = n+m-1;
            
            while (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
            
            while (i >= 0)
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            while (j >= 0)
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            
            return;
            
            
           	// Two Pointer Approach

           	//         int i = m-1;
           	//         int k = n+m-1;
           	//         while(i>=0){
           	//             nums1[k--] = nums1[i--];
           	//         }

           	//         int j=0;
           	//         i = ++k;
           	//         k = 0;
           	//         while(i<n+m && j < n){
           	//             if(nums1[i] < nums2[j]) nums1[k++] = nums1[i++];
           	//             else nums1[k++] = nums2[j++];
           	//         }

           	//         while(i<n+m) nums1[k++] = nums1[i++];
           	//         while(j < n) nums1[k++] = nums2[j++];

           	//         return;

           	//Brute Force

           	//         int k = m;
           	//         int j = 0;
           	//         while(k<m+n && j < n){
           	//             nums1[k++] = nums2[j++];
           	//         }

           	//        	// O(n)

           	//         for(int i = 0; i<m+n; i++) cout << nums1[i] << " ";
           	//         cout << endl;

           	//         sort(nums1.begin(),nums1.end());	// o(nlogn)

           	//         return;
        }
};