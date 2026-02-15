#include <stdio.h>
#include <mpi.h>

/* Function Prototypes */
double Trap(double left, double right, int n, double h);
double f(double x);

void BCS223020_Input(double* a, double* b, int* n, int rank, int size);
void BCS223020_Print(double a, double b, int n, double total);

/* Main Function */
int main(void) {

    int rank, size, n, local_n;
    double a, b, h;
    double local_a, local_b;
    double local_int, total_int;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Part A: Input */
    BCS223020_Input(&a, &b, &n, rank, size);

    h = (b - a) / n;
    local_n = n / size;

    local_a = a + rank * local_n * h;
    local_b = local_a + local_n * h;

    local_int = Trap(local_a, local_b, local_n, h);

    /* Part B & C */
    if (rank == 0) {

        total_int = local_int;
        printf("\nThe trapezoid area calculated by Process 0 of %d is %lf\n",
               size, local_int);

        for (int src = 1; src < size; src++) {
            MPI_Recv(&local_int, 1, MPI_DOUBLE, src, 0,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            printf("The trapezoid area received by Process %d of %d is %lf\n",
                   src, size, local_int);

            total_int += local_int;
        }

        /* Part C: Final Output */
        BCS223020_Print(a, b, n, total_int);
    }
    else {
        MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

/*--------------------------------------------------*/
/* Part A: Input Function */
void BCS223020_Input(double* a, double* b, int* n, int rank, int size) {

    if (rank == 0) {
        printf("Enter value of a: ");
        scanf("%lf", a);

        printf("Enter value of b: ");
        scanf("%lf", b);

        printf("Enter number of trapezoids (n): ");
        scanf("%d", n);

        for (int i = 1; i < size; i++) {
            MPI_Send(a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
            MPI_Send(b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
            MPI_Send(n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}

/*--------------------------------------------------*/
/* Part C: Print Function */
void BCS223020_Print(double a, double b, int n, double total) {

    printf("\n----------------------------------\n");
    printf("Final Result (BCS223020)\n");
    printf("Integral from %.2f to %.2f\n", a, b);
    printf("Using %d trapezoids\n", n);
    printf("Final Integral Value = %lf\n", total);
    printf("----------------------------------\n");
}

/*--------------------------------------------------*/
/* Trapezoidal Rule */
double Trap(double left, double right, int n, double h) {

    double sum = (f(left) + f(right)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += f(left + i * h);
    }

    return sum * h;
}

/*--------------------------------------------------*/
/* Function f(x) */
double f(double x) {
    return x * x;
}

