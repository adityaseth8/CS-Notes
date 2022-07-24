# Aditya Seth
# Homework 1
# ECS 132 SS1

install.packages("combinat")
library("combinat")

#Question 1 (Roulette)
#Analytic Solution
  # Want total of 15 from the next 2 roulette spins
  # let event A be the total = 15: 
  # A = {(3,12),(12,3),(4,11),(11,4),(5,10),(10,5),(6,9),(9,6),(7,8),(8,7)}
  # |A| = 10.
  # Total number of outcomes from 2 spins: 13^2 = 169
  # Answer: 10/169
  # 
  # 0.065

#Simulation
f <- function(total, spin1, nreps=100000) {
  count <- 0
  for (i in 1:nreps) {
    spin2 = sample(0:12, 1, replace=TRUE)
    spin3 = sample(0:12, 1, replace=TRUE)
    sum <- (spin1 + spin2 + spin3)
    if (sum == total) {
      count <- count + 1
    }
  }
  return (count/nreps)
}

f(total = 17, spin1 = 2)
f(total = 17, spin1 = 3)

runif(1)

################################################
#Question 2 (ALOHA)

#

# finds P(X1 = 2), P(X2 = 2) and P(X2 = 2|X1 = 1) in ALOHA example
sim <- function(p,q,nreps) {
  countX1!X2 <- 0
  countCeq0andX1!X2 <- 0
  # simulate nreps repetitions of the experiment
  
  for (i in 1:nreps) {
    numsend <- 0 # no messages sent so far
    # epoch 1 : chance of Node 1 activating, sending. chance of node 2 sending
    if (runif(1) < q) {
      #activate node 1
    }
    #else : 
    
   if runif(1)<q = numactive 2 else numactive 1
   
   
     # now simulate epoch 2
     # if X1 = 1 then one node may generate a new message
     numactive <- X1
     if (X1 == 1 && runif(1) < q) numactive <- numactive + 1
     # send?
     if (numactive == 1)
        if (runif(1) < p) X2 <- 0
        else X2 <- 1
     else { # numactive = 2
       numsend <- 0
       for (i in 1:2)
       if (runif(1) < p) numsend <- numsend + 1
       if (numsend == 1) X2 <- 1
       else X2 <- 2
     }
     if (X2 == 2) countx2eq2 <- countx2eq2 + 1
     if (X1 == 1) { # do tally for the cond. prob.
       countx1eq1 <- countx1eq1 + 1
       if (X2 == 2) countx2eq2givx1eq1 <- countx2eq2givx1eq1 + 1
     }
   }
   # print results
   cat("P(X1 = 2):",countx1eq2/nreps,"\n")
   cat("P(X2 = 2):",countx2eq2/nreps,"\n")
   cat("P(X2 = 2 | X1 = 1):",countx2eq2givx1eq1/countx1eq1,"\n")
}

sim(0.4,0.8,100)



################################################
#Question 3 (Poker)

#Analytic Solution
  #Probability of exactly 2 aces
  #we know: 4 aces in a 52 card deck
  # (4C2 * 48C3) / 52C5 = 0.04

  #Probability of exactly 4 diamonds
  #we know: 13 diamonds in a 52 card deck
  # (13C4 * 39C1) / 52C5

  #More likely: Probability of exactly 2 aces

#Simulation
  #Probability of exactly 2 aces
  f <- function(nreps = 100000) {
    success <- 0
    for (i in 1:nreps) {
      #1 = A, 11 = J, 12 = Q, 13 = K
      hand1 <- matrix(sample(1:13,5,replace=TRUE),ncol=5)
      # loop through each hand, count # of aces
      count <- 0
      for (j in 1:5) {
        if (hand1[1,j] == 1) {
            count <- count + 1
        }
      }
      if (count == 2) {
        success <- success + 1
      }
    }
    return(success/nreps)
  }
  f()

  #Probability of exactly 4 diamonds
  g <- function(nreps = 100000) {
    success <- 0
    for (i in 1:nreps) {
      #1 = H, 2 = D, 3 = S, 4 = C
      hand1 <- matrix(sample(1:4,5,replace=TRUE),ncol=5)
      # loop through each hand, count # of diamonds
      count <- 0
      for (j in 1:5) {
        if (hand1[1,j] == 2) {
          count <- count + 1
        }
      }
      if (count == 4) {
        success <- success + 1
      }
    }
    return(success/nreps)
  }
  g()

################################################
#Question 4(Camp Groups)

#Simulation
  #part a
  #1 matrix 2 rows (4,6), assign 1-30 kids no replacement
  #uhh compare the matrix with prev matrices to make sure it's unique
  f <- function(nreps = 5) {
    for (i in 1:nreps) {
      group <- matrix(sample(1:30,10,replace=FALSE),ncol=10)
      print(group)
    }
  }
  f()
  
f <- combinat::combn(3,2)
f
group1Size <- ncol(combinat::combn(30, 4))
group2Size <- ncol(combinat::combn(26, 6))
sampleSpace <- group1Size * group2Size
sampleSpace
  
  #part b

#sample space = both in grouo 1 - both in group 2
#(30C4 * 26C6) -(28C2 * 26C6) - (28C4 * 24C4)
################################################
#Question 5

  

