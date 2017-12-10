"""
    Задача "Писатель - Читатель"
"""


from multiprocessing import (
    Process,
    Queue
)


# Функция процесса - писателя
def writer(queue):
    print("Процесс-писатель готов !")
    while True:
        if queue.full():
            continue
        try:
            number = int(input())
            queue.put(number)
        except ValueError:
            break
    print("Поток-писатель завершается !")


# Функция процесса - читателя
def reader(queue):
    print("Процесс-читатель готов !")
    while True:
        if queue.empty():
            continue
        number = queue.get()
        print("{0} ** 2 == {1}".format(number, number ** 2))


# Создание канала связи для процессов
queue = Queue(10)

# Запуск процесса - читателя
process_reader = Process(target=reader, args=(queue, ))
process_reader.start()

# Работа процесса - писателя
writer(queue)
process_reader.terminate()
print("Процесс-читатель завершается !")
