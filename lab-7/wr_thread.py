"""
    2. Процесс писатель записывает содержимое некоторого файла.
    Процессы - читатели считывают данные, записанные процессом - писателем.
    Необходимо обеспечить взаимное исключение доступа
    к данным писателя и любого из читателей.
    Предполагаются следующие варианты задачи:
    * синхронизация с помощью семафоров
    * обмен данными через общую память
    * программные каналы или очереди.
"""


from threading import (
    Thread,
    Lock
)


def reader(file_name, thread_number):
    global is_terminate
    global lock
    print("### Чтец {0} готов!\n".format(thread_number))
    with open(file_name, "r") as f:
        while True:
            if is_terminate:
                break
            with lock:
                line = f.readline().strip()
            if line == "":
                continue
            print(">>> Чтец {0}: {1}".format(thread_number, line.encode()))
    print("### Чтец {0} завершается!\n".format(thread_number))


def writer(file_name):
    global is_terminate
    global lock
    print("### Писатель готов!\n")
    with open(file_name, "a") as f:
        while True:
            try:
                line = input()
                with lock:
                    f.write(line + "\n")
                    f.flush()
            except KeyboardInterrupt:
                is_terminate = True
                break
    print("### Писатель завершается!\n")


# Файл для записи и чтения строк
FILE_NAME = "test.txt"

# Количество потоков-чтецов
READER_COUNT = 3


# Признак завершения всех потоков
is_terminate = False

# Блокировка
lock = Lock()


# Создание файла
open(FILE_NAME, "w").close()


# Создание потоков-чтецов
threads_reader_list = []
for i in range(READER_COUNT):
    threads_reader_list.append(Thread(target=reader, args=(FILE_NAME, i + 1)))
    threads_reader_list[i].start()

# Начать процес записи
writer(FILE_NAME)

# Ожидание завершения остальных потоков
for thread_reader in threads_reader_list:
    thread_reader.join()
