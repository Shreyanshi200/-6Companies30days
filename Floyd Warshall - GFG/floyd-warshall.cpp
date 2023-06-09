//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int v = matrix.size();
	    vector<vector<int>>costs(matrix.size(),vector<int>(matrix.size()));
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            costs[i][j] = matrix[i][j];
	        }
	    }
	    for(int k=0;k<v;k++){
	        for(int i=0;i<v;i++){
	            for(int j=0;j<v;j++){
	                if(costs[i][k]!=-1 && costs[k][j]!=-1){
	                    if(costs[i][j]==-1){
	                        costs[i][j] = costs[i][k]+costs[k][j];
	                    }else{
	                        costs[i][j] = min(costs[i][j],costs[i][k]+costs[k][j]);
	                    }
	                }
	            }
	        }
	    }
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	             matrix[i][j]=costs[i][j];
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends