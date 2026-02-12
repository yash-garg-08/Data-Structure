// Link = https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Solution using Greedy Algorithm

class Solution {
    public:
        static bool comp(pair<double, double> &pair1, pair<double, double> &pair2){
            return pair1.first > pair2.first;
        }
        double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
            // code here
            int n = val.size();
            vector<pair<double, double> >knapsack;
            
            for(int i=0; i<n; i++){
                double valPerWt = (double)val[i]/wt[i];
                knapsack.push_back(make_pair(valPerWt, wt[i]));
            }
            
            sort(knapsack.begin(), knapsack.end(), comp);
            double max_profit = 0;
            for(int i=0; i<n; i++){
                if(knapsack[i].second <= capacity){
                    capacity = capacity - knapsack[i].second;
                    max_profit = max_profit + (knapsack[i].first*knapsack[i].second);
                }else{
                    max_profit = max_profit + (knapsack[i].first*capacity);
                    break;
                }
            }
            return max_profit;
        }
};
