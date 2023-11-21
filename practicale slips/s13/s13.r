#Consider the inbuilt iris dataset
#i) Create a variable “y” and attach to it the output attribute of the “iris” dataset.
#ii) Create a barplot to breakdown your output attribute. 
#iii) Create a density plot matrix for each attribute by class value.

data("iris")

y<- iris$Species

barplot(table(y),main = "Breakdown of species",xlab = "species",ylab = "count", col = "red")

library(ggplot2)
ggplot(iris, aes(x = Sepal.Length, fill = Species)) +
  geom_density(alpha = 0.6) +
  labs(title = "Density Plot of Sepal Length by Species")

ggplot(iris, aes(x = Sepal.Width, fill = Species)) +
  geom_density(alpha = 0.6) +
  labs(title = "Density Plot of Sepal Width by Species")

ggplot(iris, aes(x = Petal.Length, fill = Species)) +
  geom_density(alpha = 0.6) +
  labs(title = "Density Plot of Petal Length by Species")

ggplot(iris, aes(x = Petal.Width, fill = Species)) +
  geom_density(alpha = 0.6) +
  labs(title = "Density Plot of Petal Width by Species")