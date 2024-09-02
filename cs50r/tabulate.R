votes <- read.csv("votes.csv")

apply(votes, MARGIN = 1, FUN = sum)
