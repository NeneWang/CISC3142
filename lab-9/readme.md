# Exercise 9

## Getting Started

For windows run:
```
make lab9
```

For mac run:

```
make lab9-mac
```

## Prompt

![](./../img/2022-11-26-15-47-06.png)

### Solution Test cases

- They had been divided into three test cases, one for each problem as proof of work.

![](./../img/2022-11-26-15-47-13.png)

Output file...

![](./../img/2022-11-26-15-47-27.png)

## Extras

### Create also csv for weighted average 

This is supported by setting as true for including both average and weighted.

```cpp
tempP.to_csv("output_weighted_included.csv", true, true);
```


Testcase:

```
inlcude_weighted_average
```

![](./../img/2022-11-26-16-05-16.png)

![](./../img/2022-11-26-16-05-57.png)



### Forecasting all months

![](./../img/2022-11-26-16-07-45.png)

- Supports all months where forecasting makes sense in.
- If month is Jan or February not enought data for forecasting it will print `-1`
- If is larger than the last month available (october) for forecasting, it will also print `-1`