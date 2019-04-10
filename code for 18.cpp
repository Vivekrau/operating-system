#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int n;
struct process
{
    int processNumber;
    int arrivalTime, burstTime, ct, waitTime, turnAroundTime, p;
    int flagValue;    
} processList[100];

void sortByValue()
{
    struct process p;

    int i, j;

    for (i = 0; i < n - 1; i++)

    {
        for (j = i + 1; j < n; j++)

        {
            if (processList[i].arrivalTime > processList[j].arrivalTime)

            {
                p = processList[i];

                processList[i] = processList[j];

                processList[j] = p;
            }
        }
    }
}

void startProgram(){
	printf("\n\n\n\n\t\t\t\t**************** OPERATING SYSTEM PROJECT ******************");
	printf("\n\t\t\t\t**************** Name:- Vivek Roushan ******************");
	printf("\n\t\t\t\t**************** Roll no:- 61 ******************");
	printf("\n\t\t\t\t**************** Section:- K17CF ******************");
	printf("\n\t\t\t\t**************** Submitted To:- Shivali Chopra ******************\n");
	sleep(1);
	system("clear");
}
int main()
{
	startProgram();
    int i, t = 0, b_t = 0, peak;

    int a[10];

    float waitTimeime = 0, turnAroundTime = 0, averageWaitingTime = 0, averageTurnAroundTime = 0;

    printf("Enter the no. of processes: ");

    scanf("%d", &n);
    if(n<=0){
    	printf("\nERROR! OCCURED");
    	printf("\nNumber of process can't be negative and zero....");
    	exit(0);
	}

    for (i = 0; i < n; i++)

    {
        processList[i].processNumber = i + 1;

        printf("\nEnter Details For P%d process:-\n", processList[i].processNumber);
        printf("Enter Arrival Time: ");
		scanf("%d", &processList[i].arrivalTime);
		if(processList[i].arrivalTime < 0){
			printf("\nERROR! OCCURED");
    		printf("\nArrival Time of process can't be negative....");
    		exit(0);
		}
        printf("Enter Burst Time: ");
        scanf("%d", &processList[i].burstTime);
        if(processList[i].burstTime<=0){
        	printf("\nERROR! OCCURED");
    		printf("\nBurst Time of process can't be negative and zero....");
    		exit(0);
		}
        processList[i].flagValue = 0;
        b_t = b_t + processList[i].burstTime;
    }
    sortByValue();
    for (int i = 0; i < n; i++)
    {
        a[i] = processList[i].burstTime;
    }
    processList[9].burstTime = 9999;
    for (t = processList[0].arrivalTime; t <= b_t + 1;)
    {
        peak = 9;
        for (i = 0; i < n; i++)
        {
            if (processList[i].arrivalTime <= t && processList[i].burstTime < processList[peak].burstTime
                && processList[i].flagValue != 1)
            {
                peak = i;
            }
            if (processList[peak].burstTime == 0 && processList[i].flagValue != 1)
            {
                processList[i].flagValue = 1;
                processList[peak].ct = t;
                processList[peak].burstTime = 9999;
                printf("\nProcess %d completes in %d\n", processList[i].processNumber, processList[peak].ct);
            }
        }
        t++;
        (processList[peak].burstTime)--;
    }
    for (i = 0; i < n; i++)
    {
        processList[i].turnAroundTime = (processList[i].ct) - (processList[i].arrivalTime);
        averageTurnAroundTime = averageTurnAroundTime + processList[i].turnAroundTime;
        processList[i].waitTime = ((processList[i].turnAroundTime) - a[i]);
        averageWaitingTime = averageWaitingTime + processList[i].waitTime;
    }
    
    printf("\n-----------------------------------------------------------------------------------------\n");
        
    printf("\n| Process Number |\t|Arrival Time |\t\t| Current Time |\t| Turn Around Time |\t| Waiting Time |\n");
    for (i = 0; i < n; i++)
    {
        printf("\n   Process %d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processList[i].processNumber, processList[i].arrivalTime, processList[i].ct,
            processList[i].turnAroundTime, processList[i].waitTime);
    }
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("\nAverage Turn around Time: %.2f\t\n\n", averageTurnAroundTime);
    printf("Average Waiting Time :\t %.2f\t\n", averageWaitingTime);
    printf("\n-----------------------------------------------------------------------------------------\n");
}
