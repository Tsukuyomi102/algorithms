#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

#include "timer.h"

typedef uint8_t bitmask_t;

constexpr auto CHUNK_BITS = 8;
constexpr auto MASK_8b_MSB = 0b10000000;
constexpr auto MASK_64b_MSB = 0b1000000000000000000000000000000000000000000000000000000000000000;

void set_the_5th_bit()
{
    unsigned int number = 255;
    uint8_t mask = 1;
    std::cout << number << " in the bin: " << std::bitset<8>(number) << '\n';
    number = number & (~(mask << 4));
    std::cout << "The changed number" << '\n';
    std::cout << number << " in the bin: " << std::bitset<8>(number) << '\n';
}

void set_the_7th_bit()
{
    unsigned int number = 255;
    uint8_t mask = 1;
    std::cout << number << " in the bin: " << std::bitset<8>(number) << '\n';
    number = number & (~(mask << 6));
    std::cout << "The changed number" << '\n';
    std::cout << number << " in the bin: " << std::bitset<8>(number) << '\n';
}

void set_25_in_mask()
{
    unsigned int number = 25;
    const int chunk = sizeof(int) * CHUNK_BITS;
    unsigned mask = (1 << chunk - 1);
    std::cout << "Initial view of the mask: " << std::bitset<chunk>(mask) << '\n';

    std::cout << "The result: ";
    for (size_t i = 1; i < chunk; i++)
    {
        std::cout << ((number & mask) >> (chunk - i));
        mask = mask >> 1;
    }

    std::cout << '\n';
}

