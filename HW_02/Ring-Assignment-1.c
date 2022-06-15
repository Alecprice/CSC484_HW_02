#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
 

int main(void)
{
    int comm_sz, my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   
	int token = my_rank + 1;

    MPI_Send(&token, 1, MPI_INT, (my_rank + 1) % comm_sz, 0, MPI_COMM_WORLD);

    if (my_rank == 0){
        
      MPI_Recv(&token, 1, MPI_INT, comm_sz - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

/* print out the message */
       printf("Process %d received token value < %d > from process %d\n", my_rank, token, comm_sz - 1);     
    
   } else{
  
     MPI_Recv(&token, 1, MPI_INT, my_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  

 /* print out the message */
     printf("Process %d received token value < %d > from process %d\n", my_rank, token, my_rank - 1);
}

    MPI_Finalize();    

    return 0;
}

