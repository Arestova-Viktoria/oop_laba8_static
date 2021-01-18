package com.company;

public class Main {

    public static void main(String[] args) {
        Icecream [] icecreams = new Icecream[3];
        icecreams[0]=new Icecream();
        String str_1="Lakomka";
        String str_2="Russia";
        int m=250;
        int mil = 100;
        int ex = 60;
        int ch = 1;
        int x = 12;
        int y = 10;
        int k = 2020;
        icecreams[0].Init(str_1, m, mil, ex, ch, str_2, x, y, k);
        System.out.println();
        icecreams[0].Display();
        System.out.println();
        icecreams[0].Country();
        System.out.println();
        icecreams[0].output_date_postavk();
        //доступ к переменной через вспомогательный класс
        int a = icecreams[0].help_icecream.return_int(icecreams[0]);
        System.out.println(a);

        System.out.println(icecreams[0].two());

        //демонстрация использования статических полей для получения идентификатора каждого объекта
        System.out.println("ID first object: "+icecreams[0].get_id()+"\n");

        //демонстрация использования статического метода для получения текущего (свободного) идентификатора
        System.out.println("Now ID (free ID): "+Icecream.get_id_now()+"\n");
        
    }
}
