class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlen = 0;
        vector<string>lines;
        stringstream ss(input);
        string line;
        while(getline(ss,line,'\n')){
            lines.push_back(line);
        }
        stack<pair<int,int>>st; //{depth,length}
        for(string &line:lines){
            int depth = 0;
            int i=0;
            while(i<line.size() && line[i]=='\t'){
                depth++;
                i++;
            }
            while(!st.empty() && st.top().first>=depth){
                st.pop();
            }
            int linelen = line.size()-i;
            int pathlen = (st.empty()?0:st.top().second)+linelen;
            st.push({depth,pathlen});
            if (line.find('.') != string::npos) {
                maxlen = max(maxlen, pathlen + depth);
            }
        }
        return maxlen;
        
    }
};