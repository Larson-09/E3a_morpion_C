#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count_i = 0 ;
    int count_j = 1 ;

    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            if(i == 1)
            {   
                goto fin_boucle_for;
            }

            printf("boucle j\n");
            printf("-----\n");
        }
        printf("boucle i\n");
        printf("-----\n");
    }
    fin_boucle_for:

    printf("suite");
}