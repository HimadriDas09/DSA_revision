Description

Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing the score of all the subarray.

 

Note: The median of a sequence is the value that is in the middle when the sequence is sorted. If the length of the sequence is even, there are two values in the middle and the median is the smaller of these values (or either when they are equal).


Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains an integer N where (1<=N<=10^5).

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case output the median of the array containing the score of all the subarray in a new line.


Sample Input 1

5
3
1 2 3
1
5
2
1 5
10
1 2 2 3 3 4 5 4 6 7
15
100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

Sample Output 1

3
5
5
13
3629
 


Note

1st test case:
Subarray and score:
1 -> 1
1,2 -> 3
1,2,3 -> 6
2 -> 2
2,3 -> 5
3 -> 3
New array = {1,2,3,3,5,6}, median = 3

2nd test case:
Subarray and Score:
5 -> 5
New array = {5}, median = 5

3rd test case:
Subarray and score
1 -> 1
1,5 -> 5
5 -> 5
New array = {1,5,5}, median = 5.