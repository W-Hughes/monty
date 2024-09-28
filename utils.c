#include "monty.h"

/**
 *_trim - Removes leading white spaces characters
 *@str: String argument
 *Return: Pointer to the first non-whitespace character
 *	of the sting;
 */


char *_trim(char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str && (*str == ' ' || *str =='\t'))
		++str;

	if (*str == '\0')
		return (NULL);

	return (str);
}

/**
 *find_first_digit - Get the first digit in a string
 *@s: The stirng argument to search through
 *
 * Return: Pointer to the first digit in the string,
 * 	therewise NuLL on failure
 */

char *find_first_digit(char *s)
{
	if (!s)
		return (NULL);
	while (*s && !_isdigit(*s))
		++s;
	if (*s == '\0')
		return (NULL);
	return (s);
}


/**
 *_strlen - Returns the length of a string.
 *@s: Pointer to the string.
 *
 * Return: Length of the string.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 *_isdigit - Checks if a character is a digit (0 through 9)
 *@c: the character to be checked.
 *
 *Return: 1 if character is digit, otherwise return 0.
 */

int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}


/**
 *_strcmp - Compares two strings.
 *@s1: first string,
 *@s2: second string.
 *
 * Return: Am integer value equal to the difference
 * of first string,and second string.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 *_strcmp - Compares two strings.
 *@s1: first string,
 *@s2: second string.
 *@n: length of s2 to compare.
 *
 * Return: Am integer value equal to the difference
 * of first string,and second string.
 */

int _strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
    {
        if (*(s1 + i) == *(s2 + i))
        {
            ++i;
        }
        else
        {
            return (*(s1 + i) - *(s2 + i));
        }
    }
    if (i == n && (*(s1 + i) == ' ' || *(s1 + i) == '\t' ||
                   *(s1 + i) == '\0' || *(s1 + i) == '\n'))
        return (0);
    return (EXIT_FAILURE); /* one of the strings was too short, not the best*/
}

