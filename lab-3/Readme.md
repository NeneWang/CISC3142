# Assigment Markdown

## 2.1

What are the differences between int, long, long long,
and short? Between an unsigned and a signed type? Between a 
float and a double?


They differ in size

| --          | int | long | long long | short |
| ----------- | --- | ---- | --------- | ----- |
| size (bits) | 32  | 32   | 64        | 16    |


Unsigned and signed type diffes that one  signed can hold **positive and negative numbers** while **singed** can only hold **Positive values**

Difference `Float` and `Double`:
- `Float` has less less precision than double
- `Float` operations with double and single precisions are neglible and cheap compared to `Double`


## 2.2

Exercise 2.2: To calculate a mortgage payment, what types 
would you use for the rate, principal, and payment? Explain why you 
selected each type.

> I would use a float because I have to count also the 
> > Rate: Float, principal: long long, payment long
sents.

## 2.3

Exercise 2.3: What output will the following code 
produce?

```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl; 
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

```
32
4294967264 //4294967296 - 32
32
-32
0
0
```


## 2.10
Exercise 2.10: What are the initial values, if any, of each 
of the following variables?


| --            | local_int        | local_str                   |
| ------------- | ---------------- | --------------------------- |
| Initial Value | 0                |                             |
| Description   | initializes as 0 | initializes as empty string |

!Initializes as 0!

## 2.12

Exercise 2.12: Which, if any, of the following names are 
invalid? (a) int double = 3.14; (b) int _; (c) int 
catch-22; (d) int 1_or_2 = 1; (e) double Double = 3.14;

![](./../img/2022-10-19-18-43-50.png)

Invalids:

```
(a), (c), (d)
```

_ works well if its not inside of a function

## 2.13

Exercise 2.13: What is the value of j in the following 
program?

![](./../img/2022-10-19-18-46-28.png)

```cpp
int i = 42;
int main()
{
 int i = 100; int j = i;
}
```


j will be `100`


## 2.14

Exercise 2.14: Is the following program legal? If so, what 
values are printed?

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
 sum += i;
std::cout << i << " " << sum << std::endl;
```

Yes, it should be legal, printed values are:

```
100, 45
```


## 2.17

Exercise 2.17: What does the following code print?

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

Prints:

```
10 10
```



## 2.27

![](./../img/2022-10-19-18-51-03.png)

| Initialization char | is legal?   | Why                                                       |
| ------------------- | ----------- | --------------------------------------------------------- |
| a                   | No          | Because it shouldn't be a constant value,  but a variable |
| b                   | Yes-Depends | Depends `i2` has to be declared first                     |
| d                   | Yes-depends | `i2` has to be declared first. ->                             |
| e                   | Yes-depends | `i2` has to be declared first                             |
| f                   | No          | r2 needs to be initialized                                |
| g                   | Yes         |


Conclusions
- const address (&) can point to a constant value such as 0
- 

## 2.28

![](./../img/2022-10-19-18-51-17.png)
![](./../img/2022-10-19-18-51-23.png)

| initialization char | Legal | Why                    | Teacher Feed                |
| ------------------- | ----- | ---------------------- | --------------------------- |
| a                   | No    | cp must be initialized | Error Reference initializer |
| b                   | No    | p2 must be initialized |
| c                   | No    | ic must be initialized |
| d                   | No    | p3 must be initialized |
| e                   | Yes   | Because p is a pointer |

- const int*p not pointing to anyting is the only one it works.


### 



