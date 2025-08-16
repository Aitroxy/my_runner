/*
** EPITECH PROJECT, 2021
** compter nombre ecrire
** File description:
** task07 day03
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *int_to_str(int nb, char *score)
{
    int n = 1;
    int i = 0;

    if (nb < 10) {
        score[0] = (nb + 48);
        return (score);
    }
    while (nb / n != 0)
        n = n * 10;
    n = n / 10;
    while (n > 0) {
        score[i] = ((nb / n) + 48);
        i++;
        nb = nb % n;
        n = n / 10;
    }
    score[i] = '\0';
    return (score);
}
