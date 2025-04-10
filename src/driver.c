/**
 * Driver.c
 *
 * From input file: Schedule is in the format
 *
 *  [name] [arrivalTime] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/task.h"
#include "../include/list.h"
#include "../include/schedulers.h"

#define SIZE 100

int main(int argc, char *argv[]) //understand these argument usage and purpose
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int arrivalTime;
    int burst;

    in = fopen(argv[1],"r");

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task); //understand this built-in function
        name = strsep(&temp,","); //understand this built-in function
        arrivalTime = atoi(strsep(&temp,",")); //understand this built-in function
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,arrivalTime,burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    return 0;
}