void show_the_array(int arr[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}

void show_the_dynamic_array(int* arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void fill_the_array(int* arr, int length)
{
    std::cout << "Input the " << length << " numbers: ";
    for (size_t i = 0; i < length; i++)
    {
        int value;
        std::cin >> value;
        arr[i] = value;
    }
}

void easy_bitsort()
{
    const int length = 6;
    uint8_t mask = 0;
    int arr[length] = { 1, 0, 5, 7, 2, 4 };
    std::cout << "Initial view of the array: ";
    show_the_array(arr, length);

    for (size_t i = 0; i < length; i++)
    {
        mask = mask | (MASK_8b_MSB >> arr[i]);
    }
    std::cout << "View of the mask: " << std::bitset<8>(mask) << '\n';

    for (size_t i = 0, j = 0; i < 8; i++)
    {
        if ((mask & (MASK_8b_MSB >> i)) > 0)
        {
            arr[j++] = i;
        }
    }

    std::cout << "The sorting array: ";
    show_the_array(arr, length);
}

void medium_bitsort()
{
    const int length = 12;
    long long mask = 0;
    int arr[length] = { 23, 12, 54, 63, 32, 18, 4, 9, 28, 37, 39, 1 };

    std::cout << "Initial view of the array: ";
    show_the_array(arr, length);

    for (size_t i = 0; i < length; i++)
    {
        mask = mask | (MASK_64b_MSB >> arr[i]);
    }
    std::cout << "View of the mask: " << std::bitset<64>(mask) << '\n';

    for (size_t i = 0, j = 0; i < 64; i++)
    {
        if ((mask & (MASK_64b_MSB >> i)) > 0)
        {
            arr[j++] = i;
        }
    }

    std::cout << "The sorting array: ";
    show_the_array(arr, length);
}

void fill_bitmask(bitmask_t* bitmask_ptr, int* arr_ptr, size_t arr_size)
{
    for (size_t i = 0; i < arr_size; ++i)
    {
        bitmask_ptr[arr_ptr[i] / CHUNK_BITS] |= MASK_8b_MSB >> (arr_ptr[i] % CHUNK_BITS);
    }
}

void fill_array(bitmask_t* bitmask_ptr, size_t mask_chunks, int* arr_ptr)
{
    for (size_t i = 0, j = 0; i < mask_chunks * CHUNK_BITS; ++i)
    {
        if (bitmask_ptr[i / CHUNK_BITS] & (MASK_8b_MSB >> (i % CHUNK_BITS)))
        {
            arr_ptr[j++] = i;
        }
    }
}

void hard_bitsort()
{
    int length;
    size_t max_number;
    std::cout << "Input the length of the array: ";
    std::cin >> length;
    std::cout << "Name the biggest number in the array: ";
    std::cin >> max_number;
    int* dynamic_arr = new int[length];
    fill_the_array(dynamic_arr, length);

    std::cout << "Initial view of the array: ";
    show_the_dynamic_array(dynamic_arr, length);

    size_t mask_chunks{ max_number / CHUNK_BITS + 1 };
    bitmask_t* mask = new uint8_t[mask_chunks]{};

    fill_bitmask(mask, dynamic_arr, length);
    fill_array(mask, mask_chunks, dynamic_arr);

    std::cout << "The sorting array: ";
    show_the_array(dynamic_arr, length);

    delete[] mask;
}

void bitsort(int* arr_ptr, size_t arr_size)
{
    size_t mask_chunks{ arr_size / CHUNK_BITS + 1 };
    bitmask_t* mask = new uint8_t[mask_chunks]{};

    fill_bitmask(mask, arr_ptr, arr_size);
    fill_array(mask, mask_chunks, arr_ptr);

    delete[] mask;
}

void show_bitmask(bitmask_t* bitmask_ptr, size_t mask_chunks)
{
    for (size_t i = 0; i < mask_chunks; i++)
    {
        std::bitset<CHUNK_BITS> res{ bitmask_ptr[i] };
        std::cout << res;
    }

    std::cout << '\n';
}

int* read_file(std::string path, size_t arr_size, size_t buffer_size)
{
    char* buffer = new char[buffer_size];
    int* arr = new int[arr_size];

    std::ifstream f1{ path, std::ios::binary };

    size_t arr_offset{ 0 };
    for (size_t i = 0; i < arr_size * sizeof(int) / buffer_size; ++i)
    {
        f1.read(buffer, buffer_size);

        int* ptr = (int*)buffer;
        for (size_t j = 0; j < buffer_size / sizeof(int); ++j)
        {
            arr[arr_offset++] = *ptr;
            ++ptr;
        }
    }

    f1.close();
    delete[] buffer;
    return arr;
}

void write_file(std::string path, int* arr_ptr, size_t arr_size, size_t buffer_size)
{
    std::ofstream output{ path };

    std::string num;
    num.reserve(buffer_size);

    size_t arr_offset{ 0 };
    for (size_t i = 0; i < arr_size / buffer_size; ++i)
    {
        num.clear();
        for (size_t j = 0; j < buffer_size; j++)
        {
            num += std::to_string(arr_ptr[arr_offset++]) + ' ';
        }

        output.write(num.data(), num.length());
    }

    output.close();
}

int main()
{
    int menu_button;

    do
    {
        std::cout << "\nInput the number of task, 0 - exit from programm\n" <<
            "1 - Setting the 5th bit of number 255 to 0\n" <<
            "2 - Setting the 7th bit of number 255 to 0\n" <<
            "3 - Setting 25 in the 32th bit mask\n" <<
            "4 - Sort the array from 0 to 7\n" <<
            "5 - Sorting the array from 0 to 63\n" <<
            "6 - Sorting the array arbitrary non-negative numbers\n" <<
            "7 - Sorting the file of 1 to 10_000_000 numbers\n";
        std::cin >> menu_button;

        switch (menu_button)
        {

        case 1:
            set_the_5th_bit();
            break;

        case 2:
            set_the_7th_bit();
            break;

        case 3:
            set_25_in_mask();
            break;

        case 4:
            easy_bitsort();
            break;

        case 5:
            medium_bitsort();
            break;

        case 6:
            hard_bitsort();
            break;

        case 7:
            constexpr size_t out_buffer_size = 4000;
            constexpr size_t in_buffer_size = 4000;
            constexpr size_t arr_size = 10000000;

            std::string in_path{ "numbers.dat" };
            std::string out_path{ "out.txt" };

            Timer timer = Timer();

            std::cout << "Reading file...\n";
            timer.now();

            // arr_size mod buffer_size = 0 !!!
            int* arr = read_file(in_path, arr_size, in_buffer_size);

            timer.now();
            std::cout << "Elapsed: " << timer << "\n\n";
            std::cout << "Sorting...\n";
            timer.now();

            bitsort(arr, arr_size);

            timer.now();
            std::cout << "Elapsed: " << timer << "\n\n";
            std::cout << "Writing to file...\n";
            timer.now();

            // Buffer size in numbers output
            write_file(out_path, arr, arr_size, out_buffer_size);

            timer.now();
            std::cout << "Elapsed: " << timer << "\n\n";
            break;
        }
    } while (menu_button != 0.0);
}