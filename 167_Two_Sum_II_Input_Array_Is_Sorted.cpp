class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        
       int i = 0,j = v.size() - 1;

       while(i < j){

            int x = v[i] + v[j];
            if(x == target)return {i + 1,j + 1};
            if(x > target)j--;
            else i++;
       }

       return {};
       
    }
};
