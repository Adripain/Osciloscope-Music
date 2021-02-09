/*
** EPITECH PROJECT, 2020
** my str n cmp
** File description:
** comparing to strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int s1_size = 0;
    int s2_size = 0;

    while (s1[i] != '\0' && i < n) {
        s1_size += s1[i];
        i+=1;
    }
    i = 0;
    while (s2[i] != '\0' && i < n) {
        s2_size += s2[i];
        i+=1;
    }
    if (s1_size < s2_size)
        return (-1);
    else if (s1_size == s2_size)
        return (0);
    else if (s1_size > s2_size)
        return (1);
    return (0);
}
