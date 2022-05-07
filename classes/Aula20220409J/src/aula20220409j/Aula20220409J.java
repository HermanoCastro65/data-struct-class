/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula20220409j;

/**
 *
 * @author denis.cople
 */
public class Aula20220409J {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Lista<Integer> lista = new Lista<Integer>() {
            @Override
            public int comparar(Integer dado1, Integer dado2) {
                return dado1-dado2;
            }
        };
        lista.add(5);
        lista.add(6);
        lista.add(7);
        lista.add(8);
        lista.add(9);
        lista.remove(7);
        lista.listar();
        
    }
    
}
