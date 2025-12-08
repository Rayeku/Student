import sys


def count_items(s: str):
    """
    Counts and prints the number of upper-case characters,
    lower-case characters, punctuation characters, digits, and spaces
    present in the string given as argument.

    :param s:
    :type s: str

    """
    upper = lower = mark = space = digit = sum = 0
    if s == "":
        space += 1
    for char in s:
        if char.isupper():
            upper += 1
        elif char.islower():
            lower += 1
        elif char.isspace():
            space += 1
        elif char.isdigit():
            digit += 1
        else:
            mark += 1
    sum = upper + lower + mark + space + digit
    print(f"The text contains {sum} characters:")
    print(f"{upper} upper letters")
    print(f"{lower} lower letters")
    print(f"{mark} punctuation marks")
    print(f"{space} spaces")
    print(f"{digit} digits")


def main():
    """
    Display informations about user input or given argument.
    """
    try:
        assert len(sys.argv) <= 2, "more than one argument is provided"
    except AssertionError as error:
        print(f"AssertionError: {error}")
        sys.exit(1)
    if (len(sys.argv) == 1):
        try:
            user_input = input("What is the text to count?\n")
        except EOFError:
            user_input = ("")
        count_items(user_input)
    else:
        count_items(sys.argv[1])


if __name__ == "__main__":
    main()
