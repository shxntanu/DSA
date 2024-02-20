class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        def extract_inner_matrix(matrix):
            if len(matrix) < 3 or len(matrix[0]) < 3:
                return [] 

            inner_matrix = [row[1:-1] for row in matrix[1:-1]]
            return inner_matrix

        def iterate_outer_matrix( matrix):
            if not matrix:
                return []

            outer_ring = []
            rows = len(matrix)
            cols = len(matrix[0])

            top_row = 0
            bottom_row = rows - 1
            left_col = 0
            right_col = cols - 1

            if rows == 1:  # If only one row
                return matrix[0]
            elif cols == 1:  # If only one column
                return [row[0] for row in matrix]

            while top_row <= bottom_row and left_col <= right_col:
                # Traverse top row
                for col in range(left_col, right_col + 1):
                    outer_ring.append(matrix[top_row][col])
                top_row += 1

                # Traverse right column
                for row in range(top_row, bottom_row + 1):
                    outer_ring.append(matrix[row][right_col])
                right_col -= 1

                # Traverse bottom row
                if top_row <= bottom_row:
                    for col in range(right_col, left_col - 1, -1):
                        outer_ring.append(matrix[bottom_row][col])
                    bottom_row -= 1

                # Traverse left column
                if left_col <= right_col:
                    for row in range(bottom_row, top_row - 1, -1):
                        outer_ring.append(matrix[row][left_col])
                    left_col += 1

            return outer_ring
    
        mat = []

        if len(matrix) < 3 or len(matrix[0]) < 3:
            return iterate_outer_matrix(matrix)

        while True:
            mat.extend(iterate_outer_matrix(matrix))
            if len(matrix) < 3 or len(matrix[0]) < 3:
                matrix = extract_inner_matrix(matrix)
            else: 
                break

        return mat
