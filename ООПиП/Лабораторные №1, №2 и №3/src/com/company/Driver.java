package com.company;

import java.util.Objects;
import java.util.Scanner;

public class Driver {
    private final Application app;//заявка
    private int id;//идентификатор
    private String status;//фамилия

    public Driver() {
        app = new Application();
        id = 1;
        status = "Азизбек";
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Application getApp() {
        return app;
    }


    public void DriverMenu(Dispatcher base) {
        boolean cycle = true;
        int choice;
        int id, day, month, year;
        Scanner scanner = new Scanner(System.in);

        while (cycle) {
            System.out.println("1. Выбрать автомобиль для рейса");
            System.out.println("2. Отменить рейс");
            System.out.println("3. Показать текущие рейсы");
            System.out.println("4. Сделать отметку о состоянии автомобиля");
            System.out.println("5. Установить дату ремонта");
            System.out.println("0. Выход");
            System.out.println("Ваш выбор: ");
            try {
                choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> {
                        base.show();
                        if (base.getSize() != 0) {
                            System.out.println("Ваш выбор: ");
                            id = scanner.nextInt();
                            app.add(base.getFlight(id - 1));
                        }
                    }
                    case 2 -> {
                        app.show();
                        if (app.getSize() != 0) {
                            System.out.println("Ваш выбор: ");
                            id = scanner.nextInt();
                            app.delete(id - 1);
                        }
                    }
                    case 3 -> app.show();
                    case 4 -> app.makeStatus();
                    case 5 -> {
                        System.out.println("День: ");
                        day = scanner.nextInt();
                        System.out.println("Месяц: ");
                        month = scanner.nextInt();
                        System.out.println("Год: ");
                        year = scanner.nextInt();
                        Date date = new Date(day, month, year);
                        app.setDate(date);
                    }
                    case 0 -> cycle = false;
                }
            } catch (Exception ex) {
                System.out.println("Неверный ввод, войдите заново");
                scanner.nextLine();
            }

        }
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Driver driver)) return false;
        return id == driver.id && status.equals(driver.status);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, status);
    }

    @Override
    public String toString() {
        return "Driver{" +
                "id=" + id +
                ", name='" + status + '\'' +
                ", auto=" + app +
                '}';
    }
}
