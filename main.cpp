#include <iostream>
#include <string.h>
#include <stdio.h>

#define MAX_TASKS 100

struct Task {
    int id;
    char description[100];
    int isCompleted;
};

// Add Task Function
void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    tasks[*taskCount].id = *taskCount + 1;

    printf("Enter task description: ");
    getchar();  // Clear the newline left by scanf in main
    fgets(tasks[*taskCount].description, sizeof(tasks[*taskCount].description), stdin);

    // Remove the newline character if it exists
    tasks[*taskCount].description[strcspn(tasks[*taskCount].description, "\n")] = 0;

    tasks[*taskCount].isCompleted = 0;
    (*taskCount)++;

    printf("Task added successfully!\n");
}

// View Tasks Function
void viewTasks(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }
    for (int i = 0; i < *taskCount; i++) {
        printf("ID: %d | Description: %s | Status: %s\n",
               tasks[i].id, tasks[i].description,
               tasks[i].isCompleted ? "Completed" : "Incomplete");
    }
}

// Mark Task as Completed Function
void markTaskCompleted(Task tasks[], int *taskCount) {
    int id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);
    for (int i = 0; i < *taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].isCompleted = 1;
            printf("Task marked as completed.\n");
            return;
        }
    }
    printf("Task ID not found.\n");
}

// Delete Task Function
void deleteTask(Task tasks[], int *taskCount) {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *taskCount; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < *taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*taskCount)--;
            printf("Task deleted.\n");
            return;
        }
    }
    printf("Task ID not found.\n");
}

// Save Tasks to File Function
void saveTasksToFile(Task tasks[], int *taskCount) {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    for (int i = 0; i < *taskCount; i++) {
        fprintf(file, "%d,%s,%d\n", tasks[i].id, tasks[i].description, tasks[i].isCompleted);
    }
    fclose(file);
    printf("Tasks saved to file.\n");
}

// Load Tasks from File Function
void loadTasksFromFile(Task tasks[], int *taskCount) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
    *taskCount = 0;
    while (fscanf(file, "%d,%99[^\n],%d\n", &tasks[*taskCount].id, tasks[*taskCount].description, &tasks[*taskCount].isCompleted) == 3) {
        (*taskCount)++;
    }
    fclose(file);
    printf("Tasks loaded from file.\n");
}

// Main Function
int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        // Display the main menu
        printf("\n==============================\n");
        printf("      TO-DO LIST MENU\n");
        printf("==============================\n");
        printf("1. Add New Task\n");
        printf("2. View All Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Save Tasks to File\n");
        printf("6. Load Tasks from File\n");
        printf("7. Exit\n");
        printf("==============================\n");
        printf("Choose an option: ");

        // Take menu choice as input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, &taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, &taskCount);
                break;
            case 4:
                deleteTask(tasks, &taskCount);
                break;
            case 5:
                saveTasksToFile(tasks, &taskCount);
                break;
            case 6:
                loadTasksFromFile(tasks, &taskCount);
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
