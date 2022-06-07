import matplotlib.pyplot as plt
import math

out = open("output.txt", "w")

def func(k):
    return 4 * k + 1

def isPrime(x):
    k = 2
    while k * k <= x and x % k != 0:
        k += 1
    return k * k > x

def counter(p):
    print(p, ":", sep = "", file = out)
    cnt = 0
    for x in range(0, int(math.sqrt(p)) + 1):
        for y in range(0, int(math.sqrt(p)) + 1):
            if x * x + y * y == p:
                print(x, y, file = out)
                cnt += 1
    print("---", file = out)
    return cnt

p_max = 1000

p = [func(k) for k in range(0, (p_max - 1) // 4 + 1) if isPrime(func(k))]
cnt = [counter(t) for t in p]

plt.title("Функция зависимости количества решений от числа p")
plt.xlabel("Простое число p")
plt.ylabel("Количество решений уравнения x^2 + y^2 = p")
plt.plot(p, cnt, ".")
plt.show()

out.close()
