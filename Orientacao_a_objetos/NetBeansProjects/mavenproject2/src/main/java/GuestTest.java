import com.mycompany.mavenproject2.Date;
import com.mycompany.mavenproject2.Endereço;
import com.mycompany.mavenproject2.Guest;


public class GuestTest {
    public static void main(String[] args){
        Guest florentino = new Guest("Florentino", "Ariza");
        Endereço endereçoflorentino = new Endereço("Rua Vice Prefeito Silvio Faria Vieira, N 200","Areado","Minas Gerais","Brasil", "12312312");
        florentino.setEndereço(endereçoflorentino);
        florentino.setEmail("florentinoariza@gmail.com");
        Date niverflorentino = new Date(19,7,2003);
        florentino.setAniversario(niverflorentino);

        System.out.println("Nome..............: " + florentino.getName());
        System.out.println("Sobrenome.........: " + florentino.getLastName());
        System.out.println("Email.............: " + florentino.getName());
        System.out.println("Aniversário.......: " + florentino.getAniversario());
        System.out.println("Zipcode...........: " + florentino.getEndereço().getZipcode());
        System.out.println("Endereço..........: " + florentino.getEndereço().getAddress());
        System.out.println("Cidade............: " + florentino.getEndereço().getCity());
        System.out.println("Estado............: " + florentino.getEndereço().getState());
        System.out.println("País..............: " + florentino.getEndereço().getCountry());

        Guest geraldo = new Guest("Geraldo"," Azevedo");
        System.out.println("Nome: " + geraldo.getName());
        System.out.println("Sobrenome: " + geraldo.getLastName());
    }
}
