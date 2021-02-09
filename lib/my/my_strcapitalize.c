/*
** EPITECH PROJECT, 2020
** my super mtr capitalize
** File description:
** copy a string from a memory loc to another
*/

int my_is_integer(char str)
{
    int i = 0;

    while (str != '\0') {
        if (str >= '0' && str <= '9')
            return (1);
        else
            return (0);
        i+=1;
    }
    return (0);
}

int my_is_letter(char str)
{
    int i = 0;

    while (str != '\0') {
        if (str >= 'a' && str <= 'z')
            return (1);
        else if (str >= 'A' && str <= 'Z')
            return (2);
        else
            return (0);
        i++;
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (my_is_letter(str[0]) == 1)
        str[0] -= 32;
    while (str[i] != '\0') {
        if (my_is_letter(str[i]) == 2 && my_is_integer(str[i - 1]))
            str[i] += 32;
        else if (my_is_letter(str[i]) == 1 && !my_is_letter(str[i - 1]))
            str[i] -= 32;
        else if (my_is_letter(str[i]) == 2 && my_is_letter(str[i - 1]) == 1)
            str[i] += 32;
        else if (my_is_letter(str[i]) == 2 && my_is_letter(str[i - 1]) == 2)
            str[i] += 32;
        i+=1;
    }
    return (str);
}
