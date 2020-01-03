Description of the problem in hackerrank site is as below :

You are given a 2D matrix of dimension m and n a positive integer r. You have to rotate the matrix r
times and print the resultant matrix. Rotation should be in anti-clockwise direction.
It is guaranteed that the minimum of m and n will be even.

Function Description:
Complete the matrixRotation function in the editor below. It should print the resultant 2D integer array and return nothing.
matrixRotation has the following parameter(s):
    matrix: a 2D array of integers
    r: an integer that represents the rotation factor
    
Input Format:
The first line contains three space separated integers, m, n, and r, the number of rows and columns in matrix, and the required rotation.
The next m lines contain n space-separated integers representing the elements of a row of matrix.

Constraints:
2 <= m,n <= 300
1 <= r <= 10^9
min(m,n)%2=0
1 <= aij <= 10^8 where i in [1...m] and j in [1...n]
Output Format

Print each row of the rotated matrix as space-separated integers on separate lines.
