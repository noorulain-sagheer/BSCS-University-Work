#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

/* Function Prototypes */
void BCS223020_Input(double **a, double **x,int *m, int *n, int rank, int size);
                     

void BCS223020_Multiplication(double *local_a, double *x,double *local_y, int local_rows, int n);
                              

void BCS223020_Print(double *local_y, double *y, int local_rows, int m, int rank);
                    

void BCS223020_Mytime(double start, double end, int rank);

int main() {

    int rank, size;
    int m = 0, n = 0, local_rows;
    int continue_flag = 1;

    double *a = NULL, *x = NULL, *y = NULL;
    double *local_a = NULL, *local_y = NULL;

    double start_time, end_time;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    while (continue_flag) {

        /* ---------- INPUT & VALIDATION ---------- */
        BCS223020_Input(&a, &x, &m, &n, rank, size);

        local_rows = m / size;

        local_a = (double *)malloc(local_rows * n * sizeof(double));
        local_y = (double *)malloc(local_rows * sizeof(double));

        if (rank == 0)
            y = (double *)malloc(m * sizeof(double));

        start_time = MPI_Wtime();

        /* ---------- DISTRIBUTE MATRIX ---------- */
        MPI_Scatter(a, local_rows * n, MPI_DOUBLE,
                    local_a, local_rows * n, MPI_DOUBLE,
                    0, MPI_COMM_WORLD);

        /* ---------- LOCAL COMPUTATION ---------- */
        BCS223020_Multiplication(local_a, x, local_y, local_rows, n);

        /* ---------- COLLECT & PRINT RESULT ---------- */
        BCS223020_Print(local_y, y, local_rows, m, rank);

        end_time = MPI_Wtime();
        BCS223020_Mytime(start_time, end_time, rank);

        /* ---------- CONTINUE ? ---------- */
        int valid_choice = 0;
        char choice_str[10];

        while (!valid_choice) {

            if (rank == 0) {
                printf("\nDo you want to continue? (y/n): ");
                scanf("%9s", choice_str);

                if (strcmp(choice_str, "y") == 0 || strcmp(choice_str, "Y") == 0) {
                    continue_flag = 1;
                    valid_choice = 1;
                }
                else if (strcmp(choice_str, "n") == 0 || strcmp(choice_str, "N") == 0) {
                    continue_flag = 0;
                    valid_choice = 1;
                }
                else {
                    printf(" Invalid input! Enter only 'y' or 'n'.\n");
                    valid_choice = 0;
                }
            }

            MPI_Bcast(&valid_choice, 1, MPI_INT, 0, MPI_COMM_WORLD);
            MPI_Bcast(&continue_flag, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }

        /* ---------- FREE MEMORY SAFELY ---------- */
        free(local_a);
        free(local_y);
        local_a = local_y = NULL;

        if (rank == 0) {
            free(a);
            free(x);
            free(y);
            a = x = y = NULL;
        }
    }

    MPI_Finalize();
    return 0;
}

/*--------------------------------------------------*/
/* INPUT FUNCTION (ROBUST & SYNCHRONIZED) */
void BCS223020_Input(double **a, double **x,
                     int *m, int *n, int rank, int size) {

    int vector_size;
    int valid_input = 0;

    do {
        if (rank == 0) {

            printf("\nEnter number of rows (m): ");
            scanf("%d", m);

            printf("Enter number of columns (n): ");
            scanf("%d", n);

            printf("Enter vector size: ");
            scanf("%d", &vector_size);

            valid_input = 1;

            if (*m <= 0 || *n <= 0) {
                printf(" Error: Dimensions must be positive.\n");
                valid_input = 0;
            }
            else if (*m % size != 0) {
                printf(" Error: m must be divisible by %d.\n", size);
                valid_input = 0;
            }
            else if (vector_size != *n) {
                printf(" Error: Vector size must equal n.\n");
                valid_input = 0;
            }
        }

        MPI_Bcast(&valid_input, 1, MPI_INT, 0, MPI_COMM_WORLD);

    } while (!valid_input);

    MPI_Bcast(m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {

        *a = (double *)malloc((*m) * (*n) * sizeof(double));
        *x = (double *)malloc((*n) * sizeof(double));

        printf("Enter matrix A (%dx%d):\n", *m, *n);
        for (int i = 0; i < (*m) * (*n); i++)
            scanf("%lf", &(*a)[i]);

        printf("Enter vector X (size %d):\n", *n);
        for (int i = 0; i < *n; i++)
            scanf("%lf", &(*x)[i]);
    }
    else {
        *a = (double *)malloc((*m) * (*n) * sizeof(double));
        *x = (double *)malloc((*n) * sizeof(double));
    }

    MPI_Bcast(*a, (*m) * (*n), MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(*x, (*n), MPI_DOUBLE, 0, MPI_COMM_WORLD);
}

/*--------------------------------------------------*/
/* MULTIPLICATION */
void BCS223020_Multiplication(double *local_a, double *x,
                              double *local_y, int local_rows, int n) {

    for (int i = 0; i < local_rows; i++) {
        local_y[i] = 0.0;
        for (int j = 0; j < n; j++)
            local_y[i] += local_a[i * n + j] * x[j];
    }
}

/*--------------------------------------------------*/
/* PRINT RESULT */
void BCS223020_Print(double *local_y, double *y,
                     int local_rows, int m, int rank) {

    MPI_Gather(local_y, local_rows, MPI_DOUBLE,
               y, local_rows, MPI_DOUBLE,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\nFinal Result Vector y:\n");
        for (int i = 0; i < m; i++)
            printf("%lf\n", y[i]);
    }
}

/*--------------------------------------------------*/
/* TIME FUNCTION */
void BCS223020_Mytime(double start, double end, int rank) {

    if (rank == 0)
        printf("\nTime taken (including communication): %lf seconds\n",
               end - start);
}

