import jade.core.Agent;
import jade.core.Location;
import jade.core.ContainerID;
import java.io.BufferedReader;
import java.io.FileReader;

public class SumadorAgente extends Agent {
    private int sum = 0;
    private Location location;
    private String hostDestino;
    private String containerDestino;
    private String archivo;

    @Override
    public void setup(){
        this.location = here(); //Guardamos el lugar desde donde partimos 
        //Asumimos que recibimos correctamente los datos 
        Object[] args = getArguments();
        hostDestino = args[0].toString();
        containerDestino = args[1].toString();
        archivo = args[2].toString();

        //Nos preparamos para la migración 
        try {
            ContainerID destino = new ContainerID(containerDestino, hostDestino); //Se ingresa el nombre del containerDestino y el host. Si es local va null, si es remoto va su dirección. 
            doMove(destino); //Migramos el agente al nuevo container
        } catch (Exception e) {
            System.err.println("Migration failed: " + e.getMessage());
        }
    }


    @Override
    public void afterMove(){
        if (!here().getID().equals(containerDestino.getID())){ //Si cambiamos de contenedor
            BufferedReader reader;
            FileReader fileReader;
            String ruta = "/home/alumno/data/" + archivo; //Ruta del archivo en el contenedor destino
            try {
                fileReader = new FileReader(ruta);
                reader = new BufferedReader(fileReader);
                String linea;
                while ((linea = reader.readLine()) != null) {
                    sum += Integer.parseInt(linea); //Sumamos cada línea del archivo
                }
            } catch (Exception e) {
                System.err.println("Error reading file: " + e.getMessage());
            } finally{
                reader.close();
                fileReader.close()
            }
            doMove(origen); //Regresamos al contenedor inicial
        }
        else { //Si ya estamos en el contenedor origen
            System.out.println("La suma total es: " + sum);
            doDelete(); 
        }
    }
}