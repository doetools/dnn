ALL:
	@g++ dnn.cpp -o dnn -O3 -w -std=c++11
	@./dnn
	@rm dnn