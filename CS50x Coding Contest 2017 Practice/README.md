# Challenges

## 1 - Temperature Converter

Write a program that, given a temperature in Celsius, C, as a floating-point value via standard input, prints via standard output that temperature in Fahrenheit, F, as a floating-point value, rounded to one decimal place.

Recall that:

F = C * 9/5 + 32

For example, if a user inputs:

- `0.0`, your program should print `32.0`

- `100.0`, your program should print `212.0`

- `42.0`, your program should print `107.6`

You may include additional header files as needed, and you may call any functions you'd like. Note that the CS50 Library's header file must be included with double quotes (i.e., `#include "cs50.h"`) instead of angled brackets because of how it's installed on HackerRank's servers.

Odds are you'll find `GetDouble` and `printf` of interest!

**Input Format**

A temperature in Celsius as a floating-point value formatted as `x.y`, where `x` and `y` each represent one or mode decimal digits.

**Constraints**

Assume that your program will only be passed floating-point values greater than or equal to `-DBL_MAX` and less than `DBL_MAX` as input.

**Output Format**

A temperature in Fahrenheit as a floating-point value rounded to one decimal place, formatted as `x.y`, where `x` represents one or more decimal digits and `y` represents exactly one decimal digit.

**Sample Input**

```
42.0
```

**Sample Output**

```
107.6
```

Explanation

We leave the `TODO` to you!

----------

## 2 - Factorialization

Write a program that takes an integer as input and outputs its factorial.

Note that the CS50 Library's header file must be included with double quotes (i.e., `#include "cs50.h"`) instead of angled brackets because of how it's installed on HackerRank's servers.

Odds are you will find `GetInt` and `printf` of interest!

**Input Format**

An integer number.

**Constraints**

None.

**Output Format**

The factorial of the inputted number, as an integer.

**Sample Input**

```
5
```

**Sample Output**

```
120
```

**Explanation**

The factorial of a number, n, is `n × (n - 1) × (n - 2) ... × 2 × 1`. For example, the factorial of 5 is `5 × 4 × 3 × 2 × 1 = 120`.

----------

## 3 - Substring Challenge

Write a program that takes two strings as input. If the second string is a substring of the first, output the index where the second string begins within the first string. Otherwise, output `-1`. Be sure to support wildcard characters, represented by an asterisk (`*`).

**Input Format**

Two strings separated by a newline.

**Constraints**

None.

**Output Format**

The index where the second string begins within the first string, or -1, if the second string is not substring of the first.

**Sample Input**

```
Colton is cool
ton
```

**Sample Output**

```
3
```

**Explanation**

We leave the `TODO` to you!

----------

## 4 - Decimal to Binary Conversion

Take in a decimal number via input and output the corresponding binary number, displaying only significant bits (i.e., don't show `01111` for 15, only `1111`).

**Input Format**

A decimal integer.

**Constraints**

None.

**Output Format**

The corresponding binary representation of the inputted decimal number.

**Sample Input**

```
15
```

**Sample Output**

```
1111
```

**Explanation**

We leave the `TODO` to you!

----------

## 5 - Reverse Linked List

Using a linked list, allow the user to input as many integers as they want, stopping when they enter a non-numeric character, then output all of the integers in the list in reversed order, separated by newlines.

**Input Format**

A list of integers separated by newlines.

**Constraints**

None.

**Output Format**

The inputted list of integers, in reversed order, separated by newlines.

**Sample Input**

```
120
34
78
d
```

**Sample Output**

```
78
34
120
```

**Explanation**

We leave the `TODO` to you!

----------

## 6 - Phone Book Challenge

Write a program that reads a specified number of phone book entries, creating a hash map entry as needed, then reads name queries and outputs the matching entry from the phone book, if such entry exists.

**Input Format**

The first line of input will have an integer, denoting the number of entries in the phone book. Each entry consists of two lines:

a name.
a corresponding phone number to that name.
Each following line will be a name query. Read the queries until end-of-file!

**Constraints**

None.

**Output Format**

For each name query, if there is a match in the phone book, print the entry in the following format:

```
name=phone
```

otherwise, print the string `"Not found"` (without the quotes).

**Sample Input**

```
3
sam
99912222
tom
11122222
harry
12299933
sam
edward
harry
```

**Sample Output**

```
sam=99912222
Not found
harry=12299933
```

**Explanation**

We leave the `TODO` to you!
