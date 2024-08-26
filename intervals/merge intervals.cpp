class Solution {
public:
    void merge(vector<vector<int>>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<vector<int>> L(n1,vector<int>(2,0)), R(n2,vector<int>(2,0));

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];

        for (int i = 0; i < n2; i++)
            R[i] = arr[m + 1 + i];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i][0] <= R[j][0]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }

    void mergeSort(vector<vector<int>>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // vector<int> a;
        // for (int i = 0; i < intervals.size(); i++) {
        //     a.push_back(intervals[i][0]);
        // }
        // sort(a.begin(),a.end());
        mergeSort(intervals,0,intervals.size()-1);
       // for (int)
       int i=0,prev=0,end=0;
       vector<vector<int>> ans;
        while(i<intervals.size()){
            if(i==0){
                prev=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                if(intervals[i][0]>=prev&&intervals[i][0]<=end){
                    if(intervals[i][1]>end){
                        end=intervals[i][1];
                    }
                }
                else{
                    vector<int> a;

                    a.push_back(prev);
                    a.push_back(end);
                    ans.push_back(a);

                    prev=intervals[i][0];
                    end=intervals[i][1];
                }
            }
            i++;
        }

        vector<int> a;
        a.push_back(prev);
        a.push_back(end);
        ans.push_back(a);

        return ans;
    }
};
