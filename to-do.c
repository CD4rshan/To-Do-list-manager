#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256

typedef struct {
    char task[MAX_TASK_LENGTH];
    int completed;
} TodoItem;

TodoItem tasks[MAX_TASKS];
int taskCount = 0;

void addTask(const char* task) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].task, task);
        tasks[taskCount].completed = 0;
        taskCount++;
        printf("Task added: %s\n", task);
    } else {
        printf("Task list is full!\n");
    }
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].task);
    }
}

void markCompleted(int index) {
    if (index >= 0 && index < taskCount) {
        tasks[index].completed = 1;
        printf("Task marked as completed: %s\n", tasks[index].task);
    } else {
        printf("Invalid task index.\n");
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < taskCount) {
        printf("Task deleted: %s\n", tasks[index].task);
        for (int i = index; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
    } else {
        printf("Invalid task index.\n");
    }
}

int main() {
    int choice;
    char task[MAX_TASK_LENGTH];
    int index;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter task: ");
                fgets(task, MAX_TASK_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove newline
                addTask(task);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &index);
                markCompleted(index - 1);
                break;
            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &index);
                deleteTask(index - 1);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


