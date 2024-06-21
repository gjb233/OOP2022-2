#pragma once
# include <string>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy : public EncryptStrategy{
	std::string encode(std::string mes) override{
		std::string str;
		for(char c : mes){
			str.push_back(c);
			str.push_back('#');
		}
		return str;
	}
};

class InvertStrategy : public EncryptStrategy{
	std::string encode(std::string mes) override{
		std::string str;
		auto iter = mes.end();
		while(iter != mes.begin()){
			iter--;
			str.push_back(*iter);
		}
		return str;
	}
};