##########################################
###   4. Laboros gyakorlat (8-9. hét)  ###
##########################################


############################
## Konfidenciaintervallum ##
############################

# PONTBECSLÉS: a becsülendő paramétert vagy annak függvényét a 
# mintaelemekből képzett egyetlen statisztikával becsüljük, pl.
# legyenek X1, . . . , Xn független, azonos eloszlású valószínűségi 
# változók m várható értékkel
# cél: az ismeretlen m paraméter becslése
# becslés: a mintaátlaggal (ld. táblás gyakorlat)
# nem elég informatív, nem tudni mennyi bizonytalanság van a becslésben

# INTERVALLUMBECSLÉS: becslés egy egész intervallum

# Konfidenciaintervallum a normális eloszlás várható értékére:
# - ismert szórás esetén
# - ismeretlen szórás esetén


# Feladatok:

### Táblás gyakorlat 4.1 Feladat ###
# Legyen X1, X2, X3, X4 független azonos N(m, 2^2) eloszlású minta. 
# A megfigyelt értékek a következők: 14,8; 12,2; 16,8; 11,1
# a) Adjon 95%-os megbízhatóságú konfidenciaintervallumot m-re!

minta <- c(14.8, 12.2, 16.8, 11.1)
n <- length(minta)
alpha <- 0.05

## szórás ismert
sigma <- 2

ci_also <- mean(minta) - qnorm(1-alpha/2)*sigma/sqrt(n)
ci_felso <- mean(minta) + qnorm(1-alpha/2)*sigma/sqrt(n)

cat('Konfidenciaintervallum (szórás = 2 ismert):', '(',round(ci_also,1),',',  round(ci_felso,1), ')\n')


# b) Hány elemű mintára van szükség, ha azt szeretnénk, hogy a 
#    konfidenciaintervallum legfeljebb 1,6 hosszúságú legyen?

hossz <- 1.6
ceiling( (2*qnorm(1-alpha/2)*sigma/hossz)^2 )


# 2. Tekintsük az alábbi hallgatói magassságokat (cm). 
# (a) Adjunk 95% megbízhatóságú konfidenciaintervallumot a hallgatók 
#     magasságának várható értékére! Tegyük fel, hogy a hallgatók magassága 
#     normális eloszlású 10 cm szórással. Adjunk konfidenciaintervallumot 
#     abban az esetben is, ha a szórást nem ismerjük!

ht <- c(180, 163, 150, 157, 165, 165, 174, 191, 172, 165, 168, 186)
n <- length(ht)
alpha <- 0.05

## szórás ismert
sigma <- 10

ci_also <- mean(ht) - qnorm(1-alpha/2)*sigma/sqrt(n)
ci_felso <- mean(ht) + qnorm(1-alpha/2)*sigma/sqrt(n)

cat('Konfidenciaintervallum (szórás = 10 ismert):', '(',round(ci_also,1),',',  round(ci_felso,1), ')\n')

## szórás ismeretlen
sd <- sd(ht)

ci_alsoi <- mean(ht)-qt(1-alpha/2, df=n-1)*sd/sqrt(n) 
ci_felsoi <- mean(ht)+qt(1-alpha/2, df=n-1)*sd/sqrt(n) 

cat('Konfidenciaintervallum (szórás ismeretlen):', '(',round(ci_alsoi, 1),',',  round(ci_felsoi, 1), ')\n')

# (b) Hány elemű mintára van szükség, ha azt szeretnénk, hogy a 
#     konfideniciaintervallum legfeljebb 8 cm hosszúságú legyen?

## konfidenciaintervallum hossza: 2*qnorm(1-alpha/2)*sigma/sqrt(n)

hossz <- 8
legalabbn <- ( 2*qnorm(1-alpha/2)*sigma/hossz )^2

cat('Legalább', ceiling(legalabbn),'elemű mintára van szükség.')


# 3. Egy gép előírt hosszúságú darabokat vág le egy acéllemezből, 
#    de a hosszúság normális eloszlású ingadozást mutat, melynek 
#    szórásnégyzete 9 cm2 . Adjunk 95%-os megbízhatósági szintű 
#    konfidenciaintervallumot a levágott darabok átlagos hosszára, 
#    ha egy 80 elemű minta átlaga 81 cm.

