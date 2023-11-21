#Write an R program to create a simple bar plot of five subject’s marks.
marks <- c(57,75,90,85,79,95)
subject <- c('hr','ac','wt','rdbms','bm','lab')
barplot(marks,names.arg = subject,main = '5 subject marks',xlab = 'subject',ylab = 'marks',col = 'powderblue')
bar