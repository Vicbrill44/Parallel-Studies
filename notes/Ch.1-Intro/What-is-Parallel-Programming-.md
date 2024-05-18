# What is Parallel Programming about?

Created: 2024-02-07 16:32:36 -0500

Modified: 2024-02-07 18:45:16 -0500

---

• The simple notion that 2 heads are better than one.

• In computing terms, 2 CPUs are better

than one

• That's really the basic idea

-   Find out how to share the work

-   Offload parts of the work to different CPUs/GPUs. Nothing more complex than that.

 

An intelligent solution

• Instead of designing and building faster microprocessors, put multiple processors on a single integrated circuit.

-   Microprocessor: is a type of CPU, that is compact and the integrated version designed to perform the functions of a CPU on a SINGLE chip or silicon (IC).

    -   Modern day CPU's that we know of

-   IC: single integrated circuit

 

What is serial programming? (diff from parallel prog.)

-   Serial programs: execute instructions sequentially, one after the other. This means that at any given moment, the program is executing a single operation before moving on to the next.

    -   Serial programs don't benefit from parallel programming (for the most part)

 

Things that parallel programming can help in:

-   Climate modeling, protein folding, drug discovery, energy research, data analysis, etc..

    -   These are all things that require ever-increasing performance which can be done possible by techniques such as parallel programing.

 

Parallelism:

-   Move away from single core systems to multicore processors

    -   Core = central processing unit (CPU)

 

Approaches to the serial problem:

-   Rewrite serial programs so that they are parallel

-   Write translation programs that automatically convert serial programs into parallel programs.

    -   Very difficult to do

    -   Success has been little

>  

Example of Serial vs Parallel solutions: compute n values and add them together

-   Serial:

> ![](media/What-is-Parallel-Programming-abo-image1.png){width="4.302083333333333in" height="1.5in"}

-   Parallel:

