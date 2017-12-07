

class TaskManager:
    def __init__(self) -> None:
        self.__current_task = 0

    def show_title(self):
        '''Show Task Title'''

        self.__current_task += 1
        print(f"\nЗадание {self.__current_task}")
