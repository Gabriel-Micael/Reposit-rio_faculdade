package animais;

public class Gato extends Animal {
    public Gato(String nome){
        super(nome,4);
    }
    public Gato(){
        this("");
    }

    @Override
    public void comer(){
        System.out.println("Gato come ração");
    }
}
