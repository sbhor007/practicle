#Write a script in R to create two vectors of different lengths and give these vectors as 
#input to array and print addition and subtraction of those matrices.
vec1 <- c(1:10)
vec2 <- c(8:18)
arr1 <- array(vec1,dim = c(5,3))
arr2 <- array(vec2,dim = c(5,3))
print("first array : ")
print(arr1)
print("Second array : ")
print(arr2)

print("Addition of two array : ")
addition_result <-arr1 + arr2
print(addition_result)

print("substraction of two array : ")
subtraction_result <- arr1 - arr2
print(subtraction_result)
