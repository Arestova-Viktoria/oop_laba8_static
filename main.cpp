#include <iostream>
#include <string>
using namespace std;

class date{
private:
    int year;
    int month;
    int day;
public:
    void output_date_postavk();
    int Read_Int();
    void Init(int day,int month,int year);
    void Display();
    int Add(date a,date b);
};
class icecream {
private:
    int id;
    static int id_gener;
    string name;
    int massa;
    int milk;
    int expiration_date, chocolate;
    string country;
    date date_post;
public:
    string Read_String();
    int Read_Int();
    void Display();
    void Init(string name, int massa, int milk, int expiration_date, int chocolate, string country, int day, int month, int year);
    int Add(icecream a, icecream b);
    void Country();
    void Sod_Chocolate();
    void output_date_postavk();
    int& get_massa();                   //добавлено
    void get_milk(int *icecream_milk);  //добавлено
    friend void Display_name(icecream& icecream_a);  //добавлено
    friend icecream operator+(const icecream &p_1,const icecream &p_2);  //добавлено
    icecream& operator++();  //добавлено
    icecream operator++(int);  //добавлено
    int one(icecream *p);
    int two();
    int get_id();
    static int get_id_now();
};
int icecream::id_gener = 1;

int icecream::get_id(){
    id = id_gener++;
    return id;
}
//статический метод для получения значения текущего ID без создания объекта класса

int icecream::get_id_now(){
    return id_gener;
}
icecream operator+(const icecream &p_1,const icecream &p_2){
    icecream p_3;
    p_3.massa=p_1.massa+p_2.massa;
    return p_3;
}
icecream& icecream::operator++(){ //постфикс
    massa++;
    return *this;
}
icecream icecream::operator++(int temp){ //префикс
    icecream p_2;
    p_2.massa=temp;
    ++(*this);
    return p_2;
}
string icecream::Read_String(){
    string str;
    getline(cin,str);
    return str;
}
void date::Display() {
    cout << "Day:" << day << endl;
    cout << "Month:" << month << endl;
    cout << "Year:" << year << endl;
}
void icecream::Display() {
    cout<<"Name:"<<name<<endl;
    cout<<"Massa:"<<massa<<endl;
    cout<<"Chocolate:";
    if (chocolate == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cout<<"Milk:"<<milk<<endl;
    cout<<"Exp.Date:"<<expiration_date<<endl;
    cout<<"Country:"<<country<<endl;
    date_post.Display();
    cout<<" "<<endl;
}
int date::Add(date d1, date d2) {
    date d3;
    d3.year = d1.year + d2.year;
    return d3.year;
}
int icecream::Add(icecream ice1, icecream ice2) {
    icecream ice3;
    ice3.massa = ice1.massa + ice2.massa;
    return ice3.massa;
}

int icecream::Read_Int() {
    int number;
    cin >> number;
    return number;
}
int date::Read_Int() {
    int c;
    cin >> c;
    return c;
}
void date::Init(int x, int y, int k) {
    day = x;
    month = y;
    year = k;
}
void icecream::Init(string nazv, int mas, int sod_milk, int ex_date, int ch, string c, int x, int y, int k) {
    name = nazv;
    massa = mas;
    milk = sod_milk;
    expiration_date = ex_date;
    chocolate = ch;
    country = c;
    date_post.Init(x, y, k);
}
void icecream::Country() {
    cout << country;
}
void icecream::Sod_Chocolate() {
    cout<<"Chocolate:";
    if (chocolate == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
void date::output_date_postavk() {
    cout << day << "." << month << "." << year << endl;
}
void icecream::output_date_postavk() {
    date_post.output_date_postavk();
}
int& icecream::get_massa(){
    return massa;
}
void icecream::get_milk(int *milk_ice){
    *milk_ice=milk;
}
void Display_name(icecream &icecream_a){
    cout<<icecream_a.name;
}
int icecream::one(icecream *p){
    return p->massa+100;
}
int icecream::two(){
    return one(this);
}
int main()
{
    icecream ice1,ice2;
    string str_1 = "Slastena";
    string str_2 = "Russia";
    int m = 250;
    int mil = 100;
    int ex = 60;
    int ch = 1;
    int x = 12;
    int y = 10;
    int k = 2020;
    ice1.Init(str_1, m, mil, ex, ch, str_2, x, y, k);

    str_1 = "Fixiki";
    str_2 = "Usa";
    m = 120;
    mil = 98;
    ex = 90;
    ch = 0;
    x = 31;
    y = 12;
    k = 2020;
    ice2.Init(str_1, m, mil, ex, ch, str_2, x, y, k);
    ice1.Display();
    ice2.Display();

    //возврат значения из метода через ссылку
    int& mas_i=ice1.get_massa();//создаем ссылку которой присваиваем значение переменной массы
    cout<<mas_i<<endl;

    //возврат значния из метода через указатель
    int milk_ice;
    ice1.get_milk(&milk_ice);
    cout<<milk_ice<<endl;
    //указатель на объект
    Display_name(ice1);

    //демонстрация перегрузки оператора +
    icecream ice3;
    ice3=ice1+ice2;
    cout<<endl<<ice3.get_massa()<<endl;

    //демонтрация перегрузки оператора ++ (префикс)
    cout<<ice1.get_massa()<<endl;
    ++ice1;
    cout<<ice1.get_massa()<<endl;

    //постфикс
    ice1++;
    cout<<ice1.get_massa()<<endl;

    //демонстрация использования оператора this
    cout<<ice1.two()<<endl;

    //демонстрация использования статических полей для получения идентификатора каждого объекта
    cout<<"ID first object: "<<ice1.get_id()<<endl;
    cout<<"ID second object: "<<ice2.get_id()<<endl;

    //демонстрация использования статического метода для получения текущего (свободного) идентификатора
    cout<<"Now ID (free ID): "<<icecream::get_id_now()<<endl;
}
