# cook your dish here

a, b, c, d = map(int, input().split())

strr = input()
sum = 0
count = 1
for i in strr:
    if(1 == int(i)):
       sum += a 
    elif(2 == int(i)):
        sum += b
    elif(3 == int(i)):
        sum += c
    else:
        sum += d
    count+=1
print(sum)