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

| Operation | Description | Example |
|-----------|-------------|---------|
| `sa` | Swap first two elements of stack A | `[3, 2, 1]` → `[2, 3, 1]` |
| `sb` | Swap first two elements of stack B | `[5, 4]` → `[4, 5]` |
| `ss` | `sa` and `sb` simultaneously | Both stacks swapped |
| `pa` | Push top element from B to A | `A: [1] B: [2, 3]` → `A: [2, 1] B: [3]` |
| `pb` | Push top element from A to B | `A: [2, 1] B: [3]` → `A: [1] B: [2, 3]` |
| `ra` | Rotate stack A (top to bottom) | `[1, 2, 3]` → `[2, 3, 1]` |
| `rb` | Rotate stack B (top to bottom) | `[4, 5]` → `[5, 4]` |
| `rr` | `ra` and `rb` simultaneously | Both rotated |
| `rra` | Reverse rotate stack A | `[1, 2, 3]` → `[3, 1, 2]` |
| `rrb` | Reverse rotate stack B | `[4, 5]` → `[5, 4]` |
| `rrr` | `rra` and `rrb` simultaneously | Both reverse rotated |

---

## Algorithm Strategy

**Key Algorithm:** Greedy Sort / Turk Algorithm - Calculates cost of moving each element and selects the most efficient move at each step.

### Small Stacks (2-5 elements)
- **2 elements:** Use `sa` if needed
- **3 elements:** Hardcoded optimal solution (max 2-3 operations)
- **4-5 elements:** Simple insertion sort approach

### Medium Stacks (6-100 elements)
- **Chunk-based approach:** Divide stack into chunks
- **Push chunks to B:** Move elements in chunks to stack B
- **Sort chunks:** Sort each chunk independently
- **Merge back:** Push sorted chunks back to A in order

### Large Stacks (100+ elements)
- **Optimized chunking:** Dynamic chunk size calculation
- **Position tracking:** Track element positions for efficient moves
- **Cost calculation:** Calculate cost of each possible move
- **Greedy selection:** Choose moves that minimize total operations

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

## Key Algorithms Implemented

### 1. Small Stack Sort (2-5 elements)
- Hardcoded optimal solutions for small inputs
- Direct comparison and swap operations
- Minimal operation count

### 2. Chunk-Based Sort
- Divide stack into logical chunks
- Push chunks to stack B in order
- Sort chunks individually
- Merge back to stack A

### 3. Cost-Based Optimization (Greedy Algorithm)
- Calculate cost of moving each element (see [`sort.c`](sort.c) for implementation)
- Consider both rotation and reverse rotation costs
- Choose moves that minimize total operations
- Optimize for combined operations (`rr`, `rrr`, `ss`)

### 4. Position Tracking
- Track current position of each element
- Calculate shortest path to target position
- Optimize rotation direction (forward vs reverse)

---

## Technical Highlights

### Key Functions
- `stack_init()` - Initialize stack from arguments
- `sort_stack()` - Main sorting algorithm
- `calculate_costs()` - Calculate move costs for optimization
- `execute_cheapest()` - Execute the most efficient move
- `is_sorted()` - Check if stack is sorted

---

## Testing

The project has been tested with:
- **[push_swap_tester](https://github.com/nafuka11/push_swap_tester)** - Comprehensive test suite
- Custom test scripts for various stack sizes and edge cases
- Memory leak detection (AddressSanitizer/ASan)
- Performance validation against benchmark requirements

---

## Key Challenges & Solutions

### Challenge 1: Minimizing Operations
**Problem:** Finding the optimal sequence of operations  
**Solution:** Implemented cost-based algorithm that calculates and compares move costs

### Challenge 2: Handling Large Stacks
**Problem:** Meeting operation count requirements for 100+ elements  
**Solution:** Developed chunk-based approach with dynamic chunk sizing

### Challenge 3: Optimizing Rotations
**Problem:** Reducing redundant rotations  
**Solution:** Combined operations (`rr`, `rrr`) and optimized rotation direction

### Challenge 4: Position Calculation
**Problem:** Efficiently finding target positions for elements  
**Solution:** Pre-calculated positions and maintained sorted order tracking

---

## Project Status

✅ **Completed** - Both push_swap and checker implemented with optimal performance

---

*This project demonstrates advanced algorithm design, optimization techniques, and efficient data structure manipulation in C.*
