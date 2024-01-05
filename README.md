Banker's Algorithm, Coded by Charlie Dovey m00843428 for CST2555.

Bankers Algorithm
The Bankers Algorithm in OS is an algorithm used to manage and allocate resources in a multi-task environment. It is used to prevent deadlocks and ensure the system remains in a safe state. The algorithm works by keeping track of the available resources in the system and allocating them to processes in a way that ensures that the system will not run out of resources and enter a deadlock state. The Banker’s Algorithm in OS uses a combination of resource allocation and deadlock detection to ensure efficient resource usage and prevent system failures.

Available
Available[ j ] = k means there are ‘k’ instances of resource type Rj

Max
Max[ i, j ] = k means process Pi may request at most ‘k’ instances of resource type Rj.

Allocation
Allocation[ i, j ] = k means process Pi is currently allocated ‘k’ instances of resource type Rj

Need
Need [ i,   j ] = k means process Pi currently needs ‘k’ instances of resource type Rj
Need [ i,   j ] = Max [ i,   j ] – Allocation [ i,   j ]

The Algorithm used to code the program follows:
1. Start the program.
2. Get the values of resources and processes.
3. Get the available value.
4. After allocation find the need value.
5. Check whether it’s possible to allocate.
6. If it is possible then the system is in the safe state.
7. Else system is not in the safety state.
8. If the new request comes then check that the system is in safe state.
9. If so, grant the request.
10. If not, deny the request.
11. Stop the program.