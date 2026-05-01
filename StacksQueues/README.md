# Stacks and Queues

This folder covers stack and queue patterns, including expression conversion/evaluation, monotonic stacks, and classic stack problems from LeetCode. Use this for revising stack-based parsing and queue implementations.

## Problems and approaches

### Asteroid Collision
- File: [StacksQueues/AsteroidCollision.cpp](StacksQueues/AsteroidCollision.cpp)
- Approach used: stack simulation of collisions with sign checks.
- Time: O(n). Space: O(n).

### Build Array With Stack Operations
- File: [StacksQueues/BuildArrayWithStackOps.cpp](StacksQueues/BuildArrayWithStackOps.cpp)
- Approach used: simulate push/pop from 1..n to match target.
- Time: O(n). Space: O(1) extra.

### Decode String
- File: [StacksQueues/DecodeString.cpp](StacksQueues/DecodeString.cpp)
- Approach used: stack of strings; when ']' found, build substring and repeat.
- Time: O(n * k) due to expansion. Space: O(n).

### Evaluate Reverse Polish Notation
- File: [StacksQueues/EvaluateReversePolishNotation.cpp](StacksQueues/EvaluateReversePolishNotation.cpp)
- Approach used: stack of integers; apply operator on top two.
- Time: O(n). Space: O(n).

### Message Queue (Circular Queue)
- File: [StacksQueues/message_queue.c](StacksQueues/message_queue.c)
- Approach used: array-backed circular queue with menu shell.
- Note: this file appears incomplete and has undefined identifiers in `MENU`.

### Min Add to Make Parentheses Valid
- File: [StacksQueues/MinAddToMakeParanthesisValid.cpp](StacksQueues/MinAddToMakeParanthesisValid.cpp)
- Approach used: stack to cancel matching parentheses.
- Time: O(n). Space: O(n).
- Better approach: count balance and needed closes with O(1) space.

### Online Stock Span
- File: [StacksQueues/OnlineStockSpan.cpp](StacksQueues/OnlineStockSpan.cpp)
- Approach used: monotonic stack storing (price, span).
- Time: O(n) amortized. Space: O(n).

### Queue Using 2 Stacks
- File: [StacksQueues/QueueUsing2Stacks.c](StacksQueues/QueueUsing2Stacks.c)
- Note: file only contains a comment placeholder.

### Infix to Postfix Conversion
- File: [StacksQueues/stacks_infix_to_postfix.c](StacksQueues/stacks_infix_to_postfix.c)
- Approach used: operator stack with precedence rules.
- Time: O(n). Space: O(n).

### Postfix Evaluation
- File: [StacksQueues/stacks_postfix_evaluation.c](StacksQueues/stacks_postfix_evaluation.c)
- Approach used: stack of operands; apply operators.
- Time: O(n). Space: O(n).
