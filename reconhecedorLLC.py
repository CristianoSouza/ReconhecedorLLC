
regras = []
palavras = []

simbolo_inicial = raw_input()
conjunto_nao_terminais = raw_input()
conjunto_terminais = raw_input()

cond_parada = 1
while(cond_parada == 1):
	regra = raw_input()
	if (regra == '# -> #'):
		cond_parada = 0
	else:
		regras.append([regra[0], regra.split("-> ")[1]])


cond_parada = 1
while(cond_parada == 1):
	palavra = raw_input()
	if (palavra == '#'):
		cond_parada = 0
	else:
		palavras.append(palavra)

print("Simbolo Inicial: ")
print(simbolo_inicial)
print("Nao terminais: ")
print(conjunto_nao_terminais)
print("Terminais: ")
print(conjunto_terminais)
print("Regras: ")
print(regras)
print("Palavras: ")
print(palavras)

