import numpy as np

'''Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s 
telephone number. Make use of two collision handling techniques and compare them using number of comparisons required 
to find a set of telephone numbers. '''


class A:
    def __init__(self, size):
        self.size = size
        self.name = np.array([None] * self.size)
        self.num = np.array([0] * self.size)
        self.probe = np.array([0] * self.size)

    def insert(self, name, no):
        _sum = 0
        p, m = 1, 0
        for i in range(len(name)):
            _sum = _sum + ord(name[i])
            i += 1

        x = (_sum / len(name)) % 10
        c = x
        y = int(x)
        while self.num[y] != 0:
            for i in range(y, self.size + 1):
                if self.num[i] != 0:
                    y += 1
                    if y == 10:
                        y = 0
                    break
                p += 1
                i += 1
            y = (y + 1) % 10

            p += 1
            m += 1
            if m == 10:
                break
        if m == 10:
            print("Hash Table Full")
        else:
            if self.num[y] == 0:
                self.num[y] = no
                self.probe[y] = p
                self.name[y] = name

    def delete(self, name):
        _sum = 0
        n = 0
        for i in range(len(name)):
            _sum = _sum + ord(name[i])
        x = (_sum / len(name)) % 10
        c = x
        y = int(x)
        while n != 10:
            n += 1
            if self.num[y] == 0:
                print("No element")
                break
            elif self.name[y] == name:
                self.num[y] = 0
                self.probe[y] = 0
                self.name[y] = None
                print("Element Deleted")
                break
            else:
                y = int((y + 1) % 10)
        if n == 10:
            n -= 1
            print("Not Found")

    def display(self):
        print("Hash Table\nIndex\tName\tNumber\tProbe\n")
        for i in range(self.size):
            print(i, "\t", self.name[i], "\t", self.num[i], "\t", self.probe[i], "\n")

    def search(self, name):
        j = 99
        for i in range(self.size):
            if self.name[i] == name:
                j = i
            else:
                continue
        if j != 99:
            print("No.: ", self.num[j])


class B:

    def __init__(self, size):
        self.size = size
        self.name = np.array([None] * self.size)
        self.num = np.array([0] * self.size)
        self.probe = np.array([0] * self.size)

    def insert(self, name, no):
        _sum, m, l, p = 0, 0, 1, 1
        for i in range(len(name)):
            _sum = _sum + ord(name[i])
            i += 1
        x = (_sum / len(name)) % 10
        c = int(x)
        y = int(x)
        while self.num[y] != 0:
            for i in range(y, self.size):
                if self.num[i] != 0:
                    y += 1
                    if y == 10:
                        y = 0
                    break
                p += 1
                i += 1
            y = int((c + (l * l)) % 10)
            l += 1
            m += 1
            p += 1
            if m == 10:
                break
        if m == 10:
            print("Hash Full")
        else:
            if self.num[y] == 0:
                self.num[y] = no
                self.probe[y] = p
                self.name[y] = name

    def delete(self, name):
        _sum = 0
        n = 0
        for i in range(len(name)):
            _sum = _sum + ord(name[i])
        x = (_sum / len(name)) % 10
        c = x
        l = 1
        y = int(x)
        while n != 10:
            n += 1
            if self.num[y] == 0 and self.name[y] == name:
                print("No element")
                break
            elif self.name[y] == name:
                self.num[y] = 0
                self.probe[y] = 0
                self.name[y] = None
                print("Element Deleted")
                break
            else:
                h = 1
                x = int((c + (h * h)) % 10)
                y = int(x)
                l += 1
                h = l
        if n == 10:
            n -= 1
            print("Not Found")

    def display(self):
        print("Hash Table\nIndex\tName\tNumber\tProbe\n")
        for i in range(self.size):
            print(i, "\t", self.name[i], "\t", self.num[i], "\t", self.probe[i], "\n")

    def search(self, name):
        j = 0
        for i in range(self.size):
            if self.name[i] == name:
                j = i
            else:
                continue
        if j != 0:
            print("No.: ", self.num[j])


if __name__ == "__main__":
    print("1. Insert\n2. Delete\n3. Display\n4. Find\n5. Insert using Quadratic Probing\n6. Delete using Quadratic "
          "Probing\n7. Display using Quadratic Probing\n8. Find using Quadratic Probing")

    a = A(10)
    b = B(10)
    while 1:
        ch = int(input("Choice: "))
        if ch == 1:
            x = input("Name: ")
            y = int(input("No.: "))
            a.insert(x, y)
        elif ch == 2:
            x = input("Name: ")
            a.delete(x)
        elif ch == 3:
            a.display()
        elif ch == 4:
            x = input("Name: ")
            a.search(x)
        elif ch == 5:
            x = input("Name: ")
            y = input("No.: ")
            b.insert(x, y)
        elif ch == 6:
            x = input("Name: ")
            b.delete(x)
        elif ch == 7:
            b.display()
        elif ch == 8:
            x = input("Name: ")
            b.search(x)
