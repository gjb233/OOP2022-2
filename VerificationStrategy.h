#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy : public VerificationStrategy{
	std::string verify(std::string mes) override{
		return std::string(mes, 0, 3);
	}
};

class IntervalStrategy : public VerificationStrategy{
	std::string verify(std::string mes) override{
		std::string str;
		int i = 0;
		for(char c : mes){
			if(i % 2 == 0){
				str.push_back(c);
			}
			i++;
		}
		return str;
	}
};