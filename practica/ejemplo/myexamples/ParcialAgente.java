import jade.core.Agent;
import jade.core.Location;
import jade.core.ContainerID;
import java.io.BufferedReader;
import java.io.FileReader;

public class ParcialAgente extends Agent{
    private Location origen;
    private String hostDestino;
    private String containerDestino;
    private int ocurrencias = 0;
    private String clave; 
    private String archivo;

    @Override
    public void setup(){
        //Preparamos los argumentos 
        Object[] args = getArguments();
        hostDestino = args[0].toString();
        containerDestino = args[1].toString();
        archivo = args[2].toString();
        clave = args[3].toString(); 
        origen = here(); 

        try{
            ContainerID destino = new ContainerID(containerDestino, hostDestino);
            doMove(destino);
        } catch(Exception e){
            System.out.println("Migración fallida");
        }
    }

    @Override
    public void afterMove(){
        if (!here().getID().equals(origen.getID())){
            BufferedReader buffer;
            FileReader fr; 

            try{
                fr = new FileReader("/home/alumno/data/"+archivo);
                buffer = new BufferedReader(fr);
                String linea; 
                //El archivo puede tener lineas en blanco 
                while (linea = fr.readLine() != null){
                    if (linea.equals(clave){
                        ocurrencias++
                    }
                }
            } catch(Excepcion e){
                
            } finally {
                buffer.close();
                fr.close();
            }
            doMove(origen);

        } else {
            System.out.println("Cantidad de ocurrencias para la palabra clave: "+ ocurrencias);
            doDelete();
        }
    }
}