> ![](media/What-is-Parallel-Programming-abo-image2.png){width="5.78125in" height="2.0729166666666665in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image3.png){width="3.3541666666666665in" height="1.53125in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image4.png){width="3.34375in" height="0.5416666666666666in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image5.png){width="3.3645833333333335in" height="1.75in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image6.png){width="3.375in" height="1.6666666666666667in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image7.png){width="3.3854166666666665in" height="1.40625in"}
>
> ![](media/What-is-Parallel-Programming-abo-image8.png){width="3.3854166666666665in" height="1.40625in"}
>
>  
>
> ![](media/What-is-Parallel-Programming-abo-image9.png){width="3.4166666666666665in" height="1.65625in"}

Notes:

-   This will simply add to the sum after computing the value in steps starting from i all the way to n

    -   STEPS

 

 

Notes:

-   We have p cores

    -   P is much smaller than n

        -   Because of this, each core performs a partial sum of approximately n/p values

            -   Partial sum meaning:

 

 

 

-   Each summation represents a core

<!-- -->

-   Explaining the example:

    -   Each core starts with a sum of 0 and it handles a certain range from my_first_i to my_last_i and it computes the sum of that range

        -   All the cores together will handle up to n

>  

![](media/What-is-Parallel-Programming-abo-image10.png){width="0.17708333333333334in" height="0.23958333333333334in"}![](media/What-is-Parallel-Programming-abo-image11.png){width="0.19791666666666666in" height="0.22916666666666666in"}![](media/What-is-Parallel-Programming-abo-image12.png){width="0.2708333333333333in" height="0.22916666666666666in"}![](media/What-is-Parallel-Programming-abo-image13.png){width="0.13541666666666666in" height="0.21875in"}![](media/What-is-Parallel-Programming-abo-image14.png){width="0.125in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image15.png){width="0.15625in" height="0.1875in"}![](media/What-is-Parallel-Programming-abo-image16.png){width="0.15625in" height="0.1875in"}![](media/What-is-Parallel-Programming-abo-image17.png){width="0.16666666666666666in" height="0.16666666666666666in"}![](media/What-is-Parallel-Programming-abo-image18.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image19.png){width="0.1875in" height="0.16666666666666666in"}![](media/What-is-Parallel-Programming-abo-image20.png){width="0.22916666666666666in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image21.png){width="0.19791666666666666in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image22.png){width="0.10416666666666667in" height="0.17708333333333334in"}![](media/What-is-Parallel-Programming-abo-image23.png){width="0.16666666666666666in" height="0.17708333333333334in"}![](media/What-is-Parallel-Programming-abo-image24.png){width="0.14583333333333334in" height="0.16666666666666666in"}![](media/What-is-Parallel-Programming-abo-image25.png){width="5.447916666666667in" height="1.8020833333333333in"}![](media/What-is-Parallel-Programming-abo-image26.png){width="0.20833333333333334in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image27.png){width="0.3020833333333333in" height="0.13541666666666666in"}![](media/What-is-Parallel-Programming-abo-image28.png){width="0.11458333333333333in" height="0.13541666666666666in"}![](media/What-is-Parallel-Programming-abo-image29.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image30.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image31.png){width="0.1875in" height="0.23958333333333334in"}![](media/What-is-Parallel-Programming-abo-image32.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image33.png){width="0.125in" height="0.17708333333333334in"}![](media/What-is-Parallel-Programming-abo-image34.png){width="0.21875in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image35.png){width="0.10416666666666667in" height="0.14583333333333334in"}

 

![](media/What-is-Parallel-Programming-abo-image36.png){width="0.17708333333333334in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image37.png){width="0.11458333333333333in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image38.png){width="0.19791666666666666in" height="0.1875in"}![](media/What-is-Parallel-Programming-abo-image39.png){width="0.11458333333333333in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image40.png){width="0.16666666666666666in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image41.png){width="0.11458333333333333in" height="0.16666666666666666in"}![](media/What-is-Parallel-Programming-abo-image42.png){width="0.16666666666666666in" height="0.13541666666666666in"}![](media/What-is-Parallel-Programming-abo-image43.png){width="0.11458333333333333in" height="0.14583333333333334in"}![](media/What-is-Parallel-Programming-abo-image44.png){width="0.1875in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image45.png){width="0.13541666666666666in" height="0.14583333333333334in"}![](media/What-is-Parallel-Programming-abo-image46.png){width="0.4270833333333333in" height="0.3125in"}![](media/What-is-Parallel-Programming-abo-image47.png){width="0.2708333333333333in" height="0.34375in"}![](media/What-is-Parallel-Programming-abo-image48.png){width="0.3854166666666667in" height="0.46875in"}![](media/What-is-Parallel-Programming-abo-image49.png){width="0.10416666666666667in" height="0.21875in"}![](media/What-is-Parallel-Programming-abo-image50.png){width="0.11458333333333333in" height="0.15625in"}![](media/What-is-Parallel-Programming-abo-image51.png){width="0.125in" height="0.25in"}![](media/What-is-Parallel-Programming-abo-image52.png){width="0.13541666666666666in" height="0.23958333333333334in"}![](media/What-is-Parallel-Programming-abo-image53.png){width="0.25in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image54.png){width="0.25in" height="0.125in"}![](media/What-is-Parallel-Programming-abo-image55.png){width="0.22916666666666666in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image56.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image57.png){width="0.11458333333333333in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image58.png){width="0.15625in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image59.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/What-is-Parallel-Programming-abo-image60.png){width="0.125in" height="0.125in"}![](media/What-is-Parallel-Programming-abo-image61.png){width="0.125in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image62.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image63.png){width="0.13541666666666666in" height="0.125in"}![](media/What-is-Parallel-Programming-abo-image64.png){width="0.10416666666666667in" height="0.13541666666666666in"}![](media/What-is-Parallel-Programming-abo-image65.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image66.png){width="0.125in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image67.png){width="0.14583333333333334in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image68.png){width="0.13541666666666666in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image69.png){width="0.10416666666666667in" height="0.14583333333333334in"}![](media/What-is-Parallel-Programming-abo-image70.png){width="0.14583333333333334in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image71.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image72.png){width="0.125in" height="0.17708333333333334in"}![](media/What-is-Parallel-Programming-abo-image73.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image74.png){width="0.13541666666666666in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image75.png){width="0.10416666666666667in" height="0.125in"}![](media/What-is-Parallel-Programming-abo-image76.png){width="0.16666666666666666in" height="0.10416666666666667in"}

 

Notes:

-   The master core will handle adding up all of the sums found from the cores

-   ![](media/What-is-Parallel-Programming-abo-image77.png){width="3.7395833333333335in" height="2.3645833333333335in"}

![](media/What-is-Parallel-Programming-abo-image78.png){width="0.6458333333333334in" height="0.5208333333333334in"}![](media/What-is-Parallel-Programming-abo-image79.png){width="0.13541666666666666in" height="0.4270833333333333in"}![](media/What-is-Parallel-Programming-abo-image80.png){width="0.23958333333333334in" height="0.4479166666666667in"}![](media/What-is-Parallel-Programming-abo-image81.png){width="0.11458333333333333in" height="0.46875in"}![](media/What-is-Parallel-Programming-abo-image82.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/What-is-Parallel-Programming-abo-image83.png){width="0.19791666666666666in" height="0.3333333333333333in"}![](media/What-is-Parallel-Programming-abo-image84.png){width="0.4375in" height="0.3229166666666667in"}![](media/What-is-Parallel-Programming-abo-image85.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/What-is-Parallel-Programming-abo-image86.png){width="0.13541666666666666in" height="0.28125in"}![](media/What-is-Parallel-Programming-abo-image87.png){width="0.3125in" height="0.28125in"}![](media/What-is-Parallel-Programming-abo-image88.png){width="0.2604166666666667in" height="0.23958333333333334in"}![](media/What-is-Parallel-Programming-abo-image89.png){width="0.22916666666666666in" height="0.2604166666666667in"}![](media/What-is-Parallel-Programming-abo-image90.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/What-is-Parallel-Programming-abo-image91.png){width="0.3020833333333333in" height="0.125in"}![](media/What-is-Parallel-Programming-abo-image92.png){width="0.23958333333333334in" height="0.11458333333333333in"}

 

![](media/What-is-Parallel-Programming-abo-image93.png){width="0.3125in" height="0.4166666666666667in"}![](media/What-is-Parallel-Programming-abo-image94.png){width="0.3125in" height="0.4479166666666667in"}![](media/What-is-Parallel-Programming-abo-image95.png){width="0.13541666666666666in" height="0.40625in"}![](media/What-is-Parallel-Programming-abo-image96.png){width="0.3229166666666667in" height="0.4270833333333333in"}![](media/What-is-Parallel-Programming-abo-image97.png){width="0.3541666666666667in" height="0.3541666666666667in"}![](media/What-is-Parallel-Programming-abo-image98.png){width="0.625in" height="0.3020833333333333in"}![](media/What-is-Parallel-Programming-abo-image99.png){width="0.21875in" height="0.3229166666666667in"}![](media/What-is-Parallel-Programming-abo-image100.png){width="0.5104166666666666in" height="0.2916666666666667in"}![](media/What-is-Parallel-Programming-abo-image101.png){width="0.23958333333333334in" height="0.28125in"}![](media/What-is-Parallel-Programming-abo-image102.png){width="0.2604166666666667in" height="0.3125in"}![](media/What-is-Parallel-Programming-abo-image103.png){width="0.3333333333333333in" height="0.28125in"}![](media/What-is-Parallel-Programming-abo-image104.png){width="0.53125in" height="0.3125in"}![](media/What-is-Parallel-Programming-abo-image105.png){width="0.28125in" height="0.21875in"}

Notes:

![](media/What-is-Parallel-Programming-abo-image106.png){width="3.7395833333333335in" height="2.25in"}

 

![](media/What-is-Parallel-Programming-abo-image107.png){width="0.90625in" height="0.3541666666666667in"}![](media/What-is-Parallel-Programming-abo-image108.png){width="0.78125in" height="0.23958333333333334in"}![](media/What-is-Parallel-Programming-abo-image109.png){width="0.9583333333333334in" height="0.9375in"}![](media/What-is-Parallel-Programming-abo-image110.png){width="0.6770833333333334in" height="1.1354166666666667in"}![](media/What-is-Parallel-Programming-abo-image111.png){width="0.9479166666666666in" height="0.5104166666666666in"}![](media/What-is-Parallel-Programming-abo-image112.png){width="0.20833333333333334in" height="0.34375in"}

Notes:

![](media/What-is-Parallel-Programming-abo-image113.png){width="3.28125in" height="1.4791666666666667in"}

 

![](media/What-is-Parallel-Programming-abo-image114.png){width="0.10416666666666667in" height="0.10416666666666667in"}


















































































































