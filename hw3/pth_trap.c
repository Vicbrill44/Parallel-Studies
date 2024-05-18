/* File:    trap.c
 * Purpose: Calculate definite integral using trapezoidal 
 *          rule.
 *
 * Input:   a, b, n
 * Output:  Estimate of integral from a to b of f(x)
 *          using n trapezoids.
 *
 * Compile: gcc -g -Wall -o trap trap.c
 * Usage:   ./trap
 *
 * Note:    The function f(x) is hardwired.
 *
 * IPP2:    Section 3.2.1 (pp. 101 and ff.) and 5.2 (p. 228)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


double f(double x);    /* Function we're integrating */

//turn into thread function **
void *Trap(void* rank);

//global_sum of trap
double  global_integral = 0.0;   /* Store result in integral   */

//global variables for trap [moved to be global] **
double  a, b;       /* Left and right endpoints   */
int     n;          /* Number of trapezoids       */
double  h;          /* Height of trapezoids       */

// global thread_count
int thread_count;

//mutex
pthread_mutex_t mutex;

int main(int argc, char* argv[]) {

   long thread;  
   pthread_t* thread_handles;
   pthread_mutex_init(&mutex, NULL);

   // Get the number of threads from command line **
   thread_count = strtol(argv[1], NULL, 10);

   //allocate space for each pthread object for each thread **
   thread_handles = malloc(thread_count*sizeof(pthread_t));

   printf("Enter a, b, and n\n");
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%d", &n);

   h = (b-a)/n;
   
   //integral = Trap(a, b, n, h); replaced **
   for(thread = 0; thread<thread_count; thread++){
      pthread_create(&thread_handles[thread], NULL, Trap, (void*) thread );
   }

   //free the pthread objects **
   for(thread=0; thread<thread_count;thread++){
      pthread_join(thread_handles[thread], NULL);
   }

   //switched integral to be global_integral **
   printf("With n = %d trapezoids, our estimate\n", n);
   printf("of the integral from %f to %f = %.15f\n",
      a, b, global_integral);

   pthread_mutex_destroy(&mutex);
   
   // free the space allocated for the threads on the heap
   free(thread_handles);
   

   return 0;
}  /* main */

/*------------------------------------------------------------------
 * Function:    Trap
 * Purpose:     Estimate integral from a to b of f using trap rule and
 *              n trapezoids
 * Input args:  a, b, n, h
 * Return val:  Estimate of the integral 
 */
void *Trap(void* rank) {
   
   //local variables
   double local_integral_result;
   double local_a, local_b;
   int local_n;
   
   //what is the rank of the thread
   long my_rank = (long) rank;
   
   int i;
   double x;

   //find local variables we need to compute the area for assigned interval on thread
   local_n = n/thread_count;
   local_a = a + my_rank*local_n*h;
   local_b = local_a+local_n*h;

   //handle the result of the first and last iteration first 
   local_integral_result = (f(local_a) + f(local_b))/2.0;

   //get the rest of the iterations
   for (i = 1; i <= local_n-1; i++) {
     x = local_a + i*h;
     local_integral_result += f(x);
   }

   local_integral_result = local_integral_result*h;

   pthread_mutex_lock(&mutex);
   global_integral += local_integral_result;
   printf("hello thread %ld ran\n", my_rank);
   pthread_mutex_unlock(&mutex);


   return NULL;
}  /* Trap */

/*------------------------------------------------------------------
 * Function:    f
 * Purpose:     Compute value of function to be integrated
 * Input args:  x
 */
double f(double x) {
   double return_val;

   return_val = x*x;
   return return_val;
}  /* f */
