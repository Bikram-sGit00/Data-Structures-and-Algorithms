# Number of Closed Islands - 

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


# ✅ Company Tags

> **`Google`**


# Number of Islands - Another Must Try & similler - [Leetcode](https://leetcode.com/problems/number-of-islands/description/)

**Problem:** LeetCode 200
**Topic:** Matrix, DFS, BFS, Flood Fill
**Difficulty:** Medium

---

## Problem Statement

You get an `m x n` grid of characters where `'1'` is land and `'0'` is water. An island is a group of `'1'`s connected horizontally or vertically (diagonals don't count). Return the number of islands. You can assume everything outside the grid is water.

**Example 1**

```
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0

Output: 1
```

**Example 2**

```
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Output: 3
```

**Constraints:** `1 <= m, n <= 300`, and each cell is `'0'` or `'1'`.

---

## Intuition

Every island is one connected blob of land. If we walk the grid and hit a `'1'` we haven't seen yet, we've found a brand new island. The trick is to make sure we never count the same island twice.

So the moment we find land, we explore the entire blob and flip every cell in it to `'0'` (sink it). By the time the scan moves on, that island no longer exists in the grid, and the next `'1'` we meet has to belong to a different one. One DFS start equals one island.

This is the same flood fill idea used in Closed Island, but simpler. There, an island only counted if it never touched the border. Here it doesn't matter where the island sits, so the DFS doesn't need to return anything.

---

## Approach

1. Loop over every cell in the grid.
2. When a cell is `'1'`, increase the count by one and run `dfs` from it.
3. Inside `dfs`:
   - If the cell is outside the grid, return.
   - If the cell is `'0'` (water or already visited), return.
   - Otherwise set it to `'0'` and call `dfs` on the left, right, up and down neighbours.
4. After the loops finish, `count` is the answer.

---

## Code (C++)

```cpp
class Solution {
public:
    int n, m; // n = number of rows, m = number of columns

    // sinks one whole island, so no return value is needed
    void dfs(vector<vector<char>>& grid, int i, int j){
        // off the grid: just stop, touching the edge is fine for this problem
        if(i < 0 || i >= n || j < 0 || j >= m) return;

        // water, or land we already visited
        if(grid[i][j] == '0') return;

        // mark as visited by turning land into water
        grid[i][j] = '0';

        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();    // rows
        m = grid[0].size(); // columns
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // unvisited land means a new island
                if(grid[i][j] == '1'){
                    dfs(grid, i, j); // sink the whole island
                    count++;         // counted once, since it's now gone
                }
            }
        }
        return count;
    }
};
```

---

## Pen and Paper Dry Run

Using Example 2. Here `n = 4` rows and `m = 5` columns, and coordinates are written as `(row, col)`.

```
        col: 0  1  2  3  4
row 0:       1  1  0  0  0
row 1:       1  1  0  0  0
row 2:       0  0  1  0  0
row 3:       0  0  0  1  1
```

Expected answer: **3**.

### Scan starts

`(0,0)` is `'1'`, so we found land we haven't seen. `count` becomes 1 and we run `dfs(0,0)`.

### DFS #1, starting at (0,0)

The order of calls is left, right, up, down.

```
dfs(0,0)  '1' -> sink it
 |- left  (0,-1): out of bounds                  -> return
 |- right (0,1): '1' -> sink it
 |     |- left  (0,0): already '0'               -> return
 |     |- right (0,2): '0'                       -> return
 |     |- up    (-1,1): out of bounds            -> return
 |     \- down  (1,1): '1' -> sink it
 |           |- left  (1,0): '1' -> sink it
 |           |     |- left  (1,-1): out of bounds -> return
 |           |     |- right (1,1): already '0'    -> return
 |           |     |- up    (0,0): already '0'    -> return
 |           |     \- down  (2,0): '0'            -> return
 |           |- right (1,2): '0'                  -> return
 |           |- up    (0,1): already '0'          -> return
 |           \- down  (2,1): '0'                  -> return
 |- up    (-1,0): out of bounds                  -> return
 \- down  (1,0): already '0'                     -> return
```

That DFS sank four cells: `(0,0) (0,1) (1,1) (1,0)`. The top-left island is gone.

```
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 1 1
```

### Scan continues

Everything in rows 0 and 1 is `'0'` now, so nothing starts there. In row 2, `(2,2)` is `'1'`. New island, so `count = 2`, and we run `dfs(2,2)`.

```
dfs(2,2)  '1' -> sink it
 |- left  (2,1): '0'   -> return
 |- right (2,3): '0'   -> return
 |- up    (1,2): '0'   -> return
 \- down  (3,2): '0'   -> return
```

A single-cell island. Notice that `(3,3)` is diagonal to `(2,2)`, so it is **not** connected and the DFS never reaches it.

### Scan continues again

Rest of row 2 is water. In row 3, `(3,3)` is `'1'`. Another new island, so `count = 3`, and we run `dfs(3,3)`.

```
dfs(3,3)  '1' -> sink it
 |- left  (3,2): '0'                         -> return
 |- right (3,4): '1' -> sink it
 |     |- left  (3,3): already '0'           -> return
 |     |- right (3,5): out of bounds         -> return
 |     |- up    (2,4): '0'                   -> return
 |     \- down  (4,4): out of bounds         -> return
 |- up    (2,3): '0'                         -> return
 \- down  (4,3): out of bounds               -> return
```

That island had two cells: `(3,3)` and `(3,4)`. After this, `(3,4)` is already `'0'`, so the scan skips it.

### Final state

```
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

Every land cell has been sunk. **Answer = 3**, which matches.

---

## Complexity

Let `n` be the number of rows and `m` the number of columns.

**Time: O(n * m)**
The nested loops touch each cell once. In the DFS, a land cell is flipped to `'0'` the first time it is reached, so it never gets expanded again. Each cell does a constant amount of work, so the total is proportional to the grid size.

**Space: O(n * m)**
No extra visited array is used, because the input grid is edited in place. The memory cost is the recursion stack. The worst case is one long snaking island that fills the whole grid, which makes the depth reach `n * m`. With the 300 x 300 limit that is up to 90,000 calls deep.

---

## Things Worth Remembering

- **Land is `'1'` here.** In Closed Island land was `0`. Mixing these up is the easiest mistake when reusing old code.
- **These are `char`s, not strings.** Use single quotes: `'1'` and `'0'`. Double quotes make it a string literal, which won't compile against a `char` cell.
- **Only four directions.** Diagonal land cells are separate islands, as the `(2,2)` and `(3,3)` case shows.
- **The input gets modified.** If the problem needs the grid left alone, copy it first or keep a separate `visited` matrix.
- **Counting happens before the DFS call, or right after it, but only once per island.** Either order is fine because the DFS is what stops the island from being counted again.
- **How it differs from Closed Island:** that problem needs a boolean from the DFS because it only counts islands that never touch the border. This one counts every island, so the DFS is just a "sink it" helper.

---

## Alternative Approach: BFS

Recursion can get deep on a big single island. BFS does the same flood fill with a queue, so the depth never builds up on the call stack.

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != '1') continue;

                count++;
                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = '0'; // mark when pushing so a cell never enters the queue twice

                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();

                    for(int d = 0; d < 4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        // stay inside the grid and only follow land
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1'){
                            grid[nx][ny] = '0';
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return count;
    }
};
```

Time is still O(n * m). Space is O(min(n, m)) for the queue in the typical case, since the BFS frontier is roughly as wide as the shorter side of the grid.

One detail worth noting: the cell is marked `'0'` when it is pushed, not when it is popped. If you wait until pop, the same cell can get pushed several times by different neighbours, which wastes time and memory.

There is also a Union Find approach, which is handy if the interviewer follows up with a version where land gets added over time (that is Number of Islands II).