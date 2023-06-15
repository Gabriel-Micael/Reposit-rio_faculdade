package com.mycompany.mavenproject2;

public class Guest{
    private String name;
    private String lastName;
    private Endereço endereço;
    private String email;
    private Date aniversario;

    public String getName() {
        return name;
    }

    public Guest(){
        this("");
    }

    public Guest(String name){
    this(name,"");
    }

    public Guest(String name, String lastName){
        this.name = name;
        this.lastName = lastName;
    }

    public boolean setName(String name) {
        if(name.length()>2) {
            this.name = name;
            return true;
        }
        return false;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public Endereço getEndereço() {
        return endereço;
    }

    public void setEndereço(Endereço endereço) {
        this.endereço = endereço;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Date getAniversario() {
        return aniversario;
    }

    public void setAniversario(Date aniversario) {
        this.aniversario = aniversario;
    }
}
