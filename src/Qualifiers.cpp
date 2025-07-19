#include <Arduino.h>
/*
1. Qualifiers
- in C/C++ (and Arduino) are keywords that modify the behavior of variables.
- They don't change the data type, but how the variable acts in the program.

    1.1 const Qualifier - "Make it read-only"
    - Makes a variable constant (unchangeable after it is declared)
    - Helps protect values like PI, pin numbers, etc.
    - EXP: const int ledPin = 13;
    - Good when:
        - Constants you don't want accidentally modified (e.g., pin numbers, fixed values)
        - Improves code safety and clarity

    1.2 Alternative to const: #define
    - A preprocessor directive, not a variable
    - Replaces the keyword with a value before code is compiled.
    - EXP: #define PI 3.14
    - Pros:
        - Saves memory (especoa;;y useful in embedded systems like Arduino)
        - Works with any value (int, float, char, etc).
    - Cons:
        - No type checking
        - Hard to debug
        - Global replacement might cause naming conflicts.

    - Best Practice:
        - Use const when possible for type safety and debugging
        - Use #define only when you need memory savings or define constants at compile time.


2. static qualifiers - "Preserve between calls"
- Keeps local variable's value between function calls.
- Initializes only once (not every time the function runs).
- EXP:
    static int counter = 0;
    counter ++;
    Serial_println(counter);
- Behavior:
    - Without static: variable is reset each time function runs.
    - With static: variable retains its value across runs.

- Useful for:
    - Counters
    - Flags
    - Functions where data must be remembered, but scope should remain local.

*/
void qualifiersSetup(){

}

void qualifiersLoop(){

}