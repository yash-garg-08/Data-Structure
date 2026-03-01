// link - http://leetcode.com/problems/last-stone-weight/description/

// solution 1: using priority queue

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();

        if(n == 1) return stones[0];

        for(auto& it: stones){
            pq.push(it);
        }
        int top1 = 0;
        int top2 = 0;
        while(pq.size() > 1){
            top1 = pq.top();
            pq.pop();
            top2 = pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        int res = pq.top();
        return res;
    }
};