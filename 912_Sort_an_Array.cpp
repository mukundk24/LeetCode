class Solution
{
public:
    void merge(vector<int> &nums, int s, int e)
    {
        int mid = (s + e) / 2;
        vector<int> first, second;
        int len1 = mid - s + 1, len2 = e - mid;
        for (int i = s; i <= mid; i++)
        {
            first.push_back(nums[i]);
        }
        for (int i = mid + 1; i <= e; i++)
        {
            second.push_back(nums[i]);
        }

        int i1 = 0, i2 = 0, i = s;
        while (i1 < len1 && i2 < len2)
        {
            if (first[i1] > second[i2])
            {
                nums[i] = second[i2];
                i++, i2++;
            }
            else
            {
                nums[i] = first[i1];
                i++, i1++;
            }
        }

        while (i1 < len1)
        {
            nums[i] = first[i1];
            i++, i1++;
        }
        while (i2 < len2)
        {
            nums[i] = second[i2];
            i++, i2++;
        }
    }
    void sort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return;
        int mid = (s + e) / 2;

        sort(nums, s, mid);
        sort(nums, mid + 1, e);

        merge(nums, s, e);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};