class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        const int MAX_FRIEND = 1e4;
        const int MAX_ARRIVAL = 1e5;

        //(time, friend number)
        map<int,int>arrivalTimes;
        map<int,vector<int>>leavingTimes;

        int idx = 0;
        for(vector<int> i : times){
            arrivalTimes[i[0]] = idx;
            leavingTimes[i[1]].push_back(idx);
            idx++;
        }

        sort(times.begin(),times.end(),[](vector<int>&a,vector<int>&b){
            return a[0] < b[0];
       });


        map<int,int>friendChair;

        priority_queue<int,vector<int>,greater<int>>pq;

        

        for(int i = 0;i<=MAX_FRIEND;i++){
            pq.push(i);
        }
        
        for(int i = 0;i<=MAX_ARRIVAL;i++){

            if(leavingTimes.find(i) != leavingTimes.end()){

                for(int j : leavingTimes[i]){
                    pq.push(friendChair[j]);
                }
                leavingTimes[i].clear();
            }

            if(arrivalTimes.find(i) != arrivalTimes.end()){

                int smallestChairNumber = pq.top();
                pq.pop();

                friendChair[arrivalTimes[i]] = smallestChairNumber;

                if(arrivalTimes[i] == targetFriend)return smallestChairNumber;
            }

        }






        return 0;


    }
};