########## MEGOLDÁS ##########
## szórás ismert
sigma <- 3
atlag <- 81
n <- 80
alpha <- 0.05

ci_also <- atlag - qnorm(1-alpha/2)*sigma/sqrt(n)
ci_felso <- atlag + qnorm(1-alpha/2)*sigma/sqrt(n)

cat('Konfidenciaintervallum (szórás = 3 ismert):', '(',round(ci_also,1),',',  round(ci_felso,1), ')\n')
##############################


# 4. Egy műszerrel tízszer megmértünk egy ellenállást. A következő 
#    adatokat kaptuk: 
# 20.1, 19.9, 18.9, 19.5, 19.8, 19.4, 19.3, 20.0, 19.5, 19.6 Ohm
# (a) Adjunk 90%-os megbízhatósági szintű konfidenciaintervallumot 
#     az ellenállás tényleges értékére!

ell <- c(20.1, 19.9, 18.9, 19.5, 19.8, 19.4, 19.3, 20.0, 19.5, 19.6)
n <- length(ell)
alpha <- 0.1

########## MEGOLDÁS ##########
sd <- sd(ell)
ci_alsoi <- mean(ell)-qt(1-alpha/2, df=n-1)*sd/sqrt(n) 
ci_felsoi <- mean(ell)+qt(1-alpha/2, df=n-1)*sd/sqrt(n)

cat('Konfidenciaintervallum (szórás ismeretlen):', '(',round(ci_alsoi, 4),',',  round(ci_felsoi, 4), ')\n')
##############################


# (b) Mennyiben változik a konfidenciaintervallum ha tudjuk, hogy 
#     a műszer mérési eredményének a szórása 0.4 Ohm?

########## MEGOLDÁS ##########
sigma <- 0.4

ci_also <- mean(ell) - qnorm(1-alpha/2)*sigma/sqrt(n)
ci_felso <- mean(ell) + qnorm(1-alpha/2)*sigma/sqrt(n)

cat('Konfidenciaintervallum (szórás = 3 ismert):', '(',round(ci_also, 4),',',  round(ci_felso, 4), ')\n')
##############################

# Megjegyzés: vegyük észre, hogy az (a) és (b) feladat konfidenciaintervallumai 
# ugyan közel vannak egymáshoz, nem azonosak.
# A szórás becslése (sd=0,36) kicsit kisebb, mint a valódi szórás (sigma=0,4), 
# viszont a t eloszláshoz tartozó megfelelő kvantilis (qt(1-alpha/2,df=n-1)=1,833) 
# pedig kicsit nagyobb, mint a standard normálishoz tartozó megfelelő kvantilis 
# qnorm(1-alpha/2)=1,645). így a konfidenciaintervallum hossza nem lesz nagyon 
# különböző. (0.362*1.833/sqrt(10) > 0.4*1.645/sqrt(10))




#######################
# Hipotézisvizsgálat: # 
# paraméteres próbák  #
#######################

### Táblás gyakorlat 4.2 Feladat ###
# Arra szeretnénk statisztikai bizonyítékot találni, hogy a napi középhőmérséklet október 18-án Budapesten 15C 
# alatt volt. Az elmúlt 4 év napi középhőmérsékletei a következők voltak: 
# 14,8; 12,2; 16,8; 11,1 C, valamint tegyük fel, hogy az adatok normális 
# eloszlásból származnak.
hom <- c(14.8, 12.2, 16.8, 11.1)

### (a) Írjuk fel a null- és ellenhipotézist!

# Legyen mu a napi középhőmérséklet október 18-án Budapesten.

# H0: mu >= 15
# H1: mu < 15


### (b) Tegyük fel, hogy a napi középhőmérséklet szórása sigma = 2. 
# Teszteljük a fenti hipotézist alpha = 0,05 terjedelem mellett!
# Adjuk meg a kritikus tartományt és p-értéket! Mi a döntés?

alpha <- 0.05
mu0 <- 15
szoras <- 2

# Melyik próbát használjuk?  egymintás egyoldali u-próba

n <- length(hom)
atlag <- mean(hom)

u <- sqrt(n)*(atlag - mu0) / szoras  # próbastatisztika
krit <- qnorm(alpha,0,1)  # kritikus érték
pertek <- pnorm(u)   # p-érték

