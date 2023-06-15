import javax.swing.*;
import java.util.Arrays;

public class TesteArrays {
    public static void main(String[] args) {
        int array1[] = {2,3,5,7,11,13,17,19};
        int array2[] = {};
        ExibirArrays mostra = new ExibirArrays();
        System.out.println(Arrays.toString(array1));
        //mostra.exibindo(array1);
        array2 = array1;
        System.out.println("");
        for(int i = 0; i < array2.length; i++){
            if(i%2 == 0) {
                array2[i] = i;
            }
        }
        //mostra.exibindo(array2);
        System.out.println(Arrays.toString(array1));
    }
}
