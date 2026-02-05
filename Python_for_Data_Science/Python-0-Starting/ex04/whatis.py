import sys

if len(sys.argv) == 1:
    sys.exit(0)
try:
    if len(sys.argv) != 2:
        raise AssertionError("more than one arugment is provided")
    arg = sys.argv[1]
    number = int(arg)
except ValueError:
    print("AssertionError : argument is not an integer")
    sys.exit(1)
except AssertionError as error:
    print(f"AssertionError: {error}")
    sys.exit(1)
if number % 2 == 0:
    print("I'm Even.")
else:
    print("I'm Odd.")
