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

    if(val == 1)
        throw 1; //возвращает int или просто что-то абстрактное, это нужно для обработки непредсказуемый исключений

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
    catch(...){  //обрабатывает все, что угодно кроме объектов My_exeption и const char*. Самое интересное, что если поставить
        cout << "Что-то пошло не так" << endl; //catch(...) с тремя точками перед My_exception& ex и const char* stroka, то
    }                                          //то оно будет обрабатывать вообще все, включая My_exception& ex и const char* stroka
                                               //и эти два исключения не будут срабатывать, до них не дойдет ход

    return 0;
}
