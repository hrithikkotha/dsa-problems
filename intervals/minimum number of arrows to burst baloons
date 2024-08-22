class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 1)
            return 1;

        vector<pair<int, int>> pr;

        for (int i = 0; i < points.size(); i++) {
            pr.push_back({points[i][0], points[i][1]});
        }

        sort(pr.begin(), pr.end());

        // vector<pair<int,int>> res;
        int front, end, count = 0;
        int t;
        for (int i = 0; i < pr.size(); i++) {
            if (i == 0) {
                front = pr[i].first;
                end = pr[i].second;
                t = 0;
            } else {

                if (pr[i].first >= front && pr[i].first <= end) {
                    front = max(front, pr[i].first);
                    end = min(end, pr[i].second);
                    t = 0;
                } else {
                    // res.push_back({front,end});
                    count++;
                    front = pr[i].first;
                    end = pr[i].second;
                    t = 1;
                }
            }
        }

        // res.push_back({front,end});

        // return res.size();

        return count + 1;
    }
};
