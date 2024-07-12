#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int P;
    int Mn;
    int index; 
    int *M; 
} Process;

typedef struct List {
    Process *process; 
    struct List *next; 
} List;

void addProcess(List **head, Process *process) {
    List *newNode = (List *)malloc(sizeof(List));
    newNode->process = process;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        List *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Process *processes = (Process *)malloc(N * sizeof(Process));

    List *head = NULL;

    for (int i = 0; i < N; i++) {
        scanf ("%d", &processes[i].Mn);
        processes[i].P = i+1;
        processes[i].index = 0;
        processes[i].M = (int *)malloc(processes[i].Mn * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < processes[i].Mn; j++) {
            scanf("%d", &processes[i].M[j]);
        }
        addProcess(&head, &processes[i]);
    }

    List *current = head;
    int totalTemp = 0;
    int canPrint;
    while (current != NULL) {
        canPrint = 0;
        for (int i = current->process->index; i < current->process->Mn; i++) {
            if (current->process->M[i] == 0) {
                totalTemp += 10;
            }
            else {
                current->process->M[i]--;
                addProcess(&head, current->process);
                canPrint = 1;
                current->process->index = i;
                break;
            }
        }
        if (canPrint == 0) {
            printf ("%d (%d)\n", current->process->P, totalTemp);
        }
        current = current->next;
    }


    return 0;
}
