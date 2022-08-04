class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1= nums1.size();
        int n2 = nums2.size();
        int low = 0;
        int high = n1;
        
        while(low<=high){
            int nums1ctr = (low+high)>>1;
            int nums2ctr = (n1+n2+1)/2 - nums1ctr;
            
            int l1 = (nums1ctr==0)?INT_MIN : nums1[nums1ctr-1];
            int l2 = (nums2ctr==0)?INT_MIN : nums2[nums2ctr-1];
            int r1 = (nums1ctr==n1)?INT_MAX : nums1[nums1ctr];
            int r2 = (nums2ctr==n2)?INT_MAX : nums2[nums2ctr];
            
            if(l1<=r2 and l2<=r1){
                if((n1+n2) % 2 == 0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                } else {
                    return max(l1,l2);
                }
            } else if(l1>r2){
                high = nums1ctr-1;
            } else {
                low = nums1ctr+1;
            }
        }
        return 0.0;
    }
};