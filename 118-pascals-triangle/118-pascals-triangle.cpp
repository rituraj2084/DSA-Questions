class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix(numRows);
  	for(int i = 0; i < numRows; i++){
		matrix[i].resize(i+1);
	  for(int j = 0; j <= i; j++){
		  if(j == 0 || j == i){
			  matrix[i][j] = 1;
		  }
		  else{
			  matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j]; 
		  }
	  }
  	}
	return matrix; 
    }
};