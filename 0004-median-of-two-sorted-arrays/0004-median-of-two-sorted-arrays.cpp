class Solution {
private:
    int kthElement(vector<int>& a, vector<int>& b, int m, int n, int k) {
        // Ensure we always do binary search on the smaller array 
        // to keep time complexity strictly O(log(min(m,n)))
        if (m > n) {
            return kthElement(b, a, n, m, k);
        }
        
        // The minimum number of elements we can pick from 'a' is max(0, k - n)
        // because if k > n, we MUST pick at least (k - n) elements from 'a'.
        int low = max(0, k - n);
        
        // The maximum number of elements we can pick from 'a' is min(k, m)
        // because we can't pick more than k elements, nor more than m elements.
        int high = min(k, m);
        
        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;
            
            // Assign boundary values if the cut is at the extreme ends
            int l1 = (cut1 == 0) ? -1e9 : a[cut1 - 1];
            int l2 = (cut2 == 0) ? -1e9 : b[cut2 - 1];
            int r1 = (cut1 == m) ? 1e9 : a[cut1];
            int r2 = (cut2 == n) ? 1e9 : b[cut2];
            
            // Check if we have found a valid partition
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            // If l1 is greater than r2, we picked too many elements from 'a', move left
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            // Otherwise, we need more elements from 'a', move right
            else {
                low = cut1 + 1;
            }
        }
        
        return -1; // Fallback, though a valid input will never reach here
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t=nums1.size()+nums2.size();
        if(t%2){
            double ans=kthElement(nums1,nums2,nums1.size(),nums2.size(),(t+1)/2);
            return ans;
        }else{
            double x=kthElement(nums1,nums2,nums1.size(),nums2.size(),(t+1)/2);
            double y=kthElement(nums1,nums2,nums1.size(),nums2.size(),(t+1)/2+1);
            double ans=(x+y)/2.0;
            return ans;
        }
    }
};