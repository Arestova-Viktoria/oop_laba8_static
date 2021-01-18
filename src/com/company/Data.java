package com.company;

import java.util.Scanner;

public class Data {
    private int year;
    private int month;
    private int day;
    public int Read_Int(){
        Scanner in=new Scanner(System.in);
        int k = in.nextInt();
        in.close();
        return k;
    }
    public void Init(int d,int m,int y){
        day=d;
        month=m;
        year=y;
    }
    public void Display(){
        String out="Day:"+day;
        System.out.println(out);
        out="Month:"+month;
        System.out.println(out);
        out="Year:"+year;
        System.out.println(out);
    }
    public int Add(Data d1,Data d2){
        Data d3 = new Data();
        d3.year=d1.year+d2.year;
        return d3.year;
    }
    public void output_date_postavk(){
        String out=day+" "+month+" "+year;
        System.out.println(out);
    }
}
