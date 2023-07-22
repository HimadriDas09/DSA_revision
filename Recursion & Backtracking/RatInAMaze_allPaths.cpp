#include <bits/stdc++.h> 
void helper(int i, int j, vector<int> &temp, vector<vector<int>> &ans, vector<vector<int>> &maze, int &n)
{
  //edge case
  if(i < 0 || i > n-1 || j < 0 || j > n-1) return;
  if(maze[i][j] == 0) return;
  //bc
  if(i == n-1 && j == n-1) {
    temp[n*n-1] = 1;
    ans.push_back(temp);
    temp[n*n-1] = 0;
    return;
  }

  //sc : go to all the 4 directions
  //marks cur cell as one : ind = i*n + j
  int curInd = i*n + j;
  temp[curInd] = 1;
  //don't go to same cell twice : else runtime err
  //go left
  if(j-1 >= 0 && temp[n*i + j-1] != 1){
    helper(i, j-1, temp, ans, maze, n);
  }
  //right
  if(j+1 < n && temp[n*i + j+1] != 1) {
    helper(i, j+1, temp, ans, maze, n);
  }
  //top
  if(i-1 >= 0 && temp[n*(i-1) + j] != 1){
    helper(i-1, j, temp, ans, maze, n);
  }
  //bottom
  if(i+1 < n && temp[n*(i+1) + j] != 1) {
    helper(i+1, j, temp, ans, maze, n);
  }

  //unmark cur cell && return to prev RC
  temp[curInd] = 0;
  return;
  
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  vector<int> temp(n*n, 0);
  helper(0, 0, temp, ans, maze, n);
  return ans;
}