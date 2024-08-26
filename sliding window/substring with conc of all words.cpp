class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& wordsss) {
        int ss=s.size(),wordss=wordsss.size(),words=wordsss[0].size();

        unordered_map<string,int> mp;
    
        for(auto i:wordsss){
            mp[i]++;
        }
         vector<int> ans;
        if(mp.size()==1&&wordss>50){
            for(int i=0;i<ss-wordss+1;i++){
                ans.push_back(i);
            }
            return ans;
        }

       
        for(int i=0;i<=ss-words*wordss;i++){
            unordered_map<string,int> np;
            np=mp;
            int k=i,count=0;
            for(int j=0;j<wordss*words;j+=words){
                string a=s.substr(k+j,words);
                if(np.find(a)!=np.end()){
                    if(np[a]>0){
                        count++;
                        np[a]--;
                    }
                    else{
                        break;
                    }

                }
                else{
                    break;
                }

            }
            if(count==wordss){
                ans.push_back(i);
            }

        }
        return ans;
    }
};
