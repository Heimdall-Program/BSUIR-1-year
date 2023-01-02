package com.company;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Scanner;


public class Main {
    static Dispatcher Dispatcher;

    public static void main(String[] args) {


        Dispatcher = new Dispatcher();
        Driver driver = new Driver();
        String name;
        Dispatcher.add(new Auto("Волга", 1));
        Dispatcher.add(new Auto("Ауди", 0));
        Dispatcher.add(new Auto("БМВ", 1));
        try (ObjectOutputStream file = new ObjectOutputStream(new FileOutputStream("Auto.txt"))) {
            file.writeObject(Dispatcher);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Scanner scanner = new Scanner(System.in);
        boolean flag = true;
        int choice;
        while (flag) {
            System.out.println("1. Вход в качестве водителя");
            System.out.println("2. Вход в качестве диспетчера");
            System.out.println("3. Взломать пентагон");
            System.out.println("4. Записать всё в файл");
            System.out.println("0. Выход");
            System.out.println("Ваш выбор: ");
            try {
                choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> {
                        System.out.print("Введите своё имя: ");
                        name = scanner.next();
                        driver.setStatus(name);
                        driver.DriverMenu(Dispatcher);
                    }
                    case 2 -> Dispatcher.AutoBaseMenu(driver.getApp(), driver.getStatus());
                    case 3 -> System.out.print("Эта функция ещё не добавлена, следите за обновлениями\n");
                    case 4 -> {
                        try (ObjectOutputStream a = new ObjectOutputStream(new FileOutputStream("Auto.txt"))) {
                            a.writeObject(Dispatcher);
                            //a.close(Dispatcher);
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    case 0 -> flag = false;
                }
            } catch (Exception ex) {
                scanner.nextLine();
            }
        }
    }
}



