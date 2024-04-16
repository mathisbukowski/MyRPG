/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** a function that swaps the content of two integers,
** whose addresses are given as a parameter.
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
