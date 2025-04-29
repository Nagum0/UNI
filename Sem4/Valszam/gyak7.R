# 7. feladatsor

# 7.1 Feladat

x <- sample(1:6, 1000, rep=TRUE)
mean(x)

getmode <- function(v) {
  uniqv <- unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}
getmode(x)

median(x)
quantile(x, 1/2, type=4)
mom2 <-mean(x^2)
mom2
mom3 <-mean(x^3)
mom3
# sd korrigál!!
sd(x)
range(x)
quantile(x, 1/4)
quantile(x, 3/4)
plot(ecdf(x))
boxplot(x)
hist(x)
max(x)-min(x)



# 7.2 feladat

x <- rexp(1000, rate=3)
mean(x)

getmode <- function(v) {
  uniqv <- unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}
getmode(x)

median(x)
quantile(x, 1/2, type=4)
mom2 <-mean(x^2)
mom2
mom3 <-mean(x^3)
mom3
# sd korrigál!!
sd(x)
range(x)
max(x)-min(x)
quantile(x, 1/4)
quantile(x, 3/4)
plot(ecdf(x))
lines(-1000:1000/100, pexp(-1000:1000/100, 2), col = "blue", lwd= 2, type='l')
boxplot(x)
hist(x, freq = FALSE)
lines(0:300/100,dexp(0:300/100, 3), col = "blue", lwd= 2, type='l')

