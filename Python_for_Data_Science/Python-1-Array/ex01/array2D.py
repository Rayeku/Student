import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """
    Truncate a 2D list.

    Prints the original shape and the new shape after slicing.
    Returns a newly shaped list.

    Returns None if:
    - family is not a list
    - start or `end` are not integers

    :param family: 2D list
    :param start: starting row index (inclusive)
    :param end: ending row index (exclusive)
    :return: truncated 2D list or None
    """
    if not isinstance(family, list):
        return None
    if not isinstance(start, int) or not isinstance(end, int):
        return None
    arr = np.array(family)
    print(f"My shape is : {arr.shape}")
    arr = arr[start:end]
    print(f"My new shape is : {arr.shape}")
    return arr.tolist()
