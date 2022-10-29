#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);
void sort_endtime(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);

void sort_endtime(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
    vector<array<int, 3>> all;
    for (unsigned int i=0; i<startTime.size();i++){
        all.push_back(array<int, 3>{startTime[i], endTime[i], profit[i]});
    }
    sort(all.begin(), all.end(), [](const array<int, 3>a, const array<int, 3>b){return a[1]<b[1];});
    for (unsigned int i=0; i<startTime.size();i++){
        startTime[i] = all[i][0];
        endTime[i] = all[i][1];
        profit[i] = all[i][2];
    }
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
    int ans;
    unsigned int total = startTime.size();
    /* Sort the arrays with increasing endTime */
    sort_endtime(startTime, endTime, profit);
    for(auto i:startTime)cout<<" "<<i;
    cout<<endl;
    for(auto i:endTime)cout<<" "<<i;
    cout<<endl;
    for(auto i:profit)cout<<" "<<i;
    cout<<endl;
    /* Find prev(j) */
    vector<int>prev;
    for (uint i=0;i<total;i++){
        vector<int>::iterator it = upper_bound(endTime.begin(), endTime.end(), startTime[i]);
        prev.push_back(it-endTime.begin()-1);
    }
    /* for(auto i:prev)cout<<i<<" ";cout<<endl; */
    /* Make the profit dp array */
    vector<int> dp(total);
    dp[0] = profit[0];
    int prev_profit = 0;
    for(uint i=1;i<total;i++){
        if (prev[i]==-1){
           prev_profit = 0; 
        }
        else{
            prev_profit = dp[prev[i]];
        }
        if (prev_profit + profit[i] > dp[i-1]){
            dp[i] = prev_profit+profit[i];
        }
        else {dp[i] = dp[i-1];}
    }
    for(auto i:dp)cout<<i<<" ";cout<<endl;
    return dp[total-1];
}

int main(){
    vector<int> startTime = vector<int>{1,2,3,4,6};
    vector<int> endTime = vector<int>{3,5,10,6,9};
    vector<int> profit = vector<int>{20,20,100,70,60};
    cout<<jobScheduling(startTime, endTime, profit);
    return 0;
}
