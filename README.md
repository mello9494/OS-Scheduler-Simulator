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
Task Execution Order: T1 -> T2 -> T3
Turnaround Time: 5, 7, 15
Waiting Time: 0, 4, 7
Response Time: 0, 4, 7
Throughput: 0.2
```
