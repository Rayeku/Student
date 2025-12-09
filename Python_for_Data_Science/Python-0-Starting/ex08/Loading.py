import os
import sys
import time


def ft_tqdm(lst: range) -> None:
    """
    Display a loading bar on the terminal for the given iterable.

    :param lst:
    :type lst: range
    """
    try:
        sys.stdout.write("\033[?25l")
        start = time.time()
        total = len(lst)
        pipe_len = 2
        # pct_display = 0
        n_display = eta = speed = 0
        terminal_width = os.get_terminal_size().columns
        for x in lst:
            n = x + 1
            pct = n / total * 100
            passed_t = time.time() - start
            passed_t_str = time.strftime("%M:%S", time.gmtime(passed_t))
            speed = n / passed_t
            eta = total / speed - passed_t
            eta_str = time.strftime("%M:%S", time.gmtime(eta))
            # if (pct.__round__() % 6 == 0):
            #     pct_display = pct
            if (n % 20 == 0):
                n_display = n
            l_info = f"\r{pct.__round__():>3.0f}%"
            r_info = f"{n_display}/{total} " \
                f"[{passed_t_str}<{eta_str}, {speed:.2f}it/s]"
            bar_width = terminal_width - len(l_info) - len(r_info) - pipe_len
            bar_length = max(int(bar_width * n / total), 1)
            progress_bar = '█' * bar_length + ' ' * (bar_width - bar_length)
            line = f"{l_info}|{progress_bar}| {r_info}"
            line = line[:terminal_width + 1]
            print(f"\r{line:<{terminal_width}}", end="")
            yield x
        r_info = f"{n}/{total} [{passed_t_str}<00:00, {speed:.2f}it/s]"
        line = f"{l_info}|{progress_bar}| {r_info}"
        line = line[:terminal_width + 1]
        print(f"\r{line:<{terminal_width}}", end="\n")
    finally:
        sys.stdout.write("\033[?25h")
