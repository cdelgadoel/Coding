import java.util.ArrayList;
public class Ejercicio1Examen {
	public static  ArrayList <Integer> SiSeEncuentraNvecesEnElArregloSeQuita(int [] arreglo, int total, int n) {
		ArrayList <Integer> listaArr = new ArrayList<>();
		int contDatos = 0;
		
		for(int i = 0; i < total; i++){
			if(arreglo[i] == n)
				contDatos++;
		}
		
		if(contDatos == n) { 
			// agregamos los datos a la lista
			for(int i = 0; i < total; i++){
				if(arreglo[i] != n) 
					listaArr.add(arreglo[i]);
			}

			// modificamos el inicial
			total = n;
			for(int i = 0; i < n; i++)
				arreglo[i] = n;
		}
		else
			listaArr = null;
		
		return listaArr;
	}
}
