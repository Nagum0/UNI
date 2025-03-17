##########################################
###   2. Laboros gyakorlat (3-4 hét)   ###
##########################################


#########################################################
################## Eloszlásfüggvény #####################
#########################################################

# Az X valószínűségi változó eloszlásfüggvénye: F(x) = P(X < x)
# Az eloszlásfüggvény tulajdonságai: 
#   0 <= F(x) <= 1
#   monoton növő
#   balról folytonos
#   lim_{x to -Inf} F(x) = 0, lim_{x to Inf} F(x) = 1


# 1. Mi a kockadobás (elméleti) eloszlásfüggvénye?  Írja fel és ábrázolja a függvényt!

x <- 1:6
xx <- c(x,1:3)
trueF <- ecdf(x)
trueG <- ecdf(xx)

plot(trueF, do.points=FALSE, 
     col=4, lwd=2, main='Elméleti eloszlásfüggvény', ylab = "F(x)")
plot(trueG, do.points=FALSE, 
     col=4, lwd=2, main='Elméleti eloszlásfüggvény', ylab = "F(x)")
# mit jelent a do.points=FALSE? 
# ha nincs (azaz do.points=TRUE): jobbról folytonos,
# de az eloszlásfüggvény balról folytonos:

plot(trueF, do.points = FALSE, col=4, lwd=2, ylab='F(x)',
     main="Kockadobás eloszl?sfüggvénye (balról folytonos)\n (értéke pl. 4-ben: F(4) = P(X < 4) = P(X <= 3) =\n ecdf(1:6)(3) = 0.5)")
points(unique(x), unique(c(0, trueF(x)))[1:length(unique(x))], pch=19, col=4)
points(unique(x), unique(trueF(x)), pch=21, col=5)

abline(v = 4, lty = 3)
abline(h = trueF(3), lty = 3)

# Megjegyzés: ezt az eloszlásfv.-t ki lehet az alábbi utasításokkal (ld. 2-es feladat) 
# is rajzolni, ha: n <- 6; x <- -1:6+1; Fn <- c(0,1/6,2/6,3/6,4/6,5/6,6/6,1)


##################################################################################
################## Abszolút folytonos valószínűségi változók #####################
##################################################################################

# Példa: egyenletes eloszlás
# Véletlenszerűen kiválasztunk egy pontot az [a,b] intervallumból.
# Annak a valószínűsége, hogy a kiválasztott pont az E része [a,b] halmazba esik:
# P(E) = E hossza / [a, b] hossza       (ha az E halmaznak van hossza)
# 
# A valószínűségeloszlás jellemezhető az f: R -> R, D(f) = R,
# f(x) = 1/(b-a), ha x eleme [a,b] és  
#         0,      ha x nem eleme [a,b]
# függvénnyel így, hogy P(E) = integral f (az E halmazon).
#
# Vagyis ha egy véges intervallumra így dobunk egy pontot, hogy az intervallum bármely 
# részintervallumára annak hosszával arányos valószínűséggel essen, akkor a pont 
# Értéke (x-koordinátája) egyenletes eloszlású valószínűségi változó, 
# sűrűségfüggvénye a fenti f, eloszlásfüggvénye:
# F(x) =  0,          ha x<a
#        (x-a)/(b-a), ha x eleme [a,b] 
#         1,          ha x>b


# Abszolót folytonos valószínűségi változó: 
#
# Ha létezik olyan f függvény, amelyre F(x) = integr?l_{-Inf to x} f(t) dt.
# Ilyenkor f-et sűrűségfüggvénynek hívjuk. 

############################################################################# 

##########################
## Egyenletes eloszlás: ##
## Egyenletes[a,b]      ##
##########################

x<-rbinom(1000,100, 0.3)
y <- cumsum(x)/1:1000

plot(1:1000, y, t='l')
# Egyenletes[1,6] eloszlásfüggvénye
xegyen <- seq(0, 7, by = 1)
yegyen <- punif(xegyen, min = 1, max = 6)
plot(yegyen, type = "l", lwd=2, col="red", xaxt = "n",
     xlab="x", ylab="F(x)",
     main="Egyenletes[1,6] eloszlásfüggvénye")
