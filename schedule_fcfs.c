/**
 * Implementation of various scheduling algorithms.
 *
 * FCFS scheduling
 */

#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

// reference to the head of the list
struct node *head = NULL;

// sequence counter of next available thread identifier
int nextTid = 0;
int indexArr = 0;
int arrivalTime[8];
int burstTime[8];
char *names[8];
int numOfProcess=0;

Task *selectNextTask(int*);
void times(char *name[], int arrivalTime[], int burst[]);

// add a new task to the list of tasks
void add(char *name, int arrivalTime, int burst) {
    // first create the new task
    Task *newTask = (Task *) malloc(sizeof(Task));

    newTask->name = name;
    newTask->tid = nextTid++; // modify this for each task and run tasks in order afterwards
    newTask->arrivalTime = arrivalTime;
    newTask->burst = burst;

    // insert the new task into the list of tasks
    // printf("%s\n", newTask->name);
    insert(&head, newTask);
    numOfProcess++;

}

/**
 * Run the FCFS scheduler
 */
void schedule()
{
    Task *current;

    // sanity checker
    traverse(head);
    // Task stack;
    while (head != NULL) {

        current = selectNextTask(&indexArr);

        run(current, current->burst); // prints out "Running task = [T8] [0] [25] for 25 units."

        delete(&head, current);
    }
    times(names, arrivalTime, burstTime);

}

/**
 * Returns the next task selected to run.
 */
Task *selectNextTask(int* indexArr)
{
    // modify the tid's and return the smallest one
    struct node *temp = head;
    struct node *returnNode = head;

    // find the smallest time
    // given the way the list is created, this will be guaranteed to find the smallest time in order of arrival
    temp = head;
    while(temp != NULL){
        if(temp->task->arrivalTime <= returnNode->task->arrivalTime){
            returnNode = temp;
        }
        temp = temp->next;
    }
    arrivalTime[*indexArr] = returnNode->task->arrivalTime;
    burstTime[*indexArr] = returnNode->task->burst;
    names[*indexArr] = returnNode->task->name;
    *indexArr += 1;

    return returnNode->task;
}

void times(char *name[], int arrivalTime[], int burst[]){
    int turnaroundTime, waitingTime = 0; 
    int responseTime=0;
    int currTime = arrivalTime[0];
    float responseRatio, totTT, totRR = 0.0;
    float totWT, totBurst = 0.0;
    float totRT=0.0;

    printf("Times:\nProcess | Arrival Time | Burst Time | Turnaround Time | Waiting Time | Response Time | Response Ratio\n");
    
    // works for zero arrive time but not diff. needs fix
    for(int i = 0; i < numOfProcess; i++){
    	if(arrivalTime[i] > currTime){
    		currTime = arrivalTime[i] + burst[i];
    	}
       	else{
       		currTime = currTime + burst[i];
       	};
    
        turnaroundTime = currTime - arrivalTime[i];
        totTT += turnaroundTime;
        
        waitingTime = turnaroundTime - burstTime[i];
        totWT += waitingTime;
        
        responseTime = currTime - burstTime[i] - arrivalTime[i];
        totRT += responseTime; 
        
        responseRatio = (float)(waitingTime + burst[i]) / (float)burst[i];
        totRR += responseRatio;
        
        totBurst+=burst[i];
      	
        
        printf("%8s|%14d|%12d|%17d|%14d|%15d|%15.2f\n", name[i], arrivalTime[i],burst[i], turnaroundTime, waitingTime, responseTime, responseRatio);
    }
    
    float avgTT = totTT/numOfProcess;
    float avgWT = totWT/numOfProcess;
    float avgRT = totRT/numOfProcess;
    float avgRR = totRR/numOfProcess;
    float throughput= totBurst/numOfProcess;
    
    printf("\nAverages:\nTurnaround Time | Waiting Time | Response Time | Response Ratio | Throughput\n");
    printf("%16.2f|%14.2f|%15.2f|%15.2f |%10.2f\n", avgTT, avgWT, avgRT, avgRR,throughput);
}
