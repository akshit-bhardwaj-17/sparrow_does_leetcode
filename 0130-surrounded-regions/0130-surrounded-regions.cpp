class Solution {
public: 
void func(int row, int col,vector<vector<char>>& board,vector<vector<bool>>& vis,int & m ,int &n)
{
    if(row>=0&&row<m&&col>=0&&col<n &&!vis[row][col]&&board[row][col]=='O')
    {
        vis[row][col]=true;
        board[row][col]='@';
        func(row+1,col,board,vis,m,n);
         func(row-1,col,board,vis,m,n);
          func(row,col+1,board,vis,m,n);
           func(row,col-1,board,vis,m,n);
    }
}
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n = board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));

       for(int col = 0 ;col<n;col++)
       {
        if(board[0][col]=='O')
        {
            func(0,col,board,vis,m,n);
        }
        if(board[m-1][col]=='O')
        {
              func(m-1,col,board,vis,m,n);
        }
       }
        for(int row = 0 ;row<m;row++)
       {
        if(board[row][0]=='O')
        {
            func(row,0,board,vis,m,n);
        }
        if(board[row][n-1]=='O')
        {
              func(row,n-1,board,vis,m,n);
        }
       }
       for(int i =0;i<m;i++)
       {
        for( int j = 0 ;j<n;j++)
        {
          if(board[i][j]=='@')
           board[i][j]='O';
           else if(board[i][j]=='O')  
           {
            board[i][j]='X';
           }
        }
       }
    }
};