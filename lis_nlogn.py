SIZE = 100
q = [ 0 ] * SIZE
p = [ 0 ] * SIZE
sol = [ 0 ] * SIZE
NR = 0
INF = 90000009
vec = [ 5,7,1,20,4,-6,-8,-9,2,12,10,11,8,0,30 ]
N = len(vec)
 
def insert(val, left, right):
 
    global NR
 
    m = (left + right ) // 2
 
    if(left == right):
 
        if right > NR:
            NR += 1
            q[ NR + 1 ] = INF
        q[left] = val
        return left
    else:
        if val <= q[m]:
            return insert(val, left, m)
        else:
            return insert(val, m + 1, right)
def main():
 
    for i in range(1, N):
        p[ i ] = insert(vec[i], 1, NR + 1)
 
    k = N - 1
    i = NR
    while(i != 0):
 
        while(p[k] != i):
           k -=1
        sol[i] = vec[k]
        i -= 1
    print("Longest Increasing Subsequence\nTime Complexity N Log N\nLength -> ", NR, "\nSubsequence -> ", end = " ")
    for i in range(1, NR+1):
        print(sol[i],end = " ")
    print("")
 
main()
