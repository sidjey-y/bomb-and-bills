# Bombs and $100 Bills

## Overview

The "Bombs and $100 Bills" problem is a grid-based puzzle where the goal is to maximize the number of $100 bills saved before bombs explode. Each cell in the grid either contains a bomb or a number representing the number of $100 bills. When a bomb explodes, it incinerates all bills in its row and column. You can perform a limited number of swaps to optimize the number of bills saved.

## Problem Statement

Given an `n x m` grid with bombs and $100 bills, and a maximum of `k` swaps allowed:

- Each cell contains either a bomb (`B`) or a number from `1` to `9`, representing the number of $100 bills.
- Bombs incinerate all bills in their row and column when they explode.
- You are allowed to swap the positions of the bills up to `k` times to maximize the number of $100 bills saved.

### Input

The input will be read from a file. The first line of the file contains:
- Three integers: `n`, `m`, and `k`:
  - `n`: Number of rows
  - `m`: Number of columns
  - `k`: Maximum number of allowed swaps

The following `n` lines contain `m` characters each, representing the grid.

## How It Works

1. **Identify Safe Cells**: Determine cells that are not in the same row or column as any bomb.
2. **Calculate Initial Value**: Sum the values of $100 bills in safe cells.
3. **Optimize with Swaps**: If `k > 0`, strategically swap bill values to maximize the total saved before bombs explode.

## Usage

To run the program, execute the following command, providing the input file as an argument:

```bash
$ python bomb_and_bills.py testcases/test0.txt
