inp = int(input())
for i in range(inp):
    word = input()
    strr = '';
    if(len(word) > 10):
        strr+= word[0];
        strr += str(len(word)-2)
        strr += word[-1]
        print(strr)
    else:
        print(word)