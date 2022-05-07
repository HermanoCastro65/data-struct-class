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
public abstract class Lista<K> {

    class NoLista<K> {

        K dado;
        NoLista<K> proximo;
    }

    NoLista<K> inicio = null;

    public void add(K dado) {
        NoLista<K> novo = new NoLista<>();
        novo.dado = dado;
        novo.proximo = inicio;
        inicio = novo;
    }

    public abstract int comparar(K dado1, K dado2);

    public void remove(K dado) {
        NoLista<K> aux = inicio;
        NoLista<K> anterior = null;
        while (aux != null && comparar(aux.dado, dado) != 0) {
            anterior = aux;
            aux = aux.proximo;
        }
        if (aux != null) {
            if (anterior == null) {
                inicio = aux.proximo;
            } else {
                anterior.proximo = aux.proximo;
            }
            aux = null;
        }
    }

    public void listar() {
        NoLista<K> aux = inicio;
        while (aux != null) {
            System.out.println(aux.dado);
            aux = aux.proximo;
        }
    }

}