axis(1, at=1:8, labels=c(0:7))
abline(h = 0, col = "grey", lty = 2); abline(h = 1, col = "grey", lty = 2)

# Egyenletes[1,6] sűrűségfüggvénye
x <- seq(0,7,length=200)
y <- dunif(x,min=1,max=6)
plot(x,y,
     lwd=2, col="blue",
     ylim=c(0, 0.4),
     ylab="f(x)",
     main="Egyenletes[1,6] sűrűségfüggvénye")

# Egyenletes[1,6] sűrűségfüggvénye (szebb grafika)
x <- seq(1,6,length=200)
y <- dunif(x,min=1,max=6)
plot(x,y, type="l", lwd=2, col="blue",
     xlim=c(0, 7), ylim=c(0, 0.4),
     ylab="f(x)",
     main="Egyenletes[1,6] sűrűségfüggvénye")
xe <- c(seq(0,1,length=100))
ye <- seq(0,0,length=100)
lines(xe,ye,type="l",lwd=2,col="blue")
xe <- c(seq(6,7,length=100))
ye <- seq(0,0,length=100)
lines(xe,ye,type="l",lwd=2,col="blue")

# fv. alatti terület = 1
polygon(c(1,x,6),c(0,y,0),col="lightgray",border=NA)
lines(x,y,type="l",lwd=2,col="blue")

# P(1 < X < 3) = ?
polygon(c(1,x,6),c(0,y,0),col="white",border=NA)
lines(x,y,type="l",lwd=2,col="blue")
xvsz <- seq(1,3,length=100)
yvsz <- dunif(xvsz, min=1, max=6)
polygon(c(1,xvsz,3),c(0,yvsz,0),col="lightgray",border=NA)
lines(xvsz,yvsz,type="l",lwd=2,col="red")

punif(3,  min=1,max=6)
punif(1,  min=1,max=6)

# P(3 < X < 4.5) = ?
polygon(c(1,xvsz,3),c(0,yvsz,0),col="white",border=NA)
lines(x,y,type="l",lwd=2,col="blue")
xvsz <- seq(3,4.5,length=100)
yvsz <- dunif(xvsz,min=1, max=6)
polygon(c(3,xvsz,4.5),c(0,yvsz,0),col="lightgray",border=NA)
lines(xvsz ,yvsz,type="l",lwd=2,col="red")

punif(4.5,  min=1,max=6) - punif(3, min=1, max=6)


#############################
## Exponenciális eloszlás: ##
## Exp(lambda)             ##
#############################
# lambda>0 paraméterű exponenciális eloszlás
# sűrűségfüggvénye: f(x) = lambda*e^{-lambda*x} ha x > 0 ?s
#                           0       különben
# pl. radioaktív részecske bomlási ideje, élettarmtam, várakozási idő
?pexp

x <- seq(0,7,length=200)
y1 <- dexp(x, r=1)
y2 <- dexp(x, r=2)
y3 <- dexp(x, r=3)
plot(x,y1,
     type='l',
     lwd=2, col="blue",
     ylab="f(x)",
     main="Exponenciális(1)")
plot(x,y2,
     type='l',
     lwd=2, col="red",
     ylab="f(x)",
     main="Exponenciális(1)")



############################################
### Kitekintés:                          ###
###    Histogram: Airquality adathalmaz  ###
############################################
# check built-in datasets: airquality$Temp
# https://stat.ethz.ch/R-manual/R-devel/library/datasets/html/00Index.html
head(airquality)
h <- hist(airquality$Temp, #breaks=seq(50,100,2), #breaks=seq(50,100,10),
          col="red",
          xlab="hőmérséklet (F)", 
          ylab="gyakoriság", 
          main="Hőmérséklet hisztogram (airquality)")
h$breaks
h$counts
hist(airquality$Temp, freq=FALSE,
     col="blue",
     xlab="hőmérséklet (F)",
     ylab="sűrűség", 
     main="Hőmérséklet hisztogram (airquality)")
lines(density(airquality$Temp), lwd = 2, col = "red")
############################################


