Using the programming techniques of "dynamic programming" and "greedy algorithms", write in C++, a program that solves the currency exchange problem.

Input Format

The program receives an integer , followed by  integer values (one on each line) that represent the different denominations of coins available.

Following this, the program receives two integers:  and , (one in each line) through the standard input, which represent : the price of a given product and : is the ticket or coin with which said product is paid.

Constraints

, followed by a list with  elements (one on each line) of  numbers, then,  that represents the product's price. Finally,  is the amount paid for the product.

Output Format

A list of  values corresponding to the number of coins of each denomination, from highest to lowest, one in each line, which must give the change for the product paid, first using dynamic programming, and then using a greedy algorithm.

The first block should corresponds to the result using dynamic programming, and the second block corresponds to the result using the greedy algorithm. The first number represents the number of coins, and the second number represents the denomination.
