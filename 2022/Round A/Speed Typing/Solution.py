t = int(input())
for q in range(t):
    i = input()
    p = input()
    n = len(i)
    m = len(p)
    k = 0
    j = 0
    count = 0
    
    while k<n and j<m:
  
        if p[j]==i[k]:
            j+=1
            k+=1
        else:
            count+=1
            j+=1
    if j<m:
        count+=m-j
    
    if k<n or n>m:
        print(f"Case #{q+1}: IMPOSSIBLE")
    else:
        print(f"Case #{q+1}: {count}")