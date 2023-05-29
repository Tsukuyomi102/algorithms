#include <iostream>

void insert(int* arr, int length)
{
    std::cout << "Input the numbers in array: ";
    for (size_t i = 0; i < length; i++)
    {
       
        std::cin >> arr[i];
    }
}

void show(int* arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int* sequence(int* arr, int length)
{
    int count = 1;
    int* new_arr = new int[length];
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
        }

        else
        {
            new_arr[i] = count;
            count = 1;
        }
    }

    return new_arr;
}

int max_sequence(int* arr, int length)
{
    int max = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

int main()
{
    std::cout << "Input the number of length: ";
    int length;
    std::cin >> length;
    int * arr = new int[length];
    insert(arr, length);
    std::cout << "Your array" << '\n';
    show(arr, length);
    int* new_arr = sequence(arr, length);
    std::cout << '\n' << "The max sequence = " << max_sequence(new_arr, length);
}