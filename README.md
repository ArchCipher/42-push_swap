# <p align="center"> Push Swap - Stack Sorting Algorithm </p>

**42 Project | Algorithms & Data Structures**  
**Objective:** Sort a stack of integers using only two stacks and a limited set of operations, optimizing for the minimum number of operations.

---

## Overview

**Push Swap** is an algorithm project that challenges you to sort a stack of integers using only two stacks (A and B) and a restricted set of operations. The goal is to find the most efficient sequence of operations to sort the stack, with strict performance requirements.

---

## Skills Demonstrated

- **Algorithm Design:** Developing efficient sorting algorithms with constraints
- **Stack Data Structure:** Implementing and manipulating stacks
- **Optimization:** Minimizing operation count for different input sizes
- **Complexity Analysis:** Understanding time and space complexity
- **Edge Case Handling:** Handling already sorted, reverse sorted, and edge cases
- **Performance Testing:** Meeting strict operation count requirements

---

## Operations

### Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate stack A (top to bottom) |
| `rb` | Rotate stack B (top to bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm Strategy

**Key Algorithm:** Greedy Sort / Turk Algorithm - Calculates cost of moving each element and selects the most efficient move at each step.

The implementation uses two distinct approaches based on stack size:
- **Stack length 3:** Hardcoded optimal solution (see [`sort_3()`](sort.c#L24))
- **Stack length > 3:** Greedy cost-based algorithm (see [`sort_stack()`](sort.c#L44))

---

## Performance Requirements

**Benchmark:**
- Sort 100 random numbers in fewer than 700 operations
- Sort 500 random numbers in no more than 5500 operations

**Achieved Performance:**
- 3 elements: 2-3 operations
- 5 elements: 8-12 operations
- 100 elements: ~550 operations average (within limit)
- 500 elements: ~5500 operations average (within limit)

---

## Program Structure

### push_swap
- **Input:** List of integers as command-line arguments
- **Output:** Sequence of operations to sort stack A
- **Algorithm:** Implements sorting strategy based on stack size

### checker (Bonus)
- **Input:** List of integers + sequence of operations
- **Output:** `OK` if sorted correctly, `KO` otherwise
- **Purpose:** Validates that operation sequence correctly sorts the stack

---

## Key Algorithms Implemented

### 1. Small Stack Sort (Stack Length 3)
- Hardcoded optimal solutions for 3-element stacks
- Direct comparison and swap operations
- Minimal operation count (2-3 operations)

### 2. Cost-Based Optimization (Greedy Algorithm)
- Calculate cost of moving each element (see [`sort.c`](sort.c) for implementation)
- Consider both rotation and reverse rotation costs
- Choose moves that minimize total operations
- Optimize for combined operations (`rr`, `rrr`, `ss`)

### 3. Position Tracking
- Track current position of each element
- Calculate shortest path to target position
- Optimize rotation direction (forward vs reverse)

### Other Algorithms Considered
During development, I explored alternative approaches including:
- **LIS (Longest Increasing Subsequence):** Identify longest sorted subsequence to minimize moves
- **Radix Sort:** Sort by individual digits/positions
- **Counting Sort:** Count occurrences and place elements in order

The greedy cost-based approach was selected for its balance of efficiency and implementation simplicity.

---

## Compilation & Usage

```bash
# Build push_swap
make

# Build checker (bonus)
make bonus

# Run push_swap
./push_swap 4 3 2 1 0

# Test with checker
ARG="4 3 2 1 0"; ./push_swap $ARG | ./checker $ARG

# Visualize operations (with external tools)
ARG="4 3 2 1 0"; ./push_swap $ARG | ./checker -v $ARG
```

---

## Technical Highlights

### Key Functions
- [`stack_init()`](stack_init.c#L28) - Initialize stack from arguments
- [`sort_stack()`](sort.c#L44) - Main sorting algorithm
- [`calculate_costs()`](sort.c#L132) - Calculate move costs for optimization
- [`execute_cheapest()`](sort_execute.c#L25) - Execute the most efficient move
- [`is_sorted()`](sort_utils.c#L22) - Check if stack is sorted

---

## Testing

The project has been tested with:
- **[push_swap_tester](https://github.com/nafuka11/push_swap_tester)** - Comprehensive test suite
- Custom test scripts for various stack sizes and edge cases
- Memory leak detection (AddressSanitizer/ASan)
- Performance validation against benchmark requirements

---

*This project demonstrates advanced algorithm design, optimization techniques, and efficient data structure manipulation in C.*
