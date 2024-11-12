# To-Do-list Application

A simple command-line To-Do List application built in C, allowing users to manage their tasks with ease. This project supports task creation, viewing, marking tasks as completed, deleting tasks, and saving/loading tasks to and from a file. 
# Features 

Add Task: Create a new task by entering a description.
View Tasks: Display all tasks with their ID, description, and status (completed or incomplete).
Mark Task as Completed: Mark a task as completed by entering its ID.
Delete Task: Delete a task by entering its ID, removing it from the task list.
Save Tasks: Save all current tasks to a file (tasks.txt) for persistence.
Load Tasks: Load previously saved tasks from tasks.txt, restoring them in the application.

# How It Works
This application uses a structure called Task to store information about each task:

id: The unique identifier for the task.
description: A short description of the task.
isCompleted: A status flag indicating whether the task is completed.
All tasks are stored in an array, and the program uses simple file I/O to save and load tasks from tasks.txt.

