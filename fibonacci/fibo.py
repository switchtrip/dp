def fibo_recursion(n):
    assert n >= 0
    if n == 0:return 0
    if n == 1:return 1
    return fibo_recursion(n-1) + fibo_recursion(n-2)

def fibo_memoization(n):
    assert n>=0
    ans = [0, 1]
    for i in range(2, n+1):
        ans.append(ans[i-1] + ans[i-2])
    return ans[n]

def fibo_swapping(n):
    assert n>=0
    if  n==0:return 0
    curr, prev = 1, 0
    for i in range(1, n):
        newval = curr + prev
        prev = curr
        curr = newval
    return curr

print(fibo_recursion(34))
print(fibo_memoization(34))
print(fibo_swapping(34))
