// link = https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Solution

class Solution {
    public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool sortByEnd(pair<int, int> &pair1, pair<int, int> &pair2){
        return pair1.second < pair2.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int, int>> meetings;
        int n = start.size();
        for(int i=0; i<n; i++){
            meetings.push_back(make_pair(start[i], end[i]));
        }
        sort(meetings.begin(), meetings.end(), sortByEnd);
        int selected_meet = meetings[0].second;
        int count = 1;
        for(int i=1; i<n; i++){
            if(selected_meet < meetings[i].first){
                selected_meet = meetings[i].second;
                count++;
            }
        }
        return count;
    }
};