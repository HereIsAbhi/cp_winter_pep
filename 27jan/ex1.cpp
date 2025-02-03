// leetcode unique path 3

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsIII(vector<vector<int>>& grid){
    int r=grid.size(); int c=grid[0].size();
    int remaining=0; int startx=0; int starty=0; 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                startx=i; starty=j;
            }
            else if(grid[i][j]==0){
                remaining++;
            }
        }
    }
    return backtrack(grid,startx,starty,remaining+1);

}

int backtrack(vector<vector<int>>& grid,int x,int y,int remaining){
    if(x<0 || y<0 || x>=grid.size()||y>=grid[0].size() || grid[x][y]==-1){
        return 0;
    }

    if(grid[x][y]==2){
        return remaining== -1?1:0;

    }
    grid[x][y]=-1;
    int paths=0;
    paths+= backtrack(grid,x+1,y,remaining-1);
    paths+= backtrack(grid,x-1,y,remaining-1);
    paths+= backtrack(grid,x,y+1,remaining-1);
    paths+= backtrack(grid,x,y-1,remaining-1);

    grid[x][y]=0;
    return paths;
}