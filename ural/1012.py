import sys

def mult(a, b):
    ret = []
    for i in range(len(a)):
        _temp = []
        for j in range(len(b[0])):
            temp = 0
            for k in range(len(a[0])):
                temp = (temp + a[i][k] * b[k][j])
            _temp.append(temp)
        ret.append(_temp)
    return ret

def unit(size):
    ret = []
    for i in range(size):
        ret.append([0] * size)

    for i in range(size):
        ret[i][i] = 1
    return ret

def pow(mat, n):
    ret = unit(len(mat))

    pat = list(bin(n)[2:])
    pat.reverse()
    for i in pat:
        if i == '1':
            ret = mult(mat, ret)
        mat = mult(mat, mat)

    return ret

(n, k) = map(lambda x: int(x.strip('\n')),(sys.stdin).readlines())
mat = [[k-1, k-1], [1, 0]]
# print n, k, m
base = [[k-1], [1]]
print mult(pow(mat, n-1), base)[0][0]
