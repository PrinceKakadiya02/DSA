/*
GFG
Rat in a Maze Problem

Time Complexity: O(4^(n*n))
Space Complexity: O(n*n)   // visited + recursion stack
*/

class Solution {
private:
    // Check if the next cell is valid to move
    bool isSafe(int x, int y, int n,
                vector<vector<int>> &visited,
                vector<vector<int>> &maze) {

        return (x >= 0 && x < n &&
                y >= 0 && y < n &&
                visited[x][y] == 0 &&
                maze[x][y] == 1);
    }

    // Backtracking function to find all paths
    void solve(vector<vector<int>> &maze, int n,
               vector<string> &ans, int x, int y,
               string path, vector<vector<int>> &visited) {

        // Destination reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;   // mark current cell as visited

        // Down
        if (isSafe(x + 1, y, n, visited, maze)) {
            solve(maze, n, ans, x + 1, y, path + 'D', visited);
        }

        // Left
        if (isSafe(x, y - 1, n, visited, maze)) {
            solve(maze, n, ans, x, y - 1, path + 'L', visited);
        }

        // Right
        if (isSafe(x, y + 1, n, visited, maze)) {
            solve(maze, n, ans, x, y + 1, path + 'R', visited);
        }

        // Up
        if (isSafe(x - 1, y, n, visited, maze)) {
            solve(maze, n, ans, x - 1, y, path + 'U', visited);
        }

        visited[x][y] = 0;   // backtrack
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze) {
        int n = maze.size();
        vector<string> ans;

        // If starting cell is blocked
        if (maze[0][0] == 0) return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(maze, n, ans, 0, 0, "", visited);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
