# Green Efficiency Analysis

## Measurement Methodology

For this experiment, I added timers to the original C program to see how much time each part takes to execute. I used the `clock()` function from the `<time.h>` library.

I wanted to measure both the total execution time and the time spent in each individual phase.

The total timer starts just before `build_dataset()` and stops after `reduce_checksum()` has finished. This means it includes all three main phases of the program.

I also added separate timers around each function:
- `BUILD_DATA` measures the time needed to create the dataset.
- `PROCESS` measures the time needed to process the values.
- `REDUCE` measures the time needed to calculate the checksum.

To convert the results into seconds, I divided the clock differences by `CLOCKS_PER_SEC`. I kept the original program logic unchanged and only added the timing code.

I ran the program three times to compare the results and see if the execution times changed.

## Observed Performance Differences

After running the program three times, I noticed that the results were very similar.

The total execution times were 0.000281 seconds, 0.000276 seconds and 0.000278 seconds.

The `BUILD_DATA` phase took 0.000136 seconds in the first run and 0.000131 seconds in the other two runs. It was the slowest phase every time.

The `PROCESS` phase took exactly 0.000097 seconds in all three runs.

Finally, the `REDUCE` phase took 0.000045 seconds, 0.000046 seconds and 0.000045 seconds.

These results show that creating the dataset takes more time than processing it or calculating the checksum. The differences between the three runs are also very small.

## Relation Between Runtime and Energy Consumption

Execution time and energy consumption can be related. For example, if a program finishes faster, the processor may spend less time working on it.

However, a shorter execution time does not automatically mean that a program uses less energy.

In this experiment, I only measured execution time. I did not measure electricity consumption or processor power.

Because of this, I cannot say which phase uses the most energy. I would need additional measurements to make that conclusion.

## Limitations of the Experiment

There are a few limitations to this experiment.

First, I only ran the program three times. Running it more times could give more reliable results.

Another limitation is that the execution times are extremely short. Even small changes in the computer's activity could affect the measurements.

Also, the program always uses a dataset of 50,000 elements. The results could be different with a larger dataset.

Finally, I did not measure actual energy consumption. I only measured CPU execution time using `clock()`. This means that I cannot make a complete comparison of the energy efficiency of each phase.

## Practical Engineering Takeaway

This experiment helped me understand why it is useful to measure different parts of a program separately.

By looking at the results, I can see that `BUILD_DATA` takes the most time, followed by `PROCESS` and then `REDUCE`.

If I wanted to improve the program's performance, I would start by looking at the dataset creation phase because it takes the longest time in all three tests.

I also learned that execution time and energy consumption are not exactly the same thing. Measuring how fast a program runs is useful, but it is not enough to know how much energy it uses.

Overall, this experiment showed me how timing measurements can help identify which parts of a program could be improved.
