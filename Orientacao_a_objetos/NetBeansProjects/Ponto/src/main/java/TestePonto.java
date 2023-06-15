import Ponto.versão1.Ponto;

public class TestePonto {
    public static void main(String[] args) {
        Ponto primeiroPonto = new Ponto();
        Ponto segundoPonto = new Ponto(400, 230);

        primeiroPonto.setX(200);
        primeiroPonto.setY(200);

        System.out.println("Coordenadas do primeiro ponto (x,y): (" + primeiroPonto.getX() + "," + primeiroPonto.getY() + ")");
        System.out.println("Coordenadas do segundo ponto (x,y): (" + segundoPonto.getX() + "," + segundoPonto.getY() + ")");

        Ponto outraRefSegundoPonto = segundoPonto;
        outraRefSegundoPonto.setX(840);
        outraRefSegundoPonto.setY(350);

        System.out.println("Coordenadas do primeiro ponto (x,y): (" + primeiroPonto.getX() + "," + primeiroPonto.getY() + ")");
        System.out.println("Coordenadas do segundo ponto (x,y): (" + segundoPonto.getX() + "," + segundoPonto.getY() + ")");
        System.out.println("Coordenadas de outra referência para segundo ponto (x,y): (" + outraRefSegundoPonto.getX() + "," + outraRefSegundoPonto.getY() + ")");
    }
}
