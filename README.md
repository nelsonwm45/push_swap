# push_swap

This project involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you must manipulate various types of algorithms and choose the most appropriate solution (in this case, Radix Sort) for optimized data sorting.

## Learning Objectives

-   **Sorting Algorithms**: Implementing efficient sorting algorithms like Radix Sort.
-   **Stack Manipulation**: using stacks (LIFO) to organize data.
-   **Complexity Analysis**: optimizing the number of operations (Big O notation).
-   **Unix Logic**: Using standard input/output and error handling.

## Scope

### Mandatory Part

-   **The Program**: `push_swap` takes a set of integers as arguments and outputs the smallest list of instructions to sort them.
-   **The Rules**:
    -   Two stacks: `a` and `b`.
    -   Operations:
        -   `sa`, `sb`, `ss`: Swap magnitude.
        -   `pa`, `pb`: Push top element.
        -   `ra`, `rb`, `rr`: Rotate up.
        -   `rra`, `rrb`, `rrr`: Rotate down.
-   **Algorithm**: This implementation uses **Radix Sort** (base 2) for efficient sorting of large datasets.

### Radix Sort Explanation

Radix Sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix. For `push_swap`, we use a binary version (base 2) adapted for two stacks:

1.  **Indexing**: First, numbers are simplified to their relative ranks (0 to N-1). This avoids dealing with large or negative integers.
2.  **Bitwise Processing**: The algorithm processes the binary representation of these indices bit by bit, from the least significant bit (LSB) to the most significant bit (MSB).
3.  **Distribution**:
    -   For the current bit `i`, if the bit at position `i` is `0`, the number is pushed to stack `b` (`pb`).
    -   If the bit is `1`, the number stays in stack `a` and is rotated (`ra`).
4.  **Collection**: After processing all numbers for bit `i`, all elements from stack `b` are pushed back to stack `a` (`pa`).
5.  **Repeat**: This process repeats for all bits. Since the input is simplified to indices, the number of bits needed is small (e.g., 100 numbers < 2⁷, so 7 bits max).

This guarantees the stack is sorted after processing the most significant bit.

### Bonus Part

-   **The Checker**: `checker` takes the stack as arguments and reads instructions from standard input. It executes them and displays `OK` if sorted, or `KO` otherwise.

## Getting Started

### Prerequisites

-   `gcc` compiler
-   `make`

### Installation & Usage

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/nelsonwm45/push_swap.git
    cd push_swap
    ```

2.  **Build the project:**
    ```bash
    make
    ```
    This creates the `push_swap` executable.

    For the bonus (checker):
    ```bash
    make bonus
    ```
    This creates the `checker` executable.

3.  **Run push_swap:**
    ```bash
    ./push_swap 2 1 3 6 5 8
    ```
    Output:
    ```text
    sa
    pb
    pb
    pb
    sa
    pa
    pa
    pa
    ```

4.  **Run checker (Bonus):**
    ```bash
    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
    ```
    Output:
    ```text
    OK
    ```