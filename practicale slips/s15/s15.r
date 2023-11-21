#Write an R program to extract the five of the levels of factor created from a random 
#sample from the LETTERS
v <- c('a','b','c','d','a','c','s','t','s')
f <-factor(v)
print(head(levels(f)[1:5]))