##########################
## Normális eloszlás:   ##
## N(mu, szigma)        ##
##########################
# m várható értéke, szigma szórású normális eloszlás
# sűrűségfüggvénye: f(x) = 1/(sqrt(2Pi)*szigma) e^(-(x-mu)^2/2*szigma^2)
# Pl. testmértékek, terméshozam, IQ score
# https://en.wikipedia.org/wiki/Intelligence_quotient
# 0 várható értékű, szigma=1 szórású normális eloszlás = standard normális eloszlás,
# eloszlásfüggvénye Fi(x) = integrál_(-Inf to x) f(x)  nem elemi fv.

# 3.  # set.seed(2)
xseq <- seq(-4,4, 0.01)

# a) Ábrázolja a standard normális eloszlásfüggvényt!
# X ~ N(0, 1) eloszlásfüggvénye: Fi(x) = P(X < x) = pnorm(x)

plot(xseq, pnorm(xseq, 0, 1), col="red", type="l",lwd=2,
     xlab="x", ylab="Fi(x)", 
     main="Standard normális eloszlásfüggvénye\n (Értéke pl. 1-ben: Fi(1) = P(X < 1) =\n pnorm(1) = 0.8413447)")
abline(h = c(0,1), lty = 2)

abline(v = 1, lty = 3)
abline(h = pnorm(1), lty = 3)



# b) Ábrázolja a standard normális eloszlás sűrűségfüggvényét!

suruseg <- dnorm(xseq, 0,1)
plot(xseq, suruseg, type="l",lwd=2, col="blue", # cex.axis=0.8,
     xlab="x", ylab="f(x)",  
     main="Standard normális sűrűségfüggvénye")

# c) Normális(mu, szigma) eloszlás sűrűségfüggvénye

x <- seq(-6,6,1/1000)
dnorm <- dnorm(x)

plot(x, dnorm, type="l", col="green", lwd=2, ylab='', xlab='', 
     main = "Normális eloszlás sűrűségfüggvénye")
legend(x='topleft', bty='n', 
       legend = c("N(0,1)", "N(2,1)", "N(0,2)", "N(0,3)"),
       col = c("green","yellow", "blue","red"), lwd = 2 )

lines(x, dnorm, type="l", col="black", lty=2)

dn2 <- dnorm(x, mean = 2, sd = 1)
lines(x, dn2, type="l", col="yellow", lwd=2)

dn3 <- dnorm(x, mean = 0, sd = 2)
lines(x, dn3, type="l", col="blue", lwd=2)

dn4 <- dnorm(x, mean = 0, sd = 3)
lines(x, dn4,type="l", col="red", lwd=2)


# d) Szimuláljon adatokat standard normális eloszlásból, majd ábrázolja hisztogrammal.
# Rajzolja fel a standard norm?lis sűrűségfüggvényt is az ábrára!

szim <- rnorm(10000, 0, 1)
hist(szim, freq=FALSE,
     xlab=" ", 
     ylab="s?r?s?g", 
     main="Standard normális szimuláció")
curve(dnorm(x, 0, 1), add=TRUE, col="blue", lwd=2)
# curve(dnorm(x, mean(szim), sd(szim)), add=TRUE, col="darkblue", lwd=2)


############################################
### Kitekintés:                          ###
###    Airquality adathalmaz még egyszer ###
############################################
hist(airquality$Temp, freq=FALSE,
     col="red",
     xlab="hőmérséklet (F)",
     ylab="sűrűség", 
     main="Hőmérséklet hisztogram (airquality)")
x <- seq(55,100,1)
dn <- dnorm(x, mean = mean(airquality$Temp), sd = sd(airquality$Temp))
lines(x, dn,type="l", lwd=2, col="blue")
#########################################



##################################################################################
################################### FELADATOK ####################################
##################################################################################

# 4) 
# a) Legyen Z ~ N(0, 1).

   # P(Z < 1.645) = ?
   pnorm(1.645)
   
   # P(Z < z) = 0,95, z = ?
   qnorm(0.95)
   
   # P(Z < -1.645) = ?
   pnorm(-1.645)
   
   # P(Z < z) = 0,5, z = ?
   qnorm(0.5)
   
   # P(Z > 1,96) = ?
   1-pnorm(1.96)
   pnorm(1.96, lower.tail = FALSE)

