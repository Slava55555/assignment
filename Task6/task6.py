def balance_load(tasks, conflicts):
    """
        Args:
                tasks: A list of tasks with their completion time (format: [(completion time, id)]).
                conflicts: A list of conflicting sets (format: [[id1, id2, ...]]).
        Returns:
                A list of task assignments to processors (format: [(id, processor number_)]).

    """
    tasks.sort(key=lambda x: x[0], reverse=True) # Sort tasks by execution time in descending order
    processor_loads = [0, 0] # Processor loads
    assignments = []

    for task_time, task_id in tasks:
        min_load_processor = processor_loads.index(min(processor_loads)) # Choose the processor with the minimum load


        is_conflicting = False # Check for conflicts:
        for conflict_set in conflicts:
            if task_id in conflict_set and all(t[1] in assignments and assignments[assignments.index(t[1])][1] == min_load_processor for t in tasks if t[1] in conflict_set):
                is_conflicting = True
                break

        if not is_conflicting: # If the task does not conflict with already assigned ones
            processor_loads[min_load_processor] += task_time # Update processor load
            assignments.append((task_id, min_load_processor)) # Add the task to assignments

    return assignments

# Read
with open("times.txt", "r") as f:
    tasks = [tuple(map(int, line.strip().split())) for line in f]
    tasks = [(time, i) for i, (time,) in enumerate(tasks)]

with open("conflicts.txt", "r") as f:
    conflicts = [list(map(int, line.strip().split())) for line in f]

assignments = balance_load(tasks, conflicts)
ans = [0,0]
for task_id, processor in assignments:
    time,id = tasks[task_id]
    ans[processor] += time
print(ans)
