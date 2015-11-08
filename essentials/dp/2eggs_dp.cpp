/*
 SOLUTIONS
 Here, we will discuss various approaches and try to improve the solution. Our main objective is to improve the worst case.

Approach 1: If you start from floor 1, if it doesn't break then floor 2 and so on.
Worst number of attempts needed = 100. So,
Worst case = 100
Best case = 1
But, we are not using 2 eggs. 

Approach 2: What if proceed like floor no. 2, 4, 6, ... so on.
Worst Case: 51
Best case: 2

Approach 3: 5, 10, 15 , ....
If it breaks on 5th floor, try 1, 2, 3 & 4. So in this case 5 attempts needed.
If it breaks on 10th, try 6, 7, 8 &9. ==>  6 attempts needed in worst case.
Similarly the worst case is if 100th floor is the threshold. It doesn't break till 95(19th attempt), breaks at 100th(20th attempt). We try 96, 97, 98 & 99.So, 
Worst case = 24.
Best case = 5 (actually 2, if threshold floor is 1).

So, we see that we have significantly improved the worst case from 100 in approach 1, to 51 in approach 2 , to 24 in approach 3. Thus, we are moving in the right direction. 
Lets try to increase the step size further to 10.

Approach 4: 10, 20, 30, .....
If it breaks at floor 10, try 1, 2, 3,...  9 = 10 attempts needed.
If it breaks at floor 20, try 11, 12, ..19 = 11 attempts
If it breaks at floor 30, try 21, 22, ..29 = 12 attempts
If it breaks at floor 40, try 31, 32, ..39 = 13 attempts
................................50                            = 14
................................60                            = 15
................................70..........................  = 16
................................80..........................  = 17
................................90..........................  = 18
...............................100.........................  = 19
Worst Case = 19.

So, we have improved further.

Approach 5: 

One important observation to note here is that our worst case depends on which floor is the threshold. After each step increase of 10 it increases by 1.
So, instead of stepping by equal floors each time the egg doesn't break, we can decrease the nest step jump by 1, so that the worst case remains same irrespective of which interval the threshold floor lies.
What if we go like 10->19->27->34->40->45->49->52->54->55
We can't reach 100.
So, what should be our starting point, so that we decrease the step step size by 1 after each jump, and still reach 100. We have to find the minimum possible starting point.

Let the starting step size be x.
x
x + x-1
x + x-1 + x-2 
x + x-1 + x-2 + x-3
...............
x + x-1 + x-2 + x-3 ......... + 2 + 1 = 100
x(x+1)/2 = 100
x*x + x - 200 = 0
x =  [-1 + sqrt(1 + 800) ] / 2
   =  (-1 + 28.30)/2
   = 27.30/2
   = 13.65
So, minimum value requires is 13.65
i.e. if we start at floor 13, we wouldn't reach 100th floor if we are decreasing step step size by 1 each time.
So out starting floor should be 14.

So the order should be 14, 27, 39, 50, 60, 69, 77, 84, 90, 95, 99
if it breaks at 14  = 1 + 13 = 14 attempts in worst case[14, 1, 2, 3...13]
........................27 = 2 + 12 = 14 attempts .............[14, 27, 15, 16, ....26]
........................39 = 3 + 11 = 14
........................50 = 4 + 10 = 14
............................
.....................   90 = 9 + 5 = 14
........................95 = 10 + 4 = 14
........................99 = 11 + 3 = 14  
In last case if it breaks at 99th floor i.e., after 11 attempts, we try 96, 97 & 98, thus giving 14 attempts.
Further if it doesn't break at 99, we check 100th, thus giving 12 attempts.

So, the worst case would be that we have to check 14 times, and no more with 2 eggs to find the threshold floor. 
 */















# include <stdio.h>
# include <limits.h>
 
// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }
 
/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k)
{
    // If there are no floors, then no trials needed. OR if there is
    // one floor, one trial needed.
    if (k == 1 || k == 0)
        return k;
 
    // We need k trials for one egg and k floors
    if (n == 1)
        return k;
 
    int min = INT_MAX, x, res;
 
    // Consider all droppings from 1st floor to kth floor and
    // return the minimum of these values plus 1.
    for (x = 1; x <= k; x++)
    {
        res = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
        if (res < min)
            min = res;
    }
 
    return min + 1;
}
 
/* Driver program to test to pront printDups*/
int main()
{
    int n = 2, k = 10;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}
