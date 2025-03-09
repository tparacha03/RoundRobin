#include <stdio.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM 4  // Time slice for each process

typedef struct {
    int pid;
    int burst_time;
} Process;

void round_robin_scheduling(Process processes[], int n, int time_quantum) {
    int remaining_burst[n];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }

    int completed = 0, time = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                int execution_time = (remaining_burst[i] > time_quantum) ? time_quantum : remaining_burst[i];

                printf("Executing Process %d for %dms (Time: %dms - %dms)\n",
                       processes[i].pid, execution_time, time, time + execution_time);

                time += execution_time;
                remaining_burst[i] -= execution_time;

                if (remaining_burst[i] == 0) {
                    completed++;
                    printf("Process %d completed!\n", processes[i].pid);
                }
            }
        }
    }

    printf("All processes executed.\n");
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 10},
        {2, 15},
        {3, 8},
        {4, 12},
        {5, 5}
    };

    printf("Starting Round Robin Scheduling (Time Quantum = %dms)...\n\n", TIME_QUANTUM);
    round_robin_scheduling(processes, MAX_PROCESSES, TIME_QUANTUM);

    return 0;
}
