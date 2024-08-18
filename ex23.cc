#include <iostream>
#include <cmath>
#include <vector>
#include <array>

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
void initialize_abundants(std::array<bool, 28123>& abundants_array, std::vector<int>& abundants_vector) {
    for (int i = 12; i < 28123; i++)
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
int sum_of_abundants(const std::array<bool, 28123>& abundants_array, const std::vector<int>& abundants_vector, int n) {
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
    std::array<bool, 28123> abundants_array;
    std::vector<int> abundants_vector;
    initialize_abundants(abundants_array, abundants_vector);
    for (int i = 1; i < 28123; i++)
    {
        sum += sum_of_abundants(abundants_array, abundants_vector, i);
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}