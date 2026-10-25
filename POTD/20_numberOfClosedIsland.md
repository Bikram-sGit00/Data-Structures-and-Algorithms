# Number of Closed Islands

**Problem:** LeetCode 1254
**Topic:** Matrix, DFS, Flood Fill
**Difficulty:** Medium

---

## Problem Statement

You get a 2D grid made of `0` (land) and `1` (water). An island is a group of `0`s connected in the four directions (up, down, left, right). A **closed island** is an island that is completely surrounded by water on all four sides, so none of its land cells touches the edge of the grid.

Return the number of closed islands.

**Example**

```
Input:
1 1 1 1 1 1 1 0
1 0 0 0 0 1 1 0
1 0 1 0 1 1 1 0
1 0 0 0 0 1 0 1
1 1 1 1 1 1 1 0

Output: 2
```

The big island in the left-middle and the single `0` at row 3, col 6 are closed. The `0`s along the right edge touch the boundary, so they don't count.

---

## Intuition

An island is closed only if the DFS that explores it never walks off the grid. So the idea is:

1. Find an unvisited `0` and start a DFS from it.
2. Every time the DFS steps out of bounds, that island has an opening to the outside, so it is not closed.
3. If the DFS finishes without ever stepping out, the island is closed.

To avoid visiting a cell twice, we flip each visited `0` to `1` as we go. This is classic flood fill, and it also means the grid itself acts as the visited array.

The part that is easy to miss: the DFS has to keep going even after it already knows the island is open. If we stopped early, the leftover `0`s of that island would still be sitting in the grid, and the main loop would find them later and wrongly count them as a new island.

---

## Approach

1. Loop over every cell in the grid.
2. When a cell is `0`, run `dfs` from it.
3. Inside `dfs`:
   - Out of bounds: return `false` (we escaped, so this island is not closed).
   - Cell is `1` (water or already visited): return `true` (this direction is blocked, which is good).
   - Otherwise mark the cell as `1` and explore left, right, up and down.
   - Return `true` only if all four directions came back `true`.
4. If `dfs` returns `true`, increment the count.

---

## Code (C++)

```cpp
class Solution {
public:
    int m, n; // n = number of rows, m = number of columns

    bool dfs(vector<vector<int>>& grid, int i, int j){
        // walked off the grid -> this island touches the boundary, so it is NOT closed
        if(i >= n || i < 0 || j >= m || j < 0) return false;

        // water, or a land cell we already visited -> this side is safely blocked
        if(grid[i][j] == 1) return true;

        // mark current land cell as visited by turning it into water
        grid[i][j] = 1;

        // IMPORTANT: store each result in a variable instead of chaining with &&.
        // Chaining would short circuit and leave part of the island unvisited,
        // and the main loop would count that leftover land as a fake extra island.
        bool leftClose  = dfs(grid, i, j - 1);
        bool rightClose = dfs(grid, i, j + 1);
        bool upClose    = dfs(grid, i - 1, j);
        bool downClose  = dfs(grid, i + 1, j);

        // closed only if every direction was blocked
        return leftClose && rightClose && upClose && downClose;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();    // rows
        m = grid[0].size(); // columns
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // found unvisited land, so explore the whole island from here
                if(grid[i][j] == 0){
                    if(dfs(grid, i, j) == true) count++;
                }
            }
        }
        return count;
    }
};
```

---

## Pen and Paper Dry Run

A small grid so the whole thing fits on one page. Here `n = 4` rows and `m = 6` columns, and I'll write coordinates as `(row, col)`.

```
        col: 0  1  2  3  4  5
row 0:       1  1  1  1  1  1
row 1:       1  0  0  1  0  0
row 2:       1  0  1  1  0  1
row 3:       1  1  1  1  1  1
```

There are two islands here:

- **Island A:** `(1,1) (1,2) (2,1)`, fully inside the water. This should be closed.
- **Island B:** `(1,4) (1,5) (2,4)`, and `(1,5)` sits in the last column. This should NOT be closed.

Expected answer: **1**.

### Scanning the grid

Row 0 is all `1`s, so nothing happens. In row 1, `(1,0)` is `1`, skip. `(1,1)` is `0`, so we start a DFS.

### DFS #1, starting at (1,1)

Call order is left, right, up, down. I'll write `T` for true and `F` for false.

