"""
    Задача "Писатель - Читатель"
"""


from threading import Thread
from buffer import Buffer


# Функция потока - писатель
def writer(buffer):
    global is_terminate
    print("Поток-писатель готов !")
    while True:
        # === Блокировка записи в буфер ===
        if buffer.is_full():
            continue
        # =================================
        try:
            number = int(input())
            buffer.add(number)
        except ValueError:
            is_terminate = True
            break
    print("Поток-писатель завершается !")


# Функция потока - читателя
def reader(buffer):
    global terminate
    print("Поток-читатель готов !")
    while True:
        if is_terminate:
            break
        # === Блокировка чтения из буфера ===
        if buffer.is_empty():
            continue
        # =================================
        number = buffer.get()
        print("{0} ** 2 == {1}".format(number, number ** 2))
    print("Поток-читатель завершается !")


# Общий буфер чисел
buffer = Buffer(10)

# Признак завершения работы потока
is_terminate = False

# Запуск потока-читателя
thread_reader = Thread(target=reader, args=(buffer, ))
thread_reader.start()

# Работа потока - писателя
writer(buffer)
thread_reader.join()
