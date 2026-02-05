import sys
from ft_filter import ft_filter


def is_len_greater(s, num):
    """
    Returns True if len(s) is higher than num.
    """
    return len(s) > num


def main():
    """
    The program display a list of words from first argument that
    have a len greater than the second argument.\n
    First argument must be a string, words are separated by space character.\n
    Second argument must be a number.
    """
    try:
        if len(sys.argv) != 3:
            raise AssertionError("the arguments are bad")
        av1 = sys.argv[1].split()
        av2 = int(sys.argv[2])
        valid_words = ft_filter(lambda s: is_len_greater(s, av2), av1)
        my_list = [word for word in valid_words]
        print(my_list)
    except AssertionError as err:
        print(f"AssertionError : {err}")
    except ValueError as err:
        print(f"ValueError : {err}")
    return


if __name__ == "__main__":
    main()
