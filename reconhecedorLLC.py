
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

'''def getNaoTerminal(triangulo, posicao_simbolo):
	print('getNaoTerminal')
	simbolo = triangulo[posicao_simbolo]
	triangulo[posicao_simbolo] = []
	for regra in regras:
		if(regra[1] == triangulo[posicao_simbolo]):
			triangulo[posicao_simbolo].append(regra[0])
			print('Encontrado: ' + regra[0] + '->' + triangulo[posicao_simbolo])'''


def getNaoTerminal(simbolo):
	print('getNaoTerminal')
	lista = []
	for regra in regras:
		if(regra[1] == simbolo):
			lista.append(regra[0])
			print('Encontrado: ' + regra[0] + '->' + simbolo)
	return lista

#Percorrer o vetor de palavras para verificar cada uma delas
iterador = 1
for palavra in palavras:
	triangulo = []
	for i in range(0, len(palavra)):
		lista = getNaoTerminal(palavra[i])
		print('Lista obtida para o terminal ' + palavra[i] + ': ')
		print(lista)
		triangulo.append(lista)

	print('Triangulo obtido com a subtituicao dos terminais: ')
	print(triangulo)

	r= len(triangulo)-1
	print(r)
	for i in range(0, r):
		print('Iteracao no triangulo: ' + str(i))
		print('triangulo[i]: ')
		print(triangulo[i])
		print('triangulo[i+1]: ')
		print(triangulo[i+1])
		simbolo = triangulo[i][0] + triangulo[i+1][0]
		print('Simbolo: ')
		print(simbolo)


	print('Instancia ' + str (iterador))
	if (1==1):
		print( palavra + ' e uma palavra valida')
	else:
		print( palavra + ' nao e uma palavra valida')
	iterador+=1

