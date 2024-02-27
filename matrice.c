#include <stdio.h>

int main() {
    int number[2][3];
    int tab[3][7];
    int rows = sizeof(tab)/sizeof(tab[0]);
    int columns = sizeof(tab[0])/sizeof(tab[0][0]);
    printf("rows : %d\n",rows);
    printf("columns: %d\n",columns);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter number[%d][%d]: ", i, j);
            scanf("%d", &number[i][j]);
        }
    }

    // Printing the entered values
    printf("Entered numbers:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", number[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}
