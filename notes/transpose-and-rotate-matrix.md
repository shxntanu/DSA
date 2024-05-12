# Matrix Operations

## Transpose Matrix

- Run an outer for loop from 0 to `(Size of Matrix - 1)` (let's say `row` )
- Run an inner for loop for Outer + 1 to (Size of Matrix - 1) (let's say `column` )
- Swap `matrix[row][column], matrix[column][row]`

```cpp
// Transpose a matrix
// assume Matrix is a variable: vector<vector<int>> matrix;

for(int i=0; i<matrix.size(); i++) {
  for(int j=i+1; j<matrix[i].size(); j++) {
    swap(matrix[i][j], matrix[j][i]);
  }
}
```

## Rotate a Matrix by 90 Degrees

Reverse the rows of the Matrix and take a transpose

```cpp
void rotate(vector<vector<int>>& matrix) {
  // Reverse rows
  reverse(matrix.begin(), matrix.end());

  // Transpose
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = i + 1; j < matrix[i].size(); ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}
```
