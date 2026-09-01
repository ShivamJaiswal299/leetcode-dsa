class Solution {
public:
//toughest so far
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        if (a1.size() > a2.size()) swap(a1, a2);
        int n1 = a1.size(), n2 = a2.size();
        int low = 0, high = n1;
        int lefthalf = (n1 + n2 + 1) / 2;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;  
            int mid2 = lefthalf - mid1;        
//HERE IS THE IMP PART - assigning left and right half var: the int_min int_max sht is cuz of the edge cases where all the elements in the left half are from a single array, also u may see, mid1 and mid2 are not index , they are sizes, thatswhy instead of mid1(left) it is mid1-1 and mid+1(right) it is just mid
            int a1left  = (mid1 > 0)  ? a1[mid1 - 1] : INT_MIN;
            int a1right = (mid1 < n1) ? a1[mid1]     : INT_MAX;
            int a2left  = (mid2 > 0)  ? a2[mid2 - 1] : INT_MIN;
            int a2right = (mid2 < n2) ? a2[mid2]     : INT_MAX;

            if (a1left <= a2right && a2left <= a1right) {
                if ((n1 + n2) % 2 != 0)
                    return max(a1left, a2left);
                return (max(a1left, a2left) + min(a1right, a2right)) / 2.0;
            }
            else if (a1left > a2right) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        return -1;//wont reach here!!
    }
};