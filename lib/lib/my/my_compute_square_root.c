/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** a function that returns the square root (if it is a whole number)
** of the number given as argument.
** If the square root is not a whole number, the function will return 0.
*/

int my_compute_square_root(int nb)
{
    int res = 1;
    int root = 1;

    while (res <= nb) {
        res = root * root;
        if (res == nb) {
            return root;
        } else {
            root++;
        }
    }
    return 0;
}
