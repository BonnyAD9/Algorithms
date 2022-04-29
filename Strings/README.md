# Strings

## Brace checking
These algorithms check whether given string has correctly matched braces

```C
bool checkBrace(char* str, char o, char c);
bool recursiveCheckBraces(char* str, char* o, char* c);
```

- `checkBrace` checks for single brace type
- `recursiveCheckBraces` checks for multiple brace types using the stack
