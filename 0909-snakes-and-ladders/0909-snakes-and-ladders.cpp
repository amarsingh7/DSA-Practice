class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(); // Size of the board
        int lbl = 1; // Label for each cell

        // Mapping of cell number to its (row, column) position
        vector<pair<int, int>> cells(n * n + 1);

        // Columns are initially in increasing order
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        // fills values from 0 to n-1;

        // Fill in the cell positions in a zigzag pattern
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column}; // Store cell's position
            }
            reverse(columns.begin(), columns.end()); // Reverse columns for zigzag
        }

        // Distance array to keep track of minimum moves to reach each cell
        vector<int> dist(n * n + 1, -1);
        dist[1] = 0; // Start from cell 1

        queue<int> q; // Queue for BFS traversal
        q.push(1); // Start BFS from cell 1

        // BFS traversal
        while (!q.empty()) {
            int curr = q.front(); // Current cell
            q.pop();

            // Explore next possible cells after rolling the dice
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next]; // Get (row, column) position of next cell

                // If there's a snake or ladder transition, update destination
                int destination = (board[row][column] != -1) ? board[row][column] : next;

                // If destination hasn't been visited yet, update its distance and enqueue
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }

        // The distance from cell 1 to the last cell gives the minimum moves
        return dist[n * n];
    }
};
