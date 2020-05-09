#include<iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
  // Initialize the MPI environment.
  MPI_Init(NULL, NULL);

  int world_size,world_rank,name_len;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  
  // Get the number of processes
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get the rank of the process
  
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Get the name of the processor
  MPI_Get_processor_name(processor_name, &name_len);

  // Print off a hello world message
  cout<<"\nHello world from processor : "<<processor_name;
  cout<<"\nRank  : "<<world_rank<<" out of "<<world_size<<" processors\n";

  // Finalize the MPI environment. No more MPI calls can be made after this
  MPI_Finalize();
  
  return 0;
}