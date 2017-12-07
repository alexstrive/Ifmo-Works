from PIL import Image


class ImageReader:
    def __init__(self, image_path="./", image_name="image", image_type="jpg") -> None:
        self.__image_path = image_path
        self.__image_name = image_name
        self.__image_type = image_type
        self.__original_image = Image.open(self.__image_path + self.__image_name + "." + self.__image_type)

    def read_image(self):
        return self.__original_image.load()

    def get_size(self):
        return self.__original_image.size
