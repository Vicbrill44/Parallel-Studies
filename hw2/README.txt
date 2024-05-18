To run these prgs we do the same things as usual source and load mpicc and then we compile our code

The kicker here is that our prg is expecting some arguments from the jump argc argsv and thus we must execute the prg..
like so... 
mpiexec -3 ./mpi_mcpi_p2p 10000



where the -3 is number of processes and the 10000 is the arguments that our prg wants from the jump
