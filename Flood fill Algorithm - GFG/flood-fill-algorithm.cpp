//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr, int sc,vector<vector<int>>& image,int newColor,int color){
        if(sr<0 || sc<0||sr>=image.size()||sc>=image[0].size()||image[sr][sc]!=color||image[sr][sc]==newColor){
            return;
        }

        image[sr][sc]=newColor;
        dfs(sr+1,sc,image,newColor,color);
        dfs(sr-1,sc,image,newColor,color);
        dfs(sr,sc-1,image,newColor,color);
        dfs(sr,sc+1,image,newColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        dfs(sr,sc,image,newColor,image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends