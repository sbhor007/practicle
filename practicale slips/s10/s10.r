#Write a script in R to create a list of cities and perform the following 
#1) Give names to the elements in the list.
#2) Add an element at the end of the list.
#3) Remove the last element.
#4) Update the 3rd Element

citis <- list("nashik","pune","mumbai","thane")
print(citis)

#1) Give names to the elements in the list.
names(citis) <- c("citi1","citi2","citi3","citi4")
print("safter five name to the elements : ");
print(citis)

#2) Add an element at the end of the list.
#citis[length(citis)+1] = "nanded"
citis <- c(citis,"nanded")
print("after adding new city : ")
print(citis)

#3) Remove the last element.
citis <- citis[-length(citis)]
print("after remove last element : ")
print(citis)

#4) Update the 3rd Element

citis["citi3"] <- "New york"
print("after updating 3rd city ")
print(citis)