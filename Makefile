all: test_to_json

test_to_json: test_to_json.cpp to_json.hpp
	g++ $< -o $@


to_json.hpp: to_json.hpp.pump
	./pump.py $^

