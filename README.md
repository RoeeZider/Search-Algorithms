# Search Algorithms

 link to github - 

A multi-threaded server that can solve path-finding problems(in matrix)

**Prerequisites**

Linux environment to run the code

Create a parallel server that creates 10 matrices, and sends them to the server.

The structure: 
*The matrix
*start.x, start.y
*end.x, end.y
*"end"

for example:
3,3,2,1,2,2,2,2,2,1,1,1,1
1,1,4,4,4,1,4,1,2,2,1,1,1
4,2,-1,1,2,3,1,1,1,3,4,4,3
1,2,4,3,4,1,3,3,1,1,4,1,3
3,1,1,1,-1,1,4,3,4,3,1,1,3
1,4,4,4,4,2,1,3,1,2,1,4,1
2,1,2,3,1,2,-1,1,3,1,4,2,1
3,3,3,3,1,3,4,1,4,3,3,3,3
1,1,4,3,3,3,4,2,-1,1,4,3,1
3,1,4,2,1,4,1,1,4,4,1,4,2
2,4,2,2,1,4,3,1,2,3,-1,3,1
3,1,2,1,1,1,1,1,1,3,1,1,1
4,1,2,1,3,1,2,3,4,2,2,4,7
0,0
12,12
end


# Running

a. Exceute the code using the terminal or any c++ work environment. The program will wait for a connection from a client. If no client logs on to the server within 2 minutes - the server will shut down.

b. open a parallel server that bring to the server the problem(in our case - the maxtrix).

c. finally, we get the solution for the problen- The shortest route from start point to the end point.

The program handles each row and creates the matrix. We then check if the solution is already in our cache, then - we bring it. If not, we find the solution to the problem.
After an experiment we did, we found that the best algorithm is ASTAR algorithn, so this algorithm will find the solution to the problem.
