#include <iostream>
#include <cmath>
#include <vector>
#include <array>


const int MAX_LIMIT = 28123;

/// Calculates the sum of all divisors of a given number.
int get_divisors_sum(int num)
{
    if (num == 1)
    {
        return 1;
    }
    int n = std::ceil(std::sqrt(num));
    int total = 1;
    int divisor = 2;
    while (divisor < n)
    {
        if (num % divisor == 0)
        {
            total += divisor;
            total += num / divisor;
        }
        divisor++;
    }
    if (n * n == num)
    {
        total += n;
    }
    return total;
}

/// Initialize the abundants vector and array.
void initialize_abundants(std::array<bool, MAX_LIMIT>& abundants_array, std::vector<int>& abundants_vector) {
    for (int i = 12; i < MAX_LIMIT; i++)
    {
        if (get_divisors_sum(i) > i)
        {
            abundants_array[i] = true;
            abundants_vector.push_back(i);
        }
        else
        {
            abundants_array[i] = false;
        }
    }
}


/// If n is a sum of two abundents - it returns 0, otherwise, it return n.
int calc_value_to_add(const std::array<bool, MAX_LIMIT>& abundants_array, const std::vector<int>& abundants_vector, int n) {
    for (int current_abundant : abundants_vector)
    {
        if (current_abundant >= n) {
            return n;
        }
        if (abundants_array[n - current_abundant])
        {
            return 0;
        }
    }
    return n;
}


/// Main function.
int main()
{
    int sum = 0;
    std::array<bool, MAX_LIMIT> abundants_array;
    std::vector<int> abundants_vector;
    initialize_abundants(abundants_array, abundants_vector);

    for (int i = 1; i < MAX_LIMIT; i++)
    {
        sum += calc_value_to_add(abundants_array, abundants_vector, i);
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}

