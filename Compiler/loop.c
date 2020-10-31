#include <stdio.h>
int main()
{
    int num=10, count, sum = 0;

    // for loop terminates when num is less than count
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }

    printf("Sum = %d", sum);

    return 0;
}