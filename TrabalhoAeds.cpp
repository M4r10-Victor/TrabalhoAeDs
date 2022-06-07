#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct date{
    int day;
    int month;
    int year;
}Date;

typedef struct client {
    int code;
    string name;
    bool active;

    void print(){
     cout<<"Código: "<< code << ","<< " Nome: " << name << "," << " Ativo: "
    << (active  ? "Sim" : "Nao" ) << ";"<<endl;
    }

}Client;

typedef struct fuel{
    int code;
    string name;
    double price;
    Date changeDatePrice;

    void print(){
        cout<<"Código: " << code << ",\n" << " Nome: " << name << "," << " Preco: " << price << ",\n"<<
        " Data de alteração: "<< changeDatePrice.day <<"/"<< changeDatePrice.month <<"/" <<
         changeDatePrice.year << ";"<<endl;
    }
}Fuel;

typedef struct sales{
    Client cliente;
    Fuel combustivel;
    bool paidOut;
    double theAmount;
    double literValue;
    double total;
    Date date;

    void print(){
        cout << "Data: " << date.day <<"/"<< date.month <<"/" << date.year<< ", Codigo do cliente: "
        << cliente.code << ", Codigo do combustível: "<< combustivel.code<< ", Quantidade: " << theAmount
        << ", Valor no litro: " << literValue << ", Total: "<< total <<", Pago: " << (paidOut ? "Sim" : "Não") << ";"<< endl;
        }
}Sales;

void init(map<int,Client>& c, map<int,Fuel>& f);
void listFuel(map<int,Fuel>&fuel);
void listClient(map<int,Client>&Client);
void listSales(map<int,Sales>&sales);


int randomId()
{
    srand(time(0));
    int randomNumber = 100 + rand() % 899;
    return randomNumber;
}

void cadastrarUsuario(map<int, Client>&client)
{
    system("clear||cls");
    string nome;
    bool ativo;
    Client novo;



    cout<<"-------------Cadastrar Usuário---------------\n";
    cout<<"Digite o nome do cliente: \n";
    cin>> nome;
    cout<<"Cliente ativo?\n( 0= nao, 1= sim )\n";
    cin>> ativo;

    int id = 8;

    novo.code = id++;
    novo.name = nome;
    novo.active = ativo;
    client[novo.code] = novo;
}

void cadastrarVenda(map<int,Sales>&sales)
{
    system("clear||cls");
    int idCliente;
    int combustivel;
    double litros;
    bool pago;
    Sales venda;
    int dia,mes,ano;



    cout<<"-------------Cadastro de Venda---------------\n";
    cout << "Digite o id do Cliente:\n";
    cin >> idCliente;
    cout << "Digite o id do combustível:\n";
    cin >> combustivel;
    cout << "Digite quantidade de litros abastecidos:\n";
    cin >> litros;
    cout << "Data da compra(Dia, Mês, Ano):\n";
    cin >> dia;
    cin >> mes;
    cin >> ano;
    cout << "Foi pago?\n (0= Não, 1= Sim)\n";
    cin >> pago;

    venda.cliente.code = idCliente;
    venda.combustivel.code = combustivel;
    venda.theAmount = litros;
    venda.paidOut = pago;
    venda.date.day = dia;
    venda.date.month = mes;
    venda.date.year = ano;

    sales[idCliente] = venda;
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    map<int,Client>client;
    map<int,Fuel>fuel;
    map<int,Sales>sales;
    init(client,fuel);
    int opcao;
    bool sair = 1;

    while(sair = 1){
    system("clear||cls");
    int opcao;
    cout <<"-------------------MENU----------------------\n";
    cout <<"1.Cadastrar Usuário\n";
    cout <<"2.Cadastrar Venda\n";
    cout <<"3.Verificar Vendas\n";
    cout <<"4.Verificar Clientes\n";
    cout <<"5.Verificar Combustível \n";
    cout <<"---------------------------------------------\n";
    cin >> opcao;

    switch(opcao){
        case 1:
               cadastrarUsuario(client);
            break;

        case 2:
                cadastrarVenda(sales);
            break;

        case 3:
             listSales(sales);
            break;
        case 4:
            listClient(client);
            break;

        case 5:
            listFuel(fuel);
            break;
    }

};

}

void listClient(map<int,Client>&client){
    system("clear||cls");
    cout << "\n  Clientes \n\n";
    for(auto i: client){
        if(i.second.active){
        i.second.print();
        }
    }
    char voltar;
    cout<<"Deseja voltar ao menu?\n(Sim ou Não)\n";
    cin>> voltar;
        if(voltar == 'Sim'){
            main();
            }
}


void listFuel(map<int,Fuel>&fuel){
    system("clear||cls");
    cout << "\n  Combustiveis \n\n";
    for(auto i: fuel){
        i.second.print();
    }
    char voltar;
    cout<<"Deseja voltar ao menu?\n(Sim ou Não)\n";
    cin>> voltar;
         if(voltar == 'Sim'){
            main();
        }
}

void listSales(map<int,Sales>&sales){
    system("clear||cls");
    cout << "\n  Vendas \n\n";
    for(auto i: sales){
        i.second.print();
    }
    char voltar;
    cout<<"Deseja voltar ao menu?\n(Sim ou Não)\n";
    cin>> voltar;
         if(voltar == 'Sim'){
            main();
        }
}

void init(map<int,Client>& c,map<int,Fuel>& f){
    Client client;
    Fuel fuel;
    client.code = 1;
    c[client.code].code = 1;
    c[client.code].name = "Mario Victor";
    c[client.code].active = false;

    client.code = 2;
    c[client.code].code = 2;
    c[client.code].name = "Gabriel Fagundes";
    c[client.code].active = false;

    client.code = 4;
    c[client.code].code = 4;
    c[client.code].name = "Yelena Nahara";
    c[client.code].active = true;

    client.code = 5;
    c[client.code].code = 5;
    c[client.code].name = "Guts Berse";
    c[client.code].active = true;

    client.code = 8;
    c[client.code].code = 5;
    c[client.code].name = "Lucas Carneiro";
    c[client.code].active = true;


    fuel.code = 1;
    f[fuel.code].code = 1;
    f[fuel.code].name = "Diesel s10";
    f[fuel.code].price = 4.25;
    f[fuel.code].changeDatePrice.day = 30;
    f[fuel.code].changeDatePrice.month = 11;
    f[fuel.code].changeDatePrice.year = 2022;

    fuel.code = 2;
    f[fuel.code].code = 2;
    f[fuel.code].name = "Gasolina comum";
    f[fuel.code].price = 8.15;
    f[fuel.code].changeDatePrice.day = 23;
    f[fuel.code].changeDatePrice.month = 6;
    f[fuel.code].changeDatePrice.year = 2021;

    fuel.code = 3;
    f[fuel.code].code = 3;
    f[fuel.code].name = "Etanol comum";
    f[fuel.code].price = 9.05;
    f[fuel.code].changeDatePrice.day = 02;
    f[fuel.code].changeDatePrice.year = 2022;
}

