# Write an R program to sort a Vector in ascending and descending order.
vec <- c(3,6,2,1,8,9,4,5,7)
cat('original vecter is : ',vec,'\n')
print('Sorted vecter for ascending order : ')
print(sort(vec))
print('Sorted vecter for decending order : ')
print(sort(vec ,decreasing = TRUE))
