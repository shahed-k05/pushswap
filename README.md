# Description
Push_swap is a project that teaches you about sorting algorithms and how to optimize them. The project involves sorting a stack of integers using a limited set of operations (push, swap and rotate) and minimizing the number of moves.

## Instructions
The task is simple: given a sequence of random numbers disposed in a stack data structure (stack A), sort them with the help of an empty auxiliary stack (stack B) and a set of specific stack operations. The operations allowed are:

* sa (swap a): Swap the first 2 elements at the top of stack a. Does nothing if there is only one or none.
* sb (swap b): Swap the first 2 elements at the top of stack b. Does nothing if there is only one or none.
* ss: sa and sb at the same time.
* pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty.
* pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty.
* ra (rotate a): Shifts all the elements of stack a up by one. The first element becomes the last.
* rb (rotate b): Shifts all the elements of stack b up by one. The first element becomes the last.
* rr: ra and rb at the same time.
* rra (reverse rotate a): Shifts all elements of stack a down by one. The last element becomes the first.
* rrb (reverse rotate b): Shifts all elements of stack b down by one. The last element becomes the first.
* rrr: rra and rrb at the same time.

To compile and run the program:

```bash
make
```
```bash
./push_swap [--simple | --medium | --complex | --adaptive] <list_of_numbers>
```
## Algorithms
The program supports different modes:
- **Simple**: Selection sort for small stacks.
- **Medium**: Chunk sort for medium-sized stacks.
- **Complex**: Radix sort for large stacks.
- **Adaptive**: Chooses between chunk sort and radix sort based on the stack size.

## Resources

* https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
* https://medium.com/@dansylvain84my-implementation-of-the-42-push-swap-project-2706fd8c2e9f
