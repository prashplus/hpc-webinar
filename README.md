# HPC-Webinar

## Prerequisites

Before you start running any of the demo. You need to install mpich in your system.
```console
foo@bar:~$ sudo apt install mpich
```
### Things to Note

* These examples will work fine if you are running on single machine.
* For multiple machines, keep your host file updated.
* If your machines are not on the Intranet, /etc/hosts files needs to be modified, since MPI looks for the hostnames. For that, a sample script has been provided.
* MPI programs are hard to debug. Since, error can be generated by any one of the processes which makes it hard to track.
* Debuggers are available but are complicated to run. (I will attach a link if I will come accros a simple one)

## Program List

### 0. Hello World

Just a simple Hello World Program. Every process prints out its rank(Its a number given to each process) and the hostname its running on.

To get the total number of processes running in given communicator(default : all).
```cpp
MPI_Comm_size(
    MPI_Comm communicator,
    int* size)
```

To get the rank of the current process in the given communicator.
```cpp
MPI_Comm_rank(
    MPI_Comm communicator,
    int* rank)
```

To get the hostname/processor name where current process is running.
```cpp
MPI_Get_processor_name(
    char* name,
    int* name_length)
```

### 1. Send Receive

Note :  This program will only work with 2 processes.

This program demonstrate simple send recieve operation being performed between 2 processes.

Rank 0 will send 1 integer to Rank 1.
Rank 1 will print the received data.

Send function call:
```cpp
MPI_Send(
    void* data,
    int count,
    MPI_Datatype datatype,
    int destination,
    int tag,
    MPI_Comm communicator)
```

Receive Function call:
```cpp
MPI_Recv(
    void* data,
    int count,
    MPI_Datatype datatype,
    int source,
    int tag,
    MPI_Comm communicator,
    MPI_Status* status)
```

### 2. Broadcast

This program make use of the MPI_Collective calls. This are the functions that are required to be called by all the members of the communicator.

MPI_Bcast Function call:
```cpp
MPI_Bcast(
    void* data,
    int count,
    MPI_Datatype datatype,
    int root,
    MPI_Comm communicator)
```

## Authors

* **Prashant Piprotar** - - [Prash+](https://github.com/prashplus)

Visit my [Blog](http://prashplus.blogspot.com) for more Tech Stuff
### http://www.prashplus.com