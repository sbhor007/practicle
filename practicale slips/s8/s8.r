
vector1 <- c("A","B","C","E","A","B","C")
vector2 <- c(1,2,3,4,1,2,3)

data_frame <- data.frame(vector1,vector2)
print("original data frame : ")
print(data_frame)

print("duplicate values : ")
print(data_frame[duplicated(data_frame),])

print("unique elements : ")
print(unique(data_frame))