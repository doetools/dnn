ALL:
	@g++ dnn.cpp -o dnn -O3 -w -std=c++17
	@./dnn
	@rm dnn