class Solution(object):

    def imageSmoother(self, img):
        """
        :type img: List[List[int]]
        :rtype: List[List[int]]
        """
        rows, cols = len(img), len(img[0])
        returnMatrix = [[0] * cols for _ in range(rows)]
        for row in range(rows):
            for col in range(cols):
                cellSum = 0
                count = 0

                for x in range(max(0, row-1), min(rows, row+2)):
                    for y in range(max(0,col - 1), min(cols, col+2)):
                        cellSum += img[x][y]
                        count += 1

                returnMatrix[row][col] = cellSum // count

        return returnMatrix
