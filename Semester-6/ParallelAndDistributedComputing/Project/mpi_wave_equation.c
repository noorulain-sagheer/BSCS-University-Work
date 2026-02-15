/*Project by group 13, on wave equation*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
    int rank, size;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N, T;
    double c;

    /* -------------------------------
       Input (only rank 0)
    ------------------------------- */
    if (rank == 0)
    {
        printf("Enter total number of spatial points (N): ");
        scanf("%d", &N);

        printf("Enter number of time steps (T): ");
        scanf("%d", &T);

        printf("Enter wave speed (c): ");
        scanf("%lf", &c);
    }

    /* Collab safe if (rank == 0)
{
    N = 40;     // number of spatial points
    T = 100;    // number of time steps
    c = 1.0;    // wave speed
}
*/     
    /* Broadcast inputs */
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&T, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&c, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* Ensure equal division */
    if (N % size != 0)
    {
        if (rank == 0)
            printf("Error: N must be divisible by number of processes\n");

        MPI_Finalize();
        return 0;
    }

    int local_n = N / size;

    /* Allocate arrays (+2 for halo cells) */
    double *u_prev = (double *)malloc((local_n + 2) * sizeof(double));
    double *u_curr = (double *)malloc((local_n + 2) * sizeof(double));
    double *u_next = (double *)malloc((local_n + 2) * sizeof(double));

    /* Initialize arrays */
    for (int i = 0; i <= local_n + 1; i++)
    {
        u_prev[i] = 0.0;
        u_curr[i] = 0.0;
        u_next[i] = 0.0;
    }

    /* Initial disturbance in middle of string */
  int global_mid = N / 2;
if (rank == global_mid / local_n)
    u_curr[global_mid % local_n + 1] = 1.0;
    
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    /* -------------------------------
       Time stepping loop
    ------------------------------- */
    for (int t = 0; t < T; t++)
    {
        /* Halo exchange with left neighbor */
        if (rank != 0)
        {
            MPI_Send(&u_curr[1], 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&u_curr[0], 1, MPI_DOUBLE, rank - 1, 0,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        /* Halo exchange with right neighbor */
        if (rank != size - 1)
        {
            MPI_Send(&u_curr[local_n], 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&u_curr[local_n + 1], 1, MPI_DOUBLE, rank + 1, 0,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        /* Finite difference update */
        for (int i = 1; i <= local_n; i++)
        {
            u_next[i] = 2.0 * u_curr[i] - u_prev[i]
                        + c * c * (u_curr[i + 1]
                        - 2.0 * u_curr[i]
                        + u_curr[i - 1]);
        }

        /* Fixed boundary conditions */
        if (rank == 0)
            u_next[1] = 0.0;

        if (rank == size - 1)
            u_next[local_n] = 0.0;

        /* Shift time levels */
        for (int i = 1; i <= local_n; i++)
        {
            u_prev[i] = u_curr[i];
            u_curr[i] = u_next[i];
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double end_time = MPI_Wtime();

    /* -------------------------------
       Gather final values to rank 0
    ------------------------------- */
    double *global_u = NULL;

    if (rank == 0)
        global_u = (double *)malloc(N * sizeof(double));

    MPI_Gather(&u_curr[1], local_n, MPI_DOUBLE,
               global_u, local_n, MPI_DOUBLE,
               0, MPI_COMM_WORLD);

    /* -------------------------------
       Print results (rank 0)
    ------------------------------- */
    if (rank == 0)
    {
        printf("\nFinal wave displacement values:\n");
        for (int i = 0; i < N; i++)
            printf("%8.4f ", global_u[i]);

        printf("\n\nExecution time with %d processes: %f seconds\n",
               size, end_time - start_time);

        free(global_u);
    }

    /* Cleanup */
    free(u_prev);
    free(u_curr);
    free(u_next);

    MPI_Finalize();
    return 0;
}

