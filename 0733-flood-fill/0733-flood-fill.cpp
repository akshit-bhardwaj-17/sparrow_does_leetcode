class Solution {
public:

    void dfs(vector<vector<int>>& image,
             vector<vector<bool>>& vis,
             int i, int j,
             int m, int n,
             int oldColor,
             int newColor)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;

        if(vis[i][j])
            return;

        if(image[i][j] != oldColor)
            return;

        vis[i][j] = true;

        image[i][j] = newColor;

        dfs(image, vis, i+1, j, m, n, oldColor, newColor);
        dfs(image, vis, i-1, j, m, n, oldColor, newColor);
        dfs(image, vis, i, j+1, m, n, oldColor, newColor);
        dfs(image, vis, i, j-1, m, n, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color)
    {
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        vector<vector<bool>> vis(m, vector<bool>(n,false));

        dfs(image, vis, sr, sc, m, n, oldColor, color);

        return image;
    }
};