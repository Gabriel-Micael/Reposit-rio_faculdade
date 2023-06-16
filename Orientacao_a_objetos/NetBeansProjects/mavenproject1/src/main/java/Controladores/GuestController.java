package Controladores;

import com.mycompany.mavenproject1.Address;
import com.mycompany.mavenproject1.Guest;
import com.mycompany.mavenproject1.Hostel;

public class GuestController {
    private Hostel hostel;
    private Guest guest;

    public GuestController(){
        hostel = new Hostel();
    }

    public void creatorGuest(){
        guest = new Guest();
    }

    public String persistGuestDate(String firstname, String lastname, String email, String birthdate, String title, Address address){
        guest.setAddress(address);
        guest.setBirthDate(birthdate);
        guest.setEmail(email);
        guest.setFirstname(firstname);
        guest.setLastname(lastname);
        guest.setTitle(title);
        return "Guest data created successfully !";
    }
    public void setHostel(Hostel hostel) {
        this.hostel = hostel;
    }

    public void setGuest(Guest guest) {
        this.guest = guest;
    }

    public static void main(String[] args) {
        GuestController guestController = new GuestController();
        guestController.creatorGuest();
        Address guestAddress = new Address();
        String result = guestController.persistGuestDate("Gabrel", "Henrique", "gabrielmicaelhenrique@gmail.com", "19/07/2003", "Mr", guestAddress);
        System.out.println(result);
    }
}
