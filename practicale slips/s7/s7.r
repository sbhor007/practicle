#Write an R program to create a Dataframes which contain details of 5 employees and display the details in ascending order
employee <- data.frame(
  emp_id = c(100:104),
  emp_name = c('santosh','yash','dipak','yogesh','shivam')
)
print(employee[order(employee$emp_name),])