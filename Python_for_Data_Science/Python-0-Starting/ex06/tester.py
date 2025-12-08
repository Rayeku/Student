from ft_filter import ft_filter


def is_even(num):
    return num % 2 == 0


def is_higher_than_zero(num):
    if (num > 10):
        return True
    else:
        return False


test1 = (1, 5, 10, 30, 100, 0, 2)
test2 = (0, -12, 56, 10, 100, -20)

print("filter :", list(filter(is_even, test1)))
print("ft_filter:", list(ft_filter(is_even, test1)))

print("filter:", list(filter(is_higher_than_zero, test2)))
print("ft_filter:", list(ft_filter(is_higher_than_zero, test2)))
