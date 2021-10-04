#ifndef VECTORX_H
#define VECTORX_H

template <class T> T* vector4(T p1, T p2, T p3, T p4);
template <class T> T* vector4(T p1, T p2);
template <class T> T* vector4(T p);
template <class T> T* vector3(T p1, T p2, T p3);
template <class T> T* vector3(T p);

template <class T>
T* vector4(T p1, T p2, T p3, T p4) {
	T* buffer = (T*)calloc(sizeof(T), 4);

	if (!buffer) alloc_memory_error();

	buffer[0] = p1;
	buffer[1] = p2;
	buffer[2] = p3;
	buffer[3] = p4;

	return buffer;
};

template <class T>
T* vector4(T p1, T p2) {
	T* buffer = (T*)calloc(sizeof(T), 4);

	if (!buffer) alloc_memory_error();

	buffer[0] = p1;
	buffer[1] = p2;
	buffer[2] = p1;
	buffer[3] = p2;

	return buffer;
};

template <class T>
T* vector4(T p) {
	T* buffer = (T*)calloc(sizeof(T), 4);

	if (!buffer) alloc_memory_error();

	buffer[0] = p;
	buffer[1] = p;
	buffer[2] = p;
	buffer[3] = p;

	return buffer;
};

template <class T>
T* vector3(T p1, T p2, T p3) {
	T* buffer = (T*)calloc(sizeof(T), 3);

	if (!buffer) alloc_memory_error();

	buffer[0] = p1;
	buffer[1] = p2;
	buffer[2] = p3;

	return buffer;
};

template <class T>
T* vector3(T p) {
	T* buffer = (T*)calloc(sizeof(T), 3);

	if (!buffer) alloc_memory_error();

	buffer[0] = p;
	buffer[1] = p;
	buffer[2] = p;

	return buffer;
};

#endif // !VECTORX_H
