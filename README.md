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