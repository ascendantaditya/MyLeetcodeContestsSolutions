pragma solidity >=0.4.22 <0.9.0;

contract Solution {
    function satisfiesConditions(uint[][] memory grid) public pure returns (bool) {
        uint m = grid.length;
        uint n = grid[0].length;
        for (uint i = 0; i < m; i++) {
            for (uint j = 0; j < n; j++) {
                if (i < m - 1 && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j < n - 1 && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
}
