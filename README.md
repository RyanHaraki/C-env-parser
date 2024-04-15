# .env File Parser in C

Wanted to practice building a small C program and some text parsing.

This small command-line program takes in a .env file and spews the contents out as JSON.

To build:
```
gcc main.c -o parser
```

Run with
```
./parser path_to_env 
```

Example output (input `./parser .env`):
```
Printing the contents of your .env file:
----------------------------------------
{
    API_KEY: sk1234,
    SUPER_SECRET_KEY: "14515",
}
```
