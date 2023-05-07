#include <stdio.h>
#define MAX 4

int main()
{

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame[MAX];
    int used[MAX];
    int page_faults = 0;

    // initializing frames nd used
    for (int i = 0; i < MAX; i++)
    {
        frame[i] = -1;
        used[i] = 0;
    }
    // iterate thru pages
    // if page is present in frame
    int min, lru_index;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < MAX; j++)
        {

            if (frame[j] == pages[i])
            {

                flag = 1;
                used[j] = 1;

                break;
            }
        }
        if (!flag)
        {
            // if page is not present
            min = used[0]; // let first used page be min
            lru_index = 0;
            for (int k = 1; k < MAX; k++)
            {
                if (min > used[k])
                {
                    min = used[k];
                    lru_index = k;
                }
            }

            // replace the frame as lru fram
            frame[lru_index] = pages[i];
            used[lru_index] = 1;

            page_faults++;
            printf("\nPage Fault\n");
        }
        for (int k = 0; k < MAX; k++)
        {
            if (frame[k] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", frame[k]);
            }
           
        }
         printf("\n");
    }
    printf("\nTotal page faults: %d", page_faults);

    return 0;
}