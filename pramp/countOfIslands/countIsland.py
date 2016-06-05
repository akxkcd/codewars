import Queue

def findCountIslands(matrix):
  
  for i in xrange(0,len(matrix)):
     print matrix[i]
  
  countOfIsland = 1
  for i in xrange(0,len(matrix)):
     item = matrix[i]
     for j in xrange(0,len(item)):
       if matrix[i][j] == 1:
          q = Queue.Queue()
          q.put([i,j])
          while not q.empty():
            [row,col] = q.get()
            matrix[row][col] = countOfIsland
            print row,col
            if row+1 < len(matrix) and matrix[row+1][col] == 1:
              q.put([row+1,col])
            if row-1 >= 0 and matrix[row-1][col] == 1:
              q.put([row-1,col])
            if col+1 < len(matrix) and matrix[row][col+1] == 1:
              q.put([row,col+1])
            if col-1 >= 0 and matrix[row][col-1] == 1:
              q.put([row,col-1])
          countOfIsland += 1
  print countOfIsland
  for i in xrange(0,len(matrix)):
     print matrix[i]
  return countOfIsland 

data = [
        [0, 1, 0, 1, 0], 
        [0, 0, 1, 1, 1],
        [1, 0, 0, 1, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 1, 0, 1]
       ]

findCountIslands(data)
