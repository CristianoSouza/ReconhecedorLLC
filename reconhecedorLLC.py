
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

def getSimbolo(simbolo):
	print('getSimbolo')
	lista_simbolos = []
	for regra in regras:
		if(regra[1] == simbolo):
			lista_simbolos.append(regra[0])
			print('Encontrado: ' + regra[0] + '->' + simbolo)
			
	return lista_simbolos

def remove_repetidos(lista):
    l = []
    for i in lista:
        if i not in l:
            l.append(i)
    return l

#Percorrer o vetor de palavras para verificar cada uma delas
iterador = 1
for palavra in palavras:
	triangulo = []
	triangulo.append([])
	for i in range(0, len(palavra)):
		lista = getNaoTerminal(palavra[i])
		print('Lista obtida para o terminal ' + palavra[i] + ': ')
		print(lista)
		triangulo[0].append(lista)

	print('Triangulo obtido com a subtituicao dos terminais: ')
	print(triangulo)

	r= len(triangulo[0])
	s= len(triangulo[0])
	print(' s = len(triangulo[0]) = ' + str(s) )
	for i in range(1,s):
		print("i = " + str(i))
		triangulo.append([])
		for j in range(0, s-i):
			print('-------------------')
			print("[ " + str(i) + " , " + str(j) + "]")
			print('Roldana no triangulo: [' + str(j) +", "+ str(j+1)+ " ]" + str(triangulo[i-1][j]) + '---' + str(triangulo[i-1][j+1]) )

			lista_simbolos = []
			for item_a in triangulo[i-1][j]:
				
				for item_b in triangulo[i-1][j+1]:
					print('item_a: ' + str(item_a) + ' item_b: ' + str(item_b))


					simbolo = item_a + item_b

					print('Simbolo: ')
					print(simbolo)


					lista = getSimbolo(simbolo)
					lista_simbolos = lista_simbolos + lista
					print('Lista obtida para ' + simbolo + ': ')
					print(lista_simbolos)
					

					#print('------------------')
					#print( str(triangulo[0][0]))
					#print( str(simbolo_inicial))
					#print(str(triangulo[0][0]) == str(simbolo_inicial))
					#print('------------------')

			if not lista_simbolos:
				lista_simbolos.append('*')

			lista_simbolos = remove_repetidos(lista_simbolos)
			print('Lista adicionada ao triangulo')
			print(lista_simbolos)
			triangulo[i].append(lista_simbolos)

		print('Triangulo apos a iteracao ' + str(i) + ': ')
		rseqn = triangulo[:]
		rseqn.reverse()

		for item in rseqn:
				print(item)

	print('Triangulo gerado, caso o simpobolo inicial esteja na posicao 0 do triangulo a palavra pertence a linguagem: ')
	print('Instancia ' + str (iterador))
	print(triangulo[s-1])

	pertence = False
	for item in triangulo[s-1][0]:
		if(item == simbolo_inicial):
			pertence = True

	if (pertence == True):
		print( palavra + ' e uma palavra valida')
	else:
		print( palavra + ' nao e uma palavra valida')
	iterador+=1

