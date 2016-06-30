from multiprocessing.pool import ThreadPool
import datetime
import requests
import itertools


def f(x, y, z):
    return x + y + z


def fs(x_y):
    return f(*x_y)

if __name__ == '__main__':
    t1 = datetime.datetime.now()
    p = ThreadPool(processes=5)
    l1 = [1, 2, 3]
    l2 = [4, 5, 6]
    zl = zip(l1, l2)
    l3 = [7, 8, 9]
    zll = zip(l1, l2, itertools.repeat(1))
    m = p.map(fs, zll)
    print m
