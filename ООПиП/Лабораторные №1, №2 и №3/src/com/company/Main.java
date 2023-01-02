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
        Dispatcher.add(new Auto("�����", 1));
        Dispatcher.add(new Auto("����", 0));
        Dispatcher.add(new Auto("���", 1));
        try (ObjectOutputStream file = new ObjectOutputStream(new FileOutputStream("Auto.txt"))) {
            file.writeObject(Dispatcher);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Scanner scanner = new Scanner(System.in);
        boolean flag = true;
        int choice;
        while (flag) {
            System.out.println("1. ���� � �������� ��������");
            System.out.println("2. ���� � �������� ����������");
            System.out.println("3. �������� ��������");
            System.out.println("4. �������� �� � ����");
            System.out.println("0. �����");
            System.out.println("��� �����: ");
            try {
                choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> {
                        System.out.print("������� ��� ���: ");
                        name = scanner.next();
                        driver.setStatus(name);
                        driver.DriverMenu(Dispatcher);
                    }
                    case 2 -> Dispatcher.AutoBaseMenu(driver.getApp(), driver.getStatus());
                    case 3 -> System.out.print("��� ������� ��� �� ���������, ������� �� ������������\n");
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



