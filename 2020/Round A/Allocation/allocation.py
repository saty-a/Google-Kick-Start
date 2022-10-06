if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, b = map(int, input().split())
        a = list(map(int, input().split()))
        a.sort()
        count = 0
        for i in a:
            if i <= b:
                b -= i
                count += 1
            else:
                break
        print(f"Case #{_+1}: {count}")
