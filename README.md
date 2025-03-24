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
`./fcfs schedule_arrive_diff.txt`
Output:
```
[T2]     [3]     [25]    [7]
[T7]     [100]   [30]    [6]
[T6]     [12]    [10]    [5]
[T8]     [200]   [25]    [4]
[T5]     [5]     [20]    [3]
[T4]     [5]     [15]    [2]
[T3]     [3]     [25]    [1]
[T1]     [2]     [20]    [0]
Running task = [T6] [12] [10] for 10 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T1] [2] [20] for 20 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T3] [3] [25] for 25 units.
Running task = [T8] [200] [25] for 25 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T7] [100] [30] for 30 units.
Times:
Process | Arrival Time | Burst Time | Turnaround Time | Waiting Time | Response Time | Response Ratio
     T6 |           12 |         10 |              10 |            0 |             0 |           1.00
     T4 |            5 |         15 |              32 |           17 |            17 |           2.13
     T1 |            2 |         20 |              55 |           35 |            35 |           2.75
     T5 |            5 |         20 |              72 |           52 |            52 |           3.60
     T3 |            3 |         25 |              99 |           74 |            74 |           3.96
     T8 |          200 |         25 |              25 |            0 |             0 |           1.00
     T2 |            3 |         25 |             247 |          222 |           222 |           9.88
     T7 |          100 |         30 |             180 |          150 |           150 |           6.00

Averages:
Turnaround Time | Waiting Time | Response Time | Response Ratio | Throughput
           90.00|         68.75|          68.75|           3.79 |     21.25
```
