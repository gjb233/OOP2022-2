#pragma once
#include"User.h"
#include"VerificationStrategy.h"
#include"EncryptStrategy.h"
class UserProxy : public User{
private:
    RealUser* user;
    VerificationStrategy* ver;
    EncryptStrategy* enc;
public:
    UserProxy(RealUser* user0, EncryptStrategy* enc0, VerificationStrategy* ver0)
        : user(user0), ver(ver0), enc(enc0){
    }
    void sendMessage(std::string mes) override{
        user->sendMessage();
        std::cout << enc->encode(mes) << std::endl;
        std::cout << ver->verify(mes) << std::endl;
    }
};