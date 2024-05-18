# Example of Serial vs Parallel solutions: compute n values and add them together

Created: 2024-02-07 18:46:56 -0500

Modified: 2024-02-07 18:48:02 -0500

---

Example of Serial vs Parallel solutions: compute n values and add them together

-   Serial:

> ![](media/Example-of-Serial-vs-Parallel-so-image1.png){width="4.302083333333333in" height="1.5in"}

-   Parallel:

> ![](media/Example-of-Serial-vs-Parallel-so-image2.png){width="5.78125in" height="2.0729166666666665in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image3.png){width="3.3541666666666665in" height="1.53125in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image4.png){width="3.34375in" height="0.5416666666666666in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image5.png){width="3.3645833333333335in" height="1.75in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image6.png){width="3.375in" height="1.6666666666666667in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image7.png){width="3.3854166666666665in" height="1.40625in"}
>
> ![](media/Example-of-Serial-vs-Parallel-so-image8.png){width="3.3854166666666665in" height="1.40625in"}
>
>  
>
> ![](media/Example-of-Serial-vs-Parallel-so-image9.png){width="3.4166666666666665in" height="1.65625in"}

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

![](media/Example-of-Serial-vs-Parallel-so-image10.png){width="0.17708333333333334in" height="0.23958333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image11.png){width="0.19791666666666666in" height="0.22916666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image12.png){width="0.2708333333333333in" height="0.22916666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image13.png){width="0.13541666666666666in" height="0.21875in"}![](media/Example-of-Serial-vs-Parallel-so-image14.png){width="0.125in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image15.png){width="0.15625in" height="0.1875in"}![](media/Example-of-Serial-vs-Parallel-so-image16.png){width="0.15625in" height="0.1875in"}![](media/Example-of-Serial-vs-Parallel-so-image17.png){width="0.16666666666666666in" height="0.16666666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image18.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image19.png){width="0.1875in" height="0.16666666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image20.png){width="0.22916666666666666in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image21.png){width="0.19791666666666666in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image22.png){width="0.10416666666666667in" height="0.17708333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image23.png){width="0.16666666666666666in" height="0.17708333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image24.png){width="0.14583333333333334in" height="0.16666666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image25.png){width="5.447916666666667in" height="1.8020833333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image26.png){width="0.20833333333333334in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image27.png){width="0.3020833333333333in" height="0.13541666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image28.png){width="0.11458333333333333in" height="0.13541666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image29.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image30.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image31.png){width="0.1875in" height="0.23958333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image32.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image33.png){width="0.125in" height="0.17708333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image34.png){width="0.21875in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image35.png){width="0.10416666666666667in" height="0.14583333333333334in"}

 

![](media/Example-of-Serial-vs-Parallel-so-image36.png){width="0.17708333333333334in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image37.png){width="0.11458333333333333in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image38.png){width="0.19791666666666666in" height="0.1875in"}![](media/Example-of-Serial-vs-Parallel-so-image39.png){width="0.11458333333333333in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image40.png){width="0.16666666666666666in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image41.png){width="0.11458333333333333in" height="0.16666666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image42.png){width="0.16666666666666666in" height="0.13541666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image43.png){width="0.11458333333333333in" height="0.14583333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image44.png){width="0.1875in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image45.png){width="0.13541666666666666in" height="0.14583333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image46.png){width="0.4270833333333333in" height="0.3125in"}![](media/Example-of-Serial-vs-Parallel-so-image47.png){width="0.2708333333333333in" height="0.34375in"}![](media/Example-of-Serial-vs-Parallel-so-image48.png){width="0.3854166666666667in" height="0.46875in"}![](media/Example-of-Serial-vs-Parallel-so-image49.png){width="0.10416666666666667in" height="0.21875in"}![](media/Example-of-Serial-vs-Parallel-so-image50.png){width="0.11458333333333333in" height="0.15625in"}![](media/Example-of-Serial-vs-Parallel-so-image51.png){width="0.125in" height="0.25in"}![](media/Example-of-Serial-vs-Parallel-so-image52.png){width="0.13541666666666666in" height="0.23958333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image53.png){width="0.25in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image54.png){width="0.25in" height="0.125in"}![](media/Example-of-Serial-vs-Parallel-so-image55.png){width="0.22916666666666666in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image56.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image57.png){width="0.11458333333333333in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image58.png){width="0.15625in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image59.png){width="0.17708333333333334in" height="0.20833333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image60.png){width="0.125in" height="0.125in"}![](media/Example-of-Serial-vs-Parallel-so-image61.png){width="0.125in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image62.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image63.png){width="0.13541666666666666in" height="0.125in"}![](media/Example-of-Serial-vs-Parallel-so-image64.png){width="0.10416666666666667in" height="0.13541666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image65.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image66.png){width="0.125in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image67.png){width="0.14583333333333334in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image68.png){width="0.13541666666666666in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image69.png){width="0.10416666666666667in" height="0.14583333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image70.png){width="0.14583333333333334in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image71.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image72.png){width="0.125in" height="0.17708333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image73.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image74.png){width="0.13541666666666666in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image75.png){width="0.10416666666666667in" height="0.125in"}![](media/Example-of-Serial-vs-Parallel-so-image76.png){width="0.16666666666666666in" height="0.10416666666666667in"}

 

Notes:

-   The master core will handle adding up all of the sums found from the cores

-   ![](media/Example-of-Serial-vs-Parallel-so-image77.png){width="3.7395833333333335in" height="2.3645833333333335in"}

![](media/Example-of-Serial-vs-Parallel-so-image78.png){width="0.6458333333333334in" height="0.5208333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image79.png){width="0.13541666666666666in" height="0.4270833333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image80.png){width="0.23958333333333334in" height="0.4479166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image81.png){width="0.11458333333333333in" height="0.46875in"}![](media/Example-of-Serial-vs-Parallel-so-image82.png){width="0.10416666666666667in" height="0.11458333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image83.png){width="0.19791666666666666in" height="0.3333333333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image84.png){width="0.4375in" height="0.3229166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image85.png){width="0.10416666666666667in" height="0.10416666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image86.png){width="0.13541666666666666in" height="0.28125in"}![](media/Example-of-Serial-vs-Parallel-so-image87.png){width="0.3125in" height="0.28125in"}![](media/Example-of-Serial-vs-Parallel-so-image88.png){width="0.2604166666666667in" height="0.23958333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image89.png){width="0.22916666666666666in" height="0.2604166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image90.png){width="0.11458333333333333in" height="0.19791666666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image91.png){width="0.3020833333333333in" height="0.125in"}![](media/Example-of-Serial-vs-Parallel-so-image92.png){width="0.23958333333333334in" height="0.11458333333333333in"}

 

![](media/Example-of-Serial-vs-Parallel-so-image93.png){width="0.3125in" height="0.4166666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image94.png){width="0.3125in" height="0.4479166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image95.png){width="0.13541666666666666in" height="0.40625in"}![](media/Example-of-Serial-vs-Parallel-so-image96.png){width="0.3229166666666667in" height="0.4270833333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image97.png){width="0.3541666666666667in" height="0.3541666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image98.png){width="0.625in" height="0.3020833333333333in"}![](media/Example-of-Serial-vs-Parallel-so-image99.png){width="0.21875in" height="0.3229166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image100.png){width="0.5104166666666666in" height="0.2916666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image101.png){width="0.23958333333333334in" height="0.28125in"}![](media/Example-of-Serial-vs-Parallel-so-image102.png){width="0.2604166666666667in" height="0.3125in"}![](media/Example-of-Serial-vs-Parallel-so-image103.png){width="0.3333333333333333in" height="0.28125in"}![](media/Example-of-Serial-vs-Parallel-so-image104.png){width="0.53125in" height="0.3125in"}![](media/Example-of-Serial-vs-Parallel-so-image105.png){width="0.28125in" height="0.21875in"}

Notes:

![](media/Example-of-Serial-vs-Parallel-so-image106.png){width="3.7395833333333335in" height="2.25in"}

 

![](media/Example-of-Serial-vs-Parallel-so-image107.png){width="0.90625in" height="0.3541666666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image108.png){width="0.78125in" height="0.23958333333333334in"}![](media/Example-of-Serial-vs-Parallel-so-image109.png){width="0.9583333333333334in" height="0.9375in"}![](media/Example-of-Serial-vs-Parallel-so-image110.png){width="0.6770833333333334in" height="1.1354166666666667in"}![](media/Example-of-Serial-vs-Parallel-so-image111.png){width="0.9479166666666666in" height="0.5104166666666666in"}![](media/Example-of-Serial-vs-Parallel-so-image112.png){width="0.20833333333333334in" height="0.34375in"}

Notes:

![](media/Example-of-Serial-vs-Parallel-so-image113.png){width="3.28125in" height="1.4791666666666667in"}

 

![](media/Example-of-Serial-vs-Parallel-so-image114.png){width="0.10416666666666667in" height="0.10416666666666667in"}


















































































































