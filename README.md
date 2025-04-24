# 🧠 Philosophers

> A Codam/42 project that explores concurrency, synchronization, and thread management through the classic Dining Philosophers problem.

## 📚 Project Overview

The goal of the **Philosophers** project is to understand the basics of **multithreading**, **mutexes**, and handling **shared memory** between threads.

By simulating the Dining Philosophers problem, we aim to solve issues around:
- **Deadlocks**
- **Race conditions**
- **Thread starvation**

This project is a great intro to working with **POSIX threads (pthreads)** in C and learning how to write safe, concurrent code.

## 🧩 The Problem

Five philosophers sit at a table. Each of them alternates between **thinking**, **eating**, and **sleeping**.  
Each philosopher needs **two forks** to eat — but there’s only one fork between each pair of philosophers.

The challenge is to make sure they can:
- Eat without starving
- Avoid deadlocks
- Keep the simulation running efficiently and safely

## 🔧 Implementation

- Written in **C**
- Uses **POSIX threads** (`pthread`)
- Synchronization is handled via **mutexes**
- Timing is controlled with **gettimeofday** / **usleep**
- Supports different input configurations for:
  - Number of philosophers
  - Time to die / eat / sleep
  - Optional: number of meals before stopping

## 🛠️ How to Compile

```bash
make
```
## 🚀 How to Run

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals]
```
## 🧪 Testing

./philo 5 800 200 200

and

./philo 5 800 200 200 7