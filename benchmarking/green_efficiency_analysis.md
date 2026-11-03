# Green Efficiency Analysis

## Measurement Methodology

For this project, I added timers to the original C program. I used the `clock()` function from `<time.h>`. The total timer starts just before `build_dataset()` and stops after `reduce_checksum()`, so it covers all three phases. I also added one timer for each phase:

* `BUILD_DATA`: creating the dataset
* `PROCESS`: processing the values
* `REDUCE`: calculating the checksum

I divided the clock differences by `CLOCKS_PER_SEC` to get seconds. I did not change the program logic. I only added the timing code, and I ran the program three times.

Before that, I ran two programs without changing them, using `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` on the same machine. The first one, `baseline_loop.c`, repeats a loop 100,000,000 times. It shows how much the time changes between identical runs. The second one, `comparison_algorithms.c`, counts the even numbers in an array of 50,000 elements with two different methods. I ran each program three times and calculated the averages.

## Observed Performance Differences

**Baseline loop.** The three times were 0.082778, 0.087313 and 0.083843 seconds. The average was 0.084645 seconds. The fastest and the slowest run differed by 0.004535 seconds, which is about 5.4% of the average. So even the same calculation does not take exactly the same time every run.

**Instrumented program.** The total times were 0.000281, 0.000276 and 0.000278 seconds. `BUILD_DATA` was the slowest phase every time (0.000136 seconds in the first run, 0.000131 in the others). `PROCESS` always took 0.000097 seconds. `REDUCE` took about 0.000045 seconds. These times are very small, so the differences between runs are probably just noise.

**Algorithm comparison.** The naive method uses two loops inside each other, which means about 1.25 billion operations. The single-pass method uses one loop, which means 50,000 operations. The naive method took 0.516898, 0.518144 and 0.516939 seconds (average 0.517327 seconds). The single-pass method took 0.000017 seconds each time. This means the naive method is about 30,000 times slower. This is much bigger than the 5% variation seen in the baseline, so it is a real difference, not noise.

## Relation Between Runtime and Energy Consumption

When a program runs for less time, the processor works for less time, so runtime and energy use can be related. But a faster program does not always use less energy. The naive method keeps the CPU busy about 30,000 times longer to get the same result, so on a large scale it would probably use more energy. However, I only measured time. I did not measure electricity or processor power, so I cannot give real energy numbers.

## Limitations of the Experiment

* I ran each program only three times.
* The instrumented program is very short, so small changes on the computer can affect the result.
* `clock()` measures CPU time, not real time. It is also not very precise, so a value like 0.000017 seconds is only approximate, and so is the 30,000 ratio.
* I compiled without optimization, as required. Results could be different in a real production build.
* Other programs running on my computer may have changed the timings.
* I did not measure real energy consumption.

## Practical Engineering Takeaway

Measuring each phase separately shows where the time goes. In my program, `BUILD_DATA` took the most time, so I would start improving it first. The baseline taught me to measure the normal variation before comparing results. The algorithm comparison showed that a better algorithm matters much more than small timing differences: going from O(n²) to O(n) saved a huge amount of time, while the run-to-run variation was only a few percent. Finally, I learned that speed and energy use are not the same thing, so timing alone is not enough to know how much energy a program uses.
