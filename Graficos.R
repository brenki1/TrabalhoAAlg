library(ggplot2)

tExec <- read.csv("resultados.csv")

ggplot(data = tExec, aes(x = tempo, y = tamanho))+
  geom_line() +
  theme_bw()

