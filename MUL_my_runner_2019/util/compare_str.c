/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** compare 2 strings
*/

#include "runner.h"

int compare_str(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 != len2)
        return (FALSE);
    for (int i = 0; i != len1; i++)
        if (str1[i] != str2[i])
            return (FALSE);
    return (TRUE);
}