```
dfs(1,1)  grid is 0 -> mark it 1
 |- left  (1,0): value 1                       -> T
 |- right (1,2): value 0 -> mark it 1
 |     |- left  (1,1): already 1               -> T
 |     |- right (1,3): value 1                 -> T
 |     |- up    (0,2): value 1                 -> T
 |     |- down  (2,2): value 1                 -> T
 |     \- all T                                -> T
 |- up    (0,1): value 1                       -> T
 |- down  (2,1): value 0 -> mark it 1
 |     |- left  (2,0): value 1                 -> T
 |     |- right (2,2): value 1                 -> T
 |     |- up    (1,1): already 1               -> T
 |     |- down  (3,1): value 1                 -> T
 |     \- all T                                -> T
 \- T && T && T && T                           -> T
```

The DFS returned `true`, so `count = 1`.

Grid after DFS #1 (Island A is now flooded with `1`s):

```
1 1 1 1 1 1
1 1 1 1 0 0
1 1 1 1 0 1
1 1 1 1 1 1
```

### Continuing the scan

`(1,2)` and `(1,3)` are `1` now, so we skip them. `(1,4)` is `0`, so we start another DFS.

### DFS #2, starting at (1,4)

```
dfs(1,4)  grid is 0 -> mark it 1
 |- left  (1,3): value 1                       -> T
 |- right (1,5): value 0 -> mark it 1
 |     |- left  (1,4): already 1               -> T
 |     |- right (1,6): j >= m, out of bounds   -> F   <-- escaped!
 |     |- up    (0,5): value 1                 -> T
 |     |- down  (2,5): value 1                 -> T
 |     \- T && F && T && T                     -> F
 |- up    (0,4): value 1                       -> T
 |- down  (2,4): value 0 -> mark it 1
 |     |- left  (2,3): value 1                 -> T
 |     |- right (2,5): value 1                 -> T
 |     |- up    (1,4): already 1               -> T
 |     |- down  (3,4): value 1                 -> T
 |     \- all T                                -> T
 \- T && F && T && T                           -> F
```

The DFS returned `false`, so `count` stays at 1.

Notice that `(2,4)` still got visited and flooded even though the right branch had already failed. That is exactly why we store the four results in variables. If we had used `return dfs(...) && dfs(...) && ...`, the `&&` would stop at the first `false`, `(2,4)` would stay as `0`, and the main loop would later find it and count it as a separate closed island. That would give 2, which is wrong.

### Final state

```
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
```

Every land cell has been consumed. **Answer = 1**, which matches.

---

## Complexity

Let `n` be the number of rows and `m` the number of columns.

**Time: O(n * m)**
The nested loops visit each cell once. Inside the DFS, each land cell is turned into `1` the first time it is reached, so no cell is expanded more than once. Each cell does a constant amount of work (four neighbour checks), so the total is proportional to the number of cells.

**Space: O(n * m)**
We don't use a separate visited array, because we overwrite the input grid. The extra memory is the recursion stack. In the worst case (one giant snake-shaped island covering the whole grid) the depth reaches `n * m`.

---

## Things Worth Remembering

- **Out of bounds returns `false`, water returns `true`.** It feels backwards at first, but it makes sense when you read `true` as "this direction is sealed off".
- **Don't short circuit.** Save all four results first, then combine them. This is the bug that most often turns a correct idea into a wrong answer.
- **This version edits the input grid.** If the problem needs the grid left untouched, copy it first or use a separate `visited` matrix.
- **Rows and columns:** `n` is rows and `m` is columns, so the bounds check is `i` against `n` and `j` against `m`. Swapping them is an easy typo.
- **Pattern to reuse:** "count regions that don't touch the border" shows up often. The same flood fill idea applies to problems like Surrounded Regions and Number of Enclaves.

---

## Alternative Approach

Instead of returning a boolean from the DFS, flip the thinking around:

1. First flood fill every `0` that sits on the border (first row, last row, first column, last column). Those can never belong to a closed island.
2. Then scan the grid normally. Every `0` that remains must be part of a closed island, so each new DFS start is one closed island.

Time and space are the same, O(n * m), and the DFS gets simpler because it no longer needs a return value. It is worth knowing both, since interviewers like to ask for the second one as a follow up.
