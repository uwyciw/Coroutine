# Coroutine

中文说明[在此](README.md)。

This is a lightweight stackless coroutine framework designed for systems with extremely limited memory.

## Features
- **Stackless**: This is the core feature. Traditional threads each have an independent stack space, while this Coroutine reuses a single stack and only records the execution position via state variables, resulting in an ultra-low memory footprint (usually requiring only a few bytes of state variables).
- **Lightweight**: Eliminates thread stack overhead, with nearly negligible creation/switching costs, making it ideal for resource-constrained scenarios.
- **Pseudo-blocking**: Supports implementing blocking logic within C functions. Blocking essentially means state suspension, which only records the current execution position and does not save other task states (e.g., local variable values).
- **Flexible Adaptation**: Can work with RTOS, or run directly on bare-metal event-driven frameworks.

## Principle

The core of this Coroutine is to leverage the **switch-case** syntax of the C language, and through **macro definitions** and **state variables**, split a piece of **linear program** into multiple **code snippets**. When **a blocking condition** is encountered, if the condition is not met, the program exits from the blocking point. When the function is invoked again, the program resumes checking the blocking condition at that point. Only when the blocking condition is satisfied will the next code snippet be executed, thus achieving the suspension and resumption of the coroutine.
