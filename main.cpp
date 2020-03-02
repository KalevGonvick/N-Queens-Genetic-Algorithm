#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define POPULATION_SIZE 1000
#define BOARD_SIZE 8
#define SOLUTION_COUNT 92

using namespace std;

/**
 * Pseudo random number gen between a range
 * @param lower_range - lowest value that can occur
 * @param higher_range - highest value that can occur
 * @return - random integer within the given range
 */
int RandomNumberRanged(int lower_range, int higher_range)
{
    int range = higher_range - lower_range + 1;
    int randomInteger = lower_range+(rand()%range);
    return randomInteger;
}
/**
 * Takes in a vector and prints it out (mostly for debug + console display)
 * @param a - the vector being printed
 */
void BoardConfigPrint(vector<int> const &a) {
    std::cout << "Board Config : ";
    for(int i : a)
        std::cout << i << ' ';
    std::cout << std::endl;
}

class BoardConfig
{
public:
    vector<int> queen_locations;
    int fitness;
    explicit BoardConfig(const vector<int>& queen_locations);
    static int CalculateFitness(const vector<int>& queen_locations);
    vector<int> CreateOffSpring(BoardConfig config2);
};
/**
 * Constructor
 */
BoardConfig::BoardConfig(const vector<int>& queen_locations)
{
    this->queen_locations = queen_locations;
    fitness = CalculateFitness(queen_locations);
}

/**
 * Calculates the fitness of the configuration - close to 0 is better
 * Worst case fitness is 8x8-8 (56)
 * 8 x 8 for the board size, but subtract 8 because you don't compare the queens to itself
 * @param queen_locations - the vector of queen locations in a vector
 * @return - returns the integer of how fit the configuration is
 */
int BoardConfig::CalculateFitness(const vector<int>& queen_locations)
{
    int fitness = 0;
    int focused_queen_x = 0;
    for(auto focused_queen_y : queen_locations)
    {
        int compare_queen_x = 0;
        for(auto compare_queen_y : queen_locations)
        {

            if(focused_queen_x != compare_queen_x)
            {
                /* horizontal check */
                bool horizontal = true;
                if(focused_queen_y == compare_queen_y)
                {
                    horizontal = false;
                }

                /* diagonal check */
                bool diagonal = true;
                int col_diff = abs(focused_queen_x - compare_queen_x);
                if(focused_queen_y == (compare_queen_y + col_diff) || focused_queen_y == (compare_queen_y - col_diff))
                {
                    diagonal = false;
                }
                if(!horizontal || !diagonal)
                {
                    fitness++;
                }
            }
            compare_queen_x++;
        }
        focused_queen_x++;
    }
    return fitness;
}

/**
 * Takes two board configurations as parents and does a cross_over + mutation
 * @param config2
 * @return - returns a new offspring vector
 */
vector<int> BoardConfig::CreateOffSpring(BoardConfig config2)
{
    vector<int> offspring_config;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        float probability = float(RandomNumberRanged(0, 100))/100.0f;
        if(probability < 0.25f )
        {
            offspring_config.push_back(this->queen_locations[i]);
        } else if(probability < 0.50f)
        {
            offspring_config.push_back(config2.queen_locations[i]);
        } else {
            offspring_config.push_back(RandomNumberRanged(1,8));
        }
    }
    return offspring_config;
}

/**
 * Create a new random configuration
 * @return - returns of a vector of BOARD_SIZE, each index is an integer ranging from 1 to BOARD_SIZE
 */
vector<int> CreateNewConfig()
{
    vector<int> new_config;
    new_config.reserve(BOARD_SIZE);
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        new_config.push_back(RandomNumberRanged(1,BOARD_SIZE));
    }
    return new_config;
}

/**
 * Initialize the population for the Boards
 * @return - returns a vector of BoardConfig objects of length POPULATION_SIZE
 */
vector<BoardConfig> initPopulation()
{
    vector<BoardConfig> new_pop;
    new_pop.reserve(POPULATION_SIZE);
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        vector<int> new_config = CreateNewConfig();
        new_pop.emplace_back(new_config);
    }
    return new_pop;
}

/**
 * Overload operator for <
 * @param board1
 * @param board2
 * @return - returns true if board2 fitness is more than board1
 */
bool operator<(const BoardConfig &board1, const BoardConfig &board2)
{
    return board1.fitness < board2.fitness;
}

/**
 * This is the main driver for the algorithm
 * @return
 */
int main() {

    /* seeded random for testing */
    srand((unsigned)(time(0)));

    /* counter to keep track of generation number */
    int generation = 0;

    /* create initial population */
    vector<BoardConfig> population;
    population.reserve(POPULATION_SIZE);
    population = initPopulation();

    /* initialize the solution board vector */
    vector<BoardConfig> solution_boards;
    int solution_count = 0;

    /* this will loop until all solutions have been found */
    while(solution_count < SOLUTION_COUNT)
    {

        /* sort the population by fitness (done along side operator< overload) */
        sort(population.begin(), population.end());
        if(population[0].fitness == 0)
        {
            /* make sure that the solution has not already been found before */
            bool new_solution_exists = false;
            for(const auto& x : solution_boards)
            {
                if(x.queen_locations == population[0].queen_locations)
                {
                    new_solution_exists = true;
                }
            }

            /* if it doesnt, push it onto the list and increment counter */
            if(!new_solution_exists)
            {
                solution_boards.push_back(population[0]);
                solution_count++;

                /* if all 92 have been found, end it */
                if(solution_count == 92)
                {
                    std::cout << "Generation: " << generation << std::endl;
                    BoardConfigPrint(population[0].queen_locations);
                    std::cout << "Solution Count: " << solution_count << std::endl;
                    break;
                }
            }
        }

        /* initialize the next generation holder */
        vector<BoardConfig> next_gen;
        next_gen.reserve(POPULATION_SIZE);
        for(int i = 0; i < POPULATION_SIZE; i++) {

            /* the top 50% of the population make new offspring*/
            int Random1 = RandomNumberRanged(0, POPULATION_SIZE*0.5);
            int Random2 = RandomNumberRanged(0, POPULATION_SIZE*0.5);
            vector<int> new_gen_board = population[Random1].CreateOffSpring(population[Random2]);

            /* put the new child in the next population */
            next_gen.emplace_back(new_gen_board);
        }
        std::cout << "Generation: " << generation << std::endl;
        BoardConfigPrint(population[0].queen_locations);
        std::cout << "Solution Count: " << solution_count << std::endl;
        population.clear();
        population = next_gen;
        generation++;
    }
}
