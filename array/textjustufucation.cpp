#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
class Solution {
public:
    void align(string & a, int count, int maxWidth) {
        int i = 0;
        if (count -1!= 0) {
            int total=(maxWidth-a.size());
            int space=total/(count-1);
            int espace=total%(count-1);
            string b;
            while (i < a.size()) {
                if (a[i] == ' ') {
                    b += a[i];
                    int s = space;
                   // cout<<s<<endl;
                    while (s>0) {
                        b +=" ";
                        s--;
                        cout<<b;
                    }
                    if (espace > 0) {
                        b += ' ';
                        espace--;

                    }
                } else {
                    b += a[i];
                }
                i++;
            }
            a = b;
        } else {

            int ss = maxWidth - a.size();
            while (ss>0) {
                a +=" ";
                ss--;
            }
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        string a;
        int count = 0;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {

          //  cout << i;
            if (a.empty()) {
                a += words[i];
                count++;
                continue;
            }

            if (a.size() + words[i].size() + 1 <= maxWidth) {
                a += ' ';
                a += words[i];
                count++;
            } else {
                cout<<a.size()<<" "<<count<<endl;
                align(a, count, maxWidth);
               // cout << a;
                ans.push_back(a);
                a.clear();
                count=0;
                i--;
            }
        }
        if(count!=0){
            int space=maxWidth-a.size();
            while(space){
                a+=' ';
                space--;
            }

            ans.push_back(a);
        }

        return ans;
    }
};
int main(){
    Solution s;
    vector<string> words={"This","is","an","example","of","text","justification"};
    int maxWidth=16;
    vector<string> res=s.fullJustify(words,maxWidth);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
       
}
