// APPROACH: 
    - Always draw a recursion tree to know state and transition
    - direct tabulation approach: 
    - after know state, transition, bc
    - move from smaller to larger state: till you've solved the main problem

- Define a State: i.e subproblem: can it be unique to define a subproblem ?
    - eg: dp[no] or dp[ind][tar]

- Define the Transition: i.e how that state related to it's subproblems ?
    - eg: while(num > 0) {
            digit = num % 10; num /= 10;

            min_steps = min(min_steps, dp[no-digit]);
        }
        dp[no] = 1 + min_steps

- Define the BC(a very small state that can be trivially solved)
    - eg: dp[0] = 0

// TIME COMPLEXITY:

-  (# states) * avg transition time of each state

/********************* LATER TO SOLVE: ***********************************/
1. Know why is the code for Coin_Combination 1 and 2 different.
2. Couldn't solve in one go :

- Array Description (=> good dp state)

- Counting Towers (=> good problem,how'd the ith problem look like, based on that we solve it, keep in mind to only solve the ith ind)

- Rectangle Cutting (=> for a particular rectangle: what all can we do to reduce the problem ?)

/******************** KEEP IN MIND ******************************/

1. we should always work only on the ith ind i.e (we should be *only* be doing, what Recusion should do at the ith ind)
    - and make recursion make on rest of the indices.
2. 

