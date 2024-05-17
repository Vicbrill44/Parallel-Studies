#include<stdio.h>
#include<string.h>
#include<mpi.h>

//this is the function under which we are trying to find the area under the curve
//in this case we are using the function x^2
double f(double x){
    return x * x;

}

//this function is calculating the area of a trapz
double Trap(
    double left_endpt,
    double right_endpt,
    int trap_count,
    double base_len) {
        double estimate, x;
        int i;
        estimate = (f(left_endpt) + f(right_endpt))/2.0; //here we are taking the difference of the left and right endpoints and dividing it by 2 to start
        //here we are finding the area off all the traps we are assigned to find
        for( i= 1; i <= trap_count-1; i++){
            x = left_endpt + i * base_len;
            estimate += f(x);
        }
        estimate = estimate * base_len;  
        return estimate;
}

//this function will handle input and sending out global info to all processes
void Get_input(
    int my_rank,
    int comm_sz,
    double* a_p,
    double* b_p,
    int* n_p
){
    if(my_rank == 0){
        printf("Enter a, b, and n\n");
        scanf("%lf %lf %d", a_p, b_p, n_p);
    }
    MPI_Bcast(a_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(n_p, 1, MPI_INT, 0, MPI_COMM_WORLD);
}


int main(void){
    int my_rank, comm_sz, n, local_n;
    double a, b, h, local_a, local_b;
    double local_int, total_int;
    int source;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    Get_input(my_rank, comm_sz, &a, &b, &n);
    h = (b-a)/n; //the length of each trapz 
    local_n = n/comm_sz; //how many trapz will be in each process

    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;

    local_int = Trap(local_a, local_b, local_n, h);

    if(my_rank != 0){
        MPI_Send(&local_int, 1, MPI_DOUBLE, 0,0, MPI_COMM_WORLD);
    }
    else{
        total_int = local_int;
        for(source =1; source<comm_sz; source++){
            MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_int += local_int;
        }
    }

    if(my_rank == 0){
        printf("With n = %d trapz, our estimate \n", n);
        printf("of the integral from %f to %f = %f\n", a, b, total_int);
    }

    MPI_Finalize();
    return 0;



}






















