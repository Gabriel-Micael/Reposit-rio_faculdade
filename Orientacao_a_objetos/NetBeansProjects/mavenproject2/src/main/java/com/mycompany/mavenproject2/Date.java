package com.mycompany.mavenproject2;

public class Date {
    private int day;
    private int mouth;
    private int year;

    public Date (){
        this(0,0,0);
    }

    public Date(int day, int mouth, int year){
        this.day = day;
        this.mouth = mouth;
        this.year = year;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMouth() {
        return mouth;
    }

    public void setMouth(int mouth) {
        this.mouth = mouth;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
    @Override
    public String toString(){
        return this.day + "/" + this.mouth + "/" + this.year;
    }
}
