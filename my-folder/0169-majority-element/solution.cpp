class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        // Find the candidate for majority element
        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Verify the candidate
        count = 0;
        for(int num : nums) {
            if(num == candidate) {
                count++;
            }
        }

        if(count > nums.size() / 2) {
            return candidate;
        }

        return -1;
    }
};
