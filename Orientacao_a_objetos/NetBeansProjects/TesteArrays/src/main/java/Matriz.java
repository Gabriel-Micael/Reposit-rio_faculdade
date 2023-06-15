import java.util.Arrays;

public class Matriz {
    public static void main(String[] args) {
        int [][]matriz = {{},{},{},{},{}};//new int[5][];
        for(int i = 0; i < matriz.length; i++){
            matriz[i] = new int[i];
            for(int j = 0; j < i;j++){
                matriz[i][j] = i*j;
            }
        }
        System.out.println(Arrays.deepToString(matriz));
        /*ExibirArrays mostra = new ExibirArrays();
        for(int i =0; i < matriz.length; i++){
            mostra.exibindo(matriz[i]);
            System.out.println("");
        }*/

    }
}
