from load_image import ft_load
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt


def main():
    image_array = ft_load("animal.jpeg")
    if image_array is None:
        return
    print(image_array)
    image_array = image_array[300:400, 300:400]
    print (f"New shape after slicing: {image_array.shape}")
    print(image_array)
    image = Image.fromarray(image_array)
    image.show()

    return


if __name__ == "__main__":
    main()