
public class ExibirArrays {
    public void exibindo(int[] args) {
        System.out.print("<");
        for(int i = 0; i < args.length; i++ ){
            System.out.print(args[i]);
            if(i < args.length - 1){
                System.out.print(", ");
            }
        }
        System.out.print(">");
    }
}
