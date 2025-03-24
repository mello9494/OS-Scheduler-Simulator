/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>
#include <unistd.h>

#include "../include/task.h"

// run this task for the specified time howLong
void run(Task *task, int howLong) {
    // sleep(howLong);
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->arrivalTime, task->burst, howLong);
}
