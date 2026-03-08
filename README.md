# string-short-cpp
String to Short Conversion

# Overview

String-to-Short Converter is a C++ program that manually parses a string and attempts to convert it into a signed 16-bit integer (`short`). The program performs strict validation of the input format and detects numeric overflow before returning the result.

Unlike typical implementations that rely on standard library conversion functions, this project implements the full parsing and validation logic manually. This provides practice with low-level string processing, numeric validation, overflow detection, and exception handling.

# Input Format Rules

A string is considered valid if it follows these rules:

- It may optionally begin with a single `+` or `-` sign.
- All remaining characters must be numeric digits (`0–9`).
- One optional decimal point (`.`) may appear.
- If a decimal point appears, it must be followed by either:
  - nothing, or
  - only zeros.

Examples of **valid inputs**:


123
-45
+67
12.
12.0
12.0000


Examples of **invalid inputs**:


12.3
12.01
1e3
--12
12-
5.33.2


# Conversion Constraints

The converted value must fall within the signed 16-bit range:


-32768 to 32767


If the input is improperly formatted or falls outside this range, the program throws an exception with the message:


ConvertToShort: Invalid 16-bit signed integer


# Program Behavior

The program repeatedly prompts the user to enter a value to convert.

1. The input string is passed to `ConvertToShort()`.
2. If the conversion succeeds, the converted `short` value is printed.
3. If the conversion fails, an exception is thrown and caught in `main()`, and the error message is displayed.
4. The user is asked whether they want to perform another conversion.

The program continues until the user enters `N` or `n`.

# Core Concepts Applied

- Manual string parsing and validation
- Exception handling using `throw` and `catch`
- Numeric overflow detection for fixed-width integer types
- Character-level validation of numeric input
- Control-flow logic for user interaction loops
- Defensive programming practices

# Function Design

The central function:


short ConvertToShort(const std::string& input)


Responsibilities:

- Validate string formatting rules
- Detect invalid characters
- Handle optional sign and decimal point rules
- Convert the integer portion to a numeric value
- Check for signed 16-bit overflow
- Throw an exception if any rule is violated

# How to Run

1. Compile the program using a C++ compiler (ex. g++, clang++)
2. Run the executable
3. Enter strings to test conversion behavior
4. Choose whether to perform additional conversions
