# CPU Scheduler Simulator
This project aims to demonstrate how a CPU scheduler operates using several scheduling algorithms

## Overview
This project implements two CPU schedulign algorithms
1.  First Come, First Serve (FCFS)
2.  Shortest Job First (SJF)

The program reads task details from an input file, schedules them using the chosen algoritm, and outputs performance metrics including:
- Turnaround time
- Waiting time
- Repsonse time
- Response ratio
- Throughput

## Compilation
Use the `Makefile` to build the project.
To compile the FCFS scheduler:
`make fcfs`
To compile the SJF scheduler:
`make sjf`
Clead the compiled files:
`make clean`

## Usage
1. Run the FCFS Scheduler:
`./fcfs input.txt`
2. Run the SJF Scheduler:
`./sjf input.txt`

## Input Format
The input file should have the following format
```
TaskName,ArrivalTime,BurstTime
T1,0,10
T2,3,5
T3,5,8
```
## Output
The program prints the scheduling order and performance metrics, including: 
- Process execution order
- Turnaround time
- Waiting time
- Response time
- Response ratio
- Average metrics and throughput

## Example
Input (schedule_arrive_diff.txt):
```
T1,0,5
T2,1,3
T3,2,8
```
Running FCFS:
`./fcfs input/schedule_arrive_diff.txt`
Output:
```
[T8]	 [200]	 [25]	 [7]
[T7]	 [100]	 [30]	 [6]
[T6]	 [12]	 [10]	 [5]
[T5]	 [5]	 [20]	 [4]
[T4]	 [5]	 [15]	 [3]
[T3]	 [3]	 [25]	 [2]
[T2]	 [3]	 [25]	 [1]
[T1]	 [2]	 [20]	 [0]
Running task = [T1] [2] [20] for 20 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T3] [3] [25] for 25 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T6] [12] [10] for 10 units.
Running task = [T7] [100] [30] for 30 units.
Running task = [T8] [200] [25] for 25 units.
Times:
Process | Arrival Time | Burst Time | Turnaround Time | Waiting Time | Response Time | Response Ratio
      T1|             2|          20|               20|             0|              0|           1.00
      T2|             3|          25|               44|            19|             19|           1.76
      T3|             3|          25|               69|            44|             44|           2.76
      T4|             5|          15|               82|            67|             67|           5.47
      T5|             5|          20|              102|            82|             82|           5.10
      T6|            12|          10|              105|            95|             95|          10.50
      T7|           100|          30|               47|            17|             17|           1.57
      T8|           200|          25|               25|             0|              0|           1.00

Averages:
Turnaround Time | Waiting Time | Response Time | Response Ratio | Throughput
           61.75|         40.50|          40.50|           3.64 |     21.25
```
