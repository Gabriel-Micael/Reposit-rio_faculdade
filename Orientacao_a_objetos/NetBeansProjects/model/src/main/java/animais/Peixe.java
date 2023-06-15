package animais;

public class Peixe extends Animal{
    public Peixe(String nome){
        super(nome,0);
    }

    @Override
    public void caminhar(){
        System.out.println("Peixe não anda.");
    }

    @Override
    public void comer(){
        System.out.println("Peixe come algas e outros peixes.");
    }
}