# b) Legyen X ~ N(25, 3^2).

   # P(X < 33) = ?
   pnorm(33, mean = 25, sd = 3)
   
   # P(X < x) = 0,95, x = ?
   qnorm(0.95, mean = 25, sd = 3)
   
   # P(X < 21) = ?
   pnorm(21, mean = 25, sd = 3)
   
   # P(X < x) = 0,05, x = ?
   qnorm(0.05, mean = 25, sd = 3)
   
   # P(X > 22) = ?
   1-pnorm(22, mean = 25, sd = 3)
   pnorm(22, mean = 25, sd = 3, lower.tail = FALSE)
   
   # P(23 < X < 25) = ?
   pnorm(25, mean = 25, sd = 3) - pnorm(23, mean = 25, sd = 3)



# Egy tehén napi tejhozamát normális eloszású valószínűségi változóval, 
# m = 22,1 liter várható értékkel és szigma = 1,5 liter szórással modellezzük.
# Mi annak a valószínűsége, hogy egy adott napon a tejhozam 23 és 25 liter közé esik?

########## MEGOLDÁS ##########
pnorm(25, mean = 22.1, sd = 1.5) - pnorm(23, mean = 22.1, sd = 1.5)
##############################


# Tegyük fel, hogy egy populációban az intelligenciahányados (IQ) normális eloszlású 
# 110 várható értékkel és 10 szórással. Mi a valószónűsége, hogy egy véletlenszerűen 
# kiválasztott ember IQ-ja 120 feletti?

########## MEGOLDÁS ##########
1-pnorm(120, mean = 110, sd = 10)

# vagy

pnorm(120, mean = 110, sd = 10, lower.tail = FALSE)
##############################


# Mennyi garanciát adjunk, ha azt szeretnénk, hogy termékeink legfeljebb 10%-át kelljen 
# garanciaidőn belül javítani, ha a készülék élettartama 10 év vérható értékű és 
# 2 év szórású normális eloszlással közelíthető.

########## MEGOLDÁS ##########
qnorm(0.1, mean = 10, sd = 2)
##############################



# 8. Magyarországon 2017 tavaszán a 16 éves és idősebb népességen belül a férfiak 
# átlagos magassága 176 cm, 9 cm szórással.

# a) Mennyi annak a valószínűsége, hogy egy véletlenszerűen kiválasztott férfi 
# testmagassága 165 és 185 cm közé esik?
########## MEGOLDÁS ##########
pnorm(185, mean = 176, sd = 9) - pnorm(165, mean = 176, sd = 9)
##############################

# b) Mennyi annak a valószínűsége, hogy egy férfi magasabb 2 méternél?
########## MEGOLDÁS ##########
1 - pnorm(200, mean = 176, sd = 9)
##############################

# c) Hány cm-es testmagasság alatt van a férfiak 90%-a? 
########## MEGOLDÁS ##########
round(qnorm(0.9, mean = 176, sd = 9), 1)
##############################

# d) Mekkora testmagasság felett van a férfiak 80%-a?
########## MEGOLDÁS ##########
round(qnorm(0.2, mean = 176, sd = 9), 1)
##############################


# Tapasztalatok szerint az út hossza, amit egy bizonyos típusú robogó megtesz az első
# meghibásodásig exponenciális eloszlású valószínűségi változó. Ez a távolság 
# átlagosan 6000 km. Mi a valószínűsége annak, hogy egy véletlenszerűen
# kiválasztott robogó

# a) kevesebb, mint 4000 km megtétele után meghibásodik?
########## MEGOLÁS ##########
pexp(4000, rate = 1/6000) 
##############################

# b) több, mint 6500 km megtétele után hibásodik meg?
########## MEGOLDÁS ##########
1 - pexp(6500, rate = 1/6000) 
##############################

# c) 4000 km-nél több, de 6000 km-nél kevesebb út megtétele után hibásodik meg?
########## MEGOLDÁS ##########
pexp(6000, rate = 1/6000) - pexp(4000, rate = 1/6000) 
##############################

# d) Legfeljebb mekkora utat tesz meg az elso meghibásodásig a robogók leghamarabb meghibásodó 20%-a?
########## MEGOLDÁS ##########
qexp(0.2, rate = 1/6000)
##############################