cat('Próbastatisztika:', round(u, 4),
    '\nKritikus értékek:', round(krit, 4),
    '\np-érték:', round(pertek, 4),
    '\nDöntés: Nem vetjük el H0-t, azaz nincs elég bizonyítékunk, hogy a napi 
    középhőmérséklet október 18-án Budapesten 15C alatt lenne.', '\n')

# install.packages("TeachingDemos")
library(TeachingDemos)
z.test(hom, mu = 15, stdev=szoras, alternative = c("less"),
       n=length(hom), conf.level = 0.95)


### (c) Tesztelje a hipotézist úgy is, hogy nem használja a szórásra vonatkozó 
# előzetes információt!

sd <- sd(hom)

# Melyik próbát használjuk?  egymintás egyoldali t-próba

t <- sqrt(n)*(atlag - mu0) / sd
krit <- qt(alpha, df = n-1)
pertek <- pt(t, df = n-1)

cat('Próbastatisztika:', round(t, 4),
    '\nKritikus érték:', round(krit, 4),
    '\np-érték:', round(pertek, 4),
    '\nDöntés: Nem vetjük el H0-t, azaz nincs elég bizonyítékunk, hogy a napi 
    középhőmérséklet október 18-án Budapesten 15C alatt lenne.', '\n')

t.test(hom, alternative = "less", mu = 16.77, conf.level = 1-alpha)


### (d) Milyen hipotézist írjunk fel, ha azt szeretnénk vizsgálni, hogy a napi 
# középhőmérséklet október 18-án Budapesten 15C-tól különböző volt? 
# Teszteljük a fenti adatok segítségével! (szórás ismert)

# H0: mu = 15
# H1: mu nem= 15

# Melyik próbát használjuk?  egymintás kétoldali u-próba

u # próbastatisztika, u.az mint elobb
krit <- qnorm(c(alpha/2, 1-alpha/2))  # kritikus értékek
pertek <- 2*pnorm(-abs(u))  # p-érték

cat('Próbastatisztika:', round(u, 4),
    '\nKritikus értékek:', round(krit, 4),
    '\np-érték:', round(pertek, 4),
    '\nDöntés: Nem vetjük el H0-t, azaz nincs elég bizonyítékunk, hogy a napi 
    középhőmérséklet október 18-án Budapesten 15C-tól különböző lenne.', '\n')


z.test(hom, mu = 15, stdev=szoras, alternative = c("two.sided"),
       )


### Táblás gyakorlat 4.3 Feladat ###
# Az alábbi két minta két különböző gyáregységben tapasztalt selejtarányra 
# vonatkozik (ezrelékben). Állítható-e, hogy az „A” gyáregység jobban dolgozott? 
# (Feltételezhetjük, hogy a minták normális eloszlásúak, függetlenek.)

mintaA <- c(11.9, 12.1, 12.8, 12.2, 12.5, 11.9, 12.5, 11.8, 12.4, 12.9)
mintaB <- c(12.1, 12.0, 12.9, 12.2, 12.7, 12.6, 12.6, 12.8, 12.0, 13.1)

# Legyen m_A az A és m_B a B gyáregységek selejtaránya.

# H_0: m_A  >=  m_B
# H_1: m_A  <   m_B

# Melyik próbát használjuk?

# Először: elozetes F-próba a szórások különbözöségére

var.test(mintaB, mintaA, alternative="two.sided")

# u. az: F = sd(mintaB)^2 / sd(mintaA)^2; F
# pvalue = 2*pf(F, df1=length(mintaA)-1, df2=length(mintaB)-1); pvalue

# => a szórásokat nem tekintjük különbözőnek =>

# kétmintás egyoldali t-próba

t.test(mintaB, mintaA, alternative="less", paired=FALSE, var.equal=TRUE)

# Döntés: Nem utasítjuk el H_0-t, azaz nincs elég bizonyítékunk arra, hogy 
# az A gyáregység jobban dolgozott.
pt(-1.1462,18)

### Táblás gyakorlat 4.4 Feladat ###
# Két szervert hasonlítottunk össze. Az elsőn 30 futás átlagos ideje 6,7 mp volt, 
# míg ettől függetlenül a másodikon 20 futásé 7,2 mp. Vizsgáljuk meg, hogy van-e 
# szignifikáns különbség a két szerver sebessége közt, ha a futási idők szórása 
# mindkét gépen 0,5 volt?

# Legyen m_1 ill. m_2 az első ill. második szerveren való futás várható ideje.

# H_0: m_1 = m_2
# H_1: m_1 nem= m_2

# Melyik próbát használjunk?
# két mintás kétoldali u-próba
atlag1 <- 6.7
atlag2 <- 7.2
szoras1 <- 0.5 
szoras2 <- 0.5 
n1 <- 30
n2 <- 20

alpha <- 0.05

u <- (atlag1 - atlag2) / sqrt(szoras1^2/n1 + szoras2^2/n2)
krit <- qnorm(c(alpha/2, 1-alpha/2))
pertek <- 2*pnorm(-abs(u))

cat('Próbastatisztika:', u,
    '\nKritikus értékek:', krit,
    '\np-érték:', pertek,
    '\nDöntés: Elvetjük H0-t, azaz a két szerver futási ideje közt szignifikáns különbség van.', '\n')


### Táblás gyakorlat 4.5 Feladat ###
# Az alábbi két minta 10 forgalmas csomópont levegojében található szennyezőanyag 
# koncentrációra vonatkozó két adatsort tartalmaz. Az első sorban a november 15-i, 
# a másodikban a november 29-i számok szerepelnek. Szignifikánsan változott-e a 
# légszennyezettség?
nov15 <- c(20.9, 17.1, 15.8, 18.8, 20.1, 15.6, 14.8, 24.1, 18.9, 12.5)
nov29 <- c(21.4, 16.7, 16.4, 19.2, 19.9, 16.6, 15.0, 24.0, 19.2, 13.2)

# Legyen m_1 ill. m_2 a november 15-i ill. 29-i légszennyeződés várható értéke.

# H_0: m_1 = m_2        <=> H_0: m_2 - m_1 = 0
# H_1: m_1 nem= m_2         H_1: m_2 - m_1 nem= 0

# Legyen m a november 29-én és a november 15-én mért légszennyeződés 
# várható értékének különbsége, azaz m = m_2 - m_1

# H_0: m = 0
# H_1: m nem= 0

# Melyik próbát használjunk? párosított két mintás kétoldali t-próba, egymintás kétoldali t-próba

t.test(nov29, nov15, alternative="two.sided", paired=TRUE)
t.test(nov29-nov15, mu=0, alternative="two.sided")
# Döntés: Nem utasítjuk el H0-t (az alpha=0,05 szint en), azaz nincs elég bizonyíték, 
# hogy a különbség lenne a november 15-i és 29-i légszennyeződés mértéke közt.



########################
## További feladatok: ##
########################

### 1. A TTK II. évfolyamán az egyik gyakorlati csoportban 10-en írtak statisztika 
# zárthelyit. Két feladatsor volt, mindkettőben 15 pontot lehetett elérni. Tegyük fel, 
# hogy az elért pontszámok normális eloszlásúak. A pontszámok az alábbiak:

minta1 <- c(12,11,8,14,10)   # 1. feladatsor
minta2 <- c(15,14,9,15,11)   # 2. feladatsor


### (a) Vajon az elso feladatsor nehezebb volt?

# Legyen m1 ill. m2 az első ill. második feladatoron elért várható pontszám

# H_0: m1 >= m2
# H_1: m1 < m2


# Először: elozetes F-próba a szórások különbözöségére
var.test(minta1,minta2,alternative="two.sided")

# F = sd(minta1)^2 / sd(minta2)^2; F
# pvalue = 2*pf(F, df1=length(minta1)-1, df2=length(minta2)-1); pvalue

# => a szórásokat tekinthetjük azonosnak => 

# Melyik próbát használjunk? kétmintás egyoldali t-próba

t.test(minta1,minta2,alternative="less",paired=FALSE,var.equal=TRUE)

# Döntés: Nem utasítjuk el H_0-t, azaz nem mondhatjuk, hogy az elso feladatsor 
# nehezebb volt


# Megjegyés: Ha ezt tesztelnénk:  H_0: m1 = m2,  H_1: m1 nem= m2
# Kétmintás t-próba: 
# t.test(minta1,minta2,paired=FALSE,var.equal=TRUE)    # alfa=0.05 
# u.az:
# t.test(minta1,minta2,conf.level=0.95,paired=FALSE,var.equal=TRUE)


### (b) Mennyiben változik a helyzet, ha nem 10 diákról, 
# hanem csak 5-rŐl van szó, és a 2. feladatsor a pótZH eredménye?

# a két minta nem független (paired=TRUE)

# H_0: m1 >= m2     <=>     m2-m1 >= 0
# H_1: m1 < m2      <=>     m2-m1 < 0

# Melyik próbát használjunk?  egymintás t-próbát a különbségekre

t.test(minta1,minta2,alternative="less",paired=TRUE)

# Döntés: Nem utasítjuk el H_0-t az alpha = 0,01 szinten, azaz nem mondhatjuk, 
# hogy az elso feladatsor nehezebb volt, viszont az alpha = 0,05 szinten már 
# elutasítanánk H_0-t.

# Megjegyzés: ha ezt kérdeznénk:  H_0: m1 = m2,  H_a: m1 nem= m2
# t.test(minta1,minta2,paired=TRUE)
# lehet a különbségeket venni és egymintás tesztet használni, u.az:
# minta=minta1-minta2
# t.test(minta,alternative="two.sided")


### 2. Az alábbi két minta 10 egyforma képességűnek feltételezett sportoló 
# súlylökésben elért eredményeit tartalmazza. A sportolók két ötfős csoportban 
# készültek az edzőtáborban. Edzéstervük ugyanaz volt, de az első csoportban 
# készülők minden reggel fejenként 10 tojást és 25 túró rudit ettek meg. A 
# második csoportban készülőknek reggel és este 1-1 kg szalonnát és 1-1 kg 
# madártejet kellett megenni. 2 hét felkészülés után értékelték az eredményeket. 
# Tételezzük fel, hogy normális eloszlásból származnak a minták és a terjedelem 5%.

minta1 <- c(15.8, 15.2, 16.3, 17.1, 16.1) # 1. csoport
minta2 <- c(19, 12.1, 17.2, 14.7, 21)     # 2. csoport

# (a) Melyik diéta volt jobb, ha a dobások szórását 2-nek tekintjük?

# Legyen m1 az első ill. m2 a második csoport dobásainak várható eredménye.

# H_0: m1 = m2
# H_1: m1 nem= m2

# Melyik próbát használjuk?  kétmintás kétoldali u-próba

szigma <- 2
atl1 <- mean(minta1)
atl2 <- mean(minta2)
n <- length(minta1)

u <- (atl1-atl2)/(szigma*sqrt(2/n))  # próbastatisztika (szórás ismert)
pert <- 2*(1-pnorm(abs(u))); round(pert, 4)    # p-érték 

# Döntés: Nem utasítjuk el H_0-t, azaz nincs rá bizonyíték (alpha = 0,05 szinten), 
# hogy a két diéta különböző lenne.


### (b) Állíthatjuk-e, hogy a második csoportban nagyobb változékonyságot 
# mutat a sportolók teljesítménye?
sd(minta1)
sd(minta2)
# F-próba:
var.test(minta1, minta2, alternative="less")

# H0: sz1 >= sz2
# H1: sz1 < sz2 
# Elutasítjuk H0-t, így állíthatjuk, hogy a második csoportban nagyobb változékonyságot 
# mutat a sportolók teljesítménye.


### (c) Ha nem ismerjük a szórást, akkor tekinthetjük-e valamelyik diétát jobbnak?
# F-próba a szórások egyenlőségére:
# var.test(minta1, minta2, alternative = "two.sided")
# de fel lehet használni a b) feladat eredményét

# H_0: m1 = m2
# H_1: m1 nem= m2

# Melyik próbát használjunk?  kétmintás Welch-próba
t.test(minta1, minta2, alternative = "two.sided", paired=FALSE, var.equal = FALSE)

# Döntés: Nem utasítjuk el H_0-t, azaz nincs rá bizonyíték (alpha = 0,05 szinten), 
# hogy a két diéta különböző lenne.

### 3. Bublisztánban az ÖDSZ párt vezetőségi tagjainak havi keresete 
# (millió bublikban) jól közelíthető N(mu_1,sigma_1^2) eloszlással. 
# A többi lakosnál a kereset N(mu_2,sigma_2^2) eloszlással közelíthető. 
# Rita TORA oknyomozó újságíró kiderítette néhány - a Nagy vezér stadionban - 
# szurkoló ember keresetét.

oszlop1=c(20.47,21.10,18.67,16.67,18.00,20.40,22.17,20.05,24.85,19.93,19.73,20.39) 
oszlop2=c(4.56,6.67,4.10,11.91,3.89,5.48,3.89,10.12,5.13,4.24,2.36,0.22)
df <- data.frame(oszlop1,oszlop2)
colnames(df)=c("VIP páholyban ülők","Normál sorokban ülők")
szoras1 <- 2
szoras2 <- 4

### (a) Amennyiben a VIP páholyban csak az ÖDSZ párt vezetőségi tagjai ülnek, 
# akkor 5%-os elsőfajú hibavalószínűség mellett el tudja-e utasítani a H0 : mu_1 = 20 
# hipotézist a kétoldali ellenhipotézissel szemben?

########## MEGOLDÁS ##########
# H1: mu_1 nem= 20

alpha <- 0.05
mu0 <- 20

# Melyik próbát használjunk? egymintás kétoldali u-próba

z.test(x = oszlop1, mu = mu0, sd = szoras1, alternative = c("two.sided"), conf.level = 1-alpha)

# ki lehet számolni így is:
n1 <- length(oszlop1)
atlag1 <- mean(oszlop1)

probastat1 <- sqrt(n1)*(atlag1 - mu0) / szoras1  # próbastatisztika
krit <- qnorm(c(alpha/2, 1-alpha/2))  # kritikus értékek

cat('Próbastatisztika:', round(probastat1, 5),
    '\nKritikus értékek:', krit,
    '\nDöntés: Nem vetjük el H0-t, nincs rá bizonyíték, hogy 20 millió buklitól 
    különbözo lenne az ÖDSZ párt vezetőségi tagjainak havi keresete.', '\n')
##############################


### (b) Amennyiben az ÖDSZ párt vezetoségi tagjai csak a VIP páholyban ülnek, 
# akkor 5%-os elsőfajú hibavalószínűség mellett el tudja-e utasítani a H0 : mu_2 = 20 
# hipotézist a kétoldali ellenhipotézissel szemben?

########## MEGOLDÁS ##########
# H1: mu_2 nem= 20

alpha <- 0.05
mu0 <- 20

# Melyik próbát használjunk? egymintás kétoldali u-próba

z.test(x = oszlop2, mu = mu0, sd = szoras2, alternative = c("two.sided"), conf.level = 1-alpha)

# ki lehet számolni így is:
n2 <- length(oszlop2)
atlag2 <- mean(oszlop2)

probastat2 <- sqrt(n2)*(atlag2 - mu0) / szoras2
krit <- qnorm(c(alpha/2, 1-alpha/2))

cat('Próbastatisztika:', round(probastat2, 3),
    '\nKritikus értékek:', krit,
    '\nDöntés: Elvetjük H0-t, azaz 20 millió buklitól különbözo a havi keresete 
    azoknak, akik nem az ÖDSZ párt vezetoségi tagjai.', '\n')
##############################


### (c) Mennyi a p-érték az előző részfeladatoknál?

########## MEGOLDÁS ##########
pertek1 <- 2*pnorm(-abs(probastat1))
pertek2 <- 2*pnorm(-abs(probastat2))

cat('(a) p-érték:', round(pertek1, 4) , 
    '\n(b) p-érték:', round(pertek2, 4), '\n')
##############################


### (d) El tudja-e utasíani a H0 : mu_1 = mu_2 hipotézist?
# tfh. alpha = 0.05 és H1: mu_1 nem= mu_2

alpha <- 0.05

########## MEGOLDÁS ##########
# Melyik próbát használjunk? kétmintás kétoldali u-próba

probastat <- (atlag1 - atlag2) / sqrt(szoras1^2/n1 + szoras2^2/n2)
krit <- qnorm(c(alpha/2, 1-alpha/2))
pertek <- 2*pnorm(-abs(probastat))

cat('Próbastatisztika:', probastat,
    '\nKritikus értékek:', krit,
    '\np-érték:', round(pertek, 4),
    '\nDöntés: Elvetjük H0-t, azaz az ÖDSZ párt vezetoségi tagjai ill. 
    többi lakos havi keresete különbözo.', '\n')
##############################

# Ha nem tesszük fel, hogy ismertek a szórások:
# var.test(oszlop1, oszlop2, alternative="two.sided")
# t.test(oszlop1, oszlop2, paired=FALSE, alternative="two.sided", var.test=TRUE)