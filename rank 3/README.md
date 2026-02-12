This project has been created as part of the 42 curriculum by hugutterr.

# Philosophers

## Description

Philosophers is a 42 project based on the classic Dining Philosophers problem.

The goal is to learn about:
 - Threads
 - Mutexes
 - Synchronization
 - Race conditions
 - Deadlocks

Each philosopher is a thread. They must take two forks to eat, then sleep and think.  
The simulation stops if a philosopher dies or if all have eaten enough times.


## Instructions


### Compile

    make

### Execution
    
    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]

### Arguments

 - number_of_philosophers – number of philosophers (and forks)
 - time_to_die – time before a philosopher dies (ms)
 - time_to_eat – time spent eating (ms)
 - time_to_sleep – time spent sleeping (ms)
 - must_eat_count (optional) – simulation stops when all philosophers eat this many times


## Ressources

 - 42 Philosophers subject PDF
 - man pthread
 - man pthread_mutex
 - man usleep
 - man gettimeofday

 - Dining Philosophers problem (Operating Systems classic problem)

### AI Usage

AI was used to better understand thread synchronization, race conditions, and deadlock prevention.
All code implementation, debugging, and testing were done manually.


## Tests


# Basic run (no must_eat_count)
    
    ./philo 5 800 200 200

# With must_eat_count (should stop when everyone ate enough)
    
    ./philo 5 800 200 200 7

# One philosopher (should die, can’t take 2 forks)
    
    ./philo 1 800 200 200

# Tight timings (likely to die fast)

    ./philo 5 310 200 200

# Many philosophers (stress test)

    ./philo 200 800 200 200

# Very small eat/sleep times (timing/CPU stress)

    ./philo 5 800 60 60

# Death during long eat/sleep (check monitoring accuracy)

    ./philo 5 200 150 150
