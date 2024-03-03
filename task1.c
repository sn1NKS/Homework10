#include <stdio.h>
#include <string.h>
#define SIZE 100

void is_symbols(int size, char *str)
{
    int i, j;
    char tmp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (str[i] == ' ')
                i++;
            j = i + 1;

            if (str[j] == ' ')
                j++;

            if (j >= size)
                break;

            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i = j + 1;
        }
    }
}

int main(void)
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    FILE *f_in = fopen(name_in, "r");
    FILE *f_out = fopen(name_out, "w");

    char str[SIZE];

    fscanf(f_in, "%[^\n]", str);

    int len = strlen(str);

    is_symbols(len, str);

    fprintf(f_out, "%s", str);

    fclose(f_in);
    fclose(f_out);

    return 0;
}