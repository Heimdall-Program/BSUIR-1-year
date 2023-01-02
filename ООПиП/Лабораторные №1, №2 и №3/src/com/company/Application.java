package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Application {  // ����� ������
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
            System.out.println("������ �������� ���!");
        }
    }

    public void makeStatus() {
        boolean flag = true;
        Scanner scanner = new Scanner(System.in);
        while (flag) {
            if (currentStatus == 0) {
                System.out.println("�� �� ������� ��������� ����������");
                break;
            }
            int payment;
            System.out.print("������� ��������� ����������: ");
            payment = scanner.nextInt();
            if (1 == payment) {
                System.out.println("���������� ������� ������");
                setOK(false);
                flag = false;
            } else if (0 == payment) {
                System.out.println("����������, �������� ������ ����������");
                setOK(true);
                flag = false;
            }

        }
    }

    public void show() {
        if (pubList.size() != 0) {
            for (int i = 0; i < pubList.size(); i++) {
                int id = i + 1;
                System.out.print(id + ". ����������: ");
                System.out.println(pubList.get(i).getAuto());
                System.out.print("���������: ");
                System.out.println(pubList.get(i).getStatus());
            }
            System.out.print("���� ������ ������: ");
            System.out.println(date.getDay() + "." + date.getMonth() + "." + date.getYear());
            if (isOK) {
                System.out.println("������ �������������");
            } else {
                System.out.println("������ �� �������������");
            }
        } else {
            System.out.println("�����");
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
