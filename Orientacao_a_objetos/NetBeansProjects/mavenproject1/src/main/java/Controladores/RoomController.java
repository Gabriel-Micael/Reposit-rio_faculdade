package Controladores;

import com.mycompany.mavenproject1.Hostel;
import com.mycompany.mavenproject1.Room;

public class RoomController {
    private Room room;
    private Hostel hostel;  // TODO change place after refactoring

    public RoomController() {
        this.hostel = new Hostel();
     }

    public void createRoom(int number, String type) {
        room = new Room(number, type);
    }

    public String persistRoomData(String name, int floor, String description, double dimension) {
        room.setName(name);
        room.setFloor(floor);
        room.setDescription(description);
        room.setDimension(dimension);
        hostel.addRoom(room);
        return "Room data created successfully !";
    }

    public static void main(String[] args) {
        RoomController roomController = new RoomController();
        roomController.createRoom(312, "Double room");
        String result = roomController.persistRoomData("D. Leopoldina", 3, "", 20);
        System.out.println(result);
    }
}
