package com.company;

public class Date {
    int day;
    int month;
    int year;

    Date() {
        day = 25;
        month = 5;
        year = 2022;
    }

    Date(int day, int month, int year) {
        try {
            if (year == 0) {
                throw new NotCorrectYear();
            }
            this.month = month;
            this.day = day;
            this.year = year;
        } catch (Exception a) {
            System.out.println(a.getMessage() + "\n");
        }
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
}

