
def bubble_sort(arr,n):
    for i in range(n-1):
        for j in range(n-1-i):
            if(arr[j] > arr[j+1]):
               temp = arr[j+1]
               arr[j+1] = arr[j]
               arr[j] = temp
     


lst = [7,6,4,3,2]
bubble_sort(lst,len(lst))
print(lst)
