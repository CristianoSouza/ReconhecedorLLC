


def getSimbolo(simbolo, regras):
	#print('getSimbolo')
	lista_simbolos = []
	for regra in regras:
		if(regra[1] == simbolo):
			lista_simbolos.append(regra[0])
			#print('Encontrado: ' + regra[0] + '->' + simbolo)
			
	return lista_simbolos

def remove_repetidos(lista):
    l = []
    for i in lista:
        if i not in l:
            l.append(i)
    return l


def main():
	iterador = 1
	while 1:
		regras = []
		palavras = []
		try:
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

			#print("Simbolo Inicial: ")
			#print(simbolo_inicial)
			#print("Nao terminais: ")
			#print(conjunto_nao_terminais)
			#print("Terminais: ")
			#print(conjunto_terminais)
			#print("Regras: ")
			#print(regras)
			#print("Palavras: ")
			#print(palavras)


			#Percorrer o vetor de palavras para verificar cada uma delas
			print('\nInstancia ' + str (iterador) )
			for palavra in palavras:
				triangulo = []
				triangulo.append('X')
				triangulo.append([])

				triangulo[1].append('X')
				for i in range(1, len(palavra)+1):
					lista = getSimbolo(palavra[i-1],regras)
					#print('Lista obtida para o terminal ' + palavra[i] + ': ')
					#print(lista)
					if not lista:
							lista.append('*')
					triangulo[1].append(lista)

				#print('Triangulo obtido com a subtituicao dos terminais: ')
				#print(triangulo)

				tamanho_palavra= len(palavra)
				#print(' s = len(triangulo[0]) = ' + str(s) )
				for linha in range(2,tamanho_palavra+1):
					#print("l = " + str(linha))
					triangulo.append([])
					triangulo[linha].append('X')
					#print(len(palavra))
					for coluna in range(1, ((tamanho_palavra-linha)+2)):
						#print("k = " + str(coluna))
	
						lista_simbolos = []

						for aux in range(1, linha):
							#print('L= ' + str(linha) + 'K= ' + str(coluna) + 'F= ' + str(aux))

							for item_a in triangulo[linha-aux][coluna]:
								
								for item_b in triangulo[aux][(linha-aux)+coluna]:
									#print('item_a: ' + str(item_a) + ' item_b: ' + str(item_b))


									simbolo = item_a + item_b

									#print('Simbolo: ')
									#print(simbolo)


									lista = getSimbolo(simbolo, regras)
									lista_simbolos = lista_simbolos + lista
									#print('Lista obtida para ' + simbolo + ': ')
									#print(lista_simbolos)
									

									#print('------------------')
									#print( str(triangulo[0][0]))
									#print( str(simbolo_inicial))
									#print(str(triangulo[0][0]) == str(simbolo_inicial))
									#print('------------------')

						if not lista_simbolos:
							lista_simbolos.append('*')

						lista_simbolos = remove_repetidos(lista_simbolos)
						#print('Lista adicionada ao triangulo')
						#print(lista_simbolos)
						triangulo[linha].append(lista_simbolos)

					#print('Triangulo apos a iteracao ' + str(i) + ': ')
					#rseqn = triangulo[:]
					#rseqn.reverse()

					#for item in rseqn:
						#print(item)

				#print('Triangulo gerado, caso o simpobolo inicial esteja na posicao 0 do triangulo a palavra pertence a linguagem: ')
				#print(triangulo[tamanho_palavra])

				pertence = False
				for item in triangulo[tamanho_palavra][1]:
					if(item == simbolo_inicial):
						pertence = True

				if (pertence == True):
					print( palavra + ' e uma palavra valida')
				else:
					print( palavra + ' nao e uma palavra valida')
		except EOFError:
			break
		iterador+=1

if __name__ == "__main__":
	main()
