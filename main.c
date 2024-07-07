#include <stdio.h>

int calculateSequences(int length)
{
    if (length == 1) return 2;
    if (length == 2) return 4;
    int sequences[length+1];
    sequences[0] = 1;
    sequences[1] = 2;
    sequences[2] = 4;
    for (int i = 3; i <= length; i++)
    {
        sequences[i] = (sequences[i-1] + sequences[i-2] + sequences[i-3]) % 12345;
    }

    return sequences[length];
}

int main()
{
    int length;
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);
    if (length < 2 || length >= 10000)
    {
        printf("The length of the sequence must be in the range 2 <= length < 10000\n");
        return 1;
    }
    printf("Number of valid sequences: %d\n", calculateSequences(length));
    return 0;
}