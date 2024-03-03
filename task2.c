#include <stdio.h>
#include <string.h>

enum States
{
    Start,
    In,
    Out
};

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    int c, state = Start;

    while ((c = fgetc(f_in)) != EOF)
    {
        switch (state)
        {
        case Start:
            if (c != ' ')
            {
                state = In;
                fputc(c, f_out);
            }
            break;

        case In:
            if (c == ' ')
                state = Out;
            else
                fputc(c, f_out);
            break;

        case Out:
            if (c != ' ')
            {
                state = In;
                fputc(' ', f_out);
                fputc(c, f_out);
            }
            break;
        }
    }

    fclose(f_in);
    fclose(f_out);

    return 0;
}