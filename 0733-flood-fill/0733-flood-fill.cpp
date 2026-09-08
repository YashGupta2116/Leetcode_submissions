class Solution {
public:
    void flood(vector<vector<int>>& image, int i, int j, int color, int startColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != startColor) return;
        if (image[i][j] == color) return;
        image[i][j] = color;

        flood(image, i+1, j, color, startColor);
        flood(image, i-1, j, color, startColor);
        flood(image, i, j+1, color, startColor);
        flood(image, i, j-1, color, startColor);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        flood(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};