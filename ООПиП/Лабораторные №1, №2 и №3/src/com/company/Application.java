package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Application {  // класс заявки
    private final List<Auto> pubList;
    int currentStatus;
    private Date date;
    private boolean isOK = true;


    Application() {
        pubList = new ArrayList<>();
        date = new Date();
        currentStatus = 0;
    }

    public void setOK(boolean OK) {
        isOK = OK;
    }

    public void add(Auto p) {
        pubList.add(p);
        currentStatus += p.getStatus();
    }

    public void delete(int id) {
        if (id >= 0 && id < pubList.size()) {
            currentStatus -= pubList.get(id).getStatus();
            pubList.remove(id);
        } else {
            System.out.println("Такого элемента нет!");
        }
    }

    public void makeStatus() {
        boolean flag = true;
        Scanner scanner = new Scanner(System.in);
        while (flag) {
            if (currentStatus == 0) {
                System.out.println("Вы не выбрали исправный автомобиль");
                break;
            }
            int payment;
            System.out.print("Оцените состояние автомобиля: ");
            payment = scanner.nextInt();
            if (1 == payment) {
                System.out.println("Автомобиль успешно выбран");
                setOK(false);
                flag = false;
            } else if (0 == payment) {
                System.out.println("Пожалуйста, выберите другой автомобиль");
                setOK(true);
                flag = false;
            }

        }
    }

    public void show() {
        if (pubList.size() != 0) {
            for (int i = 0; i < pubList.size(); i++) {
                int id = i + 1;
                System.out.print(id + ". Автомобиль: ");
                System.out.println(pubList.get(i).getAuto());
                System.out.print("Состояние: ");
                System.out.println(pubList.get(i).getStatus());
            }
            System.out.print("Дата подачи заявки: ");
            System.out.println(date.getDay() + "." + date.getMonth() + "." + date.getYear());
            if (isOK) {
                System.out.println("Заявка действительна");
            } else {
                System.out.println("Заявка не действительна");
            }
        } else {
            System.out.println("Пусто");
        }
        System.out.println();
    }

    public int getSize() {
        return pubList.size();
    }

    public void setDate(Date date) {
        this.date = date;
    }
}
