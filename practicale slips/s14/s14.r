#Write an R program to concatenate two given factor in a single factor and display in 
#descending order

factor1 <- factor(c('A','S','F','N'))
factor2 <- factor(c('B','R','C','P'))
factor3 <- factor(c(factor1,factor2))
print("\nConcate two factos ")
print(factor3)
print('sorting')
print(sort(factor3, decreasing = TRUE))