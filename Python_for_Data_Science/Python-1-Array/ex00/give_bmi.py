def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """
    Calculate the BMI for two lists of heights and weights.

    Returns a list of BMI values.
    Returns None if:
    - The lists are not the same length
    - Any element in the lists is not an int or float

    :param height: list of heights in meters (int or float)
    :param weight: list of weights in kilograms (int or float)
    :return: list of BMI value or None
    """
    if len(height) != len(weight):
        return None
    if not all(isinstance(h, (int, float)) for h in height):
        return None
    if not all(isinstance(w, (int, float)) for w in weight):
        return None
    result = []
    for h, w in zip(height, weight):
        if h == 0:
            result.append(0)
        else:
            result.append(w / (h ** 2))

    return result


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    Compare each value in a list with a limit.

    Returns a list of booleans: True if the value
    is above the limit, False otherwise.

    Returns None if the input list contains non-int/float elements.

    :param bmi: list of numbers (int or float)
    :param limit: threshold value to compare against
    :return: list of booleans or None
    """
    if not all(isinstance(x, (int, float)) for x in bmi):
        return None
    result = []
    for x in bmi:
        result.append(x > limit)
    return result
