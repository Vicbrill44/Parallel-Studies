# INTRO

Created: 2024-03-10 23:10:24 -0400

Modified: 2024-03-12 23:37:27 -0400

---

-   [Distributed memory]{.underline} is when core(s) each have their own memory which is private to only itself but can be shared through a network

    -   [Shared memory]{.underline} is when core(s) are connected to one global memory where every core can access any memory location

-   We are going to look at how to program distributed memory systems using [message passing]{.underline}

    -   In message passing programs one core memory pair is called a [process]{.underline}, and two processes can communicate by the functions: [send]{.underline} and [receive]{.underline}.

    -   We will use MPI (message passing interface) for our implementation of message passing

        -   MPI is not a program but a library used in C

        -   It has different send and receive functions

        -   Has [collective]{.underline} functions, which involves more than two processes

-   We will also look at some fundemental issues in message passing programs

    -   Such as data partitioning, IO in distributed memory systems.

 

 

 

 
