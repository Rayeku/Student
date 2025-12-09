import sys


NESTED_MORSED = {" ": "/ ", "A": ".- ", "B": "-... ", "C": "-.-. ",
                 "D": "-.. ", "E": ". ", "F": "..-. ", "G": "--. ",
                 "H": ".... ", "I": ".. ", "J": ".--- ", "K": "-.- ",
                 "L": ".-.. ", "M": "-- ", "N": "-. ", "O": "--- ",
                 "P": ".--. ", "Q": "--.- ", "R": ".-. ", "S": "... ",
                 "T": "- ", "U": "..- ", "V": "...- ", "W": ".-- ",
                 "X": "-..- ", "Y": "-.-- ", "Z": "--.. ", "0": "----- ",
                 "1": ".---- ", "2": "..--- ", "3": "...-- ",
                 "4": "....- ", "5": "..... ", "6": "-.... ",
                 "7": "--... ", "8": "---.. ", "9": "----. "
                 }


def main():
    """
    This program displays the string given
    as an argument in its Morse code form.
    """
    try:
        if (len(sys.argv) != 2 or not sys.argv[1].isalnum() and not " "):
            raise AssertionError("the arguments are bad")
        s = sys.argv[1]
        if s is not str:
            raise AssertionError("the arguments are bad")
        morsed_code = ""
        for char in s:
            morsed_code += NESTED_MORSED.get(char.capitalize())
        print(morsed_code[:-1])
    except AssertionError as error:
        print(f"AssertionError : {error}")
    return


if __name__ == "__main__":
    main()
