#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int i;
    long data_size = 10;
    if(argc == 2){
        data_size = atoi(argv[1]);
    }

    // Allocating memery for data in each process
    int *data = (int *)malloc(sizeof(int)*data_size);

    // Initialize starting 5 elements to prove MPI_Bcast is working
    if(world_rank == 0){
        for(i=0;i<data_size;i++){
            data[i]=1;
        }
    }

    //MPI Broadcast call
    MPI_Bcast(data,data_size,MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);


    // Checking content after Broadcast
    cout<<"\nRank : "<<world_rank<<"\nData : ";
    for(i=0;i<5;i++){
        cout<<"  "<<data[i];
    }

    MPI_Finalize();
}