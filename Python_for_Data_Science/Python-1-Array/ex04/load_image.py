import numpy as np
from array import array
from PIL import Image


def ft_load(path: str) -> array:
    """
    Load an image and return its pixels as an array.

    Returns a array in RGB format.
    Returns None if there is any problem with the file.

    :param path: path to the image file
    :return: array of pixels or None
    """
    try:
        image = Image.open(path, "r")
        image = image.convert("RGB")
    except Exception:
        print("Error file")
        return None
    rgb = 3
    width, height = image.size
    pixel_values = list(image.getdata())
    arr = np.array(pixel_values)
    arr = arr.reshape((height, width, rgb))
    print(f"The shape of image is: {arr.shape}")
    return arr
