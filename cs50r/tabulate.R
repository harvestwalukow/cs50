votes <- read.csv("votes.csv")

votes$total <- votes$poll + votes$mail

colnames(votes)
rownames(votes)

write.csv(votes, "totals.csv", row.names = FALSE)
