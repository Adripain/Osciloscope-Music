/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** 
*/

int my_strlen(char *str);

char    *my_revstr(char *str)
{
    char char_temp;
    int first_char = 0;
    int last_char = my_strlen(str) - 1;

    while (first_char < last_char) {
        char_temp = str[first_char];
        str[first_char] = str[last_char];
        str[last_char] = char_temp;
        first_char+=1;
        last_char-=1;
    }
    return (str);
}
