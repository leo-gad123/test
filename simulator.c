#include <stdio.h>

int main() {
    int data[3][3];
    float inverse[3][3];
    int d[3];

    printf("this is my working simulator by using c programming\n\n");
    printf("enter the element of index: ");

    // Input 3×3 matrix
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int a = 0; a < 3; a++) {
            scanf("%d", &data[i][a]);
        }
    }

    printf("this is for equality: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &d[i]);
    }

    printf("these are inputed element :\n");
    for (int i = 0; i < 3; i++) {
        printf("\n\n");
        for (int a = 0; a < 3; a++) {
            printf("%d     ", data[i][a]);
        }
    }
    printf("\n\n");

    // Calculate determinant
    int determinant =
          data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1])
        - data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0])
        + data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

    printf("Determinant = %d\n", determinant);

    if (determinant == 0) {
        printf("Inverse does not exist (determinant = 0).\n");
        return 0;
    }

    // Compute adjoint (cofactor matrix transpose)
    float adj[3][3];

    adj[0][0] =   (data[1][1] * data[2][2] - data[1][2] * data[2][1]);
    adj[0][1] = - (data[1][0] * data[2][2] - data[1][2] * data[2][0]);
    adj[0][2] =   (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

    adj[1][0] = - (data[0][1] * data[2][2] - data[0][2] * data[2][1]);
    adj[1][1] =   (data[0][0] * data[2][2] - data[0][2] * data[2][0]);
    adj[1][2] = - (data[0][0] * data[2][1] - data[0][1] * data[2][0]);

    adj[2][0] =   (data[0][1] * data[1][2] - data[0][2] * data[1][1]);
    adj[2][1] = - (data[0][0] * data[1][2] - data[0][2] * data[1][0]);
    adj[2][2] =   (data[0][0] * data[1][1] - data[0][1] * data[1][0]);

    // Divide adjoint by determinant to get inverse
    printf("\nInverse Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[i][j] = adj[i][j] / (float)determinant;
            printf("%0.3f   ", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
