library(ggplot2)

tExec <- read.csv("resultados.csv")

ggplot(data = tExec, aes(x = tamanho))+
  geom_line(aes(y=tempoNaive), color = "red")+
  geom_line(aes(y=tempoDac), color = "blue") +
  geom_line(color = "blue")+
  scale_y_time(name = "Tempo de execução")+
  scale_x_continuous(name = "Quantidade de elementos") +
  theme_bw()
  

