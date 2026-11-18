class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int nge_arr[10005];
        std::stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            
            // Pop elements smaller than or equal to the current element
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            
            // If stack is empty, no greater element (-1), otherwise top of stack
            if (st.empty()) {
                nge_arr[num] = -1;
            } else {
                nge_arr[num] = st.top();
            }
            
            st.push(num);
        }

        // Construct the result array for nums1
        std::vector<int> result;
        for (int num : nums1) {
            result.push_back(nge_arr[num]);
        }

        return result;
    }
};