class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        auto _inverse = [&](int start,int end){
            while(start < end){
                int aux = nums[start];
                nums[start] = nums[end];
                nums[end] = aux;
                start++;
                end--;
            }
        };


        k = k % nums.size();

        _inverse(0,nums.size() - 1);
        _inverse(0,k - 1);
        _inverse(k,nums.size() - 1);

        // vector<int>v;
        // if(k > nums.size())k = k % nums.size();

        // for(int i = nums.size() - k;i<nums.size();i++)v.push_back(nums[i]);
        // for(int i = 0;i<nums.size() - k;i++)v.push_back(nums[i]);

        // nums = v;
    }
};
