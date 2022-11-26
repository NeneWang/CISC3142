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

![](./../img/2022-11-26-15-47-13.png)

Output file...

![](./../img/2022-11-26-15-47-27.png)

## Extras

### Create also csv for weigted average 

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