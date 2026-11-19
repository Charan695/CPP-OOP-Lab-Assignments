# C++ OOP Lab Assignments

Self-contained C++17 programs for the assigned practical exercises.

## Experiments

1. **C++ Basics** — data types, constants, variables, operators and input/output.
2. **Class Hierarchy** — BankAccount and SavingsAccount, access specifiers and member functions.
3. **Constructors and Rule of 5** — default, parameterized, copy and move constructors, copy/move assignment and destructor.
4. **Inheritance** — Person → Student → GraduateStudent.
5. **Runtime Polymorphism** — abstract Shape class with Circle, Rectangle and Triangle.
6. **Compile-time Polymorphism** — function overloading and Complex number operator overloading.
7. **Templates** — generic Stack tested with int, float and std::string.
8. **STL** — vector, map, unordered_map, sort, find_if and transform.
9. **Exception Handling** — custom banking exception hierarchy.

The supplied question list repeats the generic Stack/Queue exercise as Questions 7 and 8. It is represented once rather than duplicating the program.

## Build

Requires a C++17-compatible compiler such as GCC.

Compile one experiment from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic 01-cpp-basics/main.cpp -o program
./program
```

Replace the source path with the experiment you want to run. On Windows, run `program.exe`.

## Valgrind: Experiment 03

On Linux with Valgrind installed:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g 03-constructors-rule-of-five/main.cpp -o constructors
valgrind --leak-check=full --show-leak-kinds=all ./constructors
```

The program is written to release its dynamically allocated array. Run Valgrind locally to verify it; no Valgrind execution is claimed by this repository.

Each experiment has its own `main.cpp`. Compile one experiment at a time.
