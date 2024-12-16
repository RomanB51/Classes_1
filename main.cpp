#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

class My_exception: public exception{
private:
    string message;

public:
    My_exception(const string& message){  //НЕ ЗАБУДЬ CONST!!!!!!!!!!!!!   Иначе ошибка!!!
        this->message = message;
    }
    const char* what() const noexcept override{  //вот такое интересное переопределение функции what()
        return message.c_str();
    }
};


void Func(int val){
    if(val < 0)
        throw My_exception("Твое число меньше 0"); //хороший способ обработки исключений, так как используется класс exception

    if(val == 0)
        throw "Твое число равно 0";  //это терпимый способ обработки исключений, но лишний раз такое себе

    cout << "Вы ввели число: " << endl;
}
int main(){

    try{
        Func(-4);
    }
    catch(My_exception& ex){
        cout << ex.what() << endl;
    }
    catch(const char* stroka){  //const char* - это обязательная программа, никаких string!!!
        cout << stroka << endl;
    }

    return 0;
}
