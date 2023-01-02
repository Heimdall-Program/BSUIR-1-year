package com.company;

import java.io.Serializable;

public class Auto implements Serializable {
    private final String name;
    private final int status;

    Auto(String name, int status) {
        this.name = name;
        this.status = status;
    }

    Auto() {
        status = 0;
        name = "Название";
    }

    public int getStatus() {
        return status;
    }

    public String getAuto() {
        return name;
    }

    @Override
    public String toString() {
        return "Info { " + "auto: " + getAuto() + ", status: " + getStatus() + '}';
    }

}
