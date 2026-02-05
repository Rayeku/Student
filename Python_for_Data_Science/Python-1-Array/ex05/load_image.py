from typing import Optional
from PIL import Image
import numpy as np


def ft_load(path: str) -> Optional[np.ndarray]:
    """
    Load an image and return its pixels as a 3D array.

    Returns an array in RGB format.
    Returns None if there is any problem with the file.

    :param path: path to the image file
    :return: array of pixels or None
    """
    try:
        image = Image.open(path, "r")
        image = image.convert("RGB")
    except Exception:
        print("Error: error file")
        return None
    arr = np.array(image)
    print(f"The shape of image is: {arr.shape}")
    return arr
