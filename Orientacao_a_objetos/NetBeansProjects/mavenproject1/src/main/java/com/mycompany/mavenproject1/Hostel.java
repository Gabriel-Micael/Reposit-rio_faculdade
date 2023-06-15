package com.mycompany.mavenproject1;
import java.util.ArrayList;

public class Hostel {
    private String name;
    private String homepageAddress;
    private Address address;
    private String description;
    private String inaugurationDate;
    private String Contact;
    private ArrayList<Guest> clients;
    private ArrayList<Room> rooms;
    private ArrayList<Employee> employees;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHomepageAddress() {
        return homepageAddress;
    }

    public void setHomepageAddress(String homepageAddress) {
        this.homepageAddress = homepageAddress;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getInaugurationDate() {
        return inaugurationDate;
    }

    public void setInaugurationDate(String inaugurationDate) {
        this.inaugurationDate = inaugurationDate;
    }

    public String getContact() {
        return Contact;
    }

    public void setContact(String contact) {
        Contact = contact;
    }

    public ArrayList<Guest> getClients() {
        return clients;
    }

    public void setClients(ArrayList<Guest> clients) {
        this.clients = clients;
    }

    public ArrayList<Room> getRooms() {
        return rooms;
    }

    public void setRooms(ArrayList<Room> rooms) {
        this.rooms = rooms;
    }

    public ArrayList<Employee> getEmployees() {
        return employees;
    }

    public void setEmployees(ArrayList<Employee> employees) {
        this.employees = employees;
    }
}
