package com.company;

import java.util.Objects;
import java.util.Scanner;

public class Driver {
    private final Application app;//������
    private int id;//�������������
    private String status;//�������

    public Driver() {
        app = new Application();
        id = 1;
        status = "�������";
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
            System.out.println("1. ������� ���������� ��� �����");
            System.out.println("2. �������� ����");
            System.out.println("3. �������� ������� �����");
            System.out.println("4. ������� ������� � ��������� ����������");
            System.out.println("5. ���������� ���� �������");
            System.out.println("0. �����");
            System.out.println("��� �����: ");
            try {
                choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> {
                        base.show();
                        if (base.getSize() != 0) {
                            System.out.println("��� �����: ");
                            id = scanner.nextInt();
                            app.add(base.getFlight(id - 1));
                        }
                    }
                    case 2 -> {
                        app.show();
                        if (app.getSize() != 0) {
                            System.out.println("��� �����: ");
                            id = scanner.nextInt();
                            app.delete(id - 1);
                        }
                    }
                    case 3 -> app.show();
                    case 4 -> app.makeStatus();
                    case 5 -> {
                        System.out.println("����: ");
                        day = scanner.nextInt();
                        System.out.println("�����: ");
                        month = scanner.nextInt();
                        System.out.println("���: ");
                        year = scanner.nextInt();
                        Date date = new Date(day, month, year);
                        app.setDate(date);
                    }
                    case 0 -> cycle = false;
                }
            } catch (Exception ex) {
                System.out.println("�������� ����, ������� ������");
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
