#ifndef ALLOC_FONCTIONS_H
#define ALLOC_FONCTIONS_H

void alloc_memory_error(void);
unsigned int alloc_str_vector(char*** buffer, unsigned int lenght, const char* str);
template <class T> unsigned int alloc_vector(T** buffer, unsigned int lenght, T value);

void alloc_memory_error() {
	clog << " [erro] Falha ao alocar memoria\n\n";
	system("pause");
	exit(-1);
}

// aloca um novo espaço no buffer e insere uma string
// o novo tamanho é retornado, a variavel de tamanho inserida NÃO é modificada
unsigned int alloc_str_vector(char*** buffer, unsigned int lenght, const char* str) {
	char** verify = (char**)realloc(*buffer, sizeof(char*) * ++lenght);
	if (!verify) alloc_memory_error();

	verify[lenght - 1] = (char*)calloc(sizeof(char), strlen(str) + 1);
	if (!verify[lenght - 1]) alloc_memory_error();

	strcpy(verify[lenght - 1], str);
	verify[lenght - 1][strlen(str)] = '\0';

	*buffer = verify;

	return lenght;
}

template <class T>
unsigned int alloc_vector(T** buffer, unsigned int lenght, T value) {
	T* verify = (T*)realloc(*buffer, sizeof(T) * ++lenght);
	if (!verify) alloc_memory_error();

	verify[lenght - 1] = (T)calloc(sizeof(T), 1);
	if (!verify[lenght - 1]) alloc_memory_error();

	verify[lenght - 1] = value;

	*buffer = verify;

	return lenght;
}

#endif // !ALLOC_FONCTIONS_H

