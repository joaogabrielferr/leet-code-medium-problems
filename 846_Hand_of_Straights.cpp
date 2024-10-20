class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if(n % groupSize != 0)return false;

        sort(hand.begin(),hand.end());

        map<int,stack<int>>numberPosition;
        vector<bool>visited(n,false);

        for(int i = 0;i<n;i++){
            numberPosition[hand[i]].push(i);
        }

        for(int i = 0;i<n;i++){

            if(visited[i])continue;

            visited[i] = true;

            int count = 1;
            int current = hand[i] + 1;
            while(count < groupSize){

                if(numberPosition.find(current) == numberPosition.end()){
                    break;
                }
                if(numberPosition[current].empty()){
                    break;
                }

                int next_pos = numberPosition[current].top();
                numberPosition[current].pop();

                visited[next_pos] = true;
                count++;
                current++;
            }

            if(count < groupSize)break;
        }

        for(bool b : visited){
            if(!b)return false;
        }
        
        return true;




    }
};
