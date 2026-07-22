class Solution {
private:
// An Elegant DFS Approach
   
    void modImage(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int refColor){
      
        // Base Case
        if(sr < 0 || sr >= m || sc < 0 || sc >= n){
            return;
        }

//  neighbouring pixel color differs from the original color(refColor)
        if(image[sr][sc] != refColor){
            return;
        }
// neighbouring pixel color matches the original color(refColor)
        image[sr][sc] = color;
        // dfs traversal
        // UP
        modImage(image,  sr-1,  sc,  color,  m,  n, refColor);
        // Down
        modImage( image,  sr+1,  sc,  color,  m,  n, refColor);
        // Left
        modImage( image,  sr,  sc-1,  color,  m,  n, refColor);
        //Right
        modImage( image,  sr,  sc+1,  color,  m,  n, refColor);

        }
    

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
       
    // Original color 
        int refColor = image[sr][sc];
        if (refColor == color) {
            return image;
        }
    // Recursive DFS Call
        modImage(image, sr, sc, color, m, n, refColor);
        return image;
    }
};