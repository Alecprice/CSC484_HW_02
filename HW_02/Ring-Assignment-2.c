#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
 

int main(void)
{
    char Greeting[100];
    int comm_sz, my_rank;
 
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 
    sprintf(Greeting, "Greeting from process %d!", my_rank);
    MPI_Send(&Greeting, strlen(Greeting) + 1, MPI_CHAR, (my_rank + 1) % comm_sz, 0, MPI_COMM_WORLD);

    /* print out the message */
	printf("Process %d sent message to process %d\n", my_rank, (my_rank + 1) % comm_sz);


    if (my_rank != 0)
   {     
      
 MPI_Recv(Greeting, 100, MPI_CHAR, my_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  

      /* print out the message */
      printf("Process %d received message: %s\n", my_rank, Greeting);  



   }

    else
   {
      
 MPI_Recv(Greeting, 100, MPI_CHAR, comm_sz - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
      /* print out the message */
       printf("Process %d received message: %s\n", my_rank, Greeting);   



   }

    MPI_Finalize();    

    return 0;
}

