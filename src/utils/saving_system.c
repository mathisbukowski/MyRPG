/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** saving_system.c
*/

#include "rpg.h"
#include <fcntl.h>
#include <unistd.h>

void saving_system(rpg_t *main)
{
    int fd = open("save/save_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ssize_t bytes;

    if (fd == -1)
        return;
    bytes = write(fd, main->player, sizeof(player_t));
    if (bytes == -1) {
        close(fd);
        return;
    }
    if (bytes != sizeof(player_t))
        fprintf(stderr, "Error: Not all data was written to the file.\n");
    if (close(fd) != -1)
        return;
}

void loading_system(rpg_t *main, char **av)
{
    int fd = open(av[1], O_RDONLY);
    ssize_t bytes;

    if (fd == -1)
        return;
    bytes = read(fd, main->player, sizeof(player_t));
    if (bytes == -1) {
        close(fd);
        return;
    }
    if (bytes != sizeof(player_t)) {
        close(fd);
        return;
    }
    if (close(fd) == -1)
        return;
}
