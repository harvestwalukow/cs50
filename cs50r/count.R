get_votes <- function(prompt = "Enter votes: ") {
  votes <- suppressWarnings(as.integer(readline(prompt)))
  ifelse(is.na(votes), 0, votes)
}

mario <- get_votes()
peach <- get_votes()
bowser <- get_votes()

total <- sum(mario, peach, bowser)
cat("Total votes:", total)