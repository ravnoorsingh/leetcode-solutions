class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(q.size()!=0){
            int curr = q.front();
            q.pop();
            for(auto neighbour : rooms[curr]){
                if(not visited.count(neighbour)){ // neighbour not yet visited
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        if(visited.size() == rooms.size()) return true;
        else return false;
    }
};
