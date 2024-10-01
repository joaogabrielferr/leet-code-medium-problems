/**
add all numbers to a hash map
them iterate over numbers, if 'i' was already visisted, jump it
otherwise starting visiting all consecutive numbers after 'i' (i + 1, i + 2) if they are in the array,marking them as visited and adding calculated[i]
if 'j' is a consecutive number after 'i' and was already visited, increase calculated[i] with calculated[j] and end the loop
**/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)return 0;

        unordered_map<int,bool>m;
        unordered_map<int,int>calculated;
        unordered_map<int,bool>visited;

        for(int i : nums)m[i] = true;

        for(int i : nums){

            if(visited[i])continue;

            calculated[i] = 1;
            visited[i] = true;

            if(m[i + 1] && calculated[i + 1]){
                calculated[i]+=calculated[i + 1];
            }else if(m[i + 1]){
                int current = i + 1;
                while(m[current]){
                    calculated[i]++;
                    visited[current] = true;
                    current++;
                    if(calculated[current]){
                        calculated[i]+=calculated[current];
                        break;
                    }
                }
            }
        }

        int ans = 0;
        for(auto &i : calculated){
            ans = max(ans,i.second);
        }

        return ans; 

    }
};
