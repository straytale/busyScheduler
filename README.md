
# Busy Scheduler

A simple task scheduling system written in C that simulates a multitasking environment using a cooperative dispatcher and tick-based scheduling. It is suitable for educational use or as a lightweight base for embedded system simulations.

---

## 📁 Project Structure

```
busyScheduler/
├── common.h      # Some operation definitions
├── conf.h        # Configuration macros (tick count, delay settings, etc.)
├── list.h        # Task list data structure (linked list)
├── sche.c        # Scheduler core logic: task queues, state management
├── disp.c        # Dispatcher logic: executing and switching tasks
├── taskA.c       # Task A simulation
├── taskB.c       # Task B simulation
├── taskC.c       # Task C simulation
```

---

## 🚀 How It Works

1. **Tasks (`taskA/B/C`)**: Simulate individual task logic with different behaviors.
2. **Dispatcher (`disp.c`)**: Runs READY tasks and switches control between them.
3. **Scheduler (`sche.c`)**: Manages task states, handles delays, and refreshes the task queue.
4. **Configuration (`conf.h`)**: Contains constants for system ticks and delays.
5. **Task Management**: Tasks are managed via linked lists and can be set as RUNNING, WAITING, or SLEEPING.

---

## 🧠 Concepts Demonstrated

- Cooperative scheduling (non-preemptive)
- Task state management (`SLEEPING`, `WAITING`, `RUNNING`)
- Simulated time delays using system ticks
- Dispatcher-scheduler separation of responsibilities

---

## 🛠️ Build Instructions

This project doesn't include a `Makefile`, but you can compile it manually:

```bash
gcc -o busyScheduler     sche.c disp.c taskA.c taskB.c taskC.c     -I. 
```

> You may also add `-Wall -Wextra` flags to enable compiler warnings.

---

## 📌 Notes
- Designed for Windows, but portable to Linux.
- This is a tick-based simulation with no use of real threads or preemption.
- Designed to simulate embedded-style scheduling in a basic environment.
- Useful as a teaching tool for real-time scheduling principles.

---

## 📚 Suggested Extensions

- Add priority-based scheduling
- Implement round-robin with time slicing
- Integrate interrupt-driven tick simulation
