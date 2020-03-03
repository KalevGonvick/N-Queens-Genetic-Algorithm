# N-Queens-Genetic-Algorithm
##The Problem

An overall summary of the problem that this application solves is the N-Queens problem. This
problem is trying to place N queens on an NxN chess board in such a way that they cannot
attack each other. Although this solution is easier at smaller board sizes, it becomes
increasingly more complex as the N increases. This means traditional ‘brute’ force algorithms
will take a lot longer to solve these problems, and where optimization algorithms like a genetic
algorithm shines.

##The Algorithm

###Finding a Single Solution

The way I approached implementing a genetic algorithm to solve the n-queens problem was
fairly simple. The first step is to create a randomized population consisting of different board
configurations. The configurations are vectors of length 8, and each index being a number
limited to a range of 1 to 8. The index number correlates to the column number of the board,
while the number in the index is the row number of the board.
The randomness is just the built-in random function in c++, but this was just so I could set a
seed number for testing. If I wanted to make things more ‘random’, it would have been best to
implement a gaussian random function instead of the pseudo random one. After each
configuration is randomized, a fitness value is calculated for each of them. Fitness starts at 0
(the fittest value) and increases by 1 for each rule the position of the queen breaks. The worst
case fitness value for an 8 x 8 board is 56 (8 x 8 - 8).
The main loop of the function after the population has been initialized is basically where you sort
the list of vectors from most fit to least fit, and if the top position has a fitness of 0 then it is a
viable solution.

If no solution is found in this round, then we move onto the crossover and mutation functions of
the algorithm. We randomly select the top 25 percent fittest of the population as parents for the
next generation. Between these parents, a random chance happens at each of the indexes of
the vector to see what number the new child will get. The rates for the crossover and mutation
are set up with the following: 0% to 45% the gene from parent 1 is used, from 45% - 90% the
gene from parent2 is used, and anything greater than 90% means a mutation (a random
number from 1 to 8 is selected instead). This means that the mutation rate is set to 10%.

###Finding All Solutions

The above algorithm changes slightly when we want to find all solutions for an 8 x 8 chess
board. The main thing is that we now have to keep a list of all existing solutions and make sure
that we do not add the same solution to the list again. Also when we do find a solution, we want
to randomize a new population so we don't get stuck in a spot where we have an old/already
existing solution at the top of our list.
Other than that, everything is exactly the same as how we solved it for a single solution.

##The Results

Here are all 92 solutions to an 8x8 board for N-Queens. As the number of solutions found
increased, the solutions near the end took much longer to find. Also, I found that as I increased
the population, smaller amounts of generations were needed to find all 92 solutions.
At a population of 1000 it took ~55k generations, while a population size of 8000 only took ~4.5k
generations.



