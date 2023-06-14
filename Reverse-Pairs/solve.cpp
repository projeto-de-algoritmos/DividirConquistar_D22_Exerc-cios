class Solution {
public:
    int mergeAndCount(std::vector<int>& nums, int left, int mid, int right) {
        int count = 0;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                count += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }

        sort(nums.begin() + left, nums.begin() + right + 1);

        return count;
    }

    int SortAndCount(std::vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int rev1 = SortAndCount(nums, left, mid) ;
        int rev2 = SortAndCount(nums, mid + 1, right);
        int rev3 = mergeAndCount(nums, left, mid, right);

        return rev1 + rev2 + rev3;
    }

    int reversePairs(std::vector<int>& nums) {
        return SortAndCount(nums, 0, nums.size() - 1);
    }

};