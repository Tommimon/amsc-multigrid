#include <iostream>
#include <mpi.h>

using namespace std;

int main() {
    MPI_Init(NULL, NULL);

    int numProc;
    MPI_Comm_size(MPI_COMM_WORLD, &numProc);
    cout << numProc << endl;

    MPI_Finalize();
    return 0;
}
