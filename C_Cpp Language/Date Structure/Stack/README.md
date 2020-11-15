### Explanation About Programs in folder

#### A Easy Stack.c
This program doesn't consider too much about the checking user input.And check the underflow situation.
Its intention is to focus on Core operation, implementation of `PUSH()`, `POP()` and `PEEK()`.

#### stack_en.c
This program consider as far as possible the situation of the program run. For example, check if the stack is empty, is the malloc() step successful or not. Of course, it didn't check user input, the program assumes that the user input is all valid data.

The stack has been initialized at the beginning when you run the program. Of course, you can initialize it at any time, we offer the function in the menu.