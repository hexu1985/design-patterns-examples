# Memento pattern
Keep a memento of an object's state to return to that state
A token/handle representing the system state. Lets us roll back to the state when the token was generated. May or may not directly expose state information.

## Summary
- Mementos are used to roll back states arbitrarily
- A memento is simply a token/handle class with (tipically) no functions of its own
- A memento is not required to expose directly the state(s) to which it reverts the system
- Can be used to implement undo/redo

## Motivation
- An object or system goes through changes
- There are different ways of navigating those changes
- One way is to record every change (Command) and tech a command to 'undo' itself
- Another is to simply save snapshots of the system
