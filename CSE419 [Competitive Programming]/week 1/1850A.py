# cook your dish here
inp = int(input())
for i in range(inp):
    # lst = int(input().split(" "))
    a, b, c = map(int, input().split())
    lst = [a,b,c]
    mx = max(lst)
    lst.remove(mx)
    if(mx + max(lst) >= 10):
        print("YES")
    else:
        print("NO")


