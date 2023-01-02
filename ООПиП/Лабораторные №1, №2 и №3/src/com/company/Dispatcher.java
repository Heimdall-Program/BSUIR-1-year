package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dispatcher implements Serializable {
    private final List<Auto> Auto;

    Dispatcher() {
        Auto = new ArrayList<>();
    }


    public Dispatcher(List<Auto> Auto) {
        this.Auto = Auto;

    }


    public void AutoBaseMenu(Application app, String rName) {


        boolean flag = true;
        int choice, choice2, status, id;
        String name;

        Scanner scanner = new Scanner(System.in);

        while (flag) {
            System.out.println("1. Добавить автомобиль");
            System.out.println("2. Снять автомобиль(вместе с водителем)");
            System.out.println("3. Показать автопарк");
            System.out.println("4. Показать заявки на ремонт");
            System.out.println("0. Выход");
            System.out.println("Ваш выбор: ");
            try {
                choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> {
                        System.out.println("Автомобиль: ");
                        name = scanner.next();
                        System.out.println("Состояние: ");
                        status = scanner.nextInt();
                        add(new Auto(name, status));
                        read();
                    }
                    case 2 -> {
                        show();
                        if (Auto.size() != 0) {
                            System.out.println("Ваш выбор: ");
                            id = scanner.nextInt();
                            delete(id - 1);
                        }
                    }
                    case 3 -> {
                        show();
                        read();
                    }
                    case 4 -> {
                        System.out.print("Имя водителя: ");
                        System.out.println(rName);
                        app.show();
                        System.out.println("Отправить на заказ?");
                        System.out.println("1. Да");
                        System.out.println("0. Нет");
                        choice2 = scanner.nextInt();
                        app.setOK(choice2 != 0);
                    }
                    case 0 -> flag = false;
                    default -> System.out.println("Неверный ввод");
                }
            } catch (Exception ex) {
                System.out.println("Некорректный ввод, попробуйте еще раз");
                scanner.nextLine();
            }
        }
    }

    public void add(Auto p) {
        Auto.add(p);
    }

    public Auto getFlight(int id) {
        if (id >= 0 && id < Auto.size()) {
            return Auto.get(id);
        } else return new Auto();
    }

    public void show() {
        if (Auto.size() != 0) {
            for (Auto getok : Auto
            ) {
                System.out.println(getok.getAuto());
                System.out.print("Состояние: ");
                System.out.println(getok.getStatus());
            }

            for (int i = 0; i < Auto.size(); i++) {
                int id = i + 1;
                System.out.print(id + ". Автомобиль: ");
                System.out.println(Auto.get(i).getAuto());
                System.out.print("Состояние: ");
                System.out.println(Auto.get(i).getStatus());

            }


        } else {
            System.out.println("Пусто");
        }
        System.out.println();

    }

    public void delete(int id) {
        if (id >= 0 && id < Auto.size()) {
            Auto.remove(id);
        } else {
            System.out.println("Такого элемента нет!");
        }
    }

    public int getSize() {
        return Auto.size();
    }

    public List<Auto> getAuto() {
        return Auto;
    }

    private void write() {
        try (ObjectOutputStream a = new ObjectOutputStream(new FileOutputStream("Auto.txt"))) {
            a.writeObject(Auto);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void read() {
        Dispatcher flight = new Dispatcher();
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("Auto.txt"))) {
            flight = ((Dispatcher) ois.readObject());
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }

        for (Auto p : flight.getAuto())
            System.out.printf("Автомобиль: %s \t Состояние: %d \n", p.getAuto(), p.getStatus());
    }